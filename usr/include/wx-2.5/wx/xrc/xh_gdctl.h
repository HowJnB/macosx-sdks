/////////////////////////////////////////////////////////////////////////////
// Name:        xh_gdctl.h
// Purpose:     XML resource handler for wxGenericDirCtrl
// Author:      Markus Greither
// Created:     2002/01/20
// RCS-ID:      $Id: xh_gdctl.h,v 1.4 2003/07/04 13:33:41 VS Exp $
// Copyright:   (c) 2002 Markus Greither
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_XH_GDCTL_H_
#define _WX_XH_GDCTL_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "xh_gdctl.h"
#endif

#include "wx/xrc/xmlres.h"

#if wxUSE_DIRDLG

class WXDLLIMPEXP_XRC wxGenericDirCtrlXmlHandler : public wxXmlResourceHandler
{
DECLARE_DYNAMIC_CLASS(wxGenericDirCtrlXmlHandler)
public:
    wxGenericDirCtrlXmlHandler();
    virtual wxObject *DoCreateResource();
    virtual bool CanHandle(wxXmlNode *node);
};

#endif

#endif // _WX_XH_GDCTL_H_
