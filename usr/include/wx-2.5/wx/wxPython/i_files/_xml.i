/////////////////////////////////////////////////////////////////////////////
// Name:        _xml.i
// Purpose:     SWIG interface for other wxXml classes
//
// Author:      Robin Dunn
//
// Created:     4-June-2001
// RCS-ID:      $Id: _xml.i,v 1.1 2004/09/23 16:47:38 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------
%newgroup


// In order to provide wrappers for wxXmlResourceHandler we need to also
// provide the classes for representing and parsing XML.


// Represents XML node type.
enum wxXmlNodeType
{
    // note: values are synchronized with xmlElementType from libxml
    wxXML_ELEMENT_NODE,
    wxXML_ATTRIBUTE_NODE,
    wxXML_TEXT_NODE,
    wxXML_CDATA_SECTION_NODE,
    wxXML_ENTITY_REF_NODE,
    wxXML_ENTITY_NODE,
    wxXML_PI_NODE,
    wxXML_COMMENT_NODE,
    wxXML_DOCUMENT_NODE,
    wxXML_DOCUMENT_TYPE_NODE,
    wxXML_DOCUMENT_FRAG_NODE,
    wxXML_NOTATION_NODE,
    wxXML_HTML_DOCUMENT_NODE
};



// Represents node property(ies).
// Example: in <img src="hello.gif" id="3"/> "src" is property with value
//          "hello.gif" and "id" is property with value "3".
class wxXmlProperty
{
public:
    wxXmlProperty(const wxString& name = wxPyEmptyString,
                  const wxString& value = wxPyEmptyString,
                  wxXmlProperty *next = NULL);

    wxString GetName() const;
    wxString GetValue() const;
    wxXmlProperty *GetNext() const;

    void SetName(const wxString& name);
    void SetValue(const wxString& value);
    void SetNext(wxXmlProperty *next);
};




// Represents node in XML document. Node has name and may have content
// and properties. Most common node types are wxXML_TEXT_NODE (name and props
// are irrelevant) and wxXML_ELEMENT_NODE (e.g. in <title>hi</title> there is
// element with name="title", irrelevant content and one child (wxXML_TEXT_NODE
// with content="hi").
//
// If wxUSE_UNICODE is 0, all strings are encoded in the encoding given to Load
// (default is UTF-8).
class wxXmlNode
{
public:
    wxXmlNode(wxXmlNode *parent = NULL,
              wxXmlNodeType type = 0,
              const wxString& name = wxPyEmptyString,
              const wxString& content = wxPyEmptyString,
              wxXmlProperty *props = NULL,
              wxXmlNode *next = NULL);
    ~wxXmlNode();


    // user-friendly creation:
    %name(XmlNodeEasy) wxXmlNode(wxXmlNodeType type, const wxString& name,
                                  const wxString& content = wxPyEmptyString);

    void AddChild(wxXmlNode *child);
    void InsertChild(wxXmlNode *child, wxXmlNode *before_node);
    bool RemoveChild(wxXmlNode *child);
    void AddProperty(wxXmlProperty *prop);
    %name(AddPropertyName) void AddProperty(const wxString& name, const wxString& value);
    bool DeleteProperty(const wxString& name);

    // access methods:
    wxXmlNodeType GetType() const;
    wxString GetName() const;
    wxString GetContent() const;

    wxXmlNode *GetParent() const;
    wxXmlNode *GetNext() const;
    wxXmlNode *GetChildren() const;

    wxXmlProperty *GetProperties() const;
    wxString GetPropVal(const wxString& propName,
                        const wxString& defaultVal) const;
    bool HasProp(const wxString& propName) const;

    void SetType(wxXmlNodeType type);
    void SetName(const wxString& name);
    void SetContent(const wxString& con);

    void SetParent(wxXmlNode *parent);
    void SetNext(wxXmlNode *next);
    void SetChildren(wxXmlNode *child);

    void SetProperties(wxXmlProperty *prop);
};



// This class holds XML data/document as parsed by XML parser.
class wxXmlDocument : public wxObject
{
public:
    wxXmlDocument(const wxString& filename,
                  const wxString& encoding = wxPyUTF8String);
    %name(XmlDocumentFromStream) wxXmlDocument(wxInputStream& stream,
                                                const wxString& encoding = wxPyUTF8String);
    %name(EmptyXmlDocument) wxXmlDocument();

    ~wxXmlDocument();


    // Parses .xml file and loads data. Returns True on success, False
    // otherwise.
    bool Load(const wxString& filename,
              const wxString& encoding = wxPyUTF8String);
    %name(LoadFromStream)bool Load(wxInputStream& stream,
                                   const wxString& encoding = wxPyUTF8String);

    // Saves document as .xml file.
    bool Save(const wxString& filename) const;
    %name(SaveToStream)bool Save(wxOutputStream& stream) const;

    bool IsOk() const;

    // Returns root node of the document.
    wxXmlNode *GetRoot() const;

    // Returns version of document (may be empty).
    wxString GetVersion() const;

    // Returns encoding of document (may be empty).
    // Note: this is the encoding original file was saved in, *not* the
    // encoding of in-memory representation!
    wxString GetFileEncoding() const;

    // Write-access methods:
    void SetRoot(wxXmlNode *node);
    void SetVersion(const wxString& version);
    void SetFileEncoding(const wxString& encoding);

//     %extend {
//         // Returns encoding of in-memory representation of the document (same
//         // as passed to Load or ctor, defaults to UTF-8).  NB: this is
//         // meaningless in Unicode build where data are stored as wchar_t*
//         wxString GetEncoding() {
//         %#if wxUSE_UNICODE
//             return wxPyEmptyString;
//         %#else
//             return self->GetEncoding();
//         %#endif
//         }
//         void SetEncoding(const wxString& enc) {
//         %#if wxUSE_UNICODE
//             // do nothing
//         %#else
//             self->SetEncoding(enc);
//         %#endif
//         }
//     }
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
