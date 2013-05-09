/*
 * Library array type testing program
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
#include "cdata_test_unused.h"

/* Tests initializing the array
 * Make sure the value array is referencing, is set to NULL
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_initialize(
     libcdata_array_t **array,
     int number_of_entries,
     int expected_result )
{
	libcerror_error_t *error = NULL;
	static char *function    = "cdata_test_array_initialize";
	int result               = 0;

	fprintf(
	 stdout,
	 "Testing initialize\t" );

	result = libcdata_array_initialize(
	          array,
	          number_of_entries,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
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
		if( libcdata_array_free(
		     array,
		     NULL,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
			 "%s: unable to free array.",
			 function );

			libcerror_error_backtrace_fprint(
			 error,
			 stdout );

			libcerror_error_free(
			 &error );

			return( -1 );
		}
	}
	if( result != expected_result )
	{
		return( 0 );
	}
	return( 1 );
}

/* Test entry compare function
 * Returns return LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_array_entry_compare_function(
     intptr_t *first_entry,
     intptr_t *second_entry,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_array_entry_compare_function";

	if( first_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid first entry.",
		 function );

		return( -1 );
	}
	if( second_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid second entry.",
		 function );

		return( -1 );
	}
	if( *first_entry > *second_entry )
	{
		return( LIBCDATA_COMPARE_LESS );
	}
	else if( *first_entry < *second_entry )
	{
		return( LIBCDATA_COMPARE_GREATER );
	}
	return( LIBCDATA_COMPARE_EQUAL );
}

/* Tests get, set, append, prepend and insert of entries
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_entries(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value_test    = 0;
	static char *function    = "cdata_test_array_entries";
	int entry_index          = 0;
	int entry_value1         = 1;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int entry_value5         = 5;
	int entry_value6         = 6;
	int number_of_entries    = 0;
	int result               = 0;

	array = NULL;

	if( libcdata_array_initialize(
	     &array,
	     2,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );

		goto on_error;
	}
	result = libcdata_array_set_entry_by_index(
	          array,
	          1,
	          (intptr_t *) &entry_value3,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set entry: 1.",
		 function );

		goto on_error;
	}
	result = libcdata_array_set_entry_by_index(
	          array,
	          0,
	          (intptr_t *) &entry_value2,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set entry: 0.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing set_entry_by_index\t" );

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

	/* Test to set an entry that is out of bounds
	 */
	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) &entry_value4,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set entry: 2.",
		 function );

		libcerror_error_backtrace_fprint(
		 error,
		 stdout );

		libcerror_error_free(
		 &error );
	}
	fprintf(
	 stdout,
	 "Testing set_entry_by_index\t" );

	if( result != -1 )
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

	result = libcdata_array_resize(
	          array,
	          3,
	          NULL,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_RESIZE_FAILED,
		 "%s: unable to resize array.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing resize\t" );

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

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) &entry_value4,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to set entry: 2.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing set_entry_by_index\t" );

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
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 3 );

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
		if( libcdata_array_get_entry_by_index(
		     array,
		     2,
		     (intptr_t **) &entry_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve entry: 2.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_entry_by_index\t" );

		result = ( entry_value_test == &entry_value4 );

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
	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value6,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to append entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing append_entry\t" );

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

	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) &entry_value1,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to prepend entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing prepend_entry\t" );

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
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 5 );

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
		if( libcdata_array_get_entry_by_index(
		     array,
		     1,
		     (intptr_t **) &entry_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve entry: 1.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_entry_by_index\t" );

		result = ( entry_value_test == &entry_value2 );

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
	/* Test if insert of new entry succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value5,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry\t" );

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
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 6 );

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
	result = libcdata_array_reverse(
	          array,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
		 "%s: unable to reverse array.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing reverse\t" );

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
		if( libcdata_array_get_entry_by_index(
		     array,
		     1,
		     (intptr_t **) &entry_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve entry: 1.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_entry_by_index\t" );

		result = ( entry_value_test == &entry_value5 );

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
		if( libcdata_array_get_entry_by_value(
		     array,
		     (intptr_t *) &entry_value4,
		     &cdata_test_array_entry_compare_function,
		     (intptr_t **) &entry_value_test,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve entry by value.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_entry_by_value\t" );

		result = ( entry_value_test == &entry_value4 );

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
	result = libcdata_array_empty(
	          array,
	          NULL,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to empty array.",
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
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 0 );

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
	if( libcdata_array_free(
	     &array,
	     NULL,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free array.",
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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 NULL,
		 NULL );
	}
	return( -1 );
}

/* Tests insert of entries
 * Returns 1 if successful, 0 if not or -1 on error
 */
int cdata_test_array_insert(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value_test    = 0;
	static char *function    = "cdata_test_array_insert";
	int entry_index          = 0;
	int entry_value1         = 1;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int number_of_entries    = 0;
	int result               = 0;

	array = NULL;

	if( libcdata_array_initialize(
	     &array,
	     0,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_INITIALIZE_FAILED,
		 "%s: unable to create array.",
		 function );

		goto on_error;
	}
	/* Test if insert of new entry on an empty array succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry on empty array\t" );

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

	/* Test if insert of new entry before the first element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value1,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry before first entry\t" );

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

	/* Test if insert of new entry after the first element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry after first entry\t" );

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

	/* Test if insert of duplicate entry fails
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry of duplicate\t" );

	if( result != 0 )
	{
		fprintf(
		 stdout,
		 "(FAIL)" );

		result = 0;
	}
	else
	{
		fprintf(
		 stdout,
		 "(PASS)" );

		result = 1;
	}
	fprintf(
	 stdout,
	 "\n" );

	/* Test if insert of new entry after the last element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry after last entry\t" );

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
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 4 );

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
	/* Test if insert of duplicate entry succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	if( result == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_APPEND_FAILED,
		 "%s: unable to insert entry.",
		 function );

		goto on_error;
	}
	fprintf(
	 stdout,
	 "Testing insert_entry of duplicate\t" );

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

	if( result != 0 )
	{
		if( libcdata_array_get_number_of_entries(
		     array,
		     &number_of_entries,
		     &error ) == -1 )
		{
			libcerror_error_set(
			 &error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_GET_FAILED,
			 "%s: unable to retrieve number of entries.",
			 function );

			goto on_error;
		}
		fprintf(
		 stdout,
		 "Testing get_number_of_entries\t" );

		result = ( number_of_entries == 5 );

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
	if( libcdata_array_free(
	     &array,
	     NULL,
	     &error ) == -1 )
	{
		libcerror_error_set(
		 &error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_FINALIZE_FAILED,
		 "%s: unable to free array.",
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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 NULL,
		 NULL );
	}
	return( -1 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain( int argc, wchar_t * const argv[] CDATA_TEST_ATTRIBUTE_UNUSED )
#else
int main( int argc, char * const argv[] CDATA_TEST_ATTRIBUTE_UNUSED )
#endif
{
	libcdata_array_t *array = NULL;

	CDATA_TEST_UNREFERENCED_PARAMETER( argv )

	if( argc != 1 )
	{
		fprintf(
		 stderr,
		 "Unsupported number of arguments.\n" );

		return( EXIT_FAILURE );
	}
	/* Initialization tests
	 */
	array = NULL;

	if( cdata_test_array_initialize(
	     &array,
	     0,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	array = NULL;

	if( cdata_test_array_initialize(
	     &array,
	     200,
	     1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	array = (libcdata_array_t *) 0x12345678UL;

	if( cdata_test_array_initialize(
	     &array,
	     0,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	if( cdata_test_array_initialize(
	     NULL,
	     0,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	array = NULL;

	if( cdata_test_array_initialize(
	     &array,
	     -1,
	     -1 ) != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test initialize.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: get, set, prepend, append and insert entries
	 */
	if( cdata_test_array_entries() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test entries.\n" );

		return( EXIT_FAILURE );
	}
	/* Test: insert entries
	 */
	if( cdata_test_array_insert() != 1 )
	{
		fprintf(
		 stderr,
		 "Unable to test insert.\n" );

		return( EXIT_FAILURE );
	}
	/* TODO: test libcdata_array_clone, libcdata_array_clean
	 */
	return( EXIT_SUCCESS );
}

