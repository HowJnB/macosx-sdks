///////////////////////////////////////////////////////////////////////////////
// Name:        wx/bookctrl.h
// Purpose:     wxBookCtrl: common base class for wxList/Tree/Notebook
// Author:      Vadim Zeitlin
// Modified by:
// Created:     19.08.03
// RCS-ID:      $Id: bookctrl.h,v 1.11 2004/09/23 12:43:05 ABX Exp $
// Copyright:   (c) 2003 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_BOOKCTRL_H_
#define _WX_BOOKCTRL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "bookctrl.h"
#endif

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

#include "wx/defs.h"

#if wxUSE_BOOKCTRL

#include "wx/control.h"
#include "wx/dynarray.h"

WX_DEFINE_EXPORTED_ARRAY_PTR(wxWindow *, wxArrayPages);

class WXDLLEXPORT wxImageList;

// ----------------------------------------------------------------------------
// wxBookCtrl
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxBookCtrl : public wxControl
{
public:
    // construction
    // ------------

    wxBookCtrl()
    {
        Init();
    }

    wxBookCtrl(wxWindow *parent,
               wxWindowID winid,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxString& name = wxEmptyString)
    {
        Init();

        (void)Create(parent, winid, pos, size, style, name);
    }

    // quasi ctor
    bool Create(wxWindow *parent,
                wxWindowID winid,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxEmptyString);

    // dtor
    virtual ~wxBookCtrl();


    // accessors
    // ---------

    // get number of pages in the dialog
    virtual size_t GetPageCount() const { return m_pages.size(); }

    // get the panel which represents the given page
    virtual wxWindow *GetPage(size_t n) { return m_pages[n]; }

    // get the currently selected page or wxNOT_FOUND if none
    virtual int GetSelection() const = 0;

    // set/get the title of a page
    virtual bool SetPageText(size_t n, const wxString& strText) = 0;
    virtual wxString GetPageText(size_t n) const = 0;


    // image list stuff: each page may have an image associated with it (all
    // images belong to the same image list)
    // ---------------------------------------------------------------------

    // sets the image list to use, it is *not* deleted by the control
    virtual void SetImageList(wxImageList *imageList);

    // as SetImageList() but we will delete the image list ourselves
    void AssignImageList(wxImageList *imageList);

    // get pointer (may be NULL) to the associated image list
    wxImageList* GetImageList() const { return m_imageList; }

    // sets/returns item's image index in the current image list
    virtual int GetPageImage(size_t n) const = 0;
    virtual bool SetPageImage(size_t n, int imageId) = 0;


    // geometry
    // --------

    // resize the notebook so that all pages will have the specified size
    virtual void SetPageSize(const wxSize& size);

    // calculate the size of the control from the size of its page
    virtual wxSize CalcSizeFromPage(const wxSize& sizePage) const = 0;


    // operations
    // ----------

    // remove one page from the control and delete it
    virtual bool DeletePage(size_t n);

    // remove one page from the notebook, without deleting it
    virtual bool RemovePage(size_t n)
    {
        InvalidateBestSize();
        return DoRemovePage(n) != NULL;
    }

    // remove all pages and delete them
    virtual bool DeleteAllPages()
    {
        InvalidateBestSize();
        WX_CLEAR_ARRAY(m_pages);
        return true;
    }

    // adds a new page to the control
    virtual bool AddPage(wxWindow *page,
                         const wxString& text,
                         bool bSelect = false,
                         int imageId = -1)
    {
        InvalidateBestSize();
        return InsertPage(GetPageCount(), page, text, bSelect, imageId);
    }

    // the same as AddPage(), but adds the page at the specified position
    virtual bool InsertPage(size_t n,
                            wxWindow *page,
                            const wxString& text,
                            bool bSelect = false,
                            int imageId = -1) = 0;

    // set the currently selected page, return the index of the previously
    // selected one (or -1 on error)
    //
    // NB: this function will generate PAGE_CHANGING/ED events
    virtual int SetSelection(size_t n) = 0;


    // cycle thru the pages
    void AdvanceSelection(bool forward = true)
    {
        int nPage = GetNextPage(forward);
        if ( nPage != -1 )
        {
            // cast is safe because of the check above
            SetSelection((size_t)nPage);
        }
    }

    virtual void ApplyParentThemeBackground(const wxColour& bg)
        { SetBackgroundColour(bg); }

protected:
    // remove the page and return a pointer to it
    virtual wxWindow *DoRemovePage(size_t page) = 0;

    // our best size is the size which fits all our pages
    virtual wxSize DoGetBestSize() const;

    // helper: get the next page wrapping if we reached the end
    int GetNextPage(bool forward) const;

    // common part of all ctors
    void Init();

    // Always rely on GetBestSize, which will look at all the pages
    virtual void SetInitialBestSize(const wxSize& WXUNUSED(size)) { }

    // the array of all pages of this control
    wxArrayPages m_pages;

    // the associated image list or NULL
    wxImageList *m_imageList;

    // true if we must delete m_imageList
    bool m_ownsImageList;


    DECLARE_NO_COPY_CLASS(wxBookCtrl)
};

// ----------------------------------------------------------------------------
// wxBookCtrlEvent: page changing events generated by derived classes
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxBookCtrlEvent : public wxNotifyEvent
{
public:
    wxBookCtrlEvent(wxEventType commandType = wxEVT_NULL, int winid = 0,
                    int nSel = -1, int nOldSel = -1)
        : wxNotifyEvent(commandType, winid)
        {
            m_nSel = nSel;
            m_nOldSel = nOldSel;
        }

    // accessors
        // the currently selected page (-1 if none)
    int GetSelection() const { return m_nSel; }
    void SetSelection(int nSel) { m_nSel = nSel; }
        // the page that was selected before the change (-1 if none)
    int GetOldSelection() const { return m_nOldSel; }
    void SetOldSelection(int nOldSel) { m_nOldSel = nOldSel; }

private:
    int m_nSel,     // currently selected page
        m_nOldSel;  // previously selected page
};

#endif // wxUSE_BOOKCTRL

#endif // _WX_BOOKCTRL_H_
