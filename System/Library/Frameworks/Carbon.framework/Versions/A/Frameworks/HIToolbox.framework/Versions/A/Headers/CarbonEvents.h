/*
     File:       HIToolbox/CarbonEvents.h
 
     Contains:   Carbon Event Manager
 
     Version:    HIToolbox-145.48~1
 
     Copyright:  � 1999-2003 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CARBONEVENTS__
#define __CARBONEVENTS__

#ifndef __APPLICATIONSERVICES__
#include <ApplicationServices/ApplicationServices.h>
#endif

#ifndef __CARBONEVENTSCORE__
#include <HIToolbox/CarbonEventsCore.h>
#endif

#ifndef __EVENTS__
#include <HIToolbox/Events.h>
#endif

#ifndef __MENUS__
#include <HIToolbox/Menus.h>
#endif

#ifndef __CONTROLS__
#include <HIToolbox/Controls.h>
#endif

#ifndef __MACWINDOWS__
#include <HIToolbox/MacWindows.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

/*��������������������������������������������������������������������������������������*/
/* Parameter names and types                                                            */
/*��������������������������������������������������������������������������������������*/

/*
 */
enum {

  /*
   * This event parameter may be added to any event that is posted to
   * the main event queue. When the event is removed from the queue and
   * sent to the event dispatcher, the dispatcher will retrieve the
   * EventTargetRef contained in this parameter and send the event
   * directly to that event target. If this parameter is not available
   * in the event, the dispatcher will send the event to a suitable
   * target, or to the application target if no more specific target is
   * appropriate. Available in CarbonLib 1.3.1 and later, and Mac OS X.
   */
  kEventParamPostTarget         = 'ptrg', /* typeEventTargetRef*/

  /*
   * Indicates an event parameter of type EventTargetRef.
   */
  typeEventTargetRef            = 'etrg' /* EventTargetRef*/
};

/* Generic toolbox parameters and types*/

/*
   *** NOTE ON AUTOMATIC TYPE CONVERSIONS
   Please keep in mind that some of these types can be automatically converted
   to other types just by asking for them as different types. The following
   type conversions are automatic:
        typeQDRectangle     <-->        typeHIRect
        typeQDPoint         <-->        typeHIPoint
   In addition, if a CFBoolean type is added to an event, a request to receive
   the data as typeBoolean (instead of typeCFType), will be automatically honored.
*/


enum {
  kEventParamWindowRef          = 'wind', /* typeWindowRef*/
  kEventParamGrafPort           = 'graf', /* typeGrafPtr*/
  kEventParamMenuRef            = 'menu', /* typeMenuRef*/
  kEventParamEventRef           = 'evnt', /* typeEventRef*/
  kEventParamControlRef         = 'ctrl', /* typeControlRef*/
  kEventParamRgnHandle          = 'rgnh', /* typeQDRgnHandle*/
  kEventParamEnabled            = 'enab', /* typeBoolean*/
  kEventParamDimensions         = 'dims', /* typeQDPoint*/
  kEventParamBounds             = 'boun', /* typeQDRectangle*/
  kEventParamAvailableBounds    = 'avlb', /* typeQDRectangle*/
  kEventParamAEEventID          = keyAEEventID, /* typeType*/
  kEventParamAEEventClass       = keyAEEventClass, /* typeType*/
  kEventParamCGContextRef       = 'cntx', /* typeCGContextRef*/
  kEventParamDeviceDepth        = 'devd', /* typeShortInteger*/
  kEventParamDeviceColor        = 'devc', /* typeBoolean*/
  kEventParamMutableArray       = 'marr', /* typeCFMutableArrayRef*/
  kEventParamResult             = 'ansr', /* any type - depends on event like direct object*/
  kEventParamMinimumSize        = 'mnsz', /* typeHISize*/
  kEventParamMaximumSize        = 'mxsz', /* typeHISize*/
  kEventParamAttributes         = 'attr', /* typeUInt32*/
  kEventParamReason             = 'why?', /* typeUInt32*/
  kEventParamTransactionID      = 'trns', /* typeUInt32*/
  kEventParamGDevice            = 'gdev', /* typeGDHandle*/
  kEventParamIndex              = 'indx', /* typeCFIndex*/
  kEventParamUserData           = 'usrd', /* typeVoidPtr*/
  typeWindowRef                 = 'wind', /* WindowRef*/
  typeGrafPtr                   = 'graf', /* CGrafPtr*/
  typeGWorldPtr                 = 'gwld', /* GWorldPtr*/
  typeMenuRef                   = 'menu', /* MenuRef*/
  typeControlRef                = 'ctrl', /* ControlRef*/
  typeCollection                = 'cltn', /* Collection*/
  typeQDRgnHandle               = 'rgnh', /* RgnHandle*/
  typeOSStatus                  = 'osst', /* OSStatus*/
  typeCFIndex                   = 'cfix', /* CFIndex*/
  typeCGContextRef              = 'cntx', /* CGContextRef*/
  typeHIPoint                   = 'hipt', /* HIPoint*/
  typeHISize                    = 'hisz', /* HISize*/
  typeHIRect                    = 'hirc', /* HIRect*/
  typeVoidPtr                   = 'void', /* void * (used for HIObject fun)*/
  typeGDHandle                  = 'gdev' /* GDHandle*/
};

/* Mouse event parameters and types*/

enum {
  kEventParamMouseLocation      = 'mloc', /* typeHIPoint*/
  kEventParamWindowMouseLocation = 'wmou', /* typeHIPoint (Mac OS X 10.1 or later)*/
  kEventParamMouseButton        = 'mbtn', /* typeMouseButton*/
  kEventParamClickCount         = 'ccnt', /* typeUInt32*/
  kEventParamMouseWheelAxis     = 'mwax', /* typeMouseWheelAxis*/
  kEventParamMouseWheelDelta    = 'mwdl', /* typeSInt32*/
  kEventParamMouseDelta         = 'mdta', /* typeHIPoint (10.2 or later) or typeQDPoint*/
  kEventParamMouseChord         = 'chor', /* typeUInt32*/
  kEventParamTabletEventType    = 'tblt', /* typeUInt32*/
  kEventParamMouseTrackingRef   = 'mtrf', /* typeMouseTrackingRef*/
  typeMouseButton               = 'mbtn', /* EventMouseButton*/
  typeMouseWheelAxis            = 'mwax', /* EventMouseWheelAxis*/
  typeMouseTrackingRef          = 'mtrf' /* MouseTrackingRef*/
};

/* Keyboard event parameter and types*/

enum {
  kEventParamKeyCode            = 'kcod', /* typeUInt32*/
  kEventParamKeyMacCharCodes    = 'kchr', /* typeChar*/
  kEventParamKeyModifiers       = 'kmod', /* typeUInt32*/
  kEventParamKeyUnicodes        = 'kuni', /* typeUnicodeText*/
  kEventParamKeyboardType       = 'kbdt', /* typeUInt32*/
  typeEventHotKeyID             = 'hkid' /* EventHotKeyID*/
};

/* General TSM event parameters*/

enum {
  kEventParamTSMSendRefCon      = 'tsrc', /*    typeLongInteger*/
  kEventParamTSMSendComponentInstance = 'tsci' /*    typeComponentInstance*/
};

/* TextInput event parameters*/

enum {
  kEventParamTextInputSendRefCon = kEventParamTSMSendRefCon, /*    typeLongInteger*/
  kEventParamTextInputSendComponentInstance = kEventParamTSMSendComponentInstance, /*    typeComponentInstance*/
  kEventParamTextInputSendSLRec = 'tssl', /*    typeIntlWritingCode*/
  kEventParamTextInputReplySLRec = 'trsl', /*    typeIntlWritingCode*/
  kEventParamTextInputSendText  = 'tstx', /*    typeUnicodeText (if TSMDocument is Unicode), otherwise typeChar*/
  kEventParamTextInputReplyText = 'trtx', /*    typeUnicodeText (if TSMDocument is Unicode), otherwise typeChar*/
  kEventParamTextInputSendUpdateRng = 'tsup', /*    typeTextRangeArray*/
  kEventParamTextInputSendHiliteRng = 'tshi', /*    typeTextRangeArray*/
  kEventParamTextInputSendClauseRng = 'tscl', /*    typeOffsetArray*/
  kEventParamTextInputSendPinRng = 'tspn', /*    typeTextRange*/
  kEventParamTextInputSendFixLen = 'tsfx', /*    typeLongInteger*/
  kEventParamTextInputSendLeadingEdge = 'tsle', /*    typeBoolean*/
  kEventParamTextInputReplyLeadingEdge = 'trle', /*    typeBoolean*/
  kEventParamTextInputSendTextOffset = 'tsto', /*    typeLongInteger*/
  kEventParamTextInputReplyTextOffset = 'trto', /*    typeLongInteger*/
  kEventParamTextInputReplyRegionClass = 'trrg', /*    typeLongInteger*/
  kEventParamTextInputSendCurrentPoint = 'tscp', /*    typeQDPoint*/
  kEventParamTextInputSendDraggingMode = 'tsdm', /*    typeBoolean*/
  kEventParamTextInputReplyPoint = 'trpt', /*    typeQDPoint*/
  kEventParamTextInputReplyFont = 'trft', /*    typeLongInteger*/
  kEventParamTextInputReplyFMFont = 'trfm', /*    typeUInt32*/
  kEventParamTextInputReplyPointSize = 'trpz', /*    typeFixed*/
  kEventParamTextInputReplyLineHeight = 'trlh', /*    typeShortInteger*/
  kEventParamTextInputReplyLineAscent = 'trla', /*    typeShortInteger*/
  kEventParamTextInputReplyTextAngle = 'trta', /*    typeFixed*/
  kEventParamTextInputSendShowHide = 'tssh', /*    typeBoolean*/
  kEventParamTextInputReplyShowHide = 'trsh', /*    typeBoolean*/
  kEventParamTextInputSendKeyboardEvent = 'tske', /*    typeEventRef*/
  kEventParamTextInputSendTextServiceEncoding = 'tsse', /*    typeUInt32*/
  kEventParamTextInputSendTextServiceMacEncoding = 'tssm', /*    typeUInt32*/
  kEventParamTextInputReplyMacEncoding = 'trme', /*    typeUInt32*/
  kEventParamTextInputGlyphInfoArray = 'glph', /*    typeGlyphInfoArray*/
  kEventParamTextInputSendGlyphInfoArray = kEventParamTextInputGlyphInfoArray,
  kEventParamTextInputReplyGlyphInfoArray = 'rgph', /*    typeGlyphInfoArray*/
  kEventParamTextInputSendReplaceRange = 'tsrp' /*    typeCFRange*/
};

/* TSMDocumentAccess event parameters and types*/

enum {
  kEventParamTSMDocAccessSendRefCon = kEventParamTSMSendRefCon, /*    typeLongInteger*/
  kEventParamTSMDocAccessSendComponentInstance = kEventParamTSMSendComponentInstance, /*    typeComponentInstance*/
  kEventParamTSMDocAccessCharacterCount = 'tdct', /*    typeCFIndex*/
  kEventParamTSMDocAccessReplyCharacterRange = 'tdrr', /*    typeCFRange*/
  kEventParamTSMDocAccessReplyCharactersPtr = 'tdrp', /*    typePtr*/
  kEventParamTSMDocAccessSendCharacterIndex = 'tdsi', /*    typeCFIndex*/
  kEventParamTSMDocAccessSendCharacterRange = 'tdsr', /*    typeCFRange*/
  kEventParamTSMDocAccessSendCharactersPtr = 'tdsp', /*    typePtr*/
  kEventParamTSMDocAccessRequestedCharacterAttributes = 'tdca', /*    typeUInt32*/
  kEventParamTSMDocAccessReplyATSFont = 'tdaf', /*    typeATSFontRef*/
  kEventParamTSMDocAccessReplyFontSize = 'tdrs', /*    typeFloat*/
  kEventParamTSMDocAccessEffectiveRange = 'tder', /*    typeRange*/
  kEventParamTSMDocAccessReplyATSUGlyphSelector = 'tdrg', /*    typeGlyphSelector*/
  kEventParamTSMDocAccessLockCount = 'tdlc', /*    typeCFIndex*/
  typeATSFontRef                = 'atsf', /*    ATSFontRef*/
  typeGlyphSelector             = 'glfs' /*    ATSUGlyphSelector*/
};

/* Command event parameters and types*/

enum {
  kEventParamHICommand          = 'hcmd', /* typeHICommand*/
  typeHICommand                 = 'hcmd' /* HICommand*/
};

/* Window event parameters and types*/

enum {
  kEventParamWindowFeatures     = 'wftr', /* typeUInt32*/
  kEventParamWindowDefPart      = 'wdpc', /* typeWindowDefPartCode*/
  kEventParamWindowPartCode     = 'wpar', /* typeWindowPartCode*/
  kEventParamCurrentBounds      = 'crct', /* typeQDRectangle*/
  kEventParamOriginalBounds     = 'orct', /* typeQDRectangle*/
  kEventParamPreviousBounds     = 'prct', /* typeQDRectangle*/
  kEventParamClickActivation    = 'clac', /* typeClickActivationResult*/
  kEventParamWindowRegionCode   = 'wshp', /* typeWindowRegionCode*/
  kEventParamWindowDragHiliteFlag = 'wdhf', /* typeBoolean*/
  kEventParamWindowModifiedFlag = 'wmff', /* typeBoolean*/
  kEventParamWindowProxyGWorldPtr = 'wpgw', /* typeGWorldPtr*/
  kEventParamWindowProxyImageRgn = 'wpir', /* typeQDRgnHandle*/
  kEventParamWindowProxyOutlineRgn = 'wpor', /* typeQDRgnHandle*/
  kEventParamWindowStateChangedFlags = 'wscf', /* typeUInt32 */
  kEventParamWindowTitleFullWidth = 'wtfw', /* typeSInt16*/
  kEventParamWindowTitleTextWidth = 'wttw', /* typeSInt16*/
  kEventParamWindowGrowRect     = 'grct', /* typeQDRectangle*/
  kEventParamPreviousDockRect   = 'pdrc', /* typeHIRect*/
  kEventParamPreviousDockDevice = 'pdgd', /* typeGDHandle*/
  kEventParamCurrentDockRect    = 'cdrc', /* typeHIRect*/
  kEventParamCurrentDockDevice  = 'cdgd', /* typeGDHandle*/
  kEventParamWindowTransitionAction = 'wtac', /* typeWindowTransitionAction*/
  kEventParamWindowTransitionEffect = 'wtef', /* typeWindowTransitionEffect*/
  typeWindowRegionCode          = 'wshp', /* WindowRegionCode*/
  typeWindowDefPartCode         = 'wdpt', /* WindowDefPartCode*/
  typeWindowPartCode            = 'wpar', /* WindowPartCode*/
  typeClickActivationResult     = 'clac', /* ClickActivationResult*/
  typeWindowTransitionAction    = 'wtac', /* WindowTransitionAction*/
  typeWindowTransitionEffect    = 'wtef' /* WindowTransitionEffect*/
};

/* Control event parameters and types*/

enum {
  kEventParamControlPart        = 'cprt', /* typeControlPartCode*/
  kEventParamInitCollection     = 'icol', /* typeCollection*/
  kEventParamControlMessage     = 'cmsg', /* typeShortInteger*/
  kEventParamControlParam       = 'cprm', /* typeLongInteger*/
  kEventParamControlResult      = 'crsl', /* typeLongInteger*/
  kEventParamControlRegion      = 'crgn', /* typeQDRgnHandle*/
  kEventParamControlAction      = 'caup', /* typeControlActionUPP*/
  kEventParamControlIndicatorDragConstraint = 'cidc', /* typeIndicatorDragConstraint*/
  kEventParamControlIndicatorRegion = 'cirn', /* typeQDRgnHandle*/
  kEventParamControlIsGhosting  = 'cgst', /* typeBoolean*/
  kEventParamControlIndicatorOffset = 'ciof', /* typeQDPoint*/
  kEventParamControlClickActivationResult = 'ccar', /* typeClickActivationResult*/
  kEventParamControlSubControl  = 'csub', /* typeControlRef*/
  kEventParamControlOptimalBounds = 'cobn', /* typeQDRectangle*/
  kEventParamControlOptimalBaselineOffset = 'cobo', /* typeShortInteger*/
  kEventParamControlDataTag     = 'cdtg', /* typeEnumeration*/
  kEventParamControlDataBuffer  = 'cdbf', /* typePtr*/
  kEventParamControlDataBufferSize = 'cdbs', /* typeLongInteger*/
  kEventParamControlDrawDepth   = 'cddp', /* typeShortInteger*/
  kEventParamControlDrawInColor = 'cdic', /* typeBoolean*/
  kEventParamControlFeatures    = 'cftr', /* typeUInt32*/
  kEventParamControlPartBounds  = 'cpbd', /* typeQDRectangle*/
  kEventParamControlOriginalOwningWindow = 'coow', /* typeWindowRef*/
  kEventParamControlCurrentOwningWindow = 'ccow', /* typeWindowRef*/
  kEventParamControlFocusEverything = 'cfev', /* typeBoolean*/
  kEventParamNextControl        = 'cnxc', /* typeControlRef*/
  kEventParamStartControl       = 'cstc', /* typeControlRef*/
  kEventParamControlSubview     = 'csvw', /* typeControlRef*/
  kEventParamControlPreviousPart = 'copc', /* typeControlPartCode*/
  kEventParamControlCurrentPart = 'cnpc', /* typeControlPartCode*/
  kEventParamControlInvalRgn    = 'civr', /* typeQDRgnHandle*/
  kEventParamControlValue       = 'cval', /* typeLongInteger*/
  kEventParamControlHit         = 'chit', /* typeBoolean*/
  kEventParamControlPartAutoRepeats = 'caur', /* typeBoolean*/
  kEventParamControlFrameMetrics = 'cfmt', /* typeControlFrameMetrics*/
  kEventParamControlWouldAcceptDrop = 'cldg', /* typeBoolean*/
  typeControlActionUPP          = 'caup', /* ControlActionUPP*/
  typeIndicatorDragConstraint   = 'cidc', /* IndicatorDragConstraint*/
  typeControlPartCode           = 'cprt', /* ControlPartCode*/
  typeControlFrameMetrics       = 'cins' /* HIViewFrameMetrics*/
};

/* Menu event parameters and types*/

enum {
  kEventParamCurrentMenuTrackingMode = 'cmtm', /* typeMenuTrackingMode*/
  kEventParamNewMenuTrackingMode = 'nmtm', /* typeMenuTrackingMode*/
  kEventParamMenuFirstOpen      = '1sto', /* typeBoolean*/
  kEventParamMenuItemIndex      = 'item', /* typeMenuItemIndex*/
  kEventParamMenuCommand        = 'mcmd', /* typeMenuCommand*/
  kEventParamEnableMenuForKeyEvent = 'fork', /* typeBoolean*/
  kEventParamMenuEventOptions   = 'meop', /* typeMenuEventOptions*/
  kEventParamMenuContext        = 'mctx', /* typeUInt32*/
  kEventParamMenuDismissed      = 'mdis', /* typeUInt32*/
  kEventParamMenuItemBounds     = 'mitb', /* typeQDRectangle*/
  kEventParamMenuMarkBounds     = 'mmkb', /* typeQDRectangle*/
  kEventParamMenuIconBounds     = 'micb', /* typeQDRectangle*/
  kEventParamMenuTextBounds     = 'mtxb', /* typeQDRectangle*/
  kEventParamMenuTextBaseline   = 'mtbl', /* typeShortInteger*/
  kEventParamMenuCommandKeyBounds = 'mcmb', /* typeQDRectangle*/
  kEventParamMenuVirtualTop     = 'mvrt', /* typeLongInteger*/
  kEventParamMenuVirtualBottom  = 'mvrb', /* typeLongInteger*/
  kEventParamMenuDrawState      = 'mdrs', /* typeThemeMenuState*/
  kEventParamMenuItemType       = 'mitp', /* typeThemeMenuItemType*/
  kEventParamMenuItemWidth      = 'mitw', /* typeShortInteger*/
  kEventParamMenuItemHeight     = 'mith', /* typeShortInteger*/
  kEventParamMenuFrameView      = 'mfrv', /* typeControlRef*/
  kEventParamMenuType           = 'mtyp', /* typeThemeMenuType*/
  kEventParamMenuIsPopup        = 'mpop', /* typeBoolean*/
  kEventParamMenuDirection      = 'mdir', /* typeMenuDirection*/
  kEventParamParentMenu         = 'mprm', /* typeMenuRef*/
  kEventParamParentMenuItem     = 'mpri', /* typeMenuItemIndex*/
  kEventParamMenuPopupItem      = 'mpit', /* typeMenuItemIndex*/
  typeMenuItemIndex             = 'midx', /* MenuItemIndex*/
  typeMenuCommand               = 'mcmd', /* MenuCommand*/
  typeMenuTrackingMode          = 'mtmd', /* MenuTrackingMode*/
  typeMenuEventOptions          = 'meop', /* MenuEventOptions*/
  typeThemeMenuState            = 'tmns', /* ThemeMenuState*/
  typeThemeMenuItemType         = 'tmit', /* ThemeMenuItemType*/
  typeMenuDirection             = 'mdir', /* UInt32*/
  typeThemeMenuType             = 'tmty' /* ThemeMenuType*/
};

/* Application event parameters*/

enum {
  kEventParamProcessID          = 'psn ', /* typeProcessSerialNumber*/
  kEventParamLaunchRefCon       = 'lref', /* typeUInt32*/
  kEventParamLaunchErr          = 'err ', /* typeOSStatus*/
  kEventParamSystemUIMode       = 'uimd', /* typeUInt32*/
  kEventParamIsInInstantMouser  = 'imou', /* typeBoolean*/
  kEventParamPreviousWindow     = 'prvw', /* typeWindowRef*/
  kEventParamCurrentWindow      = 'curw' /* typeWindowRef*/
};

/* Tablet event parameters and types*/

enum {
  kEventParamTabletPointRec     = 'tbrc', /* typeTabletPointRec*/
  kEventParamTabletProximityRec = 'tbpx', /* typeTabletProximityRec*/
  typeTabletPointRec            = 'tbrc', /* kEventParamTabletPointRec*/
  typeTabletProximityRec        = 'tbpx', /* kEventParamTabletProximityRec*/
  kEventParamTabletPointerRec   = 'tbrc', /* typeTabletPointerRec      -- deprecated, for compatibility only*/
  typeTabletPointerRec          = 'tbrc' /* kEventParamTabletPointerRec    -- deprecated, for compatibility only*/
};

/* Appearance event parameters*/

enum {
  kEventParamNewScrollBarVariant = 'nsbv' /* typeShortInteger*/
};

/* Service event parameters*/

enum {
  kEventParamPasteboardRef      = 'pbrd', /*    typePasteboardRef*/
  kEventParamScrapRef           = 'scrp', /*    typeScrapRef*/
  kEventParamServiceCopyTypes   = 'svsd', /*    typeCFMutableArrayRef*/
  kEventParamServicePasteTypes  = 'svpt', /*    typeCFMutableArrayRef*/
  kEventParamServiceMessageName = 'svmg', /*    typeCFStringRef*/
  kEventParamServiceUserData    = 'svud', /*    typeCFStringRef*/
  typePasteboardRef             = 'pbrd', /*    PasteboardRef*/
  typeScrapRef                  = 'scrp' /*    ScrapRef*/
};

/* Accessibility event parameters*/

enum {
  kEventParamAccessibleObject   = 'aobj', /* typeCFTypeRef with an AXUIElementRef*/
  kEventParamAccessibleChild    = 'achl', /* typeCFTypeRef with an AXUIElementRef*/
  kEventParamAccessibleAttributeName = 'atnm', /* typeCFStringRef*/
  kEventParamAccessibleAttributeNames = 'atns', /* typeCFMutableArrayRef of CFStringRefs*/
  kEventParamAccessibleAttributeValue = 'atvl', /* variable*/
  kEventParamAccessibleAttributeSettable = 'atst', /* typeBoolean*/
  kEventParamAccessibleAttributeParameter = 'atpa', /* typeCFTypeRef*/
  kEventParamAccessibleActionName = 'acnm', /* typeCFStringRef*/
  kEventParamAccessibleActionNames = 'acns', /* typeCFMutableArrayRef of CFStringRefs*/
  kEventParamAccessibleActionDescription = 'acds', /* typeCFMutableStringRef*/
  kEventParamAccessibilityEventQueued = 'aequ' /* typeBoolean*/
};

/* Text field event type*/

enum {
  typeCFRange                   = 'cfrn' /* CFRange*/
};

/*��������������������������������������������������������������������������������������*/
/*  � Helpful utilities                                                                 */
/*��������������������������������������������������������������������������������������*/

/*
 *  Discussion:
 *    These are returned from calls to TrackMouseLocation and
 *    TrackMouseRegion. Those routines are designed as replacements to
 *    calls such as StillDown and WaitMouseUp. The advantage over those
 *    routines is that TrackMouseLocation and TrackMouseRegion will
 *    block if the user is not moving the mouse, whereas mouse tracking
 *    loops based on StillDown and WaitMouseUp will spin, chewing up
 *    valuable CPU time that could be better spent elsewhere. It is
 *    highly recommended that any tracking loops in your application
 *    stop using StillDown and WaitMouseUp and start using
 *    TrackMouseLocation/Region. See the notes on those routines for
 *    more information.
 */
enum {
  kTrackMouseLocationOptionDontConsumeMouseUp = (1 << 0)
};

typedef UInt16 MouseTrackingResult;
enum {
  kMouseTrackingMouseDown       = 1,
  kMouseTrackingMouseUp         = 2,
  kMouseTrackingMouseExited     = 3,
  kMouseTrackingMouseEntered    = 4,
  kMouseTrackingMouseDragged    = 5,
  kMouseTrackingKeyModifiersChanged = 6,
  kMouseTrackingUserCancelled   = 7,
  kMouseTrackingTimedOut        = 8,
  kMouseTrackingMouseMoved      = 9
};

/*
 *  IsUserCancelEventRef()
 *  
 *  Discussion:
 *    Tests the event given to see whether the event represents a 'user
 *    cancel' event. Currently this is defined to be either the escape
 *    key being pressed, or command-period being pressed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    A boolean value indicating whether the event is a user cancel
 *    event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
IsUserCancelEventRef(EventRef event)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TrackMouseLocation()
 *  
 *  Discussion:
 *    Once entered, this routine waits for certain mouse events (move,
 *    mouse down, mouse up). When one of these events occurs, the
 *    function returns and tells the caller what happened and where the
 *    mouse is currently located. While there is no activity, the
 *    current event loop is run, effectively blocking the current
 *    thread (save for any timers that fire). This helps to minimize
 *    CPU usage when there is nothing going on. 
 *    
 *    On Mac OS X 10.1 and earlier, and CarbonLib 1.5 and earlier,
 *    TrackMouseLocation, TrackMouseLocationWithOptions, and
 *    TrackMouseRegion only support mouse-tracking when a mouse button
 *    is pressed. They cannot be used for mouse-tracking when no mouse
 *    button is pressed; if called when no button is pressed, they will
 *    simply block until a button is pressed and will not return when
 *    the mouse is moved. On Mac OS X 10.2 and CarbonLib 1.6 and later,
 *    TrackMouseLocation, TrackMouseLocationWithOptions, and
 *    TrackMouseRegion support mouse-tracking without a pressed mouse
 *    button; TrackMouseLocation and TrackMouseLocationWithOptions
 *    return kMouseTrackingMouseMoved if the mouse is moved while no
 *    button is pressed, and TrackMouseRegion returns
 *    kMouseTrackingMouseEntered/Exited if the mouse moves into or out
 *    of the specified region while no button is pressed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port. The mouse
 *      location is returned in terms of local coordinates of this
 *      port. You can pass -1 for this parameter to indicate that the
 *      mouse location should be returned in global coordinates instead
 *      of local coordinates.
 *    
 *    outPt:
 *      On exit, this parameter receives the mouse location from the
 *      last mouse event that caused this function to exit.
 *    
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseUp.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
TrackMouseLocation(
  GrafPtr                inPort,          /* can be NULL */
  Point *                outPt,
  MouseTrackingResult *  outResult)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TrackMouseLocationWithOptions()
 *  
 *  Discussion:
 *    This routine is largely identical to TrackMouseLocation. Please
 *    read the notes on that function as well.
 *    TrackMouseLocationWithOptions supports additional parameters for
 *    leaving mouse-up events in the event queue, specifying a timeout,
 *    and retrieving the current mouse position and keyboard modifiers.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port. The mouse
 *      location is returned in terms of local coordinates of this
 *      port. You can pass -1 for this parameter to indicate that the
 *      mouse location should be returned in global coordinates instead
 *      of local coordinates.
 *    
 *    inOptions:
 *      The only option supported by this routine at present is
 *      kTrackMouseLocationOptionDontConsumeMouseUp, which indicates
 *      that the toolbox should leave mouse-up events in the queue. You
 *      may also pass zero for this parameter to get the default
 *      behavior, which is to remove mouse-up events from the queue
 *      before returning.
 *    
 *    inTimeout:
 *      The amount of time to wait for an event. If no events arrive
 *      within this time, kMouseTrackingTimedOut is returned in
 *      outResult.
 *    
 *    outPt:
 *      On exit, this parameter receives the mouse location from the
 *      last mouse event that caused this function to exit. If a
 *      timeout or key modifiers changed event caused this function to
 *      exit, the current mouse position at the time is returned.
 *    
 *    outModifiers:
 *      On exit, this parameter receives the most recent state of the
 *      keyboard modifiers. If a timeout caused this function to exit,
 *      the current keyboard modifiers at the time are returned.
 *    
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseUp.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
TrackMouseLocationWithOptions(
  GrafPtr                inPort,             /* can be NULL */
  OptionBits             inOptions,
  EventTimeout           inTimeout,
  Point *                outPt,
  UInt32 *               outModifiers,       /* can be NULL */
  MouseTrackingResult *  outResult)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TrackMouseRegion()
 *  
 *  Discussion:
 *    This routine is largely identical to TrackMouseLocation. Please
 *    read the notes on that function as well. TrackMouseRegion differs
 *    from TrackMouseLocation by only returning when the mouse enters
 *    or exits a specified region that you pass in to the function, as
 *    opposed to whenever the mouse moves (it also returns for mouse
 *    up/down events). This is useful if you don't need to know
 *    intermediate mouse events, but rather just if the mouse enters or
 *    leaves an area.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inPort:
 *      The grafport to consider for mouse coordinates. You can pass
 *      NULL for this parameter to indicate the current port. You can
 *      pass -1 for this parameter to indicate that the mouse region
 *      should be interpreted in global coordinates instead of local
 *      coordinates.
 *    
 *    inRegion:
 *      The region to consider. This should be in the coordinates of
 *      the port you passed to inPort, or global coordinates if you
 *      passed -1 for the inPort parameter.
 *    
 *    ioWasInRgn:
 *      On entry, this parameter should be set to true if the mouse is
 *      currently inside the region passed in inRegion, or false if the
 *      mouse is currently outside the region. On exit, this parameter
 *      is updated to reflect the current reality; e.g. if the
 *      outResult parameter returns kMouseTrackingMouseExited,
 *      ioWasInRgn will be set to false when this function exits.
 *      Because it is updated from within, you should only need to set
 *      this yourself before the first call to this function in your
 *      tracking loop.
 *    
 *    outResult:
 *      On exit, this parameter receives a value representing what kind
 *      of event was received that cause the function to exit, such as
 *      kMouseTrackingMouseEntered.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
TrackMouseRegion(
  GrafPtr                inPort,           /* can be NULL */
  RgnHandle              inRegion,
  Boolean *              ioWasInRgn,
  MouseTrackingResult *  outResult)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  Summary:
 *    Mouse tracking info selectors for HIMouseTrackingGetParameters.
 */
enum {

  /*
   * Requests the time and distance for determining �sticky� mouse
   * tracking. When the mouse is clicked on a menu title, the toolbox
   * will enter a sticky mouse-tracking mode depending on the time and
   * distance between the mouse-down event and the mouse-up event. In
   * this mode, the menu is tracked even though the mouse has already
   * been released.
   */
  kMouseParamsSticky            = 'stic'
};

/*
 *  HIMouseTrackingGetParameters()
 *  
 *  Summary:
 *    Returns information about how mouse tracking loops should behave.
 *  
 *  Discussion:
 *    Mouse tracking loops may use different timeouts and wander
 *    distances to determine their behavior. This API provides a
 *    generic service for requesting this information. Currently, the
 *    only supported selector is kMouseParamsSticky.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inSelector:
 *      Indicates which type of information should be returned.
 *    
 *    outTime:
 *      If selector is kMouseParamsSticky, returns the maximum time
 *      between mouse-down and mouse-up. If the time between events is
 *      longer than this value, sticky mode should not be invoked. May
 *      be NULL if this information is not required.
 *    
 *    outDistance:
 *      If selector is kMouseParamsSticky, returns the maximum distance
 *      between mouse-down and mouse-up. If the distance between events
 *      is longer than this value, sticky mode should not be invoked.
 *      May be NULL if this information is not required.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
HIMouseTrackingGetParameters(
  OSType       inSelector,
  EventTime *  outTime,           /* can be NULL */
  HISize *     outDistance)       /* can be NULL */           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  ConvertEventRefToEventRecord()
 *  
 *  Discussion:
 *    This is a convenience routine to help you if there are places in
 *    your application where you need an EventRecord and all you have
 *    is an EventRef. If the event can be converted, outEvent is filled
 *    in and the function returns true. If not, false is returned and
 *    outEvent will contain a nullEvent.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inEvent:
 *      The EventRef to convert into an EventRecord.
 *    
 *    outEvent:
 *      The EventRecord to fill out.
 *  
 *  Result:
 *    A boolean indicating if the conversion was successful (true) or
 *    not (false).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
ConvertEventRefToEventRecord(
  EventRef       inEvent,
  EventRecord *  outEvent)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsEventInMask()
 *  
 *  Discussion:
 *    This is a companion function for ConvertEventRefToEventRecord,
 *    and is provided as a convenience routine to help you if there are
 *    places in your application where you want to check an EventRef to
 *    see if it matches a classic EventMask bitfield. If the event
 *    matches, the function returns true.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inEvent:
 *      The EventRef to convert into an EventRecord.
 *    
 *    inMask:
 *      The mask to consider.
 *  
 *  Result:
 *    A boolean indicating if the event was considered to be in the
 *    mask provided.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
IsEventInMask(
  EventRef    inEvent,
  EventMask   inMask)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetLastUserEventTime()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTime 
GetLastUserEventTime(void)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*��������������������������������������������������������������������������������������*/
/*  � Mouse Coalescing                                                                  */
/*��������������������������������������������������������������������������������������*/
/*
 *  IsMouseCoalescingEnabled()
 *  
 *  Discussion:
 *    Returns true if mouse coalescing is current enabled. When
 *    enabled, we coalesce mouse moved and mouse dragged events. By
 *    default, coalescing is on, but you can use
 *    SetMouseCoalescingEnabled to disable it if you want finer-grained
 *    mouse movement events, which is useful for drawing with tablets.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    A boolean indicating if coalescing is enabled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.1 and later
 *    Non-Carbon CFM:   not available
 */
extern Boolean 
IsMouseCoalescingEnabled(void)                                AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;


/*
 *  SetMouseCoalescingEnabled()
 *  
 *  Discussion:
 *    Allows you to set mouse move/drag event coalescing on or off. By
 *    default, coalescing is on, but you can use this function to
 *    disable it if you want finer-grained mouse movement events, which
 *    is useful for drawing with tablets.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inNewState:
 *      A boolean indicating if coalescing should be enabled (true) or
 *      disabled (false).
 *    
 *    outOldState:
 *      A boolean which receives the prior state of mouse coalescing
 *      for restoration later. You can pass NULL for this parameter if
 *      you don't care.
 *  
 *  Result:
 *    An operating system result code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetMouseCoalescingEnabled(
  Boolean    inNewState,
  Boolean *  outOldState)       /* can be NULL */             AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;



/*======================================================================================*/
/*  EVENT CLASSES                                                                       */
/*======================================================================================*/

/*
 *  Summary:
 *    Event classes
 */
enum {

  /*
   * Events related to the mouse (mouse down/up/moved).
   */
  kEventClassMouse              = 'mous',

  /*
   * Events related to the keyboard.
   */
  kEventClassKeyboard           = 'keyb',

  /*
   * Events related to text input (by keyboard, or by input method).
   */
  kEventClassTextInput          = 'text',

  /*
   * Application-level events (launch, quit, etc.).
   */
  kEventClassApplication        = 'appl',

  /*
   * Apple Events.
   */
  kEventClassAppleEvent         = 'eppc',

  /*
   * Events related to menus.
   */
  kEventClassMenu               = 'menu',

  /*
   * Events related to windows.
   */
  kEventClassWindow             = 'wind',

  /*
   * Events related to controls.
   */
  kEventClassControl            = 'cntl',

  /*
   * Events related to commands generated by menu items or controls.
   * These events contain HICommand structures.
   */
  kEventClassCommand            = 'cmds',

  /*
   * Events related to tablets.
   */
  kEventClassTablet             = 'tblt',

  /*
   * Events related to File Manager volumes.
   */
  kEventClassVolume             = 'vol ',

  /*
   * Events related to the Appearance Manager.
   */
  kEventClassAppearance         = 'appm',

  /*
   * Events related to the Services Manager.
   */
  kEventClassService            = 'serv',

  /*
   * Events related to toolbars.
   */
  kEventClassToolbar            = 'tbar',

  /*
   * Events related to toolbar items.
   */
  kEventClassToolbarItem        = 'tbit',

  /*
   * Events related to toolbar item views.
   */
  kEventClassToolbarItemView    = 'tbiv',

  /*
   * Events related to application accessibility.
   */
  kEventClassAccessibility      = 'acce',

  /*
   * Events related to the system.
   */
  kEventClassSystem             = 'macs',

  /*
   * Events related to Ink.
   */
  kEventClassInk                = 'ink ',
  kEventClassTSMDocumentAccess  = 'tdac'
};

/*��������������������������������������������������������������������������������������*/
/* Mouse Events                                                                         */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassMouse quick reference:
    
    kEventMouseDown                 = 1,
    kEventMouseUp                   = 2,
    kEventMouseMoved                = 5,
    kEventMouseDragged              = 6,
    kEventMouseEntered              = 8,
    kEventMouseExited               = 9,
    kEventMouseWheelMoved           = 10

    NOTE: As of Mac OS X 10.1, mouse events carry more information which allow you
          to do less work and gain accuracy of hit testing. First, there is the
          kEventParamWindowRef parameter. This parameter tells you over which window
          the mouse click/move/etc occurred. In mouse dragged events, this is the
          window the mouse went down in, NOT the window the mouse is currently over.
          Next, there is the kEventParamWindowMouseLocation parameter. This is the
          window-relative position of the mouse in the window given in the
          kEventParamWindowRef parameter. 0,0 is at the top left of the structure
          of the window.
*/

/*
 *  EventMouseButton
 *  
 */
typedef UInt16 EventMouseButton;
enum {

  /*
   * Only button for a one-button mouse (usually left button for
   * multi-button mouse)
   */
  kEventMouseButtonPrimary      = 1,

  /*
   * Usually right button for a multi-button mouse
   */
  kEventMouseButtonSecondary    = 2,

  /*
   * Usually middle button for a three-button mouse
   */
  kEventMouseButtonTertiary     = 3
};


/*
 *  EventMouseWheelAxis
 *  
 */
typedef UInt16 EventMouseWheelAxis;
enum {

  /*
   * The X axis (left or right)
   */
  kEventMouseWheelAxisX         = 0,

  /*
   * The Y axis (up or down)
   */
  kEventMouseWheelAxisY         = 1
};

/*
 *  kEventClassMouse / kEventMouseDown
 *  
 *  Summary:
 *    A mouse button was pressed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMouseDown               = 1
};

/*
 *  kEventClassMouse / kEventMouseUp
 *  
 *  Summary:
 *    A mouse button was released.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window in which the mouse was original pressed.
 *          Available in Mac OS X 10.1 and later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was released.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMouseUp                 = 2
};

/*
 *  kEventClassMouse / kEventMouseMoved
 *  
 *  Summary:
 *    The mouse was moved.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.3 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseDelta (in, typeHIPoint)
 *          The change in mouse position, in absolute units, ignoring
 *          scaling. Available in Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMouseMoved              = 5
};

/*
 *  kEventClassMouse / kEventMouseDragged
 *  
 *  Summary:
 *    The mouse was moved, and a button was down.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window in which the mouse was original pressed.
 *          Available in Mac OS X 10.1 and later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseDelta (in, typeHIPoint)
 *          The change in mouse position, in absolute units, ignoring
 *          scaling. Available in Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMouseDragged            = 6
};

/*
 *  kEventClassMouse / kEventMouseEntered
 *  
 *  Summary:
 *    The mouse entered a tracking area.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseTrackingRef (in, typeMouseTrackingRef)
 *          The MouseTrackingRef whose region the mouse has just
 *          entered.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMouseEntered            = 8
};

/*
 *  kEventClassMouse / kEventMouseExited
 *  
 *  Summary:
 *    The mouse exited a tracking area.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseTrackingRef (in, typeMouseTrackingRef)
 *          The MouseTrackingRef whose region the mouse has just exited.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMouseExited             = 9
};

/*
 *  kEventClassMouse / kEventMouseWheelMoved
 *  
 *  Summary:
 *    The mouse wheel was moved.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseWheelAxis (in, typeMouseWheelAxis)
 *          The wheel axis which moved. Contains either
 *          kEventMouseWheelAxisX or kEventMouseWheelAxisY.
 *    
 *    --> kEventParamMouseWheelDelta (in, typeLongInteger)
 *          The amount of change in the wheel position. Generally, a
 *          positive change should be interpreted as an upward scroll
 *          (equivalent to a click in the up arrow of a scrollbar); a
 *          negative change should be interpreted as a downward scroll
 *          (equivalent to a click in the down arrow of a scrollbar).
 *          Applications should not scale the delta value provided in
 *          the event; the Mac OS X input device system provides
 *          pre-scaling according to the user�s desired mouse wheel
 *          speed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMouseWheelMoved         = 10
};

/*��������������������������������������������������������������������������������������*/
/* TSM Document Access Events                                                           */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassTSMDocumentAccess quick reference:
    
    ** Text Access **
    kEventTSMDocumentAccessGetLength                        = 1,
    kEventTSMDocumentAccessGetSelectedRange                 = 2,
    kEventTSMDocumentAccessGetCharactersPtr                 = 3,
    kEventTSMDocumentAccessGetCharactersPtrForLargestBuffer = 4,
    kEventTSMDocumentAccessGetCharacters                    = 5,
        
    ** Text Attribute Access **
    kEventTSMDocumentAccessGetFont                          = 6,
    kEventTSMDocumentAccessGetGlyphInfo                     = 7
    
    ** Transaction control **
    kEventTSMDocumentAccessLockDocument                     = 8,
    kEventTSMDocumentAccessUnlockDocument                   = 9
    
    These events allow access to a document's content.  They are grouped in the following
    categories: text access, text attribute, and transaction related events.
    
    NOTE:  TSM dispatches events of the TSMDocumentAccess class only as Carbon events.  These
            are not converted for TSM clients that still install AppleEvent handlers for TSM events.
    NOTE:  Text Services dispatch these Carbon events through TSM's SendTextInputEvent API.
            Normally only used for TextInput class TSM events, but this SendTextInputEvent is a bit
            of a misnomer.  You should use it for TSMDocumentAccess class events as well.
*/
/*

    ** Document Access Text events **

    The following Text Access events are very similar in design to the CFString API.
    The entire document can be conceived as a flattened Unicode string, and the
    events in this interface can access any portion of it.  The GetSelectedRange() method
    allow a text service to obtain text near the insertion point (or selection), but access
    is by no means restricted to this vicinity.  Use the GetLength() method to obtain the
    size of the document.
    
    Supporting these events effectively provide hooks into the text engine, but it is
    understood that access to a document in this way is to be strictly Read-Only.  Where
    direct access to a document's content cannot be provided through a pointer, the requested
    text can be copied instead.  Situations where a pointer may not be available from the
    text engine include the following:
    
        -A pointer would require conversion of text in Mac encodings to Unicode
        -A pointer would require sparse Unicode text blocks to be flattened into a single
         buffer.

    The idea is to minimize copying and converting text encodings where possible.  The text
    service will typically begin by asking for a document pointer via
    kEventTSMDocumentAccessGetCharactersPtr.  If this fails, it will typically fallback to
    kEventTSMDocumentAccessGetCharactersPtrForLargestBuffer, specifying a location of interest.
    If this fails, it will fallback to kEventTSMDocumentAccessGetCharacters, specifying a range
    of interest.  Of course, when requesting small amounts of data such a few characters on either
    side of the insertion point, there is no obligation to optimize in this way.  It's valid to
    simply use kEventTSMDocumentAccessGetCharacters.
    
    The text engine is entirely free to deny a request for a text pointer for these or any other
    implementation specific reason.
*/
/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetLength
 *  
 *  Summary:
 *    Returns the number of 16-bit Unicode characters in the document.
 *  
 *  Discussion:
 *    This event is equivalent to calling CFStringGetLength() on the
 *    app's document.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    <-- kEventParamTSMDocAccessCharacterCount (out, typeCFIndex)
 *          The size of the document in UniChar. Required reply
 *          parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetLength = 1
};

/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetSelectedRange
 *  
 *  Summary:
 *    Returns the selection range in the document.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    <-- kEventParamTSMDocAccessReplyCharacterRange (out, typeCFRange)
 *          The selection range as a CFRange in UniChar.  If the
 *          selection is empty, the range identifies the insertion
 *          point and the range will specify a length of 0. Required
 *          reply parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetSelectedRange = 2
};

/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetCharactersPtr
 *  
 *  Summary:
 *    Returns a Unicode pointer to the entire document content.
 *  
 *  Discussion:
 *    This event is equivalent to calling CFStringGetCharactersPtr() on
 *    the app's document treated as a CFString. Some text engines may
 *    not support this event for reasons that are implementation
 *    dependent. For example, a text engine's backing store may consist
 *    of legacy encoding runs.  It may also consist of unflattened
 *    Unicode, stored as a B-tree of text blocks.  For such reasons, a
 *    text engine may reject a request for a pointer to a flattened
 *    Unicode buffer. It is also understood that text access through
 *    this pointer is to be strictly READ-ONLY.  Any changes to the
 *    document should be made through TSM TextInput events, such as
 *    kEventTextInputUpdateActiveInputArea or
 *    kEventTextInputUnicodeText. NOTE:  This pointer is valid only
 *    during a transaction surrounded by document lock/unlock events,
 *    or until an event causes the document to change, such as
 *    dispatching kEventTextInputUpdateActiveInputArea or
 *    kEventTextInputUnicodeText events, whichever occurs first.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    <-- kEventParamTSMDocAccessReplyCharactersPtr (out, typePtr)
 *          The UniChar pointer to the document. Required reply
 *          parameter, if the event is supported.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetCharactersPtr = 3
};

/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetCharactersPtrForLargestBuffer
 *  
 *  Summary:
 *    Returns a Unicode pointer to a portion of the document.
 *  
 *  Discussion:
 *    This event is similar to calling CFStringGetCharactersPtr() on a
 *    portion of the app's document treated as a CFString, except that
 *    the substring is determined by the text engine. Some text engines
 *    may keep text in unflattened Unicode, stored as a B-tree of text
 *    blocks, for example.  In some cases, especially near locations
 *    such as the insertion point, the text engine may have cached a
 *    good chunk of text to which it can readily provide a pointer. A
 *    text engine may reject a request for such a pointer. It is also
 *    understood that text access through this pointer is to be
 *    strictly READ-ONLY.  Any changes to the document should be made
 *    through TSM TextInput events, such as
 *    kEventTextInputUpdateActiveInputArea or
 *    kEventTextInputUnicodeText. NOTE:  This pointer is valid only
 *    during a transaction surrounded by document lock/unlock, or until
 *    an event causes the document to change, such as dispatching
 *    kEventTextInputUpdateActiveInputArea or
 *    kEventTextInputUnicodeText events.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTSMDocAccessSendCharacterIndex (in, typeCFIndex)
 *          The location in the document for which the caller would
 *          like a pointer to a buffer of text that includes that
 *          location.    This buffer could be available from a cache
 *          due to recent interaction near that location, such as the
 *          insertion point. Required parameter.
 *    
 *    <-- kEventParamTSMDocAccessReplyCharactersPtr (out, typePtr)
 *          The UniChar pointer to a portion of the document text.
 *          Required reply parameter, if the event is handled.
 *    
 *    <-- kEventParamTSMDocAccessReplyCharacterRange (out, typeCFRange)
 *          The document-relative range of text represented by the
 *          returned text pointer. Required reply parameter, if the
 *          event is handled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetCharactersPtrForLargestBuffer = 4
};

/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetCharacters
 *  
 *  Summary:
 *    Fills caller provided buffer with Unicode characters in the
 *    specified range.
 *  
 *  Discussion:
 *    This event is equivalent to calling CFStringGetCharacters() on
 *    the app's document treated as a CFString.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTSMDocAccessSendCharacterRange (in, typeCFRange)
 *          The range of text that should be copied into the buffer
 *          provided by the caller. Required parameter.
 *    
 *    --> kEventParamTSMDocAccessSendCharactersPtr (in, typePtr)
 *          A buffer provided by the caller to contain the specified
 *          range of UniChars.  This buffer is identical in usage to
 *          that of CFStringGetCharacters(). Required parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetCharacters = 5
};

/*

    ** Document Access Attribute events **

    The following Text Attribute events define how a text service can obtain certain attributes
    at text locations throughout an application's document.

    Currently, the only attributes supported by these events are font (and font size)
    via kEventTSMDocumentAccessGetFont and glyphID/CID info via kEventTSMDocumentAccessGetGlyphInfo.
    
    Where these attributes span multiple characters, effective ranges (over which
    the attribute is constant) are returned by the text engine.
*/

/*
 *  Summary:
 *    Values used TSMDocAccessAttributes bit field
 *  
 *  Discussion:
 *    The following bit assignments are used for TSMDocAccessAttributes
 *    parameters. This parameter is used to specify desired (optional)
 *    attributes in the kEventTSMDocumentAccessGetFont and
 *    kEventTSMDocumentAccessGetGlyphInfo events. They are specified in
 *    the kEventParamTSMDocAccessRequestedCharacterAttributes parameter.
 */
enum {

  /*
   * Font size information is desired.  Used in
   * kEventTSMDocumentAccessGetFont event.
   */
  kTSMDocAccessFontSizeAttributeBit = 0,

  /*
   * Effective Range information is desired.  Used in
   * kEventTSMDocumentAccessGetFont and
   * kEventTSMDocumentAccessGetGlyphInfo events.
   */
  kTSMDocAccessEffectiveRangeAttributeBit = 1
};

typedef UInt32 TSMDocAccessAttributes;
enum {
  kTSMDocAccessFontSizeAttribute = 1L << kTSMDocAccessFontSizeAttributeBit,
  kTSMDocAccessEffectiveRangeAttribute = 1L << kTSMDocAccessEffectiveRangeAttributeBit /* More attributes may be added in the future*/
};


/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetFont
 *  
 *  Summary:
 *    Returns font, font size, and the range over which these
 *    attributes are constant.
 *  
 *  Discussion:
 *    Where the font/font size attributes span multiple characters, an
 *    effective range (over which requested attributes are constant) is
 *    returned by the text engine.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTSMDocAccessSendCharacterIndex (in, typeCFIndex)
 *          The location in the document for which the caller would
 *          like font information. Required parameter.
 *    
 *    --> kEventParamTSMDocAccessRequestedCharacterAttributes (in, typeUInt32)
 *          A TSMDocAccessAttributes bit field filled out with the
 *          attributes desired. Applicable values for this event are :
 *          kTSMDocAccessFontSizeAttribute which requests font size
 *          information through the
 *          kEventParamTSMDocAccessReplyFontSize parameter, and
 *          kTSMDocAccessEffectiveRangeAttribute which requests the
 *          text range over which font or font/size is constant.
 *          Required parameter.
 *    
 *    <-- kEventParamTSMDocAccessReplyATSFont (out, typeATSFontRef)
 *          The ATSFontRef for the location specified  by the caller.
 *          Required reply parameter.
 *    
 *    <-- kEventParamTSMDocAccessReplyFontSize (out, typeFloat)
 *          The font size for the requested location. Optional reply
 *          parameter. Return this information if
 *          kTSMDocAccessFontSizeAttribute is specified in the bit
 *          field passed as the
 *          kEventParamTSMDocAccessRequestedCharacterAttributes
 *          parameter.
 *    
 *    --> kEventParamTSMDocAccessSendCharacterRange (in, typeCFRange)
 *          The maximum range of text the caller cares about.  This is
 *          used to "clip" the area of interest to the caller so the
 *          text engine doesn't need to process a style run all the way
 *          back to, say, the beginning of a line or a document, in
 *          order to return an effective range. Required parameter.
 *    
 *    <-- kEventParamTSMDocAccessEffectiveRange (out, typeCFRange)
 *          The range of text over which both font and size are
 *          constant, within the bounds of the
 *          kEventParamTSMDocAccessSendCharacterRange parameter.
 *          Optional reply parameter. Return this information if
 *          kTSMDocAccessEffectiveRangeAttribute is specified in the
 *          bit field passed as the
 *          kEventParamTSMDocAccessRequestedCharacterAttributes
 *          parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetFont = 6
};

/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessGetGlyphInfo
 *  
 *  Summary:
 *    Returns glyph info and the range covered by that glyph.
 *  
 *  Discussion:
 *    Where a glyph spans multiple characters, the effective range,
 *    represented by the glyph, is returned by the app.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTSMDocAccessSendCharacterIndex (in, typeCFIndex)
 *          The location in the document for which the caller would
 *          like glyph information. Required parameter.
 *    
 *    --> kEventParamTSMDocAccessRequestedCharacterAttributes (in, typeUInt32)
 *          A TSMDocAccessAttributes bit field filled out with the
 *          information desired. Applicable values for this event are :
 *          kTSMDocAccessEffectiveRangeAttribute which requests the
 *          text range represented by a glyph. Required parameter.
 *    
 *    <-- kEventParamTSMDocAccessReplyATSUGlyphSelector (out, typeGlyphSelector)
 *          The glyph used to display the range of text returned in the
 *          kEventParamTSMDocAccessEffectiveRange parameter.  If the
 *          glyph used is the one that ATSUI would normally derive,
 *          this parameter can be omitted. Optional reply parameter.
 *    
 *    <-- kEventParamTSMDocAccessEffectiveRange (out, typeCFRange)
 *          The range of text displayed as a glyph ID or CID. Optional
 *          reply parameter. Return this information if
 *          kTSMDocAccessEffectiveRangeAttribute is specified in the
 *          bit field passed as the
 *          kEventParamTSMDocAccessRequestedCharacterAttributes
 *          parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessGetGlyphInfo = 7
};

/*

    ** Document Access Lock/Unlock events **

*/
/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessLockDocument
 *  
 *  Summary:
 *    Notifies the app that it should not change its document's text
 *    content (on its own) while a text service is involved in a
 *    transaction.  The app should not allow changes, for example, by
 *    its secondary threads.
 *  
 *  Discussion:
 *    These events define how a text service can obtain access to a
 *    document in a way that ensures data integrity during its
 *    transaction.  The primary motivation of these events is to
 *    prevent the application from letting its secondary threads modify
 *    the document while a text service is busy servicing an event,
 *    such as a key event, or some user interaction with text service
 *    provided UI such as a menu selection. Also, while the document is
 *    locked, a text service is free to request pointer access to the
 *    document's text content (if this is supported by the app's text
 *    engine.) These lock-related events should be implemented using a
 *    ref counting scheme. Most apps will not support this kind of
 *    threading, so implementation of these events in the text engine
 *    will be optional.   In most text engines, the implementation of
 *    these events should be trivial, i.e. just maintain a simple
 *    semaphore.  TSM itself will implicitly lock/unlock around normal
 *    entry points into a text service, such as when it delivers key
 *    events to an input method, but there may be times when document
 *    changes can be driven by an input method without TSM involvement,
 *    such as the Carbon events involved when the user interacts with
 *    some UI.  In this case, the input method must manage locking, if
 *    the app supports it.  However, the logic in an input method
 *    should not have to care whether TSM is in the call chain or
 *    not... and TSM should not have to care whether an input method
 *    will do the right thing. This is why the lock mechanism needs to
 *    be some kind of refcounting scheme instead of a simple on/off
 *    mechanism. This document lock support is completely optional on
 *    the part of the text engine (if it is not threaded).  TSM will
 *    implicitly lock/unlock the document around delivery of events to
 *    input methods, if the app supports it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    <-- kEventParamTSMDocAccessLockCount (out, typeCFIndex)
 *          The resulting refCount of locks on the document. Required
 *          reply parameter, if the event is handled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessLockDocument = 8
};


/*
 *  kEventClassTSMDocumentAccess / kEventTSMDocumentAccessUnlockDocument
 *  
 *  Summary:
 *    Unlock the document so the app's text engine is free to initiate
 *    changes again.
 *  
 *  Discussion:
 *    (see kEventTSMDocumentAccessLockDocument)
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTSMDocAccessSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTSMDocAccessSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    <-- kEventParamTSMDocAccessLockCount (out, typeCFIndex)
 *          The resulting refCount of locks on the document. Required
 *          reply parameter, if the event is handled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTSMDocumentAccessUnlockDocument = 9
};


/*��������������������������������������������������������������������������������������*/
/* Text Input Events                                                                    */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassTextInput quick reference:
    
    kEventTextInputUpdateActiveInputArea    = 1,
    kEventTextInputUnicodeForKeyEvent       = 2,
    kEventTextInputOffsetToPos              = 3,
    kEventTextInputPosToOffset              = 4,
    kEventTextInputShowHideBottomWindow     = 5,
    kEventTextInputGetSelectedText          = 6,
    kEventTextInputUnicodeText              = 7
    
    The following TextInput events (UpdateActiveInputArea thru GetSelectedText) reimplement
    the AppleEvents defined in Inside Mac Text: Text Services Manager, and provide the benefits
    of Carbon Event targeting, dispatching, and propagation to applications that have formerly
    handled the TSM suite of AppleEvents.
    TextInput handlers may be installed on controls, windows, or the application event target
    (equivalent to AppleEvent-based handling). In all cases, if a given TextInput handler is
    not installed, TSM will convert that TextInput to an AppleEvent and redispatch via AESend
    to the current process, making adoption as gradual as is desired.
*/
/*
 *  kEventClassTextInput / kEventTextInputUpdateActiveInputArea
 *  
 *  Summary:
 *    Tells the application/text engine to initiate/terminate or manage
 *    the content of an inline input session.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendSLRec (in, typeIntlWritingCode)
 *          The ScriptLanguageRecord associated with the contents of an
 *          inline input session.  This parameter is normally provided
 *          by the input method originating the event.  TSM's
 *          SendTextInputEvent will construct this parameter, when
 *          missing, based on the input method component description. 
 *          (Required Parameter)
 *    
 *    --> kEventParamTextInputSendFixLen (in, typeLongInteger)
 *          This parameter indicates how much, if any, of the inline
 *          input session is being confirmed (or commited) to the
 *          application.  A value of -1 indicates the entire inline
 *          session is being confirmed.  A value of 0 indicates that
 *          none of the text is being confirmed (yet), although there
 *          may be some change to the contents of the inline input
 *          session.  This parameter is provided by the input method
 *          originating the event.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendText (in, typeUnicodeText)
 *          The text to be added to the inline input session. The data
 *          type of this parameter actually depends on the TSMDocument
 *          type created via NewTSMDocument: it will be typeChar for
 *          kTextService documents, or typeUnicodeText for
 *          kUnicodeDocument documents.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendUpdateRng (in, typeTextRangeArray)
 *          An array of text-range records (see TextRangeArray) that
 *          indicates how to update (a subrange of) the active input
 *          area (aka. inline input session).  The TextRange structures
 *          occur in pairs, the first of which identifies a subrange of
 *          the existing active input area (in the app's backing store,
 *          resulting from a previous UpdateActiveInputArea event) to
 *          be replaced by a new subrange of text, identified by the
 *          second TextRange in the pair.  The new text subrange is
 *          obtained from the contents of the
 *          kEventParamTextInputSendText parameter.  In general, the
 *          Nth array element, where N is even, specifies the range of
 *          old text to be updated and array element N+1 specifies the
 *          range of new text to replace the corresponding old text. 
 *          The fHiliteStyle field of the TextRange records is ignored
 *          in this parameter. NOTE:  There are some "loose ends" in
 *          the TSM event protocol that were never clearly defined, but
 *          which have been introduced over the years by input methods
 *          themselves, probably through some trial and error.  The
 *          conventions regarding this optional parameter seem to be as
 *          follows: If the UpdateRng parameter is missing from the
 *          event, the input method is requesting that the entire
 *          contents of the existing inline input session (if there is
 *          one) is to be replaced "wholesale" by the new text
 *          contained in the kEventParamTextInputSendText parameter. If
 *          the UpdateRng parameter exists, but contains no ranges
 *          (i.e. fNumOfRanges == 0), this seems to be hint from the
 *          input method that no text in the active input area is
 *          changing.  It may be that the existing active input area is
 *          being confirmed "as is", or that the input method is
 *          modifying its highlite attributes in some way, due to some
 *          user action, such as changing the selected clause or
 *          highlited subrange of text in the active input area, or
 *          that the input method is changing the caret position in the
 *          active input area (if it uses the kCaretPosition hilite
 *          style). Depending on how your text engine draws hilite
 *          styles supported in the kEventParamTextInputSendHiliteRng
 *          parameter, you may or may not need to redraw the text
 *          itself, simply change the hilite. This parameter is
 *          optional and may not be present in all instances of this
 *          event.
 *    
 *    --> kEventParamTextInputSendHiliteRng (in, typeTextRangeArray)
 *          An array of text-range records (see TextRangeArray) that
 *          specifies how various subranges of the active input area
 *          are to be highlited, and possibly specifies caret position
 *          within the active input area. NOTE:  The text offsets used
 *          in the HiliteRng parameter are relative to the beginning of
 *          the active input area AFTER all text has been updated (per
 *          the SendUpdateRng parameter) and any (subrange of) text has
 *          been confirmed.  Specifically, if the entire text is being
 *          confirmed, it is clear that any contents of this parameter
 *          should be ignored, especially non-zero values
 *          kCaretPosition. This parameter is optional and may not be
 *          present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendClauseRng (in, typeOffsetArray)
 *          An array of offsets (see OffsetArray) used by an input
 *          method to specify word or clause boundaries in the
 *          resulting active input area.  Offsets are relative to the
 *          start of the resulting active input area. This parameter is
 *          optional and may not be present in all instances of this
 *          event.
 *    
 *    --> kEventParamTextInputSendPinRng (in, typeTextRange)
 *          A TextRange record that specifies a start offset and an end
 *          offset that should be scrolled into view if the text
 *          specified by these offsets is not already in view. The
 *          fHiliteStyle field of the TextRange records is ignored in
 *          this parameter. This parameter is optional and may not be
 *          present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendTextServiceEncoding (in, typeUInt32)
 *          The encoding associated with the text sent by an input
 *          method. On MacOS X, this parameter is not commonly used
 *          because all TSM input methods produce Unicode, but TSM will
 *          respect a Unicode encoding variant here, if specified. In
 *          CarbonLib, this parameter identifies the Mac encoding
 *          (usually an encoding variant) of the text produced by the
 *          input method on MacOS, where it is not a requirement that
 *          input methods be Unicode-savvy.  On this platform, TSM
 *          needs the information to convert text to Unicode from a Mac
 *          encoding variant which cannot be derived from the
 *          ScriptLanguage record associated with the input method
 *          component. This parameter is optional and may not be
 *          present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendTextServiceMacEncoding (in, typeUInt32)
 *          The Mac encoding (variant) associated with the text sent by
 *          an input method. On Mac OS X, this parameter is needed by
 *          TSM to convert input method produced Unicodes to a Mac
 *          encoding when the application that has focus is not
 *          Unicode-savvy in the TSM sense... i.e. the current
 *          TSMDocument is not of type kUnicodeDocument. This parameter
 *          can also be useful if a Unicode-savvy handler should need
 *          to convert from Unicode. This parameter is optional and may
 *          not be present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendGlyphInfoArray (in, typeGlyphInfoArray)
 *          A TSMGlyphInfoArray structure in which an input method can
 *          associate unencoded glyphs IDs and/or fonts with
 *          (sub)ranges of text it produces.  The array elements
 *          identify non-overlapping ranges of text and the glyph ID
 *          (character collection is 0) such as in an OpenType font, or
 *          the CID (collection is non-zero) such as in TrueType fonts.
 *           If the glyphID itself is 0, only the font specified is to
 *          be applied to the text range.  This is useful for
 *          characters in Unicode private use area, such as Windings,
 *          but note that this capability should be used with care
 *          because changing the font of an input text stream can lead
 *          to a confusing user interface. An input method will only
 *          include this parameter if the text engine has indicated it
 *          supports this feature via the
 *          kTSMDocumentSupportGlyphInfoPropertyTag TSMDocumentProperty
 *          tag. For more information, see the Glyph Access protocol
 *          described in TechNote TN20TT. This parameter is optional
 *          and may not be present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendReplaceRange (in, typeCFRange)
 *          The CFRange in the application's document that should be
 *          replaced by the contents of the inline input session
 *          defined by other parameters in this event.  The text
 *          service will have obtained and calculated this range by
 *          accessing the document's text via events of the
 *          TSMDocumentAccess class.  This CFRange parameter refers to
 *          text in flat Unicode space (UniChar) offsets, and its
 *          location is document relative, not relative to the
 *          insertion point or any inline session. A text service may
 *          include this parameter only if the text engine has
 *          indicated it supports this feature via the
 *          kTSMDocumentSupportDocumentAccessPropertyTag
 *          TSMDocumentProperty tag. This parameter is optional and may
 *          not be present in all instances of this event. NOTE:  This
 *          parameter is supported by the TSM Carbon event only, not by
 *          TSM's kUpdateActiveInputArea AppleEvent.  If a text engine
 *          developer wishes to support this parameter, it must
 *          implement a Carbon event handler for this event and set the
 *          kTSMDocumentSupportDocumentAccessPropertyTag property tag.
 *          NOTE:  Care must be exercised by the app when there is an
 *          active inline input session. A text service that sends an a
 *          UpdateActiveInputArea event specifying this parameter
 *          should not be the same text service that owns the inline
 *          input session, since the text engine would need to call
 *          FixTSMDocument().  This, in turn, would cause recursion
 *          through that same text service via FixTextService().
 *          However, the app should be prepared for recursion
 *          regardless of which text service owns the inline input
 *          session because it will call FixTSMDocument() to confirm
 *          the inline input session, and "somebody" will likely send
 *          an UpdateActiveInputArea event as a result. Therefore,
 *          document state obtained before the call to FixTSMDocument()
 *          may not be valid after this call completes.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputUpdateActiveInputArea = 1
};

/*
 *  kEventClassTextInput / kEventTextInputUnicodeForKeyEvent
 *  
 *  Summary:
 *    Provides Unicode text input resulting from either a key event
 *    (TSM originates the event in this case) or from a
 *    kEventTextInputUnicodeText event produced by an input method,
 *    such as a Character Palette class input method, or a HandWriting
 *    input method.
 *  
 *  Discussion:
 *    This is the primary event by which applications should receive
 *    text input on Mac OS X. Apple recommends that applications use
 *    this event rather than the kEventRawKeyDown event to handle text
 *    input. 
 *    
 *    A client need not be fully TSM-aware to process or receive this
 *    event. You can also get Mac encoding characters from the raw
 *    keyboard event contained in this event. If no UnicodeForKeyEvent
 *    handler is installed, and no kUnicodeNotFromInputMethod
 *    AppleEvent handler is installed (or the application has not
 *    created a Unicode TSMDocument), the Mac encoding charCodes (if
 *    these can be converted from the Unicodes) are provided to
 *    WaitNextEvent. 
 *    
 *    This event is generated automatically by TSM when a
 *    kEventRawKeyDown event is sent to the application event target.
 *    The typical keyboard event flow begins with a kEventRawKeyDown
 *    event posted to the event queue. This event is dequeued during
 *    WaitNextEvent or RunApplicationEventLoop, and sent to the event
 *    dispatcher target. If the keydown event reaches the application
 *    target, it is handled by TSM, which generates a
 *    kEventTextInputUnicodeForKeyEvent and sends it to the event
 *    dispatcher target. The event dispatcher will resend the event to
 *    the user focus target, which sends it to the focused control in
 *    the focused window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendSLRec (in, typeIntlWritingCode)
 *          The ScriptLanguageRecord associated with the text contained
 *          in the event. This parameter is normally provided by the
 *          input method originating the event.  TSM's
 *          SendTextInputEvent will construct this parameter from
 *          current script information as a result of a key event, or
 *          using input method provided information when TSM receives a
 *          kEventTextInputUnicodeText event.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendText (in, typeUnicodeText)
 *          The Unicode characters that were entered by the user.
 *    
 *    --> kEventParamTextInputSendKeyboardEvent (in, typeEventRef)
 *          This parameter is the original raw keyboard event that
 *          produced the text. It enables access to
 *          kEventParamKeyModifiers and kEventParamKeyCode parameters.
 *          Note that when contents of TSM�s bottom-line input window
 *          are confirmed (i.e., during typing of Chinese, Korean, or
 *          Japanese), the raw keyboard event�s keyCode and modifiers
 *          are set to default values. 
 *          
 *          You can also extract from the RawKeyDown event either
 *          Unicodes or Mac encoding characters as follows:
 *          
 *          kEventParamKeyUnicodes      typeUnicodeText
 *           kEventParamKeyMacCharCodes  typeChar (if available)
 *           
 *          The kEventParamKeyUnicodes parameter of the raw keyboard
 *          event is identical to the TextInput event�s
 *          kEventParamTextInputSendText parameter.
 *    
 *    --> kEventParamTextInputSendGlyphInfoArray (in, typeGlyphInfoArray)
 *          A TSMGlyphInfoArray structure in which an input method can
 *          associate unencoded glyphs IDs and/or fonts with
 *          (sub)ranges of text it produces.  The array elements
 *          identify non-overlapping ranges of text and the glyph ID
 *          (character collection is 0) such as in an OpenType font, or
 *          the CID (collection is non-zero) such as in TrueType fonts.
 *           If the glyphID itself is 0, only the font specified is to
 *          be applied to the text range.  This is useful for
 *          characters in Unicode private use area, such as Windings,
 *          but note that this capability should be used with care
 *          because changing the font of an input text stream can lead
 *          to a confusing user interface. For more information, see
 *          the Glyph Access protocol described in TechNote TN20TT.
 *          This parameter is optional and may not be present in all
 *          instances of this event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputUnicodeForKeyEvent = 2
};

/*
 *  kEventClassTextInput / kEventTextInputOffsetToPos
 *  
 *  Summary:
 *    Requests conversion from inline session text offset to global QD
 *    coordinate.
 *  
 *  Discussion:
 *    This event is typically produced by an input method so that it
 *    can best position a palette near the text being edited by the
 *    user.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendTextOffset (in, typeLongInteger)
 *          The text offset in an active input area for which the
 *          global position (in QD coordinates) is desired.  (Required
 *          Parameter) NOTE:  If no input area is active, the original
 *          definition of this parameter IM-Text 7-74 states that the
 *          offset is "relative to the start of the current text body".
 *           However, some applications have implemented the case
 *          offset = 0 relative to the insertion point, which makes
 *          some sense in that an input method is typically interested
 *          in interacting with the user at the insertion point and
 *          this allows an input method to display some UI (such as a
 *          translucent input mode indicator)  near the insertion point
 *          even before typing has taken place.  Input Methods usually
 *          have no reason to care about the on-screen position of the
 *          beginning of a text document.
 *          
 *          However, new events in the TSM suite now allow an input
 *          method to obtain the insertion point as a document-relative
 *          offset in Unicode space, so the original definition of this
 *          parameter should hold... the text offset is to be
 *          considered relative to the beginning of the text document,
 *          especially when the app indicates it supports the TSM text
 *          Attribute events, specifically
 *          kEventTextInputGetInsertionPointAttributes.
 *    
 *    --> kEventParamTextInputSendSLRec (in, typeIntlWritingCode)
 *          Specifies which glyph on either side of the supplied text
 *          offset that should be used to compute the on-screen
 *          position returned.  This value is similar to the
 *          leadingEdge parameter of the QuickDraw PixelToChar
 *          function.  If this parameter is true, the location of the
 *          character (or characters if the glyph is represented by
 *          multiple characters) at the specified text offset is
 *          returned.  If this parameter is false, the on-screen
 *          position returned should be the trailing edge of the glyph
 *          represented by the character (or characters) immediately
 *          preceding (in memory order) the supplied text offset. Note
 *          also that while the on-screen position for a given offset
 *          and leading/trailing edge value is affected by this
 *          parameter, it also affects what should be returned for the
 *          other optional parameters at style run boundaries, such as
 *          script and font information. This parameter is optional and
 *          may not be present in all instances of this event. The
 *          default value for this parameter is 'true'.
 *    
 *    --> kEventParamTextInputSendLeadingEdge (in, typeBoolean)
 *          The position on screen (in QD coordinates) of the requested
 *          text offset and leading/trailing edge value.  (Required
 *          reply parameter)
 *    
 *    <-- kEventParamTextInputReplyPoint (out, typeQDPoint)
 *          The ScriptLanguageRecord associated with the text at the
 *          offset specified in the event, either the
 *          ScriptLanguageRecord of the active input area if one
 *          exists, or of the text at the specified offset and
 *          specified leading/ trailing edge value.  At a script run
 *          boundary, such as where a Japanese text run ends, and a
 *          Roman begins, a leading edge value of 'true' should return
 *          the Roman script/language while a leading edge value of
 *          'false' should return the Japanese script/language. This
 *          parameter is optional and may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplySLRec (out, typeIntlWritingCode)
 *          The QD Font associated with the text at the offset
 *          specified in the event, either the QD Font of the active
 *          input area if one exists, or of the text at the specified
 *          offset and specified leading/ trailing edge value.  At a
 *          font run boundary, such as where a Japanese text run ends,
 *          and a Roman begins, a leading edge value of 'true' should
 *          return the font of the Roman text run while a leading edge
 *          value of 'false' should return the Japanese font. This
 *          parameter is optional and may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyFont (out, typeLongInteger)
 *          The FMFont associated with the text at the offset specified
 *          in the event, either the FMFont of the active input area if
 *          one exists, or of the text at the specified offset and
 *          specified leading/ trailing edge value.  At a font run
 *          boundary, such as where a Japanese text run ends, and a
 *          Roman begins, a leading edge value of 'true' should return
 *          the font of the Roman text run while a leading edge value
 *          of 'false' should return the Japanese font. This parameter
 *          allows the handler to return an FMFont when a FMFontFamily
 *          or FOND would be inconvenient to compute. This parameter is
 *          optional and may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyFMFont (out, typeUInt32)
 *          The point size associated with the text at the offset
 *          specified in the event, either the point size of the active
 *          input area if one exists, or of the text at the specified
 *          offset.  At a style run boundary where point size changes,
 *          the leadingEdge parameter determines which point size
 *          should be returned. This parameter is optional and may not
 *          be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyPointSize (out, typeFixed)
 *          The line height associated with the text at the offset
 *          specified in the event, either the line height of the
 *          active input area if one exists, or of the text at the
 *          specified offset.  At a style run boundary where point size
 *          changes, the leadingEdge parameter determines which line
 *          height should be returned. This parameter is optional and
 *          may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyLineHeight (out, typeShortInteger)
 *          The line ascent associated with the text at the offset
 *          specified in the event, either the line ascent of the
 *          active input area if one exists, or of the text at the
 *          specified offset.  At a style run boundary where point size
 *          changes, the leadingEdge parameter determines which line
 *          ascent should be returned. This parameter is optional and
 *          may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyLineAscent (out, typeShortInteger)
 *          The orientation associated with the text at the offset
 *          specified in the event, either the orientation of the
 *          active input area if one exists, or of the text at the
 *          specified offset.  At a style run boundary where
 *          orientation changes, the leadingEdge parameter determines
 *          which orientation should be returned.  The value 90
 *          specifies a horizontal line direction and 180 specifies a
 *          vertical line direction. This parameter is optional and may
 *          not be returned to the caller.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputOffsetToPos    = 3
};

/*
 *  kEventClassTextInput / kEventTextInputPosToOffset
 *  
 *  Summary:
 *    Requests conversion from global QD coordinate to inline session
 *    text offset.
 *  
 *  Discussion:
 *    This event is typically produced by an input method to perform
 *    proper cursor management as the cursor moves over various
 *    subranges, or clauses of text (or the boundaries between these)
 *    in the inline input session.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendCurrentPoint (in, typeQDPoint)
 *          The point (in QD coordinates) whose text offset in the
 *          active input area the input method method is requesting. 
 *          (Required Parameter)
 *    
 *    --> kEventParamTextInputSendDraggingMode (in, typeBoolean)
 *          A Boolean value that indicates whether the input method is
 *          currently tracking the mouse -- that is, whether the user
 *          is dragging the current selection. If it is TRUE, the
 *          application should pin the cursor to the limits of the
 *          active input area (to avoid highlighting beyond the limits
 *          of the active input area). This parameter is optional and
 *          may not be present in all instances of this event.
 *    
 *    <-- kEventParamTextInputReplyRegionClass (out, typeLongInteger)
 *          The text offset corresponding to the supplied QD point. If
 *          the click is within the limits of the active input area,
 *          the offset is relative to the start of the active input
 *          area. Otherwise, the offset is relative to the start of the
 *          application's text body.  (Required reply parameter)
 *    
 *    <-- kEventParamTextInputReplyTextOffset (out, typeLongInteger)
 *          The classification of the offset parameter.  The values
 *          kTSMOutsideOfBody and kTSMInsideOfBody means that the
 *          position is outside or inside of the text body,
 *          respectively.  A value of kTSMInsideOfActiveInputArea means
 *          that the position is inside of the active input area. 
 *          (Required reply parameter)
 *    
 *    <-- kEventParamTextInputReplyLeadingEdge (out, typeBoolean)
 *          Specifies whether the QD point supplied corresponds to the
 *          leading edge (true) or trailing edge (false) of a glyph. 
 *          This value is similar to the leadingEdge parameter of the
 *          QuickDraw PixelToChar function. If the supplied point is on
 *          the leading edge of a glyph, this parameter contains the
 *          text offset of the character whose glyph is at the pixel
 *          location.  (If the glyph represents multiple characters, it
 *          returns the text offset of the first of these characters in
 *          memory.)  If the supplied point is on the trailing edge of
 *          a glyph, this parameter returns the text offset of the
 *          first character in memory following the character or
 *          characters represented by the glyph. This parameter is
 *          optional and may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplySLRec (out, typeIntlWritingCode)
 *          The ScriptLanguageRecord of the script run containing the
 *          character at the returned text offset and leading/trailing
 *          edge value. This parameter is optional and may not be
 *          returned to the caller.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputPosToOffset    = 4
};

/*
 *  kEventClassTextInput / kEventTextInputShowHideBottomWindow
 *  
 *  Summary:
 *    Show or hide the bottom-line input window.
 *  
 *  Discussion:
 *    This event is produced by input methods to control the Text
 *    Services Manager bottom-line input window, and is not normally
 *    handled by an application.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendShowHide (in, typeBoolean)
 *          If true, the bottomline input window should be shown; if
 *          false, it should be hidden. This parameter is not needed if
 *          the input method is simply inquiring about the state of the
 *          input window. This parameter is optional and may not be
 *          present in all instances of this event.
 *    
 *    <-- kEventParamTextInputReplyShowHide (out, typeBoolean)
 *          The current state of the input window: true if the window
 *          is shown; false if it is hidden. If the optional parameter
 *          kEventParamTextInputSendShowHide is included, this return
 *          parameter should show the state of the window before it was
 *          set to the state requested in the optional parameter. This
 *          parameter is optional and may not be returned to the caller.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputShowHideBottomWindow = 5
};

/*
 *  kEventClassTextInput / kEventTextInputGetSelectedText
 *  
 *  Summary:
 *    Get the selected text (or the character before or after the
 *    insertion point, based on the leadingEdge parameter) from the
 *    application�s text engine.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendRefCon (in, typeLongInteger)
 *          TSM's SendTextInputEvent, called by an input method,
 *          inserts this parameter before dispatching the event to the
 *          user focus.  (Required Parameter)
 *    
 *    --> kEventParamTextInputSendLeadingEdge (in, typeBoolean)
 *          If there is a non-empty selection, this parameter should be
 *          ignored.  When the current selection is empty, i.e. an
 *          insertion point, and this parameter is NOT supplied, no
 *          text should be returned. If the current selection is empty
 *          and this parameter is supplied, return the character (or
 *          characters) representing the glyph on the side of the
 *          insertion point indicated by this leadingEdge parameter.
 *          This value is similar to the leadingEdge parameter of the
 *          QuickDraw PixelToChar function.  If this parameter is true,
 *          the character (or characters) at the insertion point is
 *          returned.  If this parameter is false, the character (or
 *          characters) immediately preceding (in memory order) the
 *          insertion point should be returned. This parameter is
 *          optional and may not be present in all instances of this
 *          event. This parameter has no default value and no text
 *          should be returned when this parameter is ommited and there
 *          is no selected text.
 *    
 *    --> kEventParamTextInputSendTextServiceEncoding (in, typeUInt32)
 *          The encoding associated with the text sent by an input
 *          method. On MacOS X, this parameter is not commonly used
 *          because all TSM input methods produce (and request)
 *          Unicode, but if specified, this may be a Unicode variant
 *          encoding. In CarbonLib on MacOS, this parameter identifies
 *          the Mac encoding (usually an encoding variant) of the text
 *          produced by the input method on MacOS, where it is not a
 *          requirement that input methods be Unicode-savvy.  On this
 *          platform, TSM needs the information to convert text to
 *          Unicode from a Mac encoding variant which cannot be derived
 *          from the ScriptLanguage record associated with the input
 *          method component. This parameter is optional and may not be
 *          present in all instances of this event.
 *    
 *    <-- kEventParamTextInputReplyText (out, typeUnicodeText)
 *          The data type of this parameter actually depends on the
 *          TSMDocument type created via NewTSMDocument: it should be
 *          typeChar for kTextService documents, or typeUnicodeText for
 *          kUnicodeDocument documents. This parameter is optional and
 *          may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplySLRec (out, typeIntlWritingCode)
 *          The ScriptLanguageRecord of the script run containing the
 *          text being returned to an input method. This parameter is
 *          optional and may not be returned to the caller.
 *    
 *    <-- kEventParamTextInputReplyMacEncoding (out, typeUInt32)
 *          The Mac encoding (variant) associated with the text
 *          returned to the input method. On Mac OS X, this parameter
 *          may needed by TSM to convert application produced text from
 *          a Mac encoding to Unicodes returned to the input method.
 *          This parameter is optional and may not be returned to the
 *          caller.
 *    
 *    <-- kEventParamTextInputGlyphInfoArray (out, typeGlyphInfoArray)
 *          A TSMGlyphInfoArray structure in which the event handler
 *          can associate unencoded glyphs IDs and/or fonts with
 *          (sub)ranges of text it returns.  The array elements
 *          identify non-overlapping ranges of text and the glyph ID
 *          (character collection is 0) such as in an OpenType font, or
 *          the CID (collection is non-zero) such as in TrueType fonts.
 *           If the glyphID itself is 0, only the font specified is to
 *          be applied to the text range.  This is useful for
 *          characters in Unicode private use area. For more
 *          information, see the Glyph Access protocol described in
 *          TechNote TN20TT. This parameter is optional and may not be
 *          returned to the caller. NOTE:  This parameter should really
 *          have been kEventParamTextInputReplyGlyphInfoArray, which
 *          was introduced after glyphInfo support was added to this
 *          event, but we can't change it now without breaking binary
 *          compatibility.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventTextInputGetSelectedText = 6
};

/*
 *  kEventClassTextInput / kEventTextInputUnicodeText
 *  
 *  Summary:
 *    Used by input methods to provide original input text to the Text
 *    Services Manager.
 *  
 *  Discussion:
 *    This Unicode text event is produced only by input methods or
 *    other text services, and is delivered to TSM via
 *    SendTextInputEvent(). TSM never dispatches this event to the user
 *    focus, so application handlers should NOT install handlers for
 *    this event. Instead, TSM chains this event into any active
 *    keyboard input method in order to prevent interference with
 *    existing inline input sessions. The keyboard input method can
 *    either insert the text into the inline session, or it may confirm
 *    its session and return the UnicodeText event to TSM unhandled, in
 *    which case TSM will convert the event into a UnicodeForKey event
 *    (converting the Unicodes to Mac charCodes and synthesizing
 *    information where needed) and finally dispatch the resulting
 *    event to the user focus as usual.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTextInputSendComponentInstance (in, typeComponentInstance)
 *          This parameter is provided by the input method originating
 *          the event. (Required parameter)
 *    
 *    --> kEventParamTextInputSendSLRec (in, typeIntlWritingCode)
 *          The ScriptLanguageRecord associated with the text contained
 *          in the event. This parameter is provided by the input
 *          method originating the event. This parameter is optional
 *          and may not be present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendText (in, typeUnicodeText)
 *          The Unicode characters produced by an input method. 
 *          (Required Parameter)
 *    
 *    --> kEventParamTextInputSendTextServiceEncoding (in, typeUInt32)
 *          The encoding associated with the text sent by an input
 *          method. On MacOS X, this parameter is not commonly used
 *          because all TSM input methods produce (and request)
 *          Unicode, but if specified, this may be a Unicode variant
 *          encoding. This parameter is optional and may not be present
 *          in all instances of this event.
 *    
 *    --> kEventParamTextInputSendTextServiceMacEncoding (in, typeUInt32)
 *          The Mac encoding (variant) associated with the text sent by
 *          an input method, should TSM or an event handler need to
 *          convert the Unicodes. This parameter is optional and may
 *          not be present in all instances of this event.
 *    
 *    --> kEventParamTextInputSendGlyphInfoArray (in, typeGlyphInfoArray)
 *          A TSMGlyphInfoArray structure in which an input method can
 *          associate unencoded glyphs IDs and/or fonts with
 *          (sub)ranges of text it produces.  The array elements
 *          identify non-overlapping ranges of text and the glyph ID
 *          (character collection is 0) such as in an OpenType font, or
 *          the CID (collection is non-zero) such as in TrueType fonts.
 *           If the glyphID itself is 0, only the font specified is to
 *          be applied to the text range.  This is useful for
 *          characters in Unicode private use area, such as Windings,
 *          but note that this capability should be used with care
 *          because changing the font of an input text stream can lead
 *          to a confusing user interface. For more information, see
 *          the Glyph Access protocol described in TechNote TN20TT.
 *          This parameter is optional and may not be present in all
 *          instances of this event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTextInputUnicodeText    = 7
};


/*��������������������������������������������������������������������������������������*/
/* Raw Keyboard Events                                                                  */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassKeyboard quick reference:
    
    kEventRawKeyDown                = 1,
    kEventRawKeyRepeat              = 2,
    kEventRawKeyUp                  = 3,
    kEventRawKeyModifiersChanged    = 4,
    kEventHotKeyPressed             = 5,
    kEventHotKeyReleased            = 6
};

|*!
    @event          kEventRawKeyDown
    @abstract       A key was pressed.
    
    @discussion     This is the lowest-level keyboard input event. When this event is sent, the keyboard
                    input has not yet been processed by the Text Services Manager or passed to input methods.
                    Usually, you should not handle this event, because doing so may interfere with input
                    methods; instead, you should handle the kEventTextInputUnicodeForKeyEvent event, which
                    is sent after input methods have handled the raw key event, and contains both Unicode
                    and the original keyboard event.
                    
                    This event has a default handler on the application event target. The default handler
                    calls the Text Services Manager to pass the event through to input methods. The default
                    handler also implements certain standard keyboard equivalents, such as cmd-` for intra-
                    process window rotation and the universal keyboard access equivalents for interprocess
                    window rotation and document, floating, toolbar, and menubar keyboard focus.
                    
    @param          kEventParamKeyMacCharCodes
                        The character generated by the key that was pressed. The character�s encoding
                        is determined by the current keyboard script.
                        
    @param          kEventParamKeyCode
                        The virtual keycode of the key that was pressed.
                        
    @param          kEventParamKeyModifiers
                        The keyboard modifiers that were down when the key was pressed.
                        
    @param          kEventParamKeyboardType
                        The type of keyboard on which the key was pressed.
*/
/*
 *  kEventClassKeyboard / kEventRawKeyDown
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventRawKeyDown              = 1
};

/*
 *  kEventClassKeyboard / kEventRawKeyRepeat
 *  
 *  Summary:
 *    Sent periodically as a key is held down by the user.
 *  
 *  Discussion:
 *    Usually, you should not handle this event, because doing so may
 *    interfere with input methods; instead, you should handle the
 *    kEventTextInputUnicodeForKeyEvent event, which is sent after
 *    input methods have handled the raw key event, and contains both
 *    Unicode and the original keyboard event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyMacCharCodes (in, typeChar)
 *          The character generated by the key that was pressed. The
 *          character�s encoding is determined by the current keyboard
 *          script.
 *    
 *    --> kEventParamKeyCode (in, typeUInt32)
 *          The virtual keycode of the key that was pressed.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were down when the key was
 *          pressed.
 *    
 *    --> kEventParamKeyboardType (in, typeUInt32)
 *          The type of keyboard on which the key was pressed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventRawKeyRepeat            = 2
};

/*
 *  kEventClassKeyboard / kEventRawKeyUp
 *  
 *  Summary:
 *    A key was released.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyMacCharCodes (in, typeChar)
 *          The character generated by the key that was released. The
 *          character�s encoding is determined by the current keyboard
 *          script.
 *    
 *    --> kEventParamKeyCode (in, typeUInt32)
 *          The virtual keycode of the key that was released.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were down when the key was
 *          released.
 *    
 *    --> kEventParamKeyboardType (in, typeUInt32)
 *          The type of keyboard on which the key was released.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventRawKeyUp                = 3
};

/*
 *  kEventClassKeyboard / kEventRawKeyModifiersChanged
 *  
 *  Summary:
 *    The keyboard modifiers have changed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that are now pressed. This is the
 *          current state of the modifiers, not a delta state; it
 *          includes modifiers that were pressed before the latest
 *          change to modifier state.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventRawKeyModifiersChanged  = 4
};

/*
 *  kEventClassKeyboard / kEventHotKeyPressed
 *  
 *  Summary:
 *    A registered hot key was pressed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeEventHotKeyID)
 *          The ID of the hot key that was pressed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 */
enum {
  kEventHotKeyPressed           = 5
};

/*
 *  kEventClassKeyboard / kEventHotKeyReleased
 *  
 *  Summary:
 *    A registered hot key was released.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeEventHotKeyID)
 *          The ID of the hot key that was released.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 */
enum {
  kEventHotKeyReleased          = 6
};


/*
 *  Summary:
 *    Key modifier change event bits and masks
 *  
 *  Discussion:
 *    From bit 8, cmdKeyBit, to bit 15, rightControlKeyBit, are
 *    compatible with Event Manager modifiers.
 */
enum {

  /*
   * The Num Lock state bit (Mac OS X only).
   */
  kEventKeyModifierNumLockBit   = 16,   /* Num Lock is on? (Mac OS X only)*/

  /*
   * The Fn key state bit (Mac OS X only).
   */
  kEventKeyModifierFnBit        = 17    /* Fn key is down? (Mac OS X only)*/
};

enum {
  kEventKeyModifierNumLockMask  = 1L << kEventKeyModifierNumLockBit,
  kEventKeyModifierFnMask       = 1L << kEventKeyModifierFnBit
};


/*��������������������������������������������������������������������������������������*/
/* Application Events                                                                   */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassApplication quick reference:
    
    %% please check CarbonEventsPriv.i for any events of class kEventClassApplication before
    %% adding values to this list...
    
    kEventAppActivated                      = 1,
    kEventAppDeactivated                    = 2,
    kEventAppQuit                           = 3,
    kEventAppLaunchNotification             = 4,
    kEventAppLaunched                       = 5,
    kEventAppTerminated                     = 6,
    kEventAppFrontSwitched                  = 7,
    
    kEventAppFocusMenuBar                   = 8,
    kEventAppFocusNextDocumentWindow        = 9,
    kEventAppFocusNextFloatingWindow        = 10,
    kEventAppFocusToolbar                   = 11,
    
    kEventAppGetDockTileMenu                = 20,
    
    kEventAppIsEventInInstantMouser         = 104,
    
    kEventAppHidden                         = 107,
    kEventAppShown                          = 108,
    kEventAppSystemUIModeChanged            = 109,
    kEventAppAvailableWindowBoundsChanged   = 110,
    kEventAppActiveWindowChanged            = 111
    
    %% Make sure to avoid overlap with the App Event IDs in CarbonEventsPriv.i!
*/
/*
 *  kEventClassApplication / kEventAppActivated
 *  
 *  Summary:
 *    This application has been activated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          This parameter is present if a click on an application
 *          window was the cause of the app activation; it contains the
 *          window that was clicked. This parameter is not provided if
 *          the application was activated for some other reason.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventAppActivated            = 1
};

/*
 *  kEventClassApplication / kEventAppDeactivated
 *  
 *  Summary:
 *    This application has been deactivated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventAppDeactivated          = 2
};

/*
 *  kEventClassApplication / kEventAppQuit
 *  
 *  Summary:
 *    A request to quit. Sent by QuitApplicationEventLoop to the
 *    application target.
 *  
 *  Discussion:
 *    The RunApplicationEventLoop API installs a default handler on the
 *    application target for this event while the event loop is
 *    running. The handler is removed before RunApplicationEventLoop
 *    returns.
 *    
 *    The event handler installed by RunApplicationEventLoop will cause
 *    RunApplicationEventLoop to exit. Most applications will not need
 *    to handle this event; instead, an application should install an
 *    AppleEvent handler for the kAEQuitApplication event handler if it
 *    needs to check for unsaved documents or do other cleanup before
 *    quitting.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventAppQuit                 = 3
};

/*
 *  kEventClassApplication / kEventAppLaunchNotification
 *  
 *  Summary:
 *    Notification that an asynchronous process launch has completed.
 *  
 *  Discussion:
 *    This event is received when you use LaunchServices to launch a
 *    process asynchronously. Your application only receives this event
 *    for processes that you launch; it is not sent for process
 *    launches from other applications (such as the Finder).
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamProcessID (in, typeProcessSerialNumber)
 *          The ProcessSerialNumber of the process that was launched.
 *    
 *    --> kEventParamLaunchRefCon (in, typeUInt32)
 *          Contains the value in the asyncRefCon field of the LSLaunch
 *          structure that was used to launch the process.
 *    
 *    --> kEventParamLaunchErr (in, typeOSStatus)
 *          A result code indicating success or failure of the launch.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppLaunchNotification   = 4
};

/*
 *  kEventClassApplication / kEventAppLaunched
 *  
 *  Summary:
 *    Another app was launched.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamProcessID (in, typeProcessSerialNumber)
 *          The ProcessSerialNumber of the process that was launched.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventAppLaunched             = 5
};

/*
 *  kEventClassApplication / kEventAppTerminated
 *  
 *  Summary:
 *    Another app terminated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamProcessID (in, typeProcessSerialNumber)
 *          The ProcessSerialNumber of the process that terminated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventAppTerminated           = 6
};

/*
 *  kEventClassApplication / kEventAppFrontSwitched
 *  
 *  Summary:
 *    The front (active) application has changed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamProcessID (in, typeProcessSerialNumber)
 *          The ProcessSerialNumber of the process that became
 *          frontmost.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventAppFrontSwitched        = 7
};

/*
 *  kEventClassApplication / kEventAppHidden
 *  
 *  Summary:
 *    The current application has been hidden.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppHidden               = 107
};

/*
 *  kEventClassApplication / kEventAppShown
 *  
 *  Summary:
 *    The current application has been shown.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppShown                = 108
};

/*
 *  kEventClassApplication / kEventAppSystemUIModeChanged
 *  
 *  Summary:
 *    The system UI mode of the frontmost application has changed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamSystemUIMode (in, typeUInt32)
 *          The new system UI mode. Contains a kUIMode constant from
 *          MacApplication.h.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppSystemUIModeChanged  = 109
};


/*
 */
enum {

  /*
   * Indicates that a device�s available window positioning bounds have
   * changed because of a change in Dock position or size.
   */
  kAvailBoundsChangedForDock    = 1 << 0,

  /*
   * Indicates that a device�s available window positioning bounds have
   * changed because of a change in display configuration.
   */
  kAvailBoundsChangedForDisplay = 1 << 1
};

/*
 *  kEventClassApplication / kEventAppAvailableWindowBoundsChanged
 *  
 *  Summary:
 *    The available window positioning bounds have changed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *    
 *    This event is currently sent in two circumstances: when the Dock
 *    has changed position or size, and when the display configuration
 *    has changed. A separate copy of this event is sent to each
 *    affected GDevice.
 *    
 *    All applications have a default handler installed on the
 *    application target that responds to this event by sending
 *    kEventWindowConstrain events to each window on the specified
 *    device. It is not possible to prevent this handler from running,
 *    since this event is sent to all registered handlers. However,
 *    applications that would like to do their own window layout may
 *    install a handler for this event, and also set the
 *    kWindowNoConstrainAttribute on their windows, which will cause
 *    the basic window handler to ignore kEventWindowConstrain. An
 *    application may also install its own kEventWindowConstrain
 *    handler and selectively return a value other than
 *    eventNotHandledErr, which will prevent the event from being sent
 *    to the basic window handler.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamGDevice (in, typeGDHandle)
 *          The device whose available positioning bounds have changed.
 *    
 *    --> kEventParamReason (in, typeUInt32)
 *          The reasons why the available positioning bounds have
 *          changed. This parameter contains one or more of the
 *          kAvailBoundsChangedFor constants.
 *    
 *    --> kEventParamTransactionID (in, typeUInt32)
 *          An integer which is the same for all instances of this
 *          event that are produced by the same configuration change.
 *          For example, if multiple displays are attached, then this
 *          event is sent once for each display after a display
 *          configuration change; however, the transaction ID parameter
 *          will the same for each event, so a handler for this event
 *          can choose to ignore all but the first event by correlating
 *          the the transaction IDs.
 *    
 *    --> kEventParamPreviousDockRect (in, typeHIRect)
 *          The Dock�s previous bounds, in global coordinates. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events with a
 *          kEventParamReason parameter containing
 *          kAvailBoundsChangedForDock.
 *    
 *    --> kEventParamPreviousDockDevice (in, typeGDHandle)
 *          The GDevice on which the Dock was previously positioned.
 *          This parameter is optional and may not be present in all
 *          instances of this event. It is present in events with a
 *          kEventParamReason parameter containing
 *          kAvailBoundsChangedForDock.
 *    
 *    --> kEventParamCurrentDockRect (in, typeHIRect)
 *          The Dock�s current bounds, in global coordinates. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events with a
 *          kEventParamReason parameter containing
 *          kAvailBoundsChangedForDock.
 *    
 *    --> kEventParamCurrentDockDevice (in, typeGDHandle)
 *          The GDevice on which the Dock is currently positioned. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events with a
 *          kEventParamReason parameter containing
 *          kAvailBoundsChangedForDock.
 *    
 *    --> kEventParamRgnHandle (in, typeQDRgnHandle)
 *          The GrayRgn before the configuration change. This parameter
 *          is optional and may not be present in all instances of this
 *          event. It is present in events with a kEventParamReason
 *          parameter containing kAvailBoundsChangedForDisplay. To get
 *          the GrayRgn after the configuration change, just call the
 *          GetGrayRgn API.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppAvailableWindowBoundsChanged = 110
};

/*
 *  kEventClassApplication / kEventAppActiveWindowChanged
 *  
 *  Summary:
 *    Notification that the active window in the current process has
 *    changed.
 *  
 *  Discussion:
 *    The Window Manager internally tracks the active window, which is
 *    the window that is returned by ActiveNonFloatingWindow. When
 *    SelectWindow is called on a window, that window is made the new
 *    active window. At that time, the Window Manager also posts a
 *    kEventAppActiveWindowChanged event to the main event
 *    queue.
 *    
 *    The ActivateWindow API also causes this event to be
 *    posted.
 *    
 *    If more than one window is activated sequentially before the
 *    event loop is run, only a single kEventAppActiveWindowChanged
 *    event will be left in the event queue, its PreviousActiveWindow
 *    parameter will be the window that was originally active, and its
 *    CurrentActiveWindow parameter will be the window that was finally
 *    active.
 *    
 *    This event only reports changes to the current process. It does
 *    not report activation changes in other processes.
 *    <BR> This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamPreviousWindow (in, typeWindowRef)
 *          The window that was previously active.
 *    
 *    --> kEventParamCurrentWindow (in, typeWindowRef)
 *          The window that is now active.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppActiveWindowChanged  = 111
};

/*
 *  kEventClassApplication / kEventAppGetDockTileMenu
 *  
 *  Summary:
 *    A request for a menu to be displayed by the application�s dock
 *    tile.
 *  
 *  Discussion:
 *    This event has a default handler on the application target. The
 *    default handler will return the menu, if any, that was provided
 *    by the SetApplicationDockTileMenu API. The sender of this event
 *    will release the menu after the Dock has displayed it, so if you
 *    return a permanently allocated MenuRef, you should call
 *    RetainMenu on it before returning from your event handler. For
 *    most applications, it will be easier to use the
 *    SetApplicationDockTileMenu API directly rather than installing a
 *    handler for this event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    <-- kEventParamMenuRef (out, typeMenuRef)
 *          A MenuRef to be displayed in the Dock is returned by the
 *          handler in this parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppGetDockTileMenu      = 20
};

/*
 *  kEventClassApplication / kEventAppFocusMenuBar
 *  
 *  Summary:
 *    The user has requested keyboard focus on the menubar.
 *  
 *  Discussion:
 *    This event is handled automatically by the default application
 *    event handler. A handler for this event should switch the
 *    keyboard focus to the menubar. Applications may install handlers
 *    for this event to track keyboard focus, but should not prevent
 *    the event from being handled by the default application handler.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the user
 *          requested a focus switch.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppFocusMenuBar         = 8
};

/*
 *  kEventClassApplication / kEventAppFocusNextDocumentWindow
 *  
 *  Summary:
 *    The user has requested keyboard focus on a document window.
 *  
 *  Discussion:
 *    This event is handled automatically by the default application
 *    event handler. A handler for this event should cycle to the next
 *    (or previous, if the shift key is down) document window, or if
 *    there are no more windows to activate in the application�s window
 *    list, to the next or previous document window in the next or
 *    previous process. User focus (see SetUserFocusWindow) should be
 *    applied to the new front document window. If something other than
 *    a document window has the focus at the time you receive this
 *    event, the frontmost document window should be given the user
 *    focus instead, and no z-order change should be made.
 *    Additionally, the keyboard focus should be moved to the main
 *    control in the newly focused window if no keyboard focus exists
 *    within the window.
 *    
 *    A handler for this event should never override it entirely; if
 *    necessary, it should only check if the user focus is somewhere
 *    other than a document window, and if so, set the focus on the
 *    active document window. If the focus is already on a document
 *    window, a handler for this event should always return
 *    eventNotHandledErr so that the default handler can rotate to the
 *    next window across all processes.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the user
 *          requested a focus switch.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppFocusNextDocumentWindow = 9
};

/*
 *  kEventClassApplication / kEventAppFocusNextFloatingWindow
 *  
 *  Summary:
 *    The user has requested keyboard focus on a floating window.
 *  
 *  Discussion:
 *    This event is handled automatically by the default application
 *    event handler. A handler for this event should cycle to the next
 *    (or previous, if the shift key is down) floating window in the
 *    application. User focus (see SetUserFocusWindow) should be
 *    applied to the new front floating window. If something other than
 *    a floating window has the focus at the time you receive this
 *    event, the frontmost floating window should be given the user
 *    focus instead, and no z-order change should be made.
 *    Additionally, the keyboard focus should be moved to the main
 *    control in the newly focused window if no keyboard focus exists
 *    within the window. The default handler sends a
 *    kEventCommandProcess event containing
 *    kHICommandRotateFloatingWindowsForward/Backward when it detects
 *    that floating windows should be cycled.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the user
 *          requested a focus switch.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppFocusNextFloatingWindow = 10
};

/*
 *  kEventClassApplication / kEventAppFocusToolbar
 *  
 *  Summary:
 *    The user has requested keyboard focus on the toolbar in the
 *    focused window.
 *  
 *  Discussion:
 *    For windows that use the standard HIToolbar control, this event
 *    is handled automatically by the default application event
 *    handler. A handler for this event should put focus on the first
 *    control in the toolbar in the focused window, if a toolbar is
 *    present.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the user
 *          requested a focus switch.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppFocusToolbar         = 11
};

/*
 *  kEventClassApplication / kEventAppIsEventInInstantMouser
 *  
 *  Summary:
 *    Sent when the system needs to determine if the given event's
 *    global mouse location is over an "instant mousing" area. An
 *    instant mousing area is an area where a mouse down should not
 *    generate ink, but should only be interpreted as a click.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamEventRef (in, typeEventRef)
 *          The Event to check.
 *    
 *    <-- kEventParamIsInInstantMouser (out, typeBoolean)
 *          True if event was in an "instant mousing" area, false
 *          otherwise.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppIsEventInInstantMouser = 104
};


/*��������������������������������������������������������������������������������������*/
/*  Apple Events                                                                        */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassAppleEvent quick reference:

    kEventAppleEvent            = 1
*/
/*
 *  kEventClassAppleEvent / kEventAppleEvent
 *  
 *  Summary:
 *    Sent when a high-level event is received.
 *  
 *  Discussion:
 *    The RunApplicationEventLoop API installs a default handler on the
 *    application target for this event while the event loop is
 *    running. The handler is removed before RunApplicationEventLoop
 *    returns.
 *    
 *    The handler installed by RunApplicationEventLoop will call
 *    AEProcessAppleEvent.
 *    
 *    It is not possible to get the AppleEvent itself from this Carbon
 *    event; only its event class and kind are available. To inspect
 *    the AppleEvent parameters, the event must actually be dispatched
 *    using AEProcessAppleEvent.
 *    
 *    If you need to handle this Carbon event yourself, the necessary
 *    steps are: (1) remove the Carbon event from the queue. The
 *    AppleEvent requires some special preparation before it can be
 *    processed, and this preparation only occurs when the event is
 *    dequeued. (2) Use ConvertEventRefToEventRecord to get an
 *    EventRecord from the Carbon event. (3) Call AEProcessAppleEvent
 *    on the EventRecord.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAEEventClass (in, typeType)
 *          The event class of the Apple event.
 *    
 *    --> kEventParamAEEventID (in, typeType)
 *          The event ID of the Apple event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventAppleEvent              = 1
};

/*��������������������������������������������������������������������������������������*/
/*  Window Events                                                                       */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassWindow quick reference:
    
    -- window refresh events --
    
    kEventWindowUpdate                  = 1,
    kEventWindowDrawContent             = 2,
    
    -- window activation events --
    
    kEventWindowActivated               = 5,
    kEventWindowDeactivated             = 6,
    kEventWindowGetClickActivation      = 7,
    
    -- window state change events --
    
    kEventWindowShowing                 = 22,
    kEventWindowHiding                  = 23,
    kEventWindowShown                   = 24,
    kEventWindowHidden                  = 25,
    kEventWindowCollapsing              = 86,
    kEventWindowCollapsed               = 67,
    kEventWindowExpanding               = 87,
    kEventWindowExpanded                = 70,
    kEventWindowZoomed                  = 76,
    kEventWindowBoundsChanging          = 26,
    kEventWindowBoundsChanged           = 27,
    kEventWindowResizeStarted           = 28,
    kEventWindowResizeCompleted         = 29,
    kEventWindowDragStarted             = 30,
    kEventWindowDragCompleted           = 31,
    kEventWindowClosed                  = 73,
    kEventWindowTransitionStarted       = 88,
    kEventWindowTransitionCompleted     = 89,
    
    -- window click events --
    
    kEventWindowClickDragRgn            = 32,
    kEventWindowClickResizeRgn          = 33,
    kEventWindowClickCollapseRgn        = 34,
    kEventWindowClickCloseRgn           = 35,
    kEventWindowClickZoomRgn            = 36,
    kEventWindowClickContentRgn         = 37,
    kEventWindowClickProxyIconRgn       = 38,
    kEventWindowClickToolbarButtonRgn   = 41,
    kEventWindowClickStructureRgn       = 42,

    -- window cursor change events --

    kEventWindowCursorChange            = 40,

    -- window action events --
    
    kEventWindowCollapse                = 66,
%%  kEventWindowCollapsed               = 67,
    kEventWindowCollapseAll             = 68,
    kEventWindowExpand                  = 69,
%%  kEventWindowExpanded                = 70,
    kEventWindowExpandAll               = 71,
    kEventWindowClose                   = 72,
%%  kEventWindowClosed                  = 73,
    kEventWindowCloseAll                = 74,
    kEventWindowZoom                    = 75,
%%  kEventWindowZoomed                  = 76,
    kEventWindowZoomAll                 = 77,
    kEventWindowContextualMenuSelect    = 78,
    kEventWindowPathSelect              = 79,
    kEventWindowGetIdealSize            = 80,
    kEventWindowGetMinimumSize          = 81,
    kEventWindowGetMaximumSize          = 82,
    kEventWindowConstrain               = 83,
    kEventWindowHandleContentClick      = 85,
%%  kEventWindowCollapsing              = 86,
%%  kEventWindowExpanding               = 87,
%%  kEventWindowTransitionStarted       = 88,
%%  kEventWindowTransitionCompleted     = 89,
    kEventWindowGetDockTileMenu         = 90,
%%  kEventWindowHandleActivate          = 91,
%%  kEventWindowHandleDeactivate        = 92,
    kEventWindowProxyBeginDrag          = 128,
    kEventWindowProxyEndDrag            = 129,
    kEventWindowToolbarSwitchMode       = 150,
    
    -- window focus events --
    
    kEventWindowFocusAcquired           = 200,
    kEventWindowFocusRelinquish         = 201,
    kEventWindowFocusContent            = 202,
    kEventWindowFocusToolbar            = 203,
    
    -- drawer events --
    
    kEventWindowDrawerOpening           = 220,
    kEventWindowDrawerOpened            = 221,
    kEventWindowDrawerClosing           = 222,
    kEventWindowDrawerClosed            = 223,
    
    -- window definition events --
    
    kEventWindowDrawFrame               = 1000,
    kEventWindowDrawPart                = 1001,
    kEventWindowGetRegion               = 1002,
    kEventWindowHitTest                 = 1003,
    kEventWindowInit                    = 1004,
    kEventWindowDispose                 = 1005,
    kEventWindowDragHilite              = 1006,
    kEventWindowModified                = 1007,
    kEventWindowSetupProxyDragImage     = 1008,
    kEventWindowStateChanged            = 1009,
    kEventWindowMeasureTitle            = 1010,
    kEventWindowDrawGrowBox             = 1011,
    kEventWindowGetGrowImageRegion      = 1012,
    kEventWindowPaint                   = 1013
    
    On window handlers:
    
    All windows have a handler installed called the �basic window handler.� This handler provides certain
    basic services for all windows; for example, it handles clicks in the collapse and toolbar buttons,
    since these buttons were handled automatically for WaitNextEvent-based applications in the classic
    Mac OS toolbox, and so are still be handled automatically in Carbon by the basic window handler. The
    basic window handler also implements the HICommands that are sent by the standard window menu to minimize,
    maximize, or zoom a window (kHICommandMinimize/Maximize/ZoomWindow), and the window-class events that are
    generated by those commands (kEventWindowCollapse/Expand/Zoom).
    
    When the window is created with, or has added, the kWindowStandardHandlerAttribute, the window also has
    installed the �standard window handler.� The standard handler provides much more advanced behavior than
    the basic window handler; a window using the standard handler generally requires no other extra handlers
    to move, resize, redraw, or track user clicks in controls. Applications will generally add extra handlers
    to respond to command events generated by controls in the window.
*/
/*
 *  kEventClassWindow / kEventWindowUpdate
 *  
 *  Summary:
 *    The lowest-level window update event.
 *  
 *  Discussion:
 *    Posted to the event queue for any window that needs updating
 *    regardless of whether the window has the standard handler
 *    installed. The standard window handler responds to this event by
 *    calling BeginUpdate and SetPort, sending a
 *    kEventWindowDrawContent event, and calling EndUpdate. An
 *    application handler for this event that does not call through to
 *    the standard handler must itself call BeginUpdate and
 *    EndUpdate.
 *    
 *    If all handlers for this event return eventNotHandledErr, and the
 *    application is calling WaitNextEvent or GetNextEvent, then a
 *    kEventWindowUpdate event will be returned as a classic updateEvt.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that requires updating.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowUpdate            = 1
};

/*
 *  kEventClassWindow / kEventWindowDrawContent
 *  
 *  Summary:
 *    A request to update a window�s content.
 *  
 *  Discussion:
 *    This event is sent by the standard window handler when it
 *    receives a kEventWindowUpdate event. BeginUpdate, SetPort, and
 *    EndUpdate are called for you; your handler only needs to draw
 *    into the current port. 
 *    
 *    Regardless of whether the window uses the standard window event
 *    handler, you will also receive this event right before a window
 *    is made visible, to allow you to draw the window�s initial
 *    contents; you can implement this event to avoid flicker when the
 *    window is first shown.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that requires updating.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDrawContent       = 2
};

/*
 *  kEventClassWindow / kEventWindowActivated
 *  
 *  Summary:
 *    Notification that a window has been activated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    to any window that is activated, regardless of whether the window
 *    has the standard handler installed. The standard window event
 *    handler responds to this event by calling ActivateControl on the
 *    window�s root control.
 *    
 *    If all handlers for this event return eventNotHandledErr, then
 *    the Window Manager posts the event to the event queue, where it
 *    will later be returned from WaitNextEvent as a classic
 *    activateEvt. If any handler returns an error code other than
 *    eventNotHandledErr, then the event will not be posted to the
 *    event queue.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that is now active.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowActivated         = 5
};

/*
 *  kEventClassWindow / kEventWindowDeactivated
 *  
 *  Summary:
 *    Notification that a window has been deactivated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    to any window that is deactivated, regardless of whether the
 *    window has the standard handler installed. The standard window
 *    event handler responds to this event by calling DeactivateControl
 *    on the window�s root control.
 *    
 *    If all handlers for this event return eventNotHandledErr, then
 *    the Window Manager posts the event to the event queue, where it
 *    will later be returned from WaitNextEvent as a classic
 *    activateEvt. If any handler returns an error code other than
 *    eventNotHandledErr, then the event will not be posted to the
 *    event queue.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that is now inactive.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDeactivated       = 6
};

/*
 *  kEventClassWindow / kEventWindowGetClickActivation
 *  
 *  Summary:
 *    Sent when a click occurs in a inactive window. Allows the window
 *    to determine whether the window should be activated and whether
 *    the click should be handled.
 *  
 *  Discussion:
 *    This event is sent to a window when a click occurs in the window
 *    while it is inactive. A handler for this event can determine
 *    whether the window is activated and whether the click is handled
 *    or ignored by setting the kEventParamClickActivation parameter to
 *    one of the ClickActivationResult constants in Controls.h.
 *    
 *    
 *    For windows which use the standard window event handler, this
 *    event is sent regardless of whether the window�s process is
 *    active or inactive; for windows that do not use the standard
 *    window event handler, this event is only sent to windows in
 *    inactive processes. This event is never sent to
 *    kUtilityWindowClass windows, since they are never inactive.
 *    
 *    
 *    The default behavior is to bring the window forward and ignore
 *    the click (in other words, return kActivateAndIgnoreClick),
 *    unless the click falls on the window widgets in the window
 *    structure, in which case kDoNotActivateAndHandleClick is usually
 *    returned. You have the option of overriding the behavior to
 *    support click-thru or select-and-click.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The location of the click, in global coordinates.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the mouse was
 *          clicked.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The window part that was clicked. Available in Mac OS X
 *          10.3 and later.
 *    
 *    --> kEventParamWindowDefPart (in, typeWindowDefPartCode)
 *          The window part that was clicked. This is really a window
 *          part code, not a window def part code, despite the
 *          parameter name; this parameter is available in all versions
 *          of Mac OS X and CarbonLib 1.1 and later, but use
 *          kEventParamWindowPartCode when available instead for
 *          clarity.
 *    
 *    --> kEventParamControlRef (in, typeControlRef)
 *          The control that was clicked. Only present if the click was
 *          on a control.
 *    
 *    <-- kEventParamClickActivation (out, typeClickActivationResult)
 *          On exit, indicates how the click should be handled. Should
 *          be set a ClickActivationResult constant from Controls.h.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetClickActivation = 7
};


/*
 *  Summary:
 *    Window bounds change event attributes
 *  
 *  Discussion:
 *    When the toolbox sends out a kEventWindowBoundsChanging or
 *    kEventWindowBoundsChanged event, it also sends along a parameter
 *    containing attributes of the event. These attributes can be used
 *    to determine what aspect of the window changed (origin, size, or
 *    both), and whether or not some user action is driving the change
 *    (drag or resize).
 */
enum {

  /*
   * The bounds is changing because the user is dragging the window
   * around.
   */
  kWindowBoundsChangeUserDrag   = (1 << 0),

  /*
   * The bounds is changing because the user is resizing the window.
   */
  kWindowBoundsChangeUserResize = (1 << 1),

  /*
   * The dimensions of the window (width and height) are changing.
   */
  kWindowBoundsChangeSizeChanged = (1 << 2),

  /*
   * The top left corner (origin) is changing.
   */
  kWindowBoundsChangeOriginChanged = (1 << 3),

  /*
   * The bounds is changing because ZoomWindow or ZoomWindowIdeal was
   * called. Note that this flag does not imply any user interaction;
   * if the application calls ZoomWindow itself without user request,
   * this flag will still be set. Available in Mac OS X 10.2 and
   * CarbonLib 1.6, and later.
   */
  kWindowBoundsChangeZoom       = (1 << 4)
};

/*
 *  kEventClassWindow / kEventWindowShowing
 *  
 *  Summary:
 *    Notification that a window is being shown.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being shown.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowShowing           = 22
};

/*
 *  kEventClassWindow / kEventWindowHiding
 *  
 *  Summary:
 *    Notification that a window is being hidden.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being hidden.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowHiding            = 23
};

/*
 *  kEventClassWindow / kEventWindowShown
 *  
 *  Summary:
 *    Notification that a window has been shown.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was shown.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowShown             = 24
};

/*
 *  kEventClassWindow / kEventWindowHidden
 *  
 *  Summary:
 *    Notification that a window has been hidden.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. Prior to
 *    Mac OS X 10.2 and CarbonLib 1.6, kEventWindowClosed and
 *    kEventWindowHidden were sent in that order by the Window Manager
 *    to a window being destroyed. This was problematic if you had a
 *    Hidden handler which used data that was destroyed by the Closed
 *    handler. The Window Manager in Mac OS X 10.2 and CarbonLib 1.6
 *    and later now sends these events in the reverse order:
 *    kEventWindowHidden first, followed by kEventWindowClosed. The
 *    last event sent to a window remains kEventWindowDispose.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was hidden.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowHidden            = 25
};

/*
 *  kEventClassWindow / kEventWindowCollapsing
 *  
 *  Summary:
 *    Notification that a window is about to collapse.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being collapsed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 */
enum {
  kEventWindowCollapsing        = 86
};

/*
 *  kEventClassWindow / kEventWindowCollapsed
 *  
 *  Summary:
 *    Notification that a window has successfully collapsed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was collapsed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowCollapsed         = 67
};

/*
 *  kEventClassWindow / kEventWindowExpanding
 *  
 *  Summary:
 *    Notification that a window is about to expand.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being expanded.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 */
enum {
  kEventWindowExpanding         = 87
};

/*
 *  kEventClassWindow / kEventWindowExpanded
 *  
 *  Summary:
 *    Notification that a window has successfully expanded.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was expanded.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowExpanded          = 70
};

/*
 *  kEventClassWindow / kEventWindowZoomed
 *  
 *  Summary:
 *    Notification that a window has been successfully zoomed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. In
 *    CarbonLib 1.1 through CarbonLib 1.4, and Mac OS X 10.0 and 10.1,
 *    this event is only sent by the standard window event handler
 *    after handling kEventWindowZoom; starting with CarbonLib 1.5 and
 *    Mac OS X 10.2, this event is sent by ZoomWindow and
 *    ZoomWindowIdeal.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was zoomed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowZoomed            = 76
};

/*
 *  kEventClassWindow / kEventWindowBoundsChanging
 *  
 *  Summary:
 *    Notification that a window�s bounds are about to be changed.
 *  
 *  Discussion:
 *    Sent during DragWindow or ResizeWindow, before the window is
 *    actually moved or resized, and also during programmatic
 *    bounds-changing APIs such as SetWindowBounds and ZoomWindow. An
 *    event handler may alter the kEventParamCurrentBounds parameter in
 *    the event to change the eventual location of the window. You may
 *    change the size, origin, or both of the window�s bounds. Do not,
 *    however, call SizeWindow or SetWindowBounds yourself from inside
 *    a handler for this event. 
 *    
 *    In Mac OS X 10.1 and later, kEventWindowBoundsChanging is sent
 *    before all changes to a window�s bounds, regardless of whether
 *    the change is initiated by the user or by a direct call to a
 *    Window Manager API. Applications may intercept the event and
 *    modify the bounds. When the event is sent because of a direct
 *    call to the Window Manager, the
 *    kWindowBoundsChangeUserDrag/Resize attribute bits will not be set.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being shown.
 *    
 *    --> kEventParamAttributes (in, typeUInt32)
 *          The bounds-changing attributes indicating whether the
 *          window is being resized, moved, or both.
 *    
 *    --> kEventParamOriginalBounds (in, typeQDRectangle)
 *          The window�s original bounds before the window resize or
 *          drag began.
 *    
 *    --> kEventParamPreviousBounds (in, typeQDRectangle)
 *          The window�s bounds before the current bounds change.
 *    
 *    <-> kEventParamCurrentBounds (in/out, typeQDRectangle)
 *          On entry, the window�s proposed new bounds; on exit, the
 *          bounds that are desired by the event handler.
 *  
 *  Result:
 *    Return noErr to indicate that the Window Manager should use the
 *    kEventParamCurrentBounds parameter as the window�s new bounds.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowBoundsChanging    = 26
};

/*
 *  kEventClassWindow / kEventWindowBoundsChanged
 *  
 *  Summary:
 *    Notification that a window�s bounds have been changed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. Do not call
 *    SizeWindow or SetWindowBounds from inside a handler for this
 *    event; if you need to enforce a certain window bounds, install a
 *    kEventWindowBoundsChanging handler instead.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose bounds were changed.
 *    
 *    --> kEventParamAttributes (in, typeUInt32)
 *          The bounds-changing attributes indicating whether the
 *          window was resized, moved, or both.
 *    
 *    --> kEventParamOriginalBounds (in, typeQDRectangle)
 *          The window�s original bounds before the window resize or
 *          drag began.
 *    
 *    --> kEventParamPreviousBounds (in, typeQDRectangle)
 *          The window�s bounds before the current bounds change.
 *    
 *    --> kEventParamCurrentBounds (in, typeQDRectangle)
 *          The window�s new bounds.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowBoundsChanged     = 27
};

/*
 *  kEventClassWindow / kEventWindowResizeStarted
 *  
 *  Summary:
 *    Notification that the user has just started to resize a window.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being resized.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowResizeStarted     = 28
};

/*
 *  kEventClassWindow / kEventWindowResizeCompleted
 *  
 *  Summary:
 *    Notification that the user has just finished resizing a window.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was resized.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowResizeCompleted   = 29
};

/*
 *  kEventClassWindow / kEventWindowDragStarted
 *  
 *  Summary:
 *    Notification that the user has just started to drag a window.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being dragged.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDragStarted       = 30
};

/*
 *  kEventClassWindow / kEventWindowDragCompleted
 *  
 *  Summary:
 *    Notification that the user has just finished dragging a window.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was dragged.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDragCompleted     = 31
};

/*
 *  kEventClassWindow / kEventWindowClosed
 *  
 *  Summary:
 *    Notification that a window is being destroyed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. Prior to
 *    Mac OS X 10.2 and CarbonLib 1.6, kEventWindowClosed and
 *    kEventWindowHidden were sent in that order by the Window Manager
 *    to a window being destroyed. This was problematic if you had a
 *    Hidden handler which used data that was destroyed by the Closed
 *    handler. The Window Manager in Mac OS X 10.2 and CarbonLib 1.6
 *    and later now sends these events in the reverse order:
 *    kEventWindowHidden first, followed by kEventWindowClosed. The
 *    last event sent to a window remains kEventWindowDispose.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being destroyed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClosed            = 73
};

/*
 *  kEventClassWindow / kEventWindowTransitionStarted
 *  
 *  Summary:
 *    Notification that a window transition has started.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    by the TransitionWindow, TransitionWindowAndParent, and
 *    TransitionWindowWithOptions APIs just before the first frame of
 *    the transition animation.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that will be transitioning.
 *    
 *    --> kEventParamUserData (in, typeVoidPtr)
 *          The user data that was specified in the
 *          TransitionWindowOptions.userData field. If no user data was
 *          specified, this parameter will still be present, but its
 *          value will be NULL.
 *    
 *    --> kEventParamWindowTransitionAction (in, typeWindowTransitionAction)
 *          The transition action that is starting.
 *    
 *    --> kEventParamWindowTransitionEffect (in, typeWindowTransitionEffect)
 *          The transition effect that is starting.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowTransitionStarted = 88
};

/*
 *  kEventClassWindow / kEventWindowTransitionCompleted
 *  
 *  Summary:
 *    Notification that a window transition has completed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    by the TransitionWindow, TransitionWindowAndParent, and
 *    TransitionWindowWithOptions APIs just after the last frame of the
 *    transition animation.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was transitioning.
 *    
 *    --> kEventParamUserData (in, typeVoidPtr)
 *          The user data that was specified in the
 *          TransitionWindowOptions.userData field. If no user data was
 *          specified, this parameter will still be present, but its
 *          value will be NULL.
 *    
 *    --> kEventParamWindowTransitionAction (in, typeWindowTransitionAction)
 *          The transition action that has completed.
 *    
 *    --> kEventParamWindowTransitionEffect (in, typeWindowTransitionEffect)
 *          The transition effect that has completed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowTransitionCompleted = 89
};

/*
 *  kEventClassWindow / kEventWindowClickDragRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the drag region.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by checking if
 *    the click is a window path-select click; if so, it sends
 *    kEventWindowPathSelect to allow customization of the path-select
 *    menu, and then calls WindowPathSelect. If the click is not a
 *    path-select click, the standard window handler calls DragWindow.
 *    Note that this event is not sent for composited windows; the
 *    window frame view handles the mouse-down event directly. To
 *    intercept a drag region click in a composited window, install a
 *    kEventControlClick handler on the window�s root view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickDragRgn      = 32
};

/*
 *  kEventClassWindow / kEventWindowClickResizeRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the resize area.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by calling
 *    ResizeWindow. Note that this event is not sent for composited
 *    windows; the window resize view handles the mouse-down event
 *    directly. To intercept a resize region click in a composited
 *    window, install a kEventControlClick handler on the window�s
 *    resize view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickResizeRgn    = 33
};

/*
 *  kEventClassWindow / kEventWindowClickCollapseRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the collapse button.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by tracking the click in the collapse button. If the mouse is
 *    released while still in the button, the basic window handler
 *    generates one of the kEventWindowCollapse,
 *    kEventWindowCollapseAll, kEventWindowExpand, or
 *    kEventWindowExpandAll events, depending on the window�s original
 *    collapse state and whether the option key was pressed. Note that
 *    this event is not sent for composited windows; the window
 *    collapse button view handles the mouse-down event directly. To
 *    intercept a collapse region click in a composited window, install
 *    a kEventControlClick handler on the window�s collapse button view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickCollapseRgn  = 34
};

/*
 *  kEventClassWindow / kEventWindowClickCloseRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the close button.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by tracking
 *    the click in the close button. If the mouse is released while
 *    still in the button, the standard window handler generates one of
 *    the kEventWindowClose or kEventWindowCloseAll events, depending
 *    on whether the option key was pressed. Note that this event is
 *    not sent for composited windows; the window close button view
 *    handles the mouse-down event directly. To intercept a close
 *    region click in a composited window, install a kEventControlClick
 *    handler on the window�s close button view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickCloseRgn     = 35
};

/*
 *  kEventClassWindow / kEventWindowClickZoomRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the zoom button.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by tracking
 *    the click in the zoom button. If the mouse is released while
 *    still in the button, the standard window handler generates one of
 *    the kEventWindowZoom or kEventWindowZoomAll events, depending on
 *    whether the option key was pressed. Note that this event is not
 *    sent for composited windows; the window zoom button view handles
 *    the mouse-down event directly. To intercept a zoom region click
 *    in a composited window, install a kEventControlClick handler on
 *    the window�s zoom region view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickZoomRgn      = 36
};

/*
 *  kEventClassWindow / kEventWindowClickContentRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the content region.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by checking if
 *    the click should display a contextual menu; if so, and if the
 *    click was in an enabled control, it calls
 *    HandleControlContextualMenuSelect. If the click was not in a
 *    control, or if the control does not display a contextual menu,
 *    the standard window handler sends a
 *    kEventWindowContextualMenuSelect event to the window. 
 *    
 *    If the click was not a contextual menu click, then the standard
 *    window handler uses HIViewGetViewForMouseEvent to determine the
 *    HIView containing the click. If a view is found, the standard
 *    window handler calls HIViewClick, which will generate a
 *    kEventControlClick event. 
 *    
 *    If no view is found that contains the click, or if the containing
 *    view does not handle the click, then the standard window handler
 *    sends a kEventWindowHandleContentClick event. 
 *    
 *    Note that this event is not sent for composited windows; all
 *    mouse-downs in a composited window are handled by a view, and
 *    there is no �content region� in a composited window. To intercept
 *    a content region click in a composited window, install a
 *    kEventControlClick handler on the window�s content view, or
 *    provide your own HIView subclass.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickContentRgn   = 37
};

/*
 *  kEventClassWindow / kEventWindowClickProxyIconRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the proxy icon.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by handling
 *    proxy icon dragging. It first sends a kEventWindowProxyBeginDrag
 *    event to allow customization of the DragRef, and then calls
 *    TrackWindowProxyFromExistingDrag. Finally, the standard window
 *    handler sends a kEventWindowProxyEndDrag event. Note that this
 *    event is not sent for composited windows; the window title view
 *    handles the mouse-down event directly. To intercept a proxy icon
 *    region click in a composited window, install a kEventControlClick
 *    handler on the window�s title view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClickProxyIconRgn = 38
};

/*
 *  kEventClassWindow / kEventWindowClickToolbarButtonRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in the toolbar button.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by tracking the click in the toolbar button. If the mouse is
 *    released while still in the button, the basic window handler
 *    sends a kEventWindowToolbarSwitchMode event. Note that this event
 *    is not sent for composited windows; the window toolbar button
 *    view handles the mouse-down event directly. To intercept a
 *    toolbar button region click in a composited window, install a
 *    kEventControlClick handler on the window�s toolbar button view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowClickToolbarButtonRgn = 41
};

/*
 *  kEventClassWindow / kEventWindowClickStructureRgn
 *  
 *  Summary:
 *    Sent when the mouse is clicked in some part of the window
 *    structure other than the window widgets, drag region, or resize
 *    region.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by calling
 *    HIViewGetViewForMouseEvent to determine the HIView containing the
 *    click. If a view is found, the standard window handler calls
 *    HIViewClick, which will generate a kEventControlClick event. Note
 *    that this event is not sent for composited windows; all parts of
 *    the window frame are built from views, and the mouse will never
 *    land outside of a view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowClickStructureRgn = 42
};


/*
 *  kEventClassWindow / kEventWindowCursorChange
 *  
 *  Summary:
 *    Sent when the mouse is moving over the content region of a window.
 *  
 *  Discussion:
 *    This event is used to manage ownership of the cursor. You should
 *    only change the cursor if you receive this event; otherwise,
 *    someone else needed to adjust the cursor and handled the event
 *    (e.g., a TSM Input Method when the mouse is over an inline input
 *    region). This event is only sent to the window itself; it is not
 *    propagated to controls in the window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window under the mouse.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location in global coordinates.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The current keyboard modifiers.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventWindowCursorChange      = 40
};

/*
 *  kEventClassWindow / kEventWindowCollapse
 *  
 *  Summary:
 *    A request to collapse a window.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by calling CollapseWindow, passing true for the collapse
 *    parameter, which sends kEventWindowCollapsing and
 *    kEventWindowCollapsed events. This event is generated by the
 *    standard window handler in response to a click in a window�s
 *    collapse button. It is also generated by the basic window handler
 *    when Minimize or Collapse is selected from the standard window
 *    menu.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should collapse.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowCollapse          = 66
};

/*
 *  kEventClassWindow / kEventWindowCollapseAll
 *  
 *  Summary:
 *    A request to collapse all windows.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by calling CollapseAllWindows, passing true for the collapse
 *    parameter. CollapseAllWindows simply calls CollapseWindow on each
 *    window; it does not send a kEventWindowCollapse to each window.
 *    This event is generated by the standard window handler in
 *    response to an option-click in a window�s collapse button. It is
 *    also generated by the basic window handler when Minimize All or
 *    Collapse All is selected from the standard window menu.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose collapse button was clicked.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowCollapseAll       = 68
};

/*
 *  kEventClassWindow / kEventWindowExpand
 *  
 *  Summary:
 *    A request to expand a window.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by calling CollapseWindow, passing false for the collapse
 *    parameter, which sends kEventWindowExpanding and
 *    kEventWindowExpanded events. This event is generated by the
 *    standard window handler in responds to a click in a collapsed
 *    window�s collapse button. It is also generated by the basic
 *    window handler when Uncollapse is selected from from the standard
 *    window menu provided by CarbonLib. 
 *    
 *    Note that you will not receive this event on Mac OS X before a
 *    window is expanded from the Dock, since minimized windows in the
 *    dock don�t uses collapse buttons to unminimize. However, you will
 *    still receive kEventWindowExpanding and kEventWindowExpanded in
 *    that case. You will receive this event on Mac OS 8 and 9 using
 *    CarbonLib since collapsed windows do have a collapse button there.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should expand.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowExpand            = 69
};

/*
 *  kEventClassWindow / kEventWindowExpandAll
 *  
 *  Summary:
 *    A request to expand all windows.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by calling CollapseAllWindows, passing false for the collapse
 *    parameter. On Mac OS X 10.3 and later, CollapseAllWindows sends a
 *    kEventWindowExpand event to each window; on earlier version of
 *    Mac OS X, and in CarbonLib, it simply calls CollapseWindow on
 *    each window. This event is generated by the standard window
 *    handler in response to an option-click in a window�s collapse
 *    button. It is also generated by the basic window handler when
 *    Uncollapse All is selected from the standard window menu provided
 *    by CarbonLib.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose collapse button was clicked.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowExpandAll         = 71
};

/*
 *  kEventClassWindow / kEventWindowClose
 *  
 *  Summary:
 *    A request to close a window.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by calling
 *    DisposeWindow. This event is generated by the standard window
 *    handler in response to a click in a window�s close button. On Mac
 *    OS X 10.3 and later, it is also generated when the Close menu
 *    item is selected from the Dock menu of a minimized window.
 *    
 *    
 *    Your application would typically intercept this event to check if
 *    the window�s document is dirty, and display a Save Changes alert
 *    if so. 
 *    
 *    In order to support closing minimized windows from the Dock, your
 *    application must provide an event hander for this event,
 *    installed on the window�s event target, even if your application
 *    does not use the standard window handler or otherwise use Carbon
 *    events.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should close.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowClose             = 72
};

/*
 *  kEventClassWindow / kEventWindowCloseAll
 *  
 *  Summary:
 *    A request to close all windows.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by sending a
 *    kEventWindowClose event to all visible windows of the same window
 *    class as the target window. This event is generated by the
 *    standard window handler in response to an option-click in a
 *    window�s close button.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose close button was clicked.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowCloseAll          = 74
};

/*
 *  kEventClassWindow / kEventWindowZoom
 *  
 *  Summary:
 *    A request to zoom a window.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by sending a kEventWindowIdealSize event to get the window�s
 *    ideal size, and then calling ZoomWindowIdeal. This event is
 *    generated by the standard window handler in response to a click
 *    in the window�s zoom button. It is also generated by the basic
 *    window handler when Zoom is selected from the standard window
 *    menu.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should zoom.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code (inZoomIn or inZoomOut) that should be passed
 *          to ZoomWindow or ZoomWindowIdeal. This parameter is
 *          optional and may not be present in all instances of this
 *          event. If present, the event handler should determine if
 *          the window is already in the requested state (i.e., if the
 *          part code is inZoomOut and the window is already in the
 *          standard state), and if so, the event handler should not
 *          zoom the window at all. If this parameter is not present,
 *          the event handler should zoom the window based on its
 *          current state. This parameter is available in Mac OS X 10.3
 *          and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowZoom              = 75
};

/*
 *  kEventClassWindow / kEventWindowZoomAll
 *  
 *  Summary:
 *    A request to zoom all windows.
 *  
 *  Discussion:
 *    The standard window handler responds to this event by zooming all
 *    visible windows of the same window class as the target window. On
 *    Mac OS X 10.3 and later, it causes each window to zoom by sending
 *    a kEventWindowZoom event to the window; on earlier versions of
 *    Mac OS X, and in CarbonLib, it simply calls ZoomWindowIdeal on
 *    each window. This event is generated by the standard window
 *    handler in response to an option-click on a window�s zoom button.
 *    
 *    
 *    After zooming all of the windows, if the windows are being zoomed
 *    out and the window class of the target window is
 *    kDocumentWindowClass, the windows are cascaded by sending a
 *    kEventCommandProcess event with the kHICommandArrangeInFront
 *    command to the target window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose zoom button was clicked.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowZoomAll           = 77
};

/*
 *  kEventClassWindow / kEventWindowContextualMenuSelect
 *  
 *  Summary:
 *    A request to display a contextual menu.
 *  
 *  Discussion:
 *    This event is generated by the standard window handler in
 *    response to a contextual menu click in the content area of a
 *    window. In response to such an event, the standard window handler
 *    first checks if the click is on a control, and if so, calls
 *    HandleControlContextualMenuClick. If the click was not on a
 *    control, or if HandleControlContextualMenuClick returned that it
 *    did not handle the click, then the standard window handler sends
 *    kEventWindowContextualMenuSelect to allow the application to
 *    provide its own customized contextual menu. The standard window
 *    handler does not respond to this event itself.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should collapse.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowContextualMenuSelect = 78
};

/*
 *  kEventClassWindow / kEventWindowPathSelect
 *  
 *  Summary:
 *    Allows customization of the path-selection popup menu displayed
 *    over a window�s title.
 *  
 *  Discussion:
 *    This event is generated by the standard window handler in
 *    response to a click in a window�s drag region. In response to
 *    such an event, the standard window handler first calls
 *    IsWindowPathSelectEvent to determine if the click should cause a
 *    path-selection popup menu to be displayed. If so, and if the
 *    window is also hilited and has a proxy icon, the standard window
 *    handler sends a kEventWindowPathSelect event to the window.
 *    
 *    
 *    A handler for this event should put a MenuRef into the event and
 *    return noErr to cause the menu to be displayed as the path
 *    selection popup menu. The menu will not be released by the
 *    standard window handler.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that will display the path-selection popup menu.
 *    
 *    <-- kEventParamMenuRef (out, typeMenuRef)
 *          On exit, contains the menu that should be displayed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowPathSelect        = 79
};

/*
 *  kEventClassWindow / kEventWindowGetIdealSize
 *  
 *  Summary:
 *    A request for the ideal size of a window�s content region, for
 *    use during window zooming.
 *  
 *  Discussion:
 *    This event is generated by the basic window handler in response
 *    to kEventWindowZoom. The basic window handler sends this event to
 *    the window to get the window�s ideal size, and passes the
 *    resulting size to ZoomWindowIdeal. 
 *    
 *    This event is not handled by either the basic or standard window
 *    handlers. If no handler responds to this event, the basic window
 *    handler uses an ideal size based on the size of the monitor on
 *    which the window is located.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being zoomed.
 *    
 *    <-- kEventParamDimensions (out, typeQDPoint)
 *          On exit, contains the window�s ideal size.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetIdealSize      = 80
};

/*
 *  kEventClassWindow / kEventWindowGetMinimumSize
 *  
 *  Summary:
 *    A request for the minimum size of a window�s content region, for
 *    use during window resizing.
 *  
 *  Discussion:
 *    This event is generated by the standard window handler before
 *    resizing a window. On Mac OS X 10.2 and later, the basic window
 *    handler responds to this event by calling GetWindowResizeLimits
 *    and returning the minimum size in the event; on earlier versions
 *    of Mac OS X and CarbonLib, this event is not handled by the basic
 *    or standard window handlers. 
 *    
 *    On Mac OS X 10.2 and CarbonLib 1.6 and later, this event is also
 *    generated by ResizeWindow and GrowWindow if the sizeConstraints
 *    parameter is NULL.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being resized.
 *    
 *    <-- kEventParamDimensions (out, typeQDPoint)
 *          On exit, contains the window�s minimum size.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetMinimumSize    = 81
};

/*
 *  kEventClassWindow / kEventWindowGetMaximumSize
 *  
 *  Summary:
 *    A request for the maximum size of a window�s content region, for
 *    use during window resizing.
 *  
 *  Discussion:
 *    This event is generated by the standard window handler before
 *    resizing a window. On Mac OS X 10.2 and later, the basic window
 *    handler responds to this event by calling GetWindowResizeLimits
 *    and returning the maximum size in the event; on earlier versions
 *    of Mac OS X and CarbonLib, this event is not handled by the basic
 *    or standard window handlers. 
 *    
 *    On Mac OS X 10.2 and CarbonLib 1.6 and later, this event is also
 *    generated by ResizeWindow and GrowWindow if the sizeConstraints
 *    parameter is NULL.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being resized.
 *    
 *    <-- kEventParamDimensions (out, typeQDPoint)
 *          On exit, contains the window�s minimum size.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetMaximumSize    = 82
};

/*
 *  kEventClassWindow / kEventWindowConstrain
 *  
 *  Summary:
 *    Requests that a window�s position be constrained to the available
 *    window positioning bounds.
 *  
 *  Discussion:
 *    The basic window handler responds to this event by calling
 *    ConstrainWindowToScreen. This event is generated in two
 *    situations: changes in graphics device configuration, and changes
 *    to Dock size. In either case, a window which was previously
 *    visible onscreen may become obscured or be totally offscreen, and
 *    should be repositioned back inside the available window
 *    positioning bounds. 
 *    
 *    The behavior of the basic window handler may be customized by
 *    modifying the parameters to the event and then allowing the event
 *    to pass through to the basic handler, or an application may
 *    choose to override the event entirely and perform its own window
 *    constraining. 
 *    
 *    Applications may also use the
 *    kEventAppAvailableWindowBoundsChanged event to be notified of
 *    changes to a device�s available bounds.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being constrained.
 *    
 *    --> kEventParamAvailableBounds (in, typeQDRectangle)
 *          The reasons why the window is being constrained. This
 *          parameter contains one or more of the
 *          kAvailBoundsChangedFor constants. This parameter is
 *          available only on Mac OS X 10.3 and later.
 *    
 *    --> kEventParamAttributes (in, typeUInt32)
 *          An integer which is the same for all instances of this
 *          event that are produced by the same configuration change.
 *          For example, if multiple displays are attached, then this
 *          event is sent once for each window on each affected display
 *          after a display configuration change; however, the
 *          transaction ID parameter will the same for each event, so a
 *          handler for this event can correlate events by observing
 *          the transaction ID. This parameter is available only on Mac
 *          OS X 10.3 and later.
 *    
 *    --> kEventParamWindowRegionCode (in, typeWindowRegionCode)
 *          The available window positioning bounds in which the window
 *          should be positioned. Event handlers may change the value
 *          in this parameter and then return eventNotHandledErr to
 *          allow the basic window handler to constrain the window to
 *          the new bounding rect. 
 *          
 *          This parameter is used by the basic window handler on Mac
 *          OS X 10.1 and later; on earlier versions of Mac OS X, the
 *          basic window handler always constrains the window to the
 *          rect returned by GetAvailableWindowPositioningBounds for
 *          the window�s device.
 *    
 *    --> kEventParamRgnHandle (in, typeQDRgnHandle)
 *          Window constraint options that should be passed to
 *          ConstrainWindowToScreen. This parameter is optional and may
 *          not be present in all instances of this event. If present,
 *          this parameter should be formed from constants in the
 *          WindowConstrainOptions enumeration. 
 *          
 *          This parameter is used by the basic window handler on Mac
 *          OS X 10.2 and later; on earlier versions of Mac OS X, or if
 *          this parameter is missing, the basic window handler passes
 *          kWindowConstrainMoveRegardlessOfFit to
 *          ConstrainWindowToScreen in Mac OS X 10.0, and
 *          kWindowConstrainMoveRegardlessOfFit |
 *          kWindowConstrainAllowPartial in Mac OS 10.1 and later.
 *    
 *    --> kEventParamPreviousDockRect (in, typeHIRect)
 *          A WindowRegionCode that should be passed to
 *          ConstrainWindowToScreen. This parameter is optional and may
 *          not be present in all instances of this event. 
 *          
 *          This parameter is used by the basic window handler on Mac
 *          OS X 10.2 and later. On earlier versions of Mac OS X, or if
 *          this parameter is missing, the basic window handler passes
 *          kWindowDragRgn to ConstrainWindowToScreen.
 *    
 *    --> kEventParamPreviousDockDevice (in, typeGDHandle)
 *          The GrayRgn before a graphics device configuration change.
 *          This parameter is optional and may not be present in all
 *          instances of this event. It is present in events generated
 *          on Mac OS X 10.2 and later. 
 *          
 *          An event handler may compare this region with the current
 *          GrayRgn to more intelligently determine whether the window
 *          should be constrained to the current GrayRgn. The basic
 *          window handler in Mac OS X 10.2 will not constrain windows
 *          that were not onscreen before the device configuration
 *          change.
 *    
 *    --> kEventParamCurrentDockRect (in, typeHIRect)
 *          The Dock bounding rect before a Dock size change. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events in events
 *          generated on Mac OS X 10.2 and later.
 *    
 *    --> kEventParamCurrentDockDevice (in, typeGDHandle)
 *          The GDevice on which the Dock was previously positioned.
 *          This parameter is optional and may not be present in all
 *          instances of this event. It is present in events generated
 *          on Mac OS X 10.3 and later.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The Dock bounding rect after a Dock size change. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events in events
 *          generated on Mac OS X 10.2 and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          The GDevice on which the Dock is currently positioned. This
 *          parameter is optional and may not be present in all
 *          instances of this event. It is present in events generated
 *          on Mac OS X 10.3 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventWindowConstrain         = 83
};

/*
 *  kEventClassWindow / kEventWindowProxyBeginDrag
 *  
 *  Summary:
 *    Notification that a proxy icon drag is beginning.
 *  
 *  Discussion:
 *    This event includes the DragRef that will be used for the proxy
 *    icon drag. An application handler may attach its own data to the
 *    DragRef as appropriate for the document content.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose proxy icon is being dragged.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef that will be used for the proxy icon drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowProxyBeginDrag    = 128
};

/*
 *  kEventClassWindow / kEventWindowProxyEndDrag
 *  
 *  Summary:
 *    Notification that a proxy icon drag has ended.
 *  
 *  Discussion:
 *    This event is sent regardless of whether the drag completed
 *    successfully, or was canceled by the user.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose proxy icon is being dragged.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef that was used for the proxy icon drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowProxyEndDrag      = 129
};

/*
 *  kEventClassWindow / kEventWindowHandleContentClick
 *  
 *  Summary:
 *    The mouse has been clicked in the content region of a window, but
 *    the click is not a contextual menu invocation or a click on a
 *    control.
 *  
 *  Discussion:
 *    This event is generated by the standard window handler in
 *    response to a kEventWindowClickContentRgn event. An application
 *    may handle this event by checking if the mouse click was on a
 *    portion of its own user interface, and responding appropriately
 *    if so.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventWindowHandleContentClick = 85
};

/*
 *  kEventClassWindow / kEventWindowGetDockTileMenu
 *  
 *  Summary:
 *    A request for a menu to be displayed by a window�s dock tile.
 *  
 *  Discussion:
 *    The basic window handler responds to this event by returning the
 *    menu, if any, that was provided by the SetWindowDockTileMenu API.
 *    For most applications, it will be easier to use the
 *    SetWindowDockTileMenu API directly rather than installing a
 *    handler for this event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that should collapse.
 *    
 *    <-- kEventParamMenuRef (out, typeMenuRef)
 *          On exit, contains the menu that should be displayed for the
 *          window�s Dock tile. The sender of this event will release
 *          the menu after the Dock has displayed it, so if you return
 *          a permanently allocated MenuRef, you should call RetainMenu
 *          on it before returning from your event handler.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowGetDockTileMenu   = 90
};

/*
 *  kEventClassWindow / kEventWindowToolbarSwitchMode
 *  
 *  Summary:
 *    A request that the window�s toolbar change its display mode.
 *  
 *  Discussion:
 *    For all windows, the basic window handler responds to this event
 *    by changing the display mode of the window�s HIToolbar, if any.
 *    If the application uses its own custom toolbar implementation, it
 *    should handle this event itself and respond appropriately. This
 *    event is generated by the basic window handler in response to a
 *    click in the window�s toolbar button.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose toolbar button was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse. Available in Mac OS X 10.1 and
 *          later.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window. Available in Mac
 *          OS X 10.1 and later.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *          Available in Mac OS X 10.1 and CarbonLib 1.5, and later.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint. Available on Mac OS X 10.1 and CarbonLib
 *          1.5, and later.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity. Available on Mac OS X 10.1 and
 *          CarbonLib 1.5, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowToolbarSwitchMode = 150
};

/*
 *  kEventClassWindow / kEventWindowFocusAcquired
 *  
 *  Summary:
 *    Notification that the user (or some other action) has caused the
 *    focus to shift to your window.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. 
 *    
 *    The standard window handler responds to this event by calling
 *    SetKeyboardFocus to focus on the first control in the window. An
 *    application handler may choose to set the focus to custom
 *    application content instead.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that is gaining focus.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowFocusAcquired     = 200
};

/*
 *  kEventClassWindow / kEventWindowFocusRelinquish
 *  
 *  Summary:
 *    Notification that a window has lost user focus.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. 
 *    
 *    The basic window handler responds to this event by clearing the
 *    the current keyboard focus, if the window�s activation scope is
 *    kWindowActivationScopeIndependent. An application handler should
 *    remove the focus from custom application content and ensure that
 *    the content is redrawn without the focus highlight.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that is losing focus.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowFocusRelinquish   = 201
};

/*
 *  kEventClassWindow / kEventWindowFocusContent
 *  
 *  Summary:
 *    A request to set the focus to the content area of a window.
 *  
 *  Discussion:
 *    If the content area of your window is not already focused, you
 *    should set the focus to the main part/control/view of the window.
 *    If the content area of your window is already focused, do
 *    nothing. The standard window handler responds to this event by
 *    calling HIViewAdvanceFocus on the window�s root control, if the
 *    focus is not already contained within the content root.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose content should be focused.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowFocusContent      = 202
};

/*
 *  kEventClassWindow / kEventWindowFocusToolbar
 *  
 *  Summary:
 *    A request to set the focus to the toolbar of a window.
 *  
 *  Discussion:
 *    If your window�s toolbar is not already focused, you should set
 *    the focus to the first item in the toolbar. If your window�s
 *    toolbar is already focused, do nothing. The basic window handler
 *    responds to this event by calling HIViewAdvanceFocus on the
 *    toolbar control, if the focus is not already contained within the
 *    toolbar.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose toolbar should be focused.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowFocusToolbar      = 203
};

/*
 *  kEventClassWindow / kEventWindowDrawerOpening
 *  
 *  Summary:
 *    Notification that a drawer is opening.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    is sent to the drawer and its parent window when the drawer
 *    begins opening.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The drawer that is opening.
 *  
 *  Result:
 *    An event handler for this event may return userCanceledErr if the
 *    drawer should not open. Any other return value is ignored and
 *    will still allow the drawer to open.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowDrawerOpening     = 220
};

/*
 *  kEventClassWindow / kEventWindowDrawerOpened
 *  
 *  Summary:
 *    Notification that a drawer is open.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    is sent to the drawer and its parent window when the drawer is
 *    fully open.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The drawer that opened.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowDrawerOpened      = 221
};

/*
 *  kEventClassWindow / kEventWindowDrawerClosing
 *  
 *  Summary:
 *    Notification that a drawer is closing.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    is sent to the drawer and its parent window when the drawer
 *    begins closing.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The drawer that is opening.
 *  
 *  Result:
 *    An event handler for this event may return userCanceledErr if the
 *    drawer should not close. Any other return value is ignored and
 *    will still allow the drawer to close.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowDrawerClosing     = 222
};

/*
 *  kEventClassWindow / kEventWindowDrawerClosed
 *  
 *  Summary:
 *    Notification that a drawer is closed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    is sent to the drawer and its parent window when the drawer is
 *    fully closed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The drawer that closed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowDrawerClosed      = 223
};

/*
 *  kEventClassWindow / kEventWindowDrawFrame
 *  
 *  Summary:
 *    Sent by the Window Manager when it�s time to draw a window�s
 *    structure.
 *  
 *  Discussion:
 *    This is the replacement to the old wDraw defProc message (though
 *    it is a special case of the 0 part code indicating to draw the
 *    entire window frame).
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window to draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDrawFrame         = 1000
};

/*
 *  kEventClassWindow / kEventWindowDrawPart
 *  
 *  Summary:
 *    Sent by the Window Manager when it�s time to draw a specific part
 *    of a window�s structure, such as the close button.
 *  
 *  Discussion:
 *    This is typically sent during window widget tracking.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window to draw.
 *    
 *    --> kEventParamWindowDefPart (in, typeWindowDefPartCode)
 *          The part to draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDrawPart          = 1001
};

/*
 *  kEventClassWindow / kEventWindowGetRegion
 *  
 *  Summary:
 *    Sent by the Window Manager when it needs to get a specific region
 *    from a window, or when the GetWindowRegion API is called.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose region to return.
 *    
 *    --> kEventParamWindowRegionCode (in, typeWindowRegionCode)
 *          The region to return.
 *    
 *    --> kEventParamRgnHandle (in, typeQDRgnHandle)
 *          On entry, contains a valid but empty RgnHandle; you should
 *          place the window region in this RgnHandle.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetRegion         = 1002
};

/*
 *  kEventClassWindow / kEventWindowHitTest
 *  
 *  Summary:
 *    Sent when the Window Manager needs to determine what part of a
 *    window would be 'hit' with a given mouse location in global
 *    coordinates.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window to hit-test.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location.
 *    
 *    <-- kEventParamWindowDefPart (out, typeWindowDefPartCode)
 *          On exit, contains the window part that was hit.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowHitTest           = 1003
};

/*
 *  kEventClassWindow / kEventWindowInit
 *  
 *  Summary:
 *    Sent by the Window Manager when the window is being created. This
 *    is a hook to allow your window definition to do any
 *    initialization you might need to do.
 *  
 *  Discussion:
 *    This event can be sent more than once to a window if the window
 *    definition function for the window is changed; see the note under
 *    kEventWindowDispose.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being created.
 *    
 *    <-- kEventParamWindowFeatures (out, typeUInt32)
 *          On exit, your event handler should store the window
 *          features in this parameter.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowInit              = 1004
};

/*
 *  kEventClassWindow / kEventWindowDispose
 *  
 *  Summary:
 *    Sent by the Window Manager to notify the window definition that
 *    it should dispose of any private data structures attached to the
 *    window.
 *  
 *  Discussion:
 *    Note that this event does not directly correspond with
 *    destruction of the window; the Window Manager occasionally needs
 *    to change the window definition of a window (for example, when
 *    ChangeWindowAttributes is used to change the visual appearance of
 *    a window), and in that case, the window will receive a
 *    kEventWindowDispose followed by a kEventWindowInit so that the
 *    old and new window definitions can disconnect and connect to the
 *    window. If you need to know when a window is really being
 *    destroyed, install a handler for kEventWindowClosed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being destroyed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDispose           = 1005
};

/*
 *  kEventClassWindow / kEventWindowDragHilite
 *  
 *  Summary:
 *    Sent by the Window Manager when it is time to draw/erase any drag
 *    hilite in the window structure.
 *  
 *  Discussion:
 *    This is typically sent from within HiliteWindowFrameForDrag.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window being hilited.
 *    
 *    --> kEventParamWindowDragHiliteFlag (in, typeBoolean)
 *          Whether to draw (true) or erase (false) the hilite.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDragHilite        = 1006
};

/*
 *  kEventClassWindow / kEventWindowModified
 *  
 *  Summary:
 *    Sent by the Window Manager when it is time to redraw window
 *    structure to account for a change in the document modified state.
 *  
 *  Discussion:
 *    This is typically sent from within SetWindowModified.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window that was modified.
 *    
 *    --> kEventParamWindowModifiedFlag (in, typeBoolean)
 *          The new modified state.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowModified          = 1007
};

/*
 *  kEventClassWindow / kEventWindowSetupProxyDragImage
 *  
 *  Summary:
 *    Sent by the Window Manager when it is time to generate a drag
 *    image for the window proxy.
 *  
 *  Discussion:
 *    This is typically sent from within BeginWindowProxyDrag.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose proxy is being dragged.
 *    
 *    <-- kEventParamWindowProxyGWorldPtr (out, typeGWorldPtr)
 *          On exit, contains a GWorld you allocate which contains the
 *          drag image.
 *    
 *    --> kEventParamWindowProxyImageRgn (in, typeQDRgnHandle)
 *          The region you modify to contain the clip region for the
 *          GWorld.
 *    
 *    --> kEventParamWindowProxyOutlineRgn (in, typeQDRgnHandle)
 *          The region you modify to contain the drag outline used when
 *          the GWorld cannot be used.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowSetupProxyDragImage = 1008
};

/*
 *  kEventClassWindow / kEventWindowStateChanged
 *  
 *  Summary:
 *    Sent by the Window Manager when a particular window state changes.
 *  
 *  Discussion:
 *    See the state-change flags in MacWindows.h.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose state was changed.
 *    
 *    --> kEventParamWindowStateChangedFlags (in, typeUInt32)
 *          The state change flags
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowStateChanged      = 1009
};

/*
 *  kEventClassWindow / kEventWindowMeasureTitle
 *  
 *  Summary:
 *    Sent when the Window Manager needs to know how much space the
 *    window�s title area takes up.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose title to measure.
 *    
 *    <-- kEventParamWindowTitleFullWidth (out, typeSInt16)
 *          On exit, contains the length of the whole title area.
 *    
 *    <-- kEventParamWindowTitleTextWidth (out, typeSInt16)
 *          On exit, contains the length just the title text.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowMeasureTitle      = 1010
};

/*
 *  kEventClassWindow / kEventWindowDrawGrowBox
 *  
 *  Summary:
 *    When the DrawGrowIcon API is called, this event is sent to the
 *    window to tell it to draw the grow box.
 *  
 *  Discussion:
 *    This is a compatibility event harkening back to the old days
 *    before Mac OS 8. Not very useful these days. This is only really
 *    needed for windows that do not have the grow box integrated into
 *    the window frame. Scroll bar delimiter lines are also drawn.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose grow box to draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowDrawGrowBox       = 1011
};

/*
 *  kEventClassWindow / kEventWindowGetGrowImageRegion
 *  
 *  Summary:
 *    This is a special way for a window to override the standard
 *    resize outline for windows that do not do live resizing.
 *  
 *  Discussion:
 *    As the user resizes the window, this event is sent with the
 *    current size the user has chosen expressed as a rectangle. You
 *    should calculate your window outline and modify the
 *    kEventParamRgnHandle parameter to reflect your desired outline.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window whose grow image to return.
 *    
 *    --> kEventParamWindowGrowRect (in, typeQDRectangle)
 *          The window�s global port bounds.
 *    
 *    --> kEventParamRgnHandle (in, typeQDRgnHandle)
 *          The region to modify.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventWindowGetGrowImageRegion = 1012
};

/*
 *  kEventClassWindow / kEventWindowPaint
 *  
 *  Summary:
 *    When the Window Manager needs to paint a window (e.g, when a
 *    window is first displayed), the kEventWindowPaint event is sent
 *    to allow the window to control all aspect of painting, including
 *    the window frame.
 *  
 *  Discussion:
 *    If a window does not respond to this event, the Window Manager
 *    ends up sending kEventWindowDrawFrame and then erasing the window
 *    to the window content color as usual. This is mostly used for
 *    specialty windows, such as help tags or appliance apps might have.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeWindowRef)
 *          The window to paint.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventWindowPaint             = 1013
};

/*��������������������������������������������������������������������������������������*/
/*  Menu Events                                                                         */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassMenu quick reference:
    
    kEventMenuBeginTracking         = 1,
    kEventMenuEndTracking           = 2,
    kEventMenuChangeTrackingMode    = 3,
    kEventMenuOpening               = 4,
    kEventMenuClosed                = 5,
    kEventMenuTargetItem            = 6,
    kEventMenuMatchKey              = 7,
    kEventMenuEnableItems           = 8,
    kEventMenuPopulate              = 9,
    
    kEventMenuMeasureItemWidth      = 100,
    kEventMenuMeasureItemHeight     = 101,
    kEventMenuDrawItem              = 102,
    kEventMenuDrawItemContent       = 103,
    
    kEventMenuDispose               = 1001,
    kEventMenuCalculateSize         = 1004,
    
    -- menu content view events --
    
    kEventMenuCreateFrameView       = 1005,
    kEventMenuGetFrameBounds        = 1006,
    kEventMenuBecomeScrollable      = 1007,
    kEventMenuCeaseToBeScrollable   = 1008,
    
    -- menu bar visibility events --
    
    kEventMenuBarShown              = 2000,
    kEventMenuBarHidden             = 2001
*/

/*
 *  Discussion:
 *    Menu context flags indicate the context or usage of a
 *    menu-related Carbon event.
 */
enum {
                                        /* menu location*/

  /*
   * Indicates that this menu is inserted in the menubar, or is a
   * (directly or indirectly) a submenu of a menu that is inserted in
   * the menubar.
   */
  kMenuContextMenuBar           = 1 << 0, /* menu type*/

  /*
   * Indicates that this menu is a pull-down menu inserted in the
   * menubar.
   */
  kMenuContextPullDown          = 1 << 8,

  /*
   * Indicates that this menu is a popup menu being displayed by
   * PopUpMenuSelect.
   */
  kMenuContextPopUp             = 1 << 9,

  /*
   * Indicates that this menu is a submenu of some other pull-down or
   * popup menu.
   */
  kMenuContextSubmenu           = 1 << 10, /* menu usage*/

  /*
   * Indicates that this Carbon event has been sent during a menubar
   * tracking session.
   */
  kMenuContextMenuBarTracking   = 1 << 16,

  /*
   * Indicates that this Carbon event has been sent during a popup menu
   * tracking session.
   */
  kMenuContextPopUpTracking     = 1 << 17,

  /*
   * Indicates that this Carbon event has been sent during command key
   * matching.
   */
  kMenuContextKeyMatching       = 1 << 18,

  /*
   * Indicates that this Carbon event has been sent at idle time to
   * update the enabled state of the menus. Available on Mac OS X 10.1
   * and later, and in CarbonLib 1.5 and later; on earlier releases,
   * the kMenuContextKeyMatching flag is set when an event is sent
   * during menu enabling.
   */
  kMenuContextMenuEnabling      = 1 << 19,

  /*
   * Indicates that this Carbon event has been sent during during a
   * search for a menu item command ID by the
   * CountMenuItemsWithCommandID or GetIndMenuItemWithCommandID APIs.
   * Available on Mac OS X 10.2 and CarbonLib 1.6.
   */
  kMenuContextCommandIDSearch   = 1 << 20
};


/*
 *  Summary:
 *    Menu direction
 */
enum {

  /*
   * Indicates that the menu should be placed to the right of its
   * parent.
   */
  kHIMenuRightDirection         = 0,

  /*
   * Indicates that the menu should be placed to the left of its parent.
   */
  kHIMenuLeftDirection          = 1,

  /*
   * Indicates that the menu should be centered on its parent.
   */
  kHIMenuCenterDirection        = 2
};

/*
 *  kEventClassMenu / kEventMenuBeginTracking
 *  
 *  Summary:
 *    The user has begun tracking the menubar or a pop-up menu.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    first to the menu specified in the direct object parameter, if
 *    any, and then to the user focus target.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The root of the menu hierarchy being tracked. If tracking a
 *          popup menu, this parameter is the popup; if tracking the
 *          menubar, this parameter is the root menu on Mac OS X, but
 *          is NULL in CarbonLib.
 *    
 *    --> kEventParamCurrentMenuTrackingMode (in, typeMenuTrackingMode)
 *          Indicates whether the user is tracking the menus using the
 *          mouse or the keyboard. Contains either
 *          kMenuTrackingModeMouse or kMenuTrackingModeKeyboard.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          Menu context flags indicating what type of menu is being
 *          tracked. This parameter is available on Mac OS X 10.1 and
 *          later, and CarbonLib 1.5 and later.
 *  
 *  Result:
 *    The handler may return userCanceledErr to stop menu tracking.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuBeginTracking       = 1
};

/*
 *  kEventClassMenu / kEventMenuEndTracking
 *  
 *  Summary:
 *    The user has finished tracking the menubar or a popup menu
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    first to the menu specified in the direct object parameter, if
 *    any, and then to the user focus target. 
 *    
 *    In Mac OS X 10.3 and later, when a menu tracking session ends,
 *    the Menu Manager now sends kEventMenuEndTracking to every menu
 *    that was opened during the session, in addition to the root menu.
 *    This is done to allow menus with dynamic content to remove that
 *    content at the end of menu tracking; for example, a menu
 *    containing many IconRefs might wish to load the IconRefs
 *    dynamically in response to a kEventMenuPopulate, and remove them
 *    in response to kEventMenuEndTracking, to avoid the memory
 *    overhead of keeping the IconRef data in memory while the menu is
 *    not being displayed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The root of the menu hierarchy being tracked. If tracking a
 *          popup menu, this parameter is the popup; if tracking the
 *          menubar, this parameter is the root menu on Mac OS X, but
 *          is NULL in CarbonLib.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          Menu context flags indicating what type of menu was being
 *          tracked. This parameter is available on Mac OS X 10.1 and
 *          later, and CarbonLib 1.5 and later.
 *    
 *    --> kEventParamMenuDismissed (in, typeUInt32)
 *          Contains an indication of why menu tracking ended; this
 *          will be one of the kHIMenuDismissedBy constants in Menus.h.
 *          This parameter is available on Mac OS X 10.3 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuEndTracking         = 2
};

/*
 *  kEventClassMenu / kEventMenuChangeTrackingMode
 *  
 *  Summary:
 *    The user has switched from selecting a menu with the mouse to
 *    selecting with the keyboard, or from selecting with the keyboard
 *    to selecting with the mouse.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    first to the menu specified in the direct object parameter, and
 *    then to the user focus target.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The root of the menu hierarchy being tracked. If tracking a
 *          popup menu, this parameter is the popup; if tracking the
 *          menubar, this parameter is the root menu.
 *    
 *    --> kEventParamCurrentMenuTrackingMode (in, typeMenuTrackingMode)
 *          Indicates whether the user was previously tracking the
 *          menus using the mouse or the keyboard. Contains either
 *          kMenuTrackingModeMouse or kMenuTrackingModeKeyboard.
 *    
 *    --> kEventParamNewMenuTrackingMode (in, typeMenuTrackingMode)
 *          Indicates whether the user is now tracking the menus using
 *          the mouse or the keyboard. Contains either
 *          kMenuTrackingModeMouse or kMenuTrackingModeKeyboard.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          Menu context flags indicating what type of menu is being
 *          tracked.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuChangeTrackingMode  = 3
};

/*
 *  kEventClassMenu / kEventMenuOpening
 *  
 *  Summary:
 *    A menu is opening.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    each time that the menu is opened (i.e., more than once during a
 *    given tracking session if the user opens the menu multiple
 *    times). It is sent before the menu is actually drawn, so you can
 *    update the menu contents (including making changes that will
 *    alter the menu size) and the new contents will be drawn correctly.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being opened.
 *    
 *    --> kEventParamMenuFirstOpen (in, typeBoolean)
 *          Whether this is the first time this menu has been opened
 *          during this menu tracking session.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu is opening. Available on Mac
 *          OS X and CarbonLib 1.5 and later.
 *  
 *  Result:
 *    On Mac OS X, the handler may return userCanceledErr to prevent
 *    this menu from opening
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuOpening             = 4
};

/*
 *  kEventClassMenu / kEventMenuClosed
 *  
 *  Summary:
 *    A menu has been closed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    after the menu is hidden.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being closed.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu is closing. Available on Mac
 *          OS X 10.1 and later, and CarbonLib 1.5 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuClosed              = 5
};

/*
 *  kEventClassMenu / kEventMenuTargetItem
 *  
 *  Summary:
 *    The mouse is moving over a particular menu item.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    for both enabled and disabled items.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being tracked.
 *    
 *    --> kEventParamMenuItemIndex (in, typeMenuItemIndex)
 *          The menu item under the mouse.
 *    
 *    --> kEventParamMenuCommand (in, typeMenuCommand)
 *          The command ID associated with this menu item.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu being tracked. Available on
 *          Mac OS X 10.1 and later, and CarbonLib 1.5 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuTargetItem          = 6
};


/*
 *  kEventClassMenu / kEventMenuMatchKey
 *  
 *  Summary:
 *    A menu is about to be examined for items that match a command key
 *    event.
 *  
 *  Discussion:
 *    A handler for this event may perform its own command key matching
 *    and override the Menu Manager�s default matching algorithms.
 *    Returning noErr from your handler indicates that you have found a
 *    match. The handler for this event should not examine submenus of
 *    this menu for a match; a separate event will be sent for each
 *    submenu. 
 *    
 *    Handlers for this event must be installed directly on the menu
 *    containing the item to be matched. To improve performance of
 *    command key matching, the Menu Manager only sends this event if
 *    the menu itself has a handler; if a handler for this event is
 *    installed on any other event target, it will not receive the
 *    event. <BR><BR> This event is sent after kEventMenuEnableItems.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being searched for a command key match.
 *    
 *    --> kEventParamEventRef (in, typeEventRef)
 *          The keyboard input event that should be checked for a
 *          match. Currently this event is always kEventRawKeyDown, but
 *          in the future it may be kEventTextInputUnicodeForKeyEvent.
 *          When called from IsMenuKeyEvent, this parameter contains
 *          the EventRef that was passed to IsMenuKeyEvent; when called
 *          from MenuKey or MenuEvent, this parameter contains an event
 *          created from the information passed to MenuKey or
 *          MenuEvent. Note that in the MenuKey case, no virtual
 *          keycode (kEventParamKeyCode) or key modifiers
 *          (kEventParamKeyModifiers) will be available.
 *    
 *    --> kEventParamMenuEventOptions (in, typeMenuEventOptions)
 *          Options from the MenuEventOptions enum that control how the
 *          menu should be searched for a command key. This parameter
 *          contains the options that were passed to IsMenuKeyEvent, or
 *          0 if called from MenuKey or MenuEvent. The only option that
 *          your handler will need to obey is
 *          kMenuEventIncludeDisabledItems; other options are
 *          irrelevant for an event handler.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu is being searched for a
 *          command key. Available on Mac OS X 10.1 and later, and
 *          CarbonLib 1.5 and later.
 *    
 *    <-- kEventParamMenuItemIndex (out, typeMenuItemIndex)
 *          On exit, contains the menu item index that matched the
 *          event.
 *  
 *  Result:
 *    If your handler finds a match, it should set the
 *    kEventParamMenuItemIndex parameter to contain the item index of
 *    the matching item, and return noErr. If it does not find a match,
 *    it should return menuItemNotFoundErr. Any other return value will
 *    cause the Menu Manager to use its default command key matching
 *    algorithm for this menu.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuMatchKey            = 7
};


/*
 *  kEventClassMenu / kEventMenuEnableItems
 *  
 *  Summary:
 *    A request that the items in the menu be properly enabled or
 *    disabled according to the current state of the application.
 *  
 *  Discussion:
 *    This event is sent from inside MenuKey, MenuEvent, and
 *    IsMenuKeyEvent before those APIs examine the menu for an item
 *    that matches a keyboard event. It is also sent during menu
 *    tracking before a menu is first made visible; it is sent
 *    immediately after kEventMenuOpening, once per menu per menu
 *    tracking session. It is also sent to the top-level menus in the
 *    menubar when the application is idle after user input has
 *    occurred, to allow the menu titles to be enabled or disabled
 *    appropriately according to the current user focus. You can
 *    distinquish between all these cases by examining the contents of
 *    the kEventParamMenuContext parameter. 
 *    
 *    If you install an event handler for kEventCommandProcess, you
 *    should also install a handler for either kEventMenuEnableItems or
 *    kEventCommandUpdateStatus. This is necessary because the Carbon
 *    event system will attempt to match command keys against the
 *    available menus before returning the keyboard event to your
 *    application via WaitNextEvent. If you have menu command event
 *    handlers installed for your menu items, your handlers will be
 *    called without your ever receiving the keyboard event or calling
 *    MenuKey/MenuEvent/IsMenuKeyEvent yourself. Therefore, you have no
 *    opportunity to enable your menu items properly other than from a
 *    kEventMenuEnableItems or kEventCommandUpdateStatus handler. 
 *     It is not necessary to handle this event if you do not install
 *    kEventCommandProcess handlers for your menu items; in that case,
 *    the command key event will be returned from WaitNextEvent or
 *    ReceiveNextEvent as normal, and you can set up your menus before
 *    calling MenuKey/MenuEvent/ IsMenuKeyEvent.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being enabled.
 *    
 *    --> kEventParamEnableMenuForKeyEvent (in, typeBoolean)
 *          Indicates whether this menu should be enabled for key event
 *          matching (true) or because the menu itself is about to
 *          become visible (false). If true, only the item enable
 *          state, command key, command key modifiers, and (optionally)
 *          the command key glyph need to be correct. If false, the
 *          entire menu item contents must be correct. This may be
 *          useful if you have custom menu content that is expensive to
 *          prepare.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu is being enabled. Available
 *          on Mac OS X and CarbonLib 1.3.1 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuEnableItems         = 8
};


/*
 *  kEventClassMenu / kEventMenuPopulate
 *  
 *  Summary:
 *    kEventMenuPopulate is intended to be handled by applications that
 *    dynamically create their menu contents just-in-time before the
 *    menu is displayed. A handler for this event can add items to tbe
 *    menu that will be displayed or searched for a command key.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. Previously,
 *    kEventMenuOpening was recommended for the purpose of dynamically
 *    updating menu content. kEventMenuPopulate is now recommended
 *    because it will be sent by the Menu Manager before it searches a
 *    menu for a matching command key, to allow a handler to
 *    dynamically add menu items that may have command key equivalents
 *    to the menu; kEventMenuOpening is only sent before the menu is
 *    displayed. kEventMenuPopulate is also sent just before
 *    kEventMenuOpening as a menu is being displayed. Finally,
 *    kEventMenuPopulate is only sent once per menu tracking session
 *    for a given menu, even if that menu is closed and opened multiple
 *    times by the user; kEventMenuOpening is sent each time that the
 *    menu is displayed. 
 *    
 *    You can distinguish the command-key case from the
 *    menu-being-displayed case by examining the contents of the
 *    kEventParamMenuContext parameter; the kMenuContextKeyMatching
 *    flag will be set if the event is sent during command key
 *    matching, and either the kMenuContextMenuBarTracking or
 *    kMenuContextPopUpTracking flags will be sent if the event is sent
 *    before actual display of the menu. 
 *    
 *    In Mac OS X 10.2 and CarbonLib 1.6, kEventMenuPopulate is also
 *    sent to menus before the menu is searched for a command ID by the
 *    CountMenuItemsWithCommandID and GetIndMenuItemWithCommandID APIs.
 *    You can distinguish this case by checking for the
 *    kMenuContextCommandIDSearch flag in the kEventParamMenuContext
 *    parameter. In this case, the event also includes a
 *    kEventParamMenuCommand parameter with the command ID being
 *    searched for as the event parameter data.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu to be populated.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          The context in which this menu is being populated.
 *    
 *    --> kEventParamMenuCommand (in, typeMenuCommand)
 *          If this event is sent by CountMenuItemsWithCommandID or
 *          GetIndMenuItemWithCommandID, this parameter contains the
 *          command ID for which the API is searching. Available on Mac
 *          OS X 10.2 and CarbonLib 1.6.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventMenuPopulate            = 9
};


/*
 *  kEventClassMenu / kEventMenuDispose
 *  
 *  Summary:
 *    Sent when a menu is being destroyed.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being destroyed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventMenuDispose             = 1001
};

/*
 *  kEventClassMenu / kEventMenuMeasureItemWidth
 *  
 *  Summary:
 *    Requests measurement of the width of a menu item.
 *  
 *  Discussion:
 *    Sent by the standard menu definition when a menu item has the
 *    kMenuItemAttrCustomDraw attribute. Handlers for this event should
 *    be installed directly on the menu. A handler for this event may
 *    respond by providing a customized width for the menu item. If no
 *    handler is installed, the standard menu definition provides a
 *    default handler that will return the standard width for the item.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu that is being measured.
 *    
 *    --> kEventParamMenuItemIndex (in, typeMenuItemIndex)
 *          The menu item that is being measured.
 *    
 *    <-- kEventParamMenuItemWidth (out, typeShortInteger)
 *          On exit, contains the menu item width.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventMenuMeasureItemWidth    = 100
};


/*
 *  kEventClassMenu / kEventMenuMeasureItemHeight
 *  
 *  Summary:
 *    Requests measurement of the height of a menu item.
 *  
 *  Discussion:
 *    Sent by the standard menu definition when a menu item has the
 *    kMenuItemAttrCustomDraw attribute. Handlers for this event should
 *    be installed directly on the menu. A handler for this event may
 *    respond by providing a customized height for the menu item. If no
 *    handler is installed, the standard menu definition provides a
 *    default handler that will return the standard height for the item.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu that is being measured.
 *    
 *    --> kEventParamMenuItemIndex (in, typeMenuItemIndex)
 *          The menu item that is being measured.
 *    
 *    <-- kEventParamMenuItemHeight (out, typeShortInteger)
 *          On exit, contains the menu item height.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventMenuMeasureItemHeight   = 101
};


/*
 *  kEventClassMenu / kEventMenuDrawItem
 *  
 *  Summary:
 *    Requests drawing of an entire menu item, including its background.
 *  
 *  Discussion:
 *    Sent by the standard menu definition when a menu item has the
 *    kMenuItemAttrCustomDraw attribute. Handlers for this event should
 *    be installed directly on the menu. A handler for this event may
 *    respond by completely overriding the drawing of the menu item.
 *    The item should be drawn into the current port if using
 *    QuickDraw, or into the provided CGContextRef if using
 *    CoreGraphics. If no handler is installed, the standard menu
 *    definition provides a default handler that calls
 *    DrawThemeMenuItem to draw the menu item background and content.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being drawn.
 *    
 *    --> kEventParamCurrentBounds (in, typeQDRectangle)
 *          The bounds of the menu, in global coordinates
 *    
 *    --> kEventParamMenuItemIndex (in, typeMenuItemIndex)
 *          The menu item being drawn.
 *    
 *    --> kEventParamMenuItemBounds (in, typeQDRectangle)
 *          The bounds of the menu item, in local coordinates of the
 *          current port.
 *    
 *    --> kEventParamMenuVirtualTop (in, typeLongInteger)
 *          The virtual top coordinate of the menu, in global
 *          coordinates.
 *    
 *    --> kEventParamMenuVirtualBottom (in, typeLongInteger)
 *          The virtual bottom coordinate of the menu, in global
 *          coordinates.
 *    
 *    --> kEventParamMenuDrawState (in, typeThemeMenuState)
 *          The ThemeMenuState of the menu.
 *    
 *    --> kEventParamMenuItemType (in, typeThemeMenuItemType)
 *          The type of menu item.
 *    
 *    --> kEventParamCGContextRef (in, typeCGContextRef)
 *          The CG context in which the menu should be drawn.
 *    
 *    <-- kEventParamMenuMarkBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item mark
 *          character. Not present if the >                       item
 *          has no mark. Added to the event by the standard menu
 *          definition�s handler, if the event is allowed to pass
 *          through.
 *    
 *    <-- kEventParamMenuIconBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item icon. Not
 *          present if the item has no icon. Added to the event by the
 *          standard menu definition�s handler, if the event is allowed
 *          to pass through.
 *    
 *    <-- kEventParamMenuTextBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item�s text. Added
 *          to the event by the standard menu definition�s handler, if
 *          the event is allowed to pass through.
 *    
 *    <-- kEventParamMenuTextBaseline (out, typeShortInteger)
 *          On exit, contains the baseline of the menu item�s text.
 *          Added to the event by the standard menu definition�s
 *          handler, if the event is allowed to pass through.
 *    
 *    <-- kEventParamMenuCommandKeyBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item command key.
 *          Not present if the item has no command key. Added to the
 *          event by the standard menu definition�s handler, if the
 *          event is allowed to pass through.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventMenuDrawItem            = 102
};


/*
 *  kEventClassMenu / kEventMenuDrawItemContent
 *  
 *  Summary:
 *    Requests drawing of a menu item�s content: its text, command key,
 *    icon, etc.
 *  
 *  Discussion:
 *    Sent by the standard menu definition when a menu item has the
 *    kMenuItemAttrCustomDraw attribute. Handlers for this event should
 *    be installed directly on the menu. A handler for this event may
 *    respond by overriding the drawing of the menu item content: the
 *    mark character, icon, text, and command key information. At the
 *    time when this event is sent, the background of the menu item has
 *    already been drawn using the standard system appearance, and if
 *    the item is selected, the background is drawn with a hilite. The
 *    item should be drawn into the current port if using QuickDraw, or
 *    into the provided CGContextRef if using CoreGraphics. If no
 *    handler is installed, the standard menu definition provides a
 *    default handler that draws the standard menu item content. The
 *    standard handler also adds event parameters to the event
 *    indicating the bounding boxes of the different portions of the
 *    menu item content (mark, icon, text, and command keys), and an
 *    event parameter with the baseline of the menu item text; this
 *    allows handlers to use CallNextEventHandler to call through to
 *    the standard system handler, and then modify the system
 *    appearance by drawing on top of the standard content.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being drawn.
 *    
 *    --> kEventParamMenuItemIndex (in, typeMenuItemIndex)
 *          The menu item being drawn.
 *    
 *    --> kEventParamMenuItemBounds (in, typeQDRectangle)
 *          The bounds of the menu item, in local coordinates of the
 *          current port.
 *    
 *    --> kEventParamDeviceDepth (in, typeShortInteger)
 *          The bit depth of the GDevice on which the menu is being
 *          drawn.
 *    
 *    --> kEventParamDeviceColor (in, typeBoolean)
 *          Whether the GDevice on which the menu is being drawn is in
 *          black&white or color mode.
 *    
 *    --> kEventParamCGContextRef (in, typeCGContextRef)
 *          The CG context in which the menu should be drawn.
 *    
 *    <-- kEventParamMenuMarkBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item mark
 *          character. Not present if the item has no mark. Added to
 *          the event by the standard menu definition�s handler, if the
 *          event is allowed to pass through.
 *    
 *    <-- kEventParamMenuIconBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item icon. Not
 *          present if the item has no icon. Added to the event by the
 *          standard menu definition�s handler, if the event is allowed
 *          to pass through.
 *    
 *    <-- kEventParamMenuTextBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item�s text. Added
 *          to the event by the standard menu definition�s handler, if
 *          the event is allowed to pass through.
 *    
 *    <-- kEventParamMenuTextBaseline (out, typeShortInteger)
 *          On exit, contains the baseline of the menu item�s text.
 *          Added to the event by the standard menu definition�s
 *          handler, if the event is allowed to pass through.
 *    
 *    <-- kEventParamMenuCommandKeyBounds (out, typeQDRectangle)
 *          On exit, contains the bounds of the menu item command key.
 *          Not present if the item has no command key. Added to the
 *          event by the standard menu definition�s handler, if the
 *          event is allowed to pass through.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.5 and later
 */
enum {
  kEventMenuDrawItemContent     = 103
};

/*
 *  kEventClassMenu / kEventMenuCalculateSize
 *  
 *  Summary:
 *    Requests that a menu calculate its total size.
 *  
 *  Discussion:
 *    Sent by CalcMenuSize to request that the menu calculate its size.
 *    The Menu Manager provides a default handler for all menus that
 *    calls the menu's MDEF or menu content view to determine the menu
 *    size. Applications will typically not need to handle this event;
 *    a custom menu definition or menu content view should use
 *    kMenuSizeMsg or kEventControlGetOptimalBounds to calculate its
 *    size. 
 *    
 *    Note that if the menu uses an MDEF, the MDEF will set the menu's
 *    width and height in response to kMenuSizeMsg. The default handler
 *    for this event saves the old width and height before calling the
 *    MDEF and restores them afterwards. CalcMenuSize will set the
 *    final menu width and height based on the dimensions returned from
 *    this event; applications may override this event to customize the
 *    width or height of a menu by modifying the kEventParamDimensions
 *    parameter. 
 *    
 *    This event is sent only to the menu, and is not propagated past
 *    it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeMenuRef)
 *          The menu being measured.
 *    
 *    --> kEventParamControlRef (in, typeControlRef)
 *          If the menu uses a content view, this parameter contains
 *          the HIViewRef that should calculate the menu's size. This
 *          parameter will not be present if the menu uses an MDEF.
 *    
 *    --> kEventParamGDevice (in, typeGDHandle)
 *          If the menu uses an MDEF, this parameter contains the
 *          GDevice on which the menu will be displayed. This parameter
 *          will not be present if the menu uses a content view.
 *    
 *    --> kEventParamAvailableBounds (in, typeQDRectangle)
 *          If the menu uses an MDEF, this parameter contains a
 *          bounding rect in global coordinates inside of which the
 *          menu should be displayed. This parameter is optional and
 *          may not be present in all instances of this event; if not
 *          present, the GDevice's bounds should be used instead. This
 *          parameter will not be present if the menu uses a content
 *          view.
 *    
 *    <-- kEventParamDimensions (out, typeHISize)
 *          On exit, contains the menu's size.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuCalculateSize       = 1004
};

/*
 *  kEventClassMenu / kEventMenuCreateFrameView
 *  
 *  Summary:
 *    Requests that a menu content view create the HIView that will
 *    used to draw the menu window frame.
 *  
 *  Discussion:
 *    The HIMenuView class provides a default handler for this event
 *    that creates an instance of the standard menu window frame view.
 *    
 *    
 *    This event is sent only to the menu content view, and is not
 *    propagated past the view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamEventRef (in, typeEventRef)
 *          The initialization event that should be used to create the
 *          view. A handler for this event may add its own parameters
 *          to this event.
 *    
 *    --> kEventParamMenuType (in, typeThemeMenuType)
 *          The type of menu frame (pull-down, popup, or hierarchical)
 *          that is needed.
 *    
 *    <-- kEventParamMenuFrameView (out, typeControlRef)
 *          On exit, contains the newly created menu frame view.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuCreateFrameView     = 1005
};

/*
 *  kEventClassMenu / kEventMenuGetFrameBounds
 *  
 *  Summary:
 *    Requests that a menu content view calculate the bounding rect, in
 *    global coordinates, of the menu window frame that should contain
 *    the menu.
 *  
 *  Discussion:
 *    This event is sent by the Menu Manager before displaying
 *    pull-down, popup, and hierarchical menus. It provides an
 *    opportunity for the menu content view to determine the position
 *    of the menu frame based on the position of the menu title, parent
 *    menu item, or popup menu location. 
 *    
 *    The HIMenuView class provides a default handler for this event
 *    that calculates an appropriate location based on the bounds of
 *    the menu, the available screen space, and the frame metrics of
 *    the menu window content view. 
 *    
 *    This event is sent only to the menu content view, and is not
 *    propagated past the view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamMenuType (in, typeThemeMenuType)
 *          The type of menu (pull-down, popup, or hierarchical) that
 *          is being displayed.
 *    
 *    --> kEventParamMenuIsPopup (in, typeBoolean)
 *          Whether this menu originated from a popup menu. Primarily
 *          useful to distinguish between hierarchical menus that are
 *          submenus of pull-down menus, and hierarchical menus that
 *          are submenus of popup menus.
 *    
 *    --> kEventParamMenuFrameView (in, typeControlRef)
 *          The menu window frame view.
 *    
 *    --> kEventParamMenuDirection (in, typeMenuDirection)
 *          The suggested direction (left or right) which the view
 *          should attempt to use when positioning the menu window. For
 *          pull-down menus, this will typically be
 *          kHIMenuRightDirection; for hierarchical menus, it will be
 *          the same direction as the parent menu.
 *    
 *    --> kEventParamMenuItemBounds (in, typeHIRect)
 *          The bounds, in global coordinates, of the parent menu title
 *          (for pull-down menus), the parent menu item (for
 *          hierarchical menus), or the popup location (for popup
 *          menus).
 *    
 *    --> kEventParamGDevice (in, typeGDHandle)
 *          The GDevice on which the menu should be displayed.
 *    
 *    --> kEventParamAvailableBounds (in, typeHIRect)
 *          The available bounds, in global coordinates, inside which
 *          the menu should be displayed. The menu should not extend
 *          outside of these bounds.
 *    
 *    --> kEventParamParentMenu (in, typeMenuRef)
 *          Only available when kEventParamMenuType is
 *          kThemeMenuTypeHierarchical. The parent menu of this menu.
 *    
 *    --> kEventParamParentMenuItem (in, typeMenuItemIndex)
 *          Only available when kEventParamMenuType is
 *          kThemeMenuTypeHierarchical. The parent menu item of this
 *          menu.
 *    
 *    --> kEventParamMenuPopupItem (in, typeMenuItemIndex)
 *          Only available when kEventParamMenuType is
 *          kThemeMenuTypePopUp. The item in the menu that should be
 *          positioned at the popup location, or zero if no item should
 *          be positioned there.
 *    
 *    <-- kEventParamBounds (out, typeHIRect)
 *          On exit, contains the bounding rect, in global coordinates,
 *          of the menu window. The handler should add this parameter
 *          to the event.
 *    
 *    <-- kEventParamOrigin (out, typeHIPoint)
 *          On exit, contains the origin to which the menu content view
 *          should be scrolled before the menu is displayed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuGetFrameBounds      = 1006
};

/*
 *  kEventClassMenu / kEventMenuBecomeScrollable
 *  
 *  Summary:
 *    Requests that a menu content view prepare to be scrollable, by
 *    installing the appropriate event handlers, timers, etc.
 *  
 *  Discussion:
 *    This event is sent by the Menu Manager when a menu becomes the
 *    most recently opened menu in the menu hierarchy. It is an
 *    indication that this menu content view is now a candidate for
 *    scrolling. 
 *    
 *    The Menu Manager provides a default handler for this event that
 *    installs event handlers to provide automatic scrolling behavior
 *    for HIView-based menus. 
 *    
 *    If a menu content view does not wish to use the Menu Manager's
 *    default scrolling support, it can override this event and return
 *    noErr to prevent the event from being propagated to the Menu
 *    Manager's default handler. 
 *    
 *    This event is sent only to the menu content view, and is not
 *    propagated past the view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuBecomeScrollable    = 1007
};

/*
 *  kEventClassMenu / kEventMenuCeaseToBeScrollable
 *  
 *  Summary:
 *    Requests that a menu content view cease to be scrollable.
 *  
 *  Discussion:
 *    This event is sent by the Menu Manager when a menu ceases to be
 *    the most recently opened menu. This occurs when the menu is
 *    closed, or when a submenu of the most recently opened menu is
 *    opened. It is an indication that this menu content view is no
 *    longer a candidate for scrolling. 
 *    
 *    The Menu Manager provides a default handler for this event that
 *    removes event handlers installed in response to
 *    kEventMenuBecomeScrollable. 
 *    
 *    This event is sent only to the menu content view, and is not
 *    propagated past the view.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuCeaseToBeScrollable = 1008
};

/*
 *  kEventClassMenu / kEventMenuBarShown
 *  
 *  Summary:
 *    Notification that the menubar in the frontmost process has been
 *    shown.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    will be sent to registered handlers in all processes when the
 *    front process shows its menubar. This event is sent only to the
 *    application target.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuBarShown            = 2000
};

/*
 *  kEventClassMenu / kEventMenuBarHidden
 *  
 *  Summary:
 *    Notification that the menubar in the frontmost process has been
 *    hidden.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. This event
 *    will be sent to registered handlers in all processes when the
 *    front process hides its menubar. This event is sent only to the
 *    application target.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventMenuBarHidden           = 2001
};

/*��������������������������������������������������������������������������������������*/
/*  Command Events                                                                      */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassCommand quick reference:
    
    kEventCommandProcess        = 1,
    kEventCommandUpdateStatus   = 2
*/
/*
 *  kEventClassCommand / kEventCommandProcess
 *  
 *  Summary:
 *    A command has been invoked and the application should handle it.
 *  
 *  Discussion:
 *    This event is sent when the user chooses a menu item or clicks a
 *    control. Any menu item selection, from either the menubar, a
 *    popup or contextual menu, or a popup or bevel button control,
 *    will cause this event to be sent; if the menu item does not have
 *    a command ID, the commandID field of the HICommand parameter will
 *    be zero, but the event will still contain a valid MenuRef and
 *    MenuItemIndex. Controls will send this event only if the control
 *    has a non-zero command ID set with SetControlCommandID. 
 *    
 *    Some senders of this event will also include the modifier keys
 *    that were pressed by the user when the command was invoked, but
 *    this parameter is optional and may not be present in all
 *    instances of this event. 
 *    
 *    When a command event is sent from a menu, a MenuContext parameter
 *    will be included on Mac OS X 10.2 and CarbonLib 1.6, indicating
 *    whether the command was sent from a menu in the menubar
 *    (kMenuContextMenuBar will be set) or from a popup menu
 *    (kMenuContextMenuBar will not be set). The MenuContext parameter
 *    also indicates whether the event was sent by a selection of a
 *    menu item with the mouse (kMenuContextMenuBarTracking or
 *    kMenuContextPopUpTracking will be set), or by a command key press
 *    (kMenuContextKeyMatching will be set). If you need to determine
 *    the source of a command event on a Carbon release prior to Mac OS
 *    X 10.2 or CarbonLib 1.6, we recommend installing a
 *    kEventMenuEnableItems handler on each menu and caching the
 *    MenuContext parameter in the EnableItems event in a menu
 *    property; when you receive the CommandProcess event, look up the
 *    cached MenuContext. 
 *    
 *    It is essential that your event handler for this event return
 *    eventNotHandledErr for any command events that you do not handle,
 *    especially for commands that are sent from menus attached to
 *    popup or bevel button controls; if, for example, you return noErr
 *    for command events sent in response to a menu selection from a
 *    popup button, the Menu Manager will return zero from
 *    PopUpMenuSelect, and the popup button control will not know that
 *    an item was selected from the popup menu and will not redraw with
 *    the new selection.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeHICommand)
 *          The command to be handled.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the command
 *          was invoked by the user. This parameter is optional and may
 *          not be present in all instances of this event.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          If the command was contained in a menu, information about
 *          the menu. This parameter is optional and may not be present
 *          in all instances of this event. Available in Mac OS X 10.2
 *          and CarbonLib 1.6, and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventCommandProcess          = 1
};

/*
 *  kEventClassCommand / kEventCommandUpdateStatus
 *  
 *  Summary:
 *    A command-generating user interface element requires updating.
 *  
 *  Discussion:
 *    When you receive this event, you should update the necessary UI
 *    elements in your application to reflect the current status of the
 *    command. For example, if the command has the kHICommandFromMenu
 *    bit set, you should update the menu item state, menu item text,
 *    and so on, to reflect the current reality in your application. If
 *    the menu item is the "Undo" item, and the last editing change to
 *    the document was a Cut operation, then you might set the text to
 *    "Undo Cut" and enable the menu item. 
 *    
 *    Currently, this event is only sent for menu items; it is not used
 *    to update the status of controls. 
 *    
 *    Note that when responding to this event, you should only update
 *    the status of the single user interface element (a menu item, for
 *    example) described by the HICommand structure; you should not
 *    update the status of the entire menu or of all menus in the
 *    menubar. You will receive a separate UpdateStatus event for each
 *    menu item in a menu, and each item should be updated
 *    individually. When updating a menu item, you should generally not
 *    use Enable/DisableMenuCommand; these APIs search the entire menu
 *    hierarchy for the command ID. Instead, just call
 *    Enable/DisableMenuItem directly, passing the menu and menu item
 *    index that are provided to you in the HICommand structure.
 *    
 *    
 *    You may wish to optimize your handling of the UpdateStatus event
 *    by examining the MenuContext parameter to the event. This
 *    parameter indicates the context in which the command requires
 *    updating. For example, if the menu context parameter has the
 *    kMenuContextKeyMatching bit set, you know that the update request
 *    is being sent in while search for a menu item that matches a
 *    command key. This knowledge can help you avoid unnecessary work;
 *    if your menu item for this command has no command key, for
 *    example, you can ignore this event when the KeyMatching bit is
 *    set because your menu item will never match a command key
 *    anyways, regardless of whether it is enabled or disabled.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeHICommand)
 *          The command to be updated.
 *    
 *    --> kEventParamMenuContext (in, typeUInt32)
 *          If the command was contained in a menu, information about
 *          the menu and the context of the command updating request.
 *          This parameter is optional and may not be present in all
 *          instances of this event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventCommandUpdateStatus     = 2
};

/* HI Commands */

/*
 *  Summary:
 *    Common command IDs
 */
enum {

  /*
   * The OK button in a dialog or alert.
   */
  kHICommandOK                  = 'ok  ',

  /*
   * The Cancel button in a dialog or alert.
   */
  kHICommandCancel              = 'not!',

  /*
   * The application should quit.
   */
  kHICommandQuit                = 'quit',

  /*
   * The last editing operation should be undone.
   */
  kHICommandUndo                = 'undo',

  /*
   * The last editing operation should be redone.
   */
  kHICommandRedo                = 'redo',

  /*
   * The selected items should be cut.
   */
  kHICommandCut                 = 'cut ',

  /*
   * The selected items should be copied.
   */
  kHICommandCopy                = 'copy',

  /*
   * The contents of the clipboard should be pasted.
   */
  kHICommandPaste               = 'past',

  /*
   * The selected items should be deleted.
   */
  kHICommandClear               = 'clea',

  /*
   * All items in the active window should be selected.
   */
  kHICommandSelectAll           = 'sall',

  /*
   * The application should be hidden. The Menu Manager will respond to
   * this command automatically; your application does not need to
   * handle it.
   */
  kHICommandHide                = 'hide',

  /*
   * Other applications should be hidden. The Menu Manager will respond
   * to this command automatically; your application does not need to
   * handle it.
   */
  kHICommandHideOthers          = 'hido',

  /*
   * All applications should become visible. The Menu Manager will
   * respond to this command automatically; your application does not
   * need to handle it.
   */
  kHICommandShowAll             = 'shal',

  /*
   * The Preferences menu item has been selected.
   */
  kHICommandPreferences         = 'pref',

  /*
   * The active window should be zoomed in or out. The Window Manager
   * will respond to this event automatically; your application does
   * not need to handle it, but you may want to install a Carbon event
   * handler for kEventWindowGetIdealSize to return the ideal size for
   * your document windows.
   */
  kHICommandZoomWindow          = 'zoom',

  /*
   * The active window should be minimized. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandMinimizeWindow      = 'mini',

  /*
   * All collapsable windows should be minimized. The Window Manager
   * will respond to this event automatically; your application does
   * not need to handle it.
   */
  kHICommandMinimizeAll         = 'mina',

  /*
   * The active window should be maximized. Only sent on Mac OS 9. The
   * Window Manager will respond to this event automatically; your
   * application does not need to handle it.
   */
  kHICommandMaximizeWindow      = 'maxi',

  /*
   * All collapsable windows should be maximized. The Window Manager
   * will respond to this event automatically; your application does
   * not need to handle it.
   */
  kHICommandMaximizeAll         = 'maxa',

  /*
   * All document-class windows should be arranged in a stack. The
   * Window Manager will respond to this event automatically; your
   * application does not need to handle it.
   */
  kHICommandArrangeInFront      = 'frnt',

  /*
   * All windows of this application should be brought in front of
   * windows from other applications. Only sent on Mac OS X. The Window
   * Manager will respond to this event automatically; your application
   * does not need to handle it.
   */
  kHICommandBringAllToFront     = 'bfrt',

  /*
   * This command ID is used as a placeholder to mark the separator
   * item dividing the Zoom/Minimize/Maximize/Arrange menu items in the
   * standard Window menu from the menu items listing the visible
   * windows. If you need to add your own menu items to the standard
   * Window menu before the window list section, you can look for the
   * menu item with this command ID using GetIndMenuItemWithCommandID,
   * and insert your menu items before the item with this ID.
   */
  kHICommandWindowListSeparator = 'wldv',

  /*
   * This command ID is used as a placeholder to mark the end of the
   * window list section of the standard Window menu. If you need to
   * add your own menu items to the standard Window menu after the
   * window list section, you can look for the menu item with this
   * command ID using GetIndMenuItemWithCommandID, and insert your
   * items after the item with this ID.
   */
  kHICommandWindowListTerminator = 'wlst',

  /*
   * A window in the standard Window menu has been selected and should
   * be activated. In Mac OS X 10.3, this command is also sent by the
   * toolbox whenever it needs to activate a window in your
   * application; for example, it is used when a window is selected
   * from the application's Dock menu, and when a window that uses the
   * standard window event handler is clicked. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandSelectWindow        = 'swin',

  /*
   * The Rotate Windows hotkey (cmd-~ by default) has been pressed, and
   * non-floating windows should be rotated so that the window after
   * the active window is activated. The Window Manager will respond to
   * this event automatically; your application does not need to handle
   * it.
   */
  kHICommandRotateWindowsForward = 'rotw',

  /*
   * The Rotate Windows hotkey (cmd-~ by default) has been pressed, and
   * non-floating windows should be rotated so that the window before
   * the active window is activated. The Window Manager will respond to
   * this event automatically; your application does not need to handle
   * it.
   */
  kHICommandRotateWindowsBackward = 'rotb',

  /*
   * The floating window focus hotkey (ctl-F6 by default) has been
   * pressed, and floating windows should be rotated so that the window
   * after the focused window is activated. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandRotateFloatingWindowsForward = 'rtfw',

  /*
   * The floating window focus hotkey (ctl-F6 by default) has been
   * pressed, and floating windows should be rotated so that the window
   * before the focused window is activated. The Window Manager will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandRotateFloatingWindowsBackward = 'rtfb',

  /*
   * The About menu item has been selected.
   */
  kHICommandAbout               = 'abou',

  /*
   * A new document or item should be created.
   */
  kHICommandNew                 = 'new ',

  /*
   * The user wants to open an existing document.
   */
  kHICommandOpen                = 'open',

  /*
   * The active window should be closed.
   */
  kHICommandClose               = 'clos',

  /*
   * The active document should be saved.
   */
  kHICommandSave                = 'save',

  /*
   * The user wants to save the active document under a new name.
   */
  kHICommandSaveAs              = 'svas',

  /*
   * The contents of the active document should be reverted to the last
   * saved version.
   */
  kHICommandRevert              = 'rvrt',

  /*
   * The active window should be printed.
   */
  kHICommandPrint               = 'prnt',

  /*
   * The user wants to configure the current page margins, formatting,
   * and print options.
   */
  kHICommandPageSetup           = 'page',

  /*
   * The application�s help book should be displayed. Used by the Help
   * Manager when it adds the "<AppName> Help" menu item to the Help
   * menu. The Help Manager will respond to this event automatically;
   * your application does not need to handle it.
   */
  kHICommandAppHelp             = 'ahlp',

  /*
   * The character palette needs to be shown. Events with this command
   * ID are only generated in Mac OS X 10.3 and later. The toolbox will
   * respond to this event automatically; your application does not
   * need to handle it.
   */
  kHICommandShowCharacterPalette = 'chrp'
};


/*
 *  Summary:
 *    Values for the attributes field of the HICommand and
 *    HICommandExtended structures.
 *  
 *  Discussion:
 *    These bit masks are mutually exclusive; only one should be set at
 *    any given time. Some HICommand and HICommandExtended structures
 *    will have an attributes value of zero; in this case, there is no
 *    information available about the source of the command.
 */
enum {

  /*
   * Indicates that the command originates from a menu item. The
   * HICommand.menu and HICommandExtended.source.menu fields are valid.
   */
  kHICommandFromMenu            = (1L << 0),

  /*
   * Indicates that the command originates from a control. The
   * HICommandExtended.source.control field is valid.
   */
  kHICommandFromControl         = (1L << 1),

  /*
   * Indicates that the command originates from a window. The
   * HICommandExtended.source.window field is valid.
   */
  kHICommandFromWindow          = (1L << 2)
};

struct HICommand {
  UInt32              attributes;
  UInt32              commandID;
  struct {
    MenuRef             menuRef;
    MenuItemIndex       menuItemIndex;
  }                       menu;
};
typedef struct HICommand                HICommand;
struct HICommandExtended {
  UInt32              attributes;
  UInt32              commandID;
  union {
    ControlRef          control;
    WindowRef           window;
    struct {
      MenuRef             menuRef;
      MenuItemIndex       menuItemIndex;
    }                       menu;
  }                       source;
};
typedef struct HICommandExtended        HICommandExtended;
/*��������������������������������������������������������������������������������������*/
/*  Control Events                                                                      */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassControl quick reference:
  
    // lifespan
    kEventControlInitialize                     = 1000,
    kEventControlDispose                        = 1001,
    kEventControlGetOptimalBounds               = 1003,
    kEventControlDefInitialize                  = kEventControlInitialize,
    kEventControlDefDispose                     = kEventControlDispose,
    
    // event handling
    kEventControlHit                            = 1,
    kEventControlSimulateHit                    = 2,
    kEventControlHitTest                        = 3,
    kEventControlDraw                           = 4,
    kEventControlApplyBackground                = 5,
    kEventControlApplyTextColor                 = 6,
    kEventControlSetFocusPart                   = 7,
    kEventControlGetFocusPart                   = 8,
    kEventControlActivate                       = 9,
    kEventControlDeactivate                     = 10,
    kEventControlSetCursor                      = 11,
    kEventControlContextualMenuClick            = 12,
    kEventControlClick                          = 13,
    kEventControlGetNextFocusCandidate          = 14,
    kEventControlGetAutoToggleValue             = 15,
    kEventControlInterceptSubviewClick          = 16,
    kEventControlGetClickActivation             = 17,
    kEventControlDragEnter                      = 18,
    kEventControlDragWithin                     = 19,
    kEventControlDragLeave                      = 20,
    kEventControlDragReceive                    = 21,
    kEventControlInvalidateForSizeChange        = 22,
%   kEventControlTrackingAreaEntered            = 23,   // in private header
%   kEventControlTrackingAreaExited             = 24,   // in private header

    // tracking
    kEventControlTrack                          = 51,
    kEventControlGetScrollToHereStartPoint      = 52,
    kEventControlGetIndicatorDragConstraint     = 53,
    kEventControlIndicatorMoved                 = 54,
    kEventControlGhostingFinished               = 55,
    kEventControlGetActionProcPart              = 56,
    
    // accessors
    kEventControlGetPartRegion                  = 101,
    kEventControlGetPartBounds                  = 102,
    kEventControlSetData                        = 103,
    kEventControlGetData                        = 104,
    kEventControlGetSizeConstraints             = 105,
    kEventControlGetFrameMetrics                = 106,
    
    // notification
    %% NOTE: some values in this range may already be taken. Look for kEventControl in ControlsPriv.i
    kEventControlValueFieldChanged              = 151,
    kEventControlAddedSubControl                = 152,
    kEventControlRemovingSubControl             = 153,
    kEventControlBoundsChanged                  = 154,
    kEventControlVisibilityChanged              = 157,
    kEventControlTitleChanged                   = 158,
    kEventControlOwningWindowChanged            = 159,  
    kEventControlHiliteChanged                  = 160,
    kEventControlEnabledStateChanged            = 161,
    kEventControlLayoutInfoChanged              = 162,
    
    // miscellaneous
    kEventControlArbitraryMessage               = 201
*/

/*
 *  kEventClassControl / kEventControlClick
 *  
 *  Summary:
 *    A mouse down event occurred over a control.
 *  
 *  Discussion:
 *    This event is sent when a non-contextual-menu click occurs over a
 *    control; a contextual menu click generates
 *    kEventControlContextualMenuClick instead.
 *    
 *    The handler of this event is responsible for two things: first,
 *    the handler must set the keyboard focus to the control if the
 *    control takes focus on clicks; look for the
 *    kControlGetsFocusOnClick feature bit and call an API such as
 *    SetKeyboardFocus. Second, the handler must call one of the
 *    control tracking APIs: HIViewClick, HandleControlClick, or
 *    TrackControl. The standard window handler does both of these
 *    things.
 *    
 *    Warning: Beware of handling kEventControlClick events! This is
 *    usually NOT the event you really want to handle.
 *    kEventControlClick is a request to "please click this control,"
 *    not "allow a control definition to track the mouse." If you are
 *    implementing or overriding a control definition�s or HIView�s
 *    support for tracking the mouse, you should handle
 *    kEventControlTrack instead.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in global coordinates.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventControlClick            = 13
};

/*
 *  kEventClassControl / kEventControlHit
 *  
 *  Summary:
 *    Sent by TrackControl and HandleControlClick after handling a
 *    click in a control.
 *  
 *  Discussion:
 *    This event indicates that a control has been manipulated by the
 *    user and that the user released the mouse button over some part
 *    of the control. It is sent automatically by the Control Manager
 *    when the control tracking code returns a non-zero part
 *    code.
 *    
 *    You might want to handle this event in a custom control
 *    definition if your control definition has special behavior after
 *    the control has been tracked. You can also handle this event in
 *    application code, to be notified after a control has been
 *    tracked; however, from the application level, it is generally
 *    preferred to provide a command ID for the control and handle
 *    kEventCommandProcess instead of kEventControlHit. Handling
 *    kEventCommandProcess is more generic and allows the same code to
 *    handle events from both controls and menu items.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was tracked.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part that the mouse was over when it was
 *          released.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the mouse was
 *          released.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 */
enum {
  kEventControlHit              = 1
};

/*
 *  kEventClassControl / kEventControlInitialize
 *  
 *  Summary:
 *    Allows the control to initialize private data.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is being created.
 *    
 *    --> kEventParamInitCollection (in, typeCollection)
 *          Initialization data supplied to CreateCustomControl.
 *    
 *    <-- kEventParamControlFeatures (out, typeUInt32)
 *          On exit, your event handler should supply the control
 *          features flags. NOTE: On Mac OS X 10.3 and later, this is
 *          deprecated in favor of using the HIViewChangeFeatures API.
 *          Instead of supplying this parameter, just call
 *          HIViewChangeFeatures. Also, this parameter can only be used
 *          to supply features for the original kControlFoo features,
 *          not the new kHIViewFoo features.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlInitialize       = 1000
};

/*
 *  kEventClassControl / kEventControlDispose
 *  
 *  Summary:
 *    Allows the control to dispose of private data.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is being destroyed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDispose          = 1001
};

/*
 *  kEventClassControl / kEventControlGetOptimalBounds
 *  
 *  Summary:
 *    Allows the control to report its best size and its text baseline
 *    based on its current settings.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose optimal bounds to return.
 *    
 *    <-- kEventParamControlOptimalBounds (out, typeHIRect)
 *          On exit, contains the control�s optimal bounds.
 *    
 *    <-- kEventParamControlOptimalBaselineOffset (out, typeShortInteger)
 *          On exit, contains the control�s optimal baseline offset:
 *          the distance from the top of the control�s optimal bounds
 *          to the baseline of the control text, if any. This parameter
 *          is optional and does not need to be provided if it doesn�t
 *          apply for your control.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetOptimalBounds = 1003
};

/*
 *  kEventClassControl / kEventControlSimulateHit
 *  
 *  Summary:
 *    Sent when your control should simulate a click in response to
 *    some other action, such as a return key for a default button.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which a hit should be simulated.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that should be used for the
 *          simulated hit.
 *    
 *    <-> kEventParamControlPart (in/out, typeControlPartCode)
 *          On entry, contains the part code for which the control
 *          should simulate a hit. On exit, the control may modify this
 *          parameter to reflect the same sort of part code that it
 *          would pass back while handling kEventControlTrack.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlSimulateHit      = 2
};

/*
 *  kEventClassControl / kEventControlHitTest
 *  
 *  Summary:
 *    Sent when someone wants to find out what part of your control is
 *    at a given point in local coordinates.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control to hit-test.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The point to hit-test. For controls in non-compositing
 *          windows, this coordinate is in local coordinates of the
 *          owning window; for controls in compositing windows, this
 *          coordinate is in view-local coordinates.
 *    
 *    <-- kEventParamControlPart (out, typeControlPartCode)
 *          On exit, contains the part code of the control part that
 *          was hit, or kControlNoPart if no part was hit.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlHitTest          = 3
};

/*
 *  kEventClassControl / kEventControlDraw
 *  
 *  Summary:
 *    Sent when your control should draw itself. The event can
 *    optionally contain a port in which to draw and a part to
 *    constrain drawing to.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control to be drawn.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part code to draw. This parameter is optional
 *          and may not be present in all instances of this event. Draw
 *          the entire control if the parameter is not present.
 *    
 *    --> kEventParamGrafPort (in, typeGrafPtr)
 *          The GrafPort into which to draw the control. This parameter
 *          is optional and may not be present in all instances of this
 *          event. Draw into the current port if the parameter is not
 *          present.
 *    
 *    --> kEventParamRgnHandle (in, typeQDRgnHandle)
 *          A region describing the area that needs to be redrawn; you
 *          may constrain your drawing to this region. This parameter
 *          is only provided on Mac OS X 10.2 and later, and only in
 *          certain situations in compositing mode (when the view is
 *          visible, etc). Draw the entire control if the parameter is
 *          not present.
 *    
 *    --> kEventParamCGContextRef (in, typeCGContextRef)
 *          The CGContext into which to draw the control. This
 *          parameter is only provided on Mac OS X 10.2 and later, and
 *          only when the owning window uses compositing mode. The
 *          context is already transformed and clipped appropriately
 *          for view-local drawing. If this parameter is present, you
 *          should always use it; this will be extremely important to
 *          allow printing of controls. If this parameter is not
 *          present (prior to Mac OS X 10.2, or in a non-compositing
 *          window), and you want to draw with CoreGraphics, you can
 *          create your own CGContext with QDBeginCGContext.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDraw             = 4
};

/*
 *  kEventClassControl / kEventControlApplyBackground
 *  
 *  Summary:
 *    Sent when your control should apply its background color or
 *    pattern to the specified port so that subcontrols of this control
 *    can properly erase.
 *  
 *  Discussion:
 *    This event is used for non-composited control drawing. When an
 *    embedded control in a non-composited window draws, it first
 *    erases its bounding rect. Before calling EraseRect or EraseRgn,
 *    the control calls SetUpControlBackground, which sends this event
 *    to parent controls of the embedded control that have the
 *    kControlHasSpecialBackground feature flag. An embedding control
 *    may respond to this event by setting the background color or
 *    pattern of the specified GrafPort; this color or pattern will
 *    then be used by the embedded control when it erases its
 *    bounds.
 *    
 *    Note that an embedding control should not actually draw its
 *    background in response to this event; doing so would not have any
 *    effect, because the embedded control will erase any drawing
 *    shortly anyways.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control which should apply a background color or
 *          pattern.
 *    
 *    --> kEventParamControlSubControl (in, typeControlRef)
 *          The subcontrol that is about to draw.
 *    
 *    --> kEventParamControlDrawDepth (in, typeShortInteger)
 *          The bit depth of the GDevice on which the subcontrol will
 *          be drawn.
 *    
 *    --> kEventParamControlDrawInColor (in, typeBoolean)
 *          Whether the GDevice on which the subcontrol will be drawn
 *          is in color or black & white.
 *    
 *    --> kEventParamGrafPort (in, typeGrafPtr)
 *          The port to which the background color or pattern should be
 *          applied. This parameter is optional and may not be present
 *          in all instances of this event. Apply the background to the
 *          current port if this parameter is not present.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlApplyBackground  = 5
};

/*
 *  kEventClassControl / kEventControlApplyTextColor
 *  
 *  Summary:
 *    Sent when your control should apply a color or pattern to the
 *    specified port and context so a subcontrol can draw text which
 *    looks appropriate for your control�s background.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control which should apply a text color.
 *    
 *    --> kEventParamControlSubControl (in, typeControlRef)
 *          The subcontrol that is about to draw.
 *    
 *    --> kEventParamControlDrawDepth (in, typeShortInteger)
 *          The bit depth of the GDevice on which the subcontrol will
 *          be drawn.
 *    
 *    --> kEventParamControlDrawInColor (in, typeBoolean)
 *          Whether the GDevice on which the subcontrol will be drawn
 *          is in color or black & white.
 *    
 *    --> kEventParamCGContextRef (in, typeCGContextRef)
 *          The CGContext to which the text color should be applied.
 *          This parameter is optional and may not be present in all
 *          instances of this event.
 *    
 *    --> kEventParamGrafPort (in, typeGrafPtr)
 *          The GrafPort to which the text color should be applied.
 *          This parameter is optional and may not be present in all
 *          instances of this event. Apply to the current port if this
 *          parameter is not present.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlApplyTextColor   = 6
};

/*
 *  kEventClassControl / kEventControlGetNextFocusCandidate
 *  
 *  Summary:
 *    Sent so that a given control can customize the focus order of its
 *    subcontrols.
 *  
 *  Discussion:
 *    The recipient will receive a start subcontrol in the
 *    kEventParamStartControl parameter and a focusing direction in the
 *    kEventParamControlPart parameter. You must only pass back
 *    subcontrols of yourself (or NULL) when receiving this event; if
 *    you do otherwise, the Control Manager�s behavior is undefined.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control which should customize the focus order.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          A focusing meta-part code, either kControlFocusNextPart or
 *          kControlFocusPrevPart.
 *    
 *    --> kEventParamStartControl (in, typeControlRef)
 *          On exit, should contain the next or previous subcontrol; if
 *          there is no next subcontrol in the given focusing
 *          direction, the recipient must either exclude the
 *          kEventParamNextControl parameter or set it to NULL
 *    
 *    <-- kEventParamNextControl (out, typeControlRef)
 *          The starting point from which to search for the next or
 *          previous control. This parameter is optional and may not be
 *          present in all instances of this event. Find the first
 *          subcontrol in the appropriate focusing direction if this
 *          parameter is not present or if it contains NULL.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetNextFocusCandidate = 14
};

/*
 *  kEventClassControl / kEventControlGetAutoToggleValue
 *  
 *  Summary:
 *    This event is sent when the Control Manager is about to
 *    autotoggle a control. You can specify the toggled value to use
 *    based on the current value of your control.
 *  
 *  Discussion:
 *    The Control Manager provides default behavior for this event. If
 *    the event is not handled by a control, the default handler
 *    automatically provides this mapping: if the control�s value is 1,
 *    the toggled value is 0. If the control�s value is any other
 *    value, the toggled value is 1.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is being toggled.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part that is being toggled.
 *    
 *    <-- kEventParamControlValue (out, typeLongInteger)
 *          On exit, contains the new control value.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetAutoToggleValue = 15
};

/*
 *  kEventClassControl / kEventControlInterceptSubviewClick
 *  
 *  Summary:
 *    This is sent when the HIViewGetViewForMouseEvent API is called,
 *    to allow embedding controls to intercept clicks in the their
 *    embedded controls.
 *  
 *  Discussion:
 *    The Control Manager sends this event before descending into any
 *    subviews. Controls can override this to intercept clicks which
 *    would normally be destined for their children. For example, the
 *    HIToolbar control intercepts cmd-clicks to handle dragging its
 *    children. To accomplish this, it overrides this event, looking
 *    for the command key modifier. When the command key is pressed,
 *    the view just returns noErr as the result from its event handler.
 *    This tells the Control Manager to stop descending and return the
 *    view that it called as the mouse event destination.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control containing the mouse.
 *    
 *    --> kEventParamEventRef (in, typeEventRef)
 *          The mouse-down event to intercept.
 *  
 *  Result:
 *    An operating system result code. Return noErr to indicate that
 *    this view intercepted the click, or eventNotHandledErr to allow
 *    subviews of this view to take the click.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlInterceptSubviewClick = 16
};

/*
 *  kEventClassControl / kEventControlGetClickActivation
 *  
 *  Summary:
 *    Sent when a click occurs in a inactive window. Allows the control
 *    to determine whether the window should be activated and whether
 *    the click should be handled.
 *  
 *  Discussion:
 *    This is very much like the window class version of this event.
 *    The difference is that the mouse location is view- or
 *    port-relative. This event is actually a copy of the mouse down
 *    event, and so it has all the parameters that such an event would
 *    have (modifiers, button number, etc.).
 *    
 *    When handling a click, this event is sent first, and is sent only
 *    to the control that was clicked; it is not propagated to the
 *    embedder of the clicked control. If the event is not handled,
 *    then a kEventWindowGetClickActivation event is sent to the window
 *    that was clicked.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was clicked.
 *    
 *    <-- kEventParamClickActivation (out, typeClickActivationResult)
 *          On exit, indicates how the click should be handled. Should
 *          be set a ClickActivationResult constant from Controls.h.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The mouse location, in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not.
 *    
 *    --> kEventParamWindowRef (in, typeWindowRef)
 *          The window under the mouse.
 *    
 *    --> kEventParamWindowMouseLocation (in, typeHIPoint)
 *          The window-relative position of the mouse in the window
 *          given in the kEventParamWindowRef parameter. 0,0 is at the
 *          top left of the structure of the window.
 *    
 *    --> kEventParamWindowPartCode (in, typeWindowPartCode)
 *          The part code the mouse location hit in the window. This
 *          parameter only exists if the windowRef parameter exists.
 *          This saves you the trouble of calling FindWindow, which is
 *          expensive on Mac OS X as it needs to call the Window
 *          Server. Available in Mac OS X 10.3 and later.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The keyboard modifiers that were pressed when the event was
 *          generated.
 *    
 *    --> kEventParamMouseButton (in, typeMouseButton)
 *          Which mouse button was pressed.
 *    
 *    --> kEventParamClickCount (in, typeUInt32)
 *          Whether this is a single click, double click, etc.
 *    
 *    --> kEventParamMouseChord (in, typeUInt32)
 *          Which other mouse buttons were pressed when the event was
 *          generated. Available on Mac OS X only.
 *    
 *    --> kEventParamTabletEventType (in, typeUInt32)
 *          The type of tablet event which generated this mouse event;
 *          contains either kEventTabletPoint or kEventTabletProximity.
 *          Only present if the event was generated from a tablet.
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletPoint.
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Further information about the tablet event which generated
 *          this mouse event. Present if the the
 *          kEventParamTabletEventType parameter contains
 *          kEventTabletProximity.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetClickActivation = 17
};

/*
 *  kEventClassControl / kEventControlDragEnter
 *  
 *  Summary:
 *    A drag has entered your control.
 *  
 *  Discussion:
 *    If you at all wish to handle the drag, you must return true in
 *    the kEventParamControlWouldAcceptDrop parameter from your event
 *    handler in response to this event. If you return
 *    eventNotHandledErr, do not supply a
 *    kEventParamControlWouldAcceptDrop parameter, or set its value to
 *    false, you will not receive 'within' or 'leave' messages, nor
 *    will you be eligible to receive the drop. This is done to try to
 *    be as efficient as possible when sending events during the drag
 *    operation.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is the drag target.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef for the drag.
 *    
 *    <-- kEventParamControlWouldAcceptDrop (out, typeBoolean)
 *          The control would accept the drop. Return true in this
 *          parameter if your view wants to track and possibly receive
 *          this drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDragEnter        = 18
};

/*
 *  kEventClassControl / kEventControlDragWithin
 *  
 *  Summary:
 *    A drag has moved with your airspace (but not on any subcontrol).
 *  
 *  Discussion:
 *    Your control will typically respond to this event by drawing its
 *    drag highlight. If the user moves into a subcontrol, it becomes
 *    the target of the drag and your control will not receive 'within'
 *    messages any longer.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is the drag target.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef for the drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDragWithin       = 19
};

/*
 *  kEventClassControl / kEventControlDragLeave
 *  
 *  Summary:
 *    A drag is leaving your view.
 *  
 *  Discussion:
 *    Your control will typically respond to this event by removing its
 *    drag highlight.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is the drag target.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef for the drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDragLeave        = 20
};

/*
 *  kEventClassControl / kEventControlDragReceive
 *  
 *  Summary:
 *    Congratulations, you are the lucky recipient of a drag. Enjoy it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is the drag target.
 *    
 *    --> kEventParamDragRef (in, typeDragRef)
 *          The DragRef for the drag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDragReceive      = 21
};

/*
 *  kEventClassControl / kEventControlSetFocusPart
 *  
 *  Summary:
 *    Sent when your control is gaining, losing, or changing the focus.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is gaining, losing, or changing focus.
 *    
 *    --> kEventParamControlFocusEverything (in, typeBoolean)
 *          Indicates whether to allowing focusing on a part that
 *          doesn�t accept general keyboard input, such as a push
 *          button, or if only traditionally focusable parts such as
 *          edit fields and list boxes should be allowed to gain focus.
 *          This parameter is optional and may not be present in all
 *          instances of this event. Restrict focus to traditionally
 *          focusable parts if this parameter is not present.
 *    
 *    <-> kEventParamControlPart (in/out, typeControlPartCode)
 *          On entry, a part code that may be either an actual control
 *          part or a control focus meta-part. This parameter may be
 *          one of kControlFocusNoPart (if the control is losing
 *          focus), kControlFocusNextPart (if the next part in the
 *          control should be focused), kControlFocusPrevPart (if the
 *          previous part in the control should be focused), or an
 *          actual control part (if that specific part should be
 *          focused). On exit, your event handler should store the
 *          actual part code that was focused into this parameter. Your
 *          control must always allow the focus to be removed (when
 *          this parameter is kControlFocusNoPart on entry).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlSetFocusPart     = 7
};

/*
 *  kEventClassControl / kEventControlGetFocusPart
 *  
 *  Summary:
 *    Sent when your the Control Manager wants to know what part of
 *    your control is currently focused. Set the kEventParamControlPart
 *    param to your currently focused part.
 *  
 *  Discussion:
 *    The Control Manager provides default behavior for this event. If
 *    the event is not handled by a control, the default handler
 *    returns the part of the control that was most recently focused.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which to get the current focus.
 *    
 *    <-- kEventParamControlPart (out, typeControlPartCode)
 *          On exit, contains the current focus for this control.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetFocusPart     = 8
};

/*
 *  kEventClassControl / kEventControlActivate
 *  
 *  Summary:
 *    Sent when your control becomes active as a result of a call to
 *    ActivateControl.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was activated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlActivate         = 9
};

/*
 *  kEventClassControl / kEventControlDeactivate
 *  
 *  Summary:
 *    Sent when your control becomes inactive as a result of a call to
 *    DeactivateControl.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was deactivated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlDeactivate       = 10
};

/*
 *  kEventClassControl / kEventControlSetCursor
 *  
 *  Summary:
 *    Sent when your control is asked to change the cursor as a result
 *    of a call to HandleControlSetCursor.
 *  
 *  Discussion:
 *    Note that the standard window event handler does not call
 *    HandleControlSetCursor, and therefore, your control will not
 *    ordinarily receive this event. Your host application must call
 *    HandleControlSetCursor itself in order for your control to
 *    receive this event. On Mac OS X 10.2 and later, we recommend
 *    using mouse tracking regions in your control to be notified when
 *    to change the cursor, rather than using this event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that should set the cursor.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location, in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The current keyboard modifiers.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlSetCursor        = 11
};

/*
 *  kEventClassControl / kEventControlContextualMenuClick
 *  
 *  Summary:
 *    Sent when your control is asked to display a contextual menu as a
 *    result of a call to HandleControlContextualMenuClick.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was clicked.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location, in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlContextualMenuClick = 12
};

/*
 *  kEventClassControl / kEventControlTrack
 *  
 *  Summary:
 *    Sent to allow a control definition to track the mouse in response
 *    to a call to HIViewClick, HandleControlClick, etc.
 *  
 *  Discussion:
 *    In fact, this event is actually sent from within HIViewClick and
 *    HandleControlClick. The default handling of this event is the
 *    Control Manager�s normal tracking logic; this is good enough for
 *    simple controls (such as push buttons) and controls with simple
 *    indicators (such as scroll bars and sliders). You should only
 *    need to handle or override this event if you are trying to do
 *    more complex tracking, such as displaying a menu in the middle of
 *    tracking.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control to track.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location, in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not.
 *    
 *    <-> kEventParamKeyModifiers (in/out, typeUInt32)
 *          The current keyboard modifiers. On exit, the event handler
 *          may update this parameter with the modifiers that were
 *          pressed when tracking ended; these modifiers will be
 *          included in the kEventCommandProcess event that is sent by
 *          the Control Manager.
 *    
 *    --> kEventParamControlAction (in, typeControlActionUPP)
 *          The control action proc that should be called by the
 *          control during tracking.
 *    
 *    <-- kEventParamControlPart (out, typeControlPartCode)
 *          On exit, contains the part code of the control part that
 *          was selected when tracking ended, or kControlNoPart if no
 *          part was selected. If the part code is non-zero, the
 *          Control Manager will automatically send kEventControlHit
 *          and kEventCommandProcess events.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlTrack            = 51
};

/*
 *  kEventClassControl / kEventControlGetScrollToHereStartPoint
 *  
 *  Summary:
 *    Sent so your control can support Scroll To Here behavior during
 *    tracking.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which to retrieve the Scroll To Here point.
 *    
 *    <-> kEventParamMouseLocation (in/out, typeQDPoint)
 *          On entry, a point in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not, which provides the location at which
 *          the user clicked to request Scroll To Here behavior. On
 *          exit, this parameter should contain the mouse location in
 *          view-local or port-local coordinates where a click would
 *          have needed to be to cause your indicator to be dragged to
 *          the incoming mouse location.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The current keyboard modifiers.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetScrollToHereStartPoint = 52
};

/*
 *  kEventClassControl / kEventControlGetIndicatorDragConstraint
 *  
 *  Summary:
 *    Sent so your control can constrain the movement of its indicator
 *    during tracking.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is being tracked.
 *    
 *    --> kEventParamMouseLocation (in, typeQDPoint)
 *          The mouse location, in view-local coordinates if the
 *          control�s owning window is composited, or port-local
 *          coordinates if not.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The current keyboard modifiers.
 *    
 *    <-- kEventParamControlIndicatorDragConstraint (out, typeIndicatorDragConstraint)
 *          On exit, contains an IndicatorDragConstraint structure.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetIndicatorDragConstraint = 53
};

/*
 *  kEventClassControl / kEventControlIndicatorMoved
 *  
 *  Summary:
 *    Sent during live-tracking of the indicator so your control can
 *    update its value based on the new indicator position. During
 *    non-live tracking, this event lets you redraw the indicator ghost
 *    at the appropriate place.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is being tracked.
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The new indicator region.
 *    
 *    --> kEventParamControlIndicatorRegion (in, typeQDRgnHandle)
 *          Indicates whether the control is using non-live-tracking
 *          (true) or live tracking (false).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlIndicatorMoved   = 54
};

/*
 *  kEventClassControl / kEventControlGhostingFinished
 *  
 *  Summary:
 *    Sent at the end of non-live indicator tracking so your control
 *    can update its value based on the final ghost location.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that was being tracked.
 *    
 *    --> kEventParamControlIndicatorOffset (in, typeQDPoint)
 *          The final offset of the indicator.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGhostingFinished = 55
};

/*
 *  kEventClassControl / kEventControlGetActionProcPart
 *  
 *  Summary:
 *    Sent during tracking so your control can alter the part that is
 *    passed to its action proc based on modifier keys, etc.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control being tracked.
 *    
 *    --> kEventParamKeyModifiers (in, typeUInt32)
 *          The current keyboard modifiers.
 *    
 *    <-> kEventParamControlPart (in/out, typeControlPartCode)
 *          On entry, the proposed control part that will be sent to
 *          the action proc. Your handler may modify this parameter
 *          based on its own criteria (which modifier keys are pressed,
 *          for example).
 *    
 *    <-- kEventParamControlPartAutoRepeats (out, typeBoolean)
 *          On output, a flag to the standard control tracking loop in
 *          the Control Manager indicating whether to autorepeat when
 *          the user presses and holds on certain parts of your custom
 *          control. The autorepeat timing curve is the same as that
 *          used for the buttons/page areas of scroll bars. This
 *          parameter is observed by the Control Manager in Mac OS X
 *          10.2 and later.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetActionProcPart = 56
};

/*
 *  kEventClassControl / kEventControlGetPartRegion
 *  
 *  Summary:
 *    Sent by the GetControlRegion API when a client wants to get a
 *    particular region of your control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose region to return.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part code whose region to return.
 *    
 *    --> kEventParamControlRegion (in, typeQDRgnHandle)
 *          A pre-allocated RgnHandle. Your handler should get the
 *          RgnHandle from the event and set the region contents
 *          appropriately.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetPartRegion    = 101
};

/*
 *  kEventClassControl / kEventControlGetPartBounds
 *  
 *  Summary:
 *    Sent when a client wants to get a particular rectangle of your
 *    control when it may be more efficient than asking for a region.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose bounds to return.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part whose bounds to return.
 *    
 *    <-- kEventParamControlPartBounds (out, typeHIRect)
 *          On exit, contains the bounds of the specified part.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetPartBounds    = 102
};

/*
 *  kEventClassControl / kEventControlSetData
 *  
 *  Summary:
 *    Sent by the SetControlData API when a client wants to change an
 *    arbitrary setting of your control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which to set data.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part for which to set data.
 *    
 *    --> kEventParamControlDataTag (in, typeEnumeration)
 *          The type of data to set.
 *    
 *    --> kEventParamControlDataBuffer (in, typePtr)
 *          A pointer to the data.
 *    
 *    --> kEventParamControlDataBufferSize (in, typeLongInteger)
 *          The size of the data.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlSetData          = 103
};

/*
 *  kEventClassControl / kEventControlGetData
 *  
 *  Summary:
 *    Sent by the GetControlData API when a client wants to get an
 *    arbitrary setting of your control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control from which to get data.
 *    
 *    --> kEventParamControlPart (in, typeControlPartCode)
 *          The control part for which to get data.
 *    
 *    --> kEventParamControlDataTag (in, typeEnumeration)
 *          The type of data to get.
 *    
 *    --> kEventParamControlDataBuffer (in, typePtr)
 *          A buffer in which to write the data.
 *    
 *    <-> kEventParamControlDataBufferSize (in/out, typeLongInteger)
 *          On entry, the size of the data buffer. On exit, the amount
 *          of data that was available.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetData          = 104
};

/*
 *  kEventClassControl / kEventControlGetSizeConstraints
 *  
 *  Summary:
 *    Sent by the HIViewGetSizeConstraints API to allow your custom
 *    control/view to specify its minimum and maximum size.
 *  
 *  Discussion:
 *    This is different from the optimal size event above. The optimal
 *    size might be larger than a view�s minimum size. A parent view
 *    can use this information to help it lay out subviews. The toolbar
 *    control uses this information to help lay out toolbar items, for
 *    example.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which to get size constraints.
 *    
 *    <-- kEventParamMinimumSize (out, typeHISize)
 *          On exit, contains the control�s minimum size.
 *    
 *    <-- kEventParamMaximumSize (out, typeHISize)
 *          On exit, contains the control�s maximum size.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetSizeConstraints = 105
};

/*
 *  kEventClassControl / kEventControlGetFrameMetrics
 *  
 *  Summary:
 *    Sent when a control client needs to determine the width of the
 *    control�s structure region.
 *  
 *  Discussion:
 *    This event is not sent automatically by the Control Manager at
 *    any time, but may be sent by control clients during various
 *    layout operations. For example, the Window Manager will send this
 *    event to a window frame HIView to determine the window structure
 *    widths, and the Menu Manager will send this event to a menu
 *    content view to determine the content structure widths.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control for which to get frame metrics.
 *    
 *    <-- kEventParamControlFrameMetrics (out, typeControlFrameMetrics)
 *          On exit, contains the control�s frame metrics.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlGetFrameMetrics  = 106
};

/*
 *  kEventClassControl / kEventControlValueFieldChanged
 *  
 *  Summary:
 *    Sent when your control�s value, min, max, or view size has
 *    changed. Useful so other entities can watch for changes to your
 *    control�s value.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose value, min, max, or view size has changed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlValueFieldChanged = 151
};

/*
 *  kEventClassControl / kEventControlAddedSubControl
 *  
 *  Summary:
 *    Sent when a control was embedded within your control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that gained a new subcontrol.
 *    
 *    --> kEventParamControlSubControl (in, typeControlRef)
 *          The subcontrol that was added.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlAddedSubControl  = 152
};

/*
 *  kEventClassControl / kEventControlRemovingSubControl
 *  
 *  Summary:
 *    Sent when one of your child controls will be removed from your
 *    control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that will be losing a subcontrol.
 *    
 *    --> kEventParamControlSubControl (in, typeControlRef)
 *          The subcontrol that will be removed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlRemovingSubControl = 153
};

/*
 *  kEventClassControl / kEventControlBoundsChanged
 *  
 *  Summary:
 *    Sent when your control�s bounding rectangle has changed.
 *  
 *  Discussion:
 *    If you want to generate an efficient invalid region in response
 *    to a size change, you need to handle
 *    kEventControlInvalidateForSizeChange.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose bounds have change.
 *    
 *    --> kEventParamAttributes (in, typeUInt32)
 *          Flags indicating how the bounds changed, including
 *          kControlBoundsChangeSizeChanged and
 *          kControlBoundsChangePositionChanged.
 *    
 *    --> kEventParamOriginalBounds (in, typeQDRectangle)
 *          The control�s bounds before the change.
 *    
 *    --> kEventParamPreviousBounds (in, typeQDRectangle)
 *          The control�s bounds before the change.
 *    
 *    --> kEventParamCurrentBounds (in, typeQDRectangle)
 *          The control�s new bounds.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlBoundsChanged    = 154
};

/*
 *  kEventClassControl / kEventControlInvalidateForSizeChange
 *  
 *  Summary:
 *    Sent when a control's size changes so it can invalidate the area
 *    of itself that needs to be redrawn.
 *  
 *  Discussion:
 *    Handle this event by calling HIViewSetNeedsDisplayInRegion with a
 *    region that properly reflects the area of your control that needs
 *    to be redrawn after a size change. The default handler for this
 *    event will invalidate the entire control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose size has changed.
 *    
 *    --> kEventParamOriginalBounds (in, typeQDRectangle)
 *          The control�s bounds before the change.
 *    
 *    --> kEventParamCurrentBounds (in, typeQDRectangle)
 *          The control�s new bounds.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlInvalidateForSizeChange = 22
};

/*
 *  kEventClassControl / kEventControlVisibilityChanged
 *  
 *  Summary:
 *    Sent when a control is hidden or shown. This is here to support
 *    custom views/controls which need to update information when the
 *    visibility changes.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose visibility has changed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlVisibilityChanged = 157
};

/*
 *  kEventClassControl / kEventControlOwningWindowChanged
 *  
 *  Summary:
 *    Sent when your control�s owning window has changed. Useful to
 *    udpate any dependencies that your control has on its owning 
 *    window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose owning window has changed.
 *    
 *    --> kEventParamAttributes (in, typeUInt32)
 *          Currently unused.
 *    
 *    --> kEventParamControlOriginalOwningWindow (in, typeWindowRef)
 *          The control�s original owning window.
 *    
 *    --> kEventParamControlCurrentOwningWindow (in, typeWindowRef)
 *          The control�s new owning window.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlOwningWindowChanged = 159
};

/*
 *  kEventClassControl / kEventControlTitleChanged
 *  
 *  Summary:
 *    Sent when the title of your control changes.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose title has changed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlTitleChanged     = 158
};

/*
 *  kEventClassControl / kEventControlHiliteChanged
 *  
 *  Summary:
 *    Sent when the hilite state changes in a control. This is here to
 *    support custom views/controls which need to update information
 *    when the hilite state changes.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose hilite has changed.
 *    
 *    --> kEventParamControlPreviousPart (in, typeControlPartCode)
 *          The previously hilited part.
 *    
 *    --> kEventParamControlCurrentPart (in, typeControlPartCode)
 *          The newly hilited part.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlHiliteChanged    = 160
};

/*
 *  kEventClassControl / kEventControlEnabledStateChanged
 *  
 *  Summary:
 *    Sent when the enabled state changes in a control. This is here to
 *    support custom views/controls which need to update information
 *    when the enabled state changes.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose enabled state has changed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlEnabledStateChanged = 161
};

/*
 *  kEventClassControl / kEventControlLayoutInfoChanged
 *  
 *  Summary:
 *    Sent when the layout info changes in a control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control whose enabled state has changed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlLayoutInfoChanged = 162
};

/*
 *  kEventClassControl / kEventControlArbitraryMessage
 *  
 *  Summary:
 *    Sent by the SendControlMessage API when someone is trying to send
 *    an old-style CDEF message to your control.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeControlRef)
 *          The control that is receiving the message.
 *    
 *    --> kEventParamControlMessage (in, typeShortInteger)
 *          The message.
 *    
 *    --> kEventParamControlParam (in, typeLongInteger)
 *          The inParam parameter from SendControlMessage.
 *    
 *    <-- kEventParamControlResult (out, typeLongInteger)
 *          On exit, contains the result that should be returned from
 *          SendControlMessage.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventControlArbitraryMessage = 201
};


/*
 *  Summary:
 *    Control bounds change event attributes
 *  
 *  Discussion:
 *    When the toolbox sends out a kEventControlBoundsChanged event, it
 *    also sends along a parameter containing attributes of the event.
 *    These attributes can be used to determine what aspect of the
 *    control changed (position, size, or both).
 */
enum {

  /*
   * The dimensions of the control (width and height) changed.
   */
  kControlBoundsChangeSizeChanged = (1 << 2),

  /*
   * The top left corner (position) changed.
   */
  kControlBoundsChangePositionChanged = (1 << 3)
};

/*��������������������������������������������������������������������������������������*/
/*  Tablet Events (and tablet data in mouse events)                                     */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassTablet quick reference:
  
    kEventTabletPoint                   = 1,
    kEventTabletProximity               = 2,
*/
/*
 *  kEventClassTablet / kEventTabletPoint
 *  
 *  Summary:
 *    Indicates that the pen has moved on or near a tablet.
 *  
 *  Discussion:
 *    Same as deprecated kEventTabletPointer.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTabletPointRec (in, typeTabletPointRec)
 *          Tablet information for the event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTabletPoint             = 1
};

/*
 *  kEventClassTablet / kEventTabletProximity
 *  
 *  Summary:
 *    Indicates that the pen has entered or exited proximity of a
 *    tablet.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamTabletProximityRec (in, typeTabletProximityRec)
 *          Tablet information for the event.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventTabletProximity         = 2
};

struct TabletPointRec {
  SInt32              absX;                   /* absolute x coordinate in tablet space at full tablet resolution */
  SInt32              absY;                   /* absolute y coordinate in tablet space at full tablet resolution */
  SInt32              absZ;                   /* absolute z coordinate in tablet space at full tablet resolution */
  UInt16              buttons;                /* one bit per button - bit 0 is first button - 1 = closed */
  UInt16              pressure;               /* scaled pressure value; MAXPRESSURE=(2^16)-1, MINPRESSURE=0 */
  SInt16              tiltX;                  /* scaled tilt x value; range is -((2^15)-1) to (2^15)-1 (-32767 to 32767) */
  SInt16              tiltY;                  /* scaled tilt y value; range is -((2^15)-1) to (2^15)-1 (-32767 to 32767) */
  UInt16              rotation;               /* Fixed-point representation of device rotation in a 10.6 format */
  SInt16              tangentialPressure;     /* tangential pressure on the device; range same as tilt */
  UInt16              deviceID;               /* system-assigned unique device ID - matches to deviceID field in proximity event */
  SInt16              vendor1;                /* vendor-defined signed 16-bit integer */
  SInt16              vendor2;                /* vendor-defined signed 16-bit integer */
  SInt16              vendor3;                /* vendor-defined signed 16-bit integer */
};
typedef struct TabletPointRec           TabletPointRec;
typedef TabletPointRec                  TabletPointerRec;
struct TabletProximityRec {
  UInt16              vendorID;               /* vendor-defined ID - typically will be USB vendor ID */
  UInt16              tabletID;               /* vendor-defined tablet ID - typically will be USB product ID for the tablet */
  UInt16              pointerID;              /* vendor-defined ID of the specific pointing device */
  UInt16              deviceID;               /* system-assigned unique device ID - matches to deviceID field in tablet event */
  UInt16              systemTabletID;         /* system-assigned unique tablet ID */
  UInt16              vendorPointerType;      /* vendor-defined pointer type */
  UInt32              pointerSerialNumber;    /* vendor-defined serial number of the specific pointing device */
  UInt64              uniqueID;               /* vendor-defined unique ID for this pointer */
  UInt32              capabilityMask;         /* mask representing the capabilities of the device */
  UInt8               pointerType;            /* type of pointing device - enum to be defined */
  UInt8               enterProximity;         /* non-zero = entering; zero = leaving */
};
typedef struct TabletProximityRec       TabletProximityRec;
/*��������������������������������������������������������������������������������������*/
/* Volume Events                                                                        */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassVolume quick reference:

    kEventVolumeMounted             = 1,        // new volume mounted
    kEventVolumeUnmounted           = 2         // volume has been ejected or unmounted
*/
enum {
  typeFSVolumeRefNum            = 'voln' /* FSVolumeRefNum*/
};

/*
 *  kEventClassVolume / kEventVolumeMounted
 *  
 *  Summary:
 *    A new volume has been mounted (or new media inserted).
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeFSVolumeRefNum)
 *          The volume refnum of the volume that was mounted.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventVolumeMounted           = 1
};

/*
 *  kEventClassVolume / kEventVolumeUnmounted
 *  
 *  Summary:
 *    An existing volume has been unmounted (or media ejected).
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamDirectObject (in, typeFSVolumeRefNum)
 *          The volume refnum of the volume that was unmounted. At the
 *          point when this event is sent, this is no longer a valid
 *          volume refnum, and cannot be passed to any File Manager
 *          API; it is useful only for comparison with cached volume
 *          refnums in your own data structures.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3.1 and later
 */
enum {
  kEventVolumeUnmounted         = 2
};

/*��������������������������������������������������������������������������������������*/
/* Appearance Events                                                                    */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassAppearance quick reference:

    kEventAppearanceScrollBarVariantChanged = 1
*/
/*
 *  kEventClassAppearance / kEventAppearanceScrollBarVariantChanged
 *  
 *  Summary:
 *    The scroll bar variant has changed. Available on Mac OS X 10.1
 *    and later.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it on Mac OS X
 *    10.3 and later.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamNewScrollBarVariant (in, typeShortInteger)
 *          The new scroll bar variant.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAppearanceScrollBarVariantChanged = 1
};

/*��������������������������������������������������������������������������������������*/
/*  Services Events                                                                     */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassService quick reference:
    
    Services are a feature by which applications can communicate with
    one another to request and provide services. This communication
    happens either through the Pasteboard or Scrap Manager. When an event is sent that 
    requires communication for processing or servicing a request, 
    you will need to use the pasteboard or scrap given in the kEventParamPasteboardRef and
    kEventParamScrapRef parameters of the event in order to communicate.
    When your app requests a service, it is usually acting on data that is 
    currently selected or in focus. Therefore all of the Services events 
    are sent to the UserFocus event target.
    <BR><BR>
    Service events are available on Mac OS X 10.1 and later.
    
    kEventServiceCopy           = 1,
    kEventServicePaste          = 2,
    kEventServiceGetTypes       = 3,
    kEventServicePerform        = 4
*/
/*
 *  kEventClassService / kEventServiceCopy
 *  
 *  Summary:
 *    The user has invoked a service that requires the application to
 *    update the given pasteboard or scrap in the
 *    kEventParamPasteboardRef and kEventParamScrapRef parameters with
 *    appropriate data from the focus.
 *  
 *  Discussion:
 *    On Mac OS X 10.3 and later, this event includes both a
 *    PasteboardRef and a ScrapRef. A handler for this event should
 *    provide its data using either Pasteboard or Scrap Manager APIs,
 *    and the corresponding pasteboard or scrap reference, depending on
 *    which is more convenient or appropriate. Data only needs to be
 *    placed on one of the pasteboard or scrap; it does not need to be
 *    placed on both. Data written to the pasteboard will also be
 *    available on the scrap, and vice versa.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamPasteboardRef (in, typePasteboardRef)
 *          Data from the current selection should be placed into this
 *          pasteboard. This parameter is provided on Mac OS X 10.3 and
 *          later.
 *    
 *    --> kEventParamScrapRef (in, typeScrapRef)
 *          Data from the current selection should be placed into this
 *          scrap.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventServiceCopy             = 1
};

/*
 *  kEventClassService / kEventServicePaste
 *  
 *  Summary:
 *    The user has invoked a service that requires the application to
 *    update the current focus with data from the pasteboard or scrap
 *    given in the kEventParamPasteboardRef and kEventParamScrapRef
 *    parameters.
 *  
 *  Discussion:
 *    On Mac OS X 10.3 and later, this event includes both a
 *    PasteboardRef and a ScrapRef. A handler for this event should
 *    retrieve its data using either Pasteboard or Scrap Manager APIs,
 *    and the corresponding pasteboard or scrap reference, depending on
 *    which is more convenient or appropriate. Data only needs to be
 *    read from one of the pasteboard or scrap; it does not need to be
 *    read from both. Data available on the pasteboard will also be
 *    available on the scrap, and vice versa.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamPasteboardRef (in, typePasteboardRef)
 *          The current selection should be replaced by data from this
 *          pasteboard. This parameter is provided on Mac OS X 10.3 and
 *          later.
 *    
 *    --> kEventParamScrapRef (in, typeScrapRef)
 *          The current selection should be replaced by data from this
 *          scrap.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventServicePaste            = 2
};

/*
 *  kEventClassService / kEventServiceGetTypes
 *  
 *  Summary:
 *    The Services Manager needs to know what types of data the
 *    application can copy and paste to and from the pasteboard or
 *    scrap in order to update the Services menu to enable items that
 *    the user can select.
 *  
 *  Discussion:
 *    This event sends two CFMutableArrayRefs for the application to
 *    add the types to: the kEventParamServiceCopyTypes and the
 *    kEventParamServicePasteTypes parameters. The types that are added
 *    are CFStringRefs. There is a convenience function,
 *    CreateTypeStringWithOSType, which takes an OSType and will create
 *    a CFStringRef that you can add to the array(s).
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamServiceCopyTypes (in, typeCFMutableArrayRef)
 *          Add CFStringRefs to this array to report the types that can
 *          be copied from the current selection. These strings will be
 *          released automatically after the event is handled.
 *    
 *    --> kEventParamServicePasteTypes (in, typeCFMutableArrayRef)
 *          Add CFStringRefs to this array to report the types that can
 *          be pasted into the currently focused object. These strings
 *          will be released automatically after the event is handled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventServiceGetTypes         = 3
};

/*
 *  kEventClassService / kEventServicePerform
 *  
 *  Summary:
 *    If the application is a service provider, this event will get
 *    sent when a service is requested of the app.
 *  
 *  Discussion:
 *    On Mac OS X 10.3 and later, this event includes both a
 *    PasteboardRef and a ScrapRef. A handler for this event may
 *    provide its data using either Pasteboard or Scrap Manager APIs,
 *    and the corresponding pasteboard or scrap reference, depending on
 *    which is more convenient or appropriate.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamPasteboardRef (in, typePasteboardRef)
 *          The pasteboard that should be used to send and receive data
 *          from the requester. This parameter is only provided on Mac
 *          OS X 10.3 and later.
 *    
 *    --> kEventParamScrapRef (in, typeScrapRef)
 *          The scrap that should be used to send and receive data from
 *          the requester.
 *    
 *    --> kEventParamServiceMessageName (in, typeCFStringRef)
 *          A string with the name of the advertised service that was
 *          invoked.
 *    
 *    --> kEventParamServiceUserData (in, typeCFStringRef)
 *          Extra data provided by the requestor.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventServicePerform          = 4
};

/*
 *  CreateTypeStringWithOSType()
 *  
 *  Discussion:
 *    This routine is used to convert an OSType to a CFStringRef that
 *    services will understand.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inType:
 *      The OSType that needs to be converted to a CFString.
 *  
 *  Result:
 *    A CFStringRef that contains the string that corresponds to the
 *    given OSType. This follows CoreFoundation semantics in that it
 *    will return NULL for failure, and because it is a "Create"
 *    function you will need to CFRelease this string when it is no
 *    longer needed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.1 and later
 *    Non-Carbon CFM:   not available
 */
extern CFStringRef 
CreateTypeStringWithOSType(OSType inType)                     AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;


/*��������������������������������������������������������������������������������������*/
/*  Accessibility Events                                                                */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassAccessibility quick reference:
    
    kEventAccessibleGetChildAtPoint                     =   1,
    kEventAccessibleGetFocusedChild                     =   2,
    
    kEventAccessibleGetAllAttributeNames                =   21,
    kEventAccessibleGetAllParameterizedAttributeNames   =   25,
    kEventAccessibleGetNamedAttribute                   =   22,
    kEventAccessibleSetNamedAttribute                   =   23,
    kEventAccessibleIsNamedAttributeSettable            =   24,
    
    kEventAccessibleGetAllActionNames                   =   41,
    kEventAccessiblePerformNamedAction                  =   42,
    kEventAccessibleGetNamedActionDescription           =   44
*/
/*
 *  kEventClassAccessibility / kEventAccessibleGetChildAtPoint
 *  
 *  Summary:
 *    Finds the child of an accessible object at a given point.
 *  
 *  Discussion:
 *    The kEventParamMouseLocation parameter will contain a global
 *    point. Your handler for this event should find the child of
 *    yourself which is underneath that point and return it in the
 *    kEventParamAccessibleChild parameter.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamMouseLocation (in, typeHIPoint)
 *          The location in global coordinates.
 *    
 *    <-- kEventParamAccessibleChild (out, typeCFTypeRef)
 *          On exit, contains the child of the accessible object at the
 *          specified point, in the form of an AXUIElementRef. If there
 *          is no child at the given point, you should still return
 *          noErr, but leave the parameter empty (do not call
 *          SetEventParameter). Only return immediate children; do not
 *          return grandchildren of yourself.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetChildAtPoint = 1
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetFocusedChild
 *  
 *  Summary:
 *    Finds the focused child of an accessible object.
 *  
 *  Discussion:
 *    Your handler for this event should find the child of itself which
 *    is part of the focus chain and return it in the
 *    kEventParamAccessibleChild parameter.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    <-- kEventParamAccessibleChild (out, typeCFTypeRef)
 *          On exit, contains the focused child of the accessible
 *          object, in the form of an AXUIElementRef. If there is no
 *          child in the focus chain, you should still return noErr,
 *          but leave the parameter empty (do not call
 *          SetEventParameter). Only return immediate children; do not
 *          return grandchildren of yourself.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetFocusedChild = 2
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetAllAttributeNames
 *  
 *  Summary:
 *    Returns the attributes supported by an accessible object. You
 *    must only return the names of your regular (non-parameterized)
 *    attributes via this event. If you support parameterized
 *    attributes, you must return them via the new
 *    kEventAccessibleGetAllParameterizedAttributeNames event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    <-> kEventParamAccessibleAttributeNames (in/out, typeCFMutableArrayRef)
 *          Add each of the regular (non-parameterized) attribute names
 *          supported by the accessible object to this array, as
 *          CFStringRefs.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetAllAttributeNames = 21
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetAllParameterizedAttributeNames
 *  
 *  Summary:
 *    Returns the parameterized attributes supported by an accessible
 *    object. You must not return the names of your regular
 *    (non-parameterized) attributes via this event. If you support
 *    regular attributes, you must return them via the original
 *    kEventAccessibleGetAllAttributeNames event. Parameterized
 *    attributes are introduced in Mac OS X 10.3.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    <-> kEventParamAccessibleAttributeNames (in/out, typeCFMutableArrayRef)
 *          Add each of the parameterized attribute names supported by
 *          the accessible object to this array, as CFStringRefs.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetAllParameterizedAttributeNames = 25
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetNamedAttribute
 *  
 *  Summary:
 *    Returns the value of an attribute of an accessible object.
 *  
 *  Discussion:
 *    The kEventParamAccessibleAttributeName parameter will contain an
 *    attribute name in the form of a CFStringRef. If you support the
 *    named attribute, return the attribute�s value in the
 *    kEventParamAccessibleAttributeValue parameter.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamAccessibleAttributeName (in, typeCFStringRef)
 *          The name of the requested attribute.
 *    
 *    --> kEventParamAccessibleAttributeParameter (in, typeCFTypeRef)
 *          This parameter is optional and will only exist if your
 *          accessible object is being asked for the value of a
 *          parameterized attribute. When present, this event parameter
 *          will contain a CFTypeRef describing the parameters of the
 *          request. Parameterized attributes are introduced in Mac OS
 *          X 10.3.
 *    
 *    <-- kEventParamAccessibleAttributeValue (out, typeCFTypeRef)
 *          On exit, contains the attribute's value. The type of this
 *          parameter varies according to the attribute; it might
 *          typically be typeCFStringRef (for a textual attribute),
 *          typeBoolean (for a boolean attribute), or typeSInt32 (for
 *          an integer-valued attribute).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetNamedAttribute = 22
};

/*
 *  kEventClassAccessibility / kEventAccessibleSetNamedAttribute
 *  
 *  Summary:
 *    Sets the value of an attribute of an accessible object.
 *  
 *  Discussion:
 *    The kEventParamAccessibleAttributeName parameter will contain an
 *    attribute name in the form of a CFStringRef. The
 *    kEventParamAccessibleAttributeValue parameter will contain data
 *    in an arbitrary format. If you support the named attribute, set
 *    the named attribute�s value to the data provided in the event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamAccessibleAttributeName (in, typeCFStringRef)
 *          The name of the requested attribute.
 *    
 *    --> kEventParamAccessibleAttributeValue (in, typeCFTypeRef)
 *          The new value of the attribute. The type of this parameter
 *          varies according to the attribute; it might typically be
 *          typeCFStringRef (for a textual attribute), typeBoolean (for
 *          a boolean attribute), or typeSInt32 (for an integer-valued
 *          attribute).
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleSetNamedAttribute = 23
};

/*
 *  kEventClassAccessibility / kEventAccessibleIsNamedAttributeSettable
 *  
 *  Summary:
 *    Determines whether an attribute of an accessible object can be
 *    modified.
 *  
 *  Discussion:
 *    The kEventParamAccessibleAttributeName parameter will contain an
 *    attribute name in the form of a CFStringRef. If you support the
 *    named attribute, set the kEventParamAccessibleAttributeSettable
 *    parameter to a Boolean indicating whether the named attribute can
 *    have its value changed via the kEventAccessibleSetNamedAttribute
 *    event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamAccessibleAttributeName (in, typeCFStringRef)
 *          The name of the requested attribute.
 *    
 *    <-- kEventParamAccessibleAttributeSettable (out, typeBoolean)
 *          On exit, indicates whether the attribute may be modified.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleIsNamedAttributeSettable = 24
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetAllActionNames
 *  
 *  Summary:
 *    Returns the actions supported by an accessible object.
 *  
 *  Discussion:
 *    The kEventParamAccessibleActionNames parameter will contain a
 *    CFMutableArrayRef. Add each of the action names you support to
 *    this array in the form of a CFStringRef.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    <-> kEventParamAccessibleActionNames (in/out, typeCFMutableArrayRef)
 *          Add each of the actions supported by the accessible object
 *          to this array, as CFStringRefs.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetAllActionNames = 41
};

/*
 *  kEventClassAccessibility / kEventAccessiblePerformNamedAction
 *  
 *  Summary:
 *    Requests that a specific action be performed by an accessible
 *    object.
 *  
 *  Discussion:
 *    The kEventParamAccessibleActionName parameter will contain an
 *    attribute name in the form of a CFStringRef. If you support the
 *    named action, perform the action. There are times, however, when
 *    performing an action causes an accessible object to call a
 *    routine which may not return immediately, such as StandardAlert
 *    or PopUpMenuSelect. You should only call such routines when you
 *    receive an action request that was queued; if you call such a
 *    routine when processing an event that was directly dispatched,
 *    you will probably cause the assistive app to receive a timeout
 *    error. On Mac OS X 10.3 and later, the
 *    kEventParamAccessibilityEventQueued parameter will indicate
 *    whether the event was queued. If so, process the request
 *    normally. If not, you can request that the event be posted to the
 *    queue and sent to you later by returning
 *    eventDeferAccessibilityEventErr from your handler. On Mac OS X
 *    10.2, the parameter will not exist, the event will always be
 *    directly dispatched, and there is no way to request that it be
 *    posted to the queue; in this case, you should perform the action
 *    even if it will cause the assistive app to receive a timeout
 *    error.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamAccessibleActionName (in, typeCFStringRef)
 *          The name of the requested action.
 *    
 *    --> kEventParamAccessibilityEventQueued (in, typeBoolean)
 *          An indication of whether this event was delivered to you
 *          via the main event queue. This parameter only exists on Mac
 *          OS X 10.3 and later. See the discussion for more details.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessiblePerformNamedAction = 42
};

/*
 *  kEventClassAccessibility / kEventAccessibleGetNamedActionDescription
 *  
 *  Summary:
 *    Returns a human-language description of an action supported by an
 *    accessible object.
 *  
 *  Discussion:
 *    The kEventParamAccessibleActionName parameter will contain an
 *    attribute name in the form of a CFStringRef. The
 *    kEventParamAccessibleActionDescription parameter will contain a
 *    CFMutableStringRef. If you support the named action, alter the
 *    mutable string to contain a textual description of the action�s
 *    significance.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamAccessibleObject (in, typeCFTypeRef)
 *          The accessible object, in the form of an AXUIElementRef.
 *    
 *    --> kEventParamAccessibleActionName (in, typeCFStringRef)
 *          The name of the requested action.
 *    
 *    <-> kEventParamAccessibleActionDescription (in/out, typeCFMutableStringRef)
 *          If you support the action, set the contents of this string
 *          to contain a description of the action.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventAccessibleGetNamedActionDescription = 44
};

/*
 *  AXUIElementCreateWithHIObjectAndIdentifier()
 *  
 *  Discussion:
 *    This routine creates an AXUIElementRef to represent an accessible
 *    object for a Carbon application. A Carbon accessible object is
 *    comprised of an HIObjectRef and a 64-bit identifier. The
 *    resulting AXUIElementRef is a CFTypeRef, and must be managed as
 *    such.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inHIObject:
 *      The HIObjectRef of the accessible object.
 *    
 *    inIdentifier:
 *      The 64-bit identifier of the accessible object.
 *  
 *  Result:
 *    An AXUIElementRef that represents the Carbon accessible object
 *    identified by the given HIObjectRef and 64-bit identifier. This
 *    follows CoreFoundation semantics in that it will return NULL for
 *    failure, and because it is a "Create" function you will need to
 *    CFRelease() this AXUIElementRef when it is no longer needed.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern AXUIElementRef 
AXUIElementCreateWithHIObjectAndIdentifier(
  HIObjectRef   inHIObject,
  UInt64        inIdentifier)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  AXUIElementGetHIObject()
 *  
 *  Discussion:
 *    If the incoming AXUIElementRef is a Carbon accessible object,
 *    this routine will return the HIObjectRef of the accessible object.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inUIElement:
 *      The AXUIElementRef of whom you'd like to get the HIObjectRef.
 *  
 *  Result:
 *    The HIObjectRef of the AXUIElementRef. If the incoming
 *    AXUIElementRef is not a Carbon accessible object, this routine
 *    will return NULL.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern HIObjectRef 
AXUIElementGetHIObject(AXUIElementRef inUIElement)            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  AXUIElementGetIdentifier()
 *  
 *  Discussion:
 *    If the incoming AXUIElementRef is a Carbon accessible object,
 *    this routine will pass back the 64-bit identifier of the
 *    accessible object.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inUIElement:
 *      The AXUIElementRef of whom you'd like to get the 64-bit
 *      identifier.
 *    
 *    outIdentifier:
 *      The 64-bit identifier of the AXUIElementRef. If the incoming
 *      AXUIElementRef is not a Carbon accessible object, this routine
 *      will pass back zero. Note that zero is often a legal value for
 *      Carbon accessible object, so do not assume that the accessible
 *      object is not a Carbon accessible object just because you get a
 *      result of zero.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern void 
AXUIElementGetIdentifier(
  AXUIElementRef   inUIElement,
  UInt64 *         outIdentifier)                             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  AXNotificationHIObjectNotify()
 *  
 *  Discussion:
 *    Posts a notification for the given pseudo-AXUIElementRef. Though
 *    an actual AXUIElementRef is not actually passed in to this
 *    function, its component parts are. This saves the implementation
 *    the hassle of dismantling the AXUIElementRef into its component
 *    parts.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inNotification:
 *      The notification name string.
 *    
 *    inHIObject:
 *      The HIObjectRef component of the AXUIElementRef to whom the
 *      notification applies.
 *    
 *    inIdentifier:
 *      The 64-bit identifier component of the AXUIElementRef to whom
 *      the notification applies.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern void 
AXNotificationHIObjectNotify(
  CFStringRef   inNotification,
  HIObjectRef   inHIObject,
  UInt64        inIdentifier)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*��������������������������������������������������������������������������������������*/
/*  System Events                                                                       */
/*��������������������������������������������������������������������������������������*/
/*
    kEventClassSystem quick reference:

    kEventSystemTimeDateChanged         = 2,
    kEventSystemUserSessionActivated    = 10,
    kEventSystemUserSessionDeactivated  = 11

    %% Make sure to avoid overlap with the System Event IDs in CarbonEventsPriv.i!
*/
/*
 *  kEventClassSystem / kEventSystemTimeDateChanged
 *  
 *  Summary:
 *    The system time and/or date has changed via the preferences panel.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventSystemTimeDateChanged   = 2
};

/*
 *  kEventClassSystem / kEventSystemUserSessionActivated
 *  
 *  Summary:
 *    The current user login session has been activated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    when the Fast User Switching feature of Mac OS X 10.3 is used to
 *    activate the login session in which the current application is
 *    running.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventSystemUserSessionActivated = 10
};

/*
 *  kEventClassSystem / kEventSystemUserSessionDeactivated
 *  
 *  Summary:
 *    The current user login session has been deactivated.
 *  
 *  Discussion:
 *    This event is sent to all handlers registered for it. It is sent
 *    when the Fast User Switching feature of Mac OS X 10.3 is used to
 *    switch to another user's login session.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventSystemUserSessionDeactivated = 11
};

/*��������������������������������������������������������������������������������������*/
/*  Installing Event Handlers                                                           */
/*��������������������������������������������������������������������������������������*/
/*
 *  GetWindowEventTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the specified window. Once you
 *    obtain this reference, you can send events to the target and
 *    install an event handler on it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window to return the target for.
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetWindowEventTarget(WindowRef inWindow)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetControlEventTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the specified control. Once you
 *    obtain this reference, you can send events to the target and
 *    install event handler on it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inControl:
 *      The control to return the target for.
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetControlEventTarget(ControlRef inControl)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMenuEventTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the specified menu. Once you
 *    obtain this reference, you can send events to the target and
 *    install event handler on it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMenu:
 *      The menu to return the target for.
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetMenuEventTarget(MenuRef inMenu)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetApplicationEventTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the application. Once you obtain
 *    this reference, you can send events to the target and install
 *    event handler on it.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetApplicationEventTarget(void)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetUserFocusEventTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the current user focus at the time
 *    of the call. Keyboard events are always sent to this target.
 *    There is a default handler installed on this target that passes
 *    the event to the focused control in the focused window.
 *    
 *    Note that command key processing occurs before key events are
 *    sent to this target; to intercept key events before command key
 *    processing occurs, install a handler on the event dispatcher
 *    target instead of this target.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetUserFocusEventTarget(void)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetEventDispatcherTarget()
 *  
 *  Discussion:
 *    Returns the EventTargetRef for the standard toolbox dispatcher.
 *    You typically would never need to use this, but there are some
 *    exotic apps that need to pick events off the event queue and call
 *    the dispatcher themselves. This allows you to do just that
 *    instead of calling RunApplicationEventLoop to handle it all.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetEventDispatcherTarget(void)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetEventMonitorTarget()
 *  
 *  Summary:
 *    Returns the event monitor target.
 *  
 *  Discussion:
 *    The event monitor target is a special event target used to
 *    monitor user input events across all processes. When an event
 *    handler is installed on the event monitor target, the Carbon
 *    Event Manager examines the EventTypeSpec for user input event
 *    types, such as mouse-down, mouse-up, key-down, and so forth. It
 *    then requests that the WindowServer make copies of any of these
 *    events that are sent to any process, and deliver them to the
 *    current process also. These events are queued into the main
 *    thread�s event queue, and during normal event dispatching are
 *    sent directly to the event handlers installed on the event
 *    monitor target. Monitored events are not sent through the normal
 *    event dispatching path for the current process; they will pass
 *    through the event dispatcher target, and will then be sent
 *    directly to the event monitor target.
 *    
 *    Handlers installed on the event monitor target will only receive
 *    events when the current application is inactive. When the current
 *    application is active, all event flow occurs through the event
 *    dispatcher target, and no events are sent to the event monitor
 *    target.
 *    
 *    Currently, the event monitor supports the following event kinds:
 *    kEventRawKeyDown, kEventRawKeyUp, kEventRawKeyRepeat,
 *    kEventRawKeyModifiersChanged, kEventMouseDown, kEventMouseUp,
 *    kEventMouseMoved, kEventMouseDragged, kEventMouseWheelMoved,
 *    kEventTabletPoint, and kEventTabletProximity.
 *    
 *    Note that both Carbon and Cocoa password edit text controls
 *    enable a secure input mode while the focus is on the control,
 *    which prevents keyboard events from being passed to other
 *    applications. This prevents the monitoring event target from
 *    being used to sniff password keystrokes.
 *    
 *    For added security, GetEventMonitorTarget requires that "Enable
 *    access for assistive devices" be checked in the Universal Access
 *    preference pane in order to monitor RawKeyDown, RawKeyUp, and
 *    RawKeyRepeat events. If this control is not checked, you can
 *    still install handlers for these events on the event monitor
 *    target, but no events of these types will be sent to your
 *    handler. Administrator privileges are required to enable this
 *    feature.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Result:
 *    An EventTargetRef.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.3 and later
 *    Non-Carbon CFM:   not available
 */
extern EventTargetRef 
GetEventMonitorTarget(void)                                   AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



#define InstallApplicationEventHandler( h, n, l, u, r ) \
     InstallEventHandler( GetApplicationEventTarget(), (h), (n), (l), (u), (r) )

#define InstallHIObjectEventHandler( t, h, n, l, u, r ) \
     InstallEventHandler( HIObjectGetEventTarget( t ), (h), (n), (l), (u), (r) )

#define InstallWindowEventHandler( t, h, n, l, u, r ) \
       InstallEventHandler( GetWindowEventTarget( t ), (h), (n), (l), (u), (r) )

#define InstallControlEventHandler( t, h, n, l, u, r ) \
        InstallEventHandler( GetControlEventTarget( t ), (h), (n), (l), (u), (r) )

#define InstallMenuEventHandler( t, h, n, l, u, r ) \
      InstallEventHandler( GetMenuEventTarget( t ), (h), (n), (l), (u), (r) )


/*
    You can use the following macro in your code to allow you to set up an
 event handler lazily. You pass the name of your event handler in. You should
   use this with caution on Mac OS 9 systems since it could cause heap fragmentation.
*/
#define DEFINE_ONE_SHOT_HANDLER_GETTER( x )       \
EventHandlerUPP Get ## x ## UPP()             \
{                                             \
  static EventHandlerUPP  sHandler = NULL;    \
                                              \
  if ( sHandler == NULL )                     \
      sHandler = NewEventHandlerUPP( x );     \
                                              \
  return sHandler;                            \
}




#define SendEventToApplication( e ) \
        SendEventToEventTarget( (e), GetApplicationEventTarget() )

#define SendEventToHIObject( e, t ) \
      SendEventToEventTarget( (e), HIObjectGetEventTarget( t ) )

#define SendEventToWindow( e, t ) \
        SendEventToEventTarget( (e), GetWindowEventTarget( t ) )

#define SendEventToControl( e, t ) \
     SendEventToEventTarget( (e), GetControlEventTarget( t ) )

#define SendEventToMenu( e, t ) \
       SendEventToEventTarget( (e), GetMenuEventTarget( t ) )

#define SendEventToUserFocus( e ) \
        SendEventToEventTarget( (e), GetUserFocusEventTarget() )

/*======================================================================================*/
/*  EVENT-BASED OBJECT CLASSES                                                          */
/*                                                                                      */
/*  Here it is - the replacement for classic defprocs. This is also a convenient way    */
/*  to create toolbox objects (windows, etc.) that have a specific behavior without     */
/*  installing handlers on each instance of the object. With a toolbox object class,    */
/*  you register your class, then use special creation routines to create objects of    */
/*  that class. The event handlers are automatically installed and ready to go.         */
/*                                                                                      */
/*  Note that on Mac OS X 10.2 and later, we recommend using the HIObject API           */
/*  HIObjectRegisterSubclass rather than RegisterToolboxObjectClass. This API is        */
/*  considered deprecated on Mac OS X 10.2 and later.                                   */
/*======================================================================================*/
typedef struct OpaqueToolboxObjectClassRef*  ToolboxObjectClassRef;
/*
 *  RegisterToolboxObjectClass()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
RegisterToolboxObjectClass(
  CFStringRef              inClassID,
  ToolboxObjectClassRef    inBaseClass,              /* can be NULL */
  UInt32                   inNumEvents,
  const EventTypeSpec *    inEventList,
  EventHandlerUPP          inEventHandler,
  void *                   inEventHandlerData,
  ToolboxObjectClassRef *  outClassRef)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UnregisterToolboxObjectClass()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
UnregisterToolboxObjectClass(ToolboxObjectClassRef inClassRef) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*======================================================================================*/
/*  � Command Routines                                                                  */
/*======================================================================================*/
/*
 *  ProcessHICommand()
 *  
 *  Summary:
 *    Sends a kEventCommandProcess event.
 *  
 *  Discussion:
 *    ProcessHICommand is a convenience function for dispatching
 *    kEventCommandProcesss events. Normally these events are created
 *    and dispatched automatically by the toolbox when a menu item or
 *    control is selected, but you may need to dispatch an event
 *    yourself at times. This API creates a CommandProcess event, adds
 *    the specified HICommand structure as an event parameter, and
 *    sends the event to the user focus target for handling. 
 *    
 *    If you need to send a CommandProcess event to some other target,
 *    or you need to add other event parameters to the event besides
 *    the HICommand structure, it is correct and supported to simply
 *    create the event yourself and send it to the desired target,
 *    without using this API.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ProcessHICommand(const HICommand * inCommand)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*��������������������������������������������������������������������������������������*/
/*  � Event Loop Routines                                                               */
/*��������������������������������������������������������������������������������������*/

/*
 *  RunApplicationEventLoop()
 *  
 *  Discussion:
 *    This routine is used as the main event loop for a Carbon
 *    Event-based application. Once entered, this function waits for
 *    events to arrive and dispatches them to your event handlers
 *    automatically.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern void 
RunApplicationEventLoop(void)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QuitApplicationEventLoop()
 *  
 *  Discussion:
 *    This routine is used to quit the RunApplicationEventLoop
 *    function. Typically, your application doesn't need to call this.
 *    If your application has the Quit menu item tagged with the
 *    kHICommandQuit Menu Command ID, the toolbox will automatically
 *    call this for your application, automatically terminating your
 *    event loop. If your application wants to do pre-processing before
 *    the event loop exits, it should intercept either the
 *    kHICommandQuit menu command, or the kEventApplicationQuit event.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern void 
QuitApplicationEventLoop(void)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*��������������������������������������������������������������������������������������*/
/*  � Event Modality routines                                                           */
/*��������������������������������������������������������������������������������������*/

/*
 *  RunAppModalLoopForWindow()
 *  
 *  Discussion:
 *    This routine is used as a replacement to ModalDialog to drive a
 *    Carbon Event-based modal dialog. Once called, this routine will
 *    not exit until QuitAppModalLoopForWindow is called. Calls to
 *    RunAppModalLoopForWindow can be nested, as long as each call is
 *    made on a different window. In Mac OS X 10.0.x,
 *    RunAppModalLoopForWindow will fail to re-enable the menubar
 *    before exiting if you dispose of the window during the modal loop
 *    (for example, from a Carbon event handler). You can work around
 *    this bug by retaining the window before calling
 *    RunAppModalLoopForWindow, and releasing it afterwards.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window you wish to behave modally.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
RunAppModalLoopForWindow(WindowRef inWindow)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QuitAppModalLoopForWindow()
 *  
 *  Discussion:
 *    This routine is used to quit a currently running call to
 *    RunAppModalLoopForWindow, i.e. it terminates a modal loop.
 *    Typically this would be called from a handler you have installed
 *    on the modal window in question when the user clicks the
 *    appropriate button, etc.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window for which to quit the modal state.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
QuitAppModalLoopForWindow(WindowRef inWindow)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  BeginAppModalStateForWindow()
 *  
 *  Discussion:
 *    This routine is a lower level routine than
 *    RunAppModalLoopForWindow. It can be used if you wish to enter an
 *    app modal state for a window, but need to control the event loop
 *    yourself for whatever reason. In most cases, you would use
 *    RunAppModalLoopForWindow. Once you begin your app modal state,
 *    the menu bar will disable and prepare for the modal situation.
 *    The window must be visible when calling
 *    BeginAppModalStateForWindow; otherwise, windowWrongStateErr is
 *    returned. Calls to BeginAppModalStateForWindow can be nested, as
 *    long as each call is made on a different window. In Mac OS 10.0.x
 *    and CarbonLib 1.3.1, BeginAppModalStateForWindow can only be
 *    called on a window once; future calls will return an error. This
 *    bug is fixed in Mac OS 10.1 and CarbonLib 1.4.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window you wish to behave modally.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
BeginAppModalStateForWindow(WindowRef inWindow)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EndAppModalStateForWindow()
 *  
 *  Discussion:
 *    This routine ends an app modal state started with
 *    BeginAppModalStateForWindow.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window you wish to stop acting as app modal.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
EndAppModalStateForWindow(WindowRef inWindow)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*��������������������������������������������������������������������������������������*/
/*  � User Focus                                                                        */
/*                                                                                      */
/* The 'user focus' is where keyboard input goes. We also use the term 'key' applied    */
/* to windows to mean this. The user focus window is normally the active non-floating   */
/* window or dialog. It is possible to make a floater get the focus, however, by calling*/
/* SetUserFocusWindow. After that call, the event model will automatically route key    */
/* input to the active keyboard focus of that window, if any. Passing kUserFocusAuto    */
/* into the window parameter tells the toolbox to pick what it considers to be the best */
/* candidate for focus. You should call this to restore focus, rather than getting the  */
/* focus, setting it to a special window, and then restoring to the saved focus. There  */
/* are cases, however, when you might want to restore to an explicit window, but the    */
/* typical usage should just be to restore to the kUserFocusAuto focus.                 */
/*                                                                                      */
/* Keep in mind that setting the focus will only last until you restore focus, or the   */
/* user starts clicking in other windows. When that happens, the toolbox will auto-     */
/* redirect the user focus to a newly selected window.                                  */
/*��������������������������������������������������������������������������������������*/
/* pick the most appropriate window for focus*/
#define kUserFocusAuto                  ((WindowRef)(-1))
/*
 *  SetUserFocusWindow()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetUserFocusWindow(WindowRef inWindow)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetUserFocusWindow()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern WindowRef 
GetUserFocusWindow(void)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*��������������������������������������������������������������������������������������*/
/*  � Default/Cancel buttons                                                            */
/*                                                                                      */
/* In our quest to eliminate the need for dialogs when using the new event model, we    */
/* have added the following routines which add dialog-like button control to normal     */
/* windows. With these routines, you can set the default and cancel buttons for a       */
/* window; these work just like the corresponding concepts in dialogs, and when         */
/* present, the standard toolbox handlers will handle keyboard input mapping to these   */
/* buttons. This means that pressing return or enter will 'press' the default button    */
/* and escape or command-period will 'press' the cancel button.                         */
/*��������������������������������������������������������������������������������������*/

/*
 *  SetWindowDefaultButton()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetWindowDefaultButton(
  WindowRef    inWindow,
  ControlRef   inControl)       /* can be NULL */             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetWindowCancelButton()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetWindowCancelButton(
  WindowRef    inWindow,
  ControlRef   inControl)       /* can be NULL */             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetWindowDefaultButton()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetWindowDefaultButton(
  WindowRef     inWindow,
  ControlRef *  outControl)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetWindowCancelButton()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetWindowCancelButton(
  WindowRef     inWindow,
  ControlRef *  outControl)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*��������������������������������������������������������������������������������������*/
/*  � Global HotKey API                                                                 */
/*��������������������������������������������������������������������������������������*/
struct EventHotKeyID {
  OSType              signature;
  UInt32              id;
};
typedef struct EventHotKeyID            EventHotKeyID;
typedef struct OpaqueEventHotKeyRef*    EventHotKeyRef;
/*
 *  RegisterEventHotKey()
 *  
 *  Discussion:
 *    Registers a global hot key based on the virtual key code and
 *    modifiers you pass in. Only one such combination can exist for
 *    the current application, i.e. multiple entities in the same
 *    application cannot register for the same hot key combination. The
 *    same hot key can, however, be registered by multiple
 *    applications. This means that multiple applications can
 *    potentially be notified when a particular hot key is requested.
 *    This might not necessarily be desirable, but it is how it works
 *    at present.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inHotKeyCode:
 *      The virtual key code of the key to watch
 *    
 *    inHotKeyModifiers:
 *      The keyboard modifiers to look for. On Mac OS X 10.2 or
 *      earlier, this parameter must be non-zero, i.e. there must be a
 *      modifier specified. On Mac OS X 10.3 or later, you may pass
 *      zero.
 *    
 *    inHotKeyID:
 *      The application-specified hot key ID. You will receive this in
 *      the kEventHotKeyPressed event as the direct object parameter.
 *    
 *    inTarget:
 *      The target to notify when the hot key is pressed.
 *    
 *    inOptions:
 *      Currently unused. Pass 0 or face the consequences.
 *    
 *    outRef:
 *      The EventHotKeyRef that represents your new, shiny hot key. You
 *      need this if you later wish to unregister it.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
RegisterEventHotKey(
  UInt32            inHotKeyCode,
  UInt32            inHotKeyModifiers,
  EventHotKeyID     inHotKeyID,
  EventTargetRef    inTarget,
  OptionBits        inOptions,
  EventHotKeyRef *  outRef)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UnregisterEventHotKey()
 *  
 *  Discussion:
 *    Unregisters a global hot key that was previously registered with
 *    the RegisterEventHotKey API. You do not need to unregister a hot
 *    key when your application terminates, the system will take care
 *    of that for you. This would be used if the user changes a hot key
 *    for something in your application - you would unregister the
 *    previous key and register your new key.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inHotKey:
 *      The EventHotKeyRef to unregister.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
UnregisterEventHotKey(EventHotKeyRef inHotKey)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  kHISymbolicHotKeyCode
 *  
 *  Discussion:
 *    A CFDictionaryRef key in a dictionary returned by
 *    CopySymbolicHotKeys. The value for this key is the virtual
 *    keycode of the hotkey, represented as a CFNumber.
 */
#define kHISymbolicHotKeyCode           CFSTR("kHISymbolicHotKeyCode")

/*
 *  kHISymbolicHotKeyModifiers
 *  
 *  Discussion:
 *    A CFDictionaryRef key in a dictionary returned by
 *    CopySymbolicHotKeys. The value for this key is the keyboard
 *    modifiers of the hotkey, represented as a CFNumber.
 */
#define kHISymbolicHotKeyModifiers      CFSTR("kHISymbolicHotKeyModifiers")

/*
 *  kHISymbolicHotKeyEnabled
 *  
 *  Discussion:
 *    A CFDictionaryRef key in a dictionary returned by
 *    CopySymbolicHotKeys. The value for this key is the enable state
 *    of the hotkey, represented as a CFBoolean.
 */
#define kHISymbolicHotKeyEnabled        CFSTR("kHISymbolicHotKeyEnabled")
/*
 *  CopySymbolicHotKeys()
 *  
 *  Summary:
 *    Returns an array of CFDictionaryRefs containing information about
 *    the system-wide symbolic hotkeys that are defined in the Keyboard
 *    preferences pane.
 *  
 *  Discussion:
 *    The hotkey info returned by this API describes the system-wide
 *    hotkeys such as the Screen Capture, Universal Access, and
 *    Keyboard Navigation keys. It does not include customized
 *    application-specific command keys.
 *    
 *    Each array entry is a CFDictionaryRef, and each dictionary
 *    contains information about a single hotkey. There is currently no
 *    way to determine which hotkey in the Keyboards preference pane
 *    corresponds to a specific dictionary. Each dictionary contains
 *    the following keys: kHISymbolicHotKeyCode,
 *    kHISymbolicHotKeyModifiers, and kHISymbolicHotKeyEnabled. The
 *    array must be released by the caller; the dictionaries do not
 *    need to be released (they will be auto-released when the array is
 *    released).
 *    
 *    Note that this API will require O(number of hotkeys) to run, and
 *    the number of hotkeys will increase in the future, so do not call
 *    this API unnecessarily or in highly performance-sensitive code.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    outHotKeyArray:
 *      On exit, contains an array of the values of all symbolic hot
 *      keys.
 *  
 *  Result:
 *    An operating system result code; currently, noErr and memFullErr
 *    may be returned.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
CopySymbolicHotKeys(CFArrayRef * outHotKeyArray)              AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



/*��������������������������������������������������������������������������������������*/
/*  � MouseTrackingRegions                                                              */
/*��������������������������������������������������������������������������������������*/

/*
 *  MouseTrackingRef
 *  
 *  Discussion:
 *    A MouseTrackingRef is an object that controls the generation of
 *    mouse-enter and mouse-exit events. When the user moves the mouse
 *    into a tracking region, a kEventClassMouse/kEventMouseEntered
 *    event is sent to the app. When the user moves the mouse out of a
 *    tracking region, an event of type
 *    kEventClassMouse/kEventMouseExited is sent. Mouse tracking
 *    regions are uniquely identified within the scope of a window by a
 *    MouseTrackingRegionID which is a client signature/id pair. The
 *    client signature is the usual DTS-registered creator OSType.
 *    Mouse tracking regions can overlap, but are not exclusive. Mouse
 *    motion events are generated for each of the tracking areas
 *    intersected by the mouse. Mouse tracking regions are initially
 *    enabled. You can explicitly disable a mouse tracking area to
 *    prevent mouse-enter/exit events from being generated. Unlike
 *    global mouse-moved events, mouse-enter and mouse-exit events are
 *    generated while your app is in the background. If this is not
 *    considered desirable, disable the tracking areas while the
 *    application is in the background. MouseTrackingRefs become
 *    invalid when the window that they are bound to is disposed of.
 */
typedef struct OpaqueMouseTrackingRef*  MouseTrackingRef;


/*
 *  MouseTrackingOptions
 *  
 *  Discussion:
 *    These values define how the user�s region is handled by the Mouse
 *    Tracking Region API. They define the behavior throughout the life
 *    of the Mouse Tracking Region. For example, if a region is created
 *    with the option of kMouseTrackingOptionsGlobalClip then all
 *    operations on this region will be interpreted in global
 *    coordinates and will be clipped to the owning window�s structure.
 */
typedef UInt32 MouseTrackingOptions;
enum {

  /*
   * The region is expected in local coordinates and mouse movement
   * tracking is clipped to the owning window�s content region.
   */
  kMouseTrackingOptionsLocalClip = 0,

  /*
   * The region is expected in global coordinates and mouse movement
   * tracking is clipped to the owning window�s structure region.
   */
  kMouseTrackingOptionsGlobalClip = 1,

  /*
   * Standard options. The region will be handled in local coordinates
   * and remain clipped against the windows content region.
   */
  kMouseTrackingOptionsStandard = kMouseTrackingOptionsLocalClip
};

struct MouseTrackingRegionID {
  OSType              signature;
  SInt32              id;
};
typedef struct MouseTrackingRegionID    MouseTrackingRegionID;
/* Creation*/

/*
 *  CreateMouseTrackingRegion()
 *  
 *  Discussion:
 *    Creates a mouse tracking region and installs it into the window
 *    system.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window that will contain the created region.
 *    
 *    inRegion:
 *      The region for which you will receive entered/exit events.
 *    
 *    inClip:
 *      A region to clip inRegion against (can be NULL).
 *    
 *    inOptions:
 *      The options which define whether inRegion is given in global or
 *      local coordinates.
 *    
 *    inID:
 *      The signature/id pair which uniquely defines this region.
 *    
 *    inRefCon:
 *      Any user defined value.
 *    
 *    inTargetToNotify:
 *      The event target that should receive kEventMouseEntered/Exited
 *      events for this tracking region. If NULL, the window�s event
 *      target receives these events.
 *    
 *    outTrackingRef:
 *      A reference to the newly created mouse tracking region.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
CreateMouseTrackingRegion(
  WindowRef               inWindow,
  RgnHandle               inRegion,
  RgnHandle               inClip,                 /* can be NULL */
  MouseTrackingOptions    inOptions,
  MouseTrackingRegionID   inID,
  void *                  inRefCon,
  EventTargetRef          inTargetToNotify,       /* can be NULL */
  MouseTrackingRef *      outTrackingRef)                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  RetainMouseTrackingRegion()
 *  
 *  Discussion:
 *    Retains the MouseTrackingRef.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to retain.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
RetainMouseTrackingRegion(MouseTrackingRef inMouseRef)        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  ReleaseMouseTrackingRegion()
 *  
 *  Discussion:
 *    Releases the MouseTrackingRef. Since mouse tracking regions are
 *    bound to a window, they are automatically released when the
 *    window is disposed of.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to release.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ReleaseMouseTrackingRegion(MouseTrackingRef inMouseRef)       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  ChangeMouseTrackingRegion()
 *  
 *  Discussion:
 *    Changes the MouseTrackingRefs region and optionally, its clip.
 *    This will not change the enabled state or options of the region.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to modify.
 *    
 *    inRegion:
 *      The region to set as the mouse tracking region.
 *    
 *    inClip:
 *      An optional clip to clip inRegion against (may be NULL).
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ChangeMouseTrackingRegion(
  MouseTrackingRef   inMouseRef,
  RgnHandle          inRegion,
  RgnHandle          inClip)           /* can be NULL */      AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  ClipMouseTrackingRegion()
 *  
 *  Discussion:
 *    Adjust the region to clip the MouseTrackingRef against. This can
 *    be used in the case where a window is resized or when a
 *    previously obscured region becomes exposed.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to adjust.
 *    
 *    inRegion:
 *      A new region to clip inMouseRef against (can be NULL). If NULL,
 *      standard clipping will be provided.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ClipMouseTrackingRegion(
  MouseTrackingRef   inMouseRef,
  RgnHandle          inRegion)                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* Accessors*/

/*
 *  GetMouseTrackingRegionID()
 *  
 *  Discussion:
 *    Retrieves the MouseTrackingRegionID of the given
 *    MouseTrackingRef. Can be used to determine if the region belongs
 *    to your app, and if so, which region it is.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef from which to obtain the
 *      MouseTrackingRegionID.
 *    
 *    outID:
 *      Receives the MouseTrackingRegionID.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetMouseTrackingRegionID(
  MouseTrackingRef         inMouseRef,
  MouseTrackingRegionID *  outID)                             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  GetMouseTrackingRegionRefCon()
 *  
 *  Discussion:
 *    Retrieves the RefCon from the given mouse tracking region.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef from which to obtain the refcon.
 *    
 *    outRefCon:
 *      Receives the refcon.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetMouseTrackingRegionRefCon(
  MouseTrackingRef   inMouseRef,
  void **            outRefCon)                               AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/* Geometry*/

/*
 *  MoveMouseTrackingRegion()
 *  
 *  Discussion:
 *    Moves the given mouse tracking region by the specified delta. It
 *    can also optionally reclip the region, such as if the region is
 *    scrolled within a pane.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to move.
 *    
 *    deltaH:
 *      The horizontal delta to move the MouseTrackingRef.
 *    
 *    deltaV:
 *      The vertical delta to move the MouseTrackingRef.
 *    
 *    inClip:
 *      A region to optionally clip against (can be NULL).
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
MoveMouseTrackingRegion(
  MouseTrackingRef   inMouseRef,
  SInt16             deltaH,
  SInt16             deltaV,
  RgnHandle          inClip)           /* can be NULL */      AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/* Enable/disable*/

/*
 *  SetMouseTrackingRegionEnabled()
 *  
 *  Discussion:
 *    Set the enabled state of the mouse tracking region
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inMouseRef:
 *      A valid MouseTrackingRef to modify.
 *    
 *    inEnabled:
 *      Indicate whether this region should be enabled (true) or
 *      disabled (false).
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetMouseTrackingRegionEnabled(
  MouseTrackingRef   inMouseRef,
  Boolean            inEnabled)                               AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
   
   Namespace operators
*/

/*
 *  ClipWindowMouseTrackingRegions()
 *  
 *  Discussion:
 *    Bulk clip operation to modify the region that all mouse tracking
 *    regions with the given signature will be clipped against.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window that contains the regions with the given signature
 *      that you are interested in updating.
 *    
 *    inSignature:
 *      The signature of the mouse tracking regions that will be
 *      reclipped.
 *    
 *    inClip:
 *      The region to clip all of the regions against (can be NULL). If
 *      NULL, standard clipping will be provided.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ClipWindowMouseTrackingRegions(
  WindowRef   inWindow,
  OSType      inSignature,
  RgnHandle   inClip)            /* can be NULL */            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  MoveWindowMouseTrackingRegions()
 *  
 *  Discussion:
 *    Bulk move operation to move all regions with the given signature
 *    the specified delta. An optional clip can be provided to reclip
 *    the regions against, such as in the case of the regions are being
 *    scrolled within a pane.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window that contains the regions with the given signature
 *      that you are interested in moving.
 *    
 *    inSignature:
 *      The signature of the mouse tracking regions that will be moved.
 *    
 *    deltaH:
 *      The horizontal delta to move all of the regions.
 *    
 *    deltaV:
 *      The vertical delta to move all of the regions.
 *    
 *    inClip:
 *      An optional clipping region to clip against (can be NULL). If
 *      NULL, standard clipping will be provided.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
MoveWindowMouseTrackingRegions(
  WindowRef   inWindow,
  OSType      inSignature,
  SInt16      deltaH,
  SInt16      deltaV,
  RgnHandle   inClip)            /* can be NULL */            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  SetWindowMouseTrackingRegionsEnabled()
 *  
 *  Discussion:
 *    Bulk set the enabled state of the mouse tracking regions of the
 *    given signature belonging to the given window.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window which contains the mouse tracking regions that you
 *      are interested in modifying.
 *    
 *    inSignature:
 *      The signature of the mouse tracking regions whose enabled state
 *      you wish to modify.
 *    
 *    inEnabled:
 *      Indicates whether the regions should be enabled (true) or
 *      disabled (false).
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
SetWindowMouseTrackingRegionsEnabled(
  WindowRef   inWindow,
  OSType      inSignature,
  Boolean     inEnabled)                                      AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  ReleaseWindowMouseTrackingRegions()
 *  
 *  Discussion:
 *    Bulk release the mouse tracking regions with the given signature.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inWindow:
 *      The window to which the regions to be released belong.
 *    
 *    inSignature:
 *      The signature of the regions to be released.
 *  
 *  Result:
 *    An operating system status code.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
ReleaseWindowMouseTrackingRegions(
  WindowRef   inWindow,
  OSType      inSignature)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;




/*��������������������������������������������������������������������������������������*/
/*  Ink Events                                                                          */
/*��������������������������������������������������������������������������������������*/
enum {
  kEventParamInkTextRef         = 'iwrd', /* typePtr */
  kEventParamInkKeyboardShortcut = 'ikbd', /* typeBoolean */
  kEventParamInkGestureKind     = 'gknd', /* typeUInt32 */
  kEventParamInkGestureBounds   = 'gbnd', /* typeHIRect */
  kEventParamInkGestureHotspot  = 'ghot' /* typeHIPoint */
};



/*
 *  kEventClassInk / kEventInkPoint
 *  
 *  Summary:
 *    A mouse event will be handled as an Ink point and used for
 *    recognition.
 *  
 *  Discussion:
 *    The Ink manager has determined that the mouse event in
 *    kEventParamEventRef should be used for recognition.  If the
 *    application handles the event and returns noErr, then the Ink
 *    Manager does nothing further with the mouse event.  If the
 *    application returns any other value (including
 *    eventNotHandledErr), the point will be processed normally by the
 *    Ink Manager.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamEventRef (in, typeEventRef)
 *          The mouse event being handled.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventInkPoint                = 10
};


/*
 *  kEventClassInk / kEventInkGesture
 *  
 *  Summary:
 *    An Ink gesture has been generated.
 *  
 *  Discussion:
 *    This Ink event is sent when the Ink Manager has recognized the
 *    current ink phrase as one of the known system gestures. 
 *    Applications can install a handler for these events, to provide
 *    targeted gestures and support for context-dependent (tentative)
 *    gestures.  Applications should return noErr if they handled the
 *    gesture.  If the gesture was context-dependent and does not apply
 *    to the current situation, then return eventNotHandledErr.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamInkGestureKind (in, typeUInt32)
 *          Kind of gesture.
 *    
 *    --> kEventParamInkGestureBounds (in, typeHIRect)
 *          Bounds of the gesture in global coordinates.
 *    
 *    --> kEventParamInkGestureHotspot (in, typeHIPoint)
 *          Hotspot for the gesture in global coordinates.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventInkGesture              = 11
};



/*
 *  kEventClassInk / kEventInkText
 *  
 *  Summary:
 *    A recognized word from the Ink Manager.
 *  
 *  Discussion:
 *    The Ink Manager has recognized a word.  kEventParamInkTextRef
 *    contains the InkTextRef with all of the information about the
 *    word.  See Ink.h for more information.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    --> kEventParamInkTextRef (in, typePtr)
 *          The InkTextRef containing the data for the recognized word.
 *    
 *    --> kEventParamInkKeyboardShortcut (in, typeBoolean)
 *          Is this likely a keyboard shortcut? (Command or Control key
 *          is held down and the top-choice alternate text is a single
 *          character.)
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in Carbon.framework
 *    CarbonLib:        not available
 */
enum {
  kEventInkText                 = 12
};





/*��������������������������������������������������������������������������������������*/
/* Obsolete constant names - use the new ones. Will be removed.                         */
/*��������������������������������������������������������������������������������������*/
enum {
  kEventWindowDefDrawFrame      = kEventWindowDrawFrame,
  kEventWindowDefDrawPart       = kEventWindowDrawPart,
  kEventWindowDefGetRegion      = kEventWindowGetRegion,
  kEventWindowDefHitTest        = kEventWindowHitTest,
  kEventWindowDefInit           = kEventWindowInit,
  kEventWindowDefDispose        = kEventWindowDispose,
  kEventWindowDefDragHilite     = kEventWindowDragHilite,
  kEventWindowDefModified       = kEventWindowModified,
  kEventWindowDefSetupProxyDragImage = kEventWindowSetupProxyDragImage,
  kEventWindowDefStateChanged   = kEventWindowStateChanged,
  kEventWindowDefMeasureTitle   = kEventWindowMeasureTitle,
  kEventWindowDefDrawGrowBox    = kEventWindowDrawGrowBox,
  kEventWindowDefGetGrowImageRegion = kEventWindowGetGrowImageRegion
};


enum {
  kEventClassEPPC               = kEventClassAppleEvent,
  kEventHighLevelEvent          = kEventAppleEvent
};

enum {
  kEventUpdateActiveInputArea   = kEventTextInputUpdateActiveInputArea,
  kEventUnicodeForKeyEvent      = kEventTextInputUnicodeForKeyEvent,
  kEventOffsetToPos             = kEventTextInputOffsetToPos,
  kEventPosToOffset             = kEventTextInputPosToOffset,
  kEventShowHideBottomWindow    = kEventTextInputShowHideBottomWindow,
  kEventGetSelectedText         = kEventTextInputGetSelectedText
};

enum {
  kEventProcessCommand          = kEventCommandProcess,
  kEventTabletPointer           = kEventTabletPoint
};

/*��������������������������������������������������������������������������������������*/
/* Obsolete typedefs. Will be removed eventually.                                       */
/*��������������������������������������������������������������������������������������*/

typedef UInt32                          EventClassID;
typedef UInt32                          EventClass;
typedef UInt32                          EventType;
/* OBSOLETE CONSTANTS*/


enum {
  kMouseTrackingMousePressed    = kMouseTrackingMouseDown,
  kMouseTrackingMouseReleased   = kMouseTrackingMouseUp
};

enum {
  kEventControlGetSubviewForMouseEvent = kEventControlInterceptSubviewClick
};


#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __CARBONEVENTS__ */

