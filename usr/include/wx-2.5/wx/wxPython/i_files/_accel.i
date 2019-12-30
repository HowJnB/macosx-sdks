/////////////////////////////////////////////////////////////////////////////
// Name:        _accel.i
// Purpose:     SWIG interface for wxAcceleratorTable
//
// Author:      Robin Dunn
//
// Created:     03-July-1997
// RCS-ID:      $Id: _accel.i,v 1.5 2004/05/12 00:17:40 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------

%typemap(in) (int n, const wxAcceleratorEntry* entries) {
    $2 = wxAcceleratorEntry_LIST_helper($input);
    if ($2) $1 = PyList_Size($input);
    else    $1 = 0;
}

%typemap(freearg) wxAcceleratorEntry* entries {
     delete [] $1;
}



//---------------------------------------------------------------------------
%newgroup;

DocStr(wxAcceleratorEntry,
"A class used to define items in an `wx.AcceleratorTable`.  wxPython
programs can choose to use wx.AcceleratorEntry objects, but using a
list of 3-tuple of integers (flags, keyCode, cmdID) usually works just
as well.  See `__init__` for details of the tuple values.

:see: `wx.AcceleratorTable`", "");

class wxAcceleratorEntry {
public:
    DocCtorStr(
        wxAcceleratorEntry(int flags = 0, int keyCode = 0, int cmdID = 0/*, wxMenuItem *menuitem = NULL*/),
        "Construct a wx.AcceleratorEntry.",
        "
    :param flags: A bitmask of wx.ACCEL_ALT, wx.ACCEL_SHIFT,
                wx.ACCEL_CTRL or wx.ACCEL_NORMAL used to specify
                which modifier keys are held down.
    :param keyCode: The keycode to be detected
    :param cmdID: The menu or control command ID to use for the
                accellerator event.
");
    ~wxAcceleratorEntry();

    DocDeclStr(
        void , Set(int flags, int keyCode, int cmd/*, wxMenuItem *menuItem = NULL*/),
        "(Re)set the attributes of a wx.AcceleratorEntry.
:see `__init__`", "");
    

//     void SetMenuItem(wxMenuItem *item);
//     wxMenuItem *GetMenuItem() const;

    DocDeclStr(
        int , GetFlags(),
        "Get the AcceleratorEntry's flags.", "");
    
    DocDeclStr(
        int , GetKeyCode(),
        "Get the AcceleratorEntry's keycode.", "");
    
    DocDeclStr(
        int , GetCommand(),
        "Get the AcceleratorEntry's command ID.", "");
};





DocStr(wxAcceleratorTable,
"An accelerator table allows the application to specify a table of
keyboard shortcuts for menus or other commands. On Windows, menu or
button commands are supported; on GTK, only menu commands are
supported.", "

The object ``wx.NullAcceleratorTable`` is defined to be a table with
no data, and is the initial accelerator table for a window.

An accelerator takes precedence over normal processing and can be a
convenient way to program some event handling. For example, you can
use an accelerator table to make a hotkey generate an event no matter
which window within a frame has the focus.

Foe example::

    aTable = wx.AcceleratorTable([(wx.ACCEL_ALT,  ord('X'), exitID),
                                  (wx.ACCEL_CTRL, ord('H'), helpID),
                                  (wx.ACCEL_CTRL, ord('F'), findID),
                                  (wx.ACCEL_NORMAL, wx.WXK_F3, findnextID)
                                  ])
    self.SetAcceleratorTable(aTable)


:see: `wx.AcceleratorEntry`, `wx.Window.SetAcceleratorTable`
");

class wxAcceleratorTable : public wxObject {
public:
    DocAStr(wxAcceleratorTable,
            "__init__(entries) -> AcceleratorTable",
            "Construct an AcceleratorTable from a list of `wx.AcceleratorEntry`
items or or of 3-tuples (flags, keyCode, cmdID)

:see: `wx.AcceleratorEntry`", "");
    wxAcceleratorTable(int n, const wxAcceleratorEntry* entries);
    ~wxAcceleratorTable();

    bool Ok() const;
};


 
%immutable;
// See also wxPy_ReinitStockObjects in helpers.cpp
const wxAcceleratorTable wxNullAcceleratorTable;
%mutable;


wxAcceleratorEntry *wxGetAccelFromString(const wxString& label);

//---------------------------------------------------------------------------
