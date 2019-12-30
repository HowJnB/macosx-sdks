#----------------------------------------------------------------------------

# Use Python's bool constants if available, make some if not
try:
    True
except NameError:
    __builtins__.True = 1==1
    __builtins__.False = 1==0
    def bool(value): return not not value
    __builtins__.bool = bool



# workarounds for bad wxRTTI names
__wxPyPtrTypeMap['wxGauge95']    = 'wxGauge'
__wxPyPtrTypeMap['wxSlider95']   = 'wxSlider'
__wxPyPtrTypeMap['wxStatusBar95']   = 'wxStatusBar'


#----------------------------------------------------------------------------
# Load version numbers from __version__...  Ensure that major and minor
# versions are the same for both wxPython and wxWidgets.

from __version__ import *
__version__ = VERSION_STRING

assert MAJOR_VERSION == _core_.MAJOR_VERSION, "wxPython/wxWidgets version mismatch"
assert MINOR_VERSION == _core_.MINOR_VERSION, "wxPython/wxWidgets version mismatch"
if RELEASE_VERSION != _core_.RELEASE_VERSION:
    import warnings
    warnings.warn("wxPython/wxWidgets release number mismatch")

#----------------------------------------------------------------------------

class PyDeadObjectError(AttributeError):
    pass

class _wxPyDeadObject(object):
    """
    Instances of wx objects that are OOR capable will have their __class__
    changed to this class when the C++ object is deleted.  This should help
    prevent crashes due to referencing a bogus C++ pointer.
    """
    reprStr = "wxPython wrapper for DELETED %s object! (The C++ object no longer exists.)"
    attrStr = "The C++ part of the %s object has been deleted, attribute access no longer allowed."

    def __repr__(self):
        if not hasattr(self, "_name"):
            self._name = "[unknown]"
        return self.reprStr % self._name

    def __getattr__(self, *args):
        if not hasattr(self, "_name"):
            self._name = "[unknown]"
        raise PyDeadObjectError(self.attrStr % self._name)

    def __nonzero__(self):
        return 0



class PyUnbornObjectError(AttributeError):
    pass

class _wxPyUnbornObject(object):
    """
    Some stock objects are created when the wx._core module is
    imported, but their C++ instance is not created until the wx.App
    object is created and initialized.  These object instances will
    temporarily have their __class__ changed to this class so an
    exception will be raised if they are used before the C++ instance
    is ready.
    """

    reprStr = "wxPython wrapper for UNBORN object! (The C++ object is not initialized yet.)"
    attrStr = "The C++ part of this object has not been initialized, attribute access not allowed."

    def __repr__(self):
        #if not hasattr(self, "_name"):
        #    self._name = "[unknown]"
        return self.reprStr #% self._name

    def __getattr__(self, *args):
        #if not hasattr(self, "_name"):
        #    self._name = "[unknown]"
        raise PyUnbornObjectError(self.attrStr) # % self._name )

    def __nonzero__(self):
        return 0


#----------------------------------------------------------------------------
_wxPyCallAfterId = None

def CallAfter(callable, *args, **kw):
    """
    Call the specified function after the current and pending event
    handlers have been completed.  This is also good for making GUI
    method calls from non-GUI threads.  Any extra positional or
    keyword args are passed on to the callable when it is called.

    :see: `wx.FutureCall`
    """
    app = wx.GetApp()
    assert app is not None, 'No wx.App created yet'

    global _wxPyCallAfterId
    if _wxPyCallAfterId is None:
        _wxPyCallAfterId = wx.NewEventType()
        app.Connect(-1, -1, _wxPyCallAfterId,
              lambda event: event.callable(*event.args, **event.kw) )
    evt = wx.PyEvent()
    evt.SetEventType(_wxPyCallAfterId)
    evt.callable = callable
    evt.args = args
    evt.kw = kw
    wx.PostEvent(app, evt)


#----------------------------------------------------------------------------


class FutureCall:
    """
    A convenience class for wx.Timer, that calls the given callable
    object once after the given amount of milliseconds, passing any
    positional or keyword args.  The return value of the callable is
    availbale after it has been run with the `GetResult` method.

    If you don't need to get the return value or restart the timer
    then there is no need to hold a reference to this object.  It will
    hold a reference to itself while the timer is running (the timer
    has a reference to self.Notify) but the cycle will be broken when
    the timer completes, automatically cleaning up the wx.FutureCall
    object.

    :see: `wx.CallAfter`
    """
    def __init__(self, millis, callable, *args, **kwargs):
        self.millis = millis
        self.callable = callable
        self.SetArgs(*args, **kwargs)
        self.runCount = 0
        self.running = False
        self.hasRun = False
        self.result = None
        self.timer = None
        self.Start()

    def __del__(self):
        self.Stop()


    def Start(self, millis=None, *args, **kwargs):
        """
        (Re)start the timer
        """
        self.hasRun = False
        if millis is not None:
            self.millis = millis
        if args or kwargs:
            self.SetArgs(*args, **kwargs)
        self.Stop()
        self.timer = wx.PyTimer(self.Notify)
        self.timer.Start(self.millis, wx.TIMER_ONE_SHOT)
        self.running = True
    Restart = Start


    def Stop(self):
        """
        Stop and destroy the timer.
        """
        if self.timer is not None:
            self.timer.Stop()
            self.timer = None


    def GetInterval(self):
        if self.timer is not None:
            return self.timer.GetInterval()
        else:
            return 0


    def IsRunning(self):
        return self.timer is not None and self.timer.IsRunning()


    def SetArgs(self, *args, **kwargs):
        """
        (Re)set the args passed to the callable object.  This is
        useful in conjunction with Restart if you want to schedule a
        new call to the same callable object but with different
        parameters.
        """
        self.args = args
        self.kwargs = kwargs


    def HasRun(self):
        return self.hasRun

    def GetResult(self):
        return self.result

    def Notify(self):
        """
        The timer has expired so call the callable.
        """
        if self.callable and getattr(self.callable, 'im_self', True):
            self.runCount += 1
            self.running = False
            self.result = self.callable(*self.args, **self.kwargs)
        self.hasRun = True
        if not self.running:
            # if it wasn't restarted, then cleanup
            wx.CallAfter(self.Stop)



#----------------------------------------------------------------------------
# Control which items in this module should be documented by epydoc.
# We allow only classes and functions, which will help reduce the size
# of the docs by filtering out the zillions of constants, EVT objects,
# and etc that don't make much sense by themselves, but are instead
# documented (or will be) as part of the classes/functions/methods
# where they should be used.

class __DocFilter:
    """
    A filter for epydoc that only allows non-Ptr classes and
    fucntions, in order to reduce the clutter in the API docs.
    """
    def __init__(self, globals):
        self._globals = globals
        
    def __call__(self, name):
        import types
        obj = self._globals.get(name, None)
        if type(obj) not in [type, types.ClassType, types.FunctionType, types.BuiltinFunctionType]:
            return False
        if name.startswith('_') or name.endswith('Ptr') or name.startswith('EVT'):
            return False
        return True

#----------------------------------------------------------------------------
#----------------------------------------------------------------------------

# Import other modules in this package that should show up in the
# "core" wx namespace
from _gdi import *
from _windows import *
from _controls import *
from _misc import *


# Fixup the stock objects since they can't be used yet.  (They will be
# restored in wx.PyApp.OnInit.)
_core_._wxPyFixStockObjects()

#----------------------------------------------------------------------------
#----------------------------------------------------------------------------
