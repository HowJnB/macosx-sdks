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

#ifndef __IOLOCALCONFIGDIRECTORY_H__
#define __IOLOCALCONFIGDIRECTORY_H__

#include <libkern/c++/OSObject.h>
#include <IOKit/IOReturn.h>
#include <IOKit/firewire/IOFWRegs.h>
#include <IOKit/firewire/IOConfigDirectory.h>

class OSArray;
class OSData;

class IOLocalConfigDirectory : public IOConfigDirectory
{
    OSDeclareDefaultStructors(IOLocalConfigDirectory);

protected:
    OSArray *fEntries;	// Entries for this directory.
    OSData *fROM;	// Local ROM, if compiled.
    UInt32 fHeader;	// Num entries and CRC.
    
/*! @struct ExpansionData
    @discussion This structure will be used to expand the capablilties of the class in the future.
    */    
    struct ExpansionData { };

/*! @var reserved
    Reserved for future use.  (Internal use only)  */
    ExpansionData *reserved;

    virtual bool init();
    virtual void free();

    virtual const UInt32 *getBase();
    virtual IOConfigDirectory *getSubDir(int start, int type);

public:
    static IOLocalConfigDirectory *create();

    /*!
        @function update
        makes sure that the ROM has at least the specified capacity,
        and that the ROM is uptodate from its start to at least the
        specified quadlet offset.
        @result kIOReturnSuccess if the specified offset is now
        accessable at romBase[offset].
    */
    virtual IOReturn update(UInt32 offset, const UInt32 *&romBase);

    virtual IOReturn compile(OSData *rom);
    virtual IOReturn addEntry(int key, UInt32 value, OSString *desc = NULL);
    virtual IOReturn addEntry(int key, IOLocalConfigDirectory *value,
                              OSString *desc = NULL);
    virtual IOReturn addEntry(int key, OSData *value, OSString *desc = NULL);
    virtual IOReturn addEntry(int key, FWAddress value, OSString *desc = NULL);
    virtual IOReturn removeSubDir(IOLocalConfigDirectory *value);
    const OSArray *getEntries() const
    			{ return fEntries; };

private:
    OSMetaClassDeclareReservedUnused(IOLocalConfigDirectory, 0);
    OSMetaClassDeclareReservedUnused(IOLocalConfigDirectory, 1);
    OSMetaClassDeclareReservedUnused(IOLocalConfigDirectory, 2);
};

#endif /* __IOLOCALCONFIGDIRECTORY_H__ */
