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

#ifndef _IOAUDIODEFINES_H
#define _IOAUDIODEFINES_H

#define kIOAudioDeviceClassName		"IOAudioDevice"
#define kIOAudioEngineClassName		"IOAudioEngine"
#define kIOAudioStreamClassName		"IOAudioStream"
#define kIOAudioPortClassName		"IOAudioPort"
#define kIOAudioControlClassName	"IOAudioControl"

/*!
 * @defined kIOAudioSampleRateKey
 * @abstract The key in the IORegistry for the IOAudioEngine sample rate attribute
 * @discussion This value is represented as an integer in samples per second.
 */
#define kIOAudioSampleRateKey				"IOAudioSampleRate"

#define kIOAudioSampleRateWholeNumberKey	"IOAudioSampleRateWholeNumber"
#define kIOAudioSampleRateFractionKey		"IOAudioSampleRateFraction"



/******
 *
 * IOAudioDevice  defines
 *
 *****/


/*!
 * @defined kIOAudioDeviceNameKey
 * @abstract The key in the IORegistry for the IOAudioDevice name attribute.
 */
#define kIOAudioDeviceNameKey				"IOAudioDeviceName"

#define kIOAudioDeviceShortNameKey			"IOAudioDeviceShortName"

/*!
 * @defined kIOAudioDeviceManufacturerNameKey
 * @abstract The key in the IORegistry for the IOAudioDevice manufacturer name attribute.
 */
#define kIOAudioDeviceManufacturerNameKey	"IOAudioDeviceManufacturerName"

#define kIOAudioDeviceLocalizedBundleKey	"IOAudioDeviceLocalizedBundle"

#define kIOAudioDeviceTransportTypeKey		"IOAudioDeviceTransportType"



/*****
 *
 * IOAudioEngine defines
 *
 *****/


 /*!
 * @defined kIOAudioEngineStateKey
 * @abstract The key in the IORegistry for the IOAudioEngine state atrribute
 * @discussion The value for this key may be one of: "Running", "Stopped" or "Paused".  Currently the "Paused"
 *  state is unimplemented.
 */
#define kIOAudioEngineStateKey		"IOAudioEngineState"

/*!
 * @defined kIOAudioEngineOutputSampleLatencyKey
 * @abstract The key in the IORegistry for the IOAudioEngine output sample latency key
 * @discussion 
 */
#define kIOAudioEngineOutputSampleLatencyKey		"IOAudioEngineOutputSampleLatency"

#define kIOAudioEngineInputSampleLatencyKey			"IOAudioEngineInputSampleLatency"

#define kIOAudioEngineSampleOffsetKey				"IOAudioEngineSampleOffset"

#define kIOAudioEngineNumSampleFramesPerBufferKey	"IOAudioEngineNumSampleFramesPerBuffer"

#define kIOAudioEngineCoreAudioPlugInKey			"IOAudioEngineCoreAudioPlugIn"

#define kIOAudioEngineNumActiveUserClientsKey		"IOAudioEngineNumActiveUserClients"

#define kIOAudioEngineUserClientActiveKey			"IOAudioEngineUserClientActive"

#define kIOAudioEngineGlobalUniqueIDKey				"IOAudioEngineGlobalUniqueID"

#define kIOAudioEngineDescriptionKey				"IOAudioEngineDescription"

/*****
 *
 * IOAudioStream defines
 *
 *****/
 
 
#define kIOAudioStreamIDKey					"IOAudioStreamID"
#define kIOAudioStreamDescriptionKey		"IOAudioStreamDescription"
#define kIOAudioStreamNumClientsKey			"IOAudioStreamNumClients"

/*!
 * @defined kIOAudioStreamDirectionKey
 * @abstract The key in the IORegistry for the IOAudioStream direction attribute.
 * @discussion The value for this key may be either "Output" or "Input".
 */
#define kIOAudioStreamDirectionKey				"IOAudioStreamDirection"

#define kIOAudioStreamStartingChannelIDKey		"IOAudioStreamStartingChannelID"
#define kIOAudioStreamStartingChannelNumberKey	"IOAudioStreamStartingChannelNumber"
#define kIOAudioStreamAvailableKey				"IOAudioStreamAvailable"

#define kIOAudioStreamFormatKey					"IOAudioStreamFormat"
#define kIOAudioStreamAvailableFormatsKey		"IOAudioStreamAvailableFormats"

#define kIOAudioStreamNumChannelsKey			"IOAudioStreamNumChannels"
#define kIOAudioStreamSampleFormatKey			"IOAudioStreamSampleFormat"

#define kIOAudioStreamNumericRepresentationKey	"IOAudioStreamNumericRepresentation"

#define kIOAudioStreamFormatFlagsKey			"IOAudioStreamFormatFlags"
#define kIOAudioStreamFramesPerPacketKey		"IOAudioStreamFramesPerPacket"
#define kIOAudioStreamBytesPerPacketKey			"IOAudioStreamBytesPerPacket"


#define kIOAudioStreamBitDepthKey				"IOAudioStreamBitDepth"
#define kIOAudioStreamBitWidthKey				"IOAudioStreamBitWidth"
    
#define kIOAudioStreamAlignmentKey				"IOAudioStreamAlignment"

#define kIOAudioStreamByteOrderKey				"IOAudioStreamByteOrder"

#define kIOAudioStreamIsMixableKey				"IOAudioStreamIsMixable"

#define kIOAudioStreamMinimumSampleRateKey		"IOAudioStreamMinimumSampleRate"
#define kIOAudioStreamMaximumSampleRateKey		"IOAudioStreamMaximumSampleRate"

#define kIOAudioStreamDriverTagKey				"IOAudioStreamDriverTag"

#define kIOAudioStreamTerminalTypeKey			"IOAudioStreamTerminalType"

/*****
 *
 * IOAudioPort defines
 *
 *****/
 
 
 /*!
 * @defined kIOAudioPortTypeKey
 * @abstract The key in the IORegistry for the IOAudioPort type attribute.
 * @discussion This is a driver-defined text attribute that may contain any type.
 *  Common types are defined as: "Speaker", "Headphones", "Microphone", "CD", "Line", "Digital", "Mixer", "PassThru".
 */
#define kIOAudioPortTypeKey			"IOAudioPortType"

/*!
 * @defined kIOAudioPortSubTypeKey
 * @abstract The key in the IORegistry for the IOAudioPort subtype attribute.
 * @discussion The IOAudioPort subtype is a driver-defined text attribute designed to complement the type
 *  attribute.
 */
#define kIOAudioPortSubTypeKey		"IOAudioPortSubType"

/*!
 * @defined kIOAudioPortNameKey
 * @abstract The key in the IORegistry for the IOAudioPort name attribute.
 */
#define kIOAudioPortNameKey			"IOAudioPortName"



/*****
 *
 * IOAudioControl defines
 *
 *****/
 
 
 /*!
 * @defined kIOAudioControlTypeKey
 * @abstract The key in the IORegistry for the IOAudioCntrol type attribute.
 * @discussion The value of this text attribute may be defined by the driver, however system-defined
 *  types recognized by the upper-level software are "Level", "Mute", "Selector".
 */
#define kIOAudioControlTypeKey		"IOAudioControlType"

#define kIOAudioControlSubTypeKey	"IOAudioControlSubType"

#define kIOAudioControlUsageKey		"IOAudioControlUsage"

#define kIOAudioControlIDKey		"IOAudioControlID"

/*!
 * @defined kIOAudioControlChannelIDKey
 * @abstract The key in the IORegistry for the IOAudioControl channel ID attribute
 * @discussion The value for this key is an integer which may be driver defined.  Default values for
 *  common channel types are provided in the following defines.
 */
#define kIOAudioControlChannelIDKey		"IOAudioControlChannelID"

#define kIOAudioControlChannelNumberKey	"IOAudioControlChannelNumber"

#define kIOAudioControlCoreAudioPropertyIDKey	"IOAudioControlCoreAudioPropertyID"
/*!
 * @defined kIOAudioControlChannelNameKey
 * @abstract The key in the IORegistry for the IOAudioControl name attribute.
 * @discussion This name should be a human-readable name for the channel(s) represented by the port.
 *  *** NOTE *** We really need to make all of the human-readable attributes that have potential to
 *  be used in a GUI localizable.  There will need to be localized strings in the kext bundle matching
 *  the text.
 */
#define kIOAudioControlChannelNameKey		"IOAudioControlChannelName"

/*!
 * @defined kIOAudioControlChannelNameAll
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for all channels.
 */
#define kIOAudioControlChannelNameAll		"All Channels"

/*!
 * @defined kIOAudioControlChannelNameLeft
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the left channel.
 */
#define kIOAudioControlChannelNameLeft		"Left"

/*!
 * @defined kIOAudioControlChannelNameRight
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the right channel.
 */
#define kIOAudioControlChannelNameRight		"Right"

/*!
 * @defined kIOAudioControlChannelNameCenter
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the center channel.
 */
#define kIOAudioControlChannelNameCenter	"Center"

/*!
 * @defined kIOAudioControlChannelNameLeftRear
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the left rear channel.
 */
#define kIOAudioControlChannelNameLeftRear	"LeftRear"

/*!
 * @defined kIOAudioControlChannelNameRightRear
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the right rear channel.
 */
#define kIOAudioControlChannelNameRightRear	"RightRear"

/*!
 * @defined kIOAudioControlChannelNameSub
 * @abstract The value for the kIOAudioControlChannelNameKey in the IORegistry representing
 *  the channel name for the sub/LFE channel.
 */
#define kIOAudioControlChannelNameSub		"Sub"

/*!
 * @defined kIOAudioControlValueKey
 * @abstract The key in the IORegistry for the IOAudioControl value attribute.
 * @discussion The value returned by this key is a 32-bit integer representing the current value of the IOAudioControl.
 */
#define kIOAudioControlValueKey				"IOAudioControlValue"

/*!
 * @defined kIOAudioLevelControlMinValueKey
 * @abstract The key in the IORegistry for the IOAudioControl minimum value attribute.
 * @discussion The value returned by this key is a 32-bit integer representing the minimum value for the IOAudioControl.
 *  This is currently only valid for Level controls or other driver-defined controls that have a minimum and maximum
 *  value.
 */
#define kIOAudioLevelControlMinValueKey		"IOAudioLevelControlMinValue"

/*!
 * @defined kIOAudioLevelControlMaxValueKey
 * @abstract The key in the IORegistry for the IOAudioControl maximum value attribute.
 * @discussion The value returned by this key is a 32-bit integer representing the maximum value for the IOAudioControl.
 *  This is currently only valid for Level controls or other driver-defined controls that have a minimum and maximum
 *  value.
 */
#define kIOAudioLevelControlMaxValueKey		"IOAudioLevelControlMaxValue"

/*!
 * @defined kIOAudioLevelControlMinDBKey
 * @abstract The key in the IORgistry for the IOAudioControl minimum db value attribute.
 * @discussion The value returned by this key is a fixed point value in 16.16 format represented as a 32-bit
 *  integer.  It represents the minimum value in db for the IOAudioControl.  This value matches the minimum
 *  value attribute.  This is currently valid for Level controls or other driver-defined controls that have a
 *  minimum and maximum db value.
 */
#define kIOAudioLevelControlMinDBKey		"IOAudioLevelControlMinDB"

/*!
 * @defined kIOAudioLevelControlMaxDBKey
 * @abstract The key in the IORgistry for the IOAudioControl maximum db value attribute.
 * @discussion The value returned by this key is a fixed point value in 16.16 format represented as a 32-bit
 *  integer.  It represents the maximum value in db for the IOAudioControl.  This value matches the maximum
 *  value attribute.  This is currently valid for Level controls or other driver-defined controls that have a
 *  minimum and maximum db value.
 */
#define kIOAudioLevelControlMaxDBKey		"IOAudioLevelControlMaxDB"

#define kIOAudioLevelControlRangesKey		"IOAudioLevelControlRanges"

#define kIOAudioSelectorControlAvailableSelectionsKey	"IOAudioSelectorControlAvailableSelections"
#define kIOAudioSelectorControlSelectionValueKey		"IOAudioSelectorControlSelectionValue"
#define kIOAudioSelectorControlSelectionDescriptionKey	"IOAudioSelectorControlSelectionDescriptionKey"

#endif /* _IOAUDIODEFINES_H */
