/*
 * Library array type test program
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
#include "cdata_test_memory.h"
#include "cdata_test_unused.h"

/* Test entry free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_array_entry_free_function(
     intptr_t **entry CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( entry )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Test entry clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_array_entry_clone_function(
     intptr_t **destination_entry CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_entry CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_entry )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_entry )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Test entry compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_array_entry_compare_function(
     intptr_t *first_entry,
     intptr_t *second_entry,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_array_entry_compare_function";
	int first_value       = 0;
	int second_value      = 0;

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
	/* This is necessary otherwise the comparision messes up
	 * as in e.g. 5 > 6 is true.
         */
	first_value  = (int) *first_entry;
	second_value = (int) *second_entry;

	if( first_value < second_value )
	{
		return( LIBCDATA_COMPARE_LESS );
	}
	else if( first_value > second_value )
	{
		return( LIBCDATA_COMPARE_GREATER );
	}
	return( LIBCDATA_COMPARE_EQUAL );
}

/* Tests the libcdata_array_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_initialize(
     void )
{
	libcdata_array_t *array         = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 2;
	int number_of_memset_fail_tests = 2;
	int test_number                 = 0;
#endif

	/* Test libcdata_array_initialize without entries
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test libcdata_array_initialize with entries
	 */
	result = libcdata_array_initialize(
	          &array,
	          200,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_initialize(
	          NULL,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	array = (libcdata_array_t *) 0x12345678UL;

	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	array = NULL;

	result = libcdata_array_initialize(
	          &array,
	          -1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#if INT_MAX == SSIZE_MAX

	result = libcdata_array_initialize(
	          &array,
	          INT_MAX,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#endif /* INT_MAX == SSIZE_MAX */

#if defined( HAVE_CDATA_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_array_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_array_initialize(
		          &array,
		          10,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( array != NULL )
			{
				libcdata_array_free(
				 &array,
				 NULL,
				 NULL );
			}
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "array",
			 array );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_array_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_array_initialize(
		          &array,
		          10,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( array != NULL )
			{
				libcdata_array_free(
				 &array,
				 NULL,
				 NULL );
			}
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "array",
			 array );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_array_free(
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_array_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_empty(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to empty an array without an entry tree function
	 */
	result = libcdata_array_empty(
	          array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_empty(
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_clear function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_clear(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to clear an array without an entry tree function
	 */
	result = libcdata_array_clear(
	          array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_clear(
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_clone(
     void )
{
	libcdata_array_t *destination_array = NULL;
	libcdata_array_t *source_array      = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &source_array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "source_array",
         source_array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test clone of an intialized array
	 */
	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          &cdata_test_array_entry_free_function,
	          &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_array",
	 destination_array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_free(
	          &destination_array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "destination_array",
         destination_array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test clone of a non-initialized array
	 */
	result = libcdata_array_clone(
	          &destination_array,
	          NULL,
	          &cdata_test_array_entry_free_function,
	          &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_clone(
	          NULL,
	          NULL,
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	destination_array = (libcdata_array_t *) 0x12345678UL;

	result = libcdata_array_clone(
	          &destination_array,
	          NULL,
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	destination_array = NULL;

	result = libcdata_array_clone(
	          &destination_array,
	          NULL,
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &source_array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "source_array",
         source_array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( source_array != NULL )
	{
		libcdata_array_free(
		 &source_array,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_resize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_resize(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to resize an array to a larger number of entries
	 */
	result = libcdata_array_resize(
	          array,
	          35,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to resize an array to a smaller number of entries
	 */
	result = libcdata_array_resize(
	          array,
	          4,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_resize(
	          NULL,
	          10,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_resize(
	          array,
	          -10,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#if INT_MAX == SSIZE_MAX

	result = libcdata_array_resize(
	          NULL,
	          INT_MAX,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#endif /* INT_MAX == SSIZE_MAX */

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_reverse function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_reserve(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          0,
	          (intptr_t *) &entry_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          1,
	          (intptr_t *) &entry_value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to reverse an array
	 */
	result = libcdata_array_reverse(
	          array,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_reverse(
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( result );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_get_number_of_entries function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_number_of_entries(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_index          = 0;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int number_of_entries    = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve the number of entries on an empty array
	 */
	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_entries",
	 number_of_entries,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve the number of entries on a non-empty array
	 */
	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &error );

	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_entries",
	 number_of_entries,
	 3 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_get_number_of_entries(
	          NULL,
	          &number_of_entries,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_get_number_of_entries(
	          array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_get_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_entry_by_index(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value_test    = NULL;
	int entry_index          = 0;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve an entry that is in bounds
	 */
	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value_test",
	 entry_value_test )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value_test",
	 *entry_value_test,
	 entry_value3 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve an entry that is out of bounds
	 */
	result = libcdata_array_get_entry_by_index(
	          array,
	          9,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	/* TODO: should this be NULL ?
	 * CDATA_TEST_ASSERT_IS_NULL(
	 *  "entry_value_test",
	 *   entry_value_test )
	 */

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Test error cases
	 */
	result = libcdata_array_get_entry_by_index(
	          NULL,
	          0,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_get_entry_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_entry_by_value(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value_test    = NULL;
	int entry_index          = 0;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int entry_value9         = 9;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve an entry that exists
	 */
	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) &entry_value3,
	          &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value_test",
	 entry_value_test )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value_test",
	 *entry_value_test,
	 entry_value3 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to retrieve an entry that not exists
	 */
	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) &entry_value9,
	          &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value_test",
	 *entry_value_test,
	 entry_value3 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_get_entry_by_index(
	          NULL,
	          0,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_set_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_set_entry_by_index(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to set an entry that is in bounds
	 */
	result = libcdata_array_set_entry_by_index(
	          array,
	          1,
	          (intptr_t *) &entry_value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          0,
	          (intptr_t *) &entry_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to set an entry that is out of bounds
	 */
	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Test error cases
	 */
	result = libcdata_array_set_entry_by_index(
	          NULL,
	          0,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          -1,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#if INT_MAX == SSIZE_MAX

	result = libcdata_array_set_entry_by_index(
	          array,
	          INT_MAX,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

#endif /* INT_MAX == SSIZE_MAX */

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_prepend_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_prepend_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_value1         = 1;
	int entry_value6         = 6;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to prepend an entry
	 */
	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) &entry_value6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to prepend another entry
	 */
	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) &entry_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_prepend_entry(
	          NULL,
	          (intptr_t *) &entry_value6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_append_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_append_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_index          = 0;
	int entry_value1         = 1;
	int entry_value6         = 6;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to append an entry
	 */
	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to append another entry
	 */
	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_append_entry(
	          NULL,
	          &entry_index,
	          (intptr_t *) &entry_value6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_append_entry(
	          array,
	          NULL,
	          (intptr_t *) &entry_value6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests the libcdata_array_insert_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_insert_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int entry_index          = 0;
	int entry_value1         = 1;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of new entry on an empty array succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of new entry before the first element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value1,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of new entry after the first element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of duplicate entry fails
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of new entry after the last element succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 3 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test if insert of duplicate entry succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 2 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_insert_entry(
	          NULL,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_insert_entry(
	          array,
	          NULL,
	          (intptr_t *) &entry_value2,
	          &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          NULL,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
}

/* Tests removing entries
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_remove_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value_test    = 0;
	int entry_index          = 0;
	int entry_value2         = 2;
	int entry_value3         = 3;
	int entry_value4         = 4;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) &entry_value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test to remove an entry that is in bounds
	 */
	result = libcdata_array_remove_entry(
	          array,
	          0,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value_test",
	 *entry_value_test,
	 entry_value2 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_array_remove_entry(
	          NULL,
	          0,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          -1,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          1000,
	          (intptr_t **) &entry_value_test,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "array",
         array );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	if( error != NULL )
	{
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
	return( 0 );
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
	 "libcdata_array_initialize",
	 cdata_test_array_initialize )

	CDATA_TEST_RUN(
	 "libcdata_array_free",
	 cdata_test_array_free )

	CDATA_TEST_RUN(
	 "libcdata_array_empty",
	 cdata_test_array_empty )

	CDATA_TEST_RUN(
	 "libcdata_array_clear",
	 cdata_test_array_clear )

	CDATA_TEST_RUN(
	 "libcdata_array_clone",
	 cdata_test_array_clone )

	CDATA_TEST_RUN(
	 "libcdata_array_resize",
	 cdata_test_array_resize )

	CDATA_TEST_RUN(
	 "libcdata_array_reverse",
	 cdata_test_array_reserve )

	CDATA_TEST_RUN(
	 "libcdata_array_get_number_of_entries",
	 cdata_test_array_get_number_of_entries )

	CDATA_TEST_RUN(
	 "libcdata_array_get_entry_by_index",
	 cdata_test_array_get_entry_by_index )

	CDATA_TEST_RUN(
	 "libcdata_array_get_entry_by_value",
	 cdata_test_array_get_entry_by_value )

	CDATA_TEST_RUN(
	 "libcdata_array_set_entry_by_index",
	 cdata_test_array_set_entry_by_index )

	CDATA_TEST_RUN(
	 "libcdata_array_prepend_entry",
	 cdata_test_array_prepend_entry )

	CDATA_TEST_RUN(
	 "libcdata_array_append_entry",
	 cdata_test_array_append_entry )

	CDATA_TEST_RUN(
	 "libcdata_array_insert_entry",
	 cdata_test_array_insert_entry )

	CDATA_TEST_RUN(
	 "libcdata_array_remove_entry",
	 cdata_test_array_remove_entry )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

