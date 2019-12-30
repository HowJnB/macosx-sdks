/////////////////////////////////////////////////////////////////////////////
// Name:        wx/colrdlgg.h
// Purpose:     wxColourDialog
// Author:      Vadim Zeitiln
// Modified by:
// Created:     01/02/97
// RCS-ID:      $Id: colordlg.h,v 1.17 2004/06/04 16:00:43 VS Exp $
// Copyright:   (c) wxWidgets team
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_COLORDLG_H_BASE_
#define _WX_COLORDLG_H_BASE_

#include "wx/defs.h"

#if wxUSE_COLOURDLG

#if defined(__WXMSW__) && !defined(__WXUNIVERSAL__)
    #include "wx/msw/colordlg.h"
#elif defined(__WXMAC__) && !defined(__WXUNIVERSAL__)
    #include "wx/mac/colordlg.h"
#elif defined(__WXGTK20__) && !defined(__WXUNIVERSAL__)
    #include "wx/gtk/colordlg.h"
#else
    #include "wx/generic/colrdlgg.h"

    #define wxColourDialog wxGenericColourDialog
#endif

// get the colour from user and return it
wxColour WXDLLEXPORT
wxGetColourFromUser(wxWindow *parent = (wxWindow *)NULL,
                    const wxColour& colInit = wxNullColour);

#endif // wxUSE_COLOURDLG

#endif
    // _WX_COLORDLG_H_BASE_
