/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 *  IOFireWireFamilyCommon.h
 *  IOFireWireUserClient/IOFireWireFamily
 *
 *  Created by NWG on Fri Apr 28 2000.
 *  Copyright (c) 2000-2001 Apple Computer, Inc. All rights reserved.
 *
 */
/*
	$Log: IOFireWireFamilyCommon.h,v $
	Revision 1.50.6.1.4.3  2005/03/08 03:48:48  collin
	*** empty log message ***
	
	Revision 1.50.6.1.4.2  2004/09/13 21:40:38  niels
	*** empty log message ***
	
	Revision 1.50.6.1.4.1  2004/09/13 21:10:10  niels
	*** empty log message ***
	
	Revision 1.50.6.1  2004/06/17 00:13:22  gecko1
	Add port disable on sleep changes for iPod
	
	Revision 1.50  2003/11/07 21:01:18  niels
	*** empty log message ***
	
	Revision 1.49  2003/10/21 01:16:41  collin
	*** empty log message ***
	
	Revision 1.48  2003/10/17 00:25:24  collin
	*** empty log message ***
	
	Revision 1.47  2003/10/15 02:19:45  collin
	*** empty log message ***
	
	Revision 1.46  2003/07/22 10:49:47  niels
	*** empty log message ***
	
	Revision 1.45  2003/07/21 06:52:59  niels
	merge isoch to TOT
	
	Revision 1.44.4.5  2003/07/21 06:44:44  niels
	*** empty log message ***
	
	Revision 1.44.4.4  2003/07/18 00:17:42  niels
	*** empty log message ***
	
	Revision 1.44.4.3  2003/07/14 22:08:53  niels
	*** empty log message ***
	
	Revision 1.44.4.2  2003/07/09 21:24:01  niels
	*** empty log message ***
	
	Revision 1.44.4.1  2003/07/01 20:54:07  niels
	isoch merge
	
	Revision 1.44  2003/03/17 01:05:22  collin
	*** empty log message ***
	
	Revision 1.43  2003/03/07 01:26:06  collin
	*** empty log message ***
	
	Revision 1.42  2003/02/19 22:33:17  niels
	add skip cycle DCL
	
	Revision 1.41  2003/02/18 00:14:01  collin
	*** empty log message ***
	
	Revision 1.40  2003/02/17 21:47:52  collin
	*** empty log message ***
	
	Revision 1.39  2002/12/05 19:08:37  niels
	remove trailing commas from enums in IOFireWireFamilyCommon.h
	
	Revision 1.38  2002/11/01 20:45:57  collin
	add enhanced IRM with support for the BROADCAST_CHANNEL register
	
	Revision 1.37  2002/10/01 02:40:27  collin
	security mode support
	
	Revision 1.36  2002/09/25 21:17:14  collin
	fix headers again.
	
	Revision 1.35  2002/09/25 00:27:23  niels
	flip your world upside-down
	
	Revision 1.34  2002/09/12 22:41:53  niels
	add GetIRMNodeID() to user client
	
*/

/*! @header IOFireWireFamilyCommon.h
This file contains useful definitions for working with FireWire
in the kernel and in user space
*/

#ifndef __IOFireWireFamilyCommon_H__
#define __IOFireWireFamilyCommon_H__

#ifdef KERNEL
#ifndef __IOKIT_IOTYPES_H
	#include <IOKit/IOTypes.h>
#endif
#else
#include <IOKit/IOKitLib.h>
#endif

#define FW_OLD_DCL_DEFS
#define FW_OLD_BIT_DEFS

// =================================================================
// bit ranges and fields
// =================================================================
#pragma mark -
#pragma mark BITS

// FireWire bit defs.

#define BIT(x)		( 1 << (x) )
#define FW_BIT(x)	( 1 << (31 - (x) ) )

#define FWBitRange(start, end)						\
(													\
	((((UInt32) 0xFFFFFFFF) << (start)) >>			\
	 ((start) + (31 - (end)))) <<					\
	(31 - (end))									\
)

#define FWBitRangePhase(start, end)					\
	(31 - (end))

#define BitRange(start, end)						\
(													\
	((((UInt32) 0xFFFFFFFF) << (31 - (end))) >>		\
	 ((31 - (end)) + (start))) <<					\
	(start)											\
)
 

#define BitRangePhase(start, end)					\
	(start)

// =================================================================
// FireWire messages & errors
// =================================================================
#pragma mark -
#pragma mark MESSAGES AND ERRORS

#define	iokit_fw_err(return) (sys_iokit|sub_iokit_firewire|return)

// e0008010 -> 0xe000801f Response codes from response packets

// Base of Response error codes
#define kIOFireWireResponseBase							iokit_fw_err(0x10)

// e0008020 -- Bus reset during command execution (current bus generation does
//             not match that specified in command.)
#define kIOFireWireBusReset								(kIOFireWireResponseBase+kFWResponseBusResetError)

// e0008001 -- Can't find requested entry in ROM
#define kIOConfigNoEntry								iokit_fw_err(1)

// e0008002 -- In pending queue waiting to execute
#define kIOFireWirePending								iokit_fw_err(2)

// e0008003 -- Last DCL callback of program (internal use)
#define kIOFireWireLastDCLToken							iokit_fw_err(3)

// e0008004
#define kIOFireWireConfigROMInvalid						iokit_fw_err(4)

// e0008005
#define kIOFireWireAlreadyRegistered					iokit_fw_err(5)

// e0008006
#define kIOFireWireMultipleTalkers						iokit_fw_err(6)

// e0008007
#define kIOFireWireChannelActive						iokit_fw_err(7)

// e0008008
#define kIOFireWireNoListenerOrTalker					iokit_fw_err(8)

// e0008009
#define kIOFireWireNoChannels							iokit_fw_err(9)

// e000800A
#define kIOFireWireChannelNotAvailable					iokit_fw_err(10)

// e000800B
#define kIOFireWireSeparateBus							iokit_fw_err(11)

// e000800C
#define kIOFireWireBadSelfIDs							iokit_fw_err(12)

// e000800D
#define kIOFireWireLowCableVoltage						iokit_fw_err(13)

// e000800E
#define kIOFireWireInsufficientPower					iokit_fw_err(14)

// e000800f
#define kIOFireWireOutOfTLabels							iokit_fw_err(15)

// NOTE: errors 16�31 used for address space response codes.. (see above)

// e0008101
#define kIOFireWireBogusDCLProgram						iokit_fw_err(257)

// e0008102
#define kIOFireWireTalkingAndListening					iokit_fw_err(258)

// e0008103
#define kIOFireWireHardwareSlept						iokit_fw_err(259)

// e0008104		// let's resume here...
// #define ???											iokit_fw_err(260)

// e00087d0
#define kIOFWMessageServiceIsRequestingClose 			(UInt32)iokit_fw_err(2000)
#define kIOFWMessagePowerStateChanged 					(UInt32)iokit_fw_err(2001)
#define kIOFWMessageTopologyChanged						(UInt32)iokit_fw_err(2002)
// =================================================================
// Pseudo address space response codes
// =================================================================
#pragma mark -
#pragma mark PSEDUO ADDRESS SPACE RESPONSE CODES
enum
{
	kFWResponseComplete			= 0,	// OK!
	kFWResponseConflictError	= 4,	// Resource conflict, may retry
	kFWResponseDataError		= 5,	// Data not available
	kFWResponseTypeError		= 6,	// Operation not supported
	kFWResponseAddressError		= 7,	// Address not valid in target device
	kFWResponseBusResetError	= 16,	// Pseudo response generated locally
	kFWResponsePending			= 17	// Pseudo response, real response sent later.
};

//
// Pseudo address space response codes
//
enum
{
	kFWAckTimeout				= -1,	// Pseudo ack generated locally
	kFWAckComplete				= 1,
	kFWAckPending				= 2,
	kFWAckBusyX					= 4,
	kFWAckBusyA					= 5,
	kFWAckBusyB					= 6,
	kFWAckDataError				= 13,
	kFWAckTypeError				= 14
};

// =================================================================
// FireWire bus speed numbers
// =================================================================
#pragma mark -
#pragma mark BUS SPEED NUMBERS

typedef enum
{
	kFWSpeed100MBit				= 0,
	kFWSpeed200MBit				= 1,
	kFWSpeed400MBit				= 2,
	kFWSpeed800MBit				= 3,
	kFWSpeedReserved			= 3,			// 1394B Devices report this no matter what speed the PHY allows
												// Worse, each port of the PHY could be different
	kFWSpeedUnknownMask			= 0x80,			// Set this bit is speed map if speed was reserved and
												// we haven't probed it further
	kFWSpeedMaximum				= 0x7FFFFFFF,	//zzz what are the best numbers???
	kFWSpeedInvalid				= 0x80000000
} IOFWSpeed;

// =================================================================
// FWAddress
// =================================================================
#pragma mark -
#pragma mark FWADDRESS
//
// The venerable FWAddress structure. This is the standard
// struct to use for passing FireWire addresses.
//

typedef struct FWAddressStruct
{
    UInt16	nodeID;		// bus/node
    UInt16	addressHi;	// Top 16 bits of node address.
    UInt32	addressLo;	// Bottom 32 bits of node address
	
	//
	// Useful C++ only constructors
	//
	#ifdef __cplusplus
	FWAddressStruct(const FWAddressStruct & a): 
			nodeID(a.nodeID), addressHi(a.addressHi), addressLo(a.addressLo) {};
    FWAddressStruct(UInt16 h=0xdead, UInt32 l=0xcafebabe) : 
			nodeID(0), addressHi(h), addressLo(l) {};
	FWAddressStruct(UInt16 h, UInt32 l, UInt16 n) :
			nodeID(n), addressHi(h), addressLo(l) {};
	#endif
} FWAddress, *FWAddressPtr ;

// =================================================================
// Config ROM
// =================================================================
#pragma mark -
#pragma mark CONFIG ROM

//
// CSR bit defs.
//

#define CSR_BIT(x) FW_BIT(x)

#define CSRBitRange(start, end)						\
(													\
	((((UInt32) 0xFFFFFFFF) << (start)) >>			\
	((start) + (31 - (end)))) <<					\
	(31 - (end))									\
)

#define CSRBitRangePhase(start, end)				\
	(31 - end)

//
// Key types.
//

typedef enum
{
	kConfigImmediateKeyType		= 0,
	kConfigOffsetKeyType		= 1,
	kConfigLeafKeyType		= 2,
	kConfigDirectoryKeyType		= 3,
	kInvalidConfigROMEntryType	= 0xff
} IOConfigKeyType;

//
// Key values.
//

enum
{
	kConfigTextualDescriptorKey		= 0x01,
	kConfigBusDependentInfoKey		= 0x02,
	kConfigModuleVendorIdKey		= 0x03,
	kConfigModuleHwVersionKey		= 0x04,
	kConfigModuleSpecIdKey			= 0x05,
	kConfigModuleSwVersionKey		= 0x06,
	kConfigModuleDependentInfoKey	= 0x07,
	kConfigNodeVendorIdKey			= 0x08,
	kConfigNodeHwVersionKey			= 0x09,
	kConfigNodeSpecIdKey			= 0x0A,
	kConfigNodeSwVersionKey			= 0x0B,
	kConfigNodeCapabilitiesKey		= 0x0C,
	kConfigNodeUniqueIdKey			= 0x0D,
	kConfigNodeUnitsExtentKey		= 0x0E,
	kConfigNodeMemoryExtentKey		= 0x0F,
	kConfigNodeDependentInfoKey		= 0x10,
	kConfigUnitDirectoryKey			= 0x11,
	kConfigUnitSpecIdKey			= 0x12,
	kConfigUnitSwVersionKey			= 0x13,
	kConfigUnitDependentInfoKey		= 0x14,
	kConfigUnitLocationKey			= 0x15,
	kConfigUnitPollMaskKey			= 0x16,
	kConfigModelIdKey				= 0x17,
	kConfigGenerationKey			= 0x38,		// Apple-specific

	kConfigRootDirectoryKey			= 0xffff	// Not a real key
};

// Core CSR registers.
enum
{
	kCSRStateUnitDepend			= CSRBitRange(0, 15),
	kCSRStateUnitDependPhase	= CSRBitRangePhase(0, 15),

	kCSRStateBusDepend			= CSRBitRange(16, 23),
	kCSRStateBusDependPhase		= CSRBitRangePhase(16, 23),

	kCSRStateLost				= CSR_BIT(24),
	kCSRStateDReq				= CSR_BIT(25),
	kCSRStateELog				= CSR_BIT(27),
	kCSRStateAtn				= CSR_BIT(28),
	kCSRStateOff				= CSR_BIT(29),

	kCSRStateState				= CSRBitRange(30, 31),
	kCSRStateStatePhase			= CSRBitRangePhase(30, 31),
	kCSRStateStateRunning		= 0,
	kCSRStateStateInitializing	= 1,
	kCSRStateStateTesting		= 2,
	kCSRStateStateDead			= 3
};

// Config ROM entry bit locations.

enum
{
	kConfigBusInfoBlockLength		= CSRBitRange (0, 7),
	kConfigBusInfoBlockLengthPhase	= CSRBitRangePhase (0, 7),

	kConfigROMCRCLength				= CSRBitRange (8, 15),
	kConfigROMCRCLengthPhase		= CSRBitRangePhase (8, 15),

	kConfigROMCRCValue				= CSRBitRange (16, 31),
	kConfigROMCRCValuePhase			= CSRBitRangePhase (16, 31),

	kConfigEntryKeyType				= CSRBitRange (0, 1),
	kConfigEntryKeyTypePhase		= CSRBitRangePhase (0, 1),

	kConfigEntryKeyValue			= CSRBitRange (2, 7),
	kConfigEntryKeyValuePhase		= CSRBitRangePhase (2, 7),

	kConfigEntryValue				= CSRBitRange (8, 31),
	kConfigEntryValuePhase			= CSRBitRangePhase (8, 31),

	kConfigLeafDirLength			= CSRBitRange (0, 15),
	kConfigLeafDirLengthPhase		= CSRBitRangePhase (0, 15),

	kConfigLeafDirCRC				= CSRBitRange (16, 31),
	kConfigLeafDirCRCPhase			= CSRBitRangePhase (16, 31)
};

//
// Key types.
//
typedef enum
{
	kCSRImmediateKeyType		= 0,
	kCSROffsetKeyType			= 1,
	kCSRLeafKeyType				= 2,
	kCSRDirectoryKeyType		= 3,
    kInvalidCSRROMEntryType		= 0xff
} IOCSRKeyType;

// CSR 64-bit fixed address defs.

enum
{
	kCSRNodeID								= CSRBitRange (0, 15),
	kCSRNodeIDPhase							= CSRBitRangePhase (0, 15),

	kCSRInitialMemorySpaceBaseAddressHi		= 0x00000000,
	kCSRInitialMemorySpaceBaseAddressLo		= 0x00000000,

	kCSRPrivateSpaceBaseAddressHi			= 0x0000FFFF,
	kCSRPrivateSpaceBaseAddressLo			= 0xE0000000,

	kCSRRegisterSpaceBaseAddressHi			= 0x0000FFFF,
	kCSRRegisterSpaceBaseAddressLo			= 0xF0000000,

	kCSRCoreRegistersBaseAddress			= kCSRRegisterSpaceBaseAddressLo,
	kCSRStateClearAddress					= kCSRCoreRegistersBaseAddress + 0x0000,
	kCSRStateSetAddress						= kCSRCoreRegistersBaseAddress + 0x0004,
	kCSRNodeIDsAddress						= kCSRCoreRegistersBaseAddress + 0x0008,
	kCSRResetStartAddress					= kCSRCoreRegistersBaseAddress + 0x000C,
	kCSRIndirectAddressAddress				= kCSRCoreRegistersBaseAddress + 0x0010,
	kCSRIndirectDataAddress					= kCSRCoreRegistersBaseAddress + 0x0014,
	kCSRSplitTimeoutHiAddress				= kCSRCoreRegistersBaseAddress + 0x0018,
	kCSRSplitTimeoutLoAddress				= kCSRCoreRegistersBaseAddress + 0x001C,
	kCSRArgumentHiAddress					= kCSRCoreRegistersBaseAddress + 0x0020,
	kCSRArgumentLoAddress					= kCSRCoreRegistersBaseAddress + 0x0024,
	kCSRTestStartAddress					= kCSRCoreRegistersBaseAddress + 0x0028,
	kCSRTestStatusAddress					= kCSRCoreRegistersBaseAddress + 0x002C,
	kCSRUnitsBaseHiAddress					= kCSRCoreRegistersBaseAddress + 0x0030,
	kCSRUnitsBaseLoAddress					= kCSRCoreRegistersBaseAddress + 0x0034,
	kCSRUnitsBoundHiAddress					= kCSRCoreRegistersBaseAddress + 0x0038,
	kCSRUnitsBoundLoAddress					= kCSRCoreRegistersBaseAddress + 0x003C,
	kCSRMemoryBaseHiAddress					= kCSRCoreRegistersBaseAddress + 0x0040,
	kCSRMemoryBaseLoAddress					= kCSRCoreRegistersBaseAddress + 0x0044,
	kCSRMemoryBoundHiAddress				= kCSRCoreRegistersBaseAddress + 0x0048,
	kCSRMemoryBoundLoAddress				= kCSRCoreRegistersBaseAddress + 0x004C,
	kCSRInterruptTargetAddress				= kCSRCoreRegistersBaseAddress + 0x0050,
	kCSRInterruptMaskAddress				= kCSRCoreRegistersBaseAddress + 0x0054,
	kCSRClockValueHiAddress					= kCSRCoreRegistersBaseAddress + 0x0058,
	kCSRClockValueMidAddress				= kCSRCoreRegistersBaseAddress + 0x005C,
	kCSRClockTickPeriodMidAddress			= kCSRCoreRegistersBaseAddress + 0x0060,
	kCSRClockTickPeriodLoAddress			= kCSRCoreRegistersBaseAddress + 0x0064,
	kCSRClockStrobeArrivedHiAddress			= kCSRCoreRegistersBaseAddress + 0x0068,
	kCSRClockStrobeArrivedMidAddress		= kCSRCoreRegistersBaseAddress + 0x006C,
	kCSRClockInfo0Address					= kCSRCoreRegistersBaseAddress + 0x0070,
	kCSRClockInfo1Address					= kCSRCoreRegistersBaseAddress + 0x0074,
	kCSRClockInfo2Address					= kCSRCoreRegistersBaseAddress + 0x0078,
	kCSRClockInfo3Address					= kCSRCoreRegistersBaseAddress + 0x007C,
	kCSRMessageRequestAddress				= kCSRCoreRegistersBaseAddress + 0x0080,
	kCSRMessageResponseAddress				= kCSRCoreRegistersBaseAddress + 0x00C0,
	kCSRErrorLogBufferAddress				= kCSRCoreRegistersBaseAddress + 0x0180,

	kCSRBusDependentRegistersBaseAddress	= kCSRRegisterSpaceBaseAddressLo + 0x0200,
	kCSRBusyTimeout							= kCSRRegisterSpaceBaseAddressLo + 0x0210,
	kCSRBusManagerID						= kCSRRegisterSpaceBaseAddressLo + 0x021C,
	kCSRBandwidthAvailable					= kCSRRegisterSpaceBaseAddressLo + 0x0220,
	kCSRChannelsAvailable31_0				= kCSRRegisterSpaceBaseAddressLo + 0x0224,
	kCSRChannelsAvailable63_32				= kCSRRegisterSpaceBaseAddressLo + 0x0228,
	kCSRBroadcastChannel					= kCSRRegisterSpaceBaseAddressLo + 0x0234,
	
	kConfigROMBaseAddress					= kCSRRegisterSpaceBaseAddressLo + 0x0400,
	kConfigBIBHeaderAddress					= kConfigROMBaseAddress,
	kConfigBIBBusNameAddress				= kConfigROMBaseAddress + 4,
	
	kPCRBaseAddress							= kCSRRegisterSpaceBaseAddressLo + 0x900,
	kFCPCommandAddress						= kCSRRegisterSpaceBaseAddressLo + 0xb00,
	kFCPResponseAddress						= kCSRRegisterSpaceBaseAddressLo + 0xd00
};

// from figure 10-7 of 1394a
#define kBroadcastChannelInitialValues 	0x8000001f
#define kBroadcastChannelValidMask 		0x40000000

// CSR defined 64 bit unique ID.

typedef UInt64 CSRNodeUniqueID;

// FireWire core CSR registers.

enum
{
	kFWCSRStateGone				= FW_BIT(16),
	kFWCSRStateLinkOff			= FW_BIT(22),
	kFWCSRStateCMstr			= FW_BIT(23)
};

// FireWire bus/nodeID address defs.

enum
{
	kFWAddressBusID				= FWBitRange (16, 25) << kCSRNodeIDPhase,
	kFWAddressBusIDPhase		= FWBitRangePhase (16, 25) + kCSRNodeIDPhase,

	kFWAddressNodeID			= FWBitRange (26, 31) << kCSRNodeIDPhase,
	kFWAddressNodeIDPhase		= FWBitRangePhase (26, 31) + kCSRNodeIDPhase,

	kFWLocalBusID				= 1023,
	kFWBroadcastNodeID			= 63,
	kFWBadNodeID				= 0xffff,

	kFWLocalBusAddress			= kFWLocalBusID << kFWAddressBusIDPhase,
	kFWBroadcastAddress			= kFWBroadcastNodeID << kFWAddressNodeIDPhase
};

#define FWNodeBaseAddress(busID, nodeID)												\
(																						\
	(busID << kFWAddressBusIDPhase) |													\
	(nodeID << kFWAddressNodeIDPhase)													\
)

#define FWNodeRegisterSpaceBaseAddressHi(busID, nodeID)									\
(																						\
	FWNodeBaseAddress (busID, nodeID) |													\
	kCSRRegisterSpaceBaseAddressHi														\
)

// FireWire CSR bus info block defs.

enum
{
	kFWBIBHeaderAddress					= kConfigBIBHeaderAddress,
	kFWBIBBusNameAddress				= kConfigBIBBusNameAddress,
	kFWBIBNodeCapabilitiesAddress		= kConfigROMBaseAddress + 8,
	kFWBIBNodeUniqueIDHiAddress			= kConfigROMBaseAddress + 12,
	kFWBIBNodeUniqueIDLoAddress			= kConfigROMBaseAddress + 16,

	kFWBIBBusName						= 0x31333934, //'1394'

	kFWBIBIrmc							= FW_BIT(0),
	kFWBIBCmc							= FW_BIT(1),
	kFWBIBIsc							= FW_BIT(2),
	kFWBIBBmc							= FW_BIT(3),
	kFWBIBCycClkAcc						= FWBitRange (8, 15),
	kFWBIBCycClkAccPhase				= FWBitRangePhase (8, 15),
	kFWBIBMaxRec						= FWBitRange (16, 19),
	kFWBIBMaxRecPhase					= FWBitRangePhase (16, 19),
	kFWBIBMaxROM						= FWBitRange (20, 21),
	kFWBIBMaxROMPhase					= FWBitRangePhase (20, 21),
	kFWBIBGeneration					= FWBitRange (24, 27),
	kFWBIBGenerationPhase				= FWBitRangePhase (24, 27),
	kFWBIBLinkSpeed						= FWBitRange (29, 31),
	kFWBIBLinkSpeedPhase				= FWBitRangePhase (29, 31)
};

// =================================================================
// Isoch defines
// =================================================================
#pragma mark -
#pragma mark ISOCH

enum
{
	kFWIsochDataLength		= FWBitRange (0, 15),
	kFWIsochDataLengthPhase	= FWBitRangePhase (0, 15),
	
	kFWIsochTag				= FWBitRange (16, 17),
	kFWIsochTagPhase		= FWBitRangePhase (16, 17),

	kFWIsochChanNum			= FWBitRange (18, 23),
	kFWIsochChanNumPhase	= FWBitRangePhase (18, 23),

	kFWIsochTCode			= FWBitRange (24, 27),
	kFWIsochTCodePhase		= FWBitRangePhase (24, 27),

	kFWIsochSy				= FWBitRange (28, 31),
	kFWIsochSyPhase			= FWBitRangePhase (28, 31)
};

#define CHAN_BIT(x) 		(((UInt64)1) << (63 - (x))
#define CHAN_MASK(x) 		(~CHAN_BIT(X))

typedef enum
{
	kFWNeverMultiMode = 0,
	kFWAllowMultiMode,
	kFWSuggestMultiMode,
	kFWAlwaysMultiMode,
	
	kFWDefaultIsochResourceFlags = kFWNeverMultiMode
} IOFWIsochResourceFlags ;

enum
{
	kFWIsochChannelDefaultFlags = 0,
	kFWIsochChannelDoNotResumeOnWake = BIT(1)
} ;

typedef enum
{
	kFWIsochPortDefaultOptions = 0,
	kFWIsochPortUseSeparateKernelThread		= BIT(1),
	kFWIsochEnableRobustness			= BIT(2)
} IOFWIsochPortOptions ;

// =================================================================
// DCL opcode defs.
// =================================================================
#pragma mark -
#pragma mark DCL OPCODES

enum
{
	kFWDCLImmediateEvent				= 0,
	kFWDCLCycleEvent					= 1,
	kFWDCLSyBitsEvent					= 2
};

typedef enum
{
	kFWDCLInvalidNotification				= 0
	, kFWDCLUpdateNotification				= 1
	, kFWDCLModifyNotification				= 2
	, kFWNuDCLModifyNotification			= 3
	, kFWNuDCLModifyJumpNotification		= 4
	, kFWNuDCLUpdateNotification			= 5
} IOFWDCLNotificationType ;

enum
{
	kFWDCLOpDynamicFlag					= BIT(16),
	kFWDCLOpVendorDefinedFlag			= BIT(17),
	kFWDCLOpFlagMask					= BitRange (16, 31),
	kFWDCLOpFlagPhase					= BitRangePhase (16, 31)
};

enum
{
	kDCLInvalidOp						= 0,
	kDCLSendPacketStartOp				= 1,
	kDCLSendPacketWithHeaderStartOp		= 2,
	kDCLSendPacketOp					= 3,
	kDCLSendBufferOp					= 4,	// obsolete - do not use
	kDCLReceivePacketStartOp			= 5,
	kDCLReceivePacketOp					= 6,
	kDCLReceiveBufferOp					= 7,	// obsolete - do not use
	kDCLCallProcOp						= 8,
	kDCLLabelOp							= 9,
	kDCLJumpOp							= 10,
	kDCLSetTagSyncBitsOp				= 11,
	kDCLUpdateDCLListOp					= 12,
	kDCLTimeStampOp						= 13,
	kDCLPtrTimeStampOp					= 14,
	kDCLSkipCycleOp						= 15,

	kDCLNuDCLLeaderOp					= 20	// compilerData field contains NuDCLRef to start of NuDCL
												// program.
												// Should not need to use this directly.
};

#ifdef FW_OLD_DCL_DEFS

//typedef struct DCLCommandStruct ;
//typedef void (DCLCallCommandProc)(DCLCommandStruct* command);

#else

//typedef struct DCLCommand ;
//typedef void (DCLCallCommandProc)(DCLCommand* command);

#endif

// =================================================================
// DCL structs
// =================================================================
#pragma mark -
#pragma mark DCL

typedef struct DCLCommandStruct
{
	struct DCLCommandStruct *	pNextDCLCommand;		// Next DCL command.
	UInt32						compilerData;			// Data for use by DCL compiler.
	UInt32						opcode;					// DCL opcode.
	UInt32						operands[1];			// DCL operands (size varies)
} DCLCommand;

typedef void (DCLCallCommandProc)(DCLCommand * command);

typedef struct DCLTransferPacketStruct
{
	DCLCommand *			pNextDCLCommand;		// Next DCL command.
	UInt32					compilerData;			// Data for use by DCL compiler.
	UInt32					opcode;					// DCL opcode.
	void *					buffer;					// Packet buffer.
	UInt32					size;					// Buffer size.
} DCLTransferPacket ;

typedef struct DCLTransferBufferStruct
{
	DCLCommand *			pNextDCLCommand;		// Next DCL command.
	UInt32					compilerData;			// Data for use by DCL compiler.
	UInt32					opcode;					// DCL opcode.
	void *					buffer;					// Buffer.
	UInt32					size;					// Buffer size.
	UInt16					packetSize;				// Size of packets to send.
	UInt16					reserved;
	UInt32					bufferOffset;			// Current offset into buffer.
} DCLTransferBuffer ;

typedef struct DCLCallProcStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	DCLCallCommandProc *	proc;				// Procedure to call.
	UInt32					procData;			// Data for use by called procedure.
} DCLCallProc;

typedef struct DCLLabelStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
} DCLLabel;

typedef struct DCLJumpStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	DCLLabel *				pJumpDCLLabel;		// DCL label to jump to.
} DCLJump;

typedef struct DCLSetTagSyncBitsStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	UInt16					tagBits;			// Tag bits for following packets.
	UInt16					syncBits;			// Sync bits for following packets.
} DCLSetTagSyncBits;

typedef struct DCLUpdateDCLListStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	DCLCommand **			dclCommandList;		// List of DCL commands to update.
	UInt32					numDCLCommands;		// Number of DCL commands in list.
} DCLUpdateDCLList;

typedef struct DCLTimeStampStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	UInt32					timeStamp;			// Time stamp.
} DCLTimeStamp;

typedef struct DCLPtrTimeStampStruct
{
	DCLCommand *			pNextDCLCommand;	// Next DCL command.
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode;				// DCL opcode.
	UInt32 *				timeStampPtr;		// Where to store the time stamp.
} DCLPtrTimeStamp ;

typedef struct 
{
	DCLCommand *			pNextDCLCommand ;	// unused - always NULL
	UInt32					compilerData;		// Data for use by DCL compiler.
	UInt32					opcode ;			// must be kDCLNuDCLLeaderOp
	void*				 	program ;			// NuDCL program here...
} DCLNuDCLLeader ;

#ifdef FW_OLD_DCL_DEFS

//  should not use these...

typedef DCLCommand*				DCLCommandPtr ;
typedef DCLTransferBuffer*		DCLTransferBufferPtr ;
typedef DCLTransferPacket*		DCLTransferPacketPtr ;
typedef DCLCallProc*			DCLCallProcPtr ;
typedef DCLLabel*				DCLLabelPtr ;
typedef DCLJump*				DCLJumpPtr ;
typedef DCLSetTagSyncBits*		DCLSetTagSyncBitsPtr ;
typedef DCLUpdateDCLList*		DCLUpdateDCLListPtr ;
typedef DCLTimeStamp*			DCLTimeStampPtr ;
typedef DCLPtrTimeStamp*		DCLPtrTimeStampPtr ;
typedef DCLCallCommandProc* 	DCLCallCommandProcPtr ;

#endif

// =================================================================
// NuDCL
// =================================================================
#pragma mark -
#pragma mark NUDCL

typedef struct __NuDCL *	NuDCLRef ;
typedef NuDCLRef			NuDCLSendPacketRef ;
typedef NuDCLRef			NuDCLSkipCycleRef ;
typedef NuDCLRef			NuDCLReceivePacketRef ;

typedef void (*NuDCLCallback)( void* refcon, NuDCLRef dcl );

typedef enum
{
	kNuDCLDynamic = BIT( 1 ),
	kNuDCLUpdateBeforeCallback = BIT( 2 )

} NuDCLFlags ;

// =================================================================
// Miscellaneous
// =================================================================
#pragma mark -
#pragma mark MISCELLANEOUS

typedef void* FWClientCommandID ;

typedef struct IOFireWireSessionRefOpaqueStuct* IOFireWireSessionRef ;

//
// bus management constants.
//

enum
{
	kFWBusManagerArbitrationTimeoutDuration	= 625 // durationMillisecond
};

//
// bus characteristics.
//

enum
{
	kFWMaxBusses				= 1023,
	kFWMaxNodesPerBus			= 63,
	kFWMaxNodeHops				= 16
};

//
// node flags
//

enum
{
    kIOFWDisablePhysicalAccess 		= (1 << 0),
	kIOFWDisableAllPhysicalAccess 	= (1 << 1),
	kIOFWEnableRetryOnAckD			= (1 << 2),
	kIOFWLimitAsyncPacketSize		= (1 << 3),
	kIOFWDisablePhyOnSleep			= (1 << 4)
};

//
// write flags
//

enum IOFWWriteFlags
{
	kIOFWWriteFlagsNone				= 0x0000000,
	kIOFWWriteFlagsDeferredNotify 	= 0x00000001
};

//
// security modes
//

enum IOFWSecurityMode
{
	kIOFWSecurityModeNormal = 0,
	kIOFWSecurityModeSecure = 1,
	kIOFWSecurityModeSecurePermanent = 2
};

//
// physical access settings
//

enum IOFWPhysicalAccessMode
{
	kIOFWPhysicalAccessEnabled = 0,
	kIOFWPhysicalAccessDisabled = 1,
	kIOFWPhysicalAccessDisabledForGeneration = 2
};

// old style bit defs
#ifdef FW_OLD_BIT_DEFS

	#define kBit0	BIT(0)
	#define kBit1	BIT(1)
	#define kBit2	BIT(2)
	#define kBit3	BIT(3)
	#define kBit4	BIT(4)
	#define kBit5	BIT(5)
	#define kBit6	BIT(6)
	#define kBit7	BIT(7)
	#define kBit8	BIT(8)
	#define kBit9	BIT(9)
	#define kBit10	BIT(10)
	#define kBit11	BIT(11)
	#define kBit12	BIT(12)
	#define kBit13	BIT(13)
	#define kBit14	BIT(14)
	#define kBit15	BIT(15)
	#define kBit16	BIT(16)
	#define kBit17	BIT(17)
	#define kBit18	BIT(18)
	#define kBit19	BIT(19)
	#define kBit20	BIT(20)
	#define kBit21	BIT(21)
	#define kBit22	BIT(22)
	#define kBit23	BIT(23)
	#define kBit24	BIT(24)
	#define kBit25	BIT(25)
	#define kBit26	BIT(26)
	#define kBit27	BIT(27)
	#define kBit28	BIT(28)
	#define kBit29	BIT(29)
	#define kBit30	BIT(30)
	#define kBit31	BIT(31)

#endif

#endif //__IOFireWireFamilyCommon_H__
