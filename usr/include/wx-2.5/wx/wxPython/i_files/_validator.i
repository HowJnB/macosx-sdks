/////////////////////////////////////////////////////////////////////////////
// Name:        _validator.i
// Purpose:     SWIG interface for wxValidator
//
// Author:      Robin Dunn
//
// Created:     24-June-1997
// RCS-ID:      $Id: _validator.i,v 1.6 2004/09/23 20:23:13 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
%newgroup

/*
 A validator has up to three purposes:

 1) To validate the data in the window that's associated
    with the validator.
 2) To transfer data to and from the window.
 3) To filter input, using its role as a wxEvtHandler
    to intercept e.g. OnChar.

 Note that wxValidator and derived classes use reference counting.
*/

class wxValidator : public wxEvtHandler
{
public:
    %pythonAppend wxValidator "self._setOORInfo(self)"
    %typemap(out) wxValidator*;    // turn off this typemap

    wxValidator();
    //~wxValidator();

    // Turn it back on again
    %typemap(out) wxValidator* { $result = wxPyMake_wxObject($1, $owner); }

    
    // Make a clone of this validator (or return NULL)
    wxValidator* Clone();

    // Called when the value in the window must be validated.
    // This function can pop up an error message.
    virtual bool Validate(wxWindow *WXUNUSED(parent));

    // Called to transfer data to the window
    virtual bool TransferToWindow();

    // Called to transfer data from the window
    virtual bool TransferFromWindow();

    wxWindow* GetWindow();
    void SetWindow(wxWindow* window);

    // validators beep by default if invalid key is pressed, these functions
    // allow to change it
    static bool IsSilent();
    static void SetBellOnError(int doIt = true);

};


//---------------------------------------------------------------------------
%{
IMP_PYCALLBACK_BOOL_WXWIN(wxPyValidator, wxValidator, Validate);
IMP_PYCALLBACK_BOOL_(wxPyValidator, wxValidator, TransferToWindow);
IMP_PYCALLBACK_BOOL_(wxPyValidator, wxValidator, TransferFromWindow);

IMPLEMENT_DYNAMIC_CLASS(wxPyValidator, wxValidator);
%}


class wxPyValidator : public wxValidator {
public:
    %pythonAppend wxPyValidator "
        self._setCallbackInfo(self, PyValidator, 1)
        self._setOORInfo(self)"
    wxPyValidator();

    void _setCallbackInfo(PyObject* self, PyObject* _class, int incref=true);
};



%immutable;
// See also wxPy_ReinitStockObjects in helpers.cpp
const wxValidator wxDefaultValidator;
%mutable;

//---------------------------------------------------------------------------
