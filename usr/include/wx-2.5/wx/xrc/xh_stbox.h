/////////////////////////////////////////////////////////////////////////////
// Name:        xh_stbox.h
// Purpose:     XML resource handler for wxStaticBox
// Author:      Brian Gavin
// Created:     2000/09/00
// RCS-ID:      $Id: xh_stbox.h,v 1.4 2003/07/04 13:33:42 VS Exp $
// Copyright:   (c) 2000 Brian Gavin
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_XH_STBOX_H_
#define _WX_XH_STBOX_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "xh_stbox.h"
#endif

#include "wx/xrc/xmlres.h"


class WXDLLIMPEXP_XRC wxStaticBoxXmlHandler : public wxXmlResourceHandler
{
DECLARE_DYNAMIC_CLASS(wxStaticBoxXmlHandler)
public:
    wxStaticBoxXmlHandler();
    virtual wxObject *DoCreateResource();
    virtual bool CanHandle(wxXmlNode *node);
};


#endif // _WX_XH_STBOX_H_
