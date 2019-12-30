/*
     File:       ATS/ATSTypes.h
 
     Contains:   Public interfaces for Apple Type Services components.
 
     Version:    ATS-77.1~62
 
     Copyright:  � 1997-2001 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __ATSTYPES__
#define __ATSTYPES__

#ifndef __MACTYPES__
#include <CarbonCore/MacTypes.h>
#endif

#ifndef __FILES__
#include <CarbonCore/Files.h>
#endif

#ifndef __MIXEDMODE__
#include <CarbonCore/MixedMode.h>
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

typedef UInt32                          FMGeneration;
/* The FMFontFamily reference represents a collection of fonts with the same design
   characteristics. It replaces the standard QuickDraw font identifer and may be used
   with all QuickDraw functions including GetFontName and TextFont. It cannot be used
   with the Resource Manager to access information from a FOND resource handle. A font
   reference does not imply a particular script system, nor is the character encoding
   of a font family determined by an arithmetic mapping of its value.
*/
typedef SInt16                          FMFontFamily;
typedef SInt16                          FMFontStyle;
typedef SInt16                          FMFontSize;
/* 
   The font family is a collection of fonts, each of which is identified
   by an FMFont reference that maps to a single object registered with
   the font database. The font references associated with the font
   family consist of individual outline and bitmapped fonts that may be
   used with the font access routines of the Font Manager and ATS.
*/
typedef UInt32                          FMFont;
struct FMFontFamilyInstance {
  FMFontFamily        fontFamily;
  FMFontStyle         fontStyle;
};
typedef struct FMFontFamilyInstance     FMFontFamilyInstance;
struct FMFontFamilyIterator {
  UInt32              reserved[16];
};
typedef struct FMFontFamilyIterator     FMFontFamilyIterator;
struct FMFontIterator {
  UInt32              reserved[16];
};
typedef struct FMFontIterator           FMFontIterator;
struct FMFontFamilyInstanceIterator {
  UInt32              reserved[16];
};
typedef struct FMFontFamilyInstanceIterator FMFontFamilyInstanceIterator;
enum {
  kInvalidGeneration            = 0L,
  kInvalidFontFamily            = -1,
  kInvalidFont                  = 0L
};

enum {
  kFMCurrentFilterFormat        = 0L
};

typedef UInt32 FMFilterSelector;
enum {
  kFMFontTechnologyFilterSelector = 1L,
  kFMFontContainerFilterSelector = 2L,
  kFMGenerationFilterSelector   = 3L,
  kFMFontFamilyCallbackFilterSelector = 4L,
  kFMFontCallbackFilterSelector = 5L,
  kFMFontDirectoryFilterSelector = 6L
};

enum {
  kFMTrueTypeFontTechnology     = 'true',
  kFMPostScriptFontTechnology   = 'typ1'
};

typedef CALLBACK_API( OSStatus , FMFontFamilyCallbackFilterProcPtr )(FMFontFamily iFontFamily, void *iRefCon);
typedef CALLBACK_API( OSStatus , FMFontCallbackFilterProcPtr )(FMFont iFont, void *iRefCon);
typedef STACK_UPP_TYPE(FMFontFamilyCallbackFilterProcPtr)       FMFontFamilyCallbackFilterUPP;
typedef STACK_UPP_TYPE(FMFontCallbackFilterProcPtr)             FMFontCallbackFilterUPP;
/*
 *  NewFMFontFamilyCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern FMFontFamilyCallbackFilterUPP
NewFMFontFamilyCallbackFilterUPP(FMFontFamilyCallbackFilterProcPtr userRoutine);

/*
 *  NewFMFontCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern FMFontCallbackFilterUPP
NewFMFontCallbackFilterUPP(FMFontCallbackFilterProcPtr userRoutine);

/*
 *  DisposeFMFontFamilyCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeFMFontFamilyCallbackFilterUPP(FMFontFamilyCallbackFilterUPP userUPP);

/*
 *  DisposeFMFontCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeFMFontCallbackFilterUPP(FMFontCallbackFilterUPP userUPP);

/*
 *  InvokeFMFontFamilyCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeFMFontFamilyCallbackFilterUPP(
  FMFontFamily                   iFontFamily,
  void *                         iRefCon,
  FMFontFamilyCallbackFilterUPP  userUPP);

/*
 *  InvokeFMFontCallbackFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in ApplicationServices.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSStatus
InvokeFMFontCallbackFilterUPP(
  FMFont                   iFont,
  void *                   iRefCon,
  FMFontCallbackFilterUPP  userUPP);

struct FMFontDirectoryFilter {
  SInt16              fontFolderDomain;
  UInt32              reserved[2];
};
typedef struct FMFontDirectoryFilter    FMFontDirectoryFilter;
struct FMFilter {
  UInt32              format;
  FMFilterSelector    selector;
  union {
    FourCharCode        fontTechnologyFilter;
    FSSpec              fontContainerFilter;
    FMGeneration        generationFilter;
    FMFontFamilyCallbackFilterUPP  fontFamilyCallbackFilter;
    FMFontCallbackFilterUPP  fontCallbackFilter;
    FMFontDirectoryFilter  fontDirectoryFilter;
  }                       filter;
};
typedef struct FMFilter                 FMFilter;

typedef OptionBits                      ATSOptionFlags;
typedef UInt32                          ATSGeneration;
typedef UInt32                          ATSFontContainerRef;
typedef UInt32                          ATSFontFamilyRef;
typedef UInt32                          ATSFontRef;
typedef UInt16                          ATSGlyphRef;
typedef Float32                         ATSFontSize;
enum {
  kATSGenerationUnspecified     = 0L,
  kATSFontContainerRefUnspecified = 0L,
  kATSFontFamilyRefUnspecified  = 0L,
  kATSFontRefUnspecified        = 0L
};

struct ATSFontMetrics {
  UInt32              version;
  Float32             ascent;                 /* Maximum height above baseline reached by the glyphs in the font */
                                              /* or maximum distance to the right of the centerline reached by the glyphs in the font */
  Float32             descent;                /* Maximum depth below baseline reached by the glyphs in the font */
                                              /* or maximum distance to the left of the centerline reached by the glyphs in the font */
  Float32             leading;                /* Desired spacing between lines of text */
  Float32             avgAdvanceWidth;
  Float32             maxAdvanceWidth;        /* Maximum advance width or height of the glyphs in the font */
  Float32             minLeftSideBearing;     /* Minimum left or top side bearing */
  Float32             minRightSideBearing;    /* Minimum right or bottom side bearing */
  Float32             stemWidth;              /* Width of the dominant vertical stems of the glyphs in the font */
  Float32             stemHeight;             /* Vertical width of the dominant horizontal stems of glyphs in the font */
  Float32             capHeight;              /* Height of a capital letter from the baseline to the top of the letter */
  Float32             xHeight;                /* Height of lowercase characters in a font, specifically the letter x, excluding ascenders and descenders */
  Float32             italicAngle;            /* Angle in degrees counterclockwise from the vertical of the dominant vertical strokes of the glyphs in the font */
  Float32             underlinePosition;      /* Distance from the baseline for positioning underlining strokes */
  Float32             underlineThickness;     /* Stroke width for underlining */
};
typedef struct ATSFontMetrics           ATSFontMetrics;
enum {
  kATSItalicQDSkew              = (1 << 16) / 4, /* fixed value of 0.25 */
  kATSBoldQDStretch             = (1 << 16) * 3 / 2, /* fixed value of 1.50 */
  kATSRadiansFactor             = 1144  /* fixed value of approx. pi/180 (0.0174560546875) */
};

/* Glyph outline path constants used in ATSFontGetNativeCurveType. */
typedef UInt16 ATSCurveType;
enum {
  kATSCubicCurveType            = 0x0001,
  kATSQuadCurveType             = 0x0002,
  kATSOtherCurveType            = 0x0003
};

struct ATSUCurvePath {
  UInt32              vectors;
  UInt32              controlBits[1];
  Float32Point        vector[1];
};
typedef struct ATSUCurvePath            ATSUCurvePath;
struct ATSUCurvePaths {
  UInt32              contours;
  ATSUCurvePath       contour[1];
};
typedef struct ATSUCurvePaths           ATSUCurvePaths;
/* Glyph ideal metrics */
struct ATSGlyphIdealMetrics {
  Float32Point        advance;
  Float32Point        sideBearing;
  Float32Point        otherSideBearing;
};
typedef struct ATSGlyphIdealMetrics     ATSGlyphIdealMetrics;
/* Glyph screen metrics */
struct ATSGlyphScreenMetrics {
  Float32Point        deviceAdvance;
  Float32Point        topLeft;
  UInt32              height;
  UInt32              width;
  Float32Point        sideBearing;
  Float32Point        otherSideBearing;
};
typedef struct ATSGlyphScreenMetrics    ATSGlyphScreenMetrics;

typedef ATSGlyphRef                     GlyphID;

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

#endif /* __ATSTYPES__ */

