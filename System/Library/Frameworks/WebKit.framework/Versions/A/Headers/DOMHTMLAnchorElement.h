/*
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Samuel Weinig <sam.weinig@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import <WebKit/DOMHTMLElement.h>

@class NSString;
@class NSURL;

NS_CLASS_AVAILABLE_MAC(10_4)
@interface DOMHTMLAnchorElement : DOMHTMLElement
@property (copy) NSString *charset;
@property (copy) NSString *coords;
@property (copy) NSString *hreflang;
@property (copy) NSString *name;
@property (copy) NSString *rel;
@property (copy) NSString *rev;
@property (copy) NSString *shape;
@property (copy) NSString *target;
@property (copy) NSString *type;
@property (copy) NSString *accessKey NS_DEPRECATED_MAC(10_4, 10_8);
@property (readonly, copy) NSString *text NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSURL *absoluteLinkURL NS_AVAILABLE_MAC(10_5);
@property (copy) NSString *href;
@property (readonly, copy) NSString *protocol NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *host NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *hostname NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *port NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *pathname NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *search NS_AVAILABLE_MAC(10_5);
@property (readonly, copy) NSString *hashName NS_AVAILABLE_MAC(10_5);
@end
