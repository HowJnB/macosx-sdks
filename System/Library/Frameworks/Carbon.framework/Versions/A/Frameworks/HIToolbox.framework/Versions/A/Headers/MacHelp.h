/*
     File:       HIToolbox/MacHelp.h
 
     Contains:   Macintosh Help Package Interfaces.
 
     Version:    HIToolbox-124.14~2
 
     Copyright:  � 1998-2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __MACHELP__
#define __MACHELP__

#ifndef __BALLOONS__
#include <HIToolbox/Balloons.h>
#endif

#ifndef __CONTROLS__
#include <HIToolbox/Controls.h>
#endif

#ifndef __DIALOGS__
#include <HIToolbox/Dialogs.h>
#endif

#ifndef __EVENTS__
#include <HIToolbox/Events.h>
#endif

#ifndef __MACWINDOWS__
#include <HIToolbox/MacWindows.h>
#endif

#ifndef __MENUS__
#include <HIToolbox/Menus.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

/*����������������������������������������������������������������������������������*/
/* Help Manager constants, etc.                                                     */
/*����������������������������������������������������������������������������������*/
enum {
  kMacHelpVersion               = 0x0003
};

typedef SInt16 HMContentRequest;
enum {
  kHMSupplyContent              = 0,
  kHMDisposeContent             = 1
};

typedef UInt32 HMContentType;
enum {
  kHMNoContent                  = 'none',
  kHMCFStringContent            = 'cfst', /* CFStringRef*/
  kHMCFStringLocalizedContent   = 'cfsl', /* CFStringRef; name of a localized string. Supported by Jaguar and later.*/
  kHMPascalStrContent           = 'pstr',
  kHMStringResContent           = 'str#',
  kHMTEHandleContent            = 'txth', /* Supported by CarbonLib and Jaguar and later*/
  kHMTextResContent             = 'text', /* Supported by CarbonLib and Jaguar and later*/
  kHMStrResContent              = 'str '
};


/*
 *  HMTagDisplaySide
 *  
 *  Discussion:
 *    Help tag display locations relative to absolute hot rect
 */
typedef SInt16 HMTagDisplaySide;
enum {

  /*
   * System default location
   */
  kHMDefaultSide                = 0,

  /*
   * Above, aligned with left or right depending on system script
   */
  kHMOutsideTopScriptAligned    = 1,

  /*
   * To the left, centered vertically
   */
  kHMOutsideLeftCenterAligned   = 2,
  kHMOutsideBottomScriptAligned = 3,

  /*
   * To the right, centered vertically
   */
  kHMOutsideRightCenterAligned  = 4,

  /*
   * Above, aligned with left
   */
  kHMOutsideTopLeftAligned      = 5,

  /*
   * Above, aligned with right
   */
  kHMOutsideTopRightAligned     = 6,

  /*
   * To the left, aligned with top
   */
  kHMOutsideLeftTopAligned      = 7,

  /*
   * To the left, aligned with bottom
   */
  kHMOutsideLeftBottomAligned   = 8,

  /*
   * To the right, aligned with top
   */
  kHMOutsideBottomLeftAligned   = 9,

  /*
   * To the right, aligned with bottom
   */
  kHMOutsideBottomRightAligned  = 10,
  kHMOutsideRightTopAligned     = 11,
  kHMOutsideRightBottomAligned  = 12,

  /*
   * Above, centered horizontally
   */
  kHMOutsideTopCenterAligned    = 13,

  /*
   * Below, centered horizontally
   */
  kHMOutsideBottomCenterAligned = 14,

  /*
   * Inside, aligned with right, centered vertically
   */
  kHMInsideRightCenterAligned   = 15,

  /*
   * Inside, aligned with left, centered vertically
   */
  kHMInsideLeftCenterAligned    = 16,

  /*
   * Inside, aligned with bottom, centered horizontally
   */
  kHMInsideBottomCenterAligned  = 17,

  /*
   * Inside, aligned with top, centered horizontally
   */
  kHMInsideTopCenterAligned     = 18,

  /*
   * Inside, aligned with top and left
   */
  kHMInsideTopLeftCorner        = 19,

  /*
   * Inside, aligned with top and right
   */
  kHMInsideTopRightCorner       = 20,

  /*
   * Inside, aligned with bottom and left
   */
  kHMInsideBottomLeftCorner     = 21,

  /*
   * Inside, aligned with bottom and right
   */
  kHMInsideBottomRightCorner    = 22,

  /*
   * Centered vertically and horizontally
   */
  kHMAbsoluteCenterAligned      = 23
};

/* Obsoleted constants HMTagDisplaySides, use the new ones, please */
enum {
  kHMTopSide                    = kHMOutsideTopScriptAligned,
  kHMLeftSide                   = kHMOutsideLeftCenterAligned,
  kHMBottomSide                 = kHMOutsideBottomScriptAligned,
  kHMRightSide                  = kHMOutsideRightCenterAligned,
  kHMTopLeftCorner              = kHMOutsideTopLeftAligned,
  kHMTopRightCorner             = kHMOutsideTopRightAligned,
  kHMLeftTopCorner              = kHMOutsideLeftTopAligned,
  kHMLeftBottomCorner           = kHMOutsideLeftBottomAligned,
  kHMBottomLeftCorner           = kHMOutsideBottomLeftAligned,
  kHMBottomRightCorner          = kHMOutsideBottomRightAligned,
  kHMRightTopCorner             = kHMOutsideRightTopAligned,
  kHMRightBottomCorner          = kHMOutsideRightBottomAligned
};

typedef SInt16 HMContentProvidedType;
enum {
  kHMContentProvided            = 0,
  kHMContentNotProvided         = 1,
  kHMContentNotProvidedDontPropagate = 2
};

enum {
  kHMMinimumContentIndex        = 0,    /* first entry in HMHelpContentRec.content is the minimum content */
  kHMMaximumContentIndex        = 1     /* second entry in HMHelpContentRec.content is the maximum content */
};

enum {
  errHMIllegalContentForMinimumState = -10980, /* unrecognized content type for minimum content */
  errHMIllegalContentForMaximumState = -10981 /* unrecognized content type for maximum content */
};

/* obsolete names; will be removed*/
enum {
  kHMIllegalContentForMinimumState = errHMIllegalContentForMinimumState
};

enum {
  kHelpTagEventHandlerTag       = 'hevt'
};

struct HMHelpContent {
  HMContentType       contentType;
  union {
    CFStringRef         tagCFString;          /* CFStringRef*/
    Str255              tagString;            /* Pascal String*/
    HMStringResType     tagStringRes;         /* STR# resource ID and index*/
    TEHandle            tagTEHandle;          /* TextEdit handle (NOT SUPPORTED ON MAC OS X)*/
    SInt16              tagTextRes;           /* TEXT/styl resource ID (NOT SUPPORTED ON MAC OS X)*/
    SInt16              tagStrRes;            /* STR resource ID*/
  }                       u;
};
typedef struct HMHelpContent            HMHelpContent;
struct HMHelpContentRec {
  SInt32              version;
  Rect                absHotRect;
  HMTagDisplaySide    tagSide;
  HMHelpContent       content[2];
};
typedef struct HMHelpContentRec         HMHelpContentRec;
typedef HMHelpContentRec *              HMHelpContentPtr;
/*������������������������������������������������������������������������������������������*/
/* Callback procs                                       */
/*������������������������������������������������������������������������������������������ */
typedef CALLBACK_API( OSStatus , HMControlContentProcPtr )(ControlRef inControl, Point inGlobalMouse, HMContentRequest inRequest, HMContentProvidedType *outContentProvided, HMHelpContentPtr ioHelpContent);
typedef CALLBACK_API( OSStatus , HMWindowContentProcPtr )(WindowRef inWindow, Point inGlobalMouse, HMContentRequest inRequest, HMContentProvidedType *outContentProvided, HMHelpContentPtr ioHelpContent);
typedef CALLBACK_API( OSStatus , HMMenuTitleContentProcPtr )(MenuRef inMenu, HMContentRequest inRequest, HMContentProvidedType *outContentProvided, HMHelpContentPtr ioHelpContent);
typedef CALLBACK_API( OSStatus , HMMenuItemContentProcPtr )(const MenuTrackingData *inTrackingData, HMContentRequest inRequest, HMContentProvidedType *outContentProvided, HMHelpContentPtr ioHelpContent);
typedef STACK_UPP_TYPE(HMControlContentProcPtr)                 HMControlContentUPP;
typedef STACK_UPP_TYPE(HMWindowContentProcPtr)                  HMWindowContentUPP;
typedef STACK_UPP_TYPE(HMMenuTitleContentProcPtr)               HMMenuTitleContentUPP;
typedef STACK_UPP_TYPE(HMMenuItemContentProcPtr)                HMMenuItemContentUPP;
/*
 *  NewHMControlContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern HMControlContentUPP
NewHMControlContentUPP(HMControlContentProcPtr userRoutine)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewHMWindowContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern HMWindowContentUPP
NewHMWindowContentUPP(HMWindowContentProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewHMMenuTitleContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern HMMenuTitleContentUPP
NewHMMenuTitleContentUPP(HMMenuTitleContentProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewHMMenuItemContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern HMMenuItemContentUPP
NewHMMenuItemContentUPP(HMMenuItemContentProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeHMControlContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeHMControlContentUPP(HMControlContentUPP userUPP)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeHMWindowContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeHMWindowContentUPP(HMWindowContentUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeHMMenuTitleContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeHMMenuTitleContentUPP(HMMenuTitleContentUPP userUPP)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeHMMenuItemContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeHMMenuItemContentUPP(HMMenuItemContentUPP userUPP)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeHMControlContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeHMControlContentUPP(
  ControlRef               inControl,
  Point                    inGlobalMouse,
  HMContentRequest         inRequest,
  HMContentProvidedType *  outContentProvided,
  HMHelpContentPtr         ioHelpContent,
  HMControlContentUPP      userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeHMWindowContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeHMWindowContentUPP(
  WindowRef                inWindow,
  Point                    inGlobalMouse,
  HMContentRequest         inRequest,
  HMContentProvidedType *  outContentProvided,
  HMHelpContentPtr         ioHelpContent,
  HMWindowContentUPP       userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeHMMenuTitleContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeHMMenuTitleContentUPP(
  MenuRef                  inMenu,
  HMContentRequest         inRequest,
  HMContentProvidedType *  outContentProvided,
  HMHelpContentPtr         ioHelpContent,
  HMMenuTitleContentUPP    userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeHMMenuItemContentUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeHMMenuItemContentUPP(
  const MenuTrackingData *  inTrackingData,
  HMContentRequest          inRequest,
  HMContentProvidedType *   outContentProvided,
  HMHelpContentPtr          ioHelpContent,
  HMMenuItemContentUPP      userUPP)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*������������������������������������������������������������������������������������������*/
/* API                                                                                      */
/*������������������������������������������������������������������������������������������*/
/* Help Menu */
/*
 *  HMGetHelpMenu()
 *  
 *  Summary:
 *    Returns a menu to which applications may add their own help items.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    outHelpMenu:
 *      On exit, contains the help menu.
 *    
 *    outFirstCustomItemIndex:
 *      On exit, contains the menu item index that will be used by the
 *      first item added by the application. This parameter may be NULL.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetHelpMenu(
  MenuRef *        outHelpMenu,
  MenuItemIndex *  outFirstCustomItemIndex)       /* can be NULL */ AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Installing/Retrieving Content */
/* Menu title and item help tags are not yet supported by Carbon or CarbonLib. */
/* They will be fully supported in a future release. */
/*
 *  HMSetControlHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetControlHelpContent(
  ControlRef                inControl,
  const HMHelpContentRec *  inContent)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetControlHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetControlHelpContent(
  ControlRef          inControl,
  HMHelpContentRec *  outContent)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMSetWindowHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetWindowHelpContent(
  WindowRef                 inWindow,
  const HMHelpContentRec *  inContent)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetWindowHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetWindowHelpContent(
  WindowRef           inWindow,
  HMHelpContentRec *  outContent)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMSetMenuItemHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetMenuItemHelpContent(
  MenuRef                   inMenu,
  MenuItemIndex             inItem,
  const HMHelpContentRec *  inContent)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetMenuItemHelpContent()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetMenuItemHelpContent(
  MenuRef             inMenu,
  MenuItemIndex       inItem,
  HMHelpContentRec *  outContent)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Installing/Retrieving Content Callbacks */
/*
 *  HMInstallControlContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMInstallControlContentCallback(
  ControlRef            inControl,
  HMControlContentUPP   inContentUPP)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMInstallWindowContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMInstallWindowContentCallback(
  WindowRef            inWindow,
  HMWindowContentUPP   inContentUPP)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMInstallMenuTitleContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMInstallMenuTitleContentCallback(
  MenuRef                 inMenu,
  HMMenuTitleContentUPP   inContentUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMInstallMenuItemContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMInstallMenuItemContentCallback(
  MenuRef                inMenu,
  HMMenuItemContentUPP   inContentUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetControlContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetControlContentCallback(
  ControlRef             inControl,
  HMControlContentUPP *  outContentUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetWindowContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetWindowContentCallback(
  WindowRef             inWindow,
  HMWindowContentUPP *  outContentUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetMenuTitleContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetMenuTitleContentCallback(
  MenuRef                  inMenu,
  HMMenuTitleContentUPP *  outContentUPP)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetMenuItemContentCallback()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetMenuItemContentCallback(
  MenuRef                 inMenu,
  HMMenuItemContentUPP *  outContentUPP)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Enabling and Disabling Help Tags */
/*
 *  HMAreHelpTagsDisplayed()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
HMAreHelpTagsDisplayed(void)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMSetHelpTagsDisplayed()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetHelpTagsDisplayed(Boolean inDisplayTags)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMSetTagDelay()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetTagDelay(Duration inDelay)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMGetTagDelay()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMGetTagDelay(Duration * outDelay)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Compatibility */
/*
 *  HMSetMenuHelpFromBalloonRsrc()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetMenuHelpFromBalloonRsrc(
  MenuRef   inMenu,
  SInt16    inHmnuRsrcID)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMSetDialogHelpFromBalloonRsrc()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMSetDialogHelpFromBalloonRsrc(
  DialogRef   inDialog,
  SInt16      inHdlgRsrcID,
  SInt16      inItemStart)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Displaying tags */
/*
 *  HMDisplayTag()
 *  
 *  Summary:
 *    Displays a help tag at a user defined location.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inContent:
 *      HMHelpContentRec describing the help tag to be displayed.
 *  
 *  Result:
 *    An OSStatus code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMDisplayTag(const HMHelpContentRec * inContent)              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HMHideTag()
 *  
 *  Summary:
 *    HMHideTag hides the currently visible help tag.  If there is no
 *    current help tag, this call does nothing.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    An OSStatus code indicating success or failure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HMHideTag(void)                                               AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;



#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __MACHELP__ */

