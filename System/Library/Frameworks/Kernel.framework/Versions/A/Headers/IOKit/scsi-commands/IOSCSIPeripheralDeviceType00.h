/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
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

#ifndef _IOKIT_IO_SCSI_PERIPHERAL_DEVICE_TYPE_OO_H_
#define _IOKIT_IO_SCSI_PERIPHERAL_DEVICE_TYPE_OO_H_

#if defined(KERNEL) && defined(__cplusplus)

// General IOKit headers
#include <IOKit/IOLib.h>

// SCSI Command set related IOKit headers
#include <IOKit/scsi-commands/IOSCSIBlockCommandsDevice.h>

class IOSCSIPeripheralDeviceType00 : public IOSCSIBlockCommandsDevice
{
	
	OSDeclareDefaultStructors ( IOSCSIPeripheralDeviceType00 )
	
protected:
    // Reserve space for future expansion.
    struct IOSCSIPeripheralDeviceType00ExpansionData { };
    IOSCSIPeripheralDeviceType00ExpansionData *fIOSCSIPeripheralDeviceType00Reserved;

public:
	
    bool			init ( OSDictionary * propTable );
  	
	virtual bool	start ( IOService * provider );
    
    virtual void	stop ( IOService *  provider );
	
private:
	// Space reserved for future expansion.
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 1 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 2 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 3 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 4 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 5 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 6 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 7 );
    OSMetaClassDeclareReservedUnused( IOSCSIPeripheralDeviceType00, 8 );
};

#endif	/* defined(KERNEL) && defined(__cplusplus) */

#endif	/* _IOKIT_IO_SCSI_PERIPHERAL_DEVICE_TYPE_OO_H_ */