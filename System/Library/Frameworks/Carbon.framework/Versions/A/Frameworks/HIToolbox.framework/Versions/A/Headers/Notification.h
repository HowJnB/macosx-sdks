/*
     File:       HIToolbox/Notification.h
 
     Contains:   Notification Manager interfaces
 
     Version:    HIToolbox-124.14~2
 
     Copyright:  � 1989-2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __NOTIFICATION__
#define __NOTIFICATION__

#ifndef __CORESERVICES__
#include <CoreServices/CoreServices.h>
#endif


#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

typedef struct NMRec                    NMRec;
typedef NMRec *                         NMRecPtr;
typedef CALLBACK_API( void , NMProcPtr )(NMRecPtr nmReqPtr);
typedef STACK_UPP_TYPE(NMProcPtr)                               NMUPP;
struct NMRec {
  QElemPtr            qLink;                  /* next queue entry*/
  short               qType;                  /* queue type -- ORD(nmType) = 8*/
  short               nmFlags;                /* reserved*/
  long                nmPrivate;              /* reserved*/
  short               nmReserved;             /* reserved*/
  short               nmMark;                 /* item to mark in Apple menu*/
  Handle              nmIcon;                 /* handle to small icon*/
  Handle              nmSound;                /* handle to sound record*/
  StringPtr           nmStr;                  /* string to appear in alert*/
  NMUPP               nmResp;                 /* pointer to response routine*/
  long                nmRefCon;               /* for application use*/
};

/*
 *  NewNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern NMUPP
NewNMUPP(NMProcPtr userRoutine)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeNMUPP(NMUPP userUPP)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeNMUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeNMUPP(
  NMRecPtr  nmReqPtr,
  NMUPP     userUPP)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NMInstall()
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern OSErr 
NMInstall(NMRecPtr nmReqPtr)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NMRemove()
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in InterfaceLib 7.1 and later
 */
extern OSErr 
NMRemove(NMRecPtr nmReqPtr)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __NOTIFICATION__ */

