/////////////////////////////////////////////////////////////////////////////
// Name:        _statctrls.i
// Purpose:     SWIG interface defs for wxStaticBox, wxStaticLine,
//              wxStaticText, wxStaticBitmap
//
// Author:      Robin Dunn
//
// Created:     10-June-1998
// RCS-ID:      $Id: _statctrls.i,v 1.10 2004/07/17 22:50:56 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------

MAKE_CONST_WXSTRING(StaticBitmapNameStr);
MAKE_CONST_WXSTRING(StaticBoxNameStr);
MAKE_CONST_WXSTRING(StaticTextNameStr);

//---------------------------------------------------------------------------
%newgroup

MustHaveApp(wxStaticBox);

class wxStaticBox : public wxControl {
public:
    %pythonAppend wxStaticBox         "self._setOORInfo(self)"
    %pythonAppend wxStaticBox()       ""
    %typemap(out) wxStaticBox*;    // turn off this typemap

    wxStaticBox(wxWindow* parent, wxWindowID id=-1,
                const wxString& label = wxPyEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPyStaticBoxNameStr);
    %name(PreStaticBox)wxStaticBox();

    // Turn it back on again
    %typemap(out) wxStaticBox* { $result = wxPyMake_wxObject($1, $owner); }

    bool Create(wxWindow* parent, wxWindowID id=-1,
                const wxString& label = wxPyEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPyStaticBoxNameStr);

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
};


//---------------------------------------------------------------------------
%newgroup


MustHaveApp(wxStaticLine);

class wxStaticLine : public wxControl {
public:
    %pythonAppend wxStaticLine         "self._setOORInfo(self)"
    %pythonAppend wxStaticLine()       ""

    wxStaticLine( wxWindow *parent, wxWindowID id=-1,
                  const wxPoint &pos = wxDefaultPosition,
                  const wxSize &size = wxDefaultSize,
                  long style = wxLI_HORIZONTAL,
                  const wxString& name = wxPyStaticTextNameStr);
    %name(PreStaticLine)wxStaticLine();

    bool Create( wxWindow *parent, wxWindowID id=-1,
                  const wxPoint &pos = wxDefaultPosition,
                  const wxSize &size = wxDefaultSize,
                  long style = wxLI_HORIZONTAL,
                  const wxString& name = wxPyStaticTextNameStr);

    // is the line vertical?
    bool IsVertical() const;

    // get the default size for the "lesser" dimension of the static line
    static int GetDefaultSize();

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
};


//---------------------------------------------------------------------------
%newgroup

MustHaveApp(wxStaticText);

class wxStaticText : public wxControl {
public:
    %pythonAppend wxStaticText         "self._setOORInfo(self)"
    %pythonAppend wxStaticText()       ""

    wxStaticText(wxWindow* parent, wxWindowID id=-1,
                 const wxString& label = wxPyEmptyString,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxPyStaticTextNameStr);
    %name(PreStaticText)wxStaticText();

    bool Create(wxWindow* parent, wxWindowID id=-1,
                const wxString& label = wxPyEmptyString,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxPyStaticTextNameStr);

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
};

//---------------------------------------------------------------------------
%newgroup

MustHaveApp(wxStaticBitmap);

class wxStaticBitmap : public wxControl {
public:
    %pythonAppend wxStaticBitmap         "self._setOORInfo(self)"
    %pythonAppend wxStaticBitmap()       ""

    wxStaticBitmap(wxWindow* parent, wxWindowID id=-1,
                   const wxBitmap& bitmap = wxNullBitmap,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxString& name = wxPyStaticBitmapNameStr);
    %name(PreStaticBitmap)wxStaticBitmap();

    bool Create(wxWindow* parent, wxWindowID id=-1,
                   const wxBitmap& bitmap = wxNullBitmap,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxString& name = wxPyStaticBitmapNameStr);

    wxBitmap GetBitmap();
    void SetBitmap(const wxBitmap& bitmap);
    void SetIcon(const wxIcon& icon);

    static wxVisualAttributes
    GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
