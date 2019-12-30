/////////////////////////////////////////////////////////////////////////////
// Name:        _core_api.i
// Purpose:
//
// Author:      Robin Dunn
//
// Created:     13-Sept-2003
// RCS-ID:      $Id: _core_api.i,v 1.9 2004/09/23 20:23:19 RD Exp $
// Copyright:   (c) 2003 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

// Not a %module


//---------------------------------------------------------------------------
%{
#ifndef wxPyUSE_EXPORT
// Helper functions for dealing with SWIG objects and such.  These are
// located here so they know about the SWIG types and functions declared
// in the wrapper code.

#include <wx/hashmap.h>
WX_DECLARE_STRING_HASH_MAP( swig_type_info*, wxPyTypeInfoHashMap );


// Maintains a hashmap of className to swig_type_info pointers.  Given the
// name of a class either looks up the type info in the cache, or scans the
// SWIG tables for it.
extern PyObject* wxPyPtrTypeMap; 
static
swig_type_info* wxPyFindSwigType(const wxChar* className) {

    static wxPyTypeInfoHashMap* typeInfoCache = NULL;

    if (typeInfoCache == NULL)
        typeInfoCache = new wxPyTypeInfoHashMap;

    wxString name(className);
    swig_type_info* swigType = (*typeInfoCache)[name];

    if (! swigType) {
        // it wasn't in the cache, so look it up from SWIG
        name.Append(wxT(" *"));
        swigType = SWIG_Python_TypeQuery(name.mb_str());
        
        // if it still wasn't found, try looking for a mapped name
        if (!swigType) {
            PyObject* item;
            name = className;
            
            if ((item = PyDict_GetItemString(wxPyPtrTypeMap,
                               (char*)(const char*)name.mbc_str())) != NULL) {
                name = wxString(PyString_AsString(item), *wxConvCurrent);
                name.Append(wxT(" *"));
                swigType = SWIG_Python_TypeQuery(name.mb_str());
            }
        }
        if (swigType) {
            // and add it to the map if found
            (*typeInfoCache)[className] = swigType;
        }
    }
    return swigType;    
}


// Check if a class name is a type known to SWIG
bool wxPyCheckSwigType(const wxChar* className) {

    swig_type_info* swigType = wxPyFindSwigType(className);
    return swigType != NULL;
}
 
    
// Given a pointer to a C++ object and a class name, construct a Python proxy
// object for it.    
PyObject* wxPyConstructObject(void* ptr,
                              const wxChar* className,
                              int setThisOwn) {

    swig_type_info* swigType = wxPyFindSwigType(className);
    wxCHECK_MSG(swigType != NULL, NULL, wxT("Unknown type in wxPyConstructObject"));

    return SWIG_Python_NewPointerObj(ptr, swigType, setThisOwn);
}


// Extract a pointer to the wrapped C++ object from a Python proxy object.
// Ensures that the proxy object is of the specified (or derived) type.  If
// not able to perform the conversion then a Python exception is set and the
// error should be handled properly in the caller.  Returns True on success.
bool wxPyConvertSwigPtr(PyObject* obj, void **ptr,
                        const wxChar* className) {

    swig_type_info* swigType = wxPyFindSwigType(className);
    wxCHECK_MSG(swigType != NULL, false, wxT("Unknown type in wxPyConvertSwigPtr"));

    return SWIG_Python_ConvertPtr(obj, ptr, swigType, SWIG_POINTER_EXCEPTION) != -1;
}


// Make a SWIGified pointer object suitable for a .this attribute
PyObject* wxPyMakeSwigPtr(void* ptr, const wxChar* className) {
    
    PyObject* robj = NULL;

    swig_type_info* swigType = wxPyFindSwigType(className);
    wxCHECK_MSG(swigType != NULL, NULL, wxT("Unknown type in wxPyConvertSwigPtr"));

#ifdef SWIG_COBJECT_TYPES
    robj = PyCObject_FromVoidPtrAndDesc((void *) ptr, (char *) swigType->name, NULL);
#else
    {
        char result[1024];
        char *r = result;
        *(r++) = '_';
        r = SWIG_Python_PackData(r, &ptr, sizeof(void *));
        strcpy(r, swigType->name);
        robj = PyString_FromString(result);
    }     
#endif

    return robj;
}




// Export a C API in a struct.  Other modules will be able to load this from
// the wx._core_ module and will then have safe access to these functions,
// even if they are located in another shared library.
static wxPyCoreAPI API = {

    (p_SWIG_Python_TypeRegister_t)SWIG_Python_TypeRegister,
    (p_SWIG_Python_TypeCheck_t)SWIG_Python_TypeCheck,
    (p_SWIG_Python_TypeCast_t)SWIG_Python_TypeCast,
    (p_SWIG_Python_TypeDynamicCast_t)SWIG_Python_TypeDynamicCast,
    (p_SWIG_Python_TypeName_t)SWIG_Python_TypeName,
    (p_SWIG_Python_TypePrettyName_t)SWIG_Python_TypePrettyName,
    (p_SWIG_Python_TypeQuery_t)SWIG_Python_TypeQuery,
    (p_SWIG_Python_TypeClientData_t)SWIG_Python_TypeClientData,
    (p_SWIG_Python_newvarlink_t)SWIG_Python_newvarlink,
    (p_SWIG_Python_addvarlink_t)SWIG_Python_addvarlink,
    (p_SWIG_Python_ConvertPtr_t)SWIG_Python_ConvertPtr,
    (p_SWIG_Python_ConvertPacked_t)SWIG_Python_ConvertPacked,
    (p_SWIG_Python_PackData_t)SWIG_Python_PackData,
    (p_SWIG_Python_UnpackData_t)SWIG_Python_UnpackData,
    (p_SWIG_Python_NewPointerObj_t)SWIG_Python_NewPointerObj,
    (p_SWIG_Python_NewPackedObj_t)SWIG_Python_NewPackedObj,
    (p_SWIG_Python_InstallConstants_t)SWIG_Python_InstallConstants,
    (p_SWIG_Python_MustGetPtr_t)SWIG_Python_MustGetPtr,

    wxPyCheckSwigType,
    wxPyConstructObject,
    wxPyConvertSwigPtr,
    wxPyMakeSwigPtr,
                                             
    wxPyBeginAllowThreads,
    wxPyEndAllowThreads,
    wxPyBeginBlockThreads,
    wxPyEndBlockThreads,
                                             
    wxPy_ConvertList,
                                             
    wxString_in_helper,
    Py2wxString,
    wx2PyString,
                                             
    byte_LIST_helper,
    int_LIST_helper,
    long_LIST_helper,
    string_LIST_helper,
    wxPoint_LIST_helper,
    wxBitmap_LIST_helper,
    wxString_LIST_helper,
    wxAcceleratorEntry_LIST_helper,
                                             
    wxSize_helper,
    wxPoint_helper,
    wxRealPoint_helper,
    wxRect_helper,
    wxColour_helper,
    wxPoint2D_helper,
                                             
    wxPySimple_typecheck,
    wxColour_typecheck,

    wxPyCBH_setCallbackInfo,
    wxPyCBH_findCallback,
    wxPyCBH_callCallback,
    wxPyCBH_callCallbackObj,
    wxPyCBH_delete,
                                             
    wxPyMake_wxObject,
    wxPyMake_wxSizer,
    wxPyPtrTypeMap_Add,
    wxPy2int_seq_helper,
    wxPy4int_seq_helper,
    wxArrayString2PyList_helper,
    wxArrayInt2PyList_helper,
                                             
    wxPyClientData_dtor,
    wxPyUserData_dtor,
    wxPyOORClientData_dtor,
                                             
    wxPyCBInputStream_create,

    wxPyInstance_Check,
    wxPySwigInstance_Check,

    wxPyCheckForApp

};

#endif
%}




%init %{
#ifndef wxPyUSE_EXPORT
    // Make our API structure a CObject so other modules can import it
    // from this module.
    PyObject* cobj = PyCObject_FromVoidPtr(&API, NULL);
    PyDict_SetItemString(d,"_wxPyCoreAPI", cobj);
    Py_XDECREF(cobj);
#endif
%}

//---------------------------------------------------------------------------
