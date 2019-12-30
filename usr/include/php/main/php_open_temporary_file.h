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
   | Author: Zeev Suraski <zeev@zend.com>                                 |
   +----------------------------------------------------------------------+
*/

#ifndef PHP_OPEN_TEMPORARY_FILE_H
#define PHP_OPEN_TEMPORARY_FILE_H

PHPAPI FILE *php_open_temporary_file(const char *dir, const char *pfx, char **opened_path_p TSRMLS_DC);
PHPAPI int php_open_temporary_fd(const char *dir, const char *pfx, char **opened_path_p TSRMLS_DC);
PHPAPI const char* php_get_temporary_directory(void);

#endif /* PHP_OPEN_TEMPORARY_FILE_H */
