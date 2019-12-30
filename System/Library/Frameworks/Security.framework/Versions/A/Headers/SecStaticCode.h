/*
 * Copyright (c) 2006 Apple Computer, Inc. All Rights Reserved.
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

/*!
	@header SecStaticCode
	SecStaticCode represents the Code Signing identity of code in the file system.
	This includes applications, tools, frameworks, plugins,	scripts, and so on.
	
	Normally, each SecCode has a specific SecStaticCode that holds its static signing
	data. Informally, that is the SecStaticCode the SecCode "was made from" (by its host).
	There is however no viable link in the other direction - given a SecStaticCode,
	it is not possible to find, enumerate, or control any SecCode that originated from it.
*/
#ifndef _H_SECSTATICCODE
#define _H_SECSTATICCODE

#include <Security/CSCommon.h>

#ifdef __cplusplus
extern "C" {
#endif


/*!
	@function SecStaticCodeGetTypeID
	Returns the type identifier of all SecStaticCode instances.
*/
CFTypeID SecStaticCodeGetTypeID(void);


/*!
	@function SecStaticCodeCreateWithPath
	Given a path to a file system object, create a SecStaticCode object representing
	the code at that location, if possible. Such a SecStaticCode is not inherently
	linked to running code in the system.
	
	It is possible to create a SecStaticCode object from an unsigned code object.
	Most uses of such an object will return the errSecCSUnsigned error. However,
	SecCodeCopyPath and SecCodeCopySigningInformation can be safely applied to such objects.

	@param path A path to a location in the file system. Only file:// URLs are
	currently supported. For bundles, pass a URL to the root directory of the
	bundle. For single files, pass a URL to the file. If you pass a URL to the
	main executable of a bundle, the bundle as a whole will be generally recognized.
	@param flags Optional flags. Pass kSecCSDefaultFlags for standard behavior.
	@param staticCode On successful return, contains a reference to the StaticCode object
	representing the code at path. Unchanged on error.
	@result Upon success, noErr. Upon error, an OSStatus value documented in
	CSCommon.h or certain other Security framework headers.
*/
OSStatus SecStaticCodeCreateWithPath(CFURLRef path, SecCSFlags flags, SecStaticCodeRef *staticCode);


/*!
	@function SecStaticCodeCheckValidity
	Performs static validation on the given SecStaticCode object. The call obtains and
	verifies the signature on the code object. It checks the validity of all
	sealed components (including resources, if any). It validates the code against
	a SecRequirement if one is given. The call succeeds if all these conditions
	are satisfactory. It fails otherwise.
	
	This call is only secure if the code is not subject to concurrent modification,
	and the outcome is only valid as long as the code is unmodified thereafter.
	Consider this carefully if the underlying file system has dynamic characteristics,
	such as a network file system, union mount, FUSE, etc.

	@param staticCode The code object to be validated.
	@param flags Optional flags. Pass kSecCSDefaultFlags for standard behavior.
	
	@constant kSecCSCheckAllArchitectures
	For multi-architecture (universal) Mach-O programs, validate all architectures
	included. By default, only the native architecture is validated.
	@constant kSecCSNoDnotValidateExecutable
	Do not validate the contents of the main executable. This is normally done.
	@constant kSecCSNoNotValidateResources
	Do not validate the presence and contents of all bundle resources (if any).
	By default, a mismatch in any bundle resource causes validation to fail.
	
	@param requirement On optional code requirement specifying additional conditions
	the staticCode object must satisfy to be considered valid. If NULL, no additional
	requirements are imposed.
	@param errors An optional pointer to a CFErrorRef variable. If the call fails
	(something other than noErr is returned), and this argument is non-NULL,
	a CFErrorRef is stored there further describing the nature and circumstances
	of the failure. The caller must CFRelease() this error object when done with it.
	@result If validation succeeds, noErr. If validation fails, an OSStatus value
	documented in CSCommon.h or certain other Security framework headers.
*/
enum {
	kSecCSCheckAllArchitectures = 1 << 0,
	kSecCSDoNotValidateExecutable = 1 << 1,
	kSecCSDoNotValidateResources = 1 << 2,
	kSecCSBasicValidateOnly = kSecCSDoNotValidateExecutable | kSecCSDoNotValidateResources
};

OSStatus SecStaticCodeCheckValidity(SecStaticCodeRef staticCode, SecCSFlags flags,
	SecRequirementRef requirement);

OSStatus SecStaticCodeCheckValidityWithErrors(SecStaticCodeRef staticCode, SecCSFlags flags,
	SecRequirementRef requirement, CFErrorRef *errors);


#ifdef __cplusplus
}
#endif

#endif //_H_SECSTATICCODE
