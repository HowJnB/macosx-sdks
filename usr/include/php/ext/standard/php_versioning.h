/* 
   +----------------------------------------------------------------------+
   | PHP Version 4                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2003 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Stig S�ther Bakken <ssb@fast.no>                             |
   +----------------------------------------------------------------------+
*/

/* $Id: php_versioning.h,v 1.5.8.1 2002/12/31 16:35:33 sebastian Exp $ */

#ifndef PHP_VERSIONING_H
#define PHP_VERSIONING_H

#include "ext/standard/basic_functions.h"

PHPAPI char *php_canonicalize_version(const char *);
PHPAPI int php_version_compare(const char *, const char *);
PHP_FUNCTION(version_compare);

#endif
