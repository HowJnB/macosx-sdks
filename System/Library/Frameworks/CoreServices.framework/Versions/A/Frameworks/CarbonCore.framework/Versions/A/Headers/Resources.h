/*
     File:       CarbonCore/Resources.h
 
     Contains:   Resource Manager Interfaces.
 
     Version:    CarbonCore-317~6
 
     Copyright:  � 1985-2001 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __RESOURCES__
#define __RESOURCES__

#ifndef __MACTYPES__
#include <CarbonCore/MacTypes.h>
#endif

#ifndef __MIXEDMODE__
#include <CarbonCore/MixedMode.h>
#endif

#ifndef __FILES__
#include <CarbonCore/Files.h>
#endif




#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_STRUCT_ALIGN
    #pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
    #pragma pack(2)
#endif


enum {
  resSysHeap                    = 64,   /*System or application heap?*/
  resPurgeable                  = 32,   /*Purgeable resource?*/
  resLocked                     = 16,   /*Load it in locked?*/
  resProtected                  = 8,    /*Protected?*/
  resPreload                    = 4,    /*Load in on OpenResFile?*/
  resChanged                    = 2,    /*Resource changed?*/
  mapReadOnly                   = 128,  /*Resource file read-only*/
  mapCompact                    = 64,   /*Compact resource file*/
  mapChanged                    = 32    /*Write map out at update*/
};

enum {
  resSysRefBit                  = 7,    /*reference to system/local reference*/
  resSysHeapBit                 = 6,    /*In system/in application heap*/
  resPurgeableBit               = 5,    /*Purgeable/not purgeable*/
  resLockedBit                  = 4,    /*Locked/not locked*/
  resProtectedBit               = 3,    /*Protected/not protected*/
  resPreloadBit                 = 2,    /*Read in at OpenResource?*/
  resChangedBit                 = 1,    /*Existing resource changed since last update*/
  mapReadOnlyBit                = 7,    /*is this file read-only?*/
  mapCompactBit                 = 6,    /*Is a compact necessary?*/
  mapChangedBit                 = 5     /*Is it necessary to write map?*/
};

enum {
  kResFileNotOpened             = -1,   /*ref num return as error when opening a resource file*/
  kSystemResFile                = 0     /*this is the default ref num to the system file*/
};


typedef CALLBACK_API( void , ResErrProcPtr )(OSErr thErr);
typedef STACK_UPP_TYPE(ResErrProcPtr)                           ResErrUPP;
/*
 *  NewResErrUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ResErrUPP
NewResErrUPP(ResErrProcPtr userRoutine);

/*
 *  DisposeResErrUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeResErrUPP(ResErrUPP userUPP);

/*
 *  InvokeResErrUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeResErrUPP(
  OSErr      thErr,
  ResErrUPP  userUPP);

/* QuickTime 3.0*/
typedef CALLBACK_API( OSErr , ResourceEndianFilterPtr )(Handle theResource, Boolean currentlyNativeEndian);
/*
 *  InitResources()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  RsrcZoneInit()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  CloseResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
CloseResFile(short refNum);


/*
 *  ResError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern OSErr 
ResError(void);


/*
 *  CurResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
CurResFile(void);


/*
 *  HomeResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
HomeResFile(Handle theResource);


/*
 *  CreateResFile()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  OpenResFile()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  UseResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
UseResFile(short refNum);


/*
 *  CountTypes()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
CountTypes(void);


/*
 *  Count1Types()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
Count1Types(void);


/*
 *  GetIndType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
GetIndType(
  ResType *  theType,
  short      index);


/*
 *  Get1IndType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
Get1IndType(
  ResType *  theType,
  short      index);


/*
 *  SetResLoad()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResLoad(Boolean load);


/*
 *  CountResources()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
CountResources(ResType theType);


/*
 *  Count1Resources()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
Count1Resources(ResType theType);


/*
 *  GetIndResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
GetIndResource(
  ResType   theType,
  short     index);


/*
 *  Get1IndResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
Get1IndResource(
  ResType   theType,
  short     index);


/*
 *  GetResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
GetResource(
  ResType   theType,
  short     theID);


/*
 *  Get1Resource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
Get1Resource(
  ResType   theType,
  short     theID);


/*
 *  GetNamedResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
GetNamedResource(
  ResType            theType,
  ConstStr255Param   name);


/*
 *  Get1NamedResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
Get1NamedResource(
  ResType            theType,
  ConstStr255Param   name);


/*
 *  [Mac]LoadResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
#if TARGET_OS_MAC
    #define MacLoadResource LoadResource
#endif
extern void 
MacLoadResource(Handle theResource);


/*
 *  ReleaseResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
ReleaseResource(Handle theResource);


/*
 *  DetachResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
DetachResource(Handle theResource);


/*
 *  UniqueID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
UniqueID(ResType theType);


/*
 *  Unique1ID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
Unique1ID(ResType theType);


/*
 *  GetResAttrs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
GetResAttrs(Handle theResource);


/*
 *  GetResInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
GetResInfo(
  Handle     theResource,
  short *    theID,
  ResType *  theType,
  Str255     name);


/*
 *  SetResInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResInfo(
  Handle             theResource,
  short              theID,
  ConstStr255Param   name);


/*
 *  AddResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
AddResource(
  Handle             theData,
  ResType            theType,
  short              theID,
  ConstStr255Param   name);


/*
 *  GetResourceSizeOnDisk()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern long 
GetResourceSizeOnDisk(Handle theResource);


/*
 *  GetMaxResourceSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern long 
GetMaxResourceSize(Handle theResource);


/*
 *  RsrcMapEntry()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  SetResAttrs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResAttrs(
  Handle   theResource,
  short    attrs);


/*
 *  ChangedResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
ChangedResource(Handle theResource);


/*
 *  RemoveResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
RemoveResource(Handle theResource);


/*
 *  UpdateResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
UpdateResFile(short refNum);


/*
 *  WriteResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
WriteResource(Handle theResource);


/*
 *  SetResPurge()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResPurge(Boolean install);


/*
 *  GetResFileAttrs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
GetResFileAttrs(short refNum);


/*
 *  SetResFileAttrs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResFileAttrs(
  short   refNum,
  short   attrs);


/*
 *  OpenRFPerm()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
OpenRFPerm(
  ConstStr255Param   fileName,
  short              vRefNum,
  SInt8              permission);


/*
 *  RGetResource()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  HOpenResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
HOpenResFile(
  short              vRefNum,
  long               dirID,
  ConstStr255Param   fileName,
  SInt8              permission);


/*
 *  HCreateResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
HCreateResFile(
  short              vRefNum,
  long               dirID,
  ConstStr255Param   fileName);


/*
 *  FSpOpenResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern short 
FSpOpenResFile(
  const FSSpec *  spec,
  SignedByte      permission);


/*
 *  FSpCreateResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
FSpCreateResFile(
  const FSSpec *  spec,
  OSType          creator,
  OSType          fileType,
  ScriptCode      scriptTag);


/*
 *  ReadPartialResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
ReadPartialResource(
  Handle   theResource,
  long     offset,
  void *   buffer,
  long     count);


/*
 *  WritePartialResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
WritePartialResource(
  Handle        theResource,
  long          offset,
  const void *  buffer,
  long          count);


/*
 *  SetResourceSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern void 
SetResourceSize(
  Handle   theResource,
  long     newSize);


/*
 *  GetNextFOND()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern Handle 
GetNextFOND(Handle fondHandle);


/* QuickTime 3.0*/
/*
 *  RegisterResourceEndianFilter()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */


/* Use TempInsertROMMap to force the ROM resource map to be
   inserted into the chain in front of the system. Note that
   this call is only temporary - the modified resource chain
   is only used for the next call to the resource manager.
   See IM IV 19 for more information. 
*/
/*
 *  TempInsertROMMap()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
  _________________________________________________________________________________________________________
      
   � RESOURCE CHAIN LOCATION - for use with the Resource Manager chain manipulation routines under Carbon.
  _________________________________________________________________________________________________________
*/

typedef SInt16                          RsrcChainLocation;
enum {
  kRsrcChainBelowSystemMap      = 0,    /* Below the system's resource map*/
  kRsrcChainBelowApplicationMap = 1,    /* Below the application's resource map*/
  kRsrcChainAboveApplicationMap = 2,    /* Above the application's resource map*/
  kRsrcChainAboveAllMaps        = 4     /* Above all resource maps*/
};

/*
   If the file is already in the resource chain, it is removed and re-inserted at the specified location
   If the file has been detached, it is added to the resource chain at the specified location
   Returns resFNotFound if it's not currently open.
*/
/*
 *  InsertResourceFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
InsertResourceFile(
  SInt16              refNum,
  RsrcChainLocation   where);


/*
   If the file is not currently in the resource chain, this returns resNotFound
   Otherwise, the resource file is removed from the resource chain.
*/
/*
 *  DetachResourceFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
DetachResourceFile(SInt16 refNum);


/*
   Returns true if the resource file is already open and known by the Resource Manager (i.e., it is
   either in the current resource chain or it's a detached resource file.)  If it's in the resource 
   chain, the inChain Boolean is set to true on exit and true is returned.  If it's an open file, but
   the file is currently detached, inChain is set to false and true is returned.  If the file is open,
   the refNum to the file is returned.
*/
/*
 *  FSpResourceFileAlreadyOpen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 9.0 and later
 */
extern Boolean 
FSpResourceFileAlreadyOpen(
  const FSSpec *  resourceFile,
  Boolean *       inChain,
  SInt16 *        refNum);


/*
   FSpOpenOrphanResFile should be used to open a resource file that is persistent across all contexts,
   because using OpenResFile normally loads a map and all preloaded resources into the application
   context.  FSpOpenOrphanResFile loads everything into the system context and detaches the file 
   from the context in which it was opened.  If the file is already in the resource chain and a new
   instance is not opened, FSpOpenOrphanResFile will return a paramErr.
   Use with care, as can and will fail if the map is very large or a lot of preload
   resources exist.
*/
/*
 *  FSpOpenOrphanResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
FSpOpenOrphanResFile(
  const FSSpec *  spec,
  SignedByte      permission,
  SInt16 *        refNum);


/*
   GetTopResourceFile returns the refNum of the top most resource map in the current resource chain. If
   the resource chain is empty it returns resFNotFound.
*/
/*
 *  GetTopResourceFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
GetTopResourceFile(SInt16 * refNum);


/*
   GetNextResourceFile can be used to iterate over resource files in the resource chain. By passing a
   valid refNum in curRefNum it will return in nextRefNum the refNum of the next file in 
   the chain. If curRefNum is not found in the resource chain, GetNextResourceFile returns resFNotFound.
   When the end of the chain is reached GetNextResourceFile will return noErr and nextRefNum will be NIL.
*/
/*
 *  GetNextResourceFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
GetNextResourceFile(
  SInt16    curRefNum,
  SInt16 *  nextRefNum);



/*
 *  getnamedresource()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  get1namedresource()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  openrfperm()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  openresfile()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  createresfile()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  getresinfo()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  setresinfo()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


/*
 *  addresource()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */


#if OLDROUTINENAMES
#define SizeResource(theResource) GetResourceSizeOnDisk(theResource)
#define MaxSizeRsrc(theResource) GetMaxResourceSize(theResource)
#define RmveResource(theResource) RemoveResource(theResource)
#endif  /* OLDROUTINENAMES */

/*
 *  FSOpenResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in InterfaceLib 9.1 and later
 */
extern short 
FSOpenResFile(
  const FSRef *  ref,
  SInt8          permission);


/*
 *  FSCreateResFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in InterfaceLib 9.1 and later
 */
extern void 
FSCreateResFile(
  const FSRef *          parentRef,
  UniCharCount           nameLength,
  const UniChar *        name,
  FSCatalogInfoBitmap    whichInfo,
  const FSCatalogInfo *  catalogInfo,
  FSRef *                newRef,
  FSSpec *               newSpec);


/*
 *  FSResourceFileAlreadyOpen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in InterfaceLib 9.1 and later
 */
extern Boolean 
FSResourceFileAlreadyOpen(
  const FSRef *  resourceFileRef,
  Boolean *      inChain,
  SInt16 *       refNum);


/*
 *  FSCreateResourceFile()
 *  
 *  Summary:
 *    Creates a new resource file.
 *  
 *  Discussion:
 *    This function creates a new file and initializes the specified
 *    named fork as an empty resource fork.  This function allows for
 *    the creation of data fork only files which can be used for
 *    storing resources.  Passing in a null name defaults to using the
 *    data fork.
 *  
 *  Parameters:
 *    
 *    parentRef:
 *      The directory where the file is to be created
 *    
 *    nameLength:
 *      Number of Unicode characters in the file's name
 *    
 *    name:
 *      A pointer to the Unicode name
 *    
 *    whichInfo:
 *      Which catalog info fields to set
 *    
 *    catalogInfo:
 *      The values for catalog info fields to set; may be NULL
 *    
 *    forkNameLength:
 *      The length of the fork name (in Unicode characters)
 *    
 *    forkName:
 *      The name of the fork to initialize (in Unicode); may be NULL
 *    
 *    newRef:
 *      A pointer to the FSRef for the new file; may be NULL
 *    
 *    newSpec:
 *      A pointer to the FSSpec for the new directory; may be NULL
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
FSCreateResourceFile(
  const FSRef *          parentRef,
  UniCharCount           nameLength,
  const UniChar *        name,
  FSCatalogInfoBitmap    whichInfo,
  const FSCatalogInfo *  catalogInfo,          /* can be NULL */
  UniCharCount           forkNameLength,
  const UniChar *        forkName,             /* can be NULL */
  FSRef *                newRef,               /* can be NULL */
  FSSpec *               newSpec);             /* can be NULL */


/*
 *  FSOpenResourceFile()
 *  
 *  Summary:
 *    Opens the specified named fork as a resource fork.
 *  
 *  Discussion:
 *    This function allows any named fork of a file to be used for
 *    storing resources.  Passing in a null forkname will result in the
 *    data fork being used.
 *  
 *  Parameters:
 *    
 *    ref:
 *      The file containing the fork to open
 *    
 *    forkNameLength:
 *      The length of the fork name (in Unicode characters)
 *    
 *    forkName:
 *      The name of the fork to open (in Unicode); may be NULL
 *    
 *    permissions:
 *      The access (read and/or write) you want
 *    
 *    refNum:
 *      On exit the reference number for accessing the open fork
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
FSOpenResourceFile(
  const FSRef *    ref,
  UniCharCount     forkNameLength,
  const UniChar *  forkName,             /* can be NULL */
  SInt8            permissions,
  SInt16 *         refNum);


/*
    These typedefs were originally created for the Copland Resource Mangager
*/
typedef short                           ResFileRefNum;
typedef short                           ResID;
typedef short                           ResAttributes;
typedef short                           ResFileAttributes;
/*
 *  SortResourceFile()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in InterfaceLib 9.2 and later
 */





#if PRAGMA_STRUCT_ALIGN
    #pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
    #pragma pack()
#endif

#ifdef __cplusplus
}
#endif

#endif /* __RESOURCES__ */

