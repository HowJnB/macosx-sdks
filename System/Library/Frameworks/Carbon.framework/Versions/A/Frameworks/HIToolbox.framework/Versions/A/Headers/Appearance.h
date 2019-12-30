/*
     File:       HIToolbox/Appearance.h
 
     Contains:   Appearance Manager Interfaces.
 
     Version:    HIToolbox-145.48~1
 
     Copyright:  � 1994-2003 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __APPEARANCE__
#define __APPEARANCE__

#ifndef __APPLICATIONSERVICES__
#include <ApplicationServices/ApplicationServices.h>
#endif

#ifndef __COLLECTIONS__
#include <CarbonCore/Collections.h>
#endif

#ifndef __PROCESSES__
#include <HIServices/Processes.h>
#endif


/*����������������������������������������������������������������������������������*/
/* Appearance Manager constants, etc.                                               */
/*����������������������������������������������������������������������������������*/
/* Appearance Manager Apple Events (1.1 and later)              */

#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k

enum {
  kAppearanceEventClass         = 'appr', /* Event Class */
  kAEAppearanceChanged          = 'thme', /* Appearance changed (e.g. platinum to hi-tech) */
  kAESystemFontChanged          = 'sysf', /* system font changed */
  kAESmallSystemFontChanged     = 'ssfn', /* small system font changed */
  kAEViewsFontChanged           = 'vfnt' /* views font changed */
};

/*����������������������������������������������������������������������������������*/
/* Appearance Manager file types                                                    */
/*����������������������������������������������������������������������������������*/
enum {
  kThemeDataFileType            = 'thme', /* file type for theme files */
  kThemePlatinumFileType        = 'pltn', /* file type for platinum appearance */
  kThemeCustomThemesFileType    = 'scen', /* file type for user themes */
  kThemeSoundTrackFileType      = 'tsnd'
};

/*����������������������������������������������������������������������������������*/
/* Appearance Manager Supported Themes                                              */
/* Use CopyThemeIdentifier to get the current theme ID                              */
/*����������������������������������������������������������������������������������*/

#define kThemeAppearancePlatinum       CFSTR( "com.apple.theme.appearance.platinum" )
#define kThemeAppearanceAqua         CFSTR( "com.apple.theme.appearance.aqua" )
#define kThemeAppearanceAquaBlue     CFSTR( "com.apple.theme.appearance.aqua.blue" )
#define kThemeAppearanceAquaGraphite    CFSTR( "com.apple.theme.appearance.aqua.graphite" )


/*
 *  AppearancePartCode
 *  
 *  Summary:
 *    These are part codes returned by a few of the hit testing
 *    Appearance APIs. Many of the Control Manager's ControlPartCodes
 *    are based on these part codes.
 */
typedef SInt16 AppearancePartCode;
enum {

  /*
   * This represents the lack of a part. It will be returned when the
   * Appearance Manager's hit testing logic determines that the input
   * point is not in any part of the widget.
   */
  kAppearancePartMetaNone       = 0,

  /*
   * This represents a widget which is not currently clickable because
   * it is disabled.
   */
  kAppearancePartMetaDisabled   = 254,

  /*
   * This represents a widget which is inactive, presumably because it
   * is in a window that is inactive.
   */
  kAppearancePartMetaInactive   = 255,

  /*
   * The part of a widget which indicates the widget's value. Scroll
   * bar thumbs and slider thumbs are the two main examples.
   */
  kAppearancePartIndicator      = 129,

  /*
   * The part of a widget which moves its value visually upward. Scroll
   * bar up arrows are the main example.
   */
  kAppearancePartUpButton       = 20,

  /*
   * The part of a widget which moves its value visually downward.
   * Scroll bar down arrows are the main example.
   */
  kAppearancePartDownButton     = 21,

  /*
   * The part of a widget which moves its value visually leftward.
   * Scroll bar left arrows are the main example.
   */
  kAppearancePartLeftButton     = kAppearancePartUpButton,

  /*
   * The part of a widget which moves its value visually rightward.
   * Scroll bar right arrows are the main example.
   */
  kAppearancePartRightButton    = kAppearancePartDownButton,

  /*
   * The part of a widget which moves its value visually upward one
   * whole page. Scroll bar page up areas are the main example.
   */
  kAppearancePartPageUpArea     = 22,

  /*
   * The part of a widget which moves its value visually downward one
   * whole page. Scroll bar page down areas are the main example.
   */
  kAppearancePartPageDownArea   = 23,

  /*
   * The part of a widget which moves its value visually leftward one
   * whole page. Scroll bar page left areas are the main example.
   */
  kAppearancePartPageLeftArea   = kAppearancePartPageUpArea,

  /*
   * The part of a widget which moves its value visually rightward one
   * whole page. Scroll bar page right areas are the main example.
   */
  kAppearancePartPageRightArea  = kAppearancePartPageDownArea
};



/*
 *  AppearanceRegionCode
 *  
 *  Summary:
 *    These are region codes used by a few of window-related Appearance
 *    APIs. Many of the Window Manager's WindowRegionCodes are based on
 *    these region codes.
 */
typedef UInt16 AppearanceRegionCode;
enum {
  kAppearanceRegionTitleBar     = 0,
  kAppearanceRegionTitleText    = 1,
  kAppearanceRegionCloseBox     = 2,
  kAppearanceRegionZoomBox      = 3,
  kAppearanceRegionDrag         = 5,
  kAppearanceRegionGrow         = 6,
  kAppearanceRegionCollapseBox  = 7,
  kAppearanceRegionTitleProxyIcon = 8,  /* Mac OS 8.5 forward*/
  kAppearanceRegionStructure    = 32,
  kAppearanceRegionContent      = 33    /* Content area of the window; empty when the window is collapsed*/
};


enum {
  kThemeBrushDialogBackgroundActive = 1, /* use with kModalWindowClass */
  kThemeBrushDialogBackgroundInactive = 2, /* use with kModalWindowClass */
  kThemeBrushAlertBackgroundActive = 3, /* use with kAlertWindowClass and kMovableAlertWindowClass */
  kThemeBrushAlertBackgroundInactive = 4, /* use with kAlertWindowClass and kMovableAlertWindowClass */
  kThemeBrushModelessDialogBackgroundActive = 5, /* use with kDocumentWindowClass */
  kThemeBrushModelessDialogBackgroundInactive = 6, /* use with kDocumentWindowClass */
  kThemeBrushUtilityWindowBackgroundActive = 7, /* use with kFloatingWindowClass and kUtilityWindowClass */
  kThemeBrushUtilityWindowBackgroundInactive = 8, /* use with kFloatingWindowClass and kUtilityWindowClass */
  kThemeBrushListViewSortColumnBackground = 9, /* Finder list views */
  kThemeBrushListViewBackground = 10,
  kThemeBrushIconLabelBackground = 11,
  kThemeBrushListViewSeparator  = 12,
  kThemeBrushChasingArrows      = 13,
  kThemeBrushDragHilite         = 14,
  kThemeBrushDocumentWindowBackground = 15, /* use with kDocumentWindowClass */
  kThemeBrushFinderWindowBackground = 16
};

/* Brushes introduced in Appearance 1.1 (Mac OS 8.5) and later */
enum {
  kThemeBrushScrollBarDelimiterActive = 17,
  kThemeBrushScrollBarDelimiterInactive = 18,
  kThemeBrushFocusHighlight     = 19,
  kThemeBrushPopupArrowActive   = 20,
  kThemeBrushPopupArrowPressed  = 21,
  kThemeBrushPopupArrowInactive = 22,
  kThemeBrushAppleGuideCoachmark = 23,
  kThemeBrushIconLabelBackgroundSelected = 24,
  kThemeBrushStaticAreaFill     = 25,
  kThemeBrushActiveAreaFill     = 26,
  kThemeBrushButtonFrameActive  = 27,
  kThemeBrushButtonFrameInactive = 28,
  kThemeBrushButtonFaceActive   = 29,
  kThemeBrushButtonFaceInactive = 30,
  kThemeBrushButtonFacePressed  = 31,
  kThemeBrushButtonActiveDarkShadow = 32,
  kThemeBrushButtonActiveDarkHighlight = 33,
  kThemeBrushButtonActiveLightShadow = 34,
  kThemeBrushButtonActiveLightHighlight = 35,
  kThemeBrushButtonInactiveDarkShadow = 36,
  kThemeBrushButtonInactiveDarkHighlight = 37,
  kThemeBrushButtonInactiveLightShadow = 38,
  kThemeBrushButtonInactiveLightHighlight = 39,
  kThemeBrushButtonPressedDarkShadow = 40,
  kThemeBrushButtonPressedDarkHighlight = 41,
  kThemeBrushButtonPressedLightShadow = 42,
  kThemeBrushButtonPressedLightHighlight = 43,
  kThemeBrushBevelActiveLight   = 44,
  kThemeBrushBevelActiveDark    = 45,
  kThemeBrushBevelInactiveLight = 46,
  kThemeBrushBevelInactiveDark  = 47
};

/* Brushes introduced in Appearance 1.1.1 (Mac OS 9.0) and later */
enum {
  kThemeBrushNotificationWindowBackground = 48
};

/* Brushes introduced in Carbon */
enum {
  kThemeBrushMovableModalBackground = 49, /* use with kMovableModalWindowClass; available in Mac OS X, and CarbonLib 1.3 and later */
  kThemeBrushSheetBackgroundOpaque = 50, /* use with kSheetWindowClass and kSheetAlertWindowClass; available in Mac OS X, and CarbonLib 1.3 and later */
  kThemeBrushDrawerBackground   = 51,   /* use with kDrawerWindowClass; available in Mac OS X, and CarbonLib 1.3 and later */
  kThemeBrushToolbarBackground  = 52,   /* use with kToolbarWindowClass; available in Mac OS X, and CarbonLib 1.6 and later */
  kThemeBrushSheetBackgroundTransparent = 53, /* use with kSheetWindowClass and kSheetAlertWindowClass; available in Mac OS X 10.1 and CarbonLib 1.6, and later */
  kThemeBrushMenuBackground     = 54,   /* available in Mac OS X 10.1 and CarbonLib 1.6, and later */
  kThemeBrushMenuBackgroundSelected = 55 /* available in Mac OS X 10.1 and CarbonLib 1.6, and later */
};

/* Appearance X or later theme brush compatibility synonyms */
enum {
  kThemeBrushSheetBackground    = kThemeBrushSheetBackgroundOpaque
};

/* These values are meta-brushes, specific colors that do not       */
/* change from theme to theme. You can use them instead of using    */
/* direct RGB values.                                               */
enum {
  kThemeBrushBlack              = -1,
  kThemeBrushWhite              = -2,
  kThemeBrushPrimaryHighlightColor = -3, /* available in Mac OS 10.1 and CarbonLib 1.6, and later*/
  kThemeBrushSecondaryHighlightColor = -4, /* available in Mac OS 10.1 and CarbonLib 1.6, and later*/
  kThemeBrushAlternatePrimaryHighlightColor = -5 /* available in Mac OS 10.2 and later*/
};

typedef SInt16                          ThemeBrush;
enum {
  kThemeTextColorDialogActive   = 1,
  kThemeTextColorDialogInactive = 2,
  kThemeTextColorAlertActive    = 3,
  kThemeTextColorAlertInactive  = 4,
  kThemeTextColorModelessDialogActive = 5,
  kThemeTextColorModelessDialogInactive = 6,
  kThemeTextColorWindowHeaderActive = 7,
  kThemeTextColorWindowHeaderInactive = 8,
  kThemeTextColorPlacardActive  = 9,
  kThemeTextColorPlacardInactive = 10,
  kThemeTextColorPlacardPressed = 11,
  kThemeTextColorPushButtonActive = 12,
  kThemeTextColorPushButtonInactive = 13,
  kThemeTextColorPushButtonPressed = 14,
  kThemeTextColorBevelButtonActive = 15,
  kThemeTextColorBevelButtonInactive = 16,
  kThemeTextColorBevelButtonPressed = 17,
  kThemeTextColorPopupButtonActive = 18,
  kThemeTextColorPopupButtonInactive = 19,
  kThemeTextColorPopupButtonPressed = 20,
  kThemeTextColorIconLabel      = 21,
  kThemeTextColorListView       = 22
};

/* Text Colors available in Appearance 1.0.1 or later */
enum {
  kThemeTextColorDocumentWindowTitleActive = 23,
  kThemeTextColorDocumentWindowTitleInactive = 24,
  kThemeTextColorMovableModalWindowTitleActive = 25,
  kThemeTextColorMovableModalWindowTitleInactive = 26,
  kThemeTextColorUtilityWindowTitleActive = 27,
  kThemeTextColorUtilityWindowTitleInactive = 28,
  kThemeTextColorPopupWindowTitleActive = 29,
  kThemeTextColorPopupWindowTitleInactive = 30,
  kThemeTextColorRootMenuActive = 31,
  kThemeTextColorRootMenuSelected = 32,
  kThemeTextColorRootMenuDisabled = 33,
  kThemeTextColorMenuItemActive = 34,
  kThemeTextColorMenuItemSelected = 35,
  kThemeTextColorMenuItemDisabled = 36,
  kThemeTextColorPopupLabelActive = 37,
  kThemeTextColorPopupLabelInactive = 38
};


/* Text colors available in Appearance 1.1 or later */
enum {
  kThemeTextColorTabFrontActive = 39,
  kThemeTextColorTabNonFrontActive = 40,
  kThemeTextColorTabNonFrontPressed = 41,
  kThemeTextColorTabFrontInactive = 42,
  kThemeTextColorTabNonFrontInactive = 43,
  kThemeTextColorIconLabelSelected = 44,
  kThemeTextColorBevelButtonStickyActive = 45,
  kThemeTextColorBevelButtonStickyInactive = 46
};

/* Text colors available in Appearance 1.1.1 or later */
enum {
  kThemeTextColorNotification   = 47
};


/* Text colors only available later than OS X 10.1.3 */
enum {
  kThemeTextColorSystemDetail   = 48
};

/* These values are specific colors that do not change from             */
/* theme to theme. You can use them instead of using direct RGB values. */
enum {
  kThemeTextColorBlack          = -1,
  kThemeTextColorWhite          = -2
};

typedef SInt16                          ThemeTextColor;
/* States to draw primitives: disabled, active, and pressed (hilited) */
enum {
  kThemeStateInactive           = 0,
  kThemeStateActive             = 1,
  kThemeStatePressed            = 2,
  kThemeStateRollover           = 6,
  kThemeStateUnavailable        = 7,
  kThemeStateUnavailableInactive = 8
};

/* obsolete name */
enum {
  kThemeStateDisabled           = 0
};

enum {
  kThemeStatePressedUp          = 2,    /* draw with up pressed     (increment/decrement buttons) */
  kThemeStatePressedDown        = 3     /* draw with down pressed (increment/decrement buttons) */
};

typedef UInt32                          ThemeDrawState;
/*����������������������������������������������������������������������������������*/
/* Theme cursor selectors available in Appearance 1.1 or later                      */
/*����������������������������������������������������������������������������������*/

/*
 */
enum {
  kThemeArrowCursor             = 0,
  kThemeCopyArrowCursor         = 1,
  kThemeAliasArrowCursor        = 2,
  kThemeContextualMenuArrowCursor = 3,
  kThemeIBeamCursor             = 4,
  kThemeCrossCursor             = 5,
  kThemePlusCursor              = 6,
  kThemeWatchCursor             = 7,    /* Can Animate */
  kThemeClosedHandCursor        = 8,
  kThemeOpenHandCursor          = 9,
  kThemePointingHandCursor      = 10,
  kThemeCountingUpHandCursor    = 11,   /* Can Animate */
  kThemeCountingDownHandCursor  = 12,   /* Can Animate */
  kThemeCountingUpAndDownHandCursor = 13, /* Can Animate */
  kThemeSpinningCursor          = 14,   /* Can Animate */
  kThemeResizeLeftCursor        = 15,
  kThemeResizeRightCursor       = 16,
  kThemeResizeLeftRightCursor   = 17,
  kThemeNotAllowedCursor        = 18,   /* available on Mac OS X 10.2 and later */

  /*
   * Available in Mac OS X 10.3 or later.
   */
  kThemeResizeUpCursor          = 19,

  /*
   * Available in Mac OS X 10.3 or later.
   */
  kThemeResizeDownCursor        = 20,

  /*
   * Available in Mac OS X 10.3 or later.
   */
  kThemeResizeUpDownCursor      = 21,

  /*
   * A special cursor to indicate that letting up the mouse will cause
   * a dragged item to go away. When the item goes away, a poof cloud
   * animation should occur. This cursor should be updated dynamically
   * dependeding on whether the mouse up action will remove the item.
   * Available in Mac OS X 10.3 or later.
   */
  kThemePoofCursor              = 22
};

typedef UInt32                          ThemeCursor;
/*����������������������������������������������������������������������������������*/
/* Theme menu bar drawing states                                                    */
/*����������������������������������������������������������������������������������*/
enum {
  kThemeMenuBarNormal           = 0,
  kThemeMenuBarSelected         = 1
};

typedef UInt16                          ThemeMenuBarState;
/* attributes */
enum {
  kThemeMenuSquareMenuBar       = (1 << 0)
};

/*����������������������������������������������������������������������������������*/
/* Theme menu drawing states                                                        */
/*����������������������������������������������������������������������������������*/
enum {
  kThemeMenuActive              = 0,
  kThemeMenuSelected            = 1,
  kThemeMenuDisabled            = 3
};

typedef UInt16                          ThemeMenuState;
/*������������������������������������������������������������������������������������������*/
/* MenuType: add kThemeMenuTypeInactive to menu type for DrawThemeMenuBackground if entire  */
/* menu is inactive                                                                         */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeMenuTypePullDown        = 0,
  kThemeMenuTypePopUp           = 1,
  kThemeMenuTypeHierarchical    = 2,
  kThemeMenuTypeInactive        = 0x0100
};

typedef UInt16                          ThemeMenuType;
enum {
  kThemeMenuItemPlain           = 0,
  kThemeMenuItemHierarchical    = 1,    /* item has hierarchical arrow*/
  kThemeMenuItemScrollUpArrow   = 2,    /* for scrollable menus, indicates item is scroller*/
  kThemeMenuItemScrollDownArrow = 3,
  kThemeMenuItemAtTop           = 0x0100, /* indicates item is being drawn at top of menu*/
  kThemeMenuItemAtBottom        = 0x0200, /* indicates item is being drawn at bottom of menu*/
  kThemeMenuItemHierBackground  = 0x0400, /* item is within a hierarchical menu*/
  kThemeMenuItemPopUpBackground = 0x0800, /* item is within a popped up menu*/
  kThemeMenuItemHasIcon         = 0x8000, /* add into non-arrow type when icon present*/
  kThemeMenuItemNoBackground    = 0x4000 /* don't draw the menu background while drawing this item (Mac OS X only)*/
};

typedef UInt16                          ThemeMenuItemType;
/*������������������������������������������������������������������������������������������*/
/* Theme Backgrounds                                                                        */
/*������������������������������������������������������������������������������������������*/

/*
 */
enum {
  kThemeBackgroundTabPane       = 1,
  kThemeBackgroundPlacard       = 2,
  kThemeBackgroundWindowHeader  = 3,
  kThemeBackgroundListViewWindowHeader = 4,
  kThemeBackgroundSecondaryGroupBox = 5,

  /*
   * A special theme brush for drawing metal backgrounds. Currently,
   * this brush only works with HIThemeApplyBackground.
   */
  kThemeBackgroundMetal         = 6
};

typedef UInt32                          ThemeBackgroundKind;
/*������������������������������������������������������������������������������������������*/
/* Theme Collection tags for Get/SetTheme                                                   */
/*                                                                                          */
/*  X ALERT: Please note that Get/SetTheme are severely neutered under Mac OS X at present. */
/*           The first group of tags below are available to get under both 9 and X. The     */
/*           second group is 9 only. None of the tags can be used in SetTheme on X, as it   */
/*           is completely inert on X, and will return unimpErr.                            */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeNameTag                 = 'name', /* Str255*/
  kThemeVariantNameTag          = 'varn', /* Str255*/
  kThemeVariantBaseTintTag      = 'tint', /* RGBColor (10.1 and later)*/
  kThemeHighlightColorTag       = 'hcol', /* RGBColor*/
  kThemeScrollBarArrowStyleTag  = 'sbar', /* ThemeScrollBarArrowStyle*/
  kThemeScrollBarThumbStyleTag  = 'sbth', /* ThemeScrollBarThumbStyle*/
  kThemeSoundsEnabledTag        = 'snds', /* Boolean*/
  kThemeDblClickCollapseTag     = 'coll' /* Boolean*/
};

enum {
  kThemeAppearanceFileNameTag   = 'thme', /* Str255*/
  kThemeSystemFontTag           = 'lgsf', /* Str255*/
  kThemeSmallSystemFontTag      = 'smsf', /* Str255*/
  kThemeViewsFontTag            = 'vfnt', /* Str255*/
  kThemeViewsFontSizeTag        = 'vfsz', /* SInt16*/
  kThemeDesktopPatternNameTag   = 'patn', /* Str255*/
  kThemeDesktopPatternTag       = 'patt', /* <variable-length data> (flattened pattern)*/
  kThemeDesktopPictureNameTag   = 'dpnm', /* Str255*/
  kThemeDesktopPictureAliasTag  = 'dpal', /* <alias handle>*/
  kThemeDesktopPictureAlignmentTag = 'dpan', /* UInt32 (see the Picture Alignments below)*/
  kThemeHighlightColorNameTag   = 'hcnm', /* Str255*/
  kThemeExamplePictureIDTag     = 'epic', /* SInt16*/
  kThemeSoundTrackNameTag       = 'sndt', /* Str255*/
  kThemeSoundMaskTag            = 'smsk', /* UInt32*/
  kThemeUserDefinedTag          = 'user', /* Boolean (this should _always_ be true if present - used by Control Panel).*/
  kThemeSmoothFontEnabledTag    = 'smoo', /* Boolean*/
  kThemeSmoothFontMinSizeTag    = 'smos' /* UInt16 (must be >= 12 and <= 24)*/
};

/* Picture Aligmnents that might be reported in the data for kThemeDesktopPictureAlignmentTag*/
enum {
  kTiledOnScreen                = 1,    /* draws picture repeatedly*/
  kCenterOnScreen               = 2,    /* "actual size", shows pattern on sides or clips picture if necessary*/
  kFitToScreen                  = 3,    /* shrinks if necessary*/
  kFillScreen                   = 4,    /* messes up aspect ratio if necessary*/
  kUseBestGuess                 = 5     /* heuristically determines the best way to display the picture based on picture and monitor sizes*/
};

/*������������������������������������������������������������������������������������������*/
/* Theme Control Settings                                                                   */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeCheckBoxClassicX        = 0,    /* check box with an 'X'*/
  kThemeCheckBoxCheckMark       = 1     /* check box with a real check mark*/
};

typedef UInt16                          ThemeCheckBoxStyle;
enum {
  kThemeScrollBarArrowsSingle   = 0,    /* single arrow on each end*/
  kThemeScrollBarArrowsLowerRight = 1   /* double arrows only on right or bottom*/
};

typedef UInt16                          ThemeScrollBarArrowStyle;
enum {
  kThemeScrollBarThumbNormal    = 0,    /* normal, classic thumb size*/
  kThemeScrollBarThumbProportional = 1  /* proportional thumbs*/
};

typedef UInt16                          ThemeScrollBarThumbStyle;
/*������������������������������������������������������������������������������������������*/
/* Font constants                                                                           */
/*������������������������������������������������������������������������������������������*/

/*
 *  Summary:
 *    A ThemeFontID value is a virtual font ID which can be passed to
 *    one of the Appearance Manager's text-related routines. Within
 *    those routines, the ThemeFontID is mapped into the appropriate
 *    real font (or fonts), size, and style based on the system
 *    appearance (Platinum on Mac OS 9, Aqua on Mac OS X), the string
 *    to be rendered (if any), the language/ script that the app is
 *    running in, and possibly other factors. The ThemeFontIDs allow
 *    you to get the correct text appearance for the platform your app
 *    is currently running on.
 */
enum {

  /*
   * The font used to draw most interface elements. If you can't find a
   * more appropriate font from the list below, you should use this
   * one. This font is suitable for drawing titles on most custom
   * widgets/buttons, as well as most static text in dialogs and
   * windows.
   */
  kThemeSystemFont              = 0,

  /*
   * The font used to draw interface elements when space is at a
   * premium. It draws a slightly smaller font compared to
   * kThemeSystemFont.
   */
  kThemeSmallSystemFont         = 1,

  /*
   * Identical to kThemeSmallSystemFont, except it draws bolded (or
   * otherwise emphasized in some fashion appropriate to your
   * application's language/script).
   */
  kThemeSmallEmphasizedSystemFont = 2,

  /*
   * The font used to draw file and folder names in Finder windows or
   * other browsable lists.
   */
  kThemeViewsFont               = 3,    /* The following ID's are only available with MacOS X or CarbonLib 1.3 and later*/

  /*
   * Identical to kThemeSystemFont, except it draws bolded (or
   * otherwise emphasized in some fashion appropriate to your
   * application's language/script). Only available on Mac OS X or
   * CarbonLib 1.3 or later.
   */
  kThemeEmphasizedSystemFont    = 4,

  /*
   * An analog to the Script Manager's notion of the Application Font.
   * This font is a suitable default choice for your application's
   * document-style text editing areas. Only available on Mac OS X or
   * CarbonLib 1.3 or later.
   */
  kThemeApplicationFont         = 5,

  /*
   * Generally smaller than kThemeSmallSystemFont, this font is
   * appropriate for drawing text labels next to image content that
   * reinforces the text's meaning (such as on a bevel button). Only
   * available on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeLabelFont               = 6,

  /*
   * The font used to draw menu titles in the menu bar. Only available
   * on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeMenuTitleFont           = 100,

  /*
   * The font used to draw menu items in the menus. Only available on
   * Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeMenuItemFont            = 101,

  /*
   * The font used to draw menu item marks in the menus. Only available
   * on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeMenuItemMarkFont        = 102,

  /*
   * The font used to draw menu item command key equivalents in the
   * menus. Only available on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeMenuItemCmdKeyFont      = 103,

  /*
   * The font used to draw text in most window title bars. Only
   * available on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeWindowTitleFont         = 104,

  /*
   * The font used to draw text labels on push buttons. Only available
   * on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemePushButtonFont          = 105,

  /*
   * The font used to draw text in utility window title bars. Only
   * available on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeUtilityWindowTitleFont  = 106,

  /*
   * The font used to draw the first (and most important) message of an
   * alert window. Only available on Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeAlertHeaderFont         = 107,
  kThemeSystemFontDetail        = 7,
  kThemeSystemFontDetailEmphasized = 8,

  /*
   * Unlike the other ThemeFontIDs, this one doesn't map to a font
   * appropriate to your application's language or script. It maps
   * directly to the font, size, and style of the current Quickdraw
   * port. This allows you to get somewhat customized behavior out of
   * the APIs which take ThemeFontIDs. Note, however, that
   * kThemeCurrentPortFont does not (and will never) support all
   * Quickdraw styles on all platforms; in particular, outline and
   * shadow style are not supported on Mac OS X. Additionally,
   * kThemeCurrentPortFont is not (and will never be) completely
   * unicode savvy; use of kThemeCurrentPortFont may result in errors
   * having to do with the current port's font not being appropriate
   * for rendering or measuring all glyphs in a given unicode string.
   * Because of overhead associated with gathering Quickdraw font
   * information and converting it to the native font format on Mac OS
   * X, use of kThemeCurrentPortFont may slow down your text drawing
   * and measuring significantly compared to other ThemeFontIDs.
   * Instead of using kThemeCurrentPortFont, your application will
   * probably be better served by using one of the other ThemeFontIDs;
   * use kThemeCurrentPortFont only as a last resort. Only available on
   * Mac OS X or CarbonLib 1.3 or later.
   */
  kThemeCurrentPortFont         = 200,

  /*
   * The font used to draw the label of a toolbar item. Available in
   * Mac OS X 10.2 or later.
   */
  kThemeToolbarFont             = 108,

  /*
   * The appropriate system font for mini-sized controls. Available in
   * Mac OS X 10.3 or later.
   */
  kThemeMiniSystemFont          = 109
};

/* This is the total of the PUBLIC ThemeFontIDs!*/
enum {
  kPublicThemeFontCount         = 20
};

typedef UInt16                          ThemeFontID;
/*������������������������������������������������������������������������������������������*/
/* Tab constants                                                                            */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeTabNonFront             = 0,
  kThemeTabNonFrontPressed      = 1,
  kThemeTabNonFrontInactive     = 2,
  kThemeTabFront                = 3,
  kThemeTabFrontInactive        = 4,
  kThemeTabNonFrontUnavailable  = 5,
  kThemeTabFrontUnavailable     = 6
};

typedef UInt16                          ThemeTabStyle;
enum {
  kThemeTabNorth                = 0,
  kThemeTabSouth                = 1,
  kThemeTabEast                 = 2,
  kThemeTabWest                 = 3
};

typedef UInt16                          ThemeTabDirection;

/*
 *  Summary:
 *    Deprecated tab height and overlap constants.
 *  
 *  Discussion:
 *    These constants have been deprecated in favor of theme metrics.
 *    Please do not use them anymore. These constants will be removed
 *    in the next major release of OS X.
 */
enum {

  /*
   * Deprecated. Use kThemeMetricSmallTabHeight.
   */
  kThemeSmallTabHeight          = 16,

  /*
   * Deprecated. Use kThemeMetricLargeTabHeight.
   */
  kThemeLargeTabHeight          = 21,

  /*
   * Deprecated. Use kThemeMetricTabFrameOverlap.
   */
  kThemeTabPaneOverlap          = 3,

  /*
   * Deprecated. Use kThemeMetricSmallTabHeight and
   * kThemeMetricSmallTabFrameOverlap.
   */
  kThemeSmallTabHeightMax       = 19,

  /*
   * Deprecated. Use metric kThemeMetricLargeTabHeight and
   * kThemeMetricTabFrameOverlap.
   */
  kThemeLargeTabHeightMax       = 24
};

/*������������������������������������������������������������������������������������������*/
/* Track kinds                                                                              */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeMediumScrollBar         = 0,
  kThemeSmallScrollBar          = 1,
  kThemeMediumSlider            = 2,
  kThemeMediumProgressBar       = 3,
  kThemeMediumIndeterminateBar  = 4,
  kThemeRelevanceBar            = 5,
  kThemeSmallSlider             = 6,
  kThemeLargeProgressBar        = 7,
  kThemeLargeIndeterminateBar   = 8
};


/*
 *  Discussion:
 *    New TThemeTrackKinds on Mac OS X 10.3 and later. Not all of them
 *    are implemented.
 */
enum {

  /*
   * Not implemented. Will return paramErr if used.
   */
  kThemeMiniScrollBar           = 9,

  /*
   * A miniature version of the slider.
   */
  kThemeMiniSlider              = 10,

  /*
   * Not implemented. Will return paramErr if used.
   */
  kThemeMiniProgressBar         = 11,

  /*
   * Not implemented. Will return paramErr if used.
   */
  kThemeMiniIndeterminateBar    = 12
};

typedef UInt16                          ThemeTrackKind;
/*������������������������������������������������������������������������������������������*/
/* Track enable states                                                                      */
/*������������������������������������������������������������������������������������������*/
enum {
                                        /* track states */
  kThemeTrackActive             = 0,
  kThemeTrackDisabled           = 1,
  kThemeTrackNothingToScroll    = 2,
  kThemeTrackInactive           = 3
};

typedef UInt8                           ThemeTrackEnableState;
/*������������������������������������������������������������������������������������������*/
/* Track pressed states                                                                     */
/*������������������������������������������������������������������������������������������*/
enum {
                                        /* press states (ignored unless track is active) */
  kThemeLeftOutsideArrowPressed = 0x01,
  kThemeLeftInsideArrowPressed  = 0x02,
  kThemeLeftTrackPressed        = 0x04,
  kThemeThumbPressed            = 0x08,
  kThemeRightTrackPressed       = 0x10,
  kThemeRightInsideArrowPressed = 0x20,
  kThemeRightOutsideArrowPressed = 0x40,
  kThemeTopOutsideArrowPressed  = kThemeLeftOutsideArrowPressed,
  kThemeTopInsideArrowPressed   = kThemeLeftInsideArrowPressed,
  kThemeTopTrackPressed         = kThemeLeftTrackPressed,
  kThemeBottomTrackPressed      = kThemeRightTrackPressed,
  kThemeBottomInsideArrowPressed = kThemeRightInsideArrowPressed,
  kThemeBottomOutsideArrowPressed = kThemeRightOutsideArrowPressed
};

typedef UInt8                           ThemeTrackPressState;
/*������������������������������������������������������������������������������������������*/
/* Thumb directions                                                                         */
/*������������������������������������������������������������������������������������������*/
enum {
                                        /* thumb direction */
  kThemeThumbPlain              = 0,
  kThemeThumbUpward             = 1,
  kThemeThumbDownward           = 2
};

typedef UInt8                           ThemeThumbDirection;
/*������������������������������������������������������������������������������������������*/
/* Track attributes                                                                         */
/*������������������������������������������������������������������������������������������*/

/*
 *  Discussion:
 *    Theme track attributes control the look of the track elements as
 *    drawn by the DrawThemeTrackFoo as well as the region returned by
 *    GetThemeTrackFoo.
 */
enum {

  /*
   * The track is drawn horizontally.
   */
  kThemeTrackHorizontal         = (1 << 0),

  /*
   * The track progresses from right to left.
   */
  kThemeTrackRightToLeft        = (1 << 1),

  /*
   * The track's thumb should be drawn.
   */
  kThemeTrackShowThumb          = (1 << 2),

  /*
   * The provided thumbRgn should be drawn opaque, not as a ghost.
   */
  kThemeTrackThumbRgnIsNotGhost = (1 << 3),

  /*
   * The track scroll bar doesn't have arrows.  This attribute
   * currently has no effect
   */
  kThemeTrackNoScrollBarArrows  = (1 << 4),

  /*
   * The thumb has focus.  This attribute currently has effect only on
   * sliders.  Available only in Mac OS X after 10.1.
   */
  kThemeTrackHasFocus           = (1 << 5)
};

typedef UInt16                          ThemeTrackAttributes;
/*������������������������������������������������������������������������������������������*/
/* Track info block                                                                         */
/*������������������������������������������������������������������������������������������*/
struct ScrollBarTrackInfo {
  SInt32              viewsize;               /* current view range size */
  ThemeTrackPressState  pressState;           /* pressed parts state */
};
typedef struct ScrollBarTrackInfo       ScrollBarTrackInfo;
struct SliderTrackInfo {
  ThemeThumbDirection  thumbDir;              /* thumb direction */
  ThemeTrackPressState  pressState;           /* pressed parts state */
};
typedef struct SliderTrackInfo          SliderTrackInfo;
struct ProgressTrackInfo {
  UInt8               phase;                  /* phase for indeterminate progress */
};
typedef struct ProgressTrackInfo        ProgressTrackInfo;
struct ThemeTrackDrawInfo {
  ThemeTrackKind      kind;                   /* what kind of track this info is for */
  Rect                bounds;                 /* track basis rectangle */
  SInt32              min;                    /* min track value */
  SInt32              max;                    /* max track value */
  SInt32              value;                  /* current thumb value */
  UInt32              reserved;

  ThemeTrackAttributes  attributes;           /* various track attributes */
  ThemeTrackEnableState  enableState;         /* enable state */
  UInt8               filler1;

  union {
    ScrollBarTrackInfo  scrollbar;
    SliderTrackInfo     slider;
    ProgressTrackInfo   progress;
  }                       trackInfo;
};
typedef struct ThemeTrackDrawInfo       ThemeTrackDrawInfo;
/*������������������������������������������������������������������������������������������*/
/* ThemeWindowAttributes                                                                    */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeWindowHasGrow           = (1 << 0), /* can the size of the window be changed by the user? */
  kThemeWindowHasHorizontalZoom = (1 << 3), /* window can zoom only horizontally */
  kThemeWindowHasVerticalZoom   = (1 << 4), /* window can zoom only vertically */
  kThemeWindowHasFullZoom       = kThemeWindowHasHorizontalZoom + kThemeWindowHasVerticalZoom, /* window zooms in all directions */
  kThemeWindowHasCloseBox       = (1 << 5), /* window has a close box */
  kThemeWindowHasCollapseBox    = (1 << 6), /* window has a collapse box */
  kThemeWindowHasTitleText      = (1 << 7), /* window has a title/title icon */
  kThemeWindowIsCollapsed       = (1 << 8), /* window is in the collapsed state */
  kThemeWindowHasDirty          = (1 << 9)
};


typedef UInt32                          ThemeWindowAttributes;
/*������������������������������������������������������������������������������������������*/
/* Window Types Supported by the Appearance Manager                                         */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeDocumentWindow          = 0,
  kThemeDialogWindow            = 1,
  kThemeMovableDialogWindow     = 2,
  kThemeAlertWindow             = 3,
  kThemeMovableAlertWindow      = 4,
  kThemePlainDialogWindow       = 5,
  kThemeShadowDialogWindow      = 6,
  kThemePopupWindow             = 7,
  kThemeUtilityWindow           = 8,
  kThemeUtilitySideWindow       = 9,
  kThemeSheetWindow             = 10,
  kThemeDrawerWindow            = 11
};

typedef UInt16                          ThemeWindowType;
/*������������������������������������������������������������������������������������������*/
/* Window Widgets Supported by the Appearance Manager                                       */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeWidgetCloseBox          = 0,
  kThemeWidgetZoomBox           = 1,
  kThemeWidgetCollapseBox       = 2,
  kThemeWidgetDirtyCloseBox     = 6
};

enum {
                                        /* Old/Obsolete name to be removed*/
  kThemeWidgetABox              = 3,
  kThemeWidgetBBox              = 4,
  kThemeWidgetBOffBox           = 5
};

typedef UInt16                          ThemeTitleBarWidget;
/*������������������������������������������������������������������������������������������*/
/* Popup arrow orientations                                                                 */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeArrowLeft               = 0,
  kThemeArrowDown               = 1,
  kThemeArrowRight              = 2,
  kThemeArrowUp                 = 3
};

typedef UInt16                          ThemeArrowOrientation;
/*������������������������������������������������������������������������������������������*/
/* Popup arrow sizes                                                                        */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeArrow3pt                = 0,
  kThemeArrow5pt                = 1,
  kThemeArrow7pt                = 2,
  kThemeArrow9pt                = 3
};

typedef UInt16                          ThemePopupArrowSize;
/*������������������������������������������������������������������������������������������*/
/* Grow box directions                                                                      */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeGrowLeft                = (1 << 0), /* can grow to the left */
  kThemeGrowRight               = (1 << 1), /* can grow to the right */
  kThemeGrowUp                  = (1 << 2), /* can grow up */
  kThemeGrowDown                = (1 << 3) /* can grow down */
};

typedef UInt16                          ThemeGrowDirection;
/*������������������������������������������������������������������������������������������*/
/* Button kinds                                                                             */
/*������������������������������������������������������������������������������������������*/

/*
 *  Discussion:
 *    ThemeButtonKinds
 */
enum {

  /*
   * Dynamically-sized push button kind. Prior to Mac OS X 10.3 all
   * push button sizes could be determined dynamically: either they
   * were smaller than normal size and therefore small or they were
   * normal size. This constant will never describe a mini push button,
   * regardless of associated bounds. Please use the explicitly-sized
   * kThemePushButton{Normal,Small,Mini} constants.
   */
  kThemePushButton              = 0,
  kThemeCheckBox                = 1,
  kThemeRadioButton             = 2,

  /*
   * Bevel button (obsolete)
   */
  kThemeBevelButton             = 3,

  /*
   * Popup button without text (no label). See ThemeButtonAdornment for
   * glyphs. The arrow button theme name is somewhat confusing. This is
   * the primitive used to draw the control known as the disclosure
   * button.
   */
  kThemeArrowButton             = 4,

  /*
   * Dynamically-sized popup button kind. Prior to Mac OS X 10.3 all
   * popup button sizes could be determined dynamically: either they
   * were smaller than normal size and therefore small or they were
   * normal size. This constant will never describe a mini popup
   * button, regardless of associated bounds. Please use the
   * explicitly-sized kThemePopupButton{Normal,Small,Mini} constants.
   */
  kThemePopupButton             = 5,
  kThemeDisclosureButton        = 6,

  /*
   * Increment/decrement buttons (no label). This is the primitive used
   * to draw the LittleArrows control.
   */
  kThemeIncDecButton            = 7,

  /*
   * Small-shadow bevel button
   */
  kThemeSmallBevelButton        = 8,

  /*
   * Med-shadow bevel button
   */
  kThemeMediumBevelButton       = 3,

  /*
   * Large-shadow bevel button
   */
  kThemeLargeBevelButton        = 9,

  /*
   * Sort button for top of a list. This is the theme primitive used to
   * draw the top of the columns in the data browser.
   */
  kThemeListHeaderButton        = 10,
  kThemeRoundButton             = 11,
  kThemeLargeRoundButton        = 12,
  kThemeSmallCheckBox           = 13,
  kThemeSmallRadioButton        = 14,
  kThemeRoundedBevelButton      = 15,
  kThemeComboBox                = 16,
  kThemeComboBoxSmall           = 17
};


/*
 *  Discussion:
 *    New ThemeButtonKinds available on Mac OS X 10.3 and later.
 */
enum {
  kThemeComboBoxMini            = 18,
  kThemeMiniCheckBox            = 19,
  kThemeMiniRadioButton         = 20,

  /*
   * This is the primitive used to draw the small variant of the
   * LittleArrows control.
   */
  kThemeIncDecButtonSmall       = 21,

  /*
   * This is the primitive used to draw the mini variant of the
   * LittleArrows control.
   */
  kThemeIncDecButtonMini        = 22,

  /*
   * The arrow button theme name is somewhat confusing. This is the
   * primitive used to draw the small variant of the control known as
   * the disclosure button.
   */
  kThemeArrowButtonSmall        = 23,

  /*
   * The arrow button theme name is somewhat confusing. This is the
   * primitive used to draw the mini variant of the control known as
   * the disclosure button.
   */
  kThemeArrowButtonMini         = 24,

  /*
   * Explicitly-sized normal push button kind. Prior to Mac OS X 10.3
   * all push button sizes could be determined dynamically: either they
   * were smaller than normal size and therefore small or they were
   * normal size. Using this constant, an explicitly-sized normal push
   * button can be specified.
   */
  kThemePushButtonNormal        = 25,

  /*
   * Explicitly-sized small push button kind. Prior to Mac OS X 10.3
   * all push button sizes could be determined dynamically: either they
   * were smaller than normal size and therefore small or they were
   * normal size. Using this constant, an explicitly-sized small push
   * button can be specified.
   */
  kThemePushButtonSmall         = 26,

  /*
   * Explicitly-sized mini push button kind. Prior to Mac OS X 10.3 all
   * push button sizes could be determined dynamically: either they
   * were smaller than normal size and therefore small or they were
   * normal size. Since a mini variant was introduced in Mac OS X 10.3,
   * smaller than normal size is can also mean mini. To avoid confusion
   * with existing code, the mini variant will never be implicitly
   * determined and must be explicity requested with the
   * kThemePushButtonMini constant.
   */
  kThemePushButtonMini          = 27,

  /*
   * Explicitly-sized normal popup button kind. Prior to Mac OS X 10.3
   * all popup button sizes could be determined dynamically: either
   * they were smaller than normal size and therefore small or they
   * were normal size. Using this constant, an explicitly-sized normal
   * popup button can be specified.
   */
  kThemePopupButtonNormal       = 28,

  /*
   * Explicitly-sized small popup button kind. Prior to Mac OS X 10.3
   * all popup button sizes could be determined dynamically: either
   * they were smaller than normal size and therefore small or they
   * were normal size. Using this constant, an explicitly-sized small
   * popup button can be specified.
   */
  kThemePopupButtonSmall        = 29,

  /*
   * Explicitly-sized mini popup button kind. Prior to Mac OS X 10.3
   * all popup button sizes could be determined dynamically: either
   * they were smaller than normal size and therefore small or they
   * were normal size. Since a mini variant was introduced in Mac OS X
   * 10.3, smaller than normal size is can also mean mini. To avoid
   * confusion with existing code, the mini variant will never be
   * implicitly determined and must be explicity requested with the
   * kThemePopupButtonMini constant.
   */
  kThemePopupButtonMini         = 30
};


/*
 *  Discussion:
 *    These are legacy synonyms for previously defined
 *    ThemeButtonKinds. Please use the modern constant names.
 */
enum {
  kThemeNormalCheckBox          = kThemeCheckBox,
  kThemeNormalRadioButton       = kThemeRadioButton
};

typedef UInt16                          ThemeButtonKind;
/*������������������������������������������������������������������������������������������*/
/* Common button values                                                                     */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeButtonOff               = 0,
  kThemeButtonOn                = 1,
  kThemeButtonMixed             = 2,
  kThemeDisclosureRight         = 0,
  kThemeDisclosureDown          = 1,
  kThemeDisclosureLeft          = 2
};

typedef UInt16                          ThemeButtonValue;
/*������������������������������������������������������������������������������������������*/
/* Button adornment types                                                                   */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeAdornmentNone           = 0,
  kThemeAdornmentDefault        = (1 << 0), /* if set, draw default ornamentation ( for push button and generic well ) */
  kThemeAdornmentFocus          = (1 << 2), /* if set, draw focus */
  kThemeAdornmentRightToLeft    = (1 << 4), /* if set, draw right to left label */
  kThemeAdornmentDrawIndicatorOnly = (1 << 5), /* if set, don't draw or erase label ( radio, check, disclosure ) */
  kThemeAdornmentHeaderButtonLeftNeighborSelected = (1 << 6), /* if set, draw the left border of the button as selected ( list header button only ) */
  kThemeAdornmentHeaderButtonRightNeighborSelected = (1 << 7), /* if set, draw the right border of the button ( list header button only ) */
  kThemeAdornmentHeaderButtonSortUp = (1 << 8), /* if set, draw the sort indicator pointing upward ( list header button only ) */
  kThemeAdornmentHeaderMenuButton = (1 << 9), /* if set, draw as a header menu button ( list header button only ) */
  kThemeAdornmentHeaderButtonNoShadow = (1 << 10), /* if set, draw the non-shadow area of the button ( list header button only ) */
  kThemeAdornmentHeaderButtonShadowOnly = (1 << 11), /* if set, draw the only the shadow area of the button ( list header button only ) */
  kThemeAdornmentNoShadow       = kThemeAdornmentHeaderButtonNoShadow, /* old name */
  kThemeAdornmentShadowOnly     = kThemeAdornmentHeaderButtonShadowOnly, /* old name */
  kThemeAdornmentArrowLeftArrow = (1 << 6), /* If set, draw a left arrow on the arrow button */
  kThemeAdornmentArrowDownArrow = (1 << 7), /* If set, draw a down arrow on the arrow button */
  kThemeAdornmentArrowDoubleArrow = (1 << 8), /* If set, draw a double arrow on the arrow button */
  kThemeAdornmentArrowUpArrow   = (1 << 9) /* If set, draw a up arrow on the arrow button */
};

typedef UInt16                          ThemeButtonAdornment;
/*������������������������������������������������������������������������������������������*/
/* Button drawing info block                                                                */
/*������������������������������������������������������������������������������������������*/
struct ThemeButtonDrawInfo {
  ThemeDrawState      state;
  ThemeButtonValue    value;
  ThemeButtonAdornment  adornment;
};
typedef struct ThemeButtonDrawInfo      ThemeButtonDrawInfo;
typedef ThemeButtonDrawInfo *           ThemeButtonDrawInfoPtr;
/*������������������������������������������������������������������������������������������*/
/* Sound Support                                                                            */
/*                                                                                          */
/*  X ALERT: Please note that none of the theme sound APIs currently function on X.         */
/*������������������������������������������������������������������������������������������*/
/*������������������������������������������������������������������������������������������*/
/* Sound classes                                                                            */
/*                                                                                          */
/* You can use the constants below to set what sounds are active using the SetTheme API.    */
/* Use these with the kThemeSoundMask tag.                                                  */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeNoSounds                = 0,
  kThemeWindowSoundsMask        = (1 << 0),
  kThemeMenuSoundsMask          = (1 << 1),
  kThemeControlSoundsMask       = (1 << 2),
  kThemeFinderSoundsMask        = (1 << 3)
};


/*������������������������������������������������������������������������������������������*/
/* Drag Sounds                                                                              */
/*                                                                                          */
/* Drag sounds are looped for the duration of the drag.                                     */
/*                                                                                          */
/* Call BeginThemeDragSound at the start of the drag.                                       */
/* Call EndThemeDragSound when the drag has finished.                                       */
/*                                                                                          */
/* Note that in order to maintain a consistent user experience, only one drag sound may     */
/* occur at a time.  The sound should be attached to a mouse action, start after the        */
/* mouse goes down and stop when the mouse is released.                                     */
/*������������������������������������������������������������������������������������������*/
enum {
  kThemeDragSoundNone           = 0,
  kThemeDragSoundMoveWindow     = 'wmov',
  kThemeDragSoundGrowWindow     = 'wgro',
  kThemeDragSoundMoveUtilWindow = 'umov',
  kThemeDragSoundGrowUtilWindow = 'ugro',
  kThemeDragSoundMoveDialog     = 'dmov',
  kThemeDragSoundMoveAlert      = 'amov',
  kThemeDragSoundMoveIcon       = 'imov',
  kThemeDragSoundSliderThumb    = 'slth',
  kThemeDragSoundSliderGhost    = 'slgh',
  kThemeDragSoundScrollBarThumb = 'sbth',
  kThemeDragSoundScrollBarGhost = 'sbgh',
  kThemeDragSoundScrollBarArrowDecreasing = 'sbad',
  kThemeDragSoundScrollBarArrowIncreasing = 'sbai',
  kThemeDragSoundDragging       = 'drag'
};

typedef OSType                          ThemeDragSoundKind;
/*��������������������������������������������������������������������������*/
/* State-change sounds                                                      */
/*                                                                          */
/* State-change sounds are played asynchonously as a one-shot.              */
/*                                                                          */
/* Call PlayThemeSound to play the sound.  The sound will play              */
/* asynchronously until complete, then stop automatically.                  */
/*��������������������������������������������������������������������������*/
enum {
  kThemeSoundNone               = 0,
  kThemeSoundMenuOpen           = 'mnuo', /* menu sounds */
  kThemeSoundMenuClose          = 'mnuc',
  kThemeSoundMenuItemHilite     = 'mnui',
  kThemeSoundMenuItemRelease    = 'mnus',
  kThemeSoundWindowClosePress   = 'wclp', /* window sounds */
  kThemeSoundWindowCloseEnter   = 'wcle',
  kThemeSoundWindowCloseExit    = 'wclx',
  kThemeSoundWindowCloseRelease = 'wclr',
  kThemeSoundWindowZoomPress    = 'wzmp',
  kThemeSoundWindowZoomEnter    = 'wzme',
  kThemeSoundWindowZoomExit     = 'wzmx',
  kThemeSoundWindowZoomRelease  = 'wzmr',
  kThemeSoundWindowCollapsePress = 'wcop',
  kThemeSoundWindowCollapseEnter = 'wcoe',
  kThemeSoundWindowCollapseExit = 'wcox',
  kThemeSoundWindowCollapseRelease = 'wcor',
  kThemeSoundWindowDragBoundary = 'wdbd',
  kThemeSoundUtilWinClosePress  = 'uclp', /* utility window sounds */
  kThemeSoundUtilWinCloseEnter  = 'ucle',
  kThemeSoundUtilWinCloseExit   = 'uclx',
  kThemeSoundUtilWinCloseRelease = 'uclr',
  kThemeSoundUtilWinZoomPress   = 'uzmp',
  kThemeSoundUtilWinZoomEnter   = 'uzme',
  kThemeSoundUtilWinZoomExit    = 'uzmx',
  kThemeSoundUtilWinZoomRelease = 'uzmr',
  kThemeSoundUtilWinCollapsePress = 'ucop',
  kThemeSoundUtilWinCollapseEnter = 'ucoe',
  kThemeSoundUtilWinCollapseExit = 'ucox',
  kThemeSoundUtilWinCollapseRelease = 'ucor',
  kThemeSoundUtilWinDragBoundary = 'udbd',
  kThemeSoundWindowOpen         = 'wopn', /* window close and zoom action */
  kThemeSoundWindowClose        = 'wcls',
  kThemeSoundWindowZoomIn       = 'wzmi',
  kThemeSoundWindowZoomOut      = 'wzmo',
  kThemeSoundWindowCollapseUp   = 'wcol',
  kThemeSoundWindowCollapseDown = 'wexp',
  kThemeSoundWindowActivate     = 'wact',
  kThemeSoundUtilWindowOpen     = 'uopn',
  kThemeSoundUtilWindowClose    = 'ucls',
  kThemeSoundUtilWindowZoomIn   = 'uzmi',
  kThemeSoundUtilWindowZoomOut  = 'uzmo',
  kThemeSoundUtilWindowCollapseUp = 'ucol',
  kThemeSoundUtilWindowCollapseDown = 'uexp',
  kThemeSoundUtilWindowActivate = 'uact',
  kThemeSoundDialogOpen         = 'dopn',
  kThemeSoundDialogClose        = 'dlgc',
  kThemeSoundAlertOpen          = 'aopn',
  kThemeSoundAlertClose         = 'altc',
  kThemeSoundPopupWindowOpen    = 'pwop',
  kThemeSoundPopupWindowClose   = 'pwcl',
  kThemeSoundButtonPress        = 'btnp', /* button */
  kThemeSoundButtonEnter        = 'btne',
  kThemeSoundButtonExit         = 'btnx',
  kThemeSoundButtonRelease      = 'btnr',
  kThemeSoundDefaultButtonPress = 'dbtp', /* default button */
  kThemeSoundDefaultButtonEnter = 'dbte',
  kThemeSoundDefaultButtonExit  = 'dbtx',
  kThemeSoundDefaultButtonRelease = 'dbtr',
  kThemeSoundCancelButtonPress  = 'cbtp', /* cancel button */
  kThemeSoundCancelButtonEnter  = 'cbte',
  kThemeSoundCancelButtonExit   = 'cbtx',
  kThemeSoundCancelButtonRelease = 'cbtr',
  kThemeSoundCheckboxPress      = 'chkp', /* checkboxes */
  kThemeSoundCheckboxEnter      = 'chke',
  kThemeSoundCheckboxExit       = 'chkx',
  kThemeSoundCheckboxRelease    = 'chkr',
  kThemeSoundRadioPress         = 'radp', /* radio buttons */
  kThemeSoundRadioEnter         = 'rade',
  kThemeSoundRadioExit          = 'radx',
  kThemeSoundRadioRelease       = 'radr',
  kThemeSoundScrollArrowPress   = 'sbap', /* scroll bars */
  kThemeSoundScrollArrowEnter   = 'sbae',
  kThemeSoundScrollArrowExit    = 'sbax',
  kThemeSoundScrollArrowRelease = 'sbar',
  kThemeSoundScrollEndOfTrack   = 'sbte',
  kThemeSoundScrollTrackPress   = 'sbtp',
  kThemeSoundSliderEndOfTrack   = 'slte', /* sliders */
  kThemeSoundSliderTrackPress   = 'sltp',
  kThemeSoundBalloonOpen        = 'blno', /* help balloons */
  kThemeSoundBalloonClose       = 'blnc',
  kThemeSoundBevelPress         = 'bevp', /* Bevel buttons */
  kThemeSoundBevelEnter         = 'beve',
  kThemeSoundBevelExit          = 'bevx',
  kThemeSoundBevelRelease       = 'bevr',
  kThemeSoundLittleArrowUpPress = 'laup', /* Little Arrows */
  kThemeSoundLittleArrowDnPress = 'ladp',
  kThemeSoundLittleArrowEnter   = 'lare',
  kThemeSoundLittleArrowExit    = 'larx',
  kThemeSoundLittleArrowUpRelease = 'laur',
  kThemeSoundLittleArrowDnRelease = 'ladr',
  kThemeSoundPopupPress         = 'popp', /* Popup Buttons */
  kThemeSoundPopupEnter         = 'pope',
  kThemeSoundPopupExit          = 'popx',
  kThemeSoundPopupRelease       = 'popr',
  kThemeSoundDisclosurePress    = 'dscp', /* Disclosure Buttons */
  kThemeSoundDisclosureEnter    = 'dsce',
  kThemeSoundDisclosureExit     = 'dscx',
  kThemeSoundDisclosureRelease  = 'dscr',
  kThemeSoundTabPressed         = 'tabp', /* Tabs */
  kThemeSoundTabEnter           = 'tabe',
  kThemeSoundTabExit            = 'tabx',
  kThemeSoundTabRelease         = 'tabr',
  kThemeSoundDragTargetHilite   = 'dthi', /* drag manager */
  kThemeSoundDragTargetUnhilite = 'dtuh',
  kThemeSoundDragTargetDrop     = 'dtdr',
  kThemeSoundEmptyTrash         = 'ftrs', /* finder */
  kThemeSoundSelectItem         = 'fsel',
  kThemeSoundNewItem            = 'fnew',
  kThemeSoundReceiveDrop        = 'fdrp',
  kThemeSoundCopyDone           = 'fcpd',
  kThemeSoundResolveAlias       = 'fral',
  kThemeSoundLaunchApp          = 'flap',
  kThemeSoundDiskInsert         = 'dski',
  kThemeSoundDiskEject          = 'dske',
  kThemeSoundFinderDragOnIcon   = 'fdon',
  kThemeSoundFinderDragOffIcon  = 'fdof'
};

typedef OSType                          ThemeSoundKind;
/*������������������������������������������������������������������������������������������*/
/* Window Metrics                                                                           */
/*������������������������������������������������������������������������������������������*/
/*  Window metrics are used by the Appearance manager to fill in the blanks necessary to    */
/*  draw windows. If a value is not appropriate for the type of window, be sure to fill in  */
/*  the slot in the structure with zero.    For the popupTabOffset parameter, you can pass a*/
/*  real value based on the left edge of the window. This value might be interpreted in a   */
/*  different manner when depending on the value of the popupTabPosition field. The values  */
/*  you can pass into popupTabPosition are:                                                 */
/*                                                                                          */
/*  kThemePopupTabNormalPosition                                                            */
/*      Starts the tab left edge at the position indicated by the popupTabOffset field.     */
/*                                                                                          */
/*  kThemePopupTabCenterOnWindow                                                            */
/*      tells us to ignore the offset field and instead simply center the width of the      */
/*      handle on the window.                                                               */
/*                                                                                          */
/*  kThemePopupTabCenterOnOffset                                                            */
/*      tells us to center the width of the handle around the value passed in offset.       */
/*                                                                                          */
/*  The Appearance Manager will try its best to accomodate the requested placement, but may */
/*  move the handle slightly to make it fit correctly.                                      */
/*                                                                                          */
enum {
  kThemePopupTabNormalPosition  = 0,
  kThemePopupTabCenterOnWindow  = 1,
  kThemePopupTabCenterOnOffset  = 2
};

struct ThemeWindowMetrics {
  UInt16              metricSize;             /* should be always be sizeof( ThemeWindowMetrics )*/
  SInt16              titleHeight;
  SInt16              titleWidth;
  SInt16              popupTabOffset;
  SInt16              popupTabWidth;
  UInt16              popupTabPosition;
};
typedef struct ThemeWindowMetrics       ThemeWindowMetrics;
typedef ThemeWindowMetrics *            ThemeWindowMetricsPtr;
/*������������������������������������������������������������������������������������������*/
/* Theme Metrics                                                                            */
/*������������������������������������������������������������������������������������������*/

/*
 *  Discussion:
 *    Theme metrics allow you to find out sizes of things in the
 *    current environment, such as how wide a scroll bar is, etc.
 */
enum {

  /*
   * The width (or height if horizontal) of a scroll bar.
   */
  kThemeMetricScrollBarWidth    = 0,

  /*
   * The width (or height if horizontal) of a small scroll bar.
   */
  kThemeMetricSmallScrollBarWidth = 1,

  /*
   * The height of the non-label part of a check box control.
   */
  kThemeMetricCheckBoxHeight    = 2,

  /*
   * The height of the non-label part of a radio button control.
   */
  kThemeMetricRadioButtonHeight = 3,

  /*
   * The amount of white space surrounding the text Rect of the text
   * inside of an Edit Text control.  If you select all of the text in
   * an Edit Text control, you can see the white space. The metric is
   * the number of pixels, per side, that the text Rect is outset to
   * create the whitespace Rect.
   */
  kThemeMetricEditTextWhitespace = 4,

  /*
   * The thickness of the Edit Text frame that surrounds the whitespace
   * Rect (that is surrounding the text Rect). The metric is the number
   * of pixels, per side, that the frame Rect is outset from the
   * whitespace Rect.
   */
  kThemeMetricEditTextFrameOutset = 5,

  /*
   * The number of pixels that the list box frame is outset from the
   * content of the list box.
   */
  kThemeMetricListBoxFrameOutset = 6,

  /*
   * This is a deprecated metric.  Don't use it.  It used to describe
   * how far the focus rect used to draw from a control, but control
   * focus drawing no longer uses this information to draw its focus.
   */
  kThemeMetricFocusRectOutset   = 7,

  /*
   * The thickness of the frame drawn by DrawThemeGenericWell.
   */
  kThemeMetricImageWellThickness = 8,

  /*
   * The number of pixels a scrollbar should overlap (actually
   * underlap) any bounding box which surrounds it and scrollable
   * content. This also includes the window frame when a scrolbar is
   * along an edge of the window.
   */
  kThemeMetricScrollBarOverlap  = 9,

  /*
   * The height of the large tab of a tab control.
   */
  kThemeMetricLargeTabHeight    = 10,

  /*
   * The width of the caps (end pieces) of the large tabs of a tab
   * control.
   */
  kThemeMetricLargeTabCapsWidth = 11,

  /*
   * The amount to add to the tab height (kThemeMetricLargeTabHeight)
   * to find out the rectangle height to use with the various Tab
   * drawing primitives. This amount is also the amount that each tab
   * overlaps the tab pane.
   */
  kThemeMetricTabFrameOverlap   = 12,

  /*
   * If less than zero, this indicates that the text should be centered
   * on each tab. If greater than zero, the text should be justified
   * (according to the system script direction) and the amount is the
   * offset from the appropriate edge at which the text should start
   * drawing.
   */
  kThemeMetricTabIndentOrStyle  = 13,

  /*
   * The amount of space that every tab's drawing rectangle overlaps
   * the one on either side of it.
   */
  kThemeMetricTabOverlap        = 14,

  /*
   * The height of the small tab of a tab control.  This includes the
   * pixels that overlap the tab pane and/or tab pane bar.
   */
  kThemeMetricSmallTabHeight    = 15,

  /*
   * The width of the caps (end pieces) of the small tabs of a tab
   * control.
   */
  kThemeMetricSmallTabCapsWidth = 16,

  /*
   * The height and the width of the push button control.
   */
  kThemeMetricPushButtonHeight  = 19,

  /*
   * The height of the list header field of the data browser control.
   */
  kThemeMetricListHeaderHeight  = 20,

  /*
   * The height of a disclosure triangle control.  This triangle is the
   * not the center of the disclosure button, but its own control.
   */
  kThemeMetricDisclosureTriangleHeight = 25,

  /*
   * The width of a disclosure triangle control.
   */
  kThemeMetricDisclosureTriangleWidth = 26,

  /*
   * The height of a little arrows control.
   */
  kThemeMetricLittleArrowsHeight = 27,

  /*
   * The width of a little arrows control.
   */
  kThemeMetricLittleArrowsWidth = 28,

  /*
   * The height of a popup button control.
   */
  kThemeMetricPopupButtonHeight = 30,

  /*
   * The height of a small popup button control.
   */
  kThemeMetricSmallPopupButtonHeight = 31,

  /*
   * The height of the large progress bar, not including its shadow.
   */
  kThemeMetricLargeProgressBarThickness = 32,

  /*
   * This metric is not used.
   */
  kThemeMetricPullDownHeight    = 33,

  /*
   * This metric is not used.
   */
  kThemeMetricSmallPullDownHeight = 34,

  /*
   * The height of the window grow box control.
   */
  kThemeMetricResizeControlHeight = 38,

  /*
   * The width of the window grow box control.
   */
  kThemeMetricSmallResizeControlHeight = 39,

  /*
   * The height of the horizontal slider control.
   */
  kThemeMetricHSliderHeight     = 41,

  /*
   * The height of the tick marks for a horizontal slider control.
   */
  kThemeMetricHSliderTickHeight = 42,

  /*
   * The width of the vertical slider control.
   */
  kThemeMetricVSliderWidth      = 45,

  /*
   * The width of the tick marks for a vertical slider control.
   */
  kThemeMetricVSliderTickWidth  = 46,

  /*
   * The height of the title bar widgets (grow, close, and zoom boxes)
   * for a document window.
   */
  kThemeMetricTitleBarControlsHeight = 49,

  /*
   * The width of the non-label part of a check box control.
   */
  kThemeMetricCheckBoxWidth     = 50,

  /*
   * The width of the non-label part of a radio button control.
   */
  kThemeMetricRadioButtonWidth  = 52,

  /*
   * The height of the normal bar, not including its shadow.
   */
  kThemeMetricNormalProgressBarThickness = 58,

  /*
   * The number of pixels of shadow depth drawn below the progress bar.
   */
  kThemeMetricProgressBarShadowOutset = 59,

  /*
   * The number of pixels of shadow depth drawn below the small
   * progress bar.
   */
  kThemeMetricSmallProgressBarShadowOutset = 60,

  /*
   * The number of pixels that the content of a primary group box is
   * from the bounds of the control.
   */
  kThemeMetricPrimaryGroupBoxContentInset = 61,

  /*
   * The number of pixels that the content of a secondary group box is
   * from the bounds of the control.
   */
  kThemeMetricSecondaryGroupBoxContentInset = 62,

  /*
   * Width allocated to draw the mark character in a menu.
   */
  kThemeMetricMenuMarkColumnWidth = 63,

  /*
   * Width allocated for the mark character in a menu item when the
   * menu has kMenuAttrExcludesMarkColumn.
   */
  kThemeMetricMenuExcludedMarkColumnWidth = 64,

  /*
   * Indent into the interior of the mark column at which the mark
   * character is drawn.
   */
  kThemeMetricMenuMarkIndent    = 65,

  /*
   * Whitespace at the leading edge of menu item text.
   */
  kThemeMetricMenuTextLeadingEdgeMargin = 66,

  /*
   * Whitespace at the trailing edge of menu item text.
   */
  kThemeMetricMenuTextTrailingEdgeMargin = 67,

  /*
   * Width per indent level (set by SetMenuItemIndent) of a menu item.
   */
  kThemeMetricMenuIndentWidth   = 68,

  /*
   * Whitespace at the trailing edge of a menu icon (if the item also
   * has text).
   */
  kThemeMetricMenuIconTrailingEdgeMargin = 69
};


/*
 *  Discussion:
 *    The following metrics are only available in OS X.
 */
enum {

  /*
   * The height of a disclosure button.
   */
  kThemeMetricDisclosureButtonHeight = 17,

  /*
   * The height and the width of the round button control.
   */
  kThemeMetricRoundButtonSize   = 18,

  /*
   * The height of the non-label part of a small check box control.
   */
  kThemeMetricSmallCheckBoxHeight = 21,

  /*
   * The width of a disclosure button.
   */
  kThemeMetricDisclosureButtonWidth = 22,

  /*
   * The height of a small disclosure button.
   */
  kThemeMetricSmallDisclosureButtonHeight = 23,

  /*
   * The width of a small disclosure button.
   */
  kThemeMetricSmallDisclosureButtonWidth = 24,

  /*
   * The height (or width if vertical) of a pane splitter.
   */
  kThemeMetricPaneSplitterHeight = 29,

  /*
   * The height of the small push button control.
   */
  kThemeMetricSmallPushButtonHeight = 35,

  /*
   * The height of the non-label part of a small radio button control.
   */
  kThemeMetricSmallRadioButtonHeight = 36,

  /*
   * The height of the relevance indicator control.
   */
  kThemeMetricRelevanceIndicatorHeight = 37,

  /*
   * The height and the width of the large round button control.
   */
  kThemeMetricLargeRoundButtonSize = 40,

  /*
   * The height of the small, horizontal slider control.
   */
  kThemeMetricSmallHSliderHeight = 43,

  /*
   * The height of the tick marks for a small, horizontal slider
   * control.
   */
  kThemeMetricSmallHSliderTickHeight = 44,

  /*
   * The width of the small, vertical slider control.
   */
  kThemeMetricSmallVSliderWidth = 47,

  /*
   * The width of the tick marks for a small, vertical slider control.
   */
  kThemeMetricSmallVSliderTickWidth = 48,

  /*
   * The width of the non-label part of a small check box control.
   */
  kThemeMetricSmallCheckBoxWidth = 51,

  /*
   * The width of the non-label part of a small radio button control.
   */
  kThemeMetricSmallRadioButtonWidth = 53,

  /*
   * The minimum width of the thumb of a small, horizontal slider
   * control.
   */
  kThemeMetricSmallHSliderMinThumbWidth = 54,

  /*
   * The minimum width of the thumb of a small, vertical slider control.
   */
  kThemeMetricSmallVSliderMinThumbHeight = 55,

  /*
   * The offset of the tick marks from the appropriate side of a small
   * horizontal slider control.
   */
  kThemeMetricSmallHSliderTickOffset = 56,

  /*
   * The offset of the tick marks from the appropriate side of a small
   * vertical slider control.
   */
  kThemeMetricSmallVSliderTickOffset = 57
};


/*
 *  Discussion:
 *    The following metrics are only available in Mac OS X 10.3 and
 *    later.
 */
enum {
  kThemeMetricComboBoxLargeBottomShadowOffset = 70,
  kThemeMetricComboBoxLargeRightShadowOffset = 71,
  kThemeMetricComboBoxSmallBottomShadowOffset = 72,
  kThemeMetricComboBoxSmallRightShadowOffset = 73,
  kThemeMetricComboBoxLargeDisclosureWidth = 74,
  kThemeMetricComboBoxSmallDisclosureWidth = 75,
  kThemeMetricRoundTextFieldContentInsetLeft = 76,
  kThemeMetricRoundTextFieldContentInsetRight = 77,
  kThemeMetricRoundTextFieldContentInsetBottom = 78,
  kThemeMetricRoundTextFieldContentInsetTop = 79,
  kThemeMetricRoundTextFieldContentHeight = 80,
  kThemeMetricComboBoxMiniBottomShadowOffset = 81,
  kThemeMetricComboBoxMiniDisclosureWidth = 82,
  kThemeMetricComboBoxMiniRightShadowOffset = 83,
  kThemeMetricLittleArrowsMiniHeight = 84,
  kThemeMetricLittleArrowsMiniWidth = 85,
  kThemeMetricLittleArrowsSmallHeight = 86,
  kThemeMetricLittleArrowsSmallWidth = 87,
  kThemeMetricMiniCheckBoxHeight = 88,
  kThemeMetricMiniCheckBoxWidth = 89,
  kThemeMetricMiniDisclosureButtonHeight = 90,
  kThemeMetricMiniDisclosureButtonWidth = 91,
  kThemeMetricMiniHSliderHeight = 92,
  kThemeMetricMiniHSliderMinThumbWidth = 93,
  kThemeMetricMiniHSliderTickHeight = 94,
  kThemeMetricMiniHSliderTickOffset = 95,
  kThemeMetricMiniPopupButtonHeight = 96,
  kThemeMetricMiniPullDownHeight = 97,
  kThemeMetricMiniPushButtonHeight = 98,
  kThemeMetricMiniRadioButtonHeight = 99,
  kThemeMetricMiniRadioButtonWidth = 100,
  kThemeMetricMiniTabCapsWidth  = 101,
  kThemeMetricMiniTabFrameOverlap = 102,
  kThemeMetricMiniTabHeight     = 103,
  kThemeMetricMiniTabOverlap    = 104,
  kThemeMetricMiniVSliderMinThumbHeight = 105,
  kThemeMetricMiniVSliderTickOffset = 106,
  kThemeMetricMiniVSliderTickWidth = 107,
  kThemeMetricMiniVSliderWidth  = 108,
  kThemeMetricRoundTextFieldContentInsetWithIconLeft = 109,
  kThemeMetricRoundTextFieldContentInsetWithIconRight = 110,
  kThemeMetricRoundTextFieldMiniContentHeight = 111,
  kThemeMetricRoundTextFieldMiniContentInsetBottom = 112,
  kThemeMetricRoundTextFieldMiniContentInsetLeft = 113,
  kThemeMetricRoundTextFieldMiniContentInsetRight = 114,
  kThemeMetricRoundTextFieldMiniContentInsetTop = 115,
  kThemeMetricRoundTextFieldMiniContentInsetWithIconLeft = 116,
  kThemeMetricRoundTextFieldMiniContentInsetWithIconRight = 117,
  kThemeMetricRoundTextFieldSmallContentHeight = 118,
  kThemeMetricRoundTextFieldSmallContentInsetBottom = 119,
  kThemeMetricRoundTextFieldSmallContentInsetLeft = 120,
  kThemeMetricRoundTextFieldSmallContentInsetRight = 121,
  kThemeMetricRoundTextFieldSmallContentInsetTop = 122,
  kThemeMetricRoundTextFieldSmallContentInsetWithIconLeft = 123,
  kThemeMetricRoundTextFieldSmallContentInsetWithIconRight = 124,
  kThemeMetricSmallTabFrameOverlap = 125,
  kThemeMetricSmallTabOverlap   = 126,

  /*
   * The height of a small pane splitter. Should only be used in a
   * window with thick borders, like a metal window.
   */
  kThemeMetricSmallPaneSplitterHeight = 127
};

typedef UInt32                          ThemeMetric;
/*������������������������������������������������������������������������������������������*/
/* Drawing State                                                                            */
/*������������������������������������������������������������������������������������������*/
typedef struct OpaqueThemeDrawingState*  ThemeDrawingState;
/*������������������������������������������������������������������������������������������*/
/* Callback procs                                                                           */
/*������������������������������������������������������������������������������������������*/
typedef CALLBACK_API( void , ThemeTabTitleDrawProcPtr )(const Rect *bounds, ThemeTabStyle style, ThemeTabDirection direction, SInt16 depth, Boolean isColorDev, UInt32 userData);
typedef CALLBACK_API( void , ThemeEraseProcPtr )(const Rect *bounds, UInt32 eraseData, SInt16 depth, Boolean isColorDev);
typedef CALLBACK_API( void , ThemeButtonDrawProcPtr )(const Rect *bounds, ThemeButtonKind kind, const ThemeButtonDrawInfo *info, UInt32 userData, SInt16 depth, Boolean isColorDev);
typedef CALLBACK_API( void , WindowTitleDrawingProcPtr )(const Rect *bounds, SInt16 depth, Boolean colorDevice, UInt32 userData);
typedef CALLBACK_API( Boolean , ThemeIteratorProcPtr )(ConstStr255Param inFileName, SInt16 resID, Collection inThemeSettings, void *inUserData);
typedef STACK_UPP_TYPE(ThemeTabTitleDrawProcPtr)                ThemeTabTitleDrawUPP;
typedef STACK_UPP_TYPE(ThemeEraseProcPtr)                       ThemeEraseUPP;
typedef STACK_UPP_TYPE(ThemeButtonDrawProcPtr)                  ThemeButtonDrawUPP;
typedef STACK_UPP_TYPE(WindowTitleDrawingProcPtr)               WindowTitleDrawingUPP;
typedef STACK_UPP_TYPE(ThemeIteratorProcPtr)                    ThemeIteratorUPP;
/*
 *  NewThemeTabTitleDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ThemeTabTitleDrawUPP
NewThemeTabTitleDrawUPP(ThemeTabTitleDrawProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewThemeEraseUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ThemeEraseUPP
NewThemeEraseUPP(ThemeEraseProcPtr userRoutine)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewThemeButtonDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ThemeButtonDrawUPP
NewThemeButtonDrawUPP(ThemeButtonDrawProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewWindowTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern WindowTitleDrawingUPP
NewWindowTitleDrawingUPP(WindowTitleDrawingProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewThemeIteratorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ThemeIteratorUPP
NewThemeIteratorUPP(ThemeIteratorProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeThemeTabTitleDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeThemeTabTitleDrawUPP(ThemeTabTitleDrawUPP userUPP)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeThemeEraseUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeThemeEraseUPP(ThemeEraseUPP userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeThemeButtonDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeThemeButtonDrawUPP(ThemeButtonDrawUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeWindowTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeWindowTitleDrawingUPP(WindowTitleDrawingUPP userUPP)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeThemeIteratorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeThemeIteratorUPP(ThemeIteratorUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeThemeTabTitleDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeThemeTabTitleDrawUPP(
  const Rect *          bounds,
  ThemeTabStyle         style,
  ThemeTabDirection     direction,
  SInt16                depth,
  Boolean               isColorDev,
  UInt32                userData,
  ThemeTabTitleDrawUPP  userUPP)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeThemeEraseUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeThemeEraseUPP(
  const Rect *   bounds,
  UInt32         eraseData,
  SInt16         depth,
  Boolean        isColorDev,
  ThemeEraseUPP  userUPP)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeThemeButtonDrawUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeThemeButtonDrawUPP(
  const Rect *                 bounds,
  ThemeButtonKind              kind,
  const ThemeButtonDrawInfo *  info,
  UInt32                       userData,
  SInt16                       depth,
  Boolean                      isColorDev,
  ThemeButtonDrawUPP           userUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeWindowTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeWindowTitleDrawingUPP(
  const Rect *           bounds,
  SInt16                 depth,
  Boolean                colorDevice,
  UInt32                 userData,
  WindowTitleDrawingUPP  userUPP)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeThemeIteratorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeThemeIteratorUPP(
  ConstStr255Param  inFileName,
  SInt16            resID,
  Collection        inThemeSettings,
  void *            inUserData,
  ThemeIteratorUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*����������������������������������������������������������������������������������*/
/* Menu Drawing callbacks                                                           */
/*����������������������������������������������������������������������������������*/
typedef CALLBACK_API( void , MenuTitleDrawingProcPtr )(const Rect *inBounds, SInt16 inDepth, Boolean inIsColorDevice, SInt32 inUserData);
typedef CALLBACK_API( void , MenuItemDrawingProcPtr )(const Rect *inBounds, SInt16 inDepth, Boolean inIsColorDevice, SInt32 inUserData);
typedef STACK_UPP_TYPE(MenuTitleDrawingProcPtr)                 MenuTitleDrawingUPP;
typedef STACK_UPP_TYPE(MenuItemDrawingProcPtr)                  MenuItemDrawingUPP;
/*
 *  NewMenuTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MenuTitleDrawingUPP
NewMenuTitleDrawingUPP(MenuTitleDrawingProcPtr userRoutine)   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMenuItemDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MenuItemDrawingUPP
NewMenuItemDrawingUPP(MenuItemDrawingProcPtr userRoutine)     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMenuTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMenuTitleDrawingUPP(MenuTitleDrawingUPP userUPP)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMenuItemDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMenuItemDrawingUPP(MenuItemDrawingUPP userUPP)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMenuTitleDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeMenuTitleDrawingUPP(
  const Rect *         inBounds,
  SInt16               inDepth,
  Boolean              inIsColorDevice,
  SInt32               inUserData,
  MenuTitleDrawingUPP  userUPP)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMenuItemDrawingUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeMenuItemDrawingUPP(
  const Rect *        inBounds,
  SInt16              inDepth,
  Boolean             inIsColorDevice,
  SInt32              inUserData,
  MenuItemDrawingUPP  userUPP)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*����������������������������������������������������������������������������������*/
/*  Appearance Manager APIs                                                         */
/*����������������������������������������������������������������������������������*/
/* Registering Appearance-Savvy Applications */
/*
 *  RegisterAppearanceClient()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
RegisterAppearanceClient(void)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UnregisterAppearanceClient()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
UnregisterAppearanceClient(void)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsAppearanceClient()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern Boolean 
IsAppearanceClient(const ProcessSerialNumber * process)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****************************************************************************
    NOTES ON THEME BRUSHES
    Theme brushes can be either colors or patterns, depending on the theme.
    Because of this, you should be prepared to handle the case where a brush
    is a pattern and save and restore the pnPixPat and bkPixPat fields of
    your GrafPorts when saving the fore and back colors. Also, since patterns
    in bkPixPat override the background color of the window, you should use
    BackPat to set your background pattern to a normal white pattern. This
    will ensure that you can use RGBBackColor to set your back color to white,
    call EraseRect and get the expected results.
*****************************************************************************/

/*
 *  SetThemePen()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
SetThemePen(
  ThemeBrush   inBrush,
  SInt16       inDepth,
  Boolean      inIsColorDevice)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetThemeBackground()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
SetThemeBackground(
  ThemeBrush   inBrush,
  SInt16       inDepth,
  Boolean      inIsColorDevice)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetThemeTextColor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
SetThemeTextColor(
  ThemeTextColor   inColor,
  SInt16           inDepth,
  Boolean          inIsColorDevice)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetThemeWindowBackground() has moved to MacWindows.h
 */
/* Window Placards, Headers and Frames */
/*
 *  DrawThemeWindowHeader()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeWindowHeader(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeWindowListViewHeader()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeWindowListViewHeader(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemePlacard()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemePlacard(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeEditTextFrame()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeEditTextFrame(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeListBoxFrame()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeListBoxFrame(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Keyboard Focus Drawing */
/*
 *  DrawThemeFocusRect()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeFocusRect(
  const Rect *  inRect,
  Boolean       inHasFocus)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Dialog Group Boxes and Separators */
/*
 *  DrawThemePrimaryGroup()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemePrimaryGroup(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeSecondaryGroup()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeSecondaryGroup(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeSeparator()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeSeparator(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*������������������������������ BEGIN APPEARANCE 1.0.1 ��������������������������������������������*/
/* The following Appearance Manager APIs are only available */
/* in Appearance 1.0.1 or later                             */
/*
 *  DrawThemeModelessDialogFrame()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeModelessDialogFrame(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeGenericWell()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeGenericWell(
  const Rect *     inRect,
  ThemeDrawState   inState,
  Boolean          inFillCenter)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeFocusRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeFocusRegion(
  RgnHandle   inRegion,
  Boolean     inHasFocus)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsThemeInColor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern Boolean 
IsThemeInColor(
  SInt16    inDepth,
  Boolean   inIsColorDevice)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* IMPORTANT: GetThemeAccentColors will only work in the platinum theme. Any other theme will */
/* most likely return an error */
/*
 *  GetThemeAccentColors()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeAccentColors(CTabHandle * outColors)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeMenuBarBackground()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeMenuBarBackground(
  const Rect *        inBounds,
  ThemeMenuBarState   inState,
  UInt32              inAttributes)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeMenuTitle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeMenuTitle(
  const Rect *          inMenuBarRect,
  const Rect *          inTitleRect,
  ThemeMenuState        inState,
  UInt32                inAttributes,
  MenuTitleDrawingUPP   inTitleProc,         /* can be NULL */
  UInt32                inTitleData)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  GetThemeMenuBarHeight()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeMenuBarHeight(SInt16 * outHeight)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeMenuBackground()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeMenuBackground(
  const Rect *    inMenuRect,
  ThemeMenuType   inMenuType)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeMenuBackgroundRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeMenuBackgroundRegion(
  const Rect *    inMenuRect,
  ThemeMenuType   menuType,
  RgnHandle       region)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeMenuItem()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeMenuItem(
  const Rect *         inMenuRect,
  const Rect *         inItemRect,
  SInt16               inVirtualMenuTop,
  SInt16               inVirtualMenuBottom,
  ThemeMenuState       inState,
  ThemeMenuItemType    inItemType,
  MenuItemDrawingUPP   inDrawProc,                /* can be NULL */
  UInt32               inUserData)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeMenuSeparator()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
DrawThemeMenuSeparator(const Rect * inItemRect)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeMenuSeparatorHeight()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeMenuSeparatorHeight(SInt16 * outHeight)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeMenuItemExtra()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeMenuItemExtra(
  ThemeMenuItemType   inItemType,
  SInt16 *            outHeight,
  SInt16 *            outWidth)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeMenuTitleExtra()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.0 and later
 */
extern OSStatus 
GetThemeMenuTitleExtra(
  SInt16 *  outWidth,
  Boolean   inIsSquished)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*������������������������������� BEGIN APPEARANCE 1.1 ���������������������������������������������*/
/*���������������������������������� THEME SWITCHING �����������������������������������������������*/
/*                                                                                                  */
/*  X ALERT: Please note that Get/SetTheme are severely neutered under Mac OS X at present.         */
/*           See the note above regarding what collection tags are supported under X.               */

/*
 *  GetTheme()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetTheme(Collection ioCollection)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTheme()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
SetTheme(Collection ioCollection)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IterateThemes()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
IterateThemes(
  ThemeIteratorUPP   inProc,
  void *             inUserData)       /* can be NULL */      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*���������������������������������������� TABS ����������������������������������������������������*/
/*
 *  DrawThemeTabPane()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTabPane(
  const Rect *     inRect,
  ThemeDrawState   inState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeTab()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTab(
  const Rect *           inRect,
  ThemeTabStyle          inStyle,
  ThemeTabDirection      inDirection,
  ThemeTabTitleDrawUPP   labelProc,         /* can be NULL */
  UInt32                 userData)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTabRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTabRegion(
  const Rect *        inRect,
  ThemeTabStyle       inStyle,
  ThemeTabDirection   inDirection,
  RgnHandle           ioRgn)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*��������������������������������������� CURSORS ��������������������������������������������������*/
/*
 *  SetThemeCursor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
SetThemeCursor(ThemeCursor inCursor)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetAnimatedThemeCursor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
SetAnimatedThemeCursor(
  ThemeCursor   inCursor,
  UInt32        inAnimationStep)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*�������������������������������� CONTROL STYLE SETTINGS ������������������������������������������*/
/*
 *  GetThemeScrollBarThumbStyle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeScrollBarThumbStyle(ThemeScrollBarThumbStyle * outStyle) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeScrollBarArrowStyle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeScrollBarArrowStyle(ThemeScrollBarArrowStyle * outStyle) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeCheckBoxStyle()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeCheckBoxStyle(ThemeCheckBoxStyle * outStyle)          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*���������������������������������������� FONTS/TEXT ����������������������������������������������*/
/*
 *  UseThemeFont()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
UseThemeFont(
  ThemeFontID   inFontID,
  ScriptCode    inScript)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeFont()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeFont(
  ThemeFontID   inFontID,
  ScriptCode    inScript,
  Str255        outFontName,       /* can be NULL */
  SInt16 *      outFontSize,
  Style *       outStyle)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeTextBox()
 *  
 *  Summary:
 *    Draws text into the area you specify.
 *  
 *  Discussion:
 *    DrawThemeTextBox allows you to draw theme-savvy (ie. Aqua-savvy
 *    on Mac OS X) text. It is unicode savvy (although only partially
 *    so under CarbonLib), and allows you to customize certain text
 *    rendering characteristics such as the font, wrapping behavior,
 *    and justification. The text is drawn into the CGContextRef you
 *    provide, or into the current Quickdraw port if no CGContextRef is
 *    provided. None of DrawThemeTextBox's parameters imply a color, so
 *    you must set up the desired text color separately before calling
 *    DrawThemeTextBox. If you provide a CGContextRef, its fill color
 *    will be used to draw the text. If you do not provide a
 *    CGContextRef, a color based on the current Quickdraw port's
 *    foreground color and the grayishTextOr mode (if set) will be used
 *    to draw the text.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inString:
 *      A CFStringRef containing the unicode characters you wish to
 *      render. You MUST NOT pass in a CFStringRef that was allocated
 *      with any of the "NoCopy" CFString creation APIs; a string
 *      created with a "NoCopy" API has transient storage which is
 *      incompatible with DrawThemeTextBox's caches.
 *    
 *    inFontID:
 *      The ThemeFontID describing the font you'd like to render the
 *      text with. See the discussion of ThemeFontIDs elsewhere in this
 *      header.
 *    
 *    inState:
 *      The ThemeDrawState describing the the state of the interface
 *      element you are drawing the text for. If, for example, you are
 *      drawing text for an inactive window, you would pass
 *      kThemeStateInactive. The ThemeDrawState is generally only used
 *      to determine the shadow characteristics for the text on Mac OS
 *      X. Note that the ThemeDrawState does NOT imply a color. It is
 *      NOT used as a mechanism for graying the text. If you wish to
 *      draw grayed text, you must set up the desired gray color and
 *      apply it to either the current Quickdraw port or the
 *      CGContextRef as appropriate.
 *    
 *    inWrapToWidth:
 *      A Boolean indicating whether you want to draw multiple lines of
 *      text wrapped to a bounding box. False indicates that only one
 *      line of text should be drawn without any sort of wrapping.
 *    
 *    inBoundingBox:
 *      The rectangle (in coordinates relative to the current Quickdraw
 *      port) describing the area to draw the text within. The first
 *      line of text will be top-justified to this rectangle. Wrapping
 *      (if desired) will happen at the horizontal extent of this
 *      rectangle. Regardless of the amount of text in your
 *      CFStringRef, all drawn text will be clipped to this rectangle.
 *    
 *    inJust:
 *      The horizontal justification you would like for your text. You
 *      can use one of the standard justification constants from
 *      TextEdit.h.
 *    
 *    inContext:
 *      The CGContextRef into which you would like to draw the text. On
 *      Mac OS X, all text drawing happens in CGContextRefs; if you
 *      pass NULL, a transient CGContextRef will be allocated and
 *      deallocated for use within the single API call. Relying on the
 *      system behavior if transiently creating CGContextRefs may
 *      result in performance problems. On Mac OS 9, the CGContextRef
 *      parameter is ignored.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
DrawThemeTextBox(
  CFStringRef      inString,
  ThemeFontID      inFontID,
  ThemeDrawState   inState,
  Boolean          inWrapToWidth,
  const Rect *     inBoundingBox,
  SInt16           inJust,
  void *           inContext)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TruncateThemeText()
 *  
 *  Summary:
 *    Truncates text to fit within the width you specify.
 *  
 *  Discussion:
 *    TruncateThemeText alters a unicode string to fit within a width
 *    that you specify. It is unicode savvy (although only partially so
 *    under CarbonLib), and makes its calculations (and any subsequent
 *    string alteration) based on the font and state you specify. If
 *    the string needs to be truncated, it will be reduced to the
 *    maximum number of characters which (with the addition of an
 *    ellipsis character) fits within the specified width.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inString:
 *      A CFMutableStringRef containing the unicode characters you wish
 *      to truncate. On output, inString may have been altered to fit
 *      within the specified width. You MUST NOT pass in a CFStringRef
 *      that was allocated with any of the "NoCopy" CFString creation
 *      APIs (see note in DrawThemeTextBox above).
 *    
 *    inFontID:
 *      The ThemeFontID to use for text measurements. See the
 *      discussion of ThemeFontIDs elsewhere in this header.
 *    
 *    inState:
 *      The ThemeDrawState which matches the state you will ultimately
 *      render the string width. This may affect text measurement
 *      during truncation, so you should be sure the value you pass to
 *      TruncateThemeText matches the value you will eventually use for
 *      drawing.
 *    
 *    inPixelWidthLimit:
 *      The maximum width (in pixels) that the resulting truncated
 *      string may have.
 *    
 *    inTruncWhere:
 *      A TruncCode indicating where you would like truncation to occur.
 *    
 *    outTruncated:
 *      On output, this Boolean value indicates whether the string was
 *      truncated. True means the string was truncated. False means the
 *      string was not (and did not need to be) truncated.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
TruncateThemeText(
  CFMutableStringRef   inString,
  ThemeFontID          inFontID,
  ThemeDrawState       inState,
  SInt16               inPixelWidthLimit,
  TruncCode            inTruncWhere,
  Boolean *            outTruncated)            /* can be NULL */ AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTextDimensions()
 *  
 *  Summary:
 *    Tells you the height, width, and baseline for a string.
 *  
 *  Discussion:
 *    GetThemeTextDimensions measures the given string using a font and
 *    state you specify. It always reports the actual height and
 *    baseline. It sometimes reports the actual width (see below). It
 *    can measure a string that wraps. It is unicode savvy (although
 *    only partially so under CarbonLib).
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inString:
 *      A CFStringRef containing the unicode characters you wish to
 *      measure. You MUST NOT pass in a CFStringRef that was allocated
 *      with any of the "NoCopy" CFString creation APIs (see note in
 *      DrawThemeTextBox above).
 *    
 *    inFontID:
 *      The ThemeFontID describing the font you'd like to measure the
 *      text with. See the discussion of ThemeFontIDs elsewhere in this
 *      header.
 *    
 *    inState:
 *      The ThemeDrawState which matches the state you will ultimately
 *      render the string width. This may affect text measurement, so
 *      you should be sure the value you pass to TruncateThemeText
 *      matches the value you will eventually use for drawing.
 *    
 *    inWrapToWidth:
 *      A Boolean indicating whether you want the measurements based on
 *      wrapping the text to a specific width. If you pass true, you
 *      must specify the desired width in ioBounds->h.
 *    
 *    ioBounds:
 *      On output, ioBounds->v contains the height of the text. If you
 *      pass false to inWrapToWidth, ioBounds->h will contain the width
 *      of the text on output. If you pass true to inWrapToWidth,
 *      ioBounds->h must (on input) contain the desired width for
 *      wrapping; on output, ioBounds->h contains the same value you
 *      specified on input.
 *    
 *    outBaseline:
 *      On output, outBaseline contains the offset (in Quickdraw space)
 *      from the bottom edge of the last line of text to the baseline
 *      of the first line of text. outBaseline will generally be a
 *      negative value. On Mac OS X 10.2 and later, you may pass NULL
 *      if you don't want this information.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetThemeTextDimensions(
  CFStringRef      inString,
  ThemeFontID      inFontID,
  ThemeDrawState   inState,
  Boolean          inWrapToWidth,
  Point *          ioBounds,
  SInt16 *         outBaseline)         /* can be NULL */     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTextShadowOutset()
 *  
 *  Summary:
 *    Tells you the amount of space taken up by the shadow for a given
 *    font/state combination.
 *  
 *  Discussion:
 *    GetThemeTextShadowOutset passes back the maximum amount of space
 *    the shadow will take up for text drawn in the specified font and
 *    state. While GetThemeTextDimensions tells you how much space is
 *    taken up by the character glyphs themselves, it does not
 *    incorporate the font/state shadow into its calculations. If you
 *    need to know how much total space including the shadow will be
 *    taken up, call GetThemeTextDimensions followed by
 *    GetThemeTextShadowOutset.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    inFontID:
 *      The ThemeFontID describing the font you'd like the shadow
 *      characteristics of. Font and state both determine the amount of
 *      shadow that will be used on rendered text. See the discussion
 *      of ThemeFontIDs elsewhere in this header.
 *    
 *    inState:
 *      The ThemeDrawState which matches the state you'd like the
 *      shadow characteristics of. Font and state both determine the
 *      amount of shadow that will be used on rendered text.
 *    
 *    outOutset:
 *      On output, outOutset contains the amount of space the shadow
 *      will take up beyond each edge of the text bounding rectangle
 *      returned by GetThemeTextDimensions. The fields of outOutset
 *      will either be positive values or zero.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
GetThemeTextShadowOutset(
  ThemeFontID      inFontID,
  ThemeDrawState   inState,
  Rect *           outOutset)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*���������������������������������������� TRACKS ��������������������������������������������������*/
/*
 *  DrawThemeTrack()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTrack(
  const ThemeTrackDrawInfo *  drawInfo,
  RgnHandle                   rgnGhost,        /* can be NULL */
  ThemeEraseUPP               eraseProc,       /* can be NULL */
  UInt32                      eraseData)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HitTestThemeTrack()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern Boolean 
HitTestThemeTrack(
  const ThemeTrackDrawInfo *  drawInfo,
  Point                       mousePoint,
  AppearancePartCode *        partHit)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackBounds(
  const ThemeTrackDrawInfo *  drawInfo,
  Rect *                      bounds)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackThumbRgn()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackThumbRgn(
  const ThemeTrackDrawInfo *  drawInfo,
  RgnHandle                   thumbRgn)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackDragRect()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackDragRect(
  const ThemeTrackDrawInfo *  drawInfo,
  Rect *                      dragRect)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeTrackTickMarks()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTrackTickMarks(
  const ThemeTrackDrawInfo *  drawInfo,
  ItemCount                   numTicks,
  ThemeEraseUPP               eraseProc,       /* can be NULL */
  UInt32                      eraseData)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackThumbPositionFromOffset()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackThumbPositionFromOffset(
  const ThemeTrackDrawInfo *  drawInfo,
  Point                       thumbOffset,
  SInt32 *                    relativePosition)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackThumbPositionFromRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackThumbPositionFromRegion(
  const ThemeTrackDrawInfo *  drawInfo,
  RgnHandle                   thumbRgn,
  SInt32 *                    relativePosition)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTrackLiveValue()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTrackLiveValue(
  const ThemeTrackDrawInfo *  drawInfo,
  SInt32                      relativePosition,
  SInt32 *                    value)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*����������������������������������� SCROLLBAR ARROWS ���������������������������������������������*/
/*
 *  DrawThemeScrollBarArrows()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeScrollBarArrows(
  const Rect *            bounds,
  ThemeTrackEnableState   enableState,
  ThemeTrackPressState    pressState,
  Boolean                 isHoriz,
  Rect *                  trackBounds)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeScrollBarTrackRect()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeScrollBarTrackRect(
  const Rect *            bounds,
  ThemeTrackEnableState   enableState,
  ThemeTrackPressState    pressState,
  Boolean                 isHoriz,
  Rect *                  trackBounds)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  HitTestThemeScrollBarArrows()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern Boolean 
HitTestThemeScrollBarArrows(
  const Rect *            scrollBarBounds,
  ThemeTrackEnableState   enableState,
  ThemeTrackPressState    pressState,
  Boolean                 isHoriz,
  Point                   ptHit,
  Rect *                  trackBounds,
  AppearancePartCode *    partcode)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*���������������������������������������� WINDOWS �������������������������������������������������*/
/*
 *  GetThemeWindowRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeWindowRegion(
  ThemeWindowType             flavor,
  const Rect *                contRect,
  ThemeDrawState              state,
  const ThemeWindowMetrics *  metrics,
  ThemeWindowAttributes       attributes,
  AppearanceRegionCode        winRegion,
  RgnHandle                   rgn)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeWindowFrame()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeWindowFrame(
  ThemeWindowType             flavor,
  const Rect *                contRect,
  ThemeDrawState              state,
  const ThemeWindowMetrics *  metrics,
  ThemeWindowAttributes       attributes,
  WindowTitleDrawingUPP       titleProc,        /* can be NULL */
  UInt32                      titleData)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeTitleBarWidget()
 *  
 *  Summary:
 *    Draws the requested theme title bar widget.
 *  
 *  Discussion:
 *    DrawThemeTitleBarWidget renders the requested theme title bar
 *    widget in the proper location of a window.  A common
 *    misconception when using this API is that the client must specify
 *    the exact location of the widget in the window. The widget will
 *    locate itself in the window based relative to the content rect
 *    passed in content rectangle -- the contRect parameter.  Another
 *    common problem is to ignore the window's attributes.  The
 *    attributes must be set up properly to describe the window for
 *    which the widget is to be drawn.
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Parameters:
 *    
 *    flavor:
 *      A valid ThemeWindowtype describing the type of theme window for
 *      which you would like to draw a widget.
 *    
 *    contRect:
 *      A rectangle describing the window's content area.  The widget
 *      is drawn relative to the content rectangle of the window, so
 *      this parameter does not describe the actual widget bounds, it
 *      describes the window's content rectangle.
 *    
 *    state:
 *      A valid ThemeDrawState which describes the state of the window
 *      for which the widget is to be drawn.
 *    
 *    metrics:
 *      A pointer to a set of valid ThemeWindowMetrics.  At this time,
 *      none of the fields of the metrics are pertinent to the widgets,
 *      so the only important field is the metricSize field to mark the
 *      structure as valid.
 *    
 *    attributes:
 *      A valid ThemeWindowAttributes set which describes the window
 *      for which the widget is to be drawn.
 *    
 *    widget:
 *      A valid ThemeTitleBarWidget set which describes which widget to
 *      draw.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTitleBarWidget(
  ThemeWindowType             flavor,
  const Rect *                contRect,
  ThemeDrawState              state,
  const ThemeWindowMetrics *  metrics,
  ThemeWindowAttributes       attributes,
  ThemeTitleBarWidget         widget)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeWindowRegionHit()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern Boolean 
GetThemeWindowRegionHit(
  ThemeWindowType             flavor,
  const Rect *                inContRect,
  ThemeDrawState              state,
  const ThemeWindowMetrics *  metrics,
  ThemeWindowAttributes       inAttributes,
  Point                       inPoint,
  AppearanceRegionCode *      outRegionHit)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeScrollBarDelimiters()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeScrollBarDelimiters(
  ThemeWindowType         flavor,
  const Rect *            inContRect,
  ThemeDrawState          state,
  ThemeWindowAttributes   attributes)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*���������������������������������������� BUTTONS �������������������������������������������������*/
/*
 *  DrawThemeButton()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeButton(
  const Rect *                 inBounds,
  ThemeButtonKind              inKind,
  const ThemeButtonDrawInfo *  inNewInfo,
  const ThemeButtonDrawInfo *  inPrevInfo,        /* can be NULL */
  ThemeEraseUPP                inEraseProc,       /* can be NULL */
  ThemeButtonDrawUPP           inLabelProc,       /* can be NULL */
  UInt32                       inUserData)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeButtonRegion()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeButtonRegion(
  const Rect *                 inBounds,
  ThemeButtonKind              inKind,
  const ThemeButtonDrawInfo *  inNewInfo,
  RgnHandle                    outRegion)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeButtonContentBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeButtonContentBounds(
  const Rect *                 inBounds,
  ThemeButtonKind              inKind,
  const ThemeButtonDrawInfo *  inDrawInfo,
  Rect *                       outBounds)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeButtonBackgroundBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeButtonBackgroundBounds(
  const Rect *                 inBounds,
  ThemeButtonKind              inKind,
  const ThemeButtonDrawInfo *  inDrawInfo,
  Rect *                       outBounds)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*������������������������������������� INTERFACE SOUNDS �������������������������������������������*/
/*                                                                                                  */
/*  X ALERT: Please note that the sound APIs do not work on Mac OS X at present.                    */
/*
 *  PlayThemeSound()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
PlayThemeSound(ThemeSoundKind kind)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  BeginThemeDragSound()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
BeginThemeDragSound(ThemeDragSoundKind kind)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EndThemeDragSound()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
EndThemeDragSound(void)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*�������������������������������������� PRIMITIVES ������������������������������������������������*/
/*
 *  DrawThemeTickMark()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeTickMark(
  const Rect *     bounds,
  ThemeDrawState   state)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeChasingArrows()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeChasingArrows(
  const Rect *     bounds,
  UInt32           index,
  ThemeDrawState   state,
  ThemeEraseUPP    eraseProc,       /* can be NULL */
  UInt32           eraseData)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemePopupArrow()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemePopupArrow(
  const Rect *            bounds,
  ThemeArrowOrientation   orientation,
  ThemePopupArrowSize     size,
  ThemeDrawState          state,
  ThemeEraseUPP           eraseProc,         /* can be NULL */
  UInt32                  eraseData)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeStandaloneGrowBox()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeStandaloneGrowBox(
  Point                origin,
  ThemeGrowDirection   growDirection,
  Boolean              isSmall,
  ThemeDrawState       state)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DrawThemeStandaloneNoGrowBox()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DrawThemeStandaloneNoGrowBox(
  Point                origin,
  ThemeGrowDirection   growDirection,
  Boolean              isSmall,
  ThemeDrawState       state)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeStandaloneGrowBoxBounds()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeStandaloneGrowBoxBounds(
  Point                origin,
  ThemeGrowDirection   growDirection,
  Boolean              isSmall,
  Rect *               bounds)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*������������������������������������� DRAWING STATE ����������������������������������������������*/
/* The following routines help you save and restore the drawing state in a theme-savvy manner. With */
/* these weapons in your arsenal, there is no grafport you cannot tame. Use ThemeGetDrawingState to */
/* get the current drawing settings for the current port. It will return an opaque object for you   */
/* to pass into SetThemeDrawingState later on. When you are finished with the state, call the       */
/* DisposeThemeDrawingState routine. You can alternatively pass true into the inDisposeNow          */
/* parameter of the SetThemeDrawingState routine.  You can use this routine to copy the drawing     */
/* state from one port to another as well.                                                          */
/*                                                                                                  */
/* As of this writing (Mac OS 9.1 and Mac OS X), Get/SetThemeDrawingState will save and restore     */
/* this data in the port:                                                                           */
/*                                                                                                  */
/*      pen size                                                                                    */
/*      pen location                                                                                */
/*      pen mode                                                                                    */
/*      pen Pattern and PixPat                                                                      */
/*      background Pattern and PixPat                                                               */
/*      RGB foreground and background colors                                                        */
/*      text mode                                                                                   */
/*      pattern origin                                                                              */
/*                                                                                                  */
/* Get/SetThemeDrawingState may save and restore additional port state in the future, but you can   */
/* rely on them to always save at least this port state.                                            */
/*
 *  NormalizeThemeDrawingState()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
NormalizeThemeDrawingState(void)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeDrawingState()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeDrawingState(ThemeDrawingState * outState)            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetThemeDrawingState()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
SetThemeDrawingState(
  ThemeDrawingState   inState,
  Boolean             inDisposeNow)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeThemeDrawingState()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
DisposeThemeDrawingState(ThemeDrawingState inState)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*������������������������������������� MISCELLANEOUS ����������������������������������������������*/
/* ApplyThemeBackground is used to set up the background for embedded controls  */
/* It is normally called by controls that are embedders. The standard controls  */
/* call this API to ensure a correct background for the current theme. You pass */
/* in the same rectangle you would if you were calling the drawing primitive.   */
/*
 *  ApplyThemeBackground()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
ApplyThemeBackground(
  ThemeBackgroundKind   inKind,
  const Rect *          bounds,
  ThemeDrawState        inState,
  SInt16                inDepth,
  Boolean               inColorDev)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetThemeTextColorForWindow() has moved to MacWindows.h
 */
/*
 *  IsValidAppearanceFileType()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern Boolean 
IsValidAppearanceFileType(OSType fileType)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeBrushAsColor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeBrushAsColor(
  ThemeBrush   inBrush,
  SInt16       inDepth,
  Boolean      inColorDev,
  RGBColor *   outColor)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetThemeTextColor()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in AppearanceLib 1.1 and later
 */
extern OSStatus 
GetThemeTextColor(
  ThemeTextColor   inColor,
  SInt16           inDepth,
  Boolean          inColorDev,
  RGBColor *       outColor)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*��������������������������������������� BEGIN CARBON ���������������������������������������������*/
/*
 *  GetThemeMetric()
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
GetThemeMetric(
  ThemeMetric   inMetric,
  SInt32 *      outMetric)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CopyThemeIdentifier()
 *  
 *  Mac OS X threading:
 *    Not thread safe
 *  
 *  Availability:
 *    Mac OS X:         in version 10.1 and later in Carbon.framework
 *    CarbonLib:        in CarbonLib 1.4 and later
 *    Non-Carbon CFM:   not available
 */
extern OSStatus 
CopyThemeIdentifier(CFStringRef * outIdentifier)              AVAILABLE_MAC_OS_X_VERSION_10_1_AND_LATER;


/*��������������������������������������������������������������������������������������������������*/
/* Obsolete symbolic names                                                                          */
/*��������������������������������������������������������������������������������������������������*/
/* Obsolete error codes - use the new ones, s'il vous plait / kudasai */
enum {
  appearanceBadBrushIndexErr    = themeInvalidBrushErr, /* pattern index invalid */
  appearanceProcessRegisteredErr = themeProcessRegisteredErr,
  appearanceProcessNotRegisteredErr = themeProcessNotRegisteredErr,
  appearanceBadTextColorIndexErr = themeBadTextColorErr,
  appearanceThemeHasNoAccents   = themeHasNoAccentsErr,
  appearanceBadCursorIndexErr   = themeBadCursorIndexErr
};

enum {
  kThemeActiveDialogBackgroundBrush = kThemeBrushDialogBackgroundActive,
  kThemeInactiveDialogBackgroundBrush = kThemeBrushDialogBackgroundInactive,
  kThemeActiveAlertBackgroundBrush = kThemeBrushAlertBackgroundActive,
  kThemeInactiveAlertBackgroundBrush = kThemeBrushAlertBackgroundInactive,
  kThemeActiveModelessDialogBackgroundBrush = kThemeBrushModelessDialogBackgroundActive,
  kThemeInactiveModelessDialogBackgroundBrush = kThemeBrushModelessDialogBackgroundInactive,
  kThemeActiveUtilityWindowBackgroundBrush = kThemeBrushUtilityWindowBackgroundActive,
  kThemeInactiveUtilityWindowBackgroundBrush = kThemeBrushUtilityWindowBackgroundInactive,
  kThemeListViewSortColumnBackgroundBrush = kThemeBrushListViewSortColumnBackground,
  kThemeListViewBackgroundBrush = kThemeBrushListViewBackground,
  kThemeIconLabelBackgroundBrush = kThemeBrushIconLabelBackground,
  kThemeListViewSeparatorBrush  = kThemeBrushListViewSeparator,
  kThemeChasingArrowsBrush      = kThemeBrushChasingArrows,
  kThemeDragHiliteBrush         = kThemeBrushDragHilite,
  kThemeDocumentWindowBackgroundBrush = kThemeBrushDocumentWindowBackground,
  kThemeFinderWindowBackgroundBrush = kThemeBrushFinderWindowBackground
};

enum {
  kThemeActiveScrollBarDelimiterBrush = kThemeBrushScrollBarDelimiterActive,
  kThemeInactiveScrollBarDelimiterBrush = kThemeBrushScrollBarDelimiterInactive,
  kThemeFocusHighlightBrush     = kThemeBrushFocusHighlight,
  kThemeActivePopupArrowBrush   = kThemeBrushPopupArrowActive,
  kThemePressedPopupArrowBrush  = kThemeBrushPopupArrowPressed,
  kThemeInactivePopupArrowBrush = kThemeBrushPopupArrowInactive,
  kThemeAppleGuideCoachmarkBrush = kThemeBrushAppleGuideCoachmark
};

enum {
  kThemeActiveDialogTextColor   = kThemeTextColorDialogActive,
  kThemeInactiveDialogTextColor = kThemeTextColorDialogInactive,
  kThemeActiveAlertTextColor    = kThemeTextColorAlertActive,
  kThemeInactiveAlertTextColor  = kThemeTextColorAlertInactive,
  kThemeActiveModelessDialogTextColor = kThemeTextColorModelessDialogActive,
  kThemeInactiveModelessDialogTextColor = kThemeTextColorModelessDialogInactive,
  kThemeActiveWindowHeaderTextColor = kThemeTextColorWindowHeaderActive,
  kThemeInactiveWindowHeaderTextColor = kThemeTextColorWindowHeaderInactive,
  kThemeActivePlacardTextColor  = kThemeTextColorPlacardActive,
  kThemeInactivePlacardTextColor = kThemeTextColorPlacardInactive,
  kThemePressedPlacardTextColor = kThemeTextColorPlacardPressed,
  kThemeActivePushButtonTextColor = kThemeTextColorPushButtonActive,
  kThemeInactivePushButtonTextColor = kThemeTextColorPushButtonInactive,
  kThemePressedPushButtonTextColor = kThemeTextColorPushButtonPressed,
  kThemeActiveBevelButtonTextColor = kThemeTextColorBevelButtonActive,
  kThemeInactiveBevelButtonTextColor = kThemeTextColorBevelButtonInactive,
  kThemePressedBevelButtonTextColor = kThemeTextColorBevelButtonPressed,
  kThemeActivePopupButtonTextColor = kThemeTextColorPopupButtonActive,
  kThemeInactivePopupButtonTextColor = kThemeTextColorPopupButtonInactive,
  kThemePressedPopupButtonTextColor = kThemeTextColorPopupButtonPressed,
  kThemeIconLabelTextColor      = kThemeTextColorIconLabel,
  kThemeListViewTextColor       = kThemeTextColorListView
};

enum {
  kThemeActiveDocumentWindowTitleTextColor = kThemeTextColorDocumentWindowTitleActive,
  kThemeInactiveDocumentWindowTitleTextColor = kThemeTextColorDocumentWindowTitleInactive,
  kThemeActiveMovableModalWindowTitleTextColor = kThemeTextColorMovableModalWindowTitleActive,
  kThemeInactiveMovableModalWindowTitleTextColor = kThemeTextColorMovableModalWindowTitleInactive,
  kThemeActiveUtilityWindowTitleTextColor = kThemeTextColorUtilityWindowTitleActive,
  kThemeInactiveUtilityWindowTitleTextColor = kThemeTextColorUtilityWindowTitleInactive,
  kThemeActivePopupWindowTitleColor = kThemeTextColorPopupWindowTitleActive,
  kThemeInactivePopupWindowTitleColor = kThemeTextColorPopupWindowTitleInactive,
  kThemeActiveRootMenuTextColor = kThemeTextColorRootMenuActive,
  kThemeSelectedRootMenuTextColor = kThemeTextColorRootMenuSelected,
  kThemeDisabledRootMenuTextColor = kThemeTextColorRootMenuDisabled,
  kThemeActiveMenuItemTextColor = kThemeTextColorMenuItemActive,
  kThemeSelectedMenuItemTextColor = kThemeTextColorMenuItemSelected,
  kThemeDisabledMenuItemTextColor = kThemeTextColorMenuItemDisabled,
  kThemeActivePopupLabelTextColor = kThemeTextColorPopupLabelActive,
  kThemeInactivePopupLabelTextColor = kThemeTextColorPopupLabelInactive
};

enum {
  kAEThemeSwitch                = kAEAppearanceChanged /* Event ID's: Theme Switched */
};

enum {
  kThemeNoAdornment             = kThemeAdornmentNone,
  kThemeDefaultAdornment        = kThemeAdornmentDefault,
  kThemeFocusAdornment          = kThemeAdornmentFocus,
  kThemeRightToLeftAdornment    = kThemeAdornmentRightToLeft,
  kThemeDrawIndicatorOnly       = kThemeAdornmentDrawIndicatorOnly
};

enum {
  kThemeBrushPassiveAreaFill    = kThemeBrushStaticAreaFill
};

enum {
  kThemeMetricCheckBoxGlyphHeight = kThemeMetricCheckBoxHeight,
  kThemeMetricRadioButtonGlyphHeight = kThemeMetricRadioButtonHeight,
  kThemeMetricDisclosureButtonSize = kThemeMetricDisclosureButtonHeight,
  kThemeMetricBestListHeaderHeight = kThemeMetricListHeaderHeight,
  kThemeMetricSmallProgressBarThickness = kThemeMetricNormalProgressBarThickness, /* obsolete */
  kThemeMetricProgressBarThickness = kThemeMetricLargeProgressBarThickness /* obsolete */
};

enum {
  kThemeScrollBar               = kThemeMediumScrollBar,
  kThemeSlider                  = kThemeMediumSlider,
  kThemeProgressBar             = kThemeMediumProgressBar,
  kThemeIndeterminateBar        = kThemeMediumIndeterminateBar
};


#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __APPEARANCE__ */

