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
   | Author: Paul Panotzki - Bunyip Information Systems                   |
   +----------------------------------------------------------------------+
*/

/* $Id: microtime.h,v 1.10.2.1 2002/12/31 16:35:32 sebastian Exp $ */

#ifndef MICROTIME_H
#define MICROTIME_H

#ifdef HAVE_GETTIMEOFDAY
PHP_FUNCTION(microtime);
PHP_FUNCTION(gettimeofday);
#endif
#ifdef HAVE_GETRUSAGE
PHP_FUNCTION(getrusage);
#endif

#endif /* MICROTIME_H */
