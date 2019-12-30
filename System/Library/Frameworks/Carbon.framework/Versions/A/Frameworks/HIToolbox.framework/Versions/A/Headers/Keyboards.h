/*
     File:       HIToolbox/Keyboards.h
 
     Contains:   Keyboard API.
 
     Version:    HIToolbox-145.48~1
 
     Copyright:  � 1997-2003 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __KEYBOARDS__
#define __KEYBOARDS__

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

/*����������������������������������������������������������������������������������*/
/*  OBSOLETE                                                                        */
/*����������������������������������������������������������������������������������*/
/* These are obsolete.  Carbon does not support these. */
/* Keyboard API Trap Number. Should be moved to Traps.i */
enum {
  _KeyboardDispatch             = 0xAA7A
};

/* Gestalt selector and values for the Keyboard API */
enum {
  gestaltKeyboardsAttr          = 'kbds',
  gestaltKBPS2Keyboards         = 1,
  gestaltKBPS2SetIDToAny        = 2,
  gestaltKBPS2SetTranslationTable = 4
};

/* Keyboard API Error Codes */
/*
   I stole the range blow from the empty space in the Allocation project but should
   be updated to the officially registered range.
*/
enum {
  errKBPS2KeyboardNotAvailable  = -30850,
  errKBIlligalParameters        = -30851,
  errKBFailSettingID            = -30852,
  errKBFailSettingTranslationTable = -30853,
  errKBFailWritePreference      = -30854
};

/*
 *  KBInitialize()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBSetupPS2Keyboard()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBGetPS2KeyboardID()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBIsPS2KeyboardConnected()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBIsPS2KeyboardEnabled()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBGetPS2KeyboardAttributes()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBSetKCAPForPS2Keyboard()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBSetupPS2KeyboardFromLayoutType()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*
 *  KBGetPS2KeyboardLayoutType()
 *  
 *  Availability:
 *    Mac OS X:         not available
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */


/*����������������������������������������������������������������������������������*/
/* Keyboard API constants                                                           */
/*����������������������������������������������������������������������������������*/

/*
 *  PhysicalKeyboardLayoutType
 *  
 *  Summary:
 *    Physical keyboard layout types indicate the physical keyboard
 *    layout. They are returned by the KBGetLayoutType API.
 */
typedef UInt32 PhysicalKeyboardLayoutType;
enum {

  /*
   * A JIS keyboard layout type.
   */
  kKeyboardJIS                  = 'JIS ',

  /*
   * An ANSI keyboard layout type.
   */
  kKeyboardANSI                 = 'ANSI',

  /*
   * An ISO keyboard layout type.
   */
  kKeyboardISO                  = 'ISO ',

  /*
   * An unknown physical keyboard layout type.
   */
  kKeyboardUnknown              = kUnknownType /* '????'*/
};

/*����������������������������������������������������������������������������������*/
/* Keyboard API types                                                               */
/*����������������������������������������������������������������������������������*/

/*
 *  KeyboardLayoutRef
 *  
 *  Summary:
 *    The opaque keyboard layout contains information about a keyboard
 *    layout. It is used with the keyboard layout APIs.
 *  
 *  Discussion:
 *    KeyboardLayoutRef APIs follow CoreFoundation function naming
 *    convention. You mustn't release any references you get from APIs
 *    named "Get."
 */
typedef struct OpaqueKeyboardLayoutRef*  KeyboardLayoutRef;

/*
 *  KeyboardLayoutPropertyTag
 *  
 *  Summary:
 *    Keyboard layout property tags specify the value you want to
 *    retrieve. They are used with the KLGetKeyboardLayoutProperty API.
 */
typedef UInt32 KeyboardLayoutPropertyTag;
enum {

  /*
   * The keyboard layout data (const void *).  It is used with the
   * KeyTranslate API.
   */
  kKLKCHRData                   = 0,

  /*
   * The keyboard layout data (const void *).  It is used with the
   * UCKeyTranslate API.
   */
  kKLuchrData                   = 1,

  /*
   * The keyboard layout identifier (KeyboardLayoutIdentifier).
   */
  kKLIdentifier                 = 2,

  /*
   * The keyboard layout icon (IconRef).
   */
  kKLIcon                       = 3,

  /*
   * The localized keyboard layout name (CFStringRef).
   */
  kKLLocalizedName              = 4,

  /*
   * The keyboard layout name (CFStringRef).
   */
  kKLName                       = 5,

  /*
   * The keyboard layout group identifier (SInt32).
   */
  kKLGroupIdentifier            = 6,

  /*
   * The keyboard layout kind (KeyboardLayoutKind).
   */
  kKLKind                       = 7
};


/*
 *  KeyboardLayoutKind
 *  
 *  Summary:
 *    Keyboard layout kinds indicate available keyboard layout formats.
 */
typedef SInt32 KeyboardLayoutKind;
enum {

  /*
   * Both KCHR and uchr formats are available.
   */
  kKLKCHRuchrKind               = 0,

  /*
   * Only KCHR format is avaiable.
   */
  kKLKCHRKind                   = 1,

  /*
   * Only uchr format is available.
   */
  kKLuchrKind                   = 2
};


/*
 *  KeyboardLayoutIdentifier
 *  
 *  Summary:
 *    Keyboard layout identifiers specify particular keyboard layouts.
 */
typedef SInt32 KeyboardLayoutIdentifier;
enum {
  kKLUSKeyboard                 = 0
};

/*����������������������������������������������������������������������������������*/
/* Keyboard API routines                                                            */
/*����������������������������������������������������������������������������������*/
/*
 *  KBGetLayoutType()
 *  
 *  Summary:
 *    Returns the physical keyboard layout type.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iKeyboardType:
 *      The keyboard type ID.  LMGetKbdType().
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.0 and later
 *    Non-Carbon CFM:   in KeyboardsLib 1.0 and later
 */
extern PhysicalKeyboardLayoutType 
KBGetLayoutType(SInt16 iKeyboardType)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* iterate keyboard layouts*/

/*
 *  KLGetKeyboardLayoutCount()
 *  
 *  Summary:
 *    Returns the number of keyboard layouts.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    oCount:
 *      On exit, the number of keyboard layouts
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetKeyboardLayoutCount(CFIndex * oCount)                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  KLGetKeyboardLayoutAtIndex()
 *  
 *  Summary:
 *    Retrieves the keyboard layout at the given index.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iIndex:
 *      The index of the keyboard layout to retrieve. If the index is
 *      outside the index space of the keyboard layouts (0 to N-1
 *      inclusive, where N is the count of the keyboard layouts), the
 *      behavior is undefined.
 *    
 *    oKeyboardLayout:
 *      On exit, the keyboard layout with the given index.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetKeyboardLayoutAtIndex(
  CFIndex              iIndex,
  KeyboardLayoutRef *  oKeyboardLayout)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
   *** deprecated. ***
   NOTE: "Indexed" is a wrong name, please use "AtIndex"...
   OSStatus KLGetIndexedKeyboardLayout(
                CFIndex                     iIndex,
                KeyboardLayoutRef           *oKeyboardLayout    );
*/

/* get keyboard layout info*/

/*
 *  KLGetKeyboardLayoutProperty()
 *  
 *  Summary:
 *    Retrives property value for the given keyboard layout and tag.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iKeyboardLayout:
 *      The keyboard layout to be queried. If this parameter is not a
 *      valid KeyboardLayoutRef, the behavior is undefined.
 *    
 *    iPropertyTag:
 *      The property tag.
 *    
 *    oValue:
 *      On exit, the property value for the given keyboard layout and
 *      tag.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetKeyboardLayoutProperty(
  KeyboardLayoutRef           iKeyboardLayout,
  KeyboardLayoutPropertyTag   iPropertyTag,
  const void **               oValue)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* get keyboard layout with identifier or name*/

/*
 *  KLGetKeyboardLayoutWithIdentifier()
 *  
 *  Summary:
 *    Retrieves the keyboard layout with the given identifier.
 *  
 *  Discussion:
 *    For now, the identifier is in the range of SInt16 which is
 *    compatible with the Resource Manager resource ID. However, it
 *    will become an arbitrary SInt32 value at some point, so do not
 *    assume it is in SInt16 range or falls into the "script range" of
 *    the resource IDs.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iIdentifier:
 *      The keyboard layout identifier.
 *    
 *    oKeyboardLayout:
 *      On exit, the keyboard layout with the given identifier.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetKeyboardLayoutWithIdentifier(
  KeyboardLayoutIdentifier   iIdentifier,
  KeyboardLayoutRef *        oKeyboardLayout)                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  KLGetKeyboardLayoutWithName()
 *  
 *  Summary:
 *    Retrieves the keyboard layout with the given name.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iName:
 *      The keyboard layout name.
 *    
 *    oKeyboardLayout:
 *      On exit, the keyboard layout with the given name.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetKeyboardLayoutWithName(
  CFStringRef          iName,
  KeyboardLayoutRef *  oKeyboardLayout)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* get/set current keyboard layout of the current group identifier*/

/*
 *  KLGetCurrentKeyboardLayout()
 *  
 *  Summary:
 *    Retrieves the current keyboard layout.
 *  
 *  Discussion:
 *    Retrieves the current keyboard layout for the current keyboard
 *    script.  To retrive the current keyboard script for Roman
 *    keyboard script, you need to call KeyScript( smRoman |
 *    smKeyForceKeyScriptMask ) then call KLGetCurrentKeyboardLayout().
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    oKeyboardLayout:
 *      On exit, the current keyboard layout.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLGetCurrentKeyboardLayout(KeyboardLayoutRef * oKeyboardLayout) AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  KLSetCurrentKeyboardLayout()
 *  
 *  Summary:
 *    Sets the current keyboard layout.
 *  
 *  Discussion:
 *    Sets the current keyboard layout for the current keyboard script.
 *     Returns "paramErr" when the current keyboard layout is not
 *    Unicode and the specified keyboard layout belongs to Unicode
 *    group.  To set Roman keyboard script's current keyboard layout to
 *    "U.S." for example, you need to call KeyScript( smRoman |
 *    smKeyForceKeyScriptMask ) then call KLSetCurrentKeyboardLayout(
 *    theUSKeyboardLayoutRef ).
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    iKeyboardLayout:
 *      The keyboard layout.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in Carbon.framework
 *    CarbonLib:        not available in CarbonLib 1.x, is available on Mac OS X version 10.2 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
KLSetCurrentKeyboardLayout(KeyboardLayoutRef iKeyboardLayout) AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



#ifdef __cplusplus
}
#endif

#endif /* __KEYBOARDS__ */

