/*
   +----------------------------------------------------------------------+
   | PHP version 4.0                                                      |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2001 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Jim Winstead (jimw@php.net)                                  |
   +----------------------------------------------------------------------+
*/

/* $Id: base64.h,v 1.1.1.3 2001/07/19 00:20:06 zarzycki Exp $ */

#ifndef BASE64_H
#define BASE64_H

PHP_FUNCTION(base64_decode);
PHP_FUNCTION(base64_encode);

extern unsigned char *php_base64_encode(const unsigned char *, int, int *);
extern unsigned char *php_base64_decode(const unsigned char *, int, int *);

#endif /* BASE64_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 */
