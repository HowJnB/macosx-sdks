/////////////////////////////////////////////////////////////////////////////
// Name:        sizer.h
// Purpose:     provide wxSizer class for layout
// Author:      Robert Roebling and Robin Dunn
// Modified by: Ron Lee, Vadim Zeitlin (wxSizerFlags)
// Created:
// RCS-ID:      $Id: sizer.h,v 1.57 2004/09/17 21:42:38 VZ Exp $
// Copyright:   (c) Robin Dunn, Robert Roebling
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef __WXSIZER_H__
#define __WXSIZER_H__

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "sizer.h"
#endif

#include "wx/defs.h"

#include "wx/window.h"
#include "wx/frame.h"
#include "wx/dialog.h"
#include "wx/bookctrl.h"

//---------------------------------------------------------------------------
// classes
//---------------------------------------------------------------------------

class WXDLLEXPORT wxSizerItem;
class WXDLLEXPORT wxSizer;
class WXDLLEXPORT wxBoxSizer;


// ----------------------------------------------------------------------------
// wxSizerFlags: flags used for an item in the sizer
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxSizerFlags
{
public:
    // construct the flags object initialized with the given proportion (0 by
    // default)
    wxSizerFlags(int proportion = 0) : m_proportion(proportion)
    {
        m_flags = 0;
        m_borderInPixels = 0;
    }

    // setters for all sizer flags, they all return the object itself so that
    // calls to them can be chained

    wxSizerFlags& Proportion(int proportion)
    {
        m_proportion = proportion;
        return *this;
    }

    wxSizerFlags& Align(int alignment) // combination of wxAlignment values
    {
        m_flags &= wxALL;
        m_flags |= alignment;

        return *this;
    }

    // some shortcuts for Align()
    wxSizerFlags& Expand() { return Align(wxEXPAND); }
    wxSizerFlags& Centre() { return Align(wxCENTRE); }
    wxSizerFlags& Center() { return Centre(); }


    wxSizerFlags& Border(int direction, int borderInPixels)
    {
        m_flags &= ~wxALL;
        m_flags |= direction;

        m_borderInPixels = borderInPixels;

        return *this;
    }

    wxSizerFlags& Border(int direction = wxALL)
    {
        // FIXME: default border size shouldn't be hardcoded
        return Border(direction, 5);
    }


    // accessors for wxSizer only
    int GetProportion() const { return m_proportion; }
    int GetFlags() const { return m_flags; }
    int GetBorderInPixels() const { return m_borderInPixels; }

private:
    int m_proportion;
    int m_flags;
    int m_borderInPixels;
};


//---------------------------------------------------------------------------
// wxSizerItem
//---------------------------------------------------------------------------

class WXDLLEXPORT wxSizerItem: public wxObject
{
public:
    // window with flags
    wxSizerItem(wxWindow *window, const wxSizerFlags& flags)
    {
        Init(flags);

        m_window = window;
    }

    // sizer with flags
    wxSizerItem(wxSizer *sizer, const wxSizerFlags& flags)
    {
        Init(flags);

        m_sizer = sizer;
    }

    // window
    wxSizerItem( wxWindow *window,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData );

    // subsizer
    wxSizerItem( wxSizer *sizer,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData );

    // spacer
    wxSizerItem( int width,
                 int height,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData);

    wxSizerItem();
    virtual ~wxSizerItem();

    virtual void DeleteWindows();

    // Enable deleting the SizerItem without destroying the contained sizer.
    void DetachSizer()
        { m_sizer = 0; }

    virtual wxSize GetSize() const;
    virtual wxSize CalcMin();
    virtual void SetDimension( wxPoint pos, wxSize size );

    wxSize GetMinSize() const
        { return m_minSize; }
    wxSize GetMinSizeWithBorder() const;

    void SetMinSize(const wxSize& size)
        {
            if (IsWindow()) m_window->SetMinSize(size);
            m_minSize = size;
        }
    void SetMinSize( int x, int y )
        { SetMinSize(wxSize(x, y)); }
    void SetInitSize( int x, int y )
        { SetMinSize(wxSize(x, y)); }

    void SetRatio( int width, int height )
        // if either of dimensions is zero, ratio is assumed to be 1
        // to avoid "divide by zero" errors
        { m_ratio = (width && height) ? ((float) width / (float) height) : 1; }
    void SetRatio( wxSize size )
        { m_ratio = (size.x && size.y) ? ((float) size.x / (float) size.y) : 1; }
    void SetRatio( float ratio )
        { m_ratio = ratio; }
    float GetRatio() const
        { return m_ratio; }

    bool IsWindow() const;
    bool IsSizer() const;
    bool IsSpacer() const;

    // Deprecated in 2.6, use {G,S}etProportion instead.
    wxDEPRECATED( void SetOption( int option ) );
    wxDEPRECATED( int GetOption() const );

    void SetProportion( int proportion )
        { m_proportion = proportion; }
    int GetProportion() const
        { return m_proportion; }
    void SetFlag( int flag )
        { m_flag = flag; }
    int GetFlag() const
        { return m_flag; }
    void SetBorder( int border )
        { m_border = border; }
    int GetBorder() const
        { return m_border; }

    wxWindow *GetWindow() const
        { return m_window; }
    void SetWindow( wxWindow *window )
        { m_window = window; m_minSize = window->GetSize(); }
    wxSizer *GetSizer() const
        { return m_sizer; }
    void SetSizer( wxSizer *sizer )
        { m_sizer = sizer; }
    const wxSize &GetSpacer() const
        { return m_size; }
    void SetSpacer( const wxSize &size )
        { m_size = size; m_minSize = size; }

    void Show ( bool show );
    bool IsShown() const
        { return m_show; }

    wxObject* GetUserData() const
        { return m_userData; }
    wxPoint GetPosition() const
        { return m_pos; }

protected:
    // common part of several ctors
    void Init();

    // common part of ctors taking wxSizerFlags
    void Init(const wxSizerFlags& flags);


    wxWindow    *m_window;
    wxSizer     *m_sizer;
    wxSize       m_size;
    wxPoint      m_pos;
    wxSize       m_minSize;
    int          m_proportion;
    int          m_border;
    int          m_flag;

    // If true, then this item is considered in the layout
    // calculation.  Otherwise, it is skipped over.
    bool         m_show;

    // Aspect ratio can always be calculated from m_size,
    // but this would cause precision loss when the window
    // is shrunk.  It is safer to preserve the initial value.
    float        m_ratio;

    wxObject    *m_userData;

private:
    DECLARE_CLASS(wxSizerItem)
    DECLARE_NO_COPY_CLASS(wxSizerItem)
};

WX_DECLARE_EXPORTED_LIST( wxSizerItem, wxSizerItemList );


//---------------------------------------------------------------------------
// wxSizer
//---------------------------------------------------------------------------

class WXDLLEXPORT wxSizer: public wxObject, public wxClientDataContainer
{
public:
    wxSizer();
    ~wxSizer();

    // methods for adding elements to the sizer: there are Add/Insert/Prepend
    // overloads for each of window/sizer/spacer/wxSizerItem
    inline void Add( wxWindow *window,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL );
    inline void Add( wxSizer *sizer,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL );
    inline void Add( int width,
                     int height,
                     int proportion = 0,
                     int flag = 0,
                     int border = 0,
                     wxObject* userData = NULL );
    inline void Add( wxWindow *window, const wxSizerFlags& flags );
    inline void Add( wxSizer *sizer, const wxSizerFlags& flags );
    inline void Add( wxSizerItem *item );

    inline void AddSpacer(int size);
    inline void AddStretchSpacer(int prop = 1);

    inline void Insert( size_t index,
                        wxWindow *window,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL );
    inline void Insert( size_t index,
                        wxSizer *sizer,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL );
    inline void Insert( size_t index,
                        int width,
                        int height,
                        int proportion = 0,
                        int flag = 0,
                        int border = 0,
                        wxObject* userData = NULL );
    inline void Insert( size_t index,
                        wxWindow *window,
                        const wxSizerFlags& flags );
    inline void Insert( size_t index,
                        wxSizer *sizer,
                        const wxSizerFlags& flags );
    virtual void Insert( size_t index, wxSizerItem *item );

    inline void InsertSpacer(size_t index, int size);
    inline void InsertStretchSpacer(size_t index, int prop = 1);

    inline void Prepend( wxWindow *window,
                         int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL );
    inline void Prepend( wxSizer *sizer,
                         int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL );
    inline void Prepend( int width,
                         int height,
                         int proportion = 0,
                         int flag = 0,
                         int border = 0,
                         wxObject* userData = NULL );
    inline void Prepend( wxWindow *window, const wxSizerFlags& flags );
    inline void Prepend( wxSizer *sizer, const wxSizerFlags& flags );
    inline void Prepend( wxSizerItem *item );

    inline void PrependSpacer(int size);
    inline void PrependStretchSpacer(int prop = 1);


    // Deprecated in 2.6 since historically it does not delete the window,
    // use Detach instead.
    wxDEPRECATED( virtual bool Remove( wxWindow *window ) );
    virtual bool Remove( wxSizer *sizer );
    virtual bool Remove( int index );

    virtual bool Detach( wxWindow *window );
    virtual bool Detach( wxSizer *sizer );
    virtual bool Detach( int index );

    virtual void Clear( bool delete_windows = false );
    virtual void DeleteWindows();

    void SetMinSize( int width, int height )
        { DoSetMinSize( width, height ); }
    void SetMinSize( wxSize size )
        { DoSetMinSize( size.x, size.y ); }

    /* Searches recursively */
    bool SetItemMinSize( wxWindow *window, int width, int height )
        { return DoSetItemMinSize( window, width, height ); }
    bool SetItemMinSize( wxWindow *window, wxSize size )
        { return DoSetItemMinSize( window, size.x, size.y ); }

    /* Searches recursively */
    bool SetItemMinSize( wxSizer *sizer, int width, int height )
        { return DoSetItemMinSize( sizer, width, height ); }
    bool SetItemMinSize( wxSizer *sizer, wxSize size )
        { return DoSetItemMinSize( sizer, size.x, size.y ); }

    bool SetItemMinSize( size_t index, int width, int height )
        { return DoSetItemMinSize( index, width, height ); }
    bool SetItemMinSize( size_t index, wxSize size )
        { return DoSetItemMinSize( index, size.x, size.y ); }

    wxSize GetSize() const
        { return m_size; }
    wxPoint GetPosition() const
        { return m_position; }

    /* Calculate the minimal size or return m_minSize if bigger. */
    wxSize GetMinSize();

    virtual void RecalcSizes() = 0;
    virtual wxSize CalcMin() = 0;

    virtual void Layout();

    wxSize Fit( wxWindow *window );
    void FitInside( wxWindow *window );
    void SetSizeHints( wxWindow *window );
    void SetVirtualSizeHints( wxWindow *window );

    wxSizerItemList& GetChildren()
        { return m_children; }

    void SetDimension( int x, int y, int width, int height );

    // Manage whether individual scene items are considered
    // in the layout calculations or not.
    bool Show( wxWindow *window, bool show = true, bool recursive = false );
    bool Show( wxSizer *sizer, bool show = true, bool recursive = false );
    bool Show( size_t index, bool show = true );

    bool Hide( wxSizer *sizer, bool recursive = false )
        { return Show( sizer, false, recursive ); }
    bool Hide( wxWindow *window, bool recursive = false )
        { return Show( window, false, recursive ); }
    bool Hide( size_t index )
        { return Show( index, false ); }

    bool IsShown( wxWindow *window ) const;
    bool IsShown( wxSizer *sizer ) const;
    bool IsShown( size_t index ) const;

    // Recursively call wxWindow::Show () on all sizer items.
    virtual void ShowItems (bool show);

protected:
    wxSize              m_size;
    wxSize              m_minSize;
    wxPoint             m_position;
    wxSizerItemList     m_children;

    wxSize GetMaxWindowSize( wxWindow *window ) const;
    wxSize GetMinWindowSize( wxWindow *window );
    wxSize GetMaxClientSize( wxWindow *window ) const;
    wxSize GetMinClientSize( wxWindow *window );
    wxSize FitSize( wxWindow *window );
    wxSize VirtualFitSize( wxWindow *window );

    virtual void DoSetMinSize( int width, int height );
    virtual bool DoSetItemMinSize( wxWindow *window, int width, int height );
    virtual bool DoSetItemMinSize( wxSizer *sizer, int width, int height );
    virtual bool DoSetItemMinSize( size_t index, int width, int height );

private:
    DECLARE_CLASS(wxSizer)
};

//---------------------------------------------------------------------------
// wxGridSizer
//---------------------------------------------------------------------------

class WXDLLEXPORT wxGridSizer: public wxSizer
{
public:
    wxGridSizer( int rows, int cols, int vgap, int hgap );
    wxGridSizer( int cols, int vgap = 0, int hgap = 0 );

    virtual void RecalcSizes();
    virtual wxSize CalcMin();

    void SetCols( int cols )    { m_cols = cols; }
    void SetRows( int rows )    { m_rows = rows; }
    void SetVGap( int gap )     { m_vgap = gap; }
    void SetHGap( int gap )     { m_hgap = gap; }
    int GetCols() const         { return m_cols; }
    int GetRows() const         { return m_rows; }
    int GetVGap() const         { return m_vgap; }
    int GetHGap() const         { return m_hgap; }

protected:
    int    m_rows;
    int    m_cols;
    int    m_vgap;
    int    m_hgap;

    // return the number of total items and the number of columns and rows
    int CalcRowsCols(int& rows, int& cols) const;

    void SetItemBounds( wxSizerItem *item, int x, int y, int w, int h );

private:
    DECLARE_CLASS(wxGridSizer)
};

//---------------------------------------------------------------------------
// wxFlexGridSizer
//---------------------------------------------------------------------------

// the bevaiour for resizing wxFlexGridSizer cells in the "non-flexible"
// direction
enum wxFlexSizerGrowMode
{
    // don't resize the cells in non-flexible direction at all
    wxFLEX_GROWMODE_NONE,

    // uniformly resize only the specified ones (default)
    wxFLEX_GROWMODE_SPECIFIED,

    // uniformly resize all cells
    wxFLEX_GROWMODE_ALL
};

class WXDLLEXPORT wxFlexGridSizer: public wxGridSizer
{
public:
    // ctors/dtor
    wxFlexGridSizer( int rows, int cols, int vgap, int hgap );
    wxFlexGridSizer( int cols, int vgap = 0, int hgap = 0 );
    virtual ~wxFlexGridSizer();


    // set the rows/columns which will grow (the others will remain of the
    // constant initial size)
    void AddGrowableRow( size_t idx, int proportion = 0 );
    void RemoveGrowableRow( size_t idx );
    void AddGrowableCol( size_t idx, int proportion = 0 );
    void RemoveGrowableCol( size_t idx );


    // the sizer cells may grow in both directions, not grow at all or only
    // grow in one direction but not the other

    // the direction may be wxVERTICAL, wxHORIZONTAL or wxBOTH (default)
    void SetFlexibleDirection(int direction) { m_flexDirection = direction; }
    int GetFlexibleDirection() const { return m_flexDirection; }

    // note that the grow mode only applies to the direction which is not
    // flexible
    void SetNonFlexibleGrowMode(wxFlexSizerGrowMode mode) { m_growMode = mode; }
    wxFlexSizerGrowMode GetNonFlexibleGrowMode() const { return m_growMode; }

    // Read-only access to the row heights and col widths arrays
    const wxArrayInt& GetRowHeights() const { return m_rowHeights; }
    const wxArrayInt& GetColWidths() const  { return m_colWidths; }

    // implementation
    virtual void RecalcSizes();
    virtual wxSize CalcMin();

protected:
    void AdjustForFlexDirection();
    void AdjustForGrowables(const wxSize& sz, const wxSize& minsz,
                            int nrows, int ncols);

    // the heights/widths of all rows/columns
    wxArrayInt  m_rowHeights,
                m_colWidths;

    // indices of the growable columns and rows
    wxArrayInt  m_growableRows,
                m_growableCols;

    // proportion values of the corresponding growable rows and columns
    wxArrayInt  m_growableRowsProportions,
                m_growableColsProportions;

    // parameters describing whether the growable cells should be resized in
    // both directions or only one
    int m_flexDirection;
    wxFlexSizerGrowMode m_growMode;

    // saves CalcMin result to optimize RecalcSizes
    wxSize m_calculatedMinSize;

private:
    DECLARE_CLASS(wxFlexGridSizer)
    DECLARE_NO_COPY_CLASS(wxFlexGridSizer)
};

//---------------------------------------------------------------------------
// wxBoxSizer
//---------------------------------------------------------------------------

class WXDLLEXPORT wxBoxSizer: public wxSizer
{
public:
    wxBoxSizer( int orient );

    void RecalcSizes();
    wxSize CalcMin();

    int GetOrientation() const
        { return m_orient; }

    void SetOrientation(int orient)
        { m_orient = orient; }

protected:
    int m_orient;
    int m_stretchable;
    int m_minWidth;
    int m_minHeight;
    int m_fixedWidth;
    int m_fixedHeight;

private:
    DECLARE_CLASS(wxBoxSizer)
};

//---------------------------------------------------------------------------
// wxStaticBoxSizer
//---------------------------------------------------------------------------

#if wxUSE_STATBOX

class WXDLLEXPORT wxStaticBox;

class WXDLLEXPORT wxStaticBoxSizer: public wxBoxSizer
{
public:
    wxStaticBoxSizer( wxStaticBox *box, int orient );

    void RecalcSizes();
    wxSize CalcMin();

    wxStaticBox *GetStaticBox() const
        { return m_staticBox; }

    // override to hide/show the static box as well
    virtual void ShowItems (bool show);

protected:
    wxStaticBox   *m_staticBox;

private:
    DECLARE_CLASS(wxStaticBoxSizer)
    DECLARE_NO_COPY_CLASS(wxStaticBoxSizer)
};

#endif // wxUSE_STATBOX


#if WXWIN_COMPATIBILITY_2_4
// NB: wxBookCtrlSizer and wxNotebookSizer are deprecated, they
//     don't do anything. wxBookCtrl::DoGetBestSize does the job now.

// ----------------------------------------------------------------------------
// wxBookCtrlSizer
// ----------------------------------------------------------------------------

#if wxUSE_BOOKCTRL

// this sizer works with wxNotebook/wxListbook/... and sizes the control to
// fit its pages
class WXDLLEXPORT wxBookCtrl;

class WXDLLEXPORT wxBookCtrlSizer : public wxSizer
{
public:
    wxDEPRECATED( wxBookCtrlSizer(wxBookCtrl *bookctrl) );

    wxBookCtrl *GetControl() const { return m_bookctrl; }

    virtual void RecalcSizes();
    virtual wxSize CalcMin();

protected:
    // this protected ctor lets us mark the real one above as deprecated
    // and still have warning-free build of the library itself:
    wxBookCtrlSizer() {}

    wxBookCtrl *m_bookctrl;

private:
    DECLARE_CLASS(wxBookCtrlSizer)
    DECLARE_NO_COPY_CLASS(wxBookCtrlSizer)
};


#if wxUSE_NOTEBOOK

// before wxBookCtrl we only had wxNotebookSizer, keep it for backwards
// compatibility
class WXDLLEXPORT wxNotebook;

class WXDLLEXPORT wxNotebookSizer : public wxBookCtrlSizer
{
public:
    wxDEPRECATED( wxNotebookSizer(wxNotebook *nb) );

    wxNotebook *GetNotebook() const { return (wxNotebook *)m_bookctrl; }

private:
    DECLARE_CLASS(wxNotebookSizer)
    DECLARE_NO_COPY_CLASS(wxNotebookSizer)
};

#endif // wxUSE_NOTEBOOK

#endif // wxUSE_BOOKCTRL

#endif // WXWIN_COMPATIBILITY_2_4

// ----------------------------------------------------------------------------
// inline functions implementation
// ----------------------------------------------------------------------------

inline void
wxSizer::Add( wxWindow *window, int proportion, int flag, int border, wxObject* userData )
{
    Add( new wxSizerItem( window, proportion, flag, border, userData ) );
}

inline void
wxSizer::Add( wxSizer *sizer, int proportion, int flag, int border, wxObject* userData )
{
    Add( new wxSizerItem( sizer, proportion, flag, border, userData ) );
}

inline void
wxSizer::Add( int width, int height, int proportion, int flag, int border, wxObject* userData )
{
    Add( new wxSizerItem( width, height, proportion, flag, border, userData ) );
}

inline void
wxSizer::Add( wxWindow *window, const wxSizerFlags& flags )
{
    Add( new wxSizerItem(window, flags) );
}

inline void
wxSizer::Add( wxSizer *sizer, const wxSizerFlags& flags )
{
    Add( new wxSizerItem(sizer, flags) );
}

inline void
wxSizer::Add( wxSizerItem *item )
{
    Insert( m_children.GetCount(), item );
}

inline void
wxSizer::AddSpacer(int size)
{
    Add(size, size);
}

inline void
wxSizer::AddStretchSpacer(int prop)
{
    Add(0, 0, prop);
}

inline void
wxSizer::Prepend( wxWindow *window, int proportion, int flag, int border, wxObject* userData )
{
    Prepend( new wxSizerItem( window, proportion, flag, border, userData ) );
}

inline void
wxSizer::Prepend( wxSizer *sizer, int proportion, int flag, int border, wxObject* userData )
{
    Prepend( new wxSizerItem( sizer, proportion, flag, border, userData ) );
}

inline void
wxSizer::Prepend( int width, int height, int proportion, int flag, int border, wxObject* userData )
{
    Prepend( new wxSizerItem( width, height, proportion, flag, border, userData ) );
}

inline void
wxSizer::Prepend( wxSizerItem *item )
{
    Insert( 0, item );
}

inline void
wxSizer::PrependSpacer(int size)
{
    Prepend(size, size);
}

inline void
wxSizer::PrependStretchSpacer(int prop)
{
    Prepend(0, 0, prop);
}

inline void
wxSizer::Prepend( wxWindow *window, const wxSizerFlags& flags )
{
    Prepend( new wxSizerItem(window, flags) );
}

inline void
wxSizer::Prepend( wxSizer *sizer, const wxSizerFlags& flags )
{
    Prepend( new wxSizerItem(sizer, flags) );
}

inline void
wxSizer::Insert( size_t index,
                 wxWindow *window,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData )
{
    Insert( index, new wxSizerItem( window, proportion, flag, border, userData ) );
}

inline void
wxSizer::Insert( size_t index,
                 wxSizer *sizer,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData )
{
    Insert( index, new wxSizerItem( sizer, proportion, flag, border, userData ) );
}

inline void
wxSizer::Insert( size_t index,
                 int width,
                 int height,
                 int proportion,
                 int flag,
                 int border,
                 wxObject* userData )
{
    Insert( index, new wxSizerItem( width, height, proportion, flag, border, userData ) );
}

inline void
wxSizer::Insert( size_t index, wxWindow *window, const wxSizerFlags& flags )
{
    Insert( index, new wxSizerItem(window, flags) );
}

inline void
wxSizer::Insert( size_t index, wxSizer *sizer, const wxSizerFlags& flags )
{
    Insert( index, new wxSizerItem(sizer, flags) );
}

inline void
wxSizer::InsertSpacer(size_t index, int size)
{
    Insert(index, size, size);
}

inline void
wxSizer::InsertStretchSpacer(size_t index, int prop)
{
    Insert(index, 0, 0, prop);
}


#endif // __WXSIZER_H__

