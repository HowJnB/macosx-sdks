///////////////////////////////////////////////////////////////////////////////
// Name:        mac/dataform.h
// Purpose:     declaration of the wxDataFormat class
// Author:      Stefan Csomor (lifted from dnd.h)
// Modified by:
// Created:     10/21/99
// RCS-ID:      $Id: dataform.h,v 1.6.8.1 2007/03/08 01:21:03 VZ Exp $
// Copyright:   (c) 1999 Stefan Csomor
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_MAC_DATAFORM_H
#define _WX_MAC_DATAFORM_H

class WXDLLEXPORT wxDataFormat
{
public:
    typedef unsigned long NativeFormat;

    wxDataFormat();
    wxDataFormat(wxDataFormatId vType);
    wxDataFormat(const wxString& rId);
    wxDataFormat(const wxChar* pId);
    wxDataFormat(NativeFormat vFormat);

    wxDataFormat& operator=(NativeFormat vFormat)
        { SetId(vFormat); return *this; }

    // comparison (must have both versions)
    bool operator==(const wxDataFormat& format) const ;
    bool operator!=(const wxDataFormat& format) const
        { return ! ( *this == format ); }
    bool operator==(wxDataFormatId format) const
        { return m_type == (wxDataFormatId)format; }
    bool operator!=(wxDataFormatId format) const
        { return m_type != (wxDataFormatId)format; }

    // explicit and implicit conversions to NativeFormat which is one of
    // standard data types (implicit conversion is useful for preserving the
    // compatibility with old code)
    NativeFormat GetFormatId() const { return m_format; }
    operator NativeFormat() const { return m_format; }

    void SetId(NativeFormat format);

    // string ids are used for custom types - this SetId() must be used for
    // application-specific formats
    wxString GetId() const;
    void SetId(const wxChar* pId);

    // implementation
    wxDataFormatId GetType() const { return m_type; }
    void SetType( wxDataFormatId type );

    // returns true if the format is one of those defined in wxDataFormatId
    bool IsStandard() const { return m_type > 0 && m_type < wxDF_PRIVATE; }

private:
    wxDataFormatId   m_type;
    NativeFormat     m_format;
    // indicates the type in case of wxDF_PRIVATE :
    wxString         m_id ;
};

#endif // _WX_MAC_DATAFORM_H
