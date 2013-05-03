/*
 * Library list type testing program
 *
 * Copyright (c) 2006-2013, Joachim Metz <joachim.metz@gmail.com>
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

/* Tests initializing the list
 * Make sure the value list is referencing, is set to NULL
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_list_initialize(
     libcdata_list_t **list,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_list_initialize";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_list_initialize(
	          list,
	          &error );

	if( result != 1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create list.",
		 function );
	}
	if( result != expected_result )
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
		if( libcdata_list_free(
		     list,
		     NULL,
		     &error ) != 1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free list.",
			 function );

			return( -1 );
		}
	}
	if( result != expected_result )
	{
		return( 0 );
	}
	return( 1 );
}

/* Tests get, set, append and prepend of elements
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_list_elements(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int *element_value_test  = 0;
	static char *function    = "cdata_test_list_elements";
	int element_index        = 0;
	int element_value1       = 1;
	int element_value2       = 2;
	int element_value3       = 3;
	int element_value4       = 4;
	int element_value5       = 5;
	int element_value6       = 6;
	int number_of_elements   = 0;
	int result               = 0;

	list = NULL;

	if( libcdata_list_initialize(
	     &list,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create list.",
		 function );

		goto on_error;
	}
	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value3,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to append element.",
		 function );

		goto on_error;
	}
	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value4,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to append element.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing append_value\t" );

	if( result == 0 )
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

	if( result != 0 )
	{
		if( libcdata_list_get_number_of_elements(
		     list,
		     &number_of_elements,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of elements.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_elements\t" );

		result = ( number_of_elements == 2 );

		if( result == 0 )
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
	}
	if( result != 0 )
	{
		if( libcdata_list_get_value_by_index(
		     list,
		     1,
		     (intptr_t **) &element_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve value: 1.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_value_by_index\t" );

		result = ( element_value_test == &element_value4 );

		if( result == 0 )
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
	}
	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value2,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to prepend value.",
		 function );

		goto on_error;
	}
	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value1,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to prepend value.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing prepend_value\t" );

	if( result == 0 )
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

	if( result != 0 )
	{
		if( libcdata_list_get_number_of_elements(
		     list,
		     &number_of_elements,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of elements.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_elements\t" );

		result = ( number_of_elements == 4 );

		if( result == 0 )
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
	}
	if( result != 0 )
	{
		if( libcdata_list_get_value_by_index(
		     list,
		     1,
		     (intptr_t **) &element_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve value: 1.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_value_by_index\t" );

		result = ( element_value_test == &element_value2 );

		if( result == 0 )
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
	}
	result = libcdata_list_empty(
	          list,
	          NULL,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to empty list.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing empty\t" );

	if( result == 0 )
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

	if( result != 0 )
	{
		if( libcdata_list_get_number_of_elements(
		     list,
		     &number_of_elements,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of elements.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_elements\t" );

		result = ( number_of_elements == 0 );

		if( result == 0 )
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
	}
	if( libcdata_list_free(
	     &list,
	     NULL,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free list.",
		 function );

		goto on_error;
	}
	return( result );

on_error:
	if( error != NULL )
	{
		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 NULL,
		 NULL );
	}
	return( -1 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] )
#else
int main( int argc, char * const argv[] )
#endif
{
	libcdata_list_t *list = NULL;

	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "Unsupported number of arguments.\n" );

		return( EXIT_FAILURE );
	}
	list = NULL;

	if( cdata_test_list_initialize(
	     &list,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	list = (libcdata_list_t *) 0x12345678UL;

	if( cdata_test_list_initialize(
	     &list,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_list_initialize(
	     NULL,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: get, set, prepend and append elements
	 */
	if( cdata_test_list_elements() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test elements.\n" );

		return( EXIT_FAILURE );
	}
	/* TODO: test libcdata_list_clone
	 */
	return( EXIT_SUCCESS );
}
