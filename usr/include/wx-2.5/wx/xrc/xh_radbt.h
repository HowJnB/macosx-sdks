/////////////////////////////////////////////////////////////////////////////
// Name:        xh_radbt.h
// Purpose:     XML resource handler for radio buttons
// Author:      Bob Mitchell
// Created:     2000/03/21
// RCS-ID:      $Id: xh_radbt.h,v 1.4 2003/07/04 13:33:41 VS Exp $
// Copyright:   (c) 2000 Bob Mitchell and Verant Interactive
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_XH_RADBT_H_
#define _WX_XH_RADBT_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "xh_radbt.h"
#endif

#include "wx/xrc/xmlres.h"
#include "wx/defs.h"

#if wxUSE_RADIOBOX

class WXDLLIMPEXP_XRC wxRadioButtonXmlHandler : public wxXmlResourceHandler
{
DECLARE_DYNAMIC_CLASS(wxRadioButtonXmlHandler)
public:
    wxRadioButtonXmlHandler();
    virtual wxObject *DoCreateResource();
    virtual bool CanHandle(wxXmlNode *node);
};

#endif

#endif // _WX_XH_RADIOBUTTON_H_
