/////////////////////////////////////////////////////////////////////////////
// Name:        _cursor.i
// Purpose:     SWIG interface for wxCursor
//
// Author:      Robin Dunn
//
// Created:     7-July-1997
// RCS-ID:      $Id: _cursor.i,v 1.10 2004/09/23 20:23:18 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------


DocStr(wxCursor,
"A cursor is a small bitmap usually used for denoting where the mouse
pointer is, with a picture that might indicate the interpretation of a
mouse click.

A single cursor object may be used in many windows (any subwindow
type). The wxWindows convention is to set the cursor for a window, as
in X, rather than to set it globally as in MS Windows, although a
global `wx.SetCursor` function is also available for use on MS Windows.
","

Stock Cursor IDs
-----------------
    ========================    ======================================
    wx.CURSOR_ARROW             A standard arrow cursor.
    wx.CURSOR_RIGHT_ARROW       A standard arrow cursor pointing to the right.
    wx.CURSOR_BLANK             Transparent cursor.
    wx.CURSOR_BULLSEYE          Bullseye cursor.
    wx.CURSOR_CHAR              Rectangular character cursor.
    wx.CURSOR_CROSS             A cross cursor.
    wx.CURSOR_HAND              A hand cursor.
    wx.CURSOR_IBEAM             An I-beam cursor (vertical line).
    wx.CURSOR_LEFT_BUTTON       Represents a mouse with the left button depressed.
    wx.CURSOR_MAGNIFIER         A magnifier icon.
    wx.CURSOR_MIDDLE_BUTTON     Represents a mouse with the middle button depressed.
    wx.CURSOR_NO_ENTRY          A no-entry sign cursor.
    wx.CURSOR_PAINT_BRUSH       A paintbrush cursor.
    wx.CURSOR_PENCIL            A pencil cursor.
    wx.CURSOR_POINT_LEFT        A cursor that points left.
    wx.CURSOR_POINT_RIGHT       A cursor that points right.
    wx.CURSOR_QUESTION_ARROW    An arrow and question mark.
    wx.CURSOR_RIGHT_BUTTON      Represents a mouse with the right button depressed.
    wx.CURSOR_SIZENESW          A sizing cursor pointing NE-SW.
    wx.CURSOR_SIZENS            A sizing cursor pointing N-S.
    wx.CURSOR_SIZENWSE          A sizing cursor pointing NW-SE.
    wx.CURSOR_SIZEWE            A sizing cursor pointing W-E.
    wx.CURSOR_SIZING            A general sizing cursor.
    wx.CURSOR_SPRAYCAN          A spraycan cursor.
    wx.CURSOR_WAIT              A wait cursor.
    wx.CURSOR_WATCH             A watch cursor.
    wx.CURSOR_ARROWWAIT         A cursor with both an arrow and an hourglass, (windows.)
    ========================    ======================================

");

MustHaveApp(wxCursor);

class wxCursor : public wxGDIObject
{
public:
    
    %extend {
        DocStr(wxCursor,
               "Construct a Cursor from a file.  Specify the type of file using
wx.BITAMP_TYPE* constants, and specify the hotspot if not using a cur
file.

This constructor is not available on wxGTK, use ``wx.StockCursor``,
``wx.CursorFromImage``, or ``wx.CursorFromBits`` instead.", "");
        wxCursor(const wxString* cursorName, long type, int hotSpotX=0, int hotSpotY=0) {
%#ifdef __WXGTK__
            wxCHECK_MSG(false, NULL,
                        wxT("wx.Cursor constructor not implemented for wxGTK, use wx.StockCursor, wx.CursorFromImage, or wx.CursorFromBits instead."));
%#else
            return new wxCursor(*cursorName, type, hotSpotX, hotSpotY);
%#endif
        }
    }

    ~wxCursor();

    DocCtorStrName(
        wxCursor(int id),
        "Create a cursor using one of the stock cursors.  Note that not all
cursors are available on all platforms.", "",
        StockCursor);

    
    DocCtorStrName(
        wxCursor(const wxImage& image),
        "Constructs a cursor from a wxImage. The cursor is monochrome, colors
with the RGB elements all greater than 127 will be foreground, colors
less than this background. The mask (if any) will be used as
transparent.",
"
In MSW the foreground will be white and the background
black. The cursor is resized to 32x32.

In GTK, the two most frequent colors will be used for foreground and
background. The cursor will be displayed at the size of the image.

On MacOS the cursor is resized to 16x16 and currently only shown as
black/white (mask respected).",
        CursorFromImage);
    
    
//     %extend {
//         DocStr(wxCursor,
//                "");
//         %name(CursorFromBits) wxCursor(PyObject* bits, int width, int  height,
//                                          int hotSpotX=-1, int hotSpotY=-1,
//                                          PyObject* maskBits=NULL) {
//             char* bitsbuf;
//             char* maskbuf = NULL;
//             int   length;
//             PyString_AsStringAndSize(bits, &bitsbuf, &length);
//             if (maskBits)
//                 PyString_AsStringAndSize(maskBits, &maskbuf, &length);
//             return new wxCursor(bitsbuf, width, height, hotSpotX, hotSpotY, maskbuf);
//         }
//     }

    
    
#ifdef __WXMSW__
    DocDeclStr(
        long , GetHandle(),
        "Get the MS Windows handle for the cursor", "");
    
    %extend {
    DocStr(SetHandle,
        "Set the MS Windows handle to use for the cursor", "");
        void SetHandle(long handle) { self->SetHandle((WXHANDLE)handle); }
    }
    
#endif
    
    DocDeclStr(
        bool , Ok(),
        "", "");

    %pythoncode { def __nonzero__(self): return self.Ok() }

    
#ifdef __WXMSW__
    DocDeclStr(
        int , GetWidth(),
        "", "");
    
    DocDeclStr(
        int , GetHeight(),
        "", "");
    
    DocDeclStr(
        int , GetDepth(),
        "", "");
    
    DocDeclStr(
        void , SetWidth(int w),
        "", "");
    
    DocDeclStr(
        void , SetHeight(int h),
        "", "");
    
    DocDeclStr(
        void , SetDepth(int d),
        "", "");
    
    DocDeclStr(
        void , SetSize(const wxSize& size),
        "", "");
    
#endif
    
};


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
