/////////////////////////////////////////////////////////////////////////////
// Name:        _wxobj.i
// Purpose:     SWIG interface for wxObject
//
// Author:      Robin Dunn
//
// Created:     9-Aug-2003
// RCS-ID:      $Id: _obj.i,v 1.5 2004/05/12 00:17:39 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------
%newgroup

DocStr(wxObject,
"The base class for most wx objects, although in wxPython not
much functionality is needed nor exposed.", "");

class wxObject {
public:

    %extend {
        DocStr(GetClassName,
               "Returns the class name of the C++ class using wxRTTI.", "");
        wxString GetClassName() {
            return self->GetClassInfo()->GetClassName();
        }

        DocStr(Destroy,
               "Deletes the C++ object this Python object is a proxy for.", "");
        void Destroy() {
            delete self;
        }
    }
};


//---------------------------------------------------------------------------
