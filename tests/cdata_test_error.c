/*
 * Library error functions test program
 *
 * Copyright (C) 2006-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "cdata_test_libcdata.h"
#include "cdata_test_libcerror.h"
#include "cdata_test_macros.h"
#include "cdata_test_unused.h"

/* Tests the libcdata_error_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_error_free(
     void )
{
	/* Test invocation of function only
	 */
	libcdata_error_free(
	 NULL );

	return( 1 );
}

/* Tests the libcdata_error_fprint function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_error_fprint(
     void )
{
	/* Test invocation of function only
	 */
	libcdata_error_fprint(
	 NULL,
	 NULL );

	return( 1 );
}

/* Tests the libcdata_error_sprint function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_error_sprint(
     void )
{
	/* Test invocation of function only
	 */
	libcdata_error_sprint(
	 NULL,
	 NULL,
	 0 );

	return( 1 );
}

/* Tests the libcdata_error_backtrace_fprint function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_error_backtrace_fprint(
     void )
{
	/* Test invocation of function only
	 */
	libcdata_error_backtrace_fprint(
	 NULL,
	 NULL );

	return( 1 );
}

/* Tests the libcdata_error_backtrace_sprint function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_error_backtrace_sprint(
     void )
{
	/* Test invocation of function only
	 */
	libcdata_error_backtrace_sprint(
	 NULL,
	 NULL,
	 0 );

	return( 1 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CDATA_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CDATA_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CDATA_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CDATA_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CDATA_TEST_UNREFERENCED_PARAMETER( argc )
	CDATA_TEST_UNREFERENCED_PARAMETER( argv )

	CDATA_TEST_RUN(
	 "libcdata_error_free",
	 cdata_test_error_free );

	CDATA_TEST_RUN(
	 "libcdata_error_fprint",
	 cdata_test_error_fprint );

	CDATA_TEST_RUN(
	 "libcdata_error_sprint",
	 cdata_test_error_sprint );

	CDATA_TEST_RUN(
	 "libcdata_error_backtrace_fprint",
	 cdata_test_error_backtrace_fprint );

	CDATA_TEST_RUN(
	 "libcdata_error_backtrace_sprint",
	 cdata_test_error_backtrace_sprint );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

