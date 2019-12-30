/*
 * Copyright (c) 1998-2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __OPEN_SOURCE__
/*
 *
 *	$Id: IOUSBLog.h,v 1.20.12.5 2004/02/20 21:15:12 nano Exp $
 *
 *	$Log: IOUSBLog.h,v $
 *	Revision 1.20.12.5  2004/02/20 21:15:12  nano
 *	Sigh -- logging again
 *	
 *	Revision 1.20.12.4  2004/02/20 21:14:15  nano
 *	Really fix 3548954
 *	
 *	Revision 1.20.12.3  2004/02/20 05:02:36  nano
 *	remve logging
 *	
 *	Revision 1.20.12.2  2004/02/20 05:01:08  nano
 *	Merge fix for rdar://3548954:don't lose the data toggle when there are no transactions to remove
 *	
 *	Revision 1.20.12.1  2003/11/10 19:47:30  nano
 *	Return the fix for 3290613 to the original strategy of doing it in stop:ports, as willTerminate is called with the gate held so we were deadlocking when trying to disable the port
 *	
 *	Revision 1.20  2003/09/05 22:38:50  nano
 *	Removed logging --set to Production
 *	
 *	Revision 1.19  2003/08/20 19:41:40  nano
 *	
 *	Bug #:
 *	New version's of Nima's USB Prober (2.2b17)
 *	3382540  Panther: Ejecting a USB CardBus card can freeze a machine
 *	3358482  Device Busy message with Modems and IOUSBFamily 201.2.14 after sleep
 *	3385948  Need to implement device recovery on High Speed Transaction errors to full speed devices
 *	3377037  USB EHCI: returnTransactions can cause unstable queue if transactions are aborted
 *	
 *	Also, updated most files to use the id/log functions of cvs
 *	
 *	Submitted by: nano
 *	Reviewed by: rhoads/barryt/nano
 *	
 */
#endif
#ifndef _IOKIT_IOUSBLOG_H
#define _IOKIT_IOUSBLOG_H

#include 	<IOKit/IOService.h>
#include	<IOKit/IOLib.h>


#ifdef	__cplusplus
	extern "C" {
#endif

// USB Specific defines
#define USBLog( LEVEL, ARGS...)		KernelDebugLogTag( LEVEL, 'USBF', ## ARGS )
#define USBError( LEVEL, ARGS...)	KernelDebugLogInternal( ( LEVEL ), 'USBF', ## ARGS )



// Possible Debug levels. If DEBUG_LEVEL is set to DEBUG_LEVEL_PRODUCTION, all debug logs will be 
// stripped of the final code. 

#define	DEBUG_LEVEL_PRODUCTION			0
#define	DEBUG_LEVEL_DEVELOPMENT			1
#define	DEBUG_LEVEL_ALPHA			2
#define	DEBUG_LEVEL_BETA			3
#define	DEBUG_LEVEL_FINAL			DEBUG_LEVEL_PRODUCTION

// Allow clients to define their own debug level.

#if( !defined( DEBUG_LEVEL ) )
	#define	DEBUG_LEVEL			DEBUG_LEVEL_FINAL
#endif

// Index for user client methods
//
enum
{
    kUSBControllerUserClientOpen = 0,
    kUSBControllerUserClientClose,
    kUSBControllerUserClientEnableLogger,
    kUSBControllerUserClientSetDebuggingLevel,
    kUSBControllerUserClientSetDebuggingType,
    kUSBControllerUserClientGetDebuggingLevel,
    kUSBControllerUserClientGetDebuggingType,
    kUSBControllerUserClientSetTestMode,
    kNumUSBControllerMethods
};

// Info Debug Output Types.

typedef UInt32		KernelDebuggingOutputType;
enum
{
	kKernelDebugOutputIOLogType		= 0x00000001, 
	kKernelDebugOutputKextLoggerType	= 0x00000002
};


// Info Debug levels.

typedef UInt32		KernelDebugLevel;
enum
{
	kKernelDebugInfoLevel 		= 1000, 
	kKernelDebugRareInfoLevel	= 2000, 
	kKernelDebugAllowedErrorLevel	= 3000, 
	kKernelDebugAssertLevel 	= 4000, 
	kKernelDebugRequireLevel	= 5000, 
	kKernelDebugErrorLevel		= 6000, 
	kKernelDebugCriticalErrorLevel	= 7000, 
	kKernelDebugTragicErrorLevel	= 8000, 
	kKernelDebugAnyLevel		= 0
};

// Function prototypes.

void			KernelDebugSetLevel( KernelDebugLevel inLevel );
KernelDebugLevel	KernelDebugGetLevel();
void			KernelDebugSetOutputType( KernelDebuggingOutputType inType );
KernelDebuggingOutputType	KernelDebugGetOutputType();
IOReturn 		KernelDebugFindKernelLogger();
void			KernelDebugEnable( bool enable );

//	Yes, you can call this directly. But, why? If you use the macros declared below, such as
//	KernelIOLog, you get the benefit of having your logs compiled out when you set the
//	DEBUG_LEVEL to production mode and recompile. Dude. Sweet. What's mine say?

void			KernelDebugLogInternal( KernelDebugLevel inLevel, UInt32 inTag, char const *inFormatString, ... );
void 			KernelDebugLogDataInternal( UInt32 inLevel,  UInt32 inTag, void *buffer, UInt32 byteCount, bool preBuffer);

// Handy macros.

#define REQUIRE_NO_ERR_PRINTF( VALUE, LABEL, ARGS... )							\
	if( VALUE != kIOReturnSuccess )									\
	{												\
		KernelDebugLogInternal( kDebugInfoLevel, 'BluD', ## ARGS );				\
		goto LABEL;										\
	}

#define REQUIRE_PRINTF( TEST, LABEL, ARGS... )								\
	do												\
	{												\
		if( !( TEST ) )										\
		{											\
			KernelDebugLogInternal( kDebugInfoLevel, 'BluD',  ## ARGS );			\
			goto LABEL;									\
		}											\
	} while( false )

// Some macros to call the debugging outputs. We'll strip out the debug logs if we are production code.

#if DEBUG_LEVEL != DEBUG_LEVEL_PRODUCTION
	#define	KernelDebugLog( LEVEL, ARGS... )			KernelDebugLogInternal( ( LEVEL ), 'KDbg', ## ARGS )
	#define	KernelDebugLogTag( LEVEL, TAG, ARGS... )		KernelDebugLogInternal( ( LEVEL ), ( TAG ),  ## ARGS )
	#define KernelDebugLogData( LEVEL, TAG, BUFFER, SIZE, HOLD)	KernelDebugLogDataInternal( ( LEVEL ), ( TAG ), ( BUFFER ), ( SIZE ), ( HOLD ))
#else
	#define	KernelDebugLog( LEVEL, ARGS... )
	#define	KernelDebugLogTag( LEVEL, TAG, ARGS... )
	#define KernelDebugLogData( LEVEL, TAG, BUFFER, SIZE, HOLD)
#endif


#ifdef	__cplusplus
	}
        
//================================================================================================
//   Forward declarations
//================================================================================================
class com_apple_iokit_KLogClient;

//================================================================================================
//   Defines
//================================================================================================
#define kLogKextName 	"com_apple_iokit_KLog"
#define MAXUSERS 	5

//================================================================================================
//   Custom Types
//================================================================================================

typedef UInt32 KLogLevel;
typedef UInt32 KLogTag;

//================================================================================================
//   com_apple_iokit_KLog
//================================================================================================

class com_apple_iokit_KLog : public IOService
{

    OSDeclareDefaultStructors(com_apple_iokit_KLog)

    com_apple_iokit_KLogClient *	mClientPtr[MAXUSERS+1];

    unsigned char *			mMsgBuffer;
    UInt8 				mClientCount;
    UInt8 				mMsgSize;
    bool 				mErrFlag;
    struct timeval *			mTimeVal;
    IOLock *				mLogLock;
    
public:

    static com_apple_iokit_KLog	*	logger;
    
    virtual bool 			init(OSDictionary *dictionary = 0);
    virtual void 			free(void);
    
    virtual IOService *			probe(IOService *provider, SInt32 *score);
    virtual bool 			start(IOService *provider);
    virtual void 			stop(IOService *provider);
    virtual IOReturn 			newUserClient( task_t owningTask, void * securityID,
                                                UInt32 type, IOUserClient ** handler );

    virtual SInt8			Log( KLogLevel level, KLogTag tag, const char *format, ... );
    virtual SInt8			vLog( KLogLevel level, KLogTag tag, const char *format, va_list in_va_list );
	
    void 				closeChild(com_apple_iokit_KLogClient *ptr);
    void 				setErr(bool set);
    
};

#define kMaxStatusBufSize	(8*1024)


class IOUSBLog : public IOService
{
    OSDeclareAbstractStructors(IOUSBLog)

private:
public:
    virtual bool	init( OSDictionary * dictionary = 0 );
    static IOUSBLog	*usblog();
    virtual void 	AddStatusLevel (UInt32 level, UInt32 ref, char *status, UInt32 value);
    virtual void	AddStatus(char *message);
    virtual void	AddStatus(UInt32 level, char *message);
    virtual void 	USBLogPrintf(UInt32 level, char *format,...);

};


#endif
#endif /* ! _IOKIT_IOUSBLOG_H */

