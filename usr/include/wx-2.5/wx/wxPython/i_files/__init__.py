#----------------------------------------------------------------------------
# Name:         __init__.py
# Purpose:      The presence of this file turns this directory into a
#               Python package.
#
# Author:       Robin Dunn
#
# Created:      8-Aug-1998
# RCS-ID:       $Id: __init__.py,v 1.9 2004/04/27 19:26:36 RD Exp $
# Copyright:    (c) 1998 by Total Control Software
# Licence:      wxWindows license
#----------------------------------------------------------------------------

import __version__
__version__ = __version__.VERSION_STRING


__all__ = [
    # Sub-packages
    'build',
    'lib',
    'py',
    'tools',

    # other modules
    'calendar',
    'grid',
    'html',
    'wizard',

    # contribs (need a better way to find these...)
    'activex',
    'gizmos',
    'glcanvas',
    'iewin',
    'ogl',
    'stc',
    'xrc',
    ]

# Load the package namespace with the core classes and such
from wx._core import *
del wx

# Load up __all__ with all the names of items that should appear to be
# defined in this pacakge so epydoc will document them that way.
import wx._core
__docfilter__ = wx._core.__DocFilter(globals())

__all__ += [name for name in dir(wx._core)
            if not (name.startswith('__') and name.endswith('__'))]



#----------------------------------------------------------------------------

