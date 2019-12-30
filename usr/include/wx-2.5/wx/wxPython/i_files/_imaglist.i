/////////////////////////////////////////////////////////////////////////////
// Name:        _imaglist.i
// Purpose:     SWIG interface defs for wxImageList and releated classes
//
// Author:      Robin Dunn
//
// Created:     7-July-1997
// RCS-ID:      $Id: _imaglist.i,v 1.6 2004/09/23 20:23:16 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------

%{
%}

//---------------------------------------------------------------------------
%newgroup

enum {
    wxIMAGELIST_DRAW_NORMAL ,
    wxIMAGELIST_DRAW_TRANSPARENT,
    wxIMAGELIST_DRAW_SELECTED,
    wxIMAGELIST_DRAW_FOCUSED,
    
    wxIMAGE_LIST_NORMAL,
    wxIMAGE_LIST_SMALL,
    wxIMAGE_LIST_STATE
};


MustHaveApp(wxImageList);


//  wxImageList is used for wxListCtrl, wxTreeCtrl. These controls refer to
//  images for their items by an index into an image list.
//  A wxImageList is capable of creating images with optional masks from
//  a variety of sources - a single bitmap plus a colour to indicate the mask,
//  two bitmaps, or an icon.
class wxImageList : public wxObject {
public:
    wxImageList(int width, int height, int mask=true, int initialCount=1);
    ~wxImageList();

    int Add(const wxBitmap& bitmap, const wxBitmap& mask = wxNullBitmap);
    %name(AddWithColourMask)int Add(const wxBitmap& bitmap, const wxColour& maskColour);
    %name(AddIcon)int Add(const wxIcon& icon);
#ifdef __WXMSW__
    bool Replace(int index, const wxBitmap& bitmap, const wxBitmap& mask = wxNullBitmap);
#else
//      %name(ReplaceIcon)bool Replace(int index, const wxIcon& icon);
//      int Add(const wxBitmap& bitmap);
    bool Replace(int index, const wxBitmap& bitmap);
#endif

    bool Draw(int index, wxDC& dc, int x, int x, int flags = wxIMAGELIST_DRAW_NORMAL,
              const bool solidBackground = false);

    int GetImageCount();
    bool Remove(int index);
    bool RemoveAll();

    DocDeclA(
        void, GetSize(int index, int& OUTPUT, int& OUTPUT),
        "GetSize() -> (width,height)");
        
};

//---------------------------------------------------------------------------
