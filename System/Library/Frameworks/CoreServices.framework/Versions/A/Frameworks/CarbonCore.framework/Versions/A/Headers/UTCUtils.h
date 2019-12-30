/*
     File:       CarbonCore/UTCUtils.h
 
     Contains:   Interface for UTC to Local Time conversion and 64 Bit Clock routines
 
     Version:    CarbonCore-317~6
 
     Copyright:  � 1999-2001 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __UTCUTILS__
#define __UTCUTILS__

#ifndef __MACTYPES__
#include <CarbonCore/MacTypes.h>
#endif

#ifndef __MACERRORS__
#include <CarbonCore/MacErrors.h>
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

/* Options for Set & Get DateTime Routines */
enum {
  kUTCDefaultOptions            = 0
};

/* 64 Bit Clock Typedefs */
struct UTCDateTime {
  UInt16              highSeconds;
  UInt32              lowSeconds;
  UInt16              fraction;
};
typedef struct UTCDateTime              UTCDateTime;
typedef UTCDateTime *                   UTCDateTimePtr;
typedef UTCDateTimePtr *                UTCDateTimeHandle;
struct LocalDateTime {
  UInt16              highSeconds;
  UInt32              lowSeconds;
  UInt16              fraction;
};
typedef struct LocalDateTime            LocalDateTime;
typedef LocalDateTime *                 LocalDateTimePtr;
typedef LocalDateTimePtr *              LocalDateTimeHandle;
/* Classic 32 bit clock conversion routines */
/*
 *  ConvertLocalTimeToUTC()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
ConvertLocalTimeToUTC(
  UInt32    localSeconds,
  UInt32 *  utcSeconds);


/*
 *  ConvertUTCToLocalTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
ConvertUTCToLocalTime(
  UInt32    utcSeconds,
  UInt32 *  localSeconds);


/* 64 bit clock conversion routines */
/*
 *  ConvertUTCToLocalDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
ConvertUTCToLocalDateTime(
  const UTCDateTime *  utcDateTime,
  LocalDateTime *      localDateTime);


/*
 *  ConvertLocalToUTCDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
ConvertLocalToUTCDateTime(
  const LocalDateTime *  localDateTime,
  UTCDateTime *          utcDateTime);


/* Getter and Setter Clock routines using 64 Bit values */
/*
 *  GetUTCDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
GetUTCDateTime(
  UTCDateTime *  utcDateTime,
  OptionBits     options);


/*
 *  SetUTCDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
SetUTCDateTime(
  const UTCDateTime *  utcDateTime,
  OptionBits           options);


/*
 *  GetLocalDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
GetLocalDateTime(
  LocalDateTime *  localDateTime,
  OptionBits       options);


/*
 *  SetLocalDateTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in CoreServices.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in UTCUtils 1.0 and later
 */
extern OSStatus 
SetLocalDateTime(
  const LocalDateTime *  localDateTime,
  OptionBits             options);



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

#endif /* __UTCUTILS__ */

