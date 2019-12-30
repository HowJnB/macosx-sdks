/*
     File:       CFNetwork/CFFTPStream.h
 
     Contains:   CoreFoundation FTP stream header
 
     Version:    CFNetwork-71.9~1
 
     Copyright:  � 2001-2003 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __CFFTPSTREAM__
#define __CFFTPSTREAM__

#ifndef __CFSTREAM__
#include <CoreFoundation/CFStream.h>
#endif



#include <AvailabilityMacros.h>

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  kCFStreamErrorDomainFTP
 *  
 *  Discussion:
 *    Result code returned by FTP server
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const SInt32 kCFStreamErrorDomainFTP                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
FTP Stream Property keys.  These keys can be passed to the stream
property "set/get" functions, such as CFReadStreamSetProperty/
CFReadStreamCopyProperty, or to a CFDictionary creator or an item
accessor/mutator.  The comment before each key declaration (treated
as definition) indicates the value type of the property.
*/


/*
 *  kCFStreamPropertyFTPUserName
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations.  CFString
 *    type to hold login user name.  Don't set this property if you
 *    want anonymous FTP.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPUserName                AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPPassword
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations. CFString
 *    type to hold login password.  Don't set this property if you want
 *    anonymous FTP.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPPassword                AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPUsePassiveMode
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations. CFBoolean
 *    type. kCFBooleanTrue means use passive mode, kCFBooleanFalse
 *    otherwise
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPUsePassiveMode          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPResourceSize
 *  
 *  Discussion:
 *    Stream property key, for read stream copy operations.  CFNumber
 *    of kCFNumberLongLongType to hold resource size in bytes.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPResourceSize            AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPFetchResourceInfo
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations.  CFBoolean
 *    type.  TRUE means that resource info, such as size, must be
 *    provided before download starts at higher cost.  Don't set if
 *    resource size/other info is unnecessary.  Initially, only
 *    resource size is implemented.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPFetchResourceInfo       AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPFileTransferOffset
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations.  CFNumber
 *    of kCFNumberLongLongType for the file offset to start transfer at.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPFileTransferOffset      AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPAttemptPersistentConnection
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations.  CFBoolean
 *    type.  TRUE by default, set to FALSE to avoid reusing existing
 *    server connections.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPAttemptPersistentConnection AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPProxy
 *  
 *  Discussion:
 *    Stream property key, for both set and copy operations. 
 *    CFDictionary type that holds key-value pairs of proxy dictionary.
 *     The dictionary returned by SystemConfiguration can also be
 *    passed directly as the value.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPProxy                   AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPProxyHost
 *  
 *  Discussion:
 *    Stream property key or FTP Proxy dictionary key, for both set and
 *    copy operations.  It matches kSCPropNetProxiesFTPProxy defined in
 *    SCSchemaDefinitions.h.  CFString for proxy server host name. 
 *    This property can be set and copied individually or via a
 *    CFDictionary.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPProxyHost               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFStreamPropertyFTPProxyPort
 *  
 *  Discussion:
 *    Stream property key or FTP Proxy dictionary key, for both set and
 *    copy operations.  It matches kSCPropNetProxiesFTPPort defined in
 *    SCSchemaDefinitions.h.  CFNumber of kCFNumberIntType for proxy
 *    server port number.  This property can be set and copied
 *    individually or via a CFDictionary.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPProxyPort               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;

/*
 *  kCFStreamPropertyFTPProxyUser
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPProxyUser               AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
/*
 *  kCFStreamPropertyFTPProxyPassword
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFStreamPropertyFTPProxyPassword           AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
CFDictionary keys for resource information.  The information is
extracted from a line of the directory list by function
CFFTPCreateParsedResourceListing.
*/


/*
 *  kCFFTPResourceMode
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFNumber to hold the
 *    resource access permission defined in sys/types.h.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceMode                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceName
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFString that holds
 *    the resource name.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceName                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceOwner
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFString that holds
 *    the resource owner's name.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceOwner                         AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceGroup
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFString to hold the
 *    name of the group that shares the resource.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceGroup                         AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceLink
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFString to hold
 *    symbolic link information.  If the item is a symbolic link the
 *    string will contain the path to the item the link references.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceLink                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceSize
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFNumber of
 *    kCFNumberLongLongType to hold the resource length in bytes.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceSize                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceType
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFNumber to hold the
 *    resource type as defined in sys/dirent.h.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceType                          AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  kCFFTPResourceModDate
 *  
 *  Discussion:
 *    CFDictinary key, for get value operation.  CFDate to hold the
 *    last modification date and time information.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern const CFStringRef kCFFTPResourceModDate                       AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;


/*
 *  CFReadStreamCreateWithFTPURL()
 *  
 *  Discussion:
 *    Create an FTP read stream for downloading operation from an FTP
 *    URL. If the URL refers to a directory, the stream is a filtered
 *    line-at-a-time read stream corresponding to the listing results
 *    provided by the server. If it's a file, then the stream is a
 *    regular read stream providing the data for that file.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    alloc:
 *      A pointer to the CFAllocator which should be used to allocate
 *      memory for the CF read stream and its storage for values. If
 *      this reference is not a valid CFAllocator, the behavior is
 *      undefined.
 *    
 *    ftpURL:
 *      A pointer to a CFURL structure created by CFURLCreateWithString
 *      function.  If this parameter is not a pointer to a valid CFURL
 *      structure, the behavior is undefined.
 *  
 *  Result:
 *    A pointer to the CF read stream created, or NULL if failed. It is
 *    caller's responsibilty to release the memory allocated for the
 *    read stream.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFReadStreamRef 
CFReadStreamCreateWithFTPURL(
  CFAllocatorRef   alloc,
  CFURLRef         ftpURL)                                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



/*
 *  CFFTPCreateParsedResourceListing()
 *  
 *  Discussion:
 *    Parse a line of file or folder listing of Unix format, and store
 *    the extracted result in a CFDictionary.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    alloc:
 *      A pointer to the CFAllocator which should be used to allocate
 *      memory for the CFDictionary to hold resource info.  If this
 *      reference is not a valid CFAllocator, the behavior is undefined.
 *    
 *    buffer:
 *      A pointer to a buffer that may hold lines of resource listing,
 *      but only the first line starting from buffer[0] will be parsed
 *      each call.
 *    
 *    bufferLength:
 *      The maximum buffer size in bytes started from the location
 *      pointed by "buffer."
 *    
 *    parsed:
 *      A pointer to a CFDictionary pointer.  The dictionary holds the
 *      extracted resource information.  When parsing fails, a NULL
 *      pointer will be returned.  It is caller's responsibilty to
 *      release the memory allocated for the dictionary.
 *  
 *  Result:
 *    The number of bytes consumed from buffer, 0 if there are not
 *    enough bytes, or -1 if a parse failure occurs.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFIndex 
CFFTPCreateParsedResourceListing(
  CFAllocatorRef     alloc,
  const UInt8 *      buffer,
  CFIndex            bufferLength,
  CFDictionaryRef *  parsed)                                  AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



/*
 *  CFWriteStreamCreateWithFTPURL()
 *  
 *  Discussion:
 *    Create an FTP write stream for uploading operation to a FTP URL.
 *    If the URL specifies a directory, the open will be followed by a
 *    close event/state and the directory will have been created. 
 *    Intermediary directory structure is not created.
 *  
 *  Mac OS X threading:
 *    Thread safe
 *  
 *  Parameters:
 *    
 *    alloc:
 *      A pointer to the CFAllocator which should be used to allocate
 *      memory for the CF read stream and its storage for values. If
 *      this reference is not a valid CFAllocator, the behavior is
 *      undefined.
 *    
 *    ftpURL:
 *      A pointer to a CFURL structure created by CFURLCreateWithString
 *      function.  If this parameter is not a pointer to a valid CFURL
 *      structure, the behavior is undefined.
 *  
 *  Result:
 *    A pointer to the CF write stream created, or NULL if failed. It
 *    is caller's responsibilty to release the memory allocated for the
 *    write stream.
 *  
 *  Availability:
 *    Mac OS X:         in version 10.3 and later in CoreServices.framework
 *    CarbonLib:        not available
 *    Non-Carbon CFM:   not available
 */
extern CFWriteStreamRef 
CFWriteStreamCreateWithFTPURL(
  CFAllocatorRef   alloc,
  CFURLRef         ftpURL)                                    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;



#ifdef __cplusplus
}
#endif

#endif /* __CFFTPSTREAM__ */

