/*
	File:		DirServicesTypes.h

	Contains:	xxx put contents here xxx

	Copyright:	� 1998-2000 by Apple Computer, Inc., all rights reserved.

	NOT_FOR_OPEN_SOURCE <to be reevaluated at a later time>
*/

#ifndef __DirServicesTypesH__
#define	__DirServicesTypesH__	1

#ifndef dsBool
	#define	dsBool	int
#endif

typedef	enum
{
	eDSNoErr					=	0,

	eDSOpenFailed				=	-14000,
	eDSCloseFailed				=	-14001,
	eDSOpenNodeFailed			=	-14002,
	eDSBadDirRefences			=	-14003,
	eDSNullRecordReference		= 	-14004,
	eDSMaxSessionsOpen			=	-14005,
	eDSCannotAccessSession 		=	-14006,
	eDSDirSrvcNotOpened 		=	-14007,
	eDSNodeNotFound				=	-14008,
	eDSUnknownNodeName			=	-14009,

	eDSRegisterCustomFailed		=	-14010,
	eDSGetCustomFailed			=	-14011,
	eDSUnRegisterFailed			=	-14012,
	
	eDSAllocationFailed			=	-14050,
	eDSDeAllocateFailed			=	-14051,
	eDSCustomBlockFailed		=	-14052,
	eDSCustomUnblockFailed		=	-14053,
	eDSCustomYieldFailed		=	-14054,

	eDSCorruptBuffer			=	-14060,
	eDSInvalidIndex				=	-14061,
	eDSIndexOutOfRange			=	-14062,
	eDSIndexNotFound			=	-14063,
	eDSCorruptRecEntryData		=	-14065,

	eDSRefSpaceFull				=	-14069,
	eDSRefTableAllocError		=	-14070,
	eDSInvalidReference			=	-14071,
	eDSInvalidRefType			=	-14072,
	eDSInvalidDirRef			=	-14073,
	eDSInvalidNodeRef			=	-14074,
	eDSInvalidRecordRef			=	-14075,
	eDSInvalidAttrListRef		=	-14076,
	eDSInvalidAttrValueRef		=	-14077,
	eDSInvalidContinueData		=	-14078,
	eDSInvalidBuffFormat		=	-14079,
	eDSInvalidPatternMatchType	=	-14080,

	eDSAuthFailed				=	-14090,
	eDSAuthMethodNotSupported	=	-14091,
	eDSAuthResponseBufTooSmall	=	-14092,
	eDSAuthParameterError		=	-14093,
	eDSAuthInBuffFormatError	=	-14094,
	eDSAuthNoSuchEntity			=	-14095,
	eDSAuthBadPassword			=	-14096,
	eDSAuthContinueDataBad		=	-14097,
	eDSAuthUnknownUser			=	-14098,
	eDSAuthInvalidUserName		=	-14099,
	eDSAuthCannotRecoverPasswd	=	-14100,
	eDSAuthFailedClearTextOnly	=	-14101,
	eDSAuthNoAuthServerFound	=	-14102,
	eDSAuthServerError			=	-14103,
	eDSInvalidContext			=	-14104,
	eDSBadContextData			=	-14105,

	eDSPermissionError			=	-14120,
	eDSReadOnly					=	-14121,
	eDSInvalidDomain			=	-14122,
	eNetInfoError				=	-14123,

	eDSInvalidRecordType		=	-14130,
	eDSInvalidAttributeType		=	-14131,
	eDSInvalidRecordName		=	-14133,
	eDSAttributeNotFound		=	-14134,
	eDSRecordAlreadyExists		=	-14135,
	eDSRecordNotFound			=	-14136,
	eDSAttributeDoesNotExist	=	-14137,

	eDSNoStdMappingAvailable	=	-14140,
	eDSInvalidNativeMapping		=	-14141,

	eDSPlugInConfigFileError	=	-14150,
	eDSInvalidPlugInConfigData	=	-14151,

	eDSNullParameter			=	-14200,
	eDSNullDataBuff				=	-14201,
	eDSNullNodeName				=	-14202,
	eDSNullRecEntryPtr			=	-14203,
	eDSNullRecName				=	-14204,
	eDSNullRecNameList			=	-14205,
	eDSNullRecType				=	-14206,
	eDSNullRecTypeList			=	-14207,
	eDSNullAttribute			=	-14208,
	eDSNullAttributeAccess		=	-14209,
	eDSNullAttributeValue		=	-14210,
	eDSNullAttributeType		=	-14211,
	eDSNullAttributeTypeList	=	-14212,
	eDSNullAttributeControlPtr	=	-14213,
	eDSNullAttributeRequestList	=	-14214,
	eDSNullDataList				=	-14215,
	eDSNullDirNodeTypeList		= 	-14216,
	eDSNullAutMethod			= 	-14217,
	eDSNullAuthStepData			=	-14218,
	eDSNullAuthStepDataResp		=	-14219,
	eDSNullNodeInfoTypeList		=	-14220,
	eDSNullPatternMatch			=	-14221,
	eDSNullNodeNamePattern		=	-14222,
	eDSNullTargetArgument		=	-14223,

	eDSEmptyParameter			=	-14230,
	eDSEmptyBuffer				=	-14231,
	eDSEmptyNodeName			=	-14232,
	eDSEmptyRecordName			=	-14233,
	eDSEmptyRecordNameList		=	-14234,
	eDSEmptyRecordType			=	-14235,
	eDSEmptyRecordTypeList		=	-14236,
	eDSEmptyRecordEntry			=	-14237,
	eDSEmptyPatternMatch		=	-14238,
	eDSEmptyNodeNamePattern		=	-14239,
	eDSEmptyAttribute			=	-14240,
	eDSEmptyAttributeType		=	-14241,
	eDSEmptyAttributeTypeList	=	-14242,
	eDSEmptyAttributeValue		=	-14243,
	eDSEmptyAttributeRequestList=	-14244,
	eDSEmptyDataList			=	-14245,
	eDSEmptyNodeInfoTypeList	=	-14246,
	eDSEmptyAuthMethod			=	-14247,
	eDSEmptyAuthStepData		=	-14248,
	eDSEmptyAuthStepDataResp	=	-14249,
	eDSEmptyPattern2Match		=	-14250,

	eDSBadDataNodeLength		=	-14255,
	eDSBadDataNodeFormat		=	-14256,
	eDSBadSourceDataNode		=	-14257,
	eDSBadTargetDataNode		=	-14258,

	eDSBufferTooSmall			=	-14260,
	eDSUnknownMatchType			=	-14261,
	eDSUnSupportedMatchType		=	-14262,
	eDSInvalDataList			= 	-14263,
	eDSAttrListError			=	-14264,

	eServerNotRunning			=	-14270,
	eUnknownAPICall				=	-14271,
	eUnknownServerError			=	-14272,
	eUnknownPlugIn				= 	-14273,
	ePlugInDataError			=	-14274,
	ePlugInNotFound				=	-14275,
	ePlugInError				= 	-14276,
	ePlugInInitError			=	-14277,
	ePlugInNotActive			=	-14278,
	ePlugInFailedToInitialize	=	-14279,
	ePlugInCallTimedOut			=	-14280,

	eNoSearchNodesFound			=	-14290,
	eSearchPathNotDefined		=	-14291,
	eNotHandledByThisNode		=	-14292,

	eIPCSendError				=	-14330,
	eIPCReceiveError			=	-14331,
	eServerReplyError			=	-14332,

	ePluginHandlerNotLoaded		=	-14400,
	eNoPluginsLoaded			=	-14402,
	ePluginAlreadyLoaded		=	-14404,
	ePluginVersionNotFound		=	-14406,
	ePluginNameNotFound			=	-14408,
	eNoPluginFactoriesFound		=	-14410,
	ePluginConfigAvailNotFound	=	-14412,
	ePluginConfigFileNotFound	=	-14414,

	eCFMGetFileSysRepErr		=	-14450,
	eCFPlugInGetBundleErr		=	-14452,
	eCFBndleGetInfoDictErr		=	-14454,
	eCFDictGetValueErr			=	-14456,

	// Authentication Errors
	eDSServerTimeout			=	-14470,
	eDSContinue					=	-14471,
	eDSInvalidHandle			=	-14472,
	eDSSendFailed				=	-14473,
	eDSReceiveFailed			=	-14474,
	eDSBadPacket				=	-14475,
	eDSInvalidTag				=	-14476,
	eDSInvalidSession			=	-14477,
	eDSInvalidName				=	-14478,
	eDSUserUnknown				=	-14479,
	eDSUnrecoverablePassword	=	-14480,
	eDSAuthenticationFailed		=	-14481,
	eDSBogusServer				=	-14482,
	eDSOperationFailed			=	-14483,
	eDSNotAuthorized			=	-14484,
	eDSNetInfoError				=	-14485,
	eDSContactMaster			=	-14486,
	eDSServiceUnavailable		=	-14487,

	eFWGetDirNodeNameErr1		=	-14501,
	eFWGetDirNodeNameErr2		=	-14502,
	eFWGetDirNodeNameErr3		=	-14503,
	eFWGetDirNodeNameErr4		=	-14504,

	// Errors received in the range -14700 : -14780 denote specific server errors.
	//	Contact Directory Services Server support when these errors are encountered
	eParameterSendError			=	-14700,
	eParameterReceiveError		=	-14720,

	eServerSendError			=	-14740,
	eServerReceiveError			=	-14760,

	eMemoryError				=	-14900,
	eMemoryAllocError			=	-14901,
	eServerError				=	-14910,
	eParameterError				= 	-14915,

	// Server response errors
	//	These errors indicate that the plug-in or server did not return the
	//	required data
	eDataReceiveErr_NoDirRef			=	-14950,		// No tDirReference returned
	eDataReceiveErr_NoRecRef			=	-14951,		// No tRecordReference returned
	eDataReceiveErr_NoAttrListRef		=	-14952,		// No tAttributeListRef returned
	eDataReceiveErr_NoAttrValueListRef	=	-14953,		// No tAttributeValueListRef returned
	eDataReceiveErr_NoAttrEntry			=	-14954,		// No tAttributeEntry returned
	eDataReceiveErr_NoAttrValueEntry	=	-14955,		// No tAttributeValueEntry returned
	eDataReceiveErr_NoNodeCount			=	-14956,		// No node Count returned
	eDataReceiveErr_NoAttrCount			=	-14957,		// No attribute count returned
	eDataReceiveErr_NoRecEntry			=	-14958,		// No tRecordEntry returned
	eDataReceiveErr_NoRecEntryCount		=	-14959,		// No record entry count returned
	eDataReceiveErr_NoRecMatchCount		=	-14960,		// No record match count returned
	eDataReceiveErr_NoDataBuff			=	-14961,		// No tDataBuffer returned
	eDataReceiveErr_NoContinueData		=	-14962,		// No continue data returned
	eDataReceiveErr_NoNodeChangeToken  	=	-14963,		// No node Change Token returned

	eNoLongerSupported			=	-14986,
	eUndefinedError				=	-14987,
	eNotYetImplemented			=	-14988,

	eDSLastValue				=	-14999

} tDirStatus;

typedef enum
{
	eDSNoMatch1				=	0x0000,
	eDSAnyMatch				=	0x0001,
	
	eDSBeginAppleReserve1	=	0x0002,
	eDSEndAppleReserve1		=	0x1fff,

	eDSExact				=	0x2001,
	eDSStartsWith			=	0x2002,
	eDSEndsWith				=	0x2003,
	eDSContains				=	0x2004,

	eDSLessThan				=	0x2005,
	eDSGreaterThan			=	0x2006,
	eDSLessEqual			=	0x2007,
	eDSGreaterEqual			=	0x2008,

	// Advanced Search Pattern Match Specifiers
	eDSWildCardPattern		=	0x2009,
	eDSRegularExpression	=	0x200A,


	// The following Specifiers are identical to the ones above
	// however, the "i" notation following the "eDS" prefix
	// denoted a case-insensitive comparision has been requested.	
	eDSiExact				=	0x2101,
	eDSiStartsWith			=	0x2102,
	eDSiEndsWith			=	0x2103,
	eDSiContains			=	0x2104,

	eDSiLessThan			=	0x2105,
	eDSiGreaterThan			=	0x2106,
	eDSiLessEqual			=	0x2107,
	eDSiGreaterEqual		=	0x2108,

	// Advanced Search Pattern Match Specifiers
	eDSiWildCardPattern		=	0x2109,
	eDSiRegularExpression	=	0x210A,

	// Specific Node Types
	eDSLocalNodeNames		=	0x2200,
	eDSSearchNodeName		=	0x2201,
	eDSConfigNodeName		=	0x2202,
	eDSLocalHostedNodes		=	0x2203,
	eDSAuthenticationSearchNodeName		=	0x2201,		//duplicate of eDSSearchNodeName
	eDSContactsSearchNodeName			=	0x2204,
	
	dDSBeginPlugInCustom	=	0x3000,
	eDSEndPlugInCustom		=	0x4fff,
	
	eDSBeginAppleReserve2	=	0x5000,
	eDSEndAppleReserve2		=	0xfffe,
	
	eDSNoMatch2		=	0xffff
} tDirPatternMatch;

typedef	unsigned long	tDirReference;
typedef	unsigned long	tDirNodeReference;

typedef	void *			tClientData;
typedef void *			tBuffer;
typedef	void *			tContextData;

//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
// Data Node Routines

typedef struct
{
	unsigned long	fBufferSize;
	unsigned long	fBufferLength;
	char			fBufferData[1];
} tDataBuffer;
typedef tDataBuffer *tDataBufferPtr;

typedef tDataBuffer tDataNode;
typedef tDataNode	*tDataNodePtr;

typedef struct
{
	unsigned long	fDataNodeCount;
	tDataNodePtr	fDataListHead;
} tDataList;
typedef tDataList *tDataListPtr;


//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

typedef struct
{
	unsigned long	fGuestAccessFlags;
	unsigned long	fDirMemberFlags;
	unsigned long	fDirNodeMemberFlags;
	unsigned long	fOwnerFlags;
	unsigned long	fAdministratorFlags;
}	tAccessControlEntry;
typedef tAccessControlEntry *tAccessControlEntryPtr;


//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------

typedef struct
{
	unsigned long	fAttributeValueID;		// unique ID of this data value
	tDataNode		fAttributeValueData;	// the actual data contents of this value...
} tAttributeValueEntry;
typedef tAttributeValueEntry *tAttributeValueEntryPtr;
typedef unsigned long tAttributeValueListRef;


//-----------------------------------------------

typedef struct
{
	unsigned long		fReserved1;
	tAccessControlEntry	fReserved2;
	unsigned long		fAttributeValueCount;		// number of values associated with this attribute..
	unsigned long		fAttributeDataSize;			// total byte count of all attribute values...
	unsigned long		fAttributeValueMaxSize;		// maximum size of a value of this attribute type
	tDataNode			fAttributeSignature;		// a Unique byte-sequence representing this attribute type
													// most likely a collection of Uni-code characters..
}	tAttributeEntry;
typedef tAttributeEntry *tAttributeEntryPtr;
typedef unsigned long	tAttributeListRef;


//-----------------------------------------------

typedef struct
{
	unsigned long		fReserved1;
	tAccessControlEntry	fReserved2;
	unsigned long		fRecordAttributeCount;
	tDataNode			fRecordNameAndType;
}	tRecordEntry;
typedef tRecordEntry *tRecordEntryPtr;
typedef unsigned long	tRecordReference;


//-----------------------------------------------
//-----------------------------------------------
//-----------------------------------------------
// Directory Services Function Pointers
#pragma mark Function Pointers

#ifdef __cplusplus
extern "C" {
#endif

// Function Pointers for allocation & deallocation routines...
// these routines only need to be set if some reason the standard OS routines won't do..
// otherwise standard OS routines will be used if nothing is registered...
typedef	tDirStatus	(*fpCustomAllocate) 		(	tDirReference	inDirReference,
													tClientData		inClientData,
													unsigned long	inAllocationRequest,
													tBuffer			*outAllocationPtr	);


typedef tDirStatus	(*fpCustomDeAllocate) 		(	tDirReference	inDirReference,
													tClientData		inClientData,
													tBuffer			inAllocationPtr		);

// Function Pointers for thread block, unblock, and yield routines...
// these routines only need to be set if some reason the standard OS routines won't do..
// otherwise standard OS routines will be used if nothing is registered...
typedef tDirStatus	(*fpCustomThreadBlock)		(	tDirReference	inDirReference,
													tClientData		inClientData		);

typedef tDirStatus	(*fpCustomThreadUnBlock)	(	tDirReference	inDirReference,
													tClientData		inClientData		);

typedef	tDirStatus	(*fpCustomThreadYield)		(	tDirReference	inDirReference,
													tClientData		inClientData		);


#ifdef __cplusplus
}
#endif

#endif
