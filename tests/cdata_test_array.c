/*
 * Cross-platform C generic data functions library array type testing program
 *
 * Copyright (c) 2006-2012, Joachim Metz <joachim.metz@gmail.com>
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

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include <stdio.h>

#include "cdata_test_libcdata.h"
#include "cdata_test_libcerror.h"
#include "cdata_test_libcstring.h"

/* Tests initializing the array
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_initialize1(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_array_initialize1";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	if( result != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );
	}
	if( result != 1 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == 1 )
	{
		if( libcdata_array_free(
		     &array,
		     NULL,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free array.",
			 function );
		}
	}
	if( result == -1 )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( result != 1 )
	{
		return( -1 );
	}
	return( 1 );
}

/* Tests initializing the array
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_initialize2(
     void )
{
	libcdata_array_t *array  = (libcdata_array_t *) 0x12345678UL;
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_array_initialize2";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	if( result != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );
	}
	if( result == 1 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == 1 )
	{
		if( libcdata_array_free(
		     &array,
		     NULL,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free array.",
			 function );
		}
	}
	if( result == -1 )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( result == 1 )
	{
		return( -1 );
	}
	return( 1 );
}

/* Tests initializing the array
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_initialize3(
     void )
{
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_array_initialize3";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_array_initialize(
	          NULL,
	          0,
	          &error );

	if( result != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );
	}
	if( result == 1 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == -1 )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( result == 1 )
	{
		return( -1 );
	}
	return( 1 );
}

/* Tests initializing the array
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_initialize4(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_array_initialize4";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_array_initialize(
	          &array,
	          -1,
	          &error );

	if( result != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );
	}
	if( result == 1 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );
	}
	fprintf(
	 stdout,
	 "\n" );

	if( result == 1 )
	{
		if( libcdata_array_free(
		     &array,
		     NULL,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free array.",
			 function );
		}
	}
	if( result == -1 )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( result == 1 )
	{
		return( -1 );
	}
	return( 1 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "Unsupported number of arguments.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_array_initialize1() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_array_initialize2() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_array_initialize3() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_array_initialize4() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	return( EXIT_SUCCESS );
}

