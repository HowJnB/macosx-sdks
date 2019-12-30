/*
     File:       QuickTime/Movies.h
 
     Contains:   QuickTime Interfaces.
 
     Version:    QuickTime_6
 
     Copyright:  � 1990-2003 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __MOVIES__
#define __MOVIES__

#ifndef __CARBON__
#include <Carbon/Carbon.h>
#endif

#ifndef __IMAGECOMPRESSION__
#include <QuickTime/ImageCompression.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma options align=mac68k


#if TARGET_API_MAC_OSX
    #include <CoreAudio/CoreAudio.h>
#endif

/*  "kFix1" is defined in FixMath as "fixed1"  */
/* error codes are in Errors.[haa] */
/* gestalt codes are in Gestalt.[hpa] */
enum {
  MovieFileType                 = 'MooV',
  MovieScrapType                = 'moov'
};

enum {
  MovieResourceType             = 'moov',
  MovieForwardPointerResourceType = 'fore',
  MovieBackwardPointerResourceType = 'back'
};

enum {
  MovieResourceAtomType         = 'moov',
  MovieDataAtomType             = 'mdat',
  FreeAtomType                  = 'free',
  SkipAtomType                  = 'skip',
  WideAtomPlaceholderType       = 'wide'
};

enum {
  MediaHandlerType              = 'mhlr',
  DataHandlerType               = 'dhlr'
};

enum {
  VideoMediaType                = 'vide',
  SoundMediaType                = 'soun',
  TextMediaType                 = 'text',
  BaseMediaType                 = 'gnrc',
  MPEGMediaType                 = 'MPEG',
  MusicMediaType                = 'musi',
  TimeCodeMediaType             = 'tmcd',
  SpriteMediaType               = 'sprt',
  FlashMediaType                = 'flsh',
  MovieMediaType                = 'moov',
  TweenMediaType                = 'twen',
  ThreeDeeMediaType             = 'qd3d',
  SkinMediaType                 = 'skin',
  HandleDataHandlerSubType      = 'hndl',
  PointerDataHandlerSubType     = 'ptr ',
  NullDataHandlerSubType        = 'null',
  ResourceDataHandlerSubType    = 'rsrc',
  URLDataHandlerSubType         = 'url ',
  AliasDataHandlerSubType       = 'alis',
  WiredActionHandlerType        = 'wire'
};

enum {
  VisualMediaCharacteristic     = 'eyes',
  AudioMediaCharacteristic      = 'ears',
  kCharacteristicCanSendVideo   = 'vsnd',
  kCharacteristicProvidesActions = 'actn',
  kCharacteristicNonLinear      = 'nonl',
  kCharacteristicCanStep        = 'step',
  kCharacteristicHasNoDuration  = 'noti',
  kCharacteristicHasSkinData    = 'skin',
  kCharacteristicProvidesKeyFocus = 'keyf'
};

enum {
  kUserDataMovieControllerType  = 'ctyp',
  kUserDataName                 = 'name',
  kUserDataTextAlbum            = (long)0xA9616C62/*'�alb' */,
  kUserDataTextArtist           = (long)0xA9415254,
  kUserDataTextAuthor           = (long)0xA9617574/*'�aut' */,
  kUserDataTextChapter          = (long)0xA9636870/*'�chp' */,
  kUserDataTextComment          = (long)0xA9636D74/*'�cmt' */,
  kUserDataTextComposer         = (long)0xA9636F6D/*'�com' */,
  kUserDataTextCopyright        = (long)0xA9637079/*'�cpy' */,
  kUserDataTextCreationDate     = (long)0xA9646179/*'�day' */,
  kUserDataTextDescription      = (long)0xA9646573/*'�des' */,
  kUserDataTextDirector         = (long)0xA9646972/*'�dir' */,
  kUserDataTextDisclaimer       = (long)0xA9646973/*'�dis' */,
  kUserDataTextEncodedBy        = (long)0xA9656E63/*'�enc' */,
  kUserDataTextFullName         = (long)0xA96E616D/*'�nam' */,
  kUserDataTextGenre            = (long)0xA967656E/*'�gen' */,
  kUserDataTextHostComputer     = (long)0xA9687374/*'�hst' */,
  kUserDataTextInformation      = (long)0xA9696E66/*'�inf' */,
  kUserDataTextKeywords         = (long)0xA96B6579/*'�key' */,
  kUserDataTextMake             = (long)0xA96D616B/*'�mak' */,
  kUserDataTextModel            = (long)0xA96D6F64/*'�mod' */,
  kUserDataTextOriginalArtist   = (long)0xA96F7065/*'�ope' */,
  kUserDataTextOriginalFormat   = (long)0xA9666D74/*'�fmt' */,
  kUserDataTextOriginalSource   = (long)0xA9737263/*'�src' */,
  kUserDataTextPerformers       = (long)0xA9707266/*'�prf' */,
  kUserDataTextProducer         = (long)0xA9707264/*'�prd' */,
  kUserDataTextProduct          = (long)0xA9505244,
  kUserDataTextSoftware         = (long)0xA9737772/*'�swr' */,
  kUserDataTextSpecialPlaybackRequirements = (long)0xA9726571/*'�req' */,
  kUserDataTextTrack            = (long)0xA974726B/*'�trk' */,
  kUserDataTextWarning          = (long)0xA977726E/*'�wrn' */,
  kUserDataTextWriter           = (long)0xA9777274/*'�wrt' */,
  kUserDataTextURLLink          = (long)0xA975726C/*'�url' */,
  kUserDataTextEditDate1        = (long)0xA9656431/*'�ed1' */,
  kUserDataAnimatedGIFLoopCount = 'gifc', /* data is big-endian UInt16 */
  kQTAnimatedGIFLoopCountInfinite = 0,
  kUserDataAnimatedGIFBufferingSize = 'gifb' /* data is big-endian UInt32 */
};

enum {
  kUserDataUnicodeBit           = 1L << 7
};

enum {
  DoTheRightThing               = 0
};

typedef struct MovieType**              Movie;
typedef Movie *                         PtrToMovie;
typedef struct TrackType**              Track;
typedef struct MediaType**              Media;
typedef struct UserDataRecord**         UserData;
typedef struct MovieStateRecord**       MovieEditState;
typedef struct TrackStateRecord**       TrackEditState;
typedef struct QTRestrictionSetRecord**  QTRestrictionSet;
typedef struct SpriteWorldRecord*       SpriteWorld;
typedef struct SpriteRecord*            Sprite;
typedef struct QTTweenerRecord*         QTTweener;
struct SampleDescription {
  long                descSize;
  long                dataFormat;
  long                resvd1;
  short               resvd2;
  short               dataRefIndex;
};
typedef struct SampleDescription        SampleDescription;
typedef SampleDescription *             SampleDescriptionPtr;
typedef SampleDescriptionPtr *          SampleDescriptionHandle;
typedef struct QTBandwidthUsageRecord**  QTBandwidthReference;
typedef struct QTScheduledBandwidthUsageRecord**  QTScheduledBandwidthReference;
enum {
  kQTNetworkStatusNoNetwork     = -2,
  kQTNetworkStatusUncertain     = -1,
  kQTNetworkStatusNotConnected  = 0,
  kQTNetworkStatusConnected     = 1
};

typedef Handle                          QTAtomContainer;
typedef long                            QTAtom;
typedef long                            QTAtomType;
typedef long                            QTAtomID;
/* QTFloatDouble is the 64-bit IEEE-754 standard*/
typedef Float64                         QTFloatDouble;
/* QTFloatSingle is the 32-bit IEEE-754 standard*/
typedef Float32                         QTFloatSingle;


struct SoundDescription {
  long                descSize;               /* total size of SoundDescription including extra data */
  long                dataFormat;             /* sound format */
  long                resvd1;                 /* reserved for apple use. set to zero */
  short               resvd2;                 /* reserved for apple use. set to zero */
  short               dataRefIndex;
  short               version;                /* which version is this data */
  short               revlevel;               /* what version of that codec did this */
  long                vendor;                 /* whose  codec compressed this data */
  short               numChannels;            /* number of channels of sound */
  short               sampleSize;             /* number of bits per sample */
  short               compressionID;          /* unused. set to zero. */
  short               packetSize;             /* unused. set to zero. */
  UnsignedFixed       sampleRate;             /* sample rate sound is captured at */
};
typedef struct SoundDescription         SoundDescription;
typedef SoundDescription *              SoundDescriptionPtr;
typedef SoundDescriptionPtr *           SoundDescriptionHandle;
/* version 1 of the SoundDescription record*/
struct SoundDescriptionV1 {
                                              /* original fields*/
  SoundDescription    desc;
                                              /* fixed compression ratio information*/
  unsigned long       samplesPerPacket;
  unsigned long       bytesPerPacket;
  unsigned long       bytesPerFrame;
  unsigned long       bytesPerSample;
                                              /* additional atom based fields ([long size, long type, some data], repeat)*/
};
typedef struct SoundDescriptionV1       SoundDescriptionV1;
typedef SoundDescriptionV1 *            SoundDescriptionV1Ptr;
typedef SoundDescriptionV1Ptr *         SoundDescriptionV1Handle;


enum {
  kTx3gSampleType               = 'tx3g',
  kTx3gFontTableAtomType        = 'ftab',
  kTx3gBlinkAtomType            = 'blnk'
};

struct Tx3gRGBAColor {
  unsigned char       red;
  unsigned char       green;
  unsigned char       blue;
  unsigned char       transparency;
};
typedef struct Tx3gRGBAColor            Tx3gRGBAColor;
struct Tx3gStyleRecord {
  unsigned short      startChar;
  unsigned short      endChar;
  unsigned short      fontID;
  unsigned char       fontFace;
  unsigned char       fontSize;
  Tx3gRGBAColor       fontColor;
};
typedef struct Tx3gStyleRecord          Tx3gStyleRecord;
typedef Tx3gStyleRecord *               Tx3gStylePtr;
typedef Tx3gStylePtr *                  Tx3gStyleHandle;
struct Tx3gStyleTableRecord {
  unsigned short      count;
  Tx3gStyleRecord     table[1];
};
typedef struct Tx3gStyleTableRecord     Tx3gStyleTableRecord;
typedef Tx3gStyleTableRecord *          Tx3gStyleTablePtr;
typedef Tx3gStyleTablePtr *             Tx3gStyleTableHandle;
struct Tx3gFontRecord {
  unsigned short      fontID;
  unsigned char       nameLength;
  unsigned char       name[1];
};
typedef struct Tx3gFontRecord           Tx3gFontRecord;
typedef Tx3gFontRecord *                Tx3gFontRecordPtr;
struct Tx3gFontTableRecord {
  unsigned short      entryCount;
  Tx3gFontRecord      fontEntries[1];
};
typedef struct Tx3gFontTableRecord      Tx3gFontTableRecord;
typedef Tx3gFontTableRecord *           Tx3gFontTablePtr;
typedef Tx3gFontTablePtr *              Tx3gFontTableHandle;
struct Tx3gDescription {
  long                descSize;
  long                dataFormat;
  long                resvd1;
  short               resvd2;
  short               dataRefIndex;

  unsigned long       displayFlags;
  char                horizontalJustification;
  char                verticalJustification;
  Tx3gRGBAColor       backgroundColor;
  Rect                defaultTextBox;
  Tx3gStyleRecord     defaultStyle;
};
typedef struct Tx3gDescription          Tx3gDescription;
typedef Tx3gDescription *               Tx3gDescriptionPtr;
typedef Tx3gDescriptionPtr *            Tx3gDescriptionHandle;
struct TextDescription {
  long                descSize;               /* Total size of TextDescription*/
  long                dataFormat;             /* 'text'*/

  long                resvd1;
  short               resvd2;
  short               dataRefIndex;

  long                displayFlags;           /* see enum below for flag values*/

  long                textJustification;      /* Can be: teCenter,teFlush -Default,-Right,-Left*/

  RGBColor            bgColor;                /* Background color*/

  Rect                defaultTextBox;         /* Location to place the text within the track bounds*/
  ScrpSTElement       defaultStyle;           /* Default style (struct defined in TextEdit.h)*/
  char                defaultFontName[1];     /* Font Name (pascal string - struct extended to fit) */
};
typedef struct TextDescription          TextDescription;
typedef TextDescription *               TextDescriptionPtr;
typedef TextDescriptionPtr *            TextDescriptionHandle;
struct SpriteDescription {
  long                descSize;               /* total size of SpriteDescription including extra data */
  long                dataFormat;             /*  */
  long                resvd1;                 /* reserved for apple use */
  short               resvd2;
  short               dataRefIndex;
  long                version;                /* which version is this data */
  OSType              decompressorType;       /* which decompressor to use, 0 for no decompression */
  long                sampleFlags;            /* how to interpret samples */
};
typedef struct SpriteDescription        SpriteDescription;
typedef SpriteDescription *             SpriteDescriptionPtr;
typedef SpriteDescriptionPtr *          SpriteDescriptionHandle;
struct FlashDescription {
  long                descSize;
  long                dataFormat;
  long                resvd1;
  short               resvd2;
  short               dataRefIndex;
  long                version;                /* which version is this data */
  OSType              decompressorType;       /* which decompressor to use, 0 for no decompression */
  long                flags;
};
typedef struct FlashDescription         FlashDescription;
typedef FlashDescription *              FlashDescriptionPtr;
typedef FlashDescriptionPtr *           FlashDescriptionHandle;
struct ThreeDeeDescription {
  long                descSize;               /* total size of ThreeDeeDescription including extra data */
  long                dataFormat;             /*  */
  long                resvd1;                 /* reserved for apple use */
  short               resvd2;
  short               dataRefIndex;
  long                version;                /* which version is this data */
  long                rendererType;           /* which renderer to use, 0 for default */
  long                decompressorType;       /* which decompressor to use, 0 for default */
};
typedef struct ThreeDeeDescription      ThreeDeeDescription;
typedef ThreeDeeDescription *           ThreeDeeDescriptionPtr;
typedef ThreeDeeDescriptionPtr *        ThreeDeeDescriptionHandle;
struct DataReferenceRecord {
  OSType              dataRefType;
  Handle              dataRef;
};
typedef struct DataReferenceRecord      DataReferenceRecord;
typedef DataReferenceRecord *           DataReferencePtr;
/*--------------------------
  Music Sample Description
--------------------------*/
struct MusicDescription {
  long                descSize;
  long                dataFormat;             /* 'musi' */

  long                resvd1;
  short               resvd2;
  short               dataRefIndex;

  long                musicFlags;
  unsigned long       headerData[1];          /* variable size! */

};
typedef struct MusicDescription         MusicDescription;
typedef MusicDescription *              MusicDescriptionPtr;
typedef MusicDescriptionPtr *           MusicDescriptionHandle;
enum {
  kMusicFlagDontPlay2Soft       = 1L << 0,
  kMusicFlagDontSlaveToMovie    = 1L << 1
};


enum {
  dfDontDisplay                 = 1 << 0, /* Don't display the text*/
  dfDontAutoScale               = 1 << 1, /* Don't scale text as track bounds grows or shrinks*/
  dfClipToTextBox               = 1 << 2, /* Clip update to the textbox*/
  dfUseMovieBGColor             = 1 << 3, /* Set text background to movie's background color*/
  dfShrinkTextBoxToFit          = 1 << 4, /* Compute minimum box to fit the sample*/
  dfScrollIn                    = 1 << 5, /* Scroll text in until last of text is in view */
  dfScrollOut                   = 1 << 6, /* Scroll text out until last of text is gone (if both set, scroll in then out)*/
  dfHorizScroll                 = 1 << 7, /* Scroll text horizontally (otherwise it's vertical)*/
  dfReverseScroll               = 1 << 8, /* vert: scroll down rather than up; horiz: scroll backwards (justfication dependent)*/
  dfContinuousScroll            = 1 << 9, /* new samples cause previous samples to scroll out */
  dfFlowHoriz                   = 1 << 10, /* horiz scroll text flows in textbox rather than extend to right */
  dfContinuousKaraoke           = 1 << 11, /* ignore begin offset, hilite everything up to the end offset(karaoke)*/
  dfDropShadow                  = 1 << 12, /* display text with a drop shadow */
  dfAntiAlias                   = 1 << 13, /* attempt to display text anti aliased*/
  dfKeyedText                   = 1 << 14, /* key the text over background*/
  dfInverseHilite               = 1 << 15, /* Use inverse hiliting rather than using hilite color*/
  dfTextColorHilite             = 1 << 16 /* changes text color in place of hiliting. */
};

enum {
  searchTextDontGoToFoundTime   = 1L << 16,
  searchTextDontHiliteFoundText = 1L << 17,
  searchTextOneTrackOnly        = 1L << 18,
  searchTextEnabledTracksOnly   = 1L << 19
};

/*use these with the text property routines*/
enum {
                                        /* set property parameter / get property parameter*/
  kTextTextHandle               = 1,    /* Handle / preallocated Handle*/
  kTextTextPtr                  = 2,    /* Pointer*/
  kTextTEStyle                  = 3,    /* TextStyle * / TextStyle **/
  kTextSelection                = 4,    /* long [2] / long [2]*/
  kTextBackColor                = 5,    /* RGBColor * / RGBColor **/
  kTextForeColor                = 6,    /* RGBColor * / RGBColor **/
  kTextFace                     = 7,    /* long / long **/
  kTextFont                     = 8,    /* long / long **/
  kTextSize                     = 9,    /* long / long **/
  kTextAlignment                = 10,   /* short * / short **/
  kTextHilite                   = 11,   /* hiliteRecord * / hiliteRecord **/
  kTextDropShadow               = 12,   /* dropShadowRecord * / dropShadowRecord **/
  kTextDisplayFlags             = 13,   /* long / long **/
  kTextScroll                   = 14,   /* TimeValue * / TimeValue **/
  kTextRelativeScroll           = 15,   /* Point **/
  kTextHyperTextFace            = 16,   /* hyperTextSetFace * / hyperTextSetFace **/
  kTextHyperTextColor           = 17,   /* hyperTextSetColor * / hyperTextSetColor **/
  kTextKeyEntry                 = 18,   /* short*/
  kTextMouseDown                = 19,   /* Point **/
  kTextTextBox                  = 20,   /* Rect * / Rect **/
  kTextEditState                = 21,   /* short / short **/
  kTextLength                   = 22    /*       / long **/
};

enum {
  k3DMediaRendererEntry         = 'rend',
  k3DMediaRendererName          = 'name',
  k3DMediaRendererCode          = 'rcod'
};

/* progress messages */
enum {
  movieProgressOpen             = 0,
  movieProgressUpdatePercent    = 1,
  movieProgressClose            = 2
};

/* progress operations */
enum {
  progressOpFlatten             = 1,
  progressOpInsertTrackSegment  = 2,
  progressOpInsertMovieSegment  = 3,
  progressOpPaste               = 4,
  progressOpAddMovieSelection   = 5,
  progressOpCopy                = 6,
  progressOpCut                 = 7,
  progressOpLoadMovieIntoRam    = 8,
  progressOpLoadTrackIntoRam    = 9,
  progressOpLoadMediaIntoRam    = 10,
  progressOpImportMovie         = 11,
  progressOpExportMovie         = 12
};

enum {
  mediaQualityDraft             = 0x0000,
  mediaQualityNormal            = 0x0040,
  mediaQualityBetter            = 0x0080,
  mediaQualityBest              = 0x00C0
};

/*****
    Interactive Sprites Support
*****/
/* QTEventRecord flags*/
enum {
  kQTEventPayloadIsQTList       = 1L << 0
};

struct QTEventRecord {
  long                version;
  OSType              eventType;
  Point               where;
  long                flags;
  long                payloadRefcon;          /* from here down only present if version >= 2*/
  long                param1;
  long                param2;
  long                param3;
};
typedef struct QTEventRecord            QTEventRecord;
typedef QTEventRecord *                 QTEventRecordPtr;
struct QTAtomSpec {
  QTAtomContainer     container;
  QTAtom              atom;
};
typedef struct QTAtomSpec               QTAtomSpec;
typedef QTAtomSpec *                    QTAtomSpecPtr;
struct ResolvedQTEventSpec {
  QTAtomSpec          actionAtom;
  Track               targetTrack;
  long                targetRefCon;
};
typedef struct ResolvedQTEventSpec      ResolvedQTEventSpec;
typedef ResolvedQTEventSpec *           ResolvedQTEventSpecPtr;

/* action constants */
enum {
  kActionMovieSetVolume         = 1024, /* (short movieVolume) */
  kActionMovieSetRate           = 1025, /* (Fixed rate) */
  kActionMovieSetLoopingFlags   = 1026, /* (long loopingFlags) */
  kActionMovieGoToTime          = 1027, /* (TimeValue time) */
  kActionMovieGoToTimeByName    = 1028, /* (Str255 timeName) */
  kActionMovieGoToBeginning     = 1029, /* no params */
  kActionMovieGoToEnd           = 1030, /* no params */
  kActionMovieStepForward       = 1031, /* no params */
  kActionMovieStepBackward      = 1032, /* no params */
  kActionMovieSetSelection      = 1033, /* (TimeValue startTime, TimeValue endTime) */
  kActionMovieSetSelectionByName = 1034, /* (Str255 startTimeName, Str255 endTimeName) */
  kActionMoviePlaySelection     = 1035, /* (Boolean selectionOnly) */
  kActionMovieSetLanguage       = 1036, /* (long language) */
  kActionMovieChanged           = 1037, /* no params */
  kActionMovieRestartAtTime     = 1038, /* (TimeValue startTime, Fixed rate) */
  kActionMovieGotoNextChapter   = 1039, /* no params */
  kActionMovieGotoPreviousChapter = 1040, /* no params */
  kActionMovieGotoFirstChapter  = 1041, /* no params */
  kActionMovieGotoLastChapter   = 1042, /* no params */
  kActionMovieGotoChapterByIndex = 1043, /* ( short index ) */
  kActionMovieSetScale          = 1044, /* (Fixed xScale, Fixed yScale) */
  kActionTrackSetVolume         = 2048, /* (short volume) */
  kActionTrackSetBalance        = 2049, /* (short balance) */
  kActionTrackSetEnabled        = 2050, /* (Boolean enabled) */
  kActionTrackSetMatrix         = 2051, /* (MatrixRecord matrix) */
  kActionTrackSetLayer          = 2052, /* (short layer) */
  kActionTrackSetClip           = 2053, /* (RgnHandle clip) */
  kActionTrackSetCursor         = 2054, /* (QTATomID cursorID) */
  kActionTrackSetGraphicsMode   = 2055, /* (ModifierTrackGraphicsModeRecord graphicsMode) */
  kActionTrackSetIdleFrequency  = 2056, /* (long frequency) */
  kActionTrackSetBassTreble     = 2057, /* (short base, short treble) */
  kActionSpriteSetMatrix        = 3072, /* (MatrixRecord matrix) */
  kActionSpriteSetImageIndex    = 3073, /* (short imageIndex) */
  kActionSpriteSetVisible       = 3074, /* (short visible) */
  kActionSpriteSetLayer         = 3075, /* (short layer) */
  kActionSpriteSetGraphicsMode  = 3076, /* (ModifierTrackGraphicsModeRecord graphicsMode) */
  kActionSpritePassMouseToCodec = 3078, /* no params */
  kActionSpriteClickOnCodec     = 3079, /* Point localLoc */
  kActionSpriteTranslate        = 3080, /* (Fixed x, Fixed y, Boolean isAbsolute) */
  kActionSpriteScale            = 3081, /* (Fixed xScale, Fixed yScale) */
  kActionSpriteRotate           = 3082, /* (Fixed degrees) */
  kActionSpriteStretch          = 3083, /* (Fixed p1x, Fixed p1y, Fixed p2x, Fixed p2y, Fixed p3x, Fixed p3y, Fixed p4x, Fixed p4y) */
  kActionSpriteSetCanBeHitTested = 3094, /* (short canBeHitTested) */
  kActionQTVRSetPanAngle        = 4096, /* (float panAngle) */
  kActionQTVRSetTiltAngle       = 4097, /* (float tiltAngle) */
  kActionQTVRSetFieldOfView     = 4098, /* (float fieldOfView) */
  kActionQTVRShowDefaultView    = 4099, /* no params */
  kActionQTVRGoToNodeID         = 4100, /* (UInt32 nodeID) */
  kActionQTVREnableHotSpot      = 4101, /* long ID, Boolean enable */
  kActionQTVRShowHotSpots       = 4102, /* Boolean show */
  kActionQTVRTranslateObject    = 4103, /* float xMove, float yMove */
  kActionQTVRSetViewState       = 4109, /* long viewStateType, short state */
  kActionMusicPlayNote          = 5120, /* (long sampleDescIndex, long partNumber, long delay, long pitch, long velocity, long duration) */
  kActionMusicSetController     = 5121, /* (long sampleDescIndex, long partNumber, long delay, long controller, long value) */
  kActionCase                   = 6144, /* [(CaseStatementActionAtoms)] */
  kActionWhile                  = 6145, /* [(WhileStatementActionAtoms)] */
  kActionGoToURL                = 6146, /* (C string urlLink) */
  kActionSendQTEventToSprite    = 6147, /* ([(SpriteTargetAtoms)], QTEventRecord theEvent) */
  kActionDebugStr               = 6148, /* (Str255 theString) */
  kActionPushCurrentTime        = 6149, /* no params */
  kActionPushCurrentTimeWithLabel = 6150, /* (Str255 theLabel) */
  kActionPopAndGotoTopTime      = 6151, /* no params */
  kActionPopAndGotoLabeledTime  = 6152, /* (Str255 theLabel) */
  kActionStatusString           = 6153, /* (C string theString, long stringTypeFlags) */
  kActionSendQTEventToTrackObject = 6154, /* ([(TrackObjectTargetAtoms)], QTEventRecord theEvent) */
  kActionAddChannelSubscription = 6155, /* (Str255 channelName, C string channelsURL, C string channelsPictureURL) */
  kActionRemoveChannelSubscription = 6156, /* (C string channelsURL) */
  kActionOpenCustomActionHandler = 6157, /* (long handlerID, ComponentDescription handlerDesc) */
  kActionDoScript               = 6158, /* (long scriptTypeFlags, CString command, CString arguments) */
  kActionDoCompressedActions    = 6159, /* (compressed QTAtomContainer prefixed with eight bytes: long compressorType, long decompressedSize) */
  kActionSendAppMessage         = 6160, /* (long appMessageID) */
  kActionLoadComponent          = 6161, /* (ComponentDescription handlerDesc) */
  kActionSetFocus               = 6162, /* [(TargetAtoms theObject)] */
  kActionDontPassKeyEvent       = 6163, /* no params */
  kActionSetRandomSeed          = 6164, /* long randomSeed */
  kActionSpriteTrackSetVariable = 7168, /* (QTAtomID variableID, float value) */
  kActionSpriteTrackNewSprite   = 7169, /* (QTAtomID spriteID, short imageIndex, MatrixRecord *matrix, short visible, short layer, ModifierTrackGraphicsModeRecord *graphicsMode, QTAtomID actionHandlingSpriteID) */
  kActionSpriteTrackDisposeSprite = 7170, /* (QTAtomID spriteID) */
  kActionSpriteTrackSetVariableToString = 7171, /* (QTAtomID variableID, C string value) */
  kActionSpriteTrackConcatVariables = 7172, /* (QTAtomID firstVariableID, QTAtomID secondVariableID, QTAtomID resultVariableID ) */
  kActionSpriteTrackSetVariableToMovieURL = 7173, /* (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) */
  kActionSpriteTrackSetVariableToMovieBaseURL = 7174, /* (QTAtomID variableID, < optional: [(MovieTargetAtoms)] > ) */
  kActionSpriteTrackSetAllSpritesHitTestingMode = 7181,
  kActionSpriteTrackNewImage    = 7182, /* (C string imageURL, QTAtomID desiredID) */
  kActionSpriteTrackDisposeImage = 7183, /* (short imageIndex) */
  kActionApplicationNumberAndString = 8192, /* (long aNumber, Str255 aString ) */
  kActionQD3DNamedObjectTranslateTo = 9216, /* (Fixed x, Fixed y, Fixed z ) */
  kActionQD3DNamedObjectScaleTo = 9217, /* (Fixed xScale, Fixed yScale, Fixed zScale ) */
  kActionQD3DNamedObjectRotateTo = 9218, /* (Fixed xDegrees, Fixed yDegrees, Fixed zDegrees ) */
  kActionFlashTrackSetPan       = 10240, /* (short xPercent, short yPercent ) */
  kActionFlashTrackSetZoom      = 10241, /* (short zoomFactor ) */
  kActionFlashTrackSetZoomRect  = 10242, /* (long left, long top, long right, long bottom ) */
  kActionFlashTrackGotoFrameNumber = 10243, /* (long frameNumber ) */
  kActionFlashTrackGotoFrameLabel = 10244, /* (C string frameLabel ) */
  kActionFlashTrackSetFlashVariable = 10245, /* (C string path, C string name, C string value, Boolean updateFocus) */
  kActionFlashTrackDoButtonActions = 10246, /* (C string path, long buttonID, long transition) */
  kActionMovieTrackAddChildMovie = 11264, /* (QTAtomID childMovieID, C string childMovieURL) */
  kActionMovieTrackLoadChildMovie = 11265, /* (QTAtomID childMovieID) */
  kActionMovieTrackLoadChildMovieWithQTListParams = 11266, /* (QTAtomID childMovieID, C string qtlistXML) */
  kActionTextTrackPasteText     = 12288, /* (C string theText, long startSelection, long endSelection ) */
  kActionTextTrackSetTextBox    = 12291, /* (short left, short top, short right, short bottom) */
  kActionTextTrackSetTextStyle  = 12292, /* (Handle textStyle) */
  kActionTextTrackSetSelection  = 12293, /* (long startSelection, long endSelection ) */
  kActionTextTrackSetBackgroundColor = 12294, /* (ModifierTrackGraphicsModeRecord backgroundColor ) */
  kActionTextTrackSetForegroundColor = 12295, /* (ModifierTrackGraphicsModeRecord foregroundColor ) */
  kActionTextTrackSetFace       = 12296, /* (long fontFace ) */
  kActionTextTrackSetFont       = 12297, /* (long fontID ) */
  kActionTextTrackSetSize       = 12298, /* (long fontSize ) */
  kActionTextTrackSetAlignment  = 12299, /* (short alignment ) */
  kActionTextTrackSetHilite     = 12300, /* (long startHighlight, long endHighlight, ModifierTrackGraphicsModeRecord highlightColor ) */
  kActionTextTrackSetDropShadow = 12301, /* (Point dropShadow, short transparency ) */
  kActionTextTrackSetDisplayFlags = 12302, /* (long flags ) */
  kActionTextTrackSetScroll     = 12303, /* (long delay ) */
  kActionTextTrackRelativeScroll = 12304, /* (short deltaX, short deltaY ) */
  kActionTextTrackFindText      = 12305, /* (long flags, Str255 theText, ModifierTrackGraphicsModeRecord highlightColor ) */
  kActionTextTrackSetHyperTextFace = 12306, /* (short index, long fontFace ) */
  kActionTextTrackSetHyperTextColor = 12307, /* (short index, ModifierTrackGraphicsModeRecord highlightColor ) */
  kActionTextTrackKeyEntry      = 12308, /* (short character ) */
  kActionTextTrackMouseDown     = 12309, /* no params */
  kActionTextTrackSetEditable   = 12310, /* (short editState) */
  kActionListAddElement         = 13312, /* (C string parentPath, long atIndex, C string newElementName) */
  kActionListRemoveElements     = 13313, /* (C string parentPath, long startIndex, long endIndex) */
  kActionListSetElementValue    = 13314, /* (C string elementPath, C string valueString) */
  kActionListPasteFromXML       = 13315, /* (C string xml, C string targetParentPath, long startIndex) */
  kActionListSetMatchingFromXML = 13316, /* (C string xml, C string targetParentPath) */
  kActionListSetFromURL         = 13317, /* (C string url, C string targetParentPath ) */
  kActionListExchangeLists      = 13318, /* (C string url, C string parentPath) */
  kActionListServerQuery        = 13319, /* (C string url, C string keyValuePairs, long flags, C string parentPath) */
  kActionListAddAttribute       = 13320, /* (C string elementPath, long atIndex, C string newAttributeName) */
  kActionListRemoveAttributes   = 13321, /* (C string elementPath, long startIndex, long endIndex) */
  kActionListSetAttributeValue  = 13322 /* (C string elementPath, C string attributeName, C string valueString) */
};


enum {
  kOperandExpression            = 1,
  kOperandConstant              = 2,
  kOperandSubscribedToChannel   = 3,    /* C string channelsURL */
  kOperandUniqueCustomActionHandlerID = 4,
  kOperandCustomActionHandlerIDIsOpen = 5, /* long ID */
  kOperandConnectionSpeed       = 6,
  kOperandGMTDay                = 7,
  kOperandGMTMonth              = 8,
  kOperandGMTYear               = 9,
  kOperandGMTHours              = 10,
  kOperandGMTMinutes            = 11,
  kOperandGMTSeconds            = 12,
  kOperandLocalDay              = 13,
  kOperandLocalMonth            = 14,
  kOperandLocalYear             = 15,
  kOperandLocalHours            = 16,
  kOperandLocalMinutes          = 17,
  kOperandLocalSeconds          = 18,
  kOperandRegisteredForQuickTimePro = 19,
  kOperandPlatformRunningOn     = 20,
  kOperandQuickTimeVersion      = 21,
  kOperandComponentVersion      = 22,   /* C string type, C string subType, C string manufacturer */
  kOperandOriginalHandlerRefcon = 23,
  kOperandTicks                 = 24,
  kOperandMaxLoadedTimeInMovie  = 25,
  kOperandEventParameter        = 26,   /* short index */
  kOperandFreeMemory            = 27,
  kOperandNetworkStatus         = 28,
  kOperandQuickTimeVersionRegistered = 29, /* long version */
  kOperandSystemVersion         = 30,
  kOperandMovieVolume           = 1024,
  kOperandMovieRate             = 1025,
  kOperandMovieIsLooping        = 1026,
  kOperandMovieLoopIsPalindrome = 1027,
  kOperandMovieTime             = 1028,
  kOperandMovieDuration         = 1029,
  kOperandMovieTimeScale        = 1030,
  kOperandMovieWidth            = 1031,
  kOperandMovieHeight           = 1032,
  kOperandMovieLoadState        = 1033,
  kOperandMovieTrackCount       = 1034,
  kOperandMovieIsActive         = 1035,
  kOperandMovieName             = 1036,
  kOperandMovieID               = 1037,
  kOperandMovieChapterCount     = 1038,
  kOperandMovieChapterIndex     = 1039,
  kOperandMovieChapterName      = 1040,
  kOperandMovieChapterNameByIndex = 1041, /* ( short index ) */
  kOperandMovieChapterIndexByName = 1042, /* (c string name)  */
  kOperandMovieAnnotation       = 1043, /* (c string requested, long flags) */
  kOperandMovieConnectionFlags  = 1044,
  kOperandMovieConnectionString = 1045,
  kOperandTrackVolume           = 2048,
  kOperandTrackBalance          = 2049,
  kOperandTrackEnabled          = 2050,
  kOperandTrackLayer            = 2051,
  kOperandTrackWidth            = 2052,
  kOperandTrackHeight           = 2053,
  kOperandTrackDuration         = 2054,
  kOperandTrackName             = 2055,
  kOperandTrackID               = 2056,
  kOperandTrackIdleFrequency    = 2057,
  kOperandTrackBass             = 2058,
  kOperandTrackTreble           = 2059,
  kOperandSpriteBoundsLeft      = 3072,
  kOperandSpriteBoundsTop       = 3073,
  kOperandSpriteBoundsRight     = 3074,
  kOperandSpriteBoundsBottom    = 3075,
  kOperandSpriteImageIndex      = 3076,
  kOperandSpriteVisible         = 3077,
  kOperandSpriteLayer           = 3078,
  kOperandSpriteTrackVariable   = 3079, /* [QTAtomID variableID] */
  kOperandSpriteTrackNumSprites = 3080,
  kOperandSpriteTrackNumImages  = 3081,
  kOperandSpriteID              = 3082,
  kOperandSpriteIndex           = 3083,
  kOperandSpriteFirstCornerX    = 3084,
  kOperandSpriteFirstCornerY    = 3085,
  kOperandSpriteSecondCornerX   = 3086,
  kOperandSpriteSecondCornerY   = 3087,
  kOperandSpriteThirdCornerX    = 3088,
  kOperandSpriteThirdCornerY    = 3089,
  kOperandSpriteFourthCornerX   = 3090,
  kOperandSpriteFourthCornerY   = 3091,
  kOperandSpriteImageRegistrationPointX = 3092,
  kOperandSpriteImageRegistrationPointY = 3093,
  kOperandSpriteTrackSpriteIDAtPoint = 3094, /* short x, short y */
  kOperandSpriteName            = 3095,
  kOperandSpriteCanBeHitTested  = 3105, /* short */
  kOperandSpriteTrackAllSpritesHitTestingMode = 3106,
  kOperandSpriteTrackImageIDByIndex = 3107, /* short imageIndex */
  kOperandSpriteTrackImageIndexByID = 3108, /* QTAtomID */
  kOperandQTVRPanAngle          = 4096,
  kOperandQTVRTiltAngle         = 4097,
  kOperandQTVRFieldOfView       = 4098,
  kOperandQTVRNodeID            = 4099,
  kOperandQTVRHotSpotsVisible   = 4100,
  kOperandQTVRViewCenterH       = 4101,
  kOperandQTVRViewCenterV       = 4102,
  kOperandQTVRViewStateCount    = 4103,
  kOperandQTVRViewState         = 4104, /* long viewStateType */
  kOperandMouseLocalHLoc        = 5120, /* [TargetAtoms aTrack] */
  kOperandMouseLocalVLoc        = 5121, /* [TargetAtoms aTrack] */
  kOperandKeyIsDown             = 5122, /* [short modKeys, char asciiValue] */
  kOperandRandom                = 5123, /* [short min, short max] */
  kOperandCanHaveFocus          = 5124, /* [(TargetAtoms theObject)] */
  kOperandHasFocus              = 5125, /* [(TargetAtoms theObject)] */
  kOperandTextTrackEditable     = 6144,
  kOperandTextTrackCopyText     = 6145, /* long startSelection, long endSelection */
  kOperandTextTrackStartSelection = 6146,
  kOperandTextTrackEndSelection = 6147,
  kOperandTextTrackTextBoxLeft  = 6148,
  kOperandTextTrackTextBoxTop   = 6149,
  kOperandTextTrackTextBoxRight = 6150,
  kOperandTextTrackTextBoxBottom = 6151,
  kOperandTextTrackTextLength   = 6152,
  kOperandListCountElements     = 7168, /* (C string parentPath) */
  kOperandListGetElementPathByIndex = 7169, /* (C string parentPath, long index) */
  kOperandListGetElementValue   = 7170, /* (C string elementPath) */
  kOperandListCopyToXML         = 7171, /* (C string parentPath, long startIndex, long endIndex) */
  kOperandListCountAttributes   = 7172, /* (C string elementPath) */
  kOperandListGetAttributeNameByIndex = 7173, /* (C string elementPath, long index) */
  kOperandListGetAttributeValue = 7174, /* (C string elementPath, C string attributeName) */
  kOperandSin                   = 8192, /* float x    */
  kOperandCos                   = 8193, /* float x    */
  kOperandTan                   = 8194, /* float x    */
  kOperandATan                  = 8195, /* float x    */
  kOperandATan2                 = 8196, /* float y, float x   */
  kOperandDegreesToRadians      = 8197, /* float x */
  kOperandRadiansToDegrees      = 8198, /* float x */
  kOperandSquareRoot            = 8199, /* float x */
  kOperandExponent              = 8200, /* float x */
  kOperandLog                   = 8201, /* float x */
  kOperandFlashTrackVariable    = 9216, /* [CString path, CString name] */
  kOperandStringLength          = 10240, /* (C string text) */
  kOperandStringCompare         = 10241, /* (C string aText, C string bText, Boolean caseSensitive, Boolan diacSensitive) */
  kOperandStringSubString       = 10242, /* (C string text, long offset, long length) */
  kOperandStringConcat          = 10243 /* (C string aText, C string bText) */
};

enum {
  kFirstMovieAction             = kActionMovieSetVolume,
  kLastMovieAction              = kActionMovieSetScale,
  kFirstTrackAction             = kActionTrackSetVolume,
  kLastTrackAction              = kActionTrackSetBassTreble,
  kFirstSpriteAction            = kActionSpriteSetMatrix,
  kLastSpriteAction             = kActionSpriteSetCanBeHitTested,
  kFirstQTVRAction              = kActionQTVRSetPanAngle,
  kLastQTVRAction               = kActionQTVRSetViewState,
  kFirstMusicAction             = kActionMusicPlayNote,
  kLastMusicAction              = kActionMusicSetController,
  kFirstSystemAction            = kActionCase,
  kLastSystemAction             = kActionSetRandomSeed,
  kFirstSpriteTrackAction       = kActionSpriteTrackSetVariable,
  kLastSpriteTrackAction        = kActionSpriteTrackDisposeImage,
  kFirstApplicationAction       = kActionApplicationNumberAndString,
  kLastApplicationAction        = kActionApplicationNumberAndString,
  kFirstQD3DNamedObjectAction   = kActionQD3DNamedObjectTranslateTo,
  kLastQD3DNamedObjectAction    = kActionQD3DNamedObjectRotateTo,
  kFirstFlashTrackAction        = kActionFlashTrackSetPan,
  kLastFlashTrackAction         = kActionFlashTrackDoButtonActions,
  kFirstMovieTrackAction        = kActionMovieTrackAddChildMovie,
  kLastMovieTrackAction         = kActionMovieTrackLoadChildMovieWithQTListParams,
  kFirstTextTrackAction         = kActionTextTrackPasteText,
  kLastTextTrackAction          = kActionTextTrackSetEditable,
  kFirstMultiTargetAction       = kActionListAddElement,
  kLastMultiTargetAction        = kActionListSetAttributeValue,
  kFirstAction                  = kFirstMovieAction,
  kLastAction                   = kLastMultiTargetAction
};

/* target atom types*/
enum {
  kTargetMovie                  = 'moov', /* no data */
  kTargetMovieName              = 'mona', /* (PString movieName) */
  kTargetMovieID                = 'moid', /* (long movieID) */
  kTargetRootMovie              = 'moro', /* no data */
  kTargetParentMovie            = 'mopa', /* no data */
  kTargetChildMovieTrackName    = 'motn', /* (PString childMovieTrackName) */
  kTargetChildMovieTrackID      = 'moti', /* (long childMovieTrackID) */
  kTargetChildMovieTrackIndex   = 'motx', /* (long childMovieTrackIndex) */
  kTargetChildMovieMovieName    = 'momn', /* (PString childMovieName) */
  kTargetChildMovieMovieID      = 'momi', /* (long childMovieID) */
  kTargetTrackName              = 'trna', /* (PString trackName) */
  kTargetTrackID                = 'trid', /* (long trackID) */
  kTargetTrackType              = 'trty', /* (OSType trackType) */
  kTargetTrackIndex             = 'trin', /* (long trackIndex) */
  kTargetSpriteName             = 'spna', /* (PString spriteName) */
  kTargetSpriteID               = 'spid', /* (QTAtomID spriteID) */
  kTargetSpriteIndex            = 'spin', /* (short spriteIndex) */
  kTargetQD3DNamedObjectName    = 'nana', /* (CString objectName) */
  kTargetCurrentQTEventParams   = 'evpa' /* no data */
};

/* action container atom types*/
enum {
  kQTEventType                  = 'evnt',
  kAction                       = 'actn',
  kWhichAction                  = 'whic',
  kActionParameter              = 'parm',
  kActionTarget                 = 'targ',
  kActionFlags                  = 'flag',
  kActionParameterMinValue      = 'minv',
  kActionParameterMaxValue      = 'maxv',
  kActionListAtomType           = 'list',
  kExpressionContainerAtomType  = 'expr',
  kConditionalAtomType          = 'test',
  kOperatorAtomType             = 'oper',
  kOperandAtomType              = 'oprn',
  kCommentAtomType              = 'why ',
  kCustomActionHandler          = 'cust',
  kCustomHandlerID              = 'id  ',
  kCustomHandlerDesc            = 'desc',
  kQTEventRecordAtomType        = 'erec'
};

/* QTEvent types */
enum {
  kQTEventMouseClick            = 'clik',
  kQTEventMouseClickEnd         = 'cend',
  kQTEventMouseClickEndTriggerButton = 'trig',
  kQTEventMouseEnter            = 'entr',
  kQTEventMouseExit             = 'exit',
  kQTEventMouseMoved            = 'move',
  kQTEventFrameLoaded           = 'fram',
  kQTEventIdle                  = 'idle',
  kQTEventKey                   = 'key ', /* qtevent.param1 = key, qtevent.param2 = modifiers, qtEvent.param3 = scanCode */
  kQTEventMovieLoaded           = 'load',
  kQTEventRequestToModifyMovie  = 'reqm',
  kQTEventListReceived          = 'list',
  kQTEventKeyUp                 = 'keyU' /* qtevent.param1 = key, qtevent.param2 = modifiers, qtEvent.param3 = scanCode */
};

/* flags for the kActionFlags atom */
enum {
  kActionFlagActionIsDelta      = 1L << 1,
  kActionFlagParameterWrapsAround = 1L << 2,
  kActionFlagActionIsToggle     = 1L << 3
};

/* flags for stringTypeFlags field of the QTStatusStringRecord */
enum {
  kStatusStringIsURLLink        = 1L << 1,
  kStatusStringIsStreamingStatus = 1L << 2,
  kStatusHasCodeNumber          = 1L << 3, /* high 16 bits of stringTypeFlags is error code number*/
  kStatusIsError                = 1L << 4
};

/* flags for scriptTypeFlags field of the QTDoScriptRecord*/
enum {
  kScriptIsUnknownType          = 1L << 0,
  kScriptIsJavaScript           = 1L << 1,
  kScriptIsLingoEvent           = 1L << 2,
  kScriptIsVBEvent              = 1L << 3,
  kScriptIsProjectorCommand     = 1L << 4,
  kScriptIsAppleScript          = 1L << 5
};

/* flags for CheckQuickTimeRegistration routine*/
enum {
  kQTRegistrationDialogTimeOutFlag = 1 << 0,
  kQTRegistrationDialogShowDialog = 1 << 1,
  kQTRegistrationDialogForceDialog = 1 << 2
};

/* constants for kOperatorAtomType IDs (operator types)*/
enum {
  kOperatorAdd                  = 'add ',
  kOperatorSubtract             = 'sub ',
  kOperatorMultiply             = 'mult',
  kOperatorDivide               = 'div ',
  kOperatorOr                   = 'or  ',
  kOperatorAnd                  = 'and ',
  kOperatorNot                  = 'not ',
  kOperatorLessThan             = '<   ',
  kOperatorLessThanEqualTo      = '<=  ',
  kOperatorEqualTo              = '=   ',
  kOperatorNotEqualTo           = '!=  ',
  kOperatorGreaterThan          = '>   ',
  kOperatorGreaterThanEqualTo   = '>=  ',
  kOperatorModulo               = 'mod ',
  kOperatorIntegerDivide        = 'idiv',
  kOperatorAbsoluteValue        = 'abs ',
  kOperatorNegate               = 'neg '
};

/* constants for kOperandPlatformRunningOn*/
enum {
  kPlatformMacintosh            = 1,
  kPlatformWindows              = 2
};

/* flags for kOperandSystemVersion*/
enum {
  kSystemIsWindows9x            = 0x00010000,
  kSystemIsWindowsNT            = 0x00020000,
  kSystemIsClassicBlueBox       = 0x00040000
};

/* constants for MediaPropertiesAtom*/
enum {
  kMediaPropertyNonLinearAtomType = 'nonl',
  kMediaPropertyHasActions      = 105
};

/* property types*/
typedef OSType                          QTPropertyClass;
typedef OSType                          QTPropertyID;
typedef OSType                          QTPropertyValueType;
typedef void *                          QTPropertyValuePtr;
typedef const void *                    ConstQTPropertyValuePtr;
/* TimeBase and TimeRecord moved to MacTypes.h */
typedef UInt32 TimeBaseFlags;
enum {
  loopTimeBase                  = 1,
  palindromeLoopTimeBase        = 2,
  maintainTimeBaseZero          = 4
};

typedef struct QTCallBackHeader*        QTCallBack;
/* CallBack equates */
typedef UInt16 QTCallBackFlags;
enum {
  triggerTimeFwd                = 0x0001, /* when curTime exceeds triggerTime going forward */
  triggerTimeBwd                = 0x0002, /* when curTime exceeds triggerTime going backwards */
  triggerTimeEither             = 0x0003, /* when curTime exceeds triggerTime going either direction */
  triggerRateLT                 = 0x0004, /* when rate changes to less than trigger value */
  triggerRateGT                 = 0x0008, /* when rate changes to greater than trigger value */
  triggerRateEqual              = 0x0010, /* when rate changes to equal trigger value */
  triggerRateLTE                = triggerRateLT | triggerRateEqual,
  triggerRateGTE                = triggerRateGT | triggerRateEqual,
  triggerRateNotEqual           = triggerRateGT | triggerRateEqual | triggerRateLT,
  triggerRateChange             = 0,
  triggerAtStart                = 0x0001,
  triggerAtStop                 = 0x0002
};

typedef UInt32 TimeBaseStatus;
enum {
  timeBaseBeforeStartTime       = 1,
  timeBaseAfterStopTime         = 2,
  timeBaseRateChanging          = 4
};


typedef UInt16 QTCallBackType;
enum {
  callBackAtTime                = 1,
  callBackAtRate                = 2,
  callBackAtTimeJump            = 3,
  callBackAtExtremes            = 4,
  callBackAtTimeBaseDisposed    = 5,
  callBackAtInterrupt           = 0x8000,
  callBackAtDeferredTask        = 0x4000
};

typedef CALLBACK_API( void , QTCallBackProcPtr )(QTCallBack cb, long refCon);
typedef STACK_UPP_TYPE(QTCallBackProcPtr)                       QTCallBackUPP;
enum {
  qtcbNeedsRateChanges          = 1,    /* wants to know about rate changes */
  qtcbNeedsTimeChanges          = 2,    /* wants to know about time changes */
  qtcbNeedsStartStopChanges     = 4     /* wants to know when TimeBase start/stop is changed*/
};

struct QTCallBackOpaqueHeader {
  long                callBackFlags;
  long                reserved1;
  SInt8               qtPrivate[52];
};
typedef struct QTCallBackOpaqueHeader   QTCallBackOpaqueHeader;
typedef CALLBACK_API( void , QTSyncTaskProcPtr )(void * task);
typedef STACK_UPP_TYPE(QTSyncTaskProcPtr)                       QTSyncTaskUPP;
struct QTSyncTaskRecord {
  void *              qLink;
  QTSyncTaskUPP       proc;
};
typedef struct QTSyncTaskRecord         QTSyncTaskRecord;
typedef QTSyncTaskRecord *              QTSyncTaskPtr;

typedef CALLBACK_API( OSErr , MovieRgnCoverProcPtr )(Movie theMovie, RgnHandle changedRgn, long refcon);
typedef CALLBACK_API( OSErr , MovieProgressProcPtr )(Movie theMovie, short message, short whatOperation, Fixed percentDone, long refcon);
typedef CALLBACK_API( OSErr , MovieDrawingCompleteProcPtr )(Movie theMovie, long refCon);
typedef CALLBACK_API( OSErr , TrackTransferProcPtr )(Track t, long refCon);
typedef CALLBACK_API( OSErr , GetMovieProcPtr )(long offset, long size, void *dataPtr, void *refCon);
typedef CALLBACK_API( Boolean , MoviePreviewCallOutProcPtr )(long refcon);
typedef CALLBACK_API( OSErr , TextMediaProcPtr )(Handle theText, Movie theMovie, short *displayFlag, long refcon);
typedef CALLBACK_API( OSErr , ActionsProcPtr )(void *refcon, Track targetTrack, long targetRefCon, QTEventRecordPtr theEvent);
typedef CALLBACK_API( OSErr , DoMCActionProcPtr )(void *refcon, short action, void *params, Boolean *handled);
typedef CALLBACK_API( OSErr , MovieExecuteWiredActionsProcPtr )(Movie theMovie, void *refcon, long flags, QTAtomContainer wiredActions);
typedef CALLBACK_API( void , MoviePrePrerollCompleteProcPtr )(Movie theMovie, OSErr prerollErr, void *refcon);
typedef CALLBACK_API( void , QTNextTaskNeededSoonerCallbackProcPtr )(TimeValue duration, unsigned long flags, void *refcon);
typedef CALLBACK_API( void , MoviesErrorProcPtr )(OSErr theErr, long refcon);
typedef STACK_UPP_TYPE(MovieRgnCoverProcPtr)                    MovieRgnCoverUPP;
typedef STACK_UPP_TYPE(MovieProgressProcPtr)                    MovieProgressUPP;
typedef STACK_UPP_TYPE(MovieDrawingCompleteProcPtr)             MovieDrawingCompleteUPP;
typedef STACK_UPP_TYPE(TrackTransferProcPtr)                    TrackTransferUPP;
typedef STACK_UPP_TYPE(GetMovieProcPtr)                         GetMovieUPP;
typedef STACK_UPP_TYPE(MoviePreviewCallOutProcPtr)              MoviePreviewCallOutUPP;
typedef STACK_UPP_TYPE(TextMediaProcPtr)                        TextMediaUPP;
typedef STACK_UPP_TYPE(ActionsProcPtr)                          ActionsUPP;
typedef STACK_UPP_TYPE(DoMCActionProcPtr)                       DoMCActionUPP;
typedef STACK_UPP_TYPE(MovieExecuteWiredActionsProcPtr)         MovieExecuteWiredActionsUPP;
typedef STACK_UPP_TYPE(MoviePrePrerollCompleteProcPtr)          MoviePrePrerollCompleteUPP;
typedef STACK_UPP_TYPE(QTNextTaskNeededSoonerCallbackProcPtr)   QTNextTaskNeededSoonerCallbackUPP;
typedef STACK_UPP_TYPE(MoviesErrorProcPtr)                      MoviesErrorUPP;
typedef ComponentInstance               MediaHandler;
typedef ComponentInstance               DataHandler;
typedef Component                       MediaHandlerComponent;
typedef Component                       DataHandlerComponent;
typedef ComponentResult                 HandlerError;
enum {
  keepInRam                     = 1 << 0, /* load and make non-purgable*/
  unkeepInRam                   = 1 << 1, /* mark as purgable*/
  flushFromRam                  = 1 << 2, /* empty those handles*/
  loadForwardTrackEdits         = 1 << 3, /*    load track edits into ram for playing forward*/
  loadBackwardTrackEdits        = 1 << 4 /*    load track edits into ram for playing in reverse*/
};

enum {
  newMovieActive                = 1 << 0,
  newMovieDontResolveDataRefs   = 1 << 1,
  newMovieDontAskUnresolvedDataRefs = 1 << 2,
  newMovieDontAutoAlternates    = 1 << 3,
  newMovieDontUpdateForeBackPointers = 1 << 4,
  newMovieDontAutoUpdateClock   = 1 << 5,
  newMovieAsyncOK               = 1 << 8,
  newMovieIdleImportOK          = 1 << 10,
  newMovieDontInteractWithUser  = 1 << 11
};

/* track usage bits */
enum {
  trackUsageInMovie             = 1 << 1,
  trackUsageInPreview           = 1 << 2,
  trackUsageInPoster            = 1 << 3
};

/* Add/GetMediaSample flags */
enum {
  mediaSampleNotSync            = 1 << 0, /* sample is not a sync sample (eg. is frame differenced */
  mediaSampleShadowSync         = 1 << 1 /* sample is a shadow sync */
};

enum {
  pasteInParallel               = 1 << 0,
  showUserSettingsDialog        = 1 << 1,
  movieToFileOnlyExport         = 1 << 2,
  movieFileSpecValid            = 1 << 3
};

enum {
  nextTimeMediaSample           = 1 << 0,
  nextTimeMediaEdit             = 1 << 1,
  nextTimeTrackEdit             = 1 << 2,
  nextTimeSyncSample            = 1 << 3,
  nextTimeStep                  = 1 << 4,
  nextTimeEdgeOK                = 1 << 14,
  nextTimeIgnoreActiveSegment   = 1 << 15
};

typedef unsigned short                  nextTimeFlagsEnum;
enum {
  createMovieFileDeleteCurFile  = 1L << 31,
  createMovieFileDontCreateMovie = 1L << 30,
  createMovieFileDontOpenFile   = 1L << 29,
  createMovieFileDontCreateResFile = 1L << 28
};

typedef unsigned long                   createMovieFileFlagsEnum;
enum {
  flattenAddMovieToDataFork     = 1L << 0,
  flattenActiveTracksOnly       = 1L << 2,
  flattenDontInterleaveFlatten  = 1L << 3,
  flattenFSSpecPtrIsDataRefRecordPtr = 1L << 4,
  flattenCompressMovieResource  = 1L << 5,
  flattenForceMovieResourceBeforeMovieData = 1L << 6
};

typedef unsigned long                   movieFlattenFlagsEnum;
enum {
  movieInDataForkResID          = -1    /* magic res ID */
};

enum {
  mcTopLeftMovie                = 1 << 0, /* usually centered */
  mcScaleMovieToFit             = 1 << 1, /* usually only scales down */
  mcWithBadge                   = 1 << 2, /* give me a badge */
  mcNotVisible                  = 1 << 3, /* don't show controller */
  mcWithFrame                   = 1 << 4 /* gimme a frame */
};

enum {
  movieScrapDontZeroScrap       = 1 << 0,
  movieScrapOnlyPutMovie        = 1 << 1
};

enum {
  dataRefSelfReference          = 1 << 0,
  dataRefWasNotResolved         = 1 << 1
};

typedef unsigned long                   dataRefAttributesFlags;
enum {
  kMovieAnchorDataRefIsDefault  = 1 << 0 /* data ref returned is movie default data ref */
};

enum {
  hintsScrubMode                = 1 << 0, /* mask == && (if flags == scrub on, flags != scrub off) */
  hintsLoop                     = 1 << 1,
  hintsDontPurge                = 1 << 2,
  hintsUseScreenBuffer          = 1 << 5,
  hintsAllowInterlace           = 1 << 6,
  hintsUseSoundInterp           = 1 << 7,
  hintsHighQuality              = 1 << 8, /* slooooow */
  hintsPalindrome               = 1 << 9,
  hintsInactive                 = 1 << 11,
  hintsOffscreen                = 1 << 12,
  hintsDontDraw                 = 1 << 13,
  hintsAllowBlacklining         = 1 << 14,
  hintsDontUseVideoOverlaySurface = 1 << 16,
  hintsIgnoreBandwidthRestrictions = 1 << 17,
  hintsPlayingEveryFrame        = 1 << 18,
  hintsAllowDynamicResize       = 1 << 19,
  hintsSingleField              = 1 << 20,
  hintsNoRenderingTimeOut       = 1 << 21,
  hintsFlushVideoInsteadOfDirtying = 1 << 22,
  hintsEnableSubPixelPositioning = 1L << 23,
  hintsRenderingMode            = 1L << 24,
  hintsAllowIdleSleep           = 1L << 25, /* asks media handlers not to call UpdateSystemActivity etc */
  hintsDeinterlaceFields        = 1L << 26
};

typedef unsigned long                   playHintsEnum;
enum {
  mediaHandlerFlagBaseClient    = 1
};

typedef unsigned long                   mediaHandlerFlagsEnum;
enum {
  movieTrackMediaType           = 1 << 0,
  movieTrackCharacteristic      = 1 << 1,
  movieTrackEnabledOnly         = 1 << 2
};

struct SampleReferenceRecord {
  long                dataOffset;
  long                dataSize;
  TimeValue           durationPerSample;
  long                numberOfSamples;
  short               sampleFlags;
};
typedef struct SampleReferenceRecord    SampleReferenceRecord;
typedef SampleReferenceRecord *         SampleReferencePtr;
struct SampleReference64Record {
  wide                dataOffset;
  unsigned long       dataSize;
  TimeValue           durationPerSample;
  unsigned long       numberOfSamples;
  short               sampleFlags;
};
typedef struct SampleReference64Record  SampleReference64Record;
typedef SampleReference64Record *       SampleReference64Ptr;

/*************************
* Initialization Routines 
**************************/
/*
 *  CheckQuickTimeRegistration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
CheckQuickTimeRegistration(
  void *  registrationKey,
  long    flags)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EnterMovies()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
EnterMovies(void)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ExitMovies()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ExitMovies(void)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  kQTEnterMoviesFlagDontSetComponentsThreadMode = 1L << 0
};

/*
 *  EnterMoviesOnThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
EnterMoviesOnThread(UInt32 inFlags)                           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  ExitMoviesOnThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
ExitMoviesOnThread(void)                                      AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*************************
* Error Routines 
**************************/

/*
 *  GetMoviesError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMoviesError(void)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClearMoviesStickyError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ClearMoviesStickyError(void)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviesStickyError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMoviesStickyError(void)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviesErrorProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviesErrorProc(
  MoviesErrorUPP   errProc,
  long             refcon)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* Idle Routines 
**************************/
/*
 *  MoviesTask()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
MoviesTask(
  Movie   theMovie,
  long    maxMilliSecToUse)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PrerollMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PrerollMovie(
  Movie       theMovie,
  TimeValue   time,
  Fixed       Rate)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PrePrerollMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
PrePrerollMovie(
  Movie                        m,
  TimeValue                    time,
  Fixed                        rate,
  MoviePrePrerollCompleteUPP   proc,
  void *                       refcon)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AbortPrePrerollMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern void 
AbortPrePrerollMovie(
  Movie   m,
  OSErr   err)                                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  LoadMovieIntoRam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
LoadMovieIntoRam(
  Movie       theMovie,
  TimeValue   time,
  TimeValue   duration,
  long        flags)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  LoadTrackIntoRam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
LoadTrackIntoRam(
  Track       theTrack,
  TimeValue   time,
  TimeValue   duration,
  long        flags)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  LoadMediaIntoRam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
LoadMediaIntoRam(
  Media       theMedia,
  TimeValue   time,
  TimeValue   duration,
  long        flags)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieActive()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieActive(
  Movie     theMovie,
  Boolean   active)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieActive()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
GetMovieActive(Movie theMovie)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetWallClockTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTGetWallClockTimeBase(TimeBase * wallClockTimeBase)          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*************************
* Idle Management
**************************/
typedef struct OpaqueIdleManager*       IdleManager;
/*
 *  QTIdleManagerOpen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern IdleManager 
QTIdleManagerOpen(void)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerClose()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerClose(IdleManager im)                            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerGetNextIdleTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerGetNextIdleTime(
  IdleManager   im,
  TimeRecord *  nextIdle)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerSetNextIdleTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerSetNextIdleTime(
  IdleManager   im,
  TimeRecord *  nextIdle)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerSetNextIdleTimeNever()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerSetNextIdleTimeNever(IdleManager im)             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerSetNextIdleTimeNow()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerSetNextIdleTimeNow(IdleManager im)               AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerSetNextIdleTimeDelta()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerSetNextIdleTimeDelta(
  IdleManager   im,
  TimeValue     duration,
  TimeScale     scale)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerSetParent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerSetParent(
  IdleManager   im,
  IdleManager   parent)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTIdleManagerNeedsAnIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTIdleManagerNeedsAnIdle(
  IdleManager   im,
  Boolean *     needsOne)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*************************
* Carbon Movie Control
**************************/
/* Movie Control option bits*/
enum {
  kMovieControlOptionHideController = (1L << 0),
  kMovieControlOptionLocateTopLeft = (1L << 1),
  kMovieControlOptionEnableEditing = (1L << 2),
  kMovieControlOptionHandleEditingHI = (1L << 3),
  kMovieControlOptionSetKeysEnabled = (1L << 4),
  kMovieControlOptionManuallyIdled = (1L << 5)
};

/* Item tags for use in GetControlData() (some with SetControlData()) calls on Movie Controls*/
enum {
  kMovieControlDataMovieController = 'mc  ',
  kMovieControlDataMovie        = 'moov',
  kMovieControlDataManualIdling = 'manu'
};

/*
** CreateMovieControl() -   This is the public API routine that creates a Movie Control. Given a window and location
**                          plus a movie, it constructs a Movie Control with a Movie Controller in the window.
*/
/*
 *  CreateMovieControl()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
CreateMovieControl(
  WindowRef     theWindow,
  Rect *        localRect,
  Movie         theMovie,
  UInt32        options,
  ControlRef *  returnedControl)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*************************
* calls for playing movies, previews, posters
**************************/
/*
 *  StartMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
StartMovie(Movie theMovie)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  StopMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
StopMovie(Movie theMovie)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GoToBeginningOfMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GoToBeginningOfMovie(Movie theMovie)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GoToEndOfMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GoToEndOfMovie(Movie theMovie)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsMovieDone()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
IsMovieDone(Movie theMovie)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePreviewMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
GetMoviePreviewMode(Movie theMovie)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviePreviewMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePreviewMode(
  Movie     theMovie,
  Boolean   usePreview)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ShowMoviePoster()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ShowMoviePoster(Movie theMovie)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PlayMoviePreview()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
PlayMoviePreview(
  Movie                    theMovie,
  MoviePreviewCallOutUPP   callOutProc,
  long                     refcon)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* calls for controlling movies & tracks which are playing
**************************/
/*
 *  GetMovieTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeBase 
GetMovieTimeBase(Movie theMovie)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieMasterTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieMasterTimeBase(
  Movie               theMovie,
  TimeBase            tb,
  const TimeRecord *  slaveZero)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieMasterClock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieMasterClock(
  Movie               theMovie,
  Component           clockMeister,
  const TimeRecord *  slaveZero)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ChooseMovieClock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern void 
ChooseMovieClock(
  Movie   m,
  long    flags)                                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  GetMovieGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieGWorld(
  Movie       theMovie,
  CGrafPtr *  port,
  GDHandle *  gdh)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieGWorld(
  Movie      theMovie,
  CGrafPtr   port,
  GDHandle   gdh)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  movieDrawingCallWhenChanged   = 0,
  movieDrawingCallAlways        = 1
};

/*
 *  SetMovieDrawingCompleteProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieDrawingCompleteProc(
  Movie                     theMovie,
  long                      flags,
  MovieDrawingCompleteUPP   proc,
  long                      refCon)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  GetMovieNaturalBoundsRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieNaturalBoundsRect(
  Movie   theMovie,
  Rect *  naturalBounds)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetNextTrackForCompositing()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetNextTrackForCompositing(
  Movie   theMovie,
  Track   theTrack)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetPrevTrackForCompositing()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetPrevTrackForCompositing(
  Movie   theMovie,
  Track   theTrack)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackGWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackGWorld(
  Track              theTrack,
  CGrafPtr           port,
  GDHandle           gdh,
  TrackTransferUPP   proc,
  long               refCon)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePict()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern PicHandle 
GetMoviePict(
  Movie       theMovie,
  TimeValue   time)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackPict()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern PicHandle 
GetTrackPict(
  Track       theTrack,
  TimeValue   time)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePosterPict()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern PicHandle 
GetMoviePosterPict(Movie theMovie)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* called between Begin & EndUpdate */
/*
 *  UpdateMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
UpdateMovie(Movie theMovie)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InvalidateMovieRegion()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InvalidateMovieRegion(
  Movie       theMovie,
  RgnHandle   invalidRgn)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/**** spatial movie routines ****/
/*
 *  GetMovieBox()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieBox(
  Movie   theMovie,
  Rect *  boxRect)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieBox()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieBox(
  Movie         theMovie,
  const Rect *  boxRect)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** movie display clip */
/*
 *  GetMovieDisplayClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetMovieDisplayClipRgn(Movie theMovie)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieDisplayClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieDisplayClipRgn(
  Movie       theMovie,
  RgnHandle   theClip)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** movie src clip */
/*
 *  GetMovieClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetMovieClipRgn(Movie theMovie)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieClipRgn(
  Movie       theMovie,
  RgnHandle   theClip)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** track src clip */
/*
 *  GetTrackClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetTrackClipRgn(Track theTrack)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackClipRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackClipRgn(
  Track       theTrack,
  RgnHandle   theClip)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** bounds in display space (not clipped by display clip) */
/*
 *  GetMovieDisplayBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetMovieDisplayBoundsRgn(Movie theMovie)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDisplayBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetTrackDisplayBoundsRgn(Track theTrack)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** bounds in movie space */
/*
 *  GetMovieBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetMovieBoundsRgn(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackMovieBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetTrackMovieBoundsRgn(Track theTrack)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** bounds in track space */
/*
 *  GetTrackBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetTrackBoundsRgn(Track theTrack)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** mattes - always in track space */
/*
 *  GetTrackMatte()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern PixMapHandle 
GetTrackMatte(Track theTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackMatte()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackMatte(
  Track          theTrack,
  PixMapHandle   theMatte)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeMatte()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeMatte(PixMapHandle theMatte)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/** video out */
/*
 *  SetMovieVideoOutput()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern void 
SetMovieVideoOutput(
  Movie               theMovie,
  ComponentInstance   vout)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* calls for getting/saving movies
**************************/
/*
 *  NewMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
NewMovie(long flags)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutMovieIntoHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PutMovieIntoHandle(
  Movie    theMovie,
  Handle   publicMovie)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutMovieIntoDataFork()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PutMovieIntoDataFork(
  Movie   theMovie,
  short   fRefNum,
  long    offset,
  long    maxSize)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutMovieIntoDataFork64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
PutMovieIntoDataFork64(
  Movie           theMovie,
  long            fRefNum,
  const wide *    offset,
  unsigned long   maxSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutMovieIntoStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
PutMovieIntoStorage(
  Movie           theMovie,
  DataHandler     dh,
  const wide *    offset,
  unsigned long   maxSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  PutMovieForDataRefIntoHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
PutMovieForDataRefIntoHandle(
  Movie    theMovie,
  Handle   dataRef,
  OSType   dataRefType,
  Handle   publicMovie)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  DisposeMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeMovie(Movie theMovie)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Movie State Routines
**************************/
/*
 *  GetMovieCreationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetMovieCreationTime(Movie theMovie)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieModificationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetMovieModificationTime(Movie theMovie)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeScale 
GetMovieTimeScale(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieTimeScale(
  Movie       theMovie,
  TimeScale   timeScale)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetMovieDuration(Movie theMovie)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
GetMovieRate(Movie theMovie)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieRate(
  Movie   theMovie,
  Fixed   rate)                                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePreferredRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
GetMoviePreferredRate(Movie theMovie)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviePreferredRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePreferredRate(
  Movie   theMovie,
  Fixed   rate)                                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePreferredVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetMoviePreferredVolume(Movie theMovie)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviePreferredVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePreferredVolume(
  Movie   theMovie,
  short   volume)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetMovieVolume(Movie theMovie)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieVolume(
  Movie   theMovie,
  short   volume)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieMatrix(
  Movie           theMovie,
  MatrixRecord *  matrix)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieMatrix(
  Movie                 theMovie,
  const MatrixRecord *  matrix)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePreviewTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMoviePreviewTime(
  Movie        theMovie,
  TimeValue *  previewTime,
  TimeValue *  previewDuration)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviePreviewTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePreviewTime(
  Movie       theMovie,
  TimeValue   previewTime,
  TimeValue   previewDuration)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePosterTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetMoviePosterTime(Movie theMovie)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMoviePosterTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePosterTime(
  Movie       theMovie,
  TimeValue   posterTime)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieSelection(
  Movie        theMovie,
  TimeValue *  selectionTime,
  TimeValue *  selectionDuration)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieSelection(
  Movie       theMovie,
  TimeValue   selectionTime,
  TimeValue   selectionDuration)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieActiveSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieActiveSegment(
  Movie       theMovie,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieActiveSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieActiveSegment(
  Movie        theMovie,
  TimeValue *  startTime,
  TimeValue *  duration)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetMovieTime(
  Movie         theMovie,
  TimeRecord *  currentTime)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieTime(
  Movie               theMovie,
  const TimeRecord *  newtime)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieTimeValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieTimeValue(
  Movie       theMovie,
  TimeValue   newtime)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  GetMovieUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern UserData 
GetMovieUserData(Movie theMovie)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetTimeUntilNextTask()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTGetTimeUntilNextTask(
  long *  duration,
  long    scale)                                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTInstallNextTaskNeededSoonerCallback()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTInstallNextTaskNeededSoonerCallback(
  QTNextTaskNeededSoonerCallbackUPP   callbackProc,
  TimeScale                           scale,
  unsigned long                       flags,
  void *                              refcon)                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTUninstallNextTaskNeededSoonerCallback()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTUninstallNextTaskNeededSoonerCallback(
  QTNextTaskNeededSoonerCallbackUPP   callbackProc,
  void *                              refcon)                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  GetMovieRateChangeConstraints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
GetMovieRateChangeConstraints(
  Movie         theMovie,
  TimeRecord *  minimumDelay,
  TimeRecord *  maximumDelay)                                 AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*************************
* Track/Media finding routines
**************************/
/*
 *  GetMovieTrackCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMovieTrackCount(Movie theMovie)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetMovieTrack(
  Movie   theMovie,
  long    trackID)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieIndTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetMovieIndTrack(
  Movie   theMovie,
  long    index)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieIndTrackType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetMovieIndTrackType(
  Movie    theMovie,
  long     index,
  OSType   trackType,
  long     flags)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTrackID(Track theTrack)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
GetTrackMovie(Track theTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Track creation routines
**************************/
/*
 *  NewMovieTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
NewMovieTrack(
  Movie   theMovie,
  Fixed   width,
  Fixed   height,
  short   trackVolume)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeMovieTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeMovieTrack(Track theTrack)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Track State routines
**************************/
/*
 *  GetTrackCreationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetTrackCreationTime(Track theTrack)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackModificationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetTrackModificationTime(Track theTrack)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  GetTrackEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
GetTrackEnabled(Track theTrack)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackEnabled(
  Track     theTrack,
  Boolean   isEnabled)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackUsage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTrackUsage(Track theTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackUsage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackUsage(
  Track   theTrack,
  long    usage)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetTrackDuration(Track theTrack)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetTrackOffset(Track theTrack)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackOffset(
  Track       theTrack,
  TimeValue   movieOffsetTime)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackLayer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetTrackLayer(Track theTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackLayer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackLayer(
  Track   theTrack,
  short   layer)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackAlternate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetTrackAlternate(Track theTrack)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackAlternate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackAlternate(
  Track   theTrack,
  Track   alternateT)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetAutoTrackAlternatesEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetAutoTrackAlternatesEnabled(
  Movie     theMovie,
  Boolean   enable)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SelectMovieAlternates()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SelectMovieAlternates(Movie theMovie)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetTrackVolume(Track theTrack)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackVolume()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackVolume(
  Track   theTrack,
  short   volume)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetTrackMatrix(
  Track           theTrack,
  MatrixRecord *  matrix)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackMatrix(
  Track                 theTrack,
  const MatrixRecord *  matrix)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDimensions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetTrackDimensions(
  Track    theTrack,
  Fixed *  width,
  Fixed *  height)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackDimensions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackDimensions(
  Track   theTrack,
  Fixed   width,
  Fixed   height)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern UserData 
GetTrackUserData(Track theTrack)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDisplayMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetTrackDisplayMatrix(
  Track           theTrack,
  MatrixRecord *  matrix)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackSoundLocalizationSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetTrackSoundLocalizationSettings(
  Track     theTrack,
  Handle *  settings)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackSoundLocalizationSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetTrackSoundLocalizationSettings(
  Track    theTrack,
  Handle   settings)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* get Media routines
**************************/
/*
 *  NewTrackMedia()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Media 
NewTrackMedia(
  Track       theTrack,
  OSType      mediaType,
  TimeScale   timeScale,
  Handle      dataRef,
  OSType      dataRefType)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeTrackMedia()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeTrackMedia(Media theMedia)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackMedia()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Media 
GetTrackMedia(Track theTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetMediaTrack(Media theMedia)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*************************
* Media State routines
**************************/
/*
 *  GetMediaCreationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetMediaCreationTime(Media theMedia)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaModificationTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern unsigned long 
GetMediaModificationTime(Media theMedia)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeScale 
GetMediaTimeScale(Media theMedia)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMediaTimeScale(
  Media       theMedia,
  TimeScale   timeScale)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetMediaDuration(Media theMedia)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaLanguage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetMediaLanguage(Media theMedia)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaLanguage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMediaLanguage(
  Media   theMedia,
  short   language)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaQuality()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetMediaQuality(Media theMedia)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaQuality()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMediaQuality(
  Media   theMedia,
  short   quality)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaHandlerDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMediaHandlerDescription(
  Media     theMedia,
  OSType *  mediaType,
  Str255    creatorName,
  OSType *  creatorManufacturer)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern UserData 
GetMediaUserData(Media theMedia)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaInputMap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaInputMap(
  Media              theMedia,
  QTAtomContainer *  inputMap)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaInputMap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaInputMap(
  Media             theMedia,
  QTAtomContainer   inputMap)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Media Handler routines
**************************/
/*
 *  GetMediaHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern MediaHandler 
GetMediaHandler(Media theMedia)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaHandler(
  Media                   theMedia,
  MediaHandlerComponent   mH)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* Media's Data routines
**************************/
/*
 *  BeginMediaEdits()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
BeginMediaEdits(Media theMedia)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EndMediaEdits()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
EndMediaEdits(Media theMedia)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaDefaultDataRefIndex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaDefaultDataRefIndex(
  Media   theMedia,
  short   index)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDataHandlerDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMediaDataHandlerDescription(
  Media     theMedia,
  short     index,
  OSType *  dhType,
  Str255    creatorName,
  OSType *  creatorManufacturer)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern DataHandler 
GetMediaDataHandler(
  Media   theMedia,
  short   index)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaDataHandler(
  Media                  theMedia,
  short                  index,
  DataHandlerComponent   dataHandler)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetDataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Component 
GetDataHandler(
  Handle   dataRef,
  OSType   dataHandlerSubType,
  long     flags)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  OpenADataHandler()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
OpenADataHandler(
  Handle               dataRef,
  OSType               dataHandlerSubType,
  Handle               anchorDataRef,
  OSType               anchorDataRefType,
  TimeBase             tb,
  long                 flags,
  ComponentInstance *  dh)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Media Sample Table Routines
**************************/
/*
 *  GetMediaSampleDescriptionCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMediaSampleDescriptionCount(Media theMedia)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMediaSampleDescription(
  Media                     theMedia,
  long                      index,
  SampleDescriptionHandle   descH)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaSampleDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaSampleDescription(
  Media                     theMedia,
  long                      index,
  SampleDescriptionHandle   descH)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSampleCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMediaSampleCount(Media theMedia)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSyncSampleCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMediaSyncSampleCount(Media theMedia)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SampleNumToMediaTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SampleNumToMediaTime(
  Media        theMedia,
  long         logicalSampleNum,
  TimeValue *  sampleTime,
  TimeValue *  sampleDuration)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MediaTimeToSampleNum()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
MediaTimeToSampleNum(
  Media        theMedia,
  TimeValue    time,
  long *       sampleNum,
  TimeValue *  sampleTime,
  TimeValue *  sampleDuration)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  AddMediaSample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddMediaSample(
  Media                     theMedia,
  Handle                    dataIn,
  long                      inOffset,
  unsigned long             size,
  TimeValue                 durationPerSample,
  SampleDescriptionHandle   sampleDescriptionH,
  long                      numberOfSamples,
  short                     sampleFlags,
  TimeValue *               sampleTime)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddMediaSampleReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddMediaSampleReference(
  Media                     theMedia,
  long                      dataOffset,
  unsigned long             size,
  TimeValue                 durationPerSample,
  SampleDescriptionHandle   sampleDescriptionH,
  long                      numberOfSamples,
  short                     sampleFlags,
  TimeValue *               sampleTime)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddMediaSampleReferences()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddMediaSampleReferences(
  Media                     theMedia,
  SampleDescriptionHandle   sampleDescriptionH,
  long                      numberOfSamples,
  SampleReferencePtr        sampleRefs,
  TimeValue *               sampleTime)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddMediaSampleReferences64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
AddMediaSampleReferences64(
  Media                     theMedia,
  SampleDescriptionHandle   sampleDescriptionH,
  long                      numberOfSamples,
  SampleReference64Ptr      sampleRefs,
  TimeValue *               sampleTime)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaSample(
  Media                     theMedia,
  Handle                    dataOut,
  long                      maxSizeToGrow,
  long *                    size,
  TimeValue                 time,
  TimeValue *               sampleTime,
  TimeValue *               durationPerSample,
  SampleDescriptionHandle   sampleDescriptionH,
  long *                    sampleDescriptionIndex,
  long                      maxNumberOfSample,
  long *                    numberOfSamples,
  short *                   sampleFlags)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSampleReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaSampleReference(
  Media                     theMedia,
  long *                    dataOffset,
  long *                    size,
  TimeValue                 time,
  TimeValue *               sampleTime,
  TimeValue *               durationPerSample,
  SampleDescriptionHandle   sampleDescriptionH,
  long *                    sampleDescriptionIndex,
  long                      maxNumberOfSamples,
  long *                    numberOfSamples,
  short *                   sampleFlags)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSampleReferences()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaSampleReferences(
  Media                     theMedia,
  TimeValue                 time,
  TimeValue *               sampleTime,
  SampleDescriptionHandle   sampleDescriptionH,
  long *                    sampleDescriptionIndex,
  long                      maxNumberOfEntries,
  long *                    actualNumberofEntries,
  SampleReferencePtr        sampleRefs)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaSampleReferences64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
GetMediaSampleReferences64(
  Media                     theMedia,
  TimeValue                 time,
  TimeValue *               sampleTime,
  SampleDescriptionHandle   sampleDescriptionH,
  long *                    sampleDescriptionIndex,
  long                      maxNumberOfEntries,
  long *                    actualNumberofEntries,
  SampleReference64Ptr      sampleRefs)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaPreferredChunkSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaPreferredChunkSize(
  Media   theMedia,
  long    maxChunkSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaPreferredChunkSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaPreferredChunkSize(
  Media   theMedia,
  long *  maxChunkSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaShadowSync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaShadowSync(
  Media   theMedia,
  long    frameDiffSampleNum,
  long    syncSampleNum)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaShadowSync()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaShadowSync(
  Media   theMedia,
  long    frameDiffSampleNum,
  long *  syncSampleNum)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Editing Routines
**************************/
/*
 *  InsertMediaIntoTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InsertMediaIntoTrack(
  Track       theTrack,
  TimeValue   trackStart,
  TimeValue   mediaTime,
  TimeValue   mediaDuration,
  Fixed       mediaRate)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InsertTrackSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InsertTrackSegment(
  Track       srcTrack,
  Track       dstTrack,
  TimeValue   srcIn,
  TimeValue   srcDuration,
  TimeValue   dstIn)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InsertMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InsertMovieSegment(
  Movie       srcMovie,
  Movie       dstMovie,
  TimeValue   srcIn,
  TimeValue   srcDuration,
  TimeValue   dstIn)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InsertEmptyTrackSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InsertEmptyTrackSegment(
  Track       dstTrack,
  TimeValue   dstIn,
  TimeValue   dstDuration)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InsertEmptyMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InsertEmptyMovieSegment(
  Movie       dstMovie,
  TimeValue   dstIn,
  TimeValue   dstDuration)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DeleteTrackSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DeleteTrackSegment(
  Track       theTrack,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DeleteMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DeleteMovieSegment(
  Movie       theMovie,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ScaleTrackSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ScaleTrackSegment(
  Track       theTrack,
  TimeValue   startTime,
  TimeValue   oldDuration,
  TimeValue   newDuration)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ScaleMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ScaleMovieSegment(
  Movie       theMovie,
  TimeValue   startTime,
  TimeValue   oldDuration,
  TimeValue   newDuration)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* Hi-level Editing Routines
**************************/
/*
 *  CutMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
CutMovieSelection(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CopyMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
CopyMovieSelection(Movie theMovie)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PasteMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
PasteMovieSelection(
  Movie   theMovie,
  Movie   src)                                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
AddMovieSelection(
  Movie   theMovie,
  Movie   src)                                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClearMovieSelection()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ClearMovieSelection(Movie theMovie)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PasteHandleIntoMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PasteHandleIntoMovie(
  Handle              h,
  OSType              handleType,
  Movie               theMovie,
  long                flags,
  ComponentInstance   userComp)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutMovieIntoTypedHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PutMovieIntoTypedHandle(
  Movie               theMovie,
  Track               targetTrack,
  OSType              handleType,
  Handle              publicMovie,
  TimeValue           start,
  TimeValue           dur,
  long                flags,
  ComponentInstance   userComp)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  IsScrapMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Component 
IsScrapMovie(Track targetTrack)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Middle-level Editing Routines
**************************/
/*
 *  CopyTrackSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
CopyTrackSettings(
  Track   srcTrack,
  Track   dstTrack)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CopyMovieSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
CopyMovieSettings(
  Movie   srcMovie,
  Movie   dstMovie)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddEmptyTrackToMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddEmptyTrackToMovie(
  Track    srcTrack,
  Movie    dstMovie,
  Handle   dataRef,
  OSType   dataRefType,
  Track *  dstTrack)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  kQTCloneShareSamples          = 1 << 0,
  kQTCloneDontCopyEdits         = 1 << 1
};

/*
 *  AddClonedTrackToMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern OSErr 
AddClonedTrackToMovie(
  Track    srcTrack,
  Movie    dstMovie,
  long     flags,
  Track *  dstTrack)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* movie & track edit state routines
**************************/
/*
 *  NewMovieEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern MovieEditState 
NewMovieEditState(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UseMovieEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
UseMovieEditState(
  Movie            theMovie,
  MovieEditState   toState)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeMovieEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DisposeMovieEditState(MovieEditState state)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewTrackEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TrackEditState 
NewTrackEditState(Track theTrack)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UseTrackEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
UseTrackEditState(
  Track            theTrack,
  TrackEditState   state)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeTrackEditState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DisposeTrackEditState(TrackEditState state)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* track reference routines
**************************/
/*
 *  AddTrackReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddTrackReference(
  Track    theTrack,
  Track    refTrack,
  OSType   refType,
  long *   addedIndex)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DeleteTrackReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DeleteTrackReference(
  Track    theTrack,
  OSType   refType,
  long     index)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTrackReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetTrackReference(
  Track    theTrack,
  Track    refTrack,
  OSType   refType,
  long     index)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Track 
GetTrackReference(
  Track    theTrack,
  OSType   refType,
  long     index)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetNextTrackReferenceType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSType 
GetNextTrackReferenceType(
  Track    theTrack,
  OSType   refType)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackReferenceCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTrackReferenceCount(
  Track    theTrack,
  OSType   refType)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* high level file conversion routines
**************************/
/*
 *  ConvertFileToMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ConvertFileToMovieFile(
  const FSSpec *      inputFile,
  const FSSpec *      outputFile,
  OSType              creator,
  ScriptCode          scriptTag,
  short *             resID,
  long                flags,
  ComponentInstance   userComp,
  MovieProgressUPP    proc,
  long                refCon)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ConvertMovieToFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ConvertMovieToFile(
  Movie               theMovie,
  Track               onlyTrack,
  FSSpec *            outputFile,
  OSType              fileType,
  OSType              creator,
  ScriptCode          scriptTag,
  short *             resID,
  long                flags,
  ComponentInstance   userComp)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ConvertMovieToDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
ConvertMovieToDataRef(
  Movie               m,
  Track               onlyTrack,
  Handle              dataRef,
  OSType              dataRefType,
  OSType              fileType,
  OSType              creator,
  long                flags,
  ComponentInstance   userComp)                               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  ConvertDataRefToMovieDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
ConvertDataRefToMovieDataRef(
  Handle              inputDataRef,
  OSType              inputDataRefType,
  Handle              outputDataRef,
  OSType              outputDataRefType,
  OSType              creator,
  long                flags,
  ComponentInstance   userComp,
  MovieProgressUPP    proc,
  long                refCon)                                 AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


enum {
  kGetMovieImporterValidateToFind = 1L << 0,
  kGetMovieImporterAllowNewFile = 1L << 1,
  kGetMovieImporterDontConsiderGraphicsImporters = 1L << 2,
  kGetMovieImporterDontConsiderFileOnlyImporters = 1L << 6,
  kGetMovieImporterAutoImportOnly = 1L << 10 /* reject aggressive movie importers which have dontAutoFileMovieImport set*/
};

/*
 *  GetMovieImporterForDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMovieImporterForDataRef(
  OSType       dataRefType,
  Handle       dataRef,
  long         flags,
  Component *  importer)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



enum {
  kQTGetMIMETypeInfoIsQuickTimeMovieType = 'moov', /* info is a pointer to a Boolean*/
  kQTGetMIMETypeInfoIsUnhelpfulType = 'dumb' /* info is a pointer to a Boolean*/
};

/*
 *  QTGetMIMETypeInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern OSErr 
QTGetMIMETypeInfo(
  const char *  mimeStringStart,
  short         mimeStringLength,
  OSType        infoSelector,
  void *        infoDataPtr,
  long *        infoDataSize)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Movie Timebase Conversion Routines
**************************/
/*
 *  TrackTimeToMediaTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
TrackTimeToMediaTime(
  TimeValue   value,
  Track       theTrack)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackEditRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
GetTrackEditRate(
  Track       theTrack,
  TimeValue   atTime)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* Miscellaneous Routines
**************************/

/*
 *  GetMovieDataSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMovieDataSize(
  Movie       theMovie,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieDataSize64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
GetMovieDataSize64(
  Movie       theMovie,
  TimeValue   startTime,
  TimeValue   duration,
  wide *      dataSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDataSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTrackDataSize(
  Track       theTrack,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackDataSize64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
GetTrackDataSize64(
  Track       theTrack,
  TimeValue   startTime,
  TimeValue   duration,
  wide *      dataSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDataSize()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetMediaDataSize(
  Media       theMedia,
  TimeValue   startTime,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDataSize64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
GetMediaDataSize64(
  Media       theMedia,
  TimeValue   startTime,
  TimeValue   duration,
  wide *      dataSize)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PtInMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
PtInMovie(
  Movie   theMovie,
  Point   pt)                                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PtInTrack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
PtInTrack(
  Track   theTrack,
  Point   pt)                                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* Group Selection Routines
**************************/

/*
 *  SetMovieLanguage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieLanguage(
  Movie   theMovie,
  long    language)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*************************
* User Data
**************************/

/*
 *  GetUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetUserData(
  UserData   theUserData,
  Handle     data,
  OSType     udType,
  long       index)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddUserData(
  UserData   theUserData,
  Handle     data,
  OSType     udType)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
RemoveUserData(
  UserData   theUserData,
  OSType     udType,
  long       index)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CountUserDataType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
CountUserDataType(
  UserData   theUserData,
  OSType     udType)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetNextUserDataType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetNextUserDataType(
  UserData   theUserData,
  OSType     udType)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetUserDataItem()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetUserDataItem(
  UserData   theUserData,
  void *     data,
  long       size,
  OSType     udType,
  long       index)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetUserDataItem()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetUserDataItem(
  UserData   theUserData,
  void *     data,
  long       size,
  OSType     udType,
  long       index)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddUserDataText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddUserDataText(
  UserData   theUserData,
  Handle     data,
  OSType     udType,
  long       index,
  short      itlRegionTag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetUserDataText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetUserDataText(
  UserData   theUserData,
  Handle     data,
  OSType     udType,
  long       index,
  short      itlRegionTag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveUserDataText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
RemoveUserDataText(
  UserData   theUserData,
  OSType     udType,
  long       index,
  short      itlRegionTag)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewUserData(UserData * theUserData)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DisposeUserData(UserData theUserData)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewUserDataFromHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewUserDataFromHandle(
  Handle      h,
  UserData *  theUserData)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  PutUserDataIntoHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PutUserDataIntoHandle(
  UserData   theUserData,
  Handle     h)                                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



enum {
  kQTCopyUserDataReplace        = 'rplc', /* Delete all destination user data items and then add source user data items */
  kQTCopyUserDataMerge          = 'merg' /* Add source user data items to destination user data */
};

/*
 *  CopyMovieUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CopyMovieUserData(
  Movie    srcMovie,
  Movie    dstMovie,
  OSType   copyRule)                                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  CopyTrackUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CopyTrackUserData(
  Track    srcTrack,
  Track    dstTrack,
  OSType   copyRule)                                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  CopyMediaUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CopyMediaUserData(
  Media    srcMedia,
  Media    dstMedia,
  OSType   copyRule)                                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  CopyUserData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CopyUserData(
  UserData   srcUserData,
  UserData   dstUserData,
  OSType     copyRule)                                        AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  SetMoviePropertyAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
SetMoviePropertyAtom(
  Movie             theMovie,
  QTAtomContainer   propertyAtom)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMoviePropertyAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
GetMoviePropertyAtom(
  Movie              theMovie,
  QTAtomContainer *  propertyAtom)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  GetMediaNextInterestingTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMediaNextInterestingTime(
  Media        theMedia,
  short        interestingTimeFlags,
  TimeValue    time,
  Fixed        rate,
  TimeValue *  interestingTime,
  TimeValue *  interestingDuration)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackNextInterestingTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetTrackNextInterestingTime(
  Track        theTrack,
  short        interestingTimeFlags,
  TimeValue    time,
  Fixed        rate,
  TimeValue *  interestingTime,
  TimeValue *  interestingDuration)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieNextInterestingTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMovieNextInterestingTime(
  Movie           theMovie,
  short           interestingTimeFlags,
  short           numMediaTypes,
  const OSType *  whichMediaTypes,
  TimeValue       time,
  Fixed           rate,
  TimeValue *     interestingTime,
  TimeValue *     interestingDuration)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  CreateMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
CreateMovieFile(
  const FSSpec *  fileSpec,
  OSType          creator,
  ScriptCode      scriptTag,
  long            createMovieFileFlags,
  short *         resRefNum,
  Movie *         newmovie)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  OpenMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
OpenMovieFile(
  const FSSpec *  fileSpec,
  short *         resRefNum,
  SInt8           permission)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CloseMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
CloseMovieFile(short resRefNum)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DeleteMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
DeleteMovieFile(const FSSpec * fileSpec)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewMovieFromFile(
  Movie *     theMovie,
  short       resRefNum,
  short *     resId,                   /* can be NULL */
  StringPtr   resName,
  short       newMovieFlags,
  Boolean *   dataRefWasChanged)       /* can be NULL */      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewMovieFromHandle(
  Movie *    theMovie,
  Handle     h,
  short      newMovieFlags,
  Boolean *  dataRefWasChanged)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromDataFork()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewMovieFromDataFork(
  Movie *    theMovie,
  short      fRefNum,
  long       fileOffset,
  short      newMovieFlags,
  Boolean *  dataRefWasChanged)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromDataFork64()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
NewMovieFromDataFork64(
  Movie *       theMovie,
  long          fRefNum,
  const wide *  fileOffset,
  short         newMovieFlags,
  Boolean *     dataRefWasChanged)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromUserProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewMovieFromUserProc(
  Movie *       m,
  short         flags,
  Boolean *     dataRefWasChanged,
  GetMovieUPP   getProc,
  void *        refCon,
  Handle        defaultDataRef,
  OSType        dataRefType)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewMovieFromDataRef(
  Movie *  m,
  short    flags,
  short *  id,
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromStorageOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
NewMovieFromStorageOffset(
  Movie *       theMovie,
  DataHandler   dh,
  const wide *  fileOffset,
  short         newMovieFlags,
  Boolean *     dataRefWasChanged)                            AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  NewMovieForDataRefFromHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
NewMovieForDataRefFromHandle(
  Movie *    theMovie,
  Handle     h,
  short      newMovieFlags,
  Boolean *  dataRefWasChanged,
  Handle     dataRef,
  OSType     dataRefType)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  AddMovieResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddMovieResource(
  Movie              theMovie,
  short              resRefNum,
  short *            resId,
  ConstStr255Param   resName)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  UpdateMovieResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
UpdateMovieResource(
  Movie              theMovie,
  short              resRefNum,
  short              resId,
  ConstStr255Param   resName)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveMovieResource()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
RemoveMovieResource(
  short   resRefNum,
  short   resId)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CreateMovieStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CreateMovieStorage(
  Handle         dataRef,
  OSType         dataRefType,
  OSType         creator,
  ScriptCode     scriptTag,
  long           createMovieFileFlags,
  DataHandler *  outDataHandler,
  Movie *        newmovie)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  OpenMovieStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
OpenMovieStorage(
  Handle         dataRef,
  OSType         dataRefType,
  long           flags,
  DataHandler *  outDataHandler)                              AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  CloseMovieStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
CloseMovieStorage(DataHandler dh)                             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  DeleteMovieStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
DeleteMovieStorage(
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  AddMovieToStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
AddMovieToStorage(
  Movie         theMovie,
  DataHandler   dh)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  UpdateMovieInStorage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
UpdateMovieInStorage(
  Movie         theMovie,
  DataHandler   dh)                                           AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  HasMovieChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Boolean 
HasMovieChanged(Movie theMovie)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ClearMovieChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ClearMovieChanged(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieDefaultDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMovieDefaultDataRef(
  Movie    theMovie,
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieDefaultDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMovieDefaultDataRef(
  Movie     theMovie,
  Handle *  dataRef,
  OSType *  dataRefType)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieAnchorDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
SetMovieAnchorDataRef(
  Movie    theMovie,
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieAnchorDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
GetMovieAnchorDataRef(
  Movie     theMovie,
  Handle *  dataRef,
  OSType *  dataRefType,
  long *    outFlags)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieColorTable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMovieColorTable(
  Movie        theMovie,
  CTabHandle   ctab)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieColorTable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMovieColorTable(
  Movie         theMovie,
  CTabHandle *  ctab)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlattenMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
FlattenMovie(
  Movie              theMovie,
  long               movieFlattenFlags,
  const FSSpec *     theFile,
  OSType             creator,
  ScriptCode         scriptTag,
  long               createMovieFileFlags,
  short *            resId,
  ConstStr255Param   resName)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlattenMovieData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
FlattenMovieData(
  Movie           theMovie,
  long            movieFlattenFlags,
  const FSSpec *  theFile,
  OSType          creator,
  ScriptCode      scriptTag,
  long            createMovieFileFlags)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlattenMovieDataToDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern Movie 
FlattenMovieDataToDataRef(
  Movie        theMovie,
  long         movieFlattenFlags,
  Handle       dataRef,
  OSType       dataRefType,
  OSType       creator,
  ScriptCode   scriptTag,
  long         createMovieFileFlags)                          AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  SetMovieProgressProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieProgressProc(
  Movie              theMovie,
  MovieProgressUPP   p,
  long               refcon)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieProgressProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern void 
GetMovieProgressProc(
  Movie               theMovie,
  MovieProgressUPP *  p,
  long *              refcon)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CreateShortcutMovieFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
CreateShortcutMovieFile(
  const FSSpec *  fileSpec,
  OSType          creator,
  ScriptCode      scriptTag,
  long            createMovieFileFlags,
  Handle          targetDataRef,
  OSType          targetDataRefType)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieSearchText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
MovieSearchText(
  Movie        theMovie,
  Ptr          text,
  long         size,
  long         searchFlags,
  Track *      searchTrack,
  TimeValue *  searchTime,
  long *       searchOffset)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetPosterBox()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetPosterBox(
  Movie   theMovie,
  Rect *  boxRect)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetPosterBox()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetPosterBox(
  Movie         theMovie,
  const Rect *  boxRect)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieSegmentDisplayBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetMovieSegmentDisplayBoundsRgn(
  Movie       theMovie,
  TimeValue   time,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackSegmentDisplayBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
GetTrackSegmentDisplayBoundsRgn(
  Track       theTrack,
  TimeValue   time,
  TimeValue   duration)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMovieCoverProcs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMovieCoverProcs(
  Movie              theMovie,
  MovieRgnCoverUPP   uncoverProc,
  MovieRgnCoverUPP   coverProc,
  long               refcon)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieCoverProcs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMovieCoverProcs(
  Movie               theMovie,
  MovieRgnCoverUPP *  uncoverProc,
  MovieRgnCoverUPP *  coverProc,
  long *              refcon)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackStatus()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
GetTrackStatus(Track theTrack)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMovieStatus()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
GetMovieStatus(
  Movie    theMovie,
  Track *  firstProblemTrack)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  kMovieLoadStateError          = -1L,
  kMovieLoadStateLoading        = 1000,
  kMovieLoadStateLoaded         = 2000,
  kMovieLoadStatePlayable       = 10000,
  kMovieLoadStatePlaythroughOK  = 20000,
  kMovieLoadStateComplete       = 100000L
};

/*
 *  GetMovieLoadState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern long 
GetMovieLoadState(Movie theMovie)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/****
    Thread related Movie routines
****/
/*
 *  AttachMovieToCurrentThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
AttachMovieToCurrentThread(Movie m)                           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  DetachMovieFromCurrentThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
DetachMovieFromCurrentThread(Movie m)                         AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  GetMovieThreadAttachState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
GetMovieThreadAttachState(
  Movie      m,
  Boolean *  outAttachedToCurrentThread,
  Boolean *  outAttachedToAnyThread)                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/****
    CanQuickTimeOpenFile, etc.
****/
/* Input flags for CanQuickTimeOpenFile/DataRef */
enum {
  kQTDontUseDataToFindImporter  = 1L << 0,
  kQTDontLookForMovieImporterIfGraphicsImporterFound = 1L << 1,
  kQTAllowOpeningStillImagesAsMovies = 1L << 2,
  kQTAllowImportersThatWouldCreateNewFile = 1L << 3,
  kQTAllowAggressiveImporters   = 1L << 4 /* eg, TEXT and PICT movie importers*/
};

/* Determines whether the file could be opened using a graphics importer or opened in place as a movie. */
/*
 *  CanQuickTimeOpenFile()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern OSErr 
CanQuickTimeOpenFile(
  FSSpecPtr   fileSpec,
  OSType      fileType,
  OSType      fileNameExtension,
  Boolean *   outCanOpenWithGraphicsImporter,
  Boolean *   outCanOpenAsMovie,
  Boolean *   outPreferGraphicsImporter,
  UInt32      inFlags)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* Determines whether the file could be opened using a graphics importer or opened in place as a movie. */
/*
 *  CanQuickTimeOpenDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern OSErr 
CanQuickTimeOpenDataRef(
  Handle     dataRef,
  OSType     dataRefType,
  Boolean *  outCanOpenWithGraphicsImporter,
  Boolean *  outCanOpenAsMovie,
  Boolean *  outPreferGraphicsImporter,
  UInt32     inFlags)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/****
    Data Reference Utilities
****/
enum {
  kQTNativeDefaultPathStyle     = -1,
  kQTPOSIXPathStyle             = 0,
  kQTHFSPathStyle               = 1,
  kQTWindowsPathStyle           = 2
};

typedef unsigned long                   QTPathStyle;
/*
 *  QTNewDataReferenceFromFSRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromFSRef(
  const FSRef *  fileRef,
  UInt32         flags,
  Handle *       outDataRef,
  OSType *       outDataRefType)                              AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceFromFSRefCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromFSRefCFString(
  const FSRef *  directoryRef,
  CFStringRef    fileName,
  UInt32         flags,
  Handle *       outDataRef,
  OSType *       outDataRefType)                              AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceFromFSSpec()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromFSSpec(
  const FSSpec *  fsspec,
  UInt32          flags,
  Handle *        outDataRef,
  OSType *        outDataRefType)                             AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceWithDirectoryCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceWithDirectoryCFString(
  Handle        inDataRef,
  OSType        inDataRefType,
  CFStringRef   targetName,
  UInt32        flags,
  Handle *      outDataRef,
  OSType *      outDataRefType)                               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceFromFullPathCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromFullPathCFString(
  CFStringRef   filePath,
  QTPathStyle   pathStyle,
  UInt32        flags,
  Handle *      outDataRef,
  OSType *      outDataRefType)                               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceFromCFURL()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromCFURL(
  CFURLRef   url,
  UInt32     flags,
  Handle *   outDataRef,
  OSType *   outDataRefType)                                  AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTNewDataReferenceFromURLCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTNewDataReferenceFromURLCFString(
  CFStringRef   urlString,
  UInt32        flags,
  Handle *      outDataRef,
  OSType *      outDataRefType)                               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



/*
 *  QTGetDataReferenceDirectoryDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataReferenceDirectoryDataReference(
  Handle    dataRef,
  OSType    dataRefType,
  UInt32    flags,
  Handle *  outDataRef,
  OSType *  outDataRefType)                                   AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTGetDataReferenceTargetNameCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataReferenceTargetNameCFString(
  Handle         dataRef,
  OSType         dataRefType,
  CFStringRef *  name)                                        AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTGetDataReferenceFullPathCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataReferenceFullPathCFString(
  Handle         dataRef,
  OSType         dataRefType,
  QTPathStyle    style,
  CFStringRef *  outPath)                                     AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



/*
 *  QTGetDataHandlerDirectoryDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataHandlerDirectoryDataReference(
  DataHandler   dh,
  UInt32        flags,
  Handle *      outDataRef,
  OSType *      outDataRefType)                               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTGetDataHandlerTargetNameCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataHandlerTargetNameCFString(
  DataHandler    dh,
  CFStringRef *  fileName)                                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTGetDataHandlerFullPathCFString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetDataHandlerFullPathCFString(
  DataHandler    dh,
  QTPathStyle    style,
  CFStringRef *  outPath)                                     AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;




/****
    Movie Controller support routines
****/
/*
 *  NewMovieController()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentInstance 
NewMovieController(
  Movie         theMovie,
  const Rect *  movieRect,
  long          someFlags)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeMovieController()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeMovieController(ComponentInstance mc)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ShowMovieInformation()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ShowMovieInformation(
  Movie            theMovie,
  ModalFilterUPP   filterProc,
  long             refCon)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*****
    Scrap routines
*****/
/*
 *  PutMovieOnScrap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
PutMovieOnScrap(
  Movie   theMovie,
  long    movieScrapFlags)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewMovieFromScrap()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
NewMovieFromScrap(long newMovieFlags)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*****
    DataRef routines
*****/

/*
 *  GetMediaDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaDataRef(
  Media     theMedia,
  short     index,
  Handle *  dataRef,
  OSType *  dataRefType,
  long *    dataRefAttributes)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaDataRef(
  Media    theMedia,
  short    index,
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaDataRefAttributes()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaDataRefAttributes(
  Media   theMedia,
  short   index,
  long    dataRefAttributes)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddMediaDataRef()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddMediaDataRef(
  Media    theMedia,
  short *  index,
  Handle   dataRef,
  OSType   dataRefType)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaDataRefCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaDataRefCount(
  Media    theMedia,
  short *  count)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTNewAlias()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTNewAlias(
  const FSSpec *  fss,
  AliasHandle *   alias,
  Boolean         minimal)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Playback hint routines
*****/
/*
 *  SetMoviePlayHints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMoviePlayHints(
  Movie   theMovie,
  long    flags,
  long    flagsMask)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaPlayHints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetMediaPlayHints(
  Media   theMedia,
  long    flags,
  long    flagsMask)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaPlayHints()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetMediaPlayHints(
  Media   theMedia,
  long *  flags)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Load time track hints
*****/
enum {
  preloadAlways                 = 1L << 0,
  preloadOnlyIfEnabled          = 1L << 1
};

/*
 *  SetTrackLoadSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTrackLoadSettings(
  Track       theTrack,
  TimeValue   preloadTime,
  TimeValue   preloadDuration,
  long        preloadFlags,
  long        defaultHints)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTrackLoadSettings()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
GetTrackLoadSettings(
  Track        theTrack,
  TimeValue *  preloadTime,
  TimeValue *  preloadDuration,
  long *       preloadFlags,
  long *       defaultHints)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Big screen TV
*****/
enum {
  fullScreenHideCursor          = 1L << 0,
  fullScreenAllowEvents         = 1L << 1,
  fullScreenDontChangeMenuBar   = 1L << 2,
  fullScreenPreflightSize       = 1L << 3,
  fullScreenDontSwitchMonitorResolution = 1L << 4,
  fullScreenCaptureDisplay      = 1 << 5L, /* capturedisplay is a mac os x specific parameter */
  fullScreenCaptureAllDisplays  = 1 << 6L /* capturealldisplays is a mac os x specific parameter */
};

/*
 *  BeginFullScreen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
BeginFullScreen(
  Ptr *        restoreState,
  GDHandle     whichGD,
  short *      desiredWidth,
  short *      desiredHeight,
  WindowRef *  newWindow,
  RGBColor *   eraseColor,
  long         flags)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  EndFullScreen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
EndFullScreen(
  Ptr    fullState,
  long   flags)                                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Wired Actions
*****/
/* flags for MovieExecuteWiredActions*/
enum {
  movieExecuteWiredActionDontExecute = 1L << 0
};

/*
 *  AddMovieExecuteWiredActionsProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
AddMovieExecuteWiredActionsProc(
  Movie                         theMovie,
  MovieExecuteWiredActionsUPP   proc,
  void *                        refCon)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveMovieExecuteWiredActionsProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
RemoveMovieExecuteWiredActionsProc(
  Movie                         theMovie,
  MovieExecuteWiredActionsUPP   proc,
  void *                        refCon)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieExecuteWiredActions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
MovieExecuteWiredActions(
  Movie             theMovie,
  long              flags,
  QTAtomContainer   actions)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Keyboard Navigation/Editable Text Field Support
*****/
/*
   Navigation Direction Constants
        for MediaNavigateTargetRefCon
*/
enum {
  kRefConNavigationNext         = 0,
  kRefConNavigationPrevious     = 1
};

/*
   Refcon Properties 
        for MediaRefConGetProerty/MediaRefConSetProperty
*/
enum {
  kRefConPropertyCanHaveFocus   = 1,    /* Boolean */
  kRefConPropertyHasFocus       = 2     /* Boolean */
};

/* media properties*/
enum {
  kTrackFocusCanEditFlag        = 'kedt',
  kTrackDefaultFocusFlags       = 'kfoc',
  kTrackFocusDefaultRefcon      = 'kref'
};

/* focus flags*/
enum {
  kTrackFocusOn                 = 1,
  kTrackHandlesTabs             = 2     /* this is reserved for a future release*/
};

/*****
    Flash track properties
*****/
enum {
  kFlashTrackPropertyAcceptAllClicks = 'clik' /* type of media property atom; data is a Boolean */
};

/*****
    Sprite Toolbox
*****/
enum {
  kBackgroundSpriteLayerNum     = 32767
};


/*  Sprite Properties*/
enum {
  kSpritePropertyMatrix         = 1,
  kSpritePropertyImageDescription = 2,
  kSpritePropertyImageDataPtr   = 3,
  kSpritePropertyVisible        = 4,
  kSpritePropertyLayer          = 5,
  kSpritePropertyGraphicsMode   = 6,
  kSpritePropertyImageDataSize  = 7,
  kSpritePropertyActionHandlingSpriteID = 8,
  kSpritePropertyCanBeHitTested = 9,
  kSpritePropertyImageIndex     = 100,
  kSpriteTrackPropertyBackgroundColor = 101,
  kSpriteTrackPropertyOffscreenBitDepth = 102,
  kSpriteTrackPropertySampleFormat = 103,
  kSpriteTrackPropertyScaleSpritesToScaleWorld = 104,
  kSpriteTrackPropertyHasActions = 105,
  kSpriteTrackPropertyVisible   = 106,
  kSpriteTrackPropertyQTIdleEventsFrequency = 107,
  kSpriteTrackPropertyAllSpritesHitTestingMode = 108,
  kSpriteTrackPropertyPreferredDepthInterpretationMode = 109,
  kSpriteImagePropertyRegistrationPoint = 1000,
  kSpriteImagePropertyGroupID   = 1001
};

/* values for kSpriteTrackPropertyPreferredDepthInterpretationMode*/
enum {
  kSpriteTrackPreferredDepthCompatibilityMode = 0,
  kSpriteTrackPreferredDepthModernMode = 1
};

/* values for kSpriteTrackPropertyAllSpritesHitTestingMode*/
enum {
  kSpriteHitTestUseSpritesOwnPropertiesMode = 0,
  kSpriteHitTestTreatAllSpritesAsHitTestableMode = 1,
  kSpriteHitTestTreatAllSpritesAsNotHitTestableMode = 2
};

/* special value for kSpriteTrackPropertyQTIdleEventsFrequency (the default)*/
enum {
  kNoQTIdleEvents               = -1
};

/* GetSpriteProperties for accessing invalid SpriteWorldRegion*/
enum {
  kGetSpriteWorldInvalidRegionAndLeaveIntact = -1L,
  kGetSpriteWorldInvalidRegionAndThenSetEmpty = -2L
};

/* flagsIn for SpriteWorldIdle*/
enum {
  kOnlyDrawToSpriteWorld        = 1L << 0,
  kSpriteWorldPreflight         = 1L << 1
};

/* flagsOut for SpriteWorldIdle*/
enum {
  kSpriteWorldDidDraw           = 1L << 0,
  kSpriteWorldNeedsToDraw       = 1L << 1
};

/* flags for sprite track sample format*/
enum {
  kKeyFrameAndSingleOverride    = 1L << 1,
  kKeyFrameAndAllOverrides      = 1L << 2
};

/* sprite world flags*/
enum {
  kScaleSpritesToScaleWorld     = 1L << 1,
  kSpriteWorldHighQuality       = 1L << 2,
  kSpriteWorldDontAutoInvalidate = 1L << 3,
  kSpriteWorldInvisible         = 1L << 4,
  kSpriteWorldDirtyInsteadOfFlush = 1L << 5
};

/*
 *  NewSpriteWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewSpriteWorld(
  SpriteWorld *  newSpriteWorld,
  GWorldPtr      destination,
  GWorldPtr      spriteLayer,
  RGBColor *     backgroundColor,
  GWorldPtr      background)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeSpriteWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeSpriteWorld(SpriteWorld theSpriteWorld)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetSpriteWorldClip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetSpriteWorldClip(
  SpriteWorld   theSpriteWorld,
  RgnHandle     clipRgn)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetSpriteWorldMatrix()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetSpriteWorldMatrix(
  SpriteWorld           theSpriteWorld,
  const MatrixRecord *  matrix)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetSpriteWorldGraphicsMode()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetSpriteWorldGraphicsMode(
  SpriteWorld       theSpriteWorld,
  long              mode,
  const RGBColor *  opColor)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteWorldIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SpriteWorldIdle(
  SpriteWorld   theSpriteWorld,
  long          flagsIn,
  long *        flagsOut)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InvalidateSpriteWorld()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
InvalidateSpriteWorld(
  SpriteWorld   theSpriteWorld,
  Rect *        invalidArea)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteWorldHitTest()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SpriteWorldHitTest(
  SpriteWorld   theSpriteWorld,
  long          flags,
  Point         loc,
  Sprite *      spriteHit)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteHitTest()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SpriteHitTest(
  Sprite     theSprite,
  long       flags,
  Point      loc,
  Boolean *  wasHit)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeAllSprites()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeAllSprites(SpriteWorld theSpriteWorld)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetSpriteWorldFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetSpriteWorldFlags(
  SpriteWorld   spriteWorld,
  long          flags,
  long          flagsMask)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
NewSprite(
  Sprite *                 newSprite,
  SpriteWorld              itsSpriteWorld,
  ImageDescriptionHandle   idh,
  Ptr                      imageDataPtr,
  MatrixRecord *           matrix,
  Boolean                  visible,
  short                    layer)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeSprite(Sprite theSprite)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  InvalidateSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
InvalidateSprite(Sprite theSprite)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetSpriteProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetSpriteProperty(
  Sprite   theSprite,
  long     propertyType,
  void *   propertyValue)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetSpriteProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetSpriteProperty(
  Sprite   theSprite,
  long     propertyType,
  void *   propertyValue)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    QT Atom Data Support
*****/
enum {
  kParentAtomIsContainer        = 0
};

/* create and dispose QTAtomContainer objects*/

/*
 *  QTNewAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTNewAtomContainer(QTAtomContainer * atomData)                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTDisposeAtomContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTDisposeAtomContainer(QTAtomContainer atomData)              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* locating nested atoms within QTAtomContainer container*/

/*
 *  QTGetNextChildType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTAtomType 
QTGetNextChildType(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomType        currentChildType)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTCountChildrenOfType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
QTCountChildrenOfType(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomType        childType)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTFindChildByIndex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTAtom 
QTFindChildByIndex(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomType        atomType,
  short             index,
  QTAtomID *        id)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTFindChildByID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTAtom 
QTFindChildByID(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomType        atomType,
  QTAtomID          id,
  short *           index)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTNextChildAnyType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTNextChildAnyType(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtom            currentChild,
  QTAtom *          nextChild)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* set a leaf atom's data*/
/*
 *  QTSetAtomData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTSetAtomData(
  QTAtomContainer   container,
  QTAtom            atom,
  long              dataSize,
  void *            atomData)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* extracting data*/
/*
 *  QTCopyAtomDataToHandle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTCopyAtomDataToHandle(
  QTAtomContainer   container,
  QTAtom            atom,
  Handle            targetHandle)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTCopyAtomDataToPtr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTCopyAtomDataToPtr(
  QTAtomContainer   container,
  QTAtom            atom,
  Boolean           sizeOrLessOK,
  long              size,
  void *            targetPtr,
  long *            actualSize)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetAtomTypeAndID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetAtomTypeAndID(
  QTAtomContainer   container,
  QTAtom            atom,
  QTAtomType *      atomType,
  QTAtomID *        id)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* extract a copy of an atom and all of it's children, caller disposes*/
/*
 *  QTCopyAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTCopyAtom(
  QTAtomContainer    container,
  QTAtom             atom,
  QTAtomContainer *  targetContainer)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* obtaining direct reference to atom data*/
/*
 *  QTLockContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTLockContainer(QTAtomContainer container)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetAtomDataPtr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetAtomDataPtr(
  QTAtomContainer   container,
  QTAtom            atom,
  long *            dataSize,
  Ptr *             atomData)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTUnlockContainer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTUnlockContainer(QTAtomContainer container)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
   building QTAtomContainer trees
   creates and inserts new atom at specified index, existing atoms at or after index are moved toward end of list
   used for Top-Down tree creation
*/
/*
 *  QTInsertChild()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTInsertChild(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomType        atomType,
  QTAtomID          id,
  short             index,
  long              dataSize,
  void *            data,
  QTAtom *          newAtom)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* inserts children from childrenContainer as children of parentAtom*/
/*
 *  QTInsertChildren()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTInsertChildren(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  QTAtomContainer   childrenContainer)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* destruction*/
/*
 *  QTRemoveAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTRemoveAtom(
  QTAtomContainer   container,
  QTAtom            atom)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTRemoveChildren()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTRemoveChildren(
  QTAtomContainer   container,
  QTAtom            atom)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* replacement must be same type as target*/
/*
 *  QTReplaceAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTReplaceAtom(
  QTAtomContainer   targetContainer,
  QTAtom            targetAtom,
  QTAtomContainer   replacementContainer,
  QTAtom            replacementAtom)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTSwapAtoms()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTSwapAtoms(
  QTAtomContainer   container,
  QTAtom            atom1,
  QTAtom            atom2)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTSetAtomID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTSetAtomID(
  QTAtomContainer   container,
  QTAtom            atom,
  QTAtomID          newID)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetAtomParent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern QTAtom 
QTGetAtomParent(
  QTAtomContainer   container,
  QTAtom            childAtom)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetMediaPropertyAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetMediaPropertyAtom(
  Media             theMedia,
  QTAtomContainer   propertyAtom)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMediaPropertyAtom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMediaPropertyAtom(
  Media              theMedia,
  QTAtomContainer *  propertyAtom)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Tween Support
*****/
typedef struct TweenRecord              TweenRecord;
typedef CALLBACK_API( ComponentResult , TweenerDataProcPtr )(TweenRecord *tr, void *tweenData, long tweenDataSize, long dataDescriptionSeed, Handle dataDescription, ICMCompletionProcRecordPtr asyncCompletionProc, UniversalProcPtr transferProc, void *refCon);
typedef STACK_UPP_TYPE(TweenerDataProcPtr)                      TweenerDataUPP;
struct TweenRecord {
  long                version;

  QTAtomContainer     container;
  QTAtom              tweenAtom;
  QTAtom              dataAtom;
  Fixed               percent;

  TweenerDataUPP      dataProc;

  void *              private1;
  void *              private2;
};

struct TweenV1Record {
  long                version;

  QTAtomContainer     container;
  QTAtom              tweenAtom;
  QTAtom              dataAtom;
  Fixed               percent;

  TweenerDataUPP      dataProc;

  void *              private1;
  void *              private2;

  Fract               fractPercent;
};
typedef struct TweenV1Record            TweenV1Record;
enum {
  kTweenRecordNoFlags           = 0,
  kTweenRecordIsAtInterruptTime = 0x00000001
};

struct TweenV2Record {
  long                version;

  QTAtomContainer     container;
  QTAtom              tweenAtom;
  QTAtom              dataAtom;
  Fixed               percent;

  TweenerDataUPP      dataProc;

  void *              private1;
  void *              private2;

  Fract               fractPercent;

  long                flags;
};
typedef struct TweenV2Record            TweenV2Record;
/*
 *  QTNewTween()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTNewTween(
  QTTweener *       tween,
  QTAtomContainer   container,
  QTAtom            tweenAtom,
  TimeValue         maxTime)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTDisposeTween()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTDisposeTween(QTTweener tween)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTDoTween()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTDoTween(
  QTTweener        tween,
  TimeValue        atTime,
  Handle           result,
  long *           resultSize,
  TweenerDataUPP   tweenDataProc,
  void *           tweenDataRefCon)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    QTDoTweenPtr is an interrupt-safe version of QTDoTween.  It has the following limitations:
     - not all tween types support this call (those which must allocated memory), in which case they return codecUnimpErr.
     - the QTAtomContainer used for the tween must be locked
     - the dataSize must be large enough to contain the result
     - this call is not supported for sequence tweens, use interpolation tweens instead
*/
/*
 *  QTDoTweenPtr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTDoTweenPtr(
  QTTweener   tween,
  TimeValue   atTime,
  Ptr         result,
  long        resultSize)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*****
    Sound Description Manipulations
*****/
/*
 *  AddSoundDescriptionExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddSoundDescriptionExtension(
  SoundDescriptionHandle   desc,
  Handle                   extension,
  OSType                   idType)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetSoundDescriptionExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetSoundDescriptionExtension(
  SoundDescriptionHandle   desc,
  Handle *                 extension,
  OSType                   idType)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveSoundDescriptionExtension()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
RemoveSoundDescriptionExtension(
  SoundDescriptionHandle   desc,
  OSType                   idType)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Preferences
*****/
/*
 *  GetQuickTimePreference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetQuickTimePreference(
  OSType             preferenceType,
  QTAtomContainer *  preferenceAtom)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetQuickTimePreference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
SetQuickTimePreference(
  OSType            preferenceType,
  QTAtomContainer   preferenceAtom)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Effects and dialog Support
*****/
/* atom types for entries in the effects list*/
enum {
  kEffectNameAtom               = 'name', /* name of effect */
  kEffectTypeAtom               = 'type', /* codec sub-type for effect */
  kEffectManufacturerAtom       = 'manu' /* codec manufacturer for effect */
};

struct QTParamPreviewRecord {
  long                sourceID;               /* 1 based source identifier*/
  PicHandle           sourcePicture;          /* picture for preview, must not dispose until dialog is disposed*/
};
typedef struct QTParamPreviewRecord     QTParamPreviewRecord;
typedef QTParamPreviewRecord *          QTParamPreviewPtr;
struct QTParamDialogEventRecord {
  EventRecord *       theEvent;               /* Event received by the dialog */
  DialogRef           whichDialog;            /* dialog that event was directed towards */
  short               itemHit;                /* dialog item which was hit */
};
typedef struct QTParamDialogEventRecord QTParamDialogEventRecord;
typedef QTParamDialogEventRecord *      QTParamDialogEventPtr;
struct QTParamFetchPreviewRecord {
  GWorldPtr           theWorld;               /* the world into which to draw the preview */
  Fixed               percentage;             /* frame percentage (from 0.0 - 1.0) to be drawn */
};
typedef struct QTParamFetchPreviewRecord QTParamFetchPreviewRecord;
typedef QTParamFetchPreviewRecord *     QTParamFetchPreviewPtr;

#if TARGET_API_MAC_CARBON
/* Only available on OS X */
enum {
 kEffectParentWindowCarbon = 'carb'
};
struct QTEventLoopDescriptionRecord
  {
  long                    recordSize;     /* must be == sizeof(QTEventLoopDescriptionRecord) */
  long                    windowRefKind;  /* kind of window reference */
 void *                  parentWindow;   /* parent window (for sheets) or NIL to use Carbon FrontWindow() */
    void *                  eventTarget;    /* EventTargetRef to receive kHICommandOK and kHICommandCancel */
};

typedef struct QTEventLoopDescriptionRecord QTEventLoopDescriptionRecord, *QTEventLoopDescriptionPtr;
#endif


enum {
  pdActionConfirmDialog         = 1,    /* no param*/
  pdActionSetAppleMenu          = 2,    /* param is MenuRef*/
  pdActionSetEditMenu           = 3,    /* param is MenuRef*/
  pdActionGetDialogValues       = 4,    /* param is QTAtomContainer*/
  pdActionSetPreviewUserItem    = 5,    /* param is long*/
  pdActionSetPreviewPicture     = 6,    /* param is QTParamPreviewPtr;*/
  pdActionSetColorPickerEventProc = 7,  /* param is UserEventUPP*/
  pdActionSetDialogTitle        = 8,    /* param is StringPtr */
  pdActionGetSubPanelMenu       = 9,    /* param is MenuRef* */
  pdActionActivateSubPanel      = 10,   /* param is long */
  pdActionConductStopAlert      = 11,   /* param is StringPtr */
  pdActionModelessCallback      = 12,   /* param is QTParamDialogEventPtr */
  pdActionFetchPreview          = 13,   /* param is QTParamFetchPreviewPtr */
  pdActionSetDialogSettings     = 14,   /* param is QTAtomContainer */
  pdActionGetDialogSettings     = 15,   /* param is QTAtomContainer */
  pdActionGetNextSample         = 16,   /* param is QTAtomContainer with effect sample to change - createdDialog may be NIL */
  pdActionGetPreviousSample     = 17,   /* param is QTAtomContainer with effect sample to change - createdDialog may be NIL */
  pdActionCompactSample         = 18,   /* param is QTAtomContainer with effect sample to compact, - createdDialog may be NIL */
  pdActionSetEditCallout        = 19,   /* param is QTParamPreviewCalloutPtr, can be NIL */
  pdActionSetSampleTime         = 20,   /* param is QTParamSampleTimePtr, can be NIL */
  pdActionDoEditCommand         = 21,   /* param is long with menu command (ie, mcMenuCut etc) */
  pdActionGetSubPanelMenuValue  = 22,   /* param is long and returns current sub-panel value selected by the effect */
                                        /* Action codes and typedefs used for custom controls within effects */
  pdActionCustomNewControl      = 23,   /* param is QTCustomControlNewPtr */
  pdActionCustomDisposeControl  = 24,   /* param is QTCustomControlNewPtr */
  pdActionCustomPositionControl = 25,   /* param is QTCustomControlPositionControlPtr */
  pdActionCustomShowHideControl = 26,   /* param is QTCustomControlShowHideControlPtr */
  pdActionCustomHandleEvent     = 27,   /* param is QTCustomControlHandleEventPtr */
  pdActionCustomSetFocus        = 28,   /* param is QTCustomControlSetFocusPtr */
  pdActionCustomSetEditMenu     = 29,   /* param is QTCustomControlSetEditMenuPtr */
  pdActionCustomSetPreviewPicture = 30, /* param is QTCustomControlSetPreviewPicturePtr */
  pdActionCustomSetEditCallout  = 31,   /* param is QTCustomControlSetEditCalloutPtr */
  pdActionCustomGetEnableValue  = 32,   /* param is QTCustomControlGetEnableValuePtr */
  pdActionCustomSetSampleTime   = 33,   /* param is QTCustomControlSetSampleTimePtr */
  pdActionCustomGetValue        = 34,   /* param is QTCustomControlGetValue */
  pdActionCustomDoEditCommand   = 35,   /* param is QTCustomControlDoEditCommand */
                                        /* more actions for the dialog */
  pdActionRunInEventLoop        = 36,   /* param is QTEventLoopDescriptionPtr - OS X only*/
  pdActionConvertSettingsToXML  = 37,   /* param is QTAtomContainer* inbound, Handle* outbound contains the XML - createdDialog may be NIL */
  pdActionConvertSettingsToXMLWithComments = 38, /* param is QTAtomContainer* inbound, Handle* outbound contains the XML with comments - createdDialog may be NIL */
  pdActionConvertSettingsToText = 39,   /* param is QTAtomContainer* inbound, Handle* outbound contains human readable text - createdDialog may be NIL */
  pdActionConvertXMLToSettings  = 40,   /* param is Handle* inbound, QTAtomContainer* outbound contains parameters - createdDialog may be NIL */
  pdActionSetPropertyComponent  = 41    /* param is QTParamComponentPropertyPtr */
};

/* Sample Time information */
enum {
  pdSampleTimeDisplayOptionsNone = 0x00000000
};

struct QTParamComponentPropertyRecord {
  ComponentInstance   component;              /* component to call for get/set properties*/
  OSType              defaultClass;           /* default property class if not overriden by a given parameter*/
};
typedef struct QTParamComponentPropertyRecord QTParamComponentPropertyRecord;
typedef QTParamComponentPropertyRecord * QTParamComponentPropertyPtr;
struct QTParamSampleTimeRecord {
  long                displayOptions;
  TimeRecord          sampleStartTime;
  TimeValue           sampleDuration;
  long                framesPerSecond;        /* if 0, will cause revert to seconds display*/
};
typedef struct QTParamSampleTimeRecord  QTParamSampleTimeRecord;
typedef QTParamSampleTimeRecord *       QTParamSampleTimePtr;
/* Preview change callout information */
struct QTParamPreviewCalloutRecord {
  MoviePreviewCallOutUPP  calloutProc;        /* called when user makes editing changes to dialog.  May be NIL.  You should return true from your function. */
  long                refCon;                 /* passed to the callout procedure */
};
typedef struct QTParamPreviewCalloutRecord QTParamPreviewCalloutRecord;
typedef QTParamPreviewCalloutRecord *   QTParamPreviewCalloutPtr;
enum {
  pdOptionsCollectOneValue      = 0x00000001, /* should collect a single value only*/
  pdOptionsAllowOptionalInterpolations = 0x00000002, /* non-novice interpolation options are shown */
  pdOptionsModalDialogBox       = 0x00000004, /* dialog box should be modal */
  pdOptionsEditCurrentEffectOnly = 0x00000008, /* List of effects will not be shown */
  pdOptionsHidePreview          = 0x00000010, /* Preview item will not be shown */
  pdOptionsDisplayAsSheet       = 0x00000020 /* Dialog will be used as a sheet (on platforms that support it) */
};

typedef long                            QTParameterDialogOptions;
/* ------- CUSTOM EFFECT CONTROLS*/
/*
    Effects may choose to implement custom controls to allow the user to more easily edit complex parameters
    that are ill-served by simple sliders or type in boxes.   Effects may allow a custom control for either
    a single parameter, or for a group of parameters.
    
    Parameter(s) for a custom control must still be data types defined by the standard set, or for
    complex records of data, must be defined within a group as individual parameters made up from base
    data types (for example, a point is a group containing two Fixed point numbers).  
    This is to allow applications that do not wish to use the custom control for the effect to set values themselves.
    
    Effects should be aware that these custom controls may be deployed by the application in either a dialog or
    a window, with application defined background colors or patterns, along with application defined font
    characteristics for the window.
    
    It is recommended that effects implement custom controls only when needed, and that custom controls be used
    for specific types of parameters (ie, point, rectangle, polygon, path) rather than the entire user interface
    for the effect.  Effects may choose to implement multiple custom controls which combine with standard controls
    to present the total user interface.  For effects which have very complex user interfaces not well suited for 
    inclusion within a single window, it is recommended to use kParameterImageIsPreset -- which allows the effect to
    have an external editing application for parameters which may then be set within the standard UI via the open file 
    dialog or drag and drop.  The Lens Flare effect's "Flare Type" is an example of such a preset.

    For parameters that use a custom control to control a single parameter value, a new behavior
    flag has been added (kCustomControl), and the behavior for the parameter should be kParameterItemControl.
    
    For parameters that are groups, the same flag (kCustomControl) should be used, and the behavior
    should be kParameterItemGroupDivider.  Groups with the kCustomControl bit set will be implemented
    by calling the custom control for that group -- the parameters within that group will not be processed
    in the normal manner.
    
    In both cases, the new customType and customID fields of the behavior must be filled in.  These are 
    used in order to allow your custom control to determine which parameter is being edited in the case
    where the custom control is used for the editing of multiple parameters.  These values are passed into
    the pdActionCustomNewControl call.  Since the custom control mechanism is also used by QuickTime's
    default effect dialogs, you should be prepared to pass onto the base effect any pdActionCustomNewControl
    calls for type/id pairs that you do not handle yourself.  When  pdActionCustomNewControl is called
    for controls of types handled by QuickTime, customType is kParameterAtomTypeAndID and customID is
    the ID of the parameter atom. 
*/


/*
    pdActionCustomNewControlControl is called by application to create a new custom control or set of controls
    for an effect parameter.  When pdActionCustomNewControl is called, the effect should perform any
    basic allocation it needs for storage and return the result in storage. The options parameter tells
    the control if the application wishes to support interpolated, optionally interpolated, or a single
    value parameter.
    
    Since pdActionCustomNewControlControl may be called upon your effect for other items within the
    dialog, it is recommended that your effect have an easy way to determine which controls it implements:
     a) by having storage be a pointer with an OSType at the begining to mark controls
        implemented by your code.
     - or -
     b) keeping track in your component globals those custom controls which you have created.
    
    When pdActionCustomDisposeControl is called any allocation done by the control should be disposed. In addition, 
    pdActionCustomDisposeControl is the last chance the control has to commit any user changes into the sample.
    Controls which implement type in fields typically need to commit any final user edits at this time.
*/
struct QTCustomControlNewRecord {
  void *              storage;                /* storage allocated/disposed by the control*/
  QTParameterDialogOptions  options;          /* options used to control interpolation/not*/
  QTAtomContainer     sample;                 /* sample that holds the data to be edited*/
  long                customType;             /* custom type and ID specified by effect for creation of this control*/
  long                customID;
};
typedef struct QTCustomControlNewRecord QTCustomControlNewRecord;
typedef QTCustomControlNewRecord *      QTCustomControlNewPtr;
/*
    pdActionCustomPositionControl is called by the application to position the control within a window or dialog.

    The control should determine if it will fit in the alloted area and position itself there.  It should also
    return the space taken up by the control.   Note you are free to implement controls which are variable in size depending upon
    which parameter you are editing.  You need not scale your control to the requested size.  If the area presented to your
    control is too small, set didFit to false.  You should still return in used the size you would have liked to use for
    the control.   The application will then try again with a new size.  Note that all
    controls must be able to fit within a minimum of 300 by 250 pixels.
    
    Custom controls that draw text should make note of the text font, size, and style at this time in order
    to properly display within application windows.
    
    Note that the default state for the control is hidden.  You will receive a pdActionCustomShowHideControl
    in order to enable your control.  You should not draw your control in response to pdActionCustomPositionControl.
*/
struct QTCustomControlPositionControlRecord {
  void *              storage;                /* storage for the control*/
  WindowPtr           window;                 /* window to be used by the control*/
  Rect                location;               /* location within the window the control may use*/
  Rect                used;                   /* returned by the control to indicate size it actually used*/
  Boolean             didFit;                 /* did the control fit in the specified area?*/
  Boolean             pad[3];
};
typedef struct QTCustomControlPositionControlRecord QTCustomControlPositionControlRecord;
typedef QTCustomControlPositionControlRecord * QTCustomControlPositionControlPtr;
/*
    pdActionCustomShowHideControl is called when the application wishes to enable/disable your control, or 
    completely disable drawing of the control
    
    Your control should make note of the new state (if different from the last) and perform an InvalRect()
    on your drawing area, or you may draw your control's initial state in the case of show.  You should not
    attempt to erase your control as the result of a hide -- instead call InvalRect() and allow the application
    to process the resulting event as appropriate.
*/
struct QTCustomControlShowHideControlRecord {
  void *              storage;                /* storage for the control*/
  Boolean             show;                   /* display the control?*/
  Boolean             enable;                 /* enable the control (ie, black vs gray display)*/
  Boolean             pad[2];
};
typedef struct QTCustomControlShowHideControlRecord QTCustomControlShowHideControlRecord;
typedef QTCustomControlShowHideControlRecord * QTCustomControlShowHideControlPtr;
/*
    pdActionCustomHandleEvent is called to allow your custom control to process events.
    
    Typical controls handle the following events:
        - activate - to draw your control in normal/gray mode
        - update - to draw your control
        - mouseDown - to handle clicks
        - keyDown - to handle typing when you have focus
        - idle - to perform idle drawing (if applicable)
    If your control handles the entire event, set didProcess to true.  If
    you handled the event, but other controls still need the event, set didProcess to false.
    
    If your control supports the concept of focus for the purposes of typing (such as by having
    a type-in box for the parameter) then you set the tookFocus Boolean as part of your processing
    of the event.  It is assumed that your control will draw the appropriate focus UI as a result, and
    the calling application will disable any focus drawing within the remainder of the UI.

    By default, custom controls are not given idle time.  If you need idle time, set needIdle to true
    in response to the even that causes you to need idle (typically the taking of focus, or the first draw).
    Your control will continue to be given idle events until you set needIdle to false in response to
    a nullEvent.
*/
struct QTCustomControlHandleEventRecord {
  void *              storage;                /* storage for the control*/
  EventRecord *       pEvent;                 /* event to process*/
  Boolean             didProcess;             /* did we process entire event?*/
  Boolean             tookFocus;              /* did we take focus as a result of this event (typically mouseDowns)*/
  Boolean             needIdle;               /* does this control need idle events?*/
  Boolean             didEdit;                /* did we edit the samples?*/
};
typedef struct QTCustomControlHandleEventRecord QTCustomControlHandleEventRecord;
typedef QTCustomControlHandleEventRecord * QTCustomControlHandleEventPtr;
/*
    pdActionCustomSetFocus is called in order to set or advance the current focus of the user interface, typically
    because the user has pressed the tab or shift-tab keys, or because the user clicked within the area defined by
    your control.
    
    Your control will be called with pdActionFocusFirst,  pdActionFocusLast, or pdActionFocusOff to set or clear focus on your
    control.  Your control will be called with pdActionFocusForward or pdActionFocusBackward to cycle
    focus within your control (if your control has multiple focus).  If your control does not support focus,
    or the focus request results in focus moving beyond your supported range, return pdActionFocusOff in
    the focus parameter.  Otherwise, return the focus that you set.
    
    Controls which have no focus would always set focus to be pdActionFocusOff.
    
    Controls with a single focus would set pdActionFocusFirst when requsted to set either
    pdActionFocusFirst or pdActionFocusLast, and would set pdActionFocusOff for either
    pdActionFocusForward or pdActionFocusBackward.
*/
enum {
  pdActionFocusOff              = 0,    /* no focus */
  pdActionFocusFirst            = 1,    /* focus on first element */
  pdActionFocusLast             = 2,    /* focus on last element */
  pdActionFocusForward          = 3,    /* focus on next element */
  pdActionFocusBackward         = 4     /* focus on previous element */
};

struct QTCustomControlSetFocusRecord {
  void *              storage;                /* storage for the control*/
  long                focus;                  /* focus to set, return resulting focus*/
};
typedef struct QTCustomControlSetFocusRecord QTCustomControlSetFocusRecord;
typedef QTCustomControlSetFocusRecord * QTCustomControlSetFocusPtr;
/* 
    pdActionCustomSetEditMenu will be called to inform your custom control of the location of the edit menu.
    
    If your control has editing boxes, this is useful in order to allow the user to perform cut/copy/paste operations
    when focus is on one of these boxes.
*/
struct QTCustomControlSetEditMenuRecord {
  void *              storage;                /* storage for the control*/
  MenuHandle          editMenu;               /* edit menu, or NIL*/
};
typedef struct QTCustomControlSetEditMenuRecord QTCustomControlSetEditMenuRecord;
typedef QTCustomControlSetEditMenuRecord * QTCustomControlSetEditMenuPtr;
/*
    pdActionCustomSetPreviewPicture will be called to inform your custom control of preview information that you
    may wish to use in the drawing of your user interface.  
*/
struct QTCustomControlSetPreviewPictureRecord {
  void *              storage;                /* storage for the control*/
  QTParamPreviewPtr   preview;                /* preview to set*/
};
typedef struct QTCustomControlSetPreviewPictureRecord QTCustomControlSetPreviewPictureRecord;
typedef QTCustomControlSetPreviewPictureRecord * QTCustomControlSetPreviewPicturePtr;
/*
    pdActionCustomSetEditCallout tells your control of the need by the application to be informed of
    changes to the parameter values (typically for the purposes of updating previews).
    
    If a callout is available, your custom control should call it whenever a change has been
    made to the parameter(s) that your control is editing (as a result of user actions, most typically).
    If you choose not to implement this, live dragging or updating of values will not work.
*/
struct QTCustomControlSetEditCalloutRecord {
  void *              storage;                /* storage for the control*/
  QTParamPreviewCalloutPtr  callout;          /* requested callout, or NIL to disable*/
};
typedef struct QTCustomControlSetEditCalloutRecord QTCustomControlSetEditCalloutRecord;
typedef QTCustomControlSetEditCalloutRecord * QTCustomControlSetEditCalloutPtr;
/*
    pdActionCustomGetEnableValue allows you to return a value for the purposes of enabling/disabling
    other controls.
    Most custom controls do not need to implement this call.
    
    If your control is able to control the enabling and disabling of other parameter controls (such as is done
    by standard pop up or enumerated type controls), you need to supply a value that can be use for greater than/less than
    types of comparisons.
*/
struct QTCustomControlGetEnableValueRecord {
  void *              storage;                /* storage for the control*/
  long                currentValue;           /* value to compare against for enable/disable purposes*/
};
typedef struct QTCustomControlGetEnableValueRecord QTCustomControlGetEnableValueRecord;
typedef QTCustomControlGetEnableValueRecord * QTCustomControlGetEnableValuePtr;
/*
    pdActionCustomSetSampleTime tells your control information from the application about the duration
    and start time for the sample being edited.
    
    Most controls do not need this information, but some may choose to use it in the interface
    they present the user.  However, this call need not be made by applications, so the custom
    control should be prepared to run when the sample time information is not available.
*/
struct QTCustomControlSetSampleTimeRecord {
  void *              storage;                /* storage for the control*/
  QTParamSampleTimePtr  sampleTime;           /* sample time information or NIL*/
};
typedef struct QTCustomControlSetSampleTimeRecord QTCustomControlSetSampleTimeRecord;
typedef QTCustomControlSetSampleTimeRecord * QTCustomControlSetSampleTimePtr;
/*
    pdActionCustomGetValue tells your control to store any value(s) into the specified atom container.
    
    All custom controls must implement this call
*/
struct QTCustomControlGetValueRecord {
  void *              storage;                /* storage for the control*/
  QTAtomContainer     sample;                 /* sample to store into*/
};
typedef struct QTCustomControlGetValueRecord QTCustomControlGetValueRecord;
typedef QTCustomControlGetValueRecord * QTCustomControlGetValuePtr;
/*
    pdActionCustomDoEditCommand tells your control to handle edit commands if it allow focus and type in boxes.
    
    All custom controls must implement this call if they support edit boxes
*/
struct QTCustomControlDoEditCommandRecord {
  void *              storage;                /* storage for the control*/
  long                command;                /* command to execute, return 0 here if processed*/
};
typedef struct QTCustomControlDoEditCommandRecord QTCustomControlDoEditCommandRecord;
typedef QTCustomControlDoEditCommandRecord * QTCustomControlDoEditCommandPtr;
typedef long                            QTParameterDialog;
enum {
  elOptionsIncludeNoneInList    = 0x00000001 /* "None" effect is included in list */
};

typedef long                            QTEffectListOptions;
enum {
  effectIsRealtime              = 0     /* effect can be rendered in real time */
};

/*
    QTGetEffectsListExtended is a call that provides for 
    more advanced filtering of effects to be placed into the
    effect list.  Applications can filter on:
     1) number of input sources
     2) effect major or minor class
     3) custom filtering through a callback
    The callback will be called for each effect which passes
    the other criteria for inclusion.  If the callback
    returns a true result the effect will be included in the list.
    
    Note that your filter proc may receive multiple effects from various
    manufacturers.  If you return true for multiple effects of a given type
    only the one with the higher parameter version number will be included.
    If you wish other filtering (such as effects from a given manufacturer, you
    can do this by return false for the other effects and true for those
    that you prefer.
*/
typedef CALLBACK_API( Boolean , QTEffectListFilterProcPtr )(Component effect, long effectMinSource, long effectMaxSource, OSType majorClass, OSType minorClass, void *refcon);
typedef STACK_UPP_TYPE(QTEffectListFilterProcPtr)               QTEffectListFilterUPP;
/*
 *  QTGetEffectsList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetEffectsList(
  QTAtomContainer *     returnedList,
  long                  minSources,
  long                  maxSources,
  QTEffectListOptions   getOptions)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetEffectsListExtended()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTGetEffectsListExtended(
  QTAtomContainer *       returnedList,
  long                    minSources,
  long                    maxSources,
  QTEffectListOptions     getOptions,
  OSType                  majorClass,
  OSType                  minorClass,
  QTEffectListFilterUPP   filterProc,
  void *                  filterRefCon)                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTCreateStandardParameterDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTCreateStandardParameterDialog(
  QTAtomContainer            effectList,
  QTAtomContainer            parameters,
  QTParameterDialogOptions   dialogOptions,
  QTParameterDialog *        createdDialog)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTIsStandardParameterDialogEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTIsStandardParameterDialogEvent(
  EventRecord *       pEvent,
  QTParameterDialog   createdDialog)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTDismissStandardParameterDialog()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTDismissStandardParameterDialog(QTParameterDialog createdDialog) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTStandardParameterDialogDoAction()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTStandardParameterDialogDoAction(
  QTParameterDialog   createdDialog,
  long                action,
  void *              params)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetEffectSpeed()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetEffectSpeed(
  QTAtomContainer   parameters,
  Fixed *           pFPS)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Error reporting
*****/
struct QTErrorReplacementRecord {
  long                numEntries;
  StringPtr           replacementString[1];   /* array of numEntries StringPtrs (each String is allocated separately).*/
};
typedef struct QTErrorReplacementRecord QTErrorReplacementRecord;
typedef QTErrorReplacementRecord *      QTErrorReplacementPtr;
/*
    QTAddMovieError is used to add orthogonal errors to a list of errors that will
    later be reported (at the end of an import or playback, for example).  Errors are stored
    in 'qter' resources within the component.
    
    QTAddMovieError(Movie       addTo,                          // in: movie to add error to
                    Component   adder,                          // in: component which is adding the error
                    long        errorCode,                      // in: error code being added
                    QTErrorReplacementPtr   stringReplacements);// in: list of strings to subsitute (in order) for "^1", "^2", etc
*/
/*
 *  QTAddMovieError()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTAddMovieError(
  Movie                   movieH,
  Component               c,
  long                    errorCode,
  QTErrorReplacementPtr   stringReplacements)                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*****
    Access Keys
*****/
enum {
  kAccessKeyAtomType            = 'acky'
};

enum {
  kAccessKeySystemFlag          = 1L << 0
};

/*
 *  QTGetAccessKeys()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetAccessKeys(
  Str255             accessKeyType,
  long               flags,
  QTAtomContainer *  keys)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTRegisterAccessKey()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTRegisterAccessKey(
  Str255   accessKeyType,
  long     flags,
  Handle   accessKey)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTUnregisterAccessKey()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTUnregisterAccessKey(
  Str255   accessKeyType,
  long     flags,
  Handle   accessKey)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*****
    Content Restrictions
*****/

/*
 *  QTGetMovieRestrictions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTGetMovieRestrictions(
  Movie               theMovie,
  QTRestrictionSet *  outRestrictionSet,
  UInt32 *            outSeed)                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*
 *  QTRestrictionsGetInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTRestrictionsGetInfo(
  QTRestrictionSet   inRestrictionSet,
  long *             outRestrictionClassCount,
  long *             outSeed)                                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTRestrictionsGetIndClass()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTRestrictionsGetIndClass(
  QTRestrictionSet   inRestrictionSet,
  long               inIndex,
  OSType *           outClass)                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTRestrictionsGetItem()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTRestrictionsGetItem(
  QTRestrictionSet   inRestrictionSet,
  OSType             inRestrictionClass,
  UInt32 *           outRestrictions)                         AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTGetSupportedRestrictions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTGetSupportedRestrictions(
  OSType    inRestrictionClass,
  UInt32 *  outRestrictionIDs)                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTCreateUUID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern OSErr 
QTCreateUUID(
  QTUUID *  outUUID,
  long      creationFlags)                                    AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  QTEqualUUIDs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern Boolean 
QTEqualUUIDs(
  const QTUUID *  uuid1,
  const QTUUID *  uuid2)                                      AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;




/*****
    Time table
*****/
/*
 *  MakeTrackTimeTable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
MakeTrackTimeTable(
  Track       trackH,
  long **     offsets,
  TimeValue   startTime,
  TimeValue   endTime,
  TimeValue   timeIncrement,
  short       firstDataRefIndex,
  short       lastDataRefIndex,
  long *      retdataRefSkew)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MakeMediaTimeTable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
MakeMediaTimeTable(
  Media       theMedia,
  long **     offsets,
  TimeValue   startTime,
  TimeValue   endTime,
  TimeValue   timeIncrement,
  short       firstDataRefIndex,
  short       lastDataRefIndex,
  long *      retdataRefSkew)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetMaxLoadedTimeInMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
GetMaxLoadedTimeInMovie(
  Movie        theMovie,
  TimeValue *  time)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTMovieNeedsTimeTable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTMovieNeedsTimeTable(
  Movie      theMovie,
  Boolean *  needsTimeTable)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTGetDataRefMaxFileOffset()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTGetDataRefMaxFileOffset(
  Movie    movieH,
  OSType   dataRefType,
  Handle   dataRef,
  long *   offset)                                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*****
    Bandwidth management support
*****/
enum {
  ConnectionSpeedPrefsType      = 'cspd',
  BandwidthManagementPrefsType  = 'bwmg'
};


struct ConnectionSpeedPrefsRecord {
  long                connectionSpeed;
};
typedef struct ConnectionSpeedPrefsRecord ConnectionSpeedPrefsRecord;
typedef ConnectionSpeedPrefsRecord *    ConnectionSpeedPrefsPtr;
typedef ConnectionSpeedPrefsPtr *       ConnectionSpeedPrefsHandle;
struct BandwidthManagementPrefsRecord {
  Boolean             overrideConnectionSpeedForBandwidth;
};
typedef struct BandwidthManagementPrefsRecord BandwidthManagementPrefsRecord;
typedef BandwidthManagementPrefsRecord * BandwidthManagementPrefsPtr;
typedef BandwidthManagementPrefsPtr *   BandwidthManagementPrefsHandle;
enum {
  kQTIdlePriority               = 10,
  kQTNonRealTimePriority        = 20,
  kQTRealTimeSharedPriority     = 25,
  kQTRealTimePriority           = 30
};

enum {
  kQTBandwidthNotifyNeedToStop  = 1L << 0,
  kQTBandwidthNotifyGoodToGo    = 1L << 1,
  kQTBandwidthChangeRequest     = 1L << 2,
  kQTBandwidthQueueRequest      = 1L << 3,
  kQTBandwidthScheduledRequest  = 1L << 4,
  kQTBandwidthVoluntaryRelease  = 1L << 5
};

typedef CALLBACK_API( OSErr , QTBandwidthNotificationProcPtr )(long flags, void *reserved, void *refcon);
struct QTScheduledBandwidthRecord {
  long                recordSize;             /* total number of bytes in QTScheduledBandwidthRecord*/

  long                priority;
  long                dataRate;
  CompTimeValue       startTime;              /* bandwidth usage start time*/
  CompTimeValue       duration;               /* duration of bandwidth usage (0 if unknown)*/
  CompTimeValue       prerollDuration;        /* time for negotiation before startTime (0 if unknown)*/
  TimeScale           scale;                  /* timescale of value/duration/prerollDuration fields*/
  TimeBase            base;                   /* timebase*/
};
typedef struct QTScheduledBandwidthRecord QTScheduledBandwidthRecord;
typedef QTScheduledBandwidthRecord *    QTScheduledBandwidthPtr;
typedef QTScheduledBandwidthPtr *       QTScheduledBandwidthHandle;
typedef STACK_UPP_TYPE(QTBandwidthNotificationProcPtr)          QTBandwidthNotificationUPP;
/*
 *  QTBandwidthRequest()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
QTBandwidthRequest(
  long                         priority,
  QTBandwidthNotificationUPP   callback,
  const void *                 refcon,
  QTBandwidthReference *       bwRef,
  long                         flags)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTBandwidthRequestForTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
QTBandwidthRequestForTimeBase(
  TimeBase                     tb,
  long                         priority,
  QTBandwidthNotificationUPP   callback,
  const void *                 refcon,
  QTBandwidthReference *       bwRef,
  long                         flags)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTBandwidthRelease()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern OSErr 
QTBandwidthRelease(
  QTBandwidthReference   bwRef,
  long                   flags)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTScheduledBandwidthRequest()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
QTScheduledBandwidthRequest(
  QTScheduledBandwidthPtr          scheduleRec,
  QTBandwidthNotificationUPP       notificationCallback,
  void *                           refcon,
  QTScheduledBandwidthReference *  sbwRef,
  long                             flags)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTScheduledBandwidthRelease()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
QTScheduledBandwidthRelease(
  QTScheduledBandwidthReference   sbwRef,
  long                            flags)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  NewQTCallBackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTCallBackUPP
NewQTCallBackUPP(QTCallBackProcPtr userRoutine)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewQTSyncTaskUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTSyncTaskUPP
NewQTSyncTaskUPP(QTSyncTaskProcPtr userRoutine)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieRgnCoverUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieRgnCoverUPP
NewMovieRgnCoverUPP(MovieRgnCoverProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieProgressUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieProgressUPP
NewMovieProgressUPP(MovieProgressProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieDrawingCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieDrawingCompleteUPP
NewMovieDrawingCompleteUPP(MovieDrawingCompleteProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewTrackTransferUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern TrackTransferUPP
NewTrackTransferUPP(TrackTransferProcPtr userRoutine)         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewGetMovieUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern GetMovieUPP
NewGetMovieUPP(GetMovieProcPtr userRoutine)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMoviePreviewCallOutUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MoviePreviewCallOutUPP
NewMoviePreviewCallOutUPP(MoviePreviewCallOutProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewTextMediaUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern TextMediaUPP
NewTextMediaUPP(TextMediaProcPtr userRoutine)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ActionsUPP
NewActionsUPP(ActionsProcPtr userRoutine)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewDoMCActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern DoMCActionUPP
NewDoMCActionUPP(DoMCActionProcPtr userRoutine)               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMovieExecuteWiredActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MovieExecuteWiredActionsUPP
NewMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMoviePrePrerollCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MoviePrePrerollCompleteUPP
NewMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewQTNextTaskNeededSoonerCallbackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTNextTaskNeededSoonerCallbackUPP
NewQTNextTaskNeededSoonerCallbackUPP(QTNextTaskNeededSoonerCallbackProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  NewMoviesErrorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MoviesErrorUPP
NewMoviesErrorUPP(MoviesErrorProcPtr userRoutine)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewTweenerDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern TweenerDataUPP
NewTweenerDataUPP(TweenerDataProcPtr userRoutine)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewQTEffectListFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTEffectListFilterUPP
NewQTEffectListFilterUPP(QTEffectListFilterProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  NewQTBandwidthNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTBandwidthNotificationUPP
NewQTBandwidthNotificationUPP(QTBandwidthNotificationProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeQTCallBackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTCallBackUPP(QTCallBackUPP userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeQTSyncTaskUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTSyncTaskUPP(QTSyncTaskUPP userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieRgnCoverUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieRgnCoverUPP(MovieRgnCoverUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieProgressUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieProgressUPP(MovieProgressUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieDrawingCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieDrawingCompleteUPP(MovieDrawingCompleteUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeTrackTransferUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeTrackTransferUPP(TrackTransferUPP userUPP)             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeGetMovieUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeGetMovieUPP(GetMovieUPP userUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMoviePreviewCallOutUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMoviePreviewCallOutUPP(MoviePreviewCallOutUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeTextMediaUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeTextMediaUPP(TextMediaUPP userUPP)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeActionsUPP(ActionsUPP userUPP)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeDoMCActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeDoMCActionUPP(DoMCActionUPP userUPP)                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMovieExecuteWiredActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMovieExecuteWiredActionsUPP(MovieExecuteWiredActionsUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMoviePrePrerollCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMoviePrePrerollCompleteUPP(MoviePrePrerollCompleteUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeQTNextTaskNeededSoonerCallbackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTNextTaskNeededSoonerCallbackUPP(QTNextTaskNeededSoonerCallbackUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  DisposeMoviesErrorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMoviesErrorUPP(MoviesErrorUPP userUPP)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeTweenerDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeTweenerDataUPP(TweenerDataUPP userUPP)                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeQTEffectListFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTEffectListFilterUPP(QTEffectListFilterUPP userUPP)   AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  DisposeQTBandwidthNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTBandwidthNotificationUPP(QTBandwidthNotificationUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeQTCallBackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeQTCallBackUPP(
  QTCallBack     cb,
  long           refCon,
  QTCallBackUPP  userUPP)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeQTSyncTaskUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeQTSyncTaskUPP(
  void *         task,
  QTSyncTaskUPP  userUPP)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieRgnCoverUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieRgnCoverUPP(
  Movie             theMovie,
  RgnHandle         changedRgn,
  long              refcon,
  MovieRgnCoverUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieProgressUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieProgressUPP(
  Movie             theMovie,
  short             message,
  short             whatOperation,
  Fixed             percentDone,
  long              refcon,
  MovieProgressUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieDrawingCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieDrawingCompleteUPP(
  Movie                    theMovie,
  long                     refCon,
  MovieDrawingCompleteUPP  userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeTrackTransferUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeTrackTransferUPP(
  Track             t,
  long              refCon,
  TrackTransferUPP  userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeGetMovieUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeGetMovieUPP(
  long         offset,
  long         size,
  void *       dataPtr,
  void *       refCon,
  GetMovieUPP  userUPP)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMoviePreviewCallOutUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeMoviePreviewCallOutUPP(
  long                    refcon,
  MoviePreviewCallOutUPP  userUPP)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeTextMediaUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeTextMediaUPP(
  Handle        theText,
  Movie         theMovie,
  short *       displayFlag,
  long          refcon,
  TextMediaUPP  userUPP)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeActionsUPP(
  void *            refcon,
  Track             targetTrack,
  long              targetRefCon,
  QTEventRecordPtr  theEvent,
  ActionsUPP        userUPP)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeDoMCActionUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeDoMCActionUPP(
  void *         refcon,
  short          action,
  void *         params,
  Boolean *      handled,
  DoMCActionUPP  userUPP)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMovieExecuteWiredActionsUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeMovieExecuteWiredActionsUPP(
  Movie                        theMovie,
  void *                       refcon,
  long                         flags,
  QTAtomContainer              wiredActions,
  MovieExecuteWiredActionsUPP  userUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMoviePrePrerollCompleteUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeMoviePrePrerollCompleteUPP(
  Movie                       theMovie,
  OSErr                       prerollErr,
  void *                      refcon,
  MoviePrePrerollCompleteUPP  userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeQTNextTaskNeededSoonerCallbackUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeQTNextTaskNeededSoonerCallbackUPP(
  TimeValue                          duration,
  unsigned long                      flags,
  void *                             refcon,
  QTNextTaskNeededSoonerCallbackUPP  userUPP)                 AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  InvokeMoviesErrorUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeMoviesErrorUPP(
  OSErr           theErr,
  long            refcon,
  MoviesErrorUPP  userUPP)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeTweenerDataUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern ComponentResult
InvokeTweenerDataUPP(
  TweenRecord *               tr,
  void *                      tweenData,
  long                        tweenDataSize,
  long                        dataDescriptionSeed,
  Handle                      dataDescription,
  ICMCompletionProcRecordPtr  asyncCompletionProc,
  UniversalProcPtr            transferProc,
  void *                      refCon,
  TweenerDataUPP              userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeQTEffectListFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeQTEffectListFilterUPP(
  Component              effect,
  long                   effectMinSource,
  long                   effectMaxSource,
  OSType                 majorClass,
  OSType                 minorClass,
  void *                 refcon,
  QTEffectListFilterUPP  userUPP)                             AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*
 *  InvokeQTBandwidthNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern OSErr
InvokeQTBandwidthNotificationUPP(
  long                        flags,
  void *                      reserved,
  void *                      refcon,
  QTBandwidthNotificationUPP  userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*****
    Connection Speed
*****/
enum {
  ConnectionSpeedIsValidPrefsType = 'vspd'
};

/*
 *  QTGetConnectionSpeedFromPrefs()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
QTGetConnectionSpeedFromPrefs(long * pConnectionSpeed)        AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*****
    QT International Text Atom Support
*****/
enum {
  kITextRemoveEverythingBut     = 0 << 1,
  kITextRemoveLeaveSuggestedAlternate = 1 << 1
};

enum {
  kITextAtomType                = 'itxt',
  kITextStringAtomType          = 'text'
};

/*
 *  ITextAddString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ITextAddString(
  QTAtomContainer    container,
  QTAtom             parentAtom,
  RegionCode         theRegionCode,
  ConstStr255Param   theString)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ITextRemoveString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ITextRemoveString(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  RegionCode        theRegionCode,
  long              flags)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ITextGetString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
ITextGetString(
  QTAtomContainer   container,
  QTAtom            parentAtom,
  RegionCode        requestedRegion,
  RegionCode *      foundRegion,
  StringPtr         theString)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  QTTextToNativeText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
QTTextToNativeText(
  Handle   theText,
  long     encoding,
  long     flags)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* QTParseTextHREF inContainer atoms*/
enum {
  kQTParseTextHREFText          = 'text', /* string*/
  kQTParseTextHREFBaseURL       = 'burl', /* string*/
  kQTParseTextHREFClickPoint    = 'clik', /* Point; if present, QTParseTextHREF will expand URLs to support server-side image maps*/
  kQTParseTextHREFUseAltDelim   = 'altd', /* boolean; if no kQTParseTextHREFDelimiter, delim is ':'*/
  kQTParseTextHREFDelimiter     = 'delm', /* character*/
  kQTParseTextHREFRecomposeHREF = 'rhrf' /* Boolean; if true, QTParseTextHREF returns recomposed HREF with URL expanded as appropriate*/
};

/* QTParseTextHREF outContainer atoms*/
enum {
  kQTParseTextHREFURL           = 'url ', /* string*/
  kQTParseTextHREFTarget        = 'targ', /* string*/
  kQTParseTextHREFChapter       = 'chap', /* string*/
  kQTParseTextHREFIsAutoHREF    = 'auto', /* Boolean*/
  kQTParseTextHREFIsServerMap   = 'smap', /* Boolean*/
  kQTParseTextHREFHREF          = 'href', /* string; recomposed HREF with URL expanded as appropriate, suitable for mcActionLinkToURL*/
  kQTParseTextHREFEMBEDArgs     = 'mbed' /* string; text between 'E<' and '>' to be used as new movie's embed tags*/
};

/*
 *  QTParseTextHREF()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern OSErr 
QTParseTextHREF(
  char *             href,
  SInt32             hrefLen,
  QTAtomContainer    inContainer,
  QTAtomContainer *  outContainer)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*************************
* track reference types
**************************/
enum {
  kTrackReferenceChapterList    = 'chap',
  kTrackReferenceTimeCode       = 'tmcd',
  kTrackReferenceModifier       = 'ssrc'
};

/*************************
* modifier track types
**************************/
enum {
  kTrackModifierInput           = 0x696E, /* is really 'in'*/
  kTrackModifierType            = 0x7479, /* is really 'ty'*/
  kTrackModifierReference       = 'ssrc',
  kTrackModifierObjectID        = 'obid',
  kTrackModifierInputName       = 'name'
};

enum {
  kInputMapSubInputID           = 'subi'
};

enum {
  kTrackModifierTypeMatrix      = 1,
  kTrackModifierTypeClip        = 2,
  kTrackModifierTypeGraphicsMode = 5,
  kTrackModifierTypeVolume      = 3,
  kTrackModifierTypeBalance     = 4,
  kTrackModifierTypeImage       = 'vide', /* was kTrackModifierTypeSpriteImage*/
  kTrackModifierObjectMatrix    = 6,
  kTrackModifierObjectGraphicsMode = 7,
  kTrackModifierType3d4x4Matrix = 8,
  kTrackModifierCameraData      = 9,
  kTrackModifierSoundLocalizationData = 10,
  kTrackModifierObjectImageIndex = 11,
  kTrackModifierObjectLayer     = 12,
  kTrackModifierObjectVisible   = 13,
  kTrackModifierAngleAspectCamera = 14,
  kTrackModifierPanAngle        = 'pan ',
  kTrackModifierTiltAngle       = 'tilt',
  kTrackModifierVerticalFieldOfViewAngle = 'fov ',
  kTrackModifierObjectQTEventSend = 'evnt',
  kTrackModifierObjectCanBeHitTested = 15
};

struct ModifierTrackGraphicsModeRecord {
  long                graphicsMode;
  RGBColor            opColor;
};
typedef struct ModifierTrackGraphicsModeRecord ModifierTrackGraphicsModeRecord;

/*************************
* tween track types
**************************/
enum {
  kTweenTypeShort               = 1,
  kTweenTypeLong                = 2,
  kTweenTypeFixed               = 3,
  kTweenTypePoint               = 4,
  kTweenTypeQDRect              = 5,
  kTweenTypeQDRegion            = 6,
  kTweenTypeMatrix              = 7,
  kTweenTypeRGBColor            = 8,
  kTweenTypeGraphicsModeWithRGBColor = 9,
  kTweenTypeQTFloatSingle       = 10,
  kTweenTypeQTFloatDouble       = 11,
  kTweenTypeFixedPoint          = 12,
  kTweenType3dScale             = '3sca',
  kTweenType3dTranslate         = '3tra',
  kTweenType3dRotate            = '3rot',
  kTweenType3dRotateAboutPoint  = '3rap',
  kTweenType3dRotateAboutAxis   = '3rax',
  kTweenType3dRotateAboutVector = '3rvc',
  kTweenType3dQuaternion        = '3qua',
  kTweenType3dMatrix            = '3mat',
  kTweenType3dCameraData        = '3cam',
  kTweenType3dAngleAspectCameraData = '3caa',
  kTweenType3dSoundLocalizationData = '3slc',
  kTweenTypePathToMatrixTranslation = 'gxmt',
  kTweenTypePathToMatrixRotation = 'gxpr',
  kTweenTypePathToMatrixTranslationAndRotation = 'gxmr',
  kTweenTypePathToFixedPoint    = 'gxfp',
  kTweenTypePathXtoY            = 'gxxy',
  kTweenTypePathYtoX            = 'gxyx',
  kTweenTypeAtomList            = 'atom',
  kTweenTypePolygon             = 'poly',
  kTweenTypeMultiMatrix         = 'mulm',
  kTweenTypeSpin                = 'spin',
  kTweenType3dMatrixNonLinear   = '3nlr',
  kTweenType3dVRObject          = '3vro'
};

enum {
  kTweenEntry                   = 'twen',
  kTweenData                    = 'data',
  kTweenType                    = 'twnt',
  kTweenStartOffset             = 'twst',
  kTweenDuration                = 'twdu',
  kTweenFlags                   = 'flag',
  kTweenOutputMin               = 'omin',
  kTweenOutputMax               = 'omax',
  kTweenSequenceElement         = 'seqe',
  kTween3dInitialCondition      = 'icnd',
  kTweenInterpolationID         = 'intr',
  kTweenRegionData              = 'qdrg',
  kTweenPictureData             = 'PICT',
  kListElementType              = 'type',
  kListElementDataType          = 'daty',
  kNameAtom                     = 'name',
  kInitialRotationAtom          = 'inro',
  kNonLinearTweenHeader         = 'nlth'
};

/* kTweenFlags*/
enum {
  kTweenReturnDelta             = 1L << 0
};

struct TweenSequenceEntryRecord {
  Fixed               endPercent;
  QTAtomID            tweenAtomID;
  QTAtomID            dataAtomID;
};
typedef struct TweenSequenceEntryRecord TweenSequenceEntryRecord;

#ifdef __QD3D__

struct ThreeDeeVRObjectSample {
  long            rows;  
    long            columns;
   TQ3Matrix4x4    calib1;
    TQ3Matrix4x4    calib2;
    long            reserved1;
 long            reserved2;
};

typedef struct ThreeDeeVRObjectSample ThreeDeeVRObjectSample;

struct ThreeDeeNonLinearSample {
 float           DurFromLastSample;  /* 0 to 1 */
   TQ3Matrix4x4    matrix;
};
typedef struct ThreeDeeNonLinearSample ThreeDeeNonLinearSample;

struct ThreeDeeNonLinearTweenHeaderAtom {
  long    number;
    long    dataSize;
  float   tensionFactor;  /* default is 0 */
 long    reserved1;
 long    reserved2;
};
typedef struct ThreeDeeNonLinearTweenHeaderAtom ThreeDeeNonLinearTweenHeaderAtom;


#endif




#if OLDROUTINENAMES

/*************************
* Video Media routines
**************************/

#define GetVideoMediaGraphicsMode      MediaGetGraphicsMode
#define SetVideoMediaGraphicsMode      MediaSetGraphicsMode

/* use these two routines at your own peril */
#define ResetVideoMediaStatistics      VideoMediaResetStatistics
#define GetVideoMediaStatistics           VideoMediaGetStatistics

/*************************
* Sound Media routines
**************************/

#define GetSoundMediaBalance            MediaGetSoundBalance
#define SetSoundMediaBalance           MediaSetSoundBalance

/*************************
* Text Media routines
**************************/

#define SetTextProc         TextMediaSetTextProc
#define AddTextSample      TextMediaAddTextSample
#define AddTESample          TextMediaAddTESample
#define AddHiliteSample        TextMediaAddHiliteSample
#define FindNextText       TextMediaFindNextText
#define HiliteTextSample  TextMediaHiliteTextSample
#define SetTextSampleData TextMediaSetTextSampleData
#define DrawRaw              TextMediaDrawRaw
#define RawSetup           TextMediaRawSetup
#define RawIdle               TextMediaRawIdle
#define SetTextProperty        TextMediaSetTextProperty

/*************************
* Sprite Media routines
**************************/

#define SetSpriteMediaSpriteProperty  SpriteMediaSetProperty
#define GetSpriteMediaSpriteProperty SpriteMediaGetProperty
#define HitTestSpriteMedia               SpriteMediaHitTestSprites
#define CountSpriteMediaSprites           SpriteMediaCountSprites
#define CountSpriteMediaImages          SpriteMediaCountImages
#define GetSpriteMediaIndImageDescription    SpriteMediaGetIndImageDescription
#define GetDisplayedSampleNumber      SpriteMediaGetDisplayedSampleNumber
#endif /* OLDROUTINENAMES */



/*****
    Content Restrictions
*****/
enum {
  kQTRestrictionClassSave       = 'save',
  kQTRestrictionSaveDontAddMovieResource = (1L << 0),
  kQTRestrictionSaveDontFlatten = (1L << 1),
  kQTRestrictionSaveDontExport  = (1L << 2),
  kQTRestrictionSaveDontExtract = (1L << 3), /* don't allow any form of extraction of content*/
  kQTRestrictionClassEdit       = 'edit',
  kQTRestrictionEditDontCopy    = (1L << 0), /* disable copy */
  kQTRestrictionEditDontCut     = (1L << 1), /* disable cut */
  kQTRestrictionEditDontPaste   = (1L << 2), /* disable paste */
  kQTRestrictionEditDontClear   = (1L << 3), /* disable clear*/
  kQTRestrictionEditDontModify  = (1L << 4), /* don't allow modification of content*/
  kQTRestrictionEditDontExtract = (1L << 5), /* don't allow any form of extraction of content*/
  kQTRestrictionClassPlay       = 'play',
  kQTRestrictionPlayDontPlay    = (1L << 0) /* disable playback   */
};


/*************************
* Video Media routines
**************************/


enum {
  videoFlagDontLeanAhead        = 1L << 0
};




/* use these five routines at your own peril*/
/*
 *  VideoMediaResetStatistics()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
VideoMediaResetStatistics(MediaHandler mh)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VideoMediaGetStatistics()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
VideoMediaGetStatistics(MediaHandler mh)                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  VideoMediaGetStallCount()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
VideoMediaGetStallCount(
  MediaHandler     mh,
  unsigned long *  stalls)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  VideoMediaSetCodecParameter()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
VideoMediaSetCodecParameter(
  MediaHandler   mh,
  CodecType      cType,
  OSType         parameterID,
  long           parameterChangeSeed,
  void *         dataPtr,
  long           dataSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  VideoMediaGetCodecParameter()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
VideoMediaGetCodecParameter(
  MediaHandler   mh,
  CodecType      cType,
  OSType         parameterID,
  Handle         outParameterData)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;





/*************************
* Text Media routines
**************************/



/* Return displayFlags for TextProc */
enum {
  txtProcDefaultDisplay         = 0,    /*    Use the media's default*/
  txtProcDontDisplay            = 1,    /*    Don't display the text*/
  txtProcDoDisplay              = 2     /*    Do display the text*/
};

/*
 *  TextMediaSetTextProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaSetTextProc(
  MediaHandler   mh,
  TextMediaUPP   TextProc,
  long           refcon)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaAddTextSample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaAddTextSample(
  MediaHandler    mh,
  Ptr             text,
  unsigned long   size,
  short           fontNumber,
  short           fontSize,
  Style           textFace,
  RGBColor *      textColor,
  RGBColor *      backColor,
  short           textJustification,
  Rect *          textBox,
  long            displayFlags,
  TimeValue       scrollDelay,
  short           hiliteStart,
  short           hiliteEnd,
  RGBColor *      rgbHiliteColor,
  TimeValue       duration,
  TimeValue *     sampleTime)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaAddTESample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaAddTESample(
  MediaHandler   mh,
  TEHandle       hTE,
  RGBColor *     backColor,
  short          textJustification,
  Rect *         textBox,
  long           displayFlags,
  TimeValue      scrollDelay,
  short          hiliteStart,
  short          hiliteEnd,
  RGBColor *     rgbHiliteColor,
  TimeValue      duration,
  TimeValue *    sampleTime)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaAddHiliteSample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaAddHiliteSample(
  MediaHandler   mh,
  short          hiliteStart,
  short          hiliteEnd,
  RGBColor *     rgbHiliteColor,
  TimeValue      duration,
  TimeValue *    sampleTime)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaDrawRaw()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
TextMediaDrawRaw(
  MediaHandler            mh,
  GWorldPtr               gw,
  GDHandle                gd,
  void *                  data,
  long                    dataSize,
  TextDescriptionHandle   tdh)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaSetTextProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
TextMediaSetTextProperty(
  MediaHandler   mh,
  TimeValue      atMediaTime,
  long           propertyType,
  void *         data,
  long           dataSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaRawSetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
TextMediaRawSetup(
  MediaHandler            mh,
  GWorldPtr               gw,
  GDHandle                gd,
  void *                  data,
  long                    dataSize,
  TextDescriptionHandle   tdh,
  TimeValue               sampleDuration)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaRawIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
TextMediaRawIdle(
  MediaHandler   mh,
  GWorldPtr      gw,
  GDHandle       gd,
  TimeValue      sampleTime,
  long           flagsIn,
  long *         flagsOut)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaGetTextProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
TextMediaGetTextProperty(
  MediaHandler   mh,
  TimeValue      atMediaTime,
  long           propertyType,
  void *         data,
  long           dataSize)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  findTextEdgeOK                = 1 << 0, /* Okay to find text at specified sample time*/
  findTextCaseSensitive         = 1 << 1, /* Case sensitive search*/
  findTextReverseSearch         = 1 << 2, /* Search from sampleTime backwards*/
  findTextWrapAround            = 1 << 3, /* Wrap search when beginning or end of movie is hit*/
  findTextUseOffset             = 1 << 4 /* Begin search at the given character offset into sample rather than edge*/
};

/*
 *  TextMediaFindNextText()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaFindNextText(
  MediaHandler   mh,
  Ptr            text,
  long           size,
  short          findFlags,
  TimeValue      startTime,
  TimeValue *    foundTime,
  TimeValue *    foundDuration,
  long *         offset)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  TextMediaHiliteTextSample()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaHiliteTextSample(
  MediaHandler   mh,
  TimeValue      sampleTime,
  short          hiliteStart,
  short          hiliteEnd,
  RGBColor *     rgbHiliteColor)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


enum {
  dropShadowOffsetType          = 'drpo',
  dropShadowTranslucencyType    = 'drpt'
};

/*
 *  TextMediaSetTextSampleData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
TextMediaSetTextSampleData(
  MediaHandler   mh,
  void *         data,
  OSType         dataType)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;






/*************************
* Sprite Media routines
**************************/
/* flags for sprite hit test routines */
enum {
  spriteHitTestBounds           = 1L << 0, /*    point must only be within sprite's bounding box*/
  spriteHitTestImage            = 1L << 1, /*  point must be within the shape of the sprite's image*/
  spriteHitTestInvisibleSprites = 1L << 2, /*  invisible sprites may be hit tested*/
  spriteHitTestIsClick          = 1L << 3, /*  for codecs that want mouse events*/
  spriteHitTestLocInDisplayCoordinates = 1L << 4, /*    set if you want to pass a display coordiate point to SpriteHitTest*/
  spriteHitTestTreatAllSpritesAsHitTestable = 1L << 5 /* set if you want to override each sprites hittestable property as true*/
};

/* atom types for sprite media */
enum {
  kSpriteAtomType               = 'sprt',
  kSpriteImagesContainerAtomType = 'imct',
  kSpriteImageAtomType          = 'imag',
  kSpriteImageDataAtomType      = 'imda',
  kSpriteImageDataRefAtomType   = 'imre',
  kSpriteImageDataRefTypeAtomType = 'imrt',
  kSpriteImageGroupIDAtomType   = 'imgr',
  kSpriteImageRegistrationAtomType = 'imrg',
  kSpriteImageDefaultImageIndexAtomType = 'defi',
  kSpriteSharedDataAtomType     = 'dflt',
  kSpriteNameAtomType           = 'name',
  kSpriteImageNameAtomType      = 'name',
  kSpriteUsesImageIDsAtomType   = 'uses', /* leaf data is an array of QTAtomID's, one per image used*/
  kSpriteBehaviorsAtomType      = 'beha',
  kSpriteImageBehaviorAtomType  = 'imag',
  kSpriteCursorBehaviorAtomType = 'crsr',
  kSpriteStatusStringsBehaviorAtomType = 'sstr',
  kSpriteVariablesContainerAtomType = 'vars',
  kSpriteStringVariableAtomType = 'strv',
  kSpriteFloatingPointVariableAtomType = 'flov'
};

struct QTRuntimeSpriteDescStruct {
  long                version;                /* set to zero*/
  QTAtomID            spriteID;
  short               imageIndex;
  MatrixRecord        matrix;
  short               visible;
  short               layer;
  ModifierTrackGraphicsModeRecord  graphicsMode;
  QTAtomID            actionHandlingSpriteID;
};
typedef struct QTRuntimeSpriteDescStruct QTRuntimeSpriteDescStruct;
typedef QTRuntimeSpriteDescStruct *     QTRuntimeSpriteDescPtr;
/*
   when filling in QTSpriteButtonBehaviorStruct values -1 may be used to indicate that
   the state transition does not change the property
*/
struct QTSpriteButtonBehaviorStruct {
  QTAtomID            notOverNotPressedStateID;
  QTAtomID            overNotPressedStateID;
  QTAtomID            overPressedStateID;
  QTAtomID            notOverPressedStateID;
};
typedef struct QTSpriteButtonBehaviorStruct QTSpriteButtonBehaviorStruct;
typedef QTSpriteButtonBehaviorStruct *  QTSpriteButtonBehaviorPtr;
/*
 *  SpriteMediaSetProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaSetProperty(
  MediaHandler   mh,
  short          spriteIndex,
  long           propertyType,
  void *         propertyValue)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetProperty(
  MediaHandler   mh,
  short          spriteIndex,
  long           propertyType,
  void *         propertyValue)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaHitTestSprites()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaHitTestSprites(
  MediaHandler   mh,
  long           flags,
  Point          loc,
  short *        spriteHitIndex)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaCountSprites()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaCountSprites(
  MediaHandler   mh,
  short *        numSprites)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaCountImages()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaCountImages(
  MediaHandler   mh,
  short *        numImages)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetIndImageDescription()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetIndImageDescription(
  MediaHandler             mh,
  short                    imageIndex,
  ImageDescriptionHandle   imageDescription)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetDisplayedSampleNumber()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetDisplayedSampleNumber(
  MediaHandler   mh,
  long *         sampleNum)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetSpriteName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetSpriteName(
  MediaHandler   mh,
  QTAtomID       spriteID,
  Str255         spriteName)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetImageName()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetImageName(
  MediaHandler   mh,
  short          imageIndex,
  Str255         imageName)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaSetSpriteProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaSetSpriteProperty(
  MediaHandler   mh,
  QTAtomID       spriteID,
  long           propertyType,
  void *         propertyValue)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetSpriteProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetSpriteProperty(
  MediaHandler   mh,
  QTAtomID       spriteID,
  long           propertyType,
  void *         propertyValue)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaHitTestAllSprites()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaHitTestAllSprites(
  MediaHandler   mh,
  long           flags,
  Point          loc,
  QTAtomID *     spriteHitID)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaHitTestOneSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaHitTestOneSprite(
  MediaHandler   mh,
  QTAtomID       spriteID,
  long           flags,
  Point          loc,
  Boolean *      wasHit)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaSpriteIndexToID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaSpriteIndexToID(
  MediaHandler   mh,
  short          spriteIndex,
  QTAtomID *     spriteID)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaSpriteIDToIndex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaSpriteIDToIndex(
  MediaHandler   mh,
  QTAtomID       spriteID,
  short *        spriteIndex)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetSpriteActionsForQTEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetSpriteActionsForQTEvent(
  MediaHandler       mh,
  QTEventRecordPtr   event,
  QTAtomID           spriteID,
  QTAtomContainer *  container,
  QTAtom *           atom)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaSetActionVariable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaSetActionVariable(
  MediaHandler   mh,
  QTAtomID       variableID,
  const float *  value)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetActionVariable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetActionVariable(
  MediaHandler   mh,
  QTAtomID       variableID,
  float *        value)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetIndImageProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
SpriteMediaGetIndImageProperty(
  MediaHandler   mh,
  short          imageIndex,
  long           imagePropertyType,
  void *         imagePropertyValue)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaNewSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SpriteMediaNewSprite(
  MediaHandler             mh,
  QTRuntimeSpriteDescPtr   newSpriteDesc)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaDisposeSprite()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SpriteMediaDisposeSprite(
  MediaHandler   mh,
  QTAtomID       spriteID)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaSetActionVariableToString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SpriteMediaSetActionVariableToString(
  MediaHandler   mh,
  QTAtomID       variableID,
  Ptr            theCString)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SpriteMediaGetActionVariableAsString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
SpriteMediaGetActionVariableAsString(
  MediaHandler   mh,
  QTAtomID       variableID,
  Handle *       theCString)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*
 *  SpriteMediaNewImage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SpriteMediaNewImage(
  MediaHandler   mh,
  Handle         dataRef,
  OSType         dataRefType,
  QTAtomID       desiredID)                                   AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  SpriteMediaDisposeImage()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SpriteMediaDisposeImage(
  MediaHandler   mh,
  short          imageIndex)                                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  SpriteMediaImageIndexToID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SpriteMediaImageIndexToID(
  MediaHandler   mh,
  short          imageIndex,
  QTAtomID *     imageID)                                     AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*
 *  SpriteMediaImageIDToIndex()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
SpriteMediaImageIDToIndex(
  MediaHandler   mh,
  QTAtomID       imageID,
  short *        imageIndex)                                  AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;



/*************************
* Flash Media routines
**************************/

/*
 *  FlashMediaSetPan()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaSetPan(
  MediaHandler   mh,
  short          xPercent,
  short          yPercent)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaSetZoom()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaSetZoom(
  MediaHandler   mh,
  short          factor)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaSetZoomRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaSetZoomRect(
  MediaHandler   mh,
  long           left,
  long           top,
  long           right,
  long           bottom)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaGetRefConBounds()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaGetRefConBounds(
  MediaHandler   mh,
  long           refCon,
  long *         left,
  long *         top,
  long *         right,
  long *         bottom)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaGetRefConID()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaGetRefConID(
  MediaHandler   mh,
  long           refCon,
  long *         refConID)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaIDToRefCon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaIDToRefCon(
  MediaHandler   mh,
  long           refConID,
  long *         refCon)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaGetDisplayedFrameNumber()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaGetDisplayedFrameNumber(
  MediaHandler   mh,
  long *         flashFrameNumber)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaFrameNumberToMovieTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaFrameNumberToMovieTime(
  MediaHandler   mh,
  long           flashFrameNumber,
  TimeValue *    movieTime)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaFrameLabelToMovieTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
FlashMediaFrameLabelToMovieTime(
  MediaHandler   mh,
  Ptr            theLabel,
  TimeValue *    movieTime)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaGetFlashVariable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
FlashMediaGetFlashVariable(
  MediaHandler   mh,
  char *         path,
  char *         name,
  Handle *       theVariableCStringOut)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaSetFlashVariable()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
FlashMediaSetFlashVariable(
  MediaHandler   mh,
  char *         path,
  char *         name,
  char *         value,
  Boolean        updateFocus)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaDoButtonActions()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
FlashMediaDoButtonActions(
  MediaHandler   mh,
  char *         path,
  long           buttonID,
  long           transition)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  FlashMediaGetSupportedSwfVersion()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
FlashMediaGetSupportedSwfVersion(
  MediaHandler     mh,
  unsigned char *  swfVersion)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/* sample format atoms*/
enum {
  kMovieMediaDataReference      = 'mmdr', /* data reference*/
  kMovieMediaDefaultDataReferenceID = 'ddri', /* atom id*/
  kMovieMediaSlaveTime          = 'slti', /* boolean*/
  kMovieMediaSlaveAudio         = 'slau', /* boolean*/
  kMovieMediaSlaveGraphicsMode  = 'slgr', /* boolean*/
  kMovieMediaAutoPlay           = 'play', /* boolean*/
  kMovieMediaLoop               = 'loop', /* UInt8 (0=no loop, 1=loop, 2=palindrome loop)*/
  kMovieMediaUseMIMEType        = 'mime', /* string indicating the MIME type to use for the dataref (usually not required)*/
  kMovieMediaTitle              = 'titl', /* string of the media's title (tooltips)*/
  kMovieMediaAltText            = 'altt', /* string of alternate text if media isn't loaded*/
  kMovieMediaClipBegin          = 'clpb', /* MovieMediaTimeRecord of start time of embedded media*/
  kMovieMediaClipDuration       = 'clpd', /* MovieMediaTimeRecord of duration of embedded media*/
  kMovieMediaRegionAtom         = 'regi', /* contains subatoms that describe layout*/
  kMovieMediaSlaveTrackDuration = 'sltr', /* Boolean indicating that media handler should adjust track and media based on actual embedded movie duration*/
  kMovieMediaEnableFrameStepping = 'enfs', /* boolean. if true stepping on external movie steps frames within embedded movie.*/
  kMovieMediaBackgroundColor    = 'bkcl', /* RGBColor.*/
  kMovieMediaPrerollTime        = 'prer' /* SInt32 indicating preroll time*/
};

/* fit types*/
enum {
  kMovieMediaFitNone            = 0,
  kMovieMediaFitScroll          = 'scro',
  kMovieMediaFitClipIfNecessary = 'hidd',
  kMovieMediaFitFill            = 'fill',
  kMovieMediaFitMeet            = 'meet',
  kMovieMediaFitSlice           = 'slic'
};

/* sub atoms for region atom*/
enum {
  kMovieMediaSpatialAdjustment  = 'fit ', /* OSType from kMovieMediaFit**/
  kMovieMediaRectangleAtom      = 'rect',
  kMovieMediaTop                = 'top ',
  kMovieMediaLeft               = 'left',
  kMovieMediaWidth              = 'wd  ',
  kMovieMediaHeight             = 'ht  '
};

/* contained movie properties*/
enum {
  kMoviePropertyDuration        = 'dura', /* TimeValue **/
  kMoviePropertyTimeScale       = 'tims', /* TimeValue **/
  kMoviePropertyTime            = 'timv', /* TimeValue **/
  kMoviePropertyNaturalBounds   = 'natb', /* Rect **/
  kMoviePropertyMatrix          = 'mtrx', /* Matrix **/
  kMoviePropertyTrackList       = 'tlst' /* long ****/
};


enum {
  kTrackPropertyMediaType       = 'mtyp', /* OSType*/
  kTrackPropertyInstantiation   = 'inst' /* MovieMediaInstantiationInfoRecord*/
};

struct MovieMediaTimeRecord {
  wide                time;
  TimeScale           scale;
};
typedef struct MovieMediaTimeRecord     MovieMediaTimeRecord;
struct MovieMediaInstantiationInfoRecord {
  Boolean             immediately;
  Boolean             pad;
  SInt32              bitRate;
};
typedef struct MovieMediaInstantiationInfoRecord MovieMediaInstantiationInfoRecord;
/*************************
* Movie Media routines
**************************/


/*
 *  MovieMediaGetChildDoMCActionCallback()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaGetChildDoMCActionCallback(
  MediaHandler     mh,
  DoMCActionUPP *  doMCActionCallbackProc,
  long *           refcon)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaGetDoMCActionCallback()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaGetDoMCActionCallback(
  MediaHandler     mh,
  DoMCActionUPP *  doMCActionCallbackProc,
  long *           refcon)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaGetCurrentMovieProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaGetCurrentMovieProperty(
  MediaHandler   mh,
  OSType         whichProperty,
  void *         value)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaGetCurrentTrackProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaGetCurrentTrackProperty(
  MediaHandler   mh,
  long           trackID,
  OSType         whichProperty,
  void *         value)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaGetChildMovieDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaGetChildMovieDataReference(
  MediaHandler   mh,
  QTAtomID       dataRefID,
  short          dataRefIndex,
  OSType *       dataRefType,
  Handle *       dataRef,
  QTAtomID *     dataRefIDOut,
  short *        dataRefIndexOut)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaSetChildMovieDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaSetChildMovieDataReference(
  MediaHandler   mh,
  QTAtomID       dataRefID,
  OSType         dataRefType,
  Handle         dataRef)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MovieMediaLoadChildMovieFromDataReference()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
MovieMediaLoadChildMovieFromDataReference(
  MediaHandler   mh,
  QTAtomID       dataRefID)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*************************
* 3D Media routines
**************************/
/*
 *  Media3DGetNamedObjectList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
Media3DGetNamedObjectList(
  MediaHandler       mh,
  QTAtomContainer *  objectList)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetRendererList()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
Media3DGetRendererList(
  MediaHandler       mh,
  QTAtomContainer *  rendererList)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetCurrentGroup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DGetCurrentGroup(
  MediaHandler   mh,
  void *         group)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DTranslateNamedObjectTo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DTranslateNamedObjectTo(
  MediaHandler   mh,
  char *         objectName,
  Fixed          x,
  Fixed          y,
  Fixed          z)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DScaleNamedObjectTo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DScaleNamedObjectTo(
  MediaHandler   mh,
  char *         objectName,
  Fixed          xScale,
  Fixed          yScale,
  Fixed          zScale)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DRotateNamedObjectTo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DRotateNamedObjectTo(
  MediaHandler   mh,
  char *         objectName,
  Fixed          xDegrees,
  Fixed          yDegrees,
  Fixed          zDegrees)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DSetCameraData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DSetCameraData(
  MediaHandler   mh,
  void *         cameraData)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetCameraData()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DGetCameraData(
  MediaHandler   mh,
  void *         cameraData)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DSetCameraAngleAspect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DSetCameraAngleAspect(
  MediaHandler    mh,
  QTFloatSingle   fov,
  QTFloatSingle   aspectRatioXToY)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetCameraAngleAspect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DGetCameraAngleAspect(
  MediaHandler     mh,
  QTFloatSingle *  fov,
  QTFloatSingle *  aspectRatioXToY)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  Media3DSetCameraRange()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DSetCameraRange(
  MediaHandler   mh,
  void *         tQ3CameraRange)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetCameraRange()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
Media3DGetCameraRange(
  MediaHandler   mh,
  void *         tQ3CameraRange)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  Media3DGetViewObject()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.1 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.1 and later
 *    Windows:          in qtmlClient.lib 4.1 and later
 */
extern ComponentResult 
Media3DGetViewObject(
  MediaHandler   mh,
  void *         tq3viewObject)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/****************************************
*                                       *
*   M O V I E   C O N T R O L L E R     *
*                                       *
****************************************/
enum {
  MovieControllerComponentType  = 'play'
};


enum {
  kMovieControllerQTVRFlag      = 1 << 0,
  kMovieControllerDontDisplayToUser = 1 << 1
};


typedef ComponentInstance               MovieController;
typedef MovieController *               MovieControllerPtr;
enum {
  mcActionIdle                  = 1,    /* no param*/
  mcActionDraw                  = 2,    /* param is WindowRef*/
  mcActionActivate              = 3,    /* no param*/
  mcActionDeactivate            = 4,    /* no param*/
  mcActionMouseDown             = 5,    /* param is pointer to EventRecord*/
  mcActionKey                   = 6,    /* param is pointer to EventRecord*/
  mcActionPlay                  = 8,    /* param is Fixed, play rate*/
  mcActionGoToTime              = 12,   /* param is TimeRecord*/
  mcActionSetVolume             = 14,   /* param is a short*/
  mcActionGetVolume             = 15,   /* param is pointer to a short*/
  mcActionStep                  = 18,   /* param is number of steps (short)*/
  mcActionSetLooping            = 21,   /* param is Boolean*/
  mcActionGetLooping            = 22,   /* param is pointer to a Boolean*/
  mcActionSetLoopIsPalindrome   = 23,   /* param is Boolean*/
  mcActionGetLoopIsPalindrome   = 24,   /* param is pointer to a Boolean*/
  mcActionSetGrowBoxBounds      = 25,   /* param is a Rect*/
  mcActionControllerSizeChanged = 26,   /* no param*/
  mcActionSetSelectionBegin     = 29,   /* param is TimeRecord*/
  mcActionSetSelectionDuration  = 30,   /* param is TimeRecord, action only taken on set-duration*/
  mcActionSetKeysEnabled        = 32,   /* param is Boolean*/
  mcActionGetKeysEnabled        = 33,   /* param is pointer to Boolean*/
  mcActionSetPlaySelection      = 34,   /* param is Boolean*/
  mcActionGetPlaySelection      = 35,   /* param is pointer to Boolean*/
  mcActionSetUseBadge           = 36,   /* param is Boolean*/
  mcActionGetUseBadge           = 37,   /* param is pointer to Boolean*/
  mcActionSetFlags              = 38,   /* param is long of flags*/
  mcActionGetFlags              = 39,   /* param is pointer to a long of flags*/
  mcActionSetPlayEveryFrame     = 40,   /* param is Boolean*/
  mcActionGetPlayEveryFrame     = 41,   /* param is pointer to Boolean*/
  mcActionGetPlayRate           = 42,   /* param is pointer to Fixed*/
  mcActionShowBalloon           = 43,   /* param is a pointer to a boolean. set to false to stop balloon*/
  mcActionBadgeClick            = 44,   /* param is pointer to Boolean. set to false to ignore click*/
  mcActionMovieClick            = 45,   /* param is pointer to event record. change "what" to nullEvt to kill click*/
  mcActionSuspend               = 46,   /* no param*/
  mcActionResume                = 47,   /* no param*/
  mcActionSetControllerKeysEnabled = 48, /* param is Boolean*/
  mcActionGetTimeSliderRect     = 49,   /* param is pointer to rect*/
  mcActionMovieEdited           = 50,   /* no param*/
  mcActionGetDragEnabled        = 51,   /* param is pointer to Boolean*/
  mcActionSetDragEnabled        = 52,   /* param is Boolean*/
  mcActionGetSelectionBegin     = 53,   /* param is TimeRecord*/
  mcActionGetSelectionDuration  = 54,   /* param is TimeRecord*/
  mcActionPrerollAndPlay        = 55,   /* param is Fixed, play rate*/
  mcActionGetCursorSettingEnabled = 56, /* param is pointer to Boolean*/
  mcActionSetCursorSettingEnabled = 57, /* param is Boolean*/
  mcActionSetColorTable         = 58,   /* param is CTabHandle*/
  mcActionLinkToURL             = 59,   /* param is Handle to URL*/
  mcActionCustomButtonClick     = 60,   /* param is pointer to EventRecord*/
  mcActionForceTimeTableUpdate  = 61,   /* no param*/
  mcActionSetControllerTimeLimits = 62, /* param is pointer to 2 time values min/max. do no send this message to controller. used internally only.*/
  mcActionExecuteAllActionsForQTEvent = 63, /* param is ResolvedQTEventSpecPtr*/
  mcActionExecuteOneActionForQTEvent = 64, /* param is ResolvedQTEventSpecPtr*/
  mcActionAdjustCursor          = 65,   /* param is pointer to EventRecord (WindowRef is in message parameter)*/
  mcActionUseTrackForTimeTable  = 66,   /* param is pointer to {long trackID; Boolean useIt}. do not send this message to controller. */
  mcActionClickAndHoldPoint     = 67,   /* param is point (local coordinates). return true if point has click & hold action (e.g., VR object movie autorotate spot)*/
  mcActionShowMessageString     = 68,   /* param is a StringPtr*/
  mcActionShowStatusString      = 69,   /* param is a QTStatusStringPtr*/
  mcActionGetExternalMovie      = 70,   /* param is a QTGetExternalMoviePtr*/
  mcActionGetChapterTime        = 71,   /* param is a QTGetChapterTimePtr*/
  mcActionPerformActionList     = 72,   /* param is a QTAtomSpecPtr*/
  mcActionEvaluateExpression    = 73,   /* param is a QTEvaluateExpressionPtr*/
  mcActionFetchParameterAs      = 74,   /* param is a QTFetchParameterAsPtr*/
  mcActionGetCursorByID         = 75,   /* param is a QTGetCursorByIDPtr*/
  mcActionGetNextURL            = 76,   /* param is a Handle to URL*/
  mcActionMovieChanged          = 77,
  mcActionDoScript              = 78,   /* param is QTDoScriptPtr*/
  mcActionRestartAtTime         = 79,   /* param is QTResartAtTimePtr*/
  mcActionGetIndChapter         = 80,   /* param is QTChapterInfoPtr*/
  mcActionLinkToURLExtended     = 81,   /* param is QTAtomContainer as used by QTParseHREF*/
  mcActionSetVolumeStep         = 82,   /* param is short containing amount to step volume via arrow keys - default = 64*/
  mcActionAutoPlay              = 83,   /* param is Fixed, play rate*/
  mcActionPauseToBuffer         = 84,   /* param is Fixed, play rate on restart*/
  mcActionAppMessageReceived    = 85,   /* param is a long, application message*/
  mcActionMovieFinished         = 86,   /* no param*/
  mcActionEvaluateExpressionWithType = 89, /* param is a QTEvaluateExpressionWithTypePtr*/
  mcActionGetMovieName          = 90,   /* param is a p String Handle*/
  mcActionGetMovieID            = 91,   /* param is pointer to long*/
  mcActionGetMovieActive        = 92,   /* param is pointer to Boolean*/
  mcActionGetKeyboardFocus      = 93,   /* param is QTKeyboardFocusPtr*/
  mcActionSetKeyboardFocus      = 94,   /* param is QTKeyboardFocusPtr*/
  mcActionAddActionNotification = 95,   /* param is QTMCActionNotificationPtr*/
  mcActionRemoveActionNotification = 96, /* param is QTMCActionNotificationPtr*/
  mcActionKeyUp                 = 97,   /* param is pointer to EventRecord */
  mcActionGetConnectionStatus   = 98,   /* param is QTConnectionStatusPtr*/
  mcActionChapterListChanged    = 99,   /* no param */
  mcActionMovieLoadStateChanged = 100,  /* param is SInt32, new load state*/
  mcActionEditStateChanged      = 101   /* param is a Boolean, editing enabled?*/
};

typedef short                           mcAction;
enum {
  mcFlagSuppressMovieFrame      = 1 << 0,
  mcFlagSuppressStepButtons     = 1 << 1,
  mcFlagSuppressSpeakerButton   = 1 << 2,
  mcFlagsUseWindowPalette       = 1 << 3,
  mcFlagsDontInvalidate         = 1 << 4,
  mcFlagsUseCustomButton        = 1 << 5
};


enum {
  mcPositionDontInvalidate      = 1 << 5
};

typedef unsigned long                   mcFlags;
enum {
  kMCIEEnabledButtonPicture     = 1,
  kMCIEDisabledButtonPicture    = 2,
  kMCIEDepressedButtonPicture   = 3,
  kMCIEEnabledSizeBoxPicture    = 4,
  kMCIEDisabledSizeBoxPicture   = 5,
  kMCIEEnabledUnavailableButtonPicture = 6,
  kMCIEDisabledUnavailableButtonPicture = 7,
  kMCIESoundSlider              = 128,
  kMCIESoundThumb               = 129,
  kMCIEColorTable               = 256,
  kMCIEIsFlatAppearance         = 257,
  kMCIEDoButtonIconsDropOnDepress = 258
};

typedef unsigned long                   MCInterfaceElement;
typedef CALLBACK_API( Boolean , MCActionFilterProcPtr )(MovieController mc, short *action, void *params);
typedef CALLBACK_API( Boolean , MCActionFilterWithRefConProcPtr )(MovieController mc, short action, void *params, long refCon);
typedef CALLBACK_API( Boolean , MCActionNotificationProcPtr )(MovieController mc, short action, void *params, UInt32 inFlags, UInt32 *outFlags, void *refCon);
typedef STACK_UPP_TYPE(MCActionFilterProcPtr)                   MCActionFilterUPP;
typedef STACK_UPP_TYPE(MCActionFilterWithRefConProcPtr)         MCActionFilterWithRefConUPP;
typedef STACK_UPP_TYPE(MCActionNotificationProcPtr)             MCActionNotificationUPP;
/*
    menu related stuff
*/
enum {
  mcInfoUndoAvailable           = 1 << 0,
  mcInfoCutAvailable            = 1 << 1,
  mcInfoCopyAvailable           = 1 << 2,
  mcInfoPasteAvailable          = 1 << 3,
  mcInfoClearAvailable          = 1 << 4,
  mcInfoHasSound                = 1 << 5,
  mcInfoIsPlaying               = 1 << 6,
  mcInfoIsLooping               = 1 << 7,
  mcInfoIsInPalindrome          = 1 << 8,
  mcInfoEditingEnabled          = 1 << 9,
  mcInfoMovieIsInteractive      = 1 << 10
};

/* menu item codes*/
enum {
  mcMenuUndo                    = 1,
  mcMenuCut                     = 3,
  mcMenuCopy                    = 4,
  mcMenuPaste                   = 5,
  mcMenuClear                   = 6
};

/* messages to the application via mcActionAppMessageReceived*/
enum {
  kQTAppMessageSoftwareChanged  = 1,    /* notification to app that installed QuickTime software has been updated*/
  kQTAppMessageWindowCloseRequested = 3, /* request for app to close window containing movie controller*/
  kQTAppMessageExitFullScreenRequested = 4, /* request for app to turn off full screen mode if active*/
  kQTAppMessageDisplayChannels  = 5,    /* request for app to display the channel UI*/
  kQTAppMessageEnterFullScreenRequested = 6 /* request for app to turn on full screen mode*/
};

/* structures used as mcActionFilterProc params*/
struct QTStatusStringRecord {
  long                stringTypeFlags;
  char *              statusString;
};
typedef struct QTStatusStringRecord     QTStatusStringRecord;
typedef QTStatusStringRecord *          QTStatusStringPtr;
struct QTGetExternalMovieRecord {
  long                targetType;             /* set to kTargetMovieName or kTargetMovieID*/
  StringPtr           movieName;
  long                movieID;
  PtrToMovie          theMovie;
  MovieControllerPtr  theController;
};
typedef struct QTGetExternalMovieRecord QTGetExternalMovieRecord;
typedef QTGetExternalMovieRecord *      QTGetExternalMoviePtr;
struct QTGetChapterTimeRecord {
  StringPtr           chapterName;
  TimeRecord          chapterTime;
};
typedef struct QTGetChapterTimeRecord   QTGetChapterTimeRecord;
typedef QTGetChapterTimeRecord *        QTGetChapterTimePtr;
struct QTChapterInfoRecord {
  long                index;                  /* first chapter has index of 1*/
  TimeValue           time;                   /* -1 if no more chapters available*/
  Str255              name;
};
typedef struct QTChapterInfoRecord      QTChapterInfoRecord;
typedef QTChapterInfoRecord *           QTChapterInfoPtr;
struct QTEvaluateExpressionRecord {
  QTAtomSpec          expressionSpec;
  float *             expressionResult;
};
typedef struct QTEvaluateExpressionRecord QTEvaluateExpressionRecord;
typedef QTEvaluateExpressionRecord *    QTEvaluateExpressionPtr;
struct QTEvaluateExpressionWithTypeRecord {
  long                recordSize;             /* Size of structure (fill in at allocation) */
  QTAtomSpec          expressionSpec;
  float *             expressionResult;
  long                fetchAsType;
  Handle              nonNumericResult;
                                              /* Current size is 24 */
};
typedef struct QTEvaluateExpressionWithTypeRecord QTEvaluateExpressionWithTypeRecord;
typedef QTEvaluateExpressionWithTypeRecord * QTEvaluateExpressionWithTypePtr;
struct QTFetchParameterAsRecord {
  QTAtomSpec          paramListSpec;
  long                paramIndex;
  long                paramType;
  long                allowedFlags;
  void *              min;
  void *              max;
  void *              currentValue;
  void *              newValue;
  Boolean             isUnsignedValue;
};
typedef struct QTFetchParameterAsRecord QTFetchParameterAsRecord;
typedef QTFetchParameterAsRecord *      QTFetchParameterAsPtr;
struct QTGetCursorByIDRecord {
  short               cursorID;
  Handle              colorCursorData;
  long                reserved1;
};
typedef struct QTGetCursorByIDRecord    QTGetCursorByIDRecord;
typedef QTGetCursorByIDRecord *         QTGetCursorByIDPtr;
struct QTDoScriptRecord {
  long                scriptTypeFlags;
  char *              command;
  char *              arguments;
};
typedef struct QTDoScriptRecord         QTDoScriptRecord;
typedef QTDoScriptRecord *              QTDoScriptPtr;
struct QTRestartAtTimeRecord {
  TimeValue           startTime;              /* time scale is the movie timescale*/
  Fixed               rate;                   /* if rate is zero, the movie's current rate is maintained*/
};
typedef struct QTRestartAtTimeRecord    QTRestartAtTimeRecord;
typedef QTRestartAtTimeRecord *         QTRestartAtTimePtr;
/* values for paramType field of QTFetchParameterAsRecord*/
enum {
  kFetchAsBooleanPtr            = 1,
  kFetchAsShortPtr              = 2,
  kFetchAsLongPtr               = 3,
  kFetchAsMatrixRecordPtr       = 4,
  kFetchAsModifierTrackGraphicsModeRecord = 5,
  kFetchAsHandle                = 6,
  kFetchAsStr255                = 7,
  kFetchAsFloatPtr              = 8,
  kFetchAsPointPtr              = 9,
  kFetchAsNewAtomContainer      = 10,
  kFetchAsQTEventRecordPtr      = 11,
  kFetchAsFixedPtr              = 12,
  kFetchAsSetControllerValuePtr = 13,
  kFetchAsRgnHandle             = 14,   /* flipped to native*/
  kFetchAsComponentDescriptionPtr = 15,
  kFetchAsCString               = 16
};

enum {
  kQTCursorOpenHand             = -19183,
  kQTCursorClosedHand           = -19182,
  kQTCursorPointingHand         = -19181,
  kQTCursorRightArrow           = -19180,
  kQTCursorLeftArrow            = -19179,
  kQTCursorDownArrow            = -19178,
  kQTCursorUpArrow              = -19177,
  kQTCursorIBeam                = -19176
};



/* keyboard focus items*/

enum {
  kKeyboardAllowFocus           = 1,
  kKeyboardHaveFocus            = 2,
  kKeyboardValidate             = 4
};


enum {
  kRefConNavigateClick          = 'clik'
};


struct QTKeyboardFocusRecord {
  long                recordSize;             /* -> size of structure*/
  long                navigation;             /* -> same as in MediaNavigateTargetRefCon*/
  long                focusRefCon;            /* <-> refcon*/
  short               focusFlags;             /* <-> flags from kKeyboard... enum */
};
typedef struct QTKeyboardFocusRecord    QTKeyboardFocusRecord;
typedef QTKeyboardFocusRecord *         QTKeyboardFocusPtr;
enum {
  kQTMCActionNotifyBefore       = (1L << 0),
  kQTMCActionNotifyAfter        = (1L << 1),
  kQTMCActionNotifyParamChanged = (1L << 8),
  kQTMCActionNotifyCancelled    = (1L << 9),
  kQTMCActionNotifyUserFilterCancelled = (1L << 10),
  kQTMCActionNotifySignature    = 'noti'
};

struct QTMCActionNotificationRecord {
  OSType              returnSignature;        /* Set to zero when passed to movieController, set to 'noti' if mcActionAddActionNotification is implemented*/
  MCActionNotificationUPP  notifyAction;      /* Function to be called at action time*/
  void *              refcon;                 /* Something to pass to the action function*/
  UInt32              flags;                  /* Option flags*/
};
typedef struct QTMCActionNotificationRecord QTMCActionNotificationRecord;
typedef QTMCActionNotificationRecord *  QTMCActionNotificationPtr;
struct QTConnectionStatusRecord {

  short               flags;
  short               error;

  Handle              message;
};
typedef struct QTConnectionStatusRecord QTConnectionStatusRecord;
typedef QTConnectionStatusRecord *      QTConnectionStatusPtr;

/* target management */
/*
 *  MCSetMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetMovie(
  MovieController   mc,
  Movie             theMovie,
  WindowRef         movieWindow,
  Point             where)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetIndMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
MCGetIndMovie(
  MovieController   mc,
  short             index)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



#define MCGetMovie(mc) MCGetIndMovie(mc, 0)
/*
 *  MCRemoveAllMovies()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCRemoveAllMovies(MovieController mc)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCRemoveAMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCRemoveAMovie(
  MovieController   mc,
  Movie             m)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCRemoveMovie()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCRemoveMovie(MovieController mc)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* event handling etc. */
/*
 *  MCIsPlayerEvent()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCIsPlayerEvent(
  MovieController      mc,
  const EventRecord *  e)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* obsolete. use MCSetActionFilterWithRefCon instead. */
/*
 *  MCSetActionFilter()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetActionFilter(
  MovieController     mc,
  MCActionFilterUPP   blob)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    proc is of the form:
        Boolean userPlayerFilter(MovieController mc, short *action, void *params) =
    proc returns TRUE if it handles the action, FALSE if not
    action is passed as a VAR so that it could be changed by filter
    this is consistent with the current dialog manager stuff
    params is any potential parameters that go with the action
        such as set playback rate to xxx.
*/
/*
 *  MCDoAction()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCDoAction(
  MovieController   mc,
  short             action,
  void *            params)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* state type things */
/*
 *  MCSetControllerAttached()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetControllerAttached(
  MovieController   mc,
  Boolean           attach)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCIsControllerAttached()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCIsControllerAttached(MovieController mc)                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetControllerPort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetControllerPort(
  MovieController   mc,
  CGrafPtr          gp)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetControllerPort()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern CGrafPtr 
MCGetControllerPort(MovieController mc)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetVisible()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetVisible(
  MovieController   mc,
  Boolean           visible)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetVisible()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetVisible(MovieController mc)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetControllerBoundsRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetControllerBoundsRect(
  MovieController   mc,
  Rect *            bounds)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetControllerBoundsRect()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetControllerBoundsRect(
  MovieController   mc,
  const Rect *      bounds)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetControllerBoundsRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
MCGetControllerBoundsRgn(MovieController mc)                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetWindowRgn()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern RgnHandle 
MCGetWindowRgn(
  MovieController   mc,
  WindowRef         w)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/* other stuff */
/*
 *  MCMovieChanged()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCMovieChanged(
  MovieController   mc,
  Movie             m)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
    called when the app has changed thing about the movie (like bounding rect) or rate. So that we
        can update our graphical (and internal) state accordingly.
*/
/*
 *  MCSetDuration()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetDuration(
  MovieController   mc,
  TimeValue         duration)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    duration to use for time slider -- will be reset next time MCMovieChanged is called
        or MCSetMovie is called
*/
/*
 *  MCGetCurrentTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
MCGetCurrentTime(
  MovieController   mc,
  TimeScale *       scale)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    returns the time value and the time scale it is on. if there are no movies, the
        time scale is passed back as 0. scale is an optional parameter

*/
/*
 *  MCNewAttachedController()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCNewAttachedController(
  MovieController   mc,
  Movie             theMovie,
  WindowRef         w,
  Point             where)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
    makes theMovie the only movie attached to the controller. makes the controller visible.
    the window and where parameters are passed a long to MCSetMovie and behave as
    described there
*/
/*
 *  MCDraw()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCDraw(
  MovieController   mc,
  WindowRef         w)                                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCActivate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCActivate(
  MovieController   mc,
  WindowRef         w,
  Boolean           activate)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCIdle()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCIdle(MovieController mc)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCKey()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCKey(
  MovieController   mc,
  SInt8             key,
  long              modifiers)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCClick()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCClick(
  MovieController   mc,
  WindowRef         w,
  Point             where,
  long              when,
  long              modifiers)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
    calls for editing
*/
/*
 *  MCEnableEditing()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCEnableEditing(
  MovieController   mc,
  Boolean           enabled)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCIsEditingEnabled()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
MCIsEditingEnabled(MovieController mc)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCCopy()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
MCCopy(MovieController mc)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCCut()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Movie 
MCCut(MovieController mc)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCPaste()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCPaste(
  MovieController   mc,
  Movie             srcMovie)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCClear()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCClear(MovieController mc)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCUndo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCUndo(MovieController mc)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  somewhat special stuff
 */
/*
 *  MCPositionController()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCPositionController(
  MovieController   mc,
  const Rect *      movieRect,
  const Rect *      controllerRect,
  long              someFlags)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  MCGetControllerInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetControllerInfo(
  MovieController   mc,
  long *            someFlags)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/*
 *  MCSetClip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetClip(
  MovieController   mc,
  RgnHandle         theClip,
  RgnHandle         movieClip)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetClip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetClip(
  MovieController   mc,
  RgnHandle *       theClip,
  RgnHandle *       movieClip)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/*
 *  MCDrawBadge()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCDrawBadge(
  MovieController   mc,
  RgnHandle         movieRgn,
  RgnHandle *       badgeRgn)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetUpEditMenu()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetUpEditMenu(
  MovieController   mc,
  long              modifiers,
  MenuRef           mh)                                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetMenuString()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetMenuString(
  MovieController   mc,
  long              modifiers,
  short             item,
  Str255            aString)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetActionFilterWithRefCon()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCSetActionFilterWithRefCon(
  MovieController               mc,
  MCActionFilterWithRefConUPP   blob,
  long                          refCon)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCPtInController()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCPtInController(
  MovieController   mc,
  Point             thePt,
  Boolean *         inController)                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCInvalidate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCInvalidate(
  MovieController   mc,
  WindowRef         w,
  RgnHandle         invalidRgn)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCAdjustCursor()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCAdjustCursor(
  MovieController   mc,
  WindowRef         w,
  Point             where,
  long              modifiers)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetInterfaceElement()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MCGetInterfaceElement(
  MovieController      mc,
  MCInterfaceElement   whichElement,
  void *               element)                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCGetDoActionsProc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0.2 and later
 *    Non-Carbon CFM:   in QuickTimeLib 4.0 and later
 *    Windows:          in qtmlClient.lib 4.0 and later
 */
extern ComponentResult 
MCGetDoActionsProc(
  MovieController   mc,
  DoMCActionUPP *   doMCActionProc,
  long *            doMCActionRefCon)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCAddMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
MCAddMovieSegment(
  MovieController   mc,
  Movie             srcMovie,
  Boolean           scaled)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCTrimMovieSegment()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.3 and later
 *    Non-Carbon CFM:   in QuickTimeLib 5.0 and later
 *    Windows:          in qtmlClient.lib 5.0 and later
 */
extern ComponentResult 
MCTrimMovieSegment(MovieController mc)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  MCSetIdleManager()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
MCSetIdleManager(
  MovieController   mc,
  IdleManager       im)                                       AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/* Called (but not implemented) by controllers that derive from the standard movie controller.
   All controllers except standard movie controller must delegate this call. */
enum {
  kControllerUnderstandsIdleManagers = 1 << 0
};

/*
 *  MCSetControllerCapabilities()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.2 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.6 and later
 *    Non-Carbon CFM:   in QuickTimeLib 6.0 and later
 *    Windows:          in qtmlClient.lib 6.0 and later
 */
extern ComponentResult 
MCSetControllerCapabilities(
  MovieController   mc,
  long              flags,
  long              flagsMask)                                AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;






/****************************************
*                                       *
*       T  I  M  E  B  A  S  E          *
*                                       *
****************************************/
/*
 *  NewTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeBase 
NewTimeBase(void)                                             AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeTimeBase(TimeBase tb)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetTimeBaseTime(
  TimeBase      tb,
  TimeScale     s,
  TimeRecord *  tr)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseTime(
  TimeBase            tb,
  const TimeRecord *  tr)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseValue()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseValue(
  TimeBase    tb,
  TimeValue   t,
  TimeScale   s)                                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
GetTimeBaseRate(TimeBase tb)                                  AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseRate(
  TimeBase   tb,
  Fixed      r)                                               AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseStartTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetTimeBaseStartTime(
  TimeBase      tb,
  TimeScale     s,
  TimeRecord *  tr)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseStartTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseStartTime(
  TimeBase            tb,
  const TimeRecord *  tr)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseStopTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeValue 
GetTimeBaseStopTime(
  TimeBase      tb,
  TimeScale     s,
  TimeRecord *  tr)                                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseStopTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseStopTime(
  TimeBase            tb,
  const TimeRecord *  tr)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTimeBaseFlags(TimeBase tb)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseFlags()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseFlags(
  TimeBase   tb,
  long       timeBaseFlags)                                   AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseMasterTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseMasterTimeBase(
  TimeBase            slave,
  TimeBase            master,
  const TimeRecord *  slaveZero)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseMasterTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeBase 
GetTimeBaseMasterTimeBase(TimeBase tb)                        AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseMasterClock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseMasterClock(
  TimeBase            slave,
  Component           clockMeister,
  const TimeRecord *  slaveZero)                              AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseMasterClock()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentInstance 
GetTimeBaseMasterClock(TimeBase tb)                           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ConvertTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ConvertTime(
  TimeRecord *  theTime,
  TimeBase      newBase)                                      AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ConvertTimeScale()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ConvertTimeScale(
  TimeRecord *  theTime,
  TimeScale     newScale)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  AddTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
AddTime(
  TimeRecord *        dst,
  const TimeRecord *  src)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SubtractTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SubtractTime(
  TimeRecord *        dst,
  const TimeRecord *  src)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseStatus()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern long 
GetTimeBaseStatus(
  TimeBase      tb,
  TimeRecord *  unpinnedTime)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  SetTimeBaseZero()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
SetTimeBaseZero(
  TimeBase      tb,
  TimeRecord *  zero)                                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseEffectiveRate()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern Fixed 
GetTimeBaseEffectiveRate(TimeBase tb)                         AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetTimeBaseRateChangeStatus()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
GetTimeBaseRateChangeStatus(
  TimeBase          tb,
  TimeScale         scale,
  Fixed *           ratedChangedTo,
  TimeBaseStatus *  flags,
  TimeRecord *      rateChangeTimeBaseTime,
  TimeRecord *      rateChangeClockTime,
  TimeRecord *      currentClockTime)                         AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  ConvertTimeToClockTime()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern void 
ConvertTimeToClockTime(TimeRecord * time)                     AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  GetTimeBaseMasterOffsetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern TimeBase 
GetTimeBaseMasterOffsetTimeBase(TimeBase tb)                  AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  SetTimeBaseOffsetTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
SetTimeBaseOffsetTimeBase(
  TimeBase            tb,
  TimeBase            offsettb,
  const TimeRecord *  offsetZero)                             AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  AttachTimeBaseToCurrentThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
AttachTimeBaseToCurrentThread(TimeBase tb)                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  DetachTimeBaseFromCurrentThread()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
DetachTimeBaseFromCurrentThread(TimeBase tb)                  AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  GetTimeBaseThreadAttachState()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 *    Windows:          in qtmlClient.lib 6.5 and later
 */
extern OSErr 
GetTimeBaseThreadAttachState(
  TimeBase   inTimeBase,
  Boolean *  outAttachedToCurrentThread,
  Boolean *  outAttachedToAnyThread)                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/****************************************
*                                       *
*       C  A  L  L  B  A  C  K          *
*                                       *
****************************************/
/*
 *  NewCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTCallBack 
NewCallBack(
  TimeBase   tb,
  short      cbType)                                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  DisposeCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
DisposeCallBack(QTCallBack cb)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetCallBackType()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern short 
GetCallBackType(QTCallBack cb)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetCallBackTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern TimeBase 
GetCallBackTimeBase(QTCallBack cb)                            AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CallMeWhen()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
CallMeWhen(
  QTCallBack      cb,
  QTCallBackUPP   callBackProc,
  long            refCon,
  long            param1,
  long            param2,
  long            param3)                                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  CancelCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
CancelCallBack(QTCallBack cb)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;



/****************************************
*                                       *
*       C L O C K   C A L L B A C K     *
*             S U P P O R T             *
*                                       *
****************************************/
/*
 *  AddCallBackToTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
AddCallBackToTimeBase(QTCallBack cb)                          AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  RemoveCallBackFromTimeBase()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern OSErr 
RemoveCallBackFromTimeBase(QTCallBack cb)                     AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetFirstCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTCallBack 
GetFirstCallBack(TimeBase tb)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  GetNextCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern QTCallBack 
GetNextCallBack(QTCallBack cb)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/*
 *  ExecuteCallBack()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 2.5 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern void 
ExecuteCallBack(QTCallBack cb)                                AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;




/****************************************
*                                       *
*   M O V I E  P R O P E R T I E S      *
*                                       *
****************************************/

typedef CALLBACK_API( void , QTMoviePropertyListenerProcPtr )(Movie inMovie, QTPropertyClass inPropClass, QTPropertyID inPropID, void *inUserData);
typedef STACK_UPP_TYPE(QTMoviePropertyListenerProcPtr)          QTMoviePropertyListenerUPP;
/*
 *  QTGetMoviePropertyInfo()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
QTGetMoviePropertyInfo(
  Movie                  inMovie,
  QTPropertyClass        inPropClass,
  QTPropertyID           inPropID,
  QTPropertyValueType *  outPropType,
  ByteCount *            outPropValueSize,
  UInt32 *               outPropertyFlags)                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTGetMovieProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
QTGetMovieProperty(
  Movie                inMovie,
  QTPropertyClass      inPropClass,
  QTPropertyID         inPropID,
  ByteCount            inPropValueSize,
  QTPropertyValuePtr   outPropValueAddress,
  ByteCount *          outPropValueSizeUsed)                  AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTSetMovieProperty()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
QTSetMovieProperty(
  Movie                     inMovie,
  QTPropertyClass           inPropClass,
  QTPropertyID              inPropID,
  ByteCount                 inPropValueSize,
  ConstQTPropertyValuePtr   inPropValueAddress)               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTAddMoviePropertyListener()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
QTAddMoviePropertyListener(
  Movie                        inMovie,
  QTPropertyClass              inPropClass,
  QTPropertyID                 inPropID,
  QTMoviePropertyListenerUPP   inListenerProc,
  void *                       inUserData)                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  QTRemoveMoviePropertyListener()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern OSErr 
QTRemoveMoviePropertyListener(
  Movie                        inMovie,
  QTPropertyClass              inPropClass,
  QTPropertyID                 inPropID,
  QTMoviePropertyListenerUPP   inListenerProc,
  void *                       inUserData)                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;




/*
 *  MusicMediaGetIndexedTunePlayer()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   in QuickTimeLib 3.0 and later
 *    Windows:          in qtmlClient.lib 3.0 and later
 */
extern ComponentResult 
MusicMediaGetIndexedTunePlayer(
  ComponentInstance    ti,
  long                 sampleDescIndex,
  ComponentInstance *  tp)                                    AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;


/* UPP call backs */
/*
 *  NewMCActionFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MCActionFilterUPP
NewMCActionFilterUPP(MCActionFilterProcPtr userRoutine)       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMCActionFilterWithRefConUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MCActionFilterWithRefConUPP
NewMCActionFilterWithRefConUPP(MCActionFilterWithRefConProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  NewMCActionNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   available as macro/inline
 */
extern MCActionNotificationUPP
NewMCActionNotificationUPP(MCActionNotificationProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  NewQTMoviePropertyListenerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 9.9 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern QTMoviePropertyListenerUPP
NewQTMoviePropertyListenerUPP(QTMoviePropertyListenerProcPtr userRoutine) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  DisposeMCActionFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMCActionFilterUPP(MCActionFilterUPP userUPP)           AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMCActionFilterWithRefConUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMCActionFilterWithRefConUPP(MCActionFilterWithRefConUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  DisposeMCActionNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeMCActionNotificationUPP(MCActionNotificationUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  DisposeQTMoviePropertyListenerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 9.9 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
DisposeQTMoviePropertyListenerUPP(QTMoviePropertyListenerUPP userUPP) AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  InvokeMCActionFilterUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeMCActionFilterUPP(
  MovieController    mc,
  short *            action,
  void *             params,
  MCActionFilterUPP  userUPP)                                 AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMCActionFilterWithRefConUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 1.0 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeMCActionFilterWithRefConUPP(
  MovieController              mc,
  short                        action,
  void *                       params,
  long                         refCon,
  MCActionFilterWithRefConUPP  userUPP)                       AVAILABLE_MAC_OS_X_VERSION_10_0_AND_LATER;

/*
 *  InvokeMCActionNotificationUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   available as macro/inline
 */
extern Boolean
InvokeMCActionNotificationUPP(
  MovieController          mc,
  short                    action,
  void *                   params,
  UInt32                   inFlags,
  UInt32 *                 outFlags,
  void *                   refCon,
  MCActionNotificationUPP  userUPP)                           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  InvokeQTMoviePropertyListenerUPP()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 (or QuickTime 6.4) and later in QuickTime.framework
 *    CarbonLib:        in CarbonLib 9.9 and later
 *    Non-Carbon CFM:   available as macro/inline
 */
extern void
InvokeQTMoviePropertyListenerUPP(
  Movie                       inMovie,
  QTPropertyClass             inPropClass,
  QTPropertyID                inPropID,
  void *                      inUserData,
  QTMoviePropertyListenerUPP  userUPP)                        AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/* selectors for component calls */
enum {
    kVideoMediaResetStatisticsSelect           = 0x0105,
    kVideoMediaGetStatisticsSelect             = 0x0106,
    kVideoMediaGetStallCountSelect             = 0x010E,
    kVideoMediaSetCodecParameterSelect         = 0x010F,
    kVideoMediaGetCodecParameterSelect         = 0x0110,
    kTextMediaSetTextProcSelect                = 0x0101,
    kTextMediaAddTextSampleSelect              = 0x0102,
    kTextMediaAddTESampleSelect                = 0x0103,
    kTextMediaAddHiliteSampleSelect            = 0x0104,
    kTextMediaDrawRawSelect                    = 0x0109,
    kTextMediaSetTextPropertySelect            = 0x010A,
    kTextMediaRawSetupSelect                   = 0x010B,
    kTextMediaRawIdleSelect                    = 0x010C,
    kTextMediaGetTextPropertySelect            = 0x010D,
    kTextMediaFindNextTextSelect               = 0x0105,
    kTextMediaHiliteTextSampleSelect           = 0x0106,
    kTextMediaSetTextSampleDataSelect          = 0x0107,
    kSpriteMediaSetPropertySelect              = 0x0101,
    kSpriteMediaGetPropertySelect              = 0x0102,
    kSpriteMediaHitTestSpritesSelect           = 0x0103,
    kSpriteMediaCountSpritesSelect             = 0x0104,
    kSpriteMediaCountImagesSelect              = 0x0105,
    kSpriteMediaGetIndImageDescriptionSelect   = 0x0106,
    kSpriteMediaGetDisplayedSampleNumberSelect = 0x0107,
    kSpriteMediaGetSpriteNameSelect            = 0x0108,
    kSpriteMediaGetImageNameSelect             = 0x0109,
    kSpriteMediaSetSpritePropertySelect        = 0x010A,
    kSpriteMediaGetSpritePropertySelect        = 0x010B,
    kSpriteMediaHitTestAllSpritesSelect        = 0x010C,
    kSpriteMediaHitTestOneSpriteSelect         = 0x010D,
    kSpriteMediaSpriteIndexToIDSelect          = 0x010E,
    kSpriteMediaSpriteIDToIndexSelect          = 0x010F,
    kSpriteMediaGetSpriteActionsForQTEventSelect = 0x0110,
    kSpriteMediaSetActionVariableSelect        = 0x0111,
    kSpriteMediaGetActionVariableSelect        = 0x0112,
    kSpriteMediaGetIndImagePropertySelect      = 0x0113,
    kSpriteMediaNewSpriteSelect                = 0x0114,
    kSpriteMediaDisposeSpriteSelect            = 0x0115,
    kSpriteMediaSetActionVariableToStringSelect = 0x0116,
    kSpriteMediaGetActionVariableAsStringSelect = 0x0117,
    kSpriteMediaNewImageSelect                 = 0x011B,
    kSpriteMediaDisposeImageSelect             = 0x011C,
    kSpriteMediaImageIndexToIDSelect           = 0x011D,
    kSpriteMediaImageIDToIndexSelect           = 0x011E,
    kFlashMediaSetPanSelect                    = 0x0101,
    kFlashMediaSetZoomSelect                   = 0x0102,
    kFlashMediaSetZoomRectSelect               = 0x0103,
    kFlashMediaGetRefConBoundsSelect           = 0x0104,
    kFlashMediaGetRefConIDSelect               = 0x0105,
    kFlashMediaIDToRefConSelect                = 0x0106,
    kFlashMediaGetDisplayedFrameNumberSelect   = 0x0107,
    kFlashMediaFrameNumberToMovieTimeSelect    = 0x0108,
    kFlashMediaFrameLabelToMovieTimeSelect     = 0x0109,
    kFlashMediaGetFlashVariableSelect          = 0x010A,
    kFlashMediaSetFlashVariableSelect          = 0x010B,
    kFlashMediaDoButtonActionsSelect           = 0x010C,
    kFlashMediaGetSupportedSwfVersionSelect    = 0x010D,
    kMovieMediaGetChildDoMCActionCallbackSelect = 0x0102,
    kMovieMediaGetDoMCActionCallbackSelect     = 0x0103,
    kMovieMediaGetCurrentMoviePropertySelect   = 0x0104,
    kMovieMediaGetCurrentTrackPropertySelect   = 0x0105,
    kMovieMediaGetChildMovieDataReferenceSelect = 0x0106,
    kMovieMediaSetChildMovieDataReferenceSelect = 0x0107,
    kMovieMediaLoadChildMovieFromDataReferenceSelect = 0x0108,
    kMedia3DGetNamedObjectListSelect           = 0x0101,
    kMedia3DGetRendererListSelect              = 0x0102,
    kMedia3DGetCurrentGroupSelect              = 0x0103,
    kMedia3DTranslateNamedObjectToSelect       = 0x0104,
    kMedia3DScaleNamedObjectToSelect           = 0x0105,
    kMedia3DRotateNamedObjectToSelect          = 0x0106,
    kMedia3DSetCameraDataSelect                = 0x0107,
    kMedia3DGetCameraDataSelect                = 0x0108,
    kMedia3DSetCameraAngleAspectSelect         = 0x0109,
    kMedia3DGetCameraAngleAspectSelect         = 0x010A,
    kMedia3DSetCameraRangeSelect               = 0x010D,
    kMedia3DGetCameraRangeSelect               = 0x010E,
    kMedia3DGetViewObjectSelect                = 0x010F,
    kMCSetMovieSelect                          = 0x0002,
    kMCGetIndMovieSelect                       = 0x0005,
    kMCRemoveAllMoviesSelect                   = 0x0006,
    kMCRemoveAMovieSelect                      = 0x0003,
    kMCRemoveMovieSelect                       = 0x0006,
    kMCIsPlayerEventSelect                     = 0x0007,
    kMCSetActionFilterSelect                   = 0x0008,
    kMCDoActionSelect                          = 0x0009,
    kMCSetControllerAttachedSelect             = 0x000A,
    kMCIsControllerAttachedSelect              = 0x000B,
    kMCSetControllerPortSelect                 = 0x000C,
    kMCGetControllerPortSelect                 = 0x000D,
    kMCSetVisibleSelect                        = 0x000E,
    kMCGetVisibleSelect                        = 0x000F,
    kMCGetControllerBoundsRectSelect           = 0x0010,
    kMCSetControllerBoundsRectSelect           = 0x0011,
    kMCGetControllerBoundsRgnSelect            = 0x0012,
    kMCGetWindowRgnSelect                      = 0x0013,
    kMCMovieChangedSelect                      = 0x0014,
    kMCSetDurationSelect                       = 0x0015,
    kMCGetCurrentTimeSelect                    = 0x0016,
    kMCNewAttachedControllerSelect             = 0x0017,
    kMCDrawSelect                              = 0x0018,
    kMCActivateSelect                          = 0x0019,
    kMCIdleSelect                              = 0x001A,
    kMCKeySelect                               = 0x001B,
    kMCClickSelect                             = 0x001C,
    kMCEnableEditingSelect                     = 0x001D,
    kMCIsEditingEnabledSelect                  = 0x001E,
    kMCCopySelect                              = 0x001F,
    kMCCutSelect                               = 0x0020,
    kMCPasteSelect                             = 0x0021,
    kMCClearSelect                             = 0x0022,
    kMCUndoSelect                              = 0x0023,
    kMCPositionControllerSelect                = 0x0024,
    kMCGetControllerInfoSelect                 = 0x0025,
    kMCSetClipSelect                           = 0x0028,
    kMCGetClipSelect                           = 0x0029,
    kMCDrawBadgeSelect                         = 0x002A,
    kMCSetUpEditMenuSelect                     = 0x002B,
    kMCGetMenuStringSelect                     = 0x002C,
    kMCSetActionFilterWithRefConSelect         = 0x002D,
    kMCPtInControllerSelect                    = 0x002E,
    kMCInvalidateSelect                        = 0x002F,
    kMCAdjustCursorSelect                      = 0x0030,
    kMCGetInterfaceElementSelect               = 0x0031,
    kMCGetDoActionsProcSelect                  = 0x0032,
    kMCAddMovieSegmentSelect                   = 0x0033,
    kMCTrimMovieSegmentSelect                  = 0x0034,
    kMCSetIdleManagerSelect                    = 0x0035,
    kMCSetControllerCapabilitiesSelect         = 0x0036,
    kMusicMediaGetIndexedTunePlayerSelect      = 0x0101
};


#pragma options align=reset

#ifdef __cplusplus
}
#endif

#endif /* __MOVIES__ */

