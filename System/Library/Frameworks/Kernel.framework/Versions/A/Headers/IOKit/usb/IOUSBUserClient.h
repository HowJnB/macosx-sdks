/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.2 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.  
 * Please see the License for the specific language governing rights and 
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef _IOKIT_IOUSBUSERCLIENT_H
#define _IOKIT_IOUSBUSERCLIENT_H

// these are the new User Client method names    
enum {
    kUSBDeviceUserClientOpen,
    kUSBDeviceUserClientClose,
    kUSBDeviceUserClientSetConfig,
    kUSBDeviceUserClientGetConfig,
    kUSBDeviceUserClientGetConfigDescriptor,
    kUSBDeviceUserClientGetFrameNumber,
    kUSBDeviceUserClientDeviceRequestOut,
    kUSBDeviceUserClientDeviceRequestIn,
    kUSBDeviceUserClientDeviceRequestOutOOL,
    kUSBDeviceUserClientDeviceRequestInOOL,
    kUSBDeviceUserClientCreateInterfaceIterator,
    kUSBDeviceUserClientResetDevice,
    // new with 1.8.2
    kUSBDeviceUserClientSuspend,
    kUSBDeviceUserClientAbortPipeZero,
    // new with 1.8.7
    kUSBDeviceUserClientReEnumerateDevice,
    kNumUSBDeviceMethods
    };

enum {
    kUSBDeviceUserClientSetAsyncPort,
    kUSBDeviceUserClientDeviceAsyncRequestOut,
    kUSBDeviceUserClientDeviceAsyncRequestIn,
    kNumUSBDeviceAsyncMethods
    };

enum {
    kUSBInterfaceUserClientOpen,
    kUSBInterfaceUserClientClose,
    kUSBInterfaceUserClientGetDevice,
    kUSBInterfaceUserClientSetAlternateInterface,
    kUSBInterfaceUserClientGetFrameNumber,
    kUSBInterfaceUserClientGetPipeProperties,
    kUSBInterfaceUserClientReadPipe,
    kUSBInterfaceUserClientReadPipeOOL,
    kUSBInterfaceUserClientWritePipe,
    kUSBInterfaceUserClientWritePipeOOL,
    kUSBInterfaceUserClientGetPipeStatus,
    kUSBInterfaceUserClientAbortPipe,
    kUSBInterfaceUserClientResetPipe,
    kUSBInterfaceUserClientSetPipeIdle,
    kUSBInterfaceUserClientSetPipeActive,
    kUSBInterfaceUserClientClearPipeStall,
    kUSBInterfaceUserClientControlRequestOut,
    kUSBInterfaceUserClientControlRequestIn,
    kUSBInterfaceUserClientControlRequestOutOOL,
    kUSBInterfaceUserClientControlRequestInOOL,
    kNumUSBInterfaceMethods
    };


enum {
    kUSBInterfaceUserClientSetAsyncPort,
    kUSBInterfaceUserClientControlAsyncRequestOut,
    kUSBInterfaceUserClientControlAsyncRequestIn,
    kUSBInterfaceUserClientAsyncReadPipe,
    kUSBInterfaceUserClientAsyncWritePipe,
    kUSBInterfaceUserClientReadIsochPipe,
    kUSBInterfaceUserClientWriteIsochPipe,
    kNumUSBInterfaceAsyncMethods
    };

#if KERNEL
#include <IOKit/IOService.h>

//
// This class is used to add an IOCFPlugInTypes dictionary entry to a provider's
// property list, thus providing a tie between hardware and a CFBundle at hardware
// load time
//
class IOUSBUserClientInit : public IOService 
{
    OSDeclareDefaultStructors(IOUSBUserClientInit);

public:
	virtual IOService*	probe(IOService* provider, SInt32* score) ;
	virtual bool		start(IOService*	provider) ;
	virtual bool		init(OSDictionary*	propTable) ;
	virtual void		stop(IOService*		provider) ;
	
protected:
	virtual void		mergeProperties(OSObject* dest, OSObject* src) ;
};

#endif // KERNEL

#endif /* ! _IOKIT_IOUSBUSERCLIENT_H */

