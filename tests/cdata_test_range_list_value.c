/*
 * Library range_list_value type test program
 *
 * Copyright (C) 2006-2019, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

#include "../libcdata/libcdata_range_list_value.h"

int cdata_test_range_list_value_value_free_function_return_value  = 1;
int cdata_test_range_list_value_value_clone_function_return_value = 1;
int cdata_test_range_list_value_value_merge_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_value_free_function_return_value );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_value_clone_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_value_clone_function_return_value );
}

/* Test value merge function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_value_merge_function(
     intptr_t *destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_value_merge_function_return_value );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_range_list_value_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_value_initialize(
     void )
{
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests               = 1;
	int number_of_memset_fail_tests               = 1;
	int test_number                               = 0;
#endif

	/* Test regular cases
	 */
	result = libcdata_range_list_value_initialize(
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_free(
	          &range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_value_initialize(
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

	range_list_value = (libcdata_range_list_value_t *) 0x12345678UL;

	result = libcdata_range_list_value_initialize(
	          &range_list_value,
	          &error );

	range_list_value = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_range_list_value_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_range_list_value_initialize(
		          &range_list_value,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( range_list_value != NULL )
			{
				libcdata_range_list_value_free(
				 &range_list_value,
				 &cdata_test_range_list_value_value_free_function,
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
			 "range_list_value",
			 range_list_value );

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
		/* Test libcdata_range_list_value_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_range_list_value_initialize(
		          &range_list_value,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( range_list_value != NULL )
			{
				libcdata_range_list_value_free(
				 &range_list_value,
				 &cdata_test_range_list_value_value_free_function,
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
			 "range_list_value",
			 range_list_value );

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
	if( range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_value_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_value_free(
     void )
{
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_value_initialize(
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value->value = (intptr_t *) 0x12345678;

	/* Test regular cases
	 */
	result = libcdata_range_list_value_free(
	          &range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_value_free(
	          NULL,
	          &cdata_test_range_list_value_value_free_function,
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

	/* Initialize test
	 */
	result = libcdata_range_list_value_initialize(
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value->value = (intptr_t *) 0x12345678;

	/* Test libcdata_range_list_value_free with free_function failing
	 */
	cdata_test_range_list_value_value_free_function_return_value = -1;

	result = libcdata_range_list_value_free(
	          &range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	cdata_test_range_list_value_value_free_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

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
	if( range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_value_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_value_clone(
     void )
{
	libcdata_range_list_value_t *destination_range_list_value = NULL;
	libcdata_range_list_value_t *source_range_list_value      = NULL;
	libcerror_error_t *error                                  = NULL;
	int result                                                = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_value_initialize(
	          &source_range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_range_list_value",
	 source_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_value_clone on initialized range_list_value
	 */
	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_free(
	          &destination_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_value_clone on non-initialized range_list_value
	 */
	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          NULL,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_value_clone(
	          NULL,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_range_list_value = (libcdata_range_list_value_t *) 0x12345678UL;

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	destination_range_list_value = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          NULL,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_range_list_value_clone with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_range_list_value != NULL )
		{
			libcdata_range_list_value_free(
			 &destination_range_list_value,
			 &cdata_test_range_list_value_value_free_function,
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
		 "destination_range_list_value",
		 destination_range_list_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_range_list_value_clone with memcpy failing
	 */
	cdata_test_memcpy_attempts_before_fail = 0;

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	if( cdata_test_memcpy_attempts_before_fail != -1 )
	{
		cdata_test_memcpy_attempts_before_fail = -1;

		if( destination_range_list_value != NULL )
		{
			libcdata_range_list_value_free(
			 &destination_range_list_value,
			 &cdata_test_range_list_value_value_free_function,
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
		 "destination_range_list_value",
		 destination_range_list_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Test libcdata_range_list_clone with value_clone_function failing
	 */
	cdata_test_range_list_value_value_clone_function_return_value = -1;

	result = libcdata_range_list_value_clone(
	          &destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &cdata_test_range_list_value_value_clone_function,
	          &error );

	cdata_test_range_list_value_value_clone_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_range_list_value_free(
	          &source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_range_list_value",
	 source_range_list_value );

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
	if( destination_range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &destination_range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	if( source_range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &source_range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_value_merge function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_value_merge(
     void )
{
	libcdata_range_list_value_t *destination_range_list_value = NULL;
	libcdata_range_list_value_t *source_range_list_value      = NULL;
	libcerror_error_t *error                                  = NULL;
	int result                                                = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_value_initialize(
	          &destination_range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_initialize(
	          &source_range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_range_list_value",
	 source_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	destination_range_list_value->start = 0;
	destination_range_list_value->end   = 32;
	destination_range_list_value->value = NULL;

	source_range_list_value->start      = 16;
	source_range_list_value->end        = 32;
	source_range_list_value->value      = (intptr_t *) 0x12345678;

	result = libcdata_range_list_value_merge(
	          destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	destination_range_list_value->start = 16;
	destination_range_list_value->end   = 32;
	destination_range_list_value->value = (intptr_t *) 0x87654321;

	source_range_list_value->start      = 0;
	source_range_list_value->end        = 32;
	source_range_list_value->value      = (intptr_t *) 0x12345678;

	result = libcdata_range_list_value_merge(
	          destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_merge_function,
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
	result = libcdata_range_list_value_merge(
	          NULL,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_merge_function,
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

	result = libcdata_range_list_value_merge(
	          destination_range_list_value,
	          NULL,
	          &cdata_test_range_list_value_value_merge_function,
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

	destination_range_list_value->value = (intptr_t *) 0x87654321;
	source_range_list_value->value      = (intptr_t *) 0x12345678;

	result = libcdata_range_list_value_merge(
	          destination_range_list_value,
	          source_range_list_value,
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

	/* Test libcdata_range_list_value_merge with merge_function failing
	 */
	cdata_test_range_list_value_value_merge_function_return_value = -1;

	result = libcdata_range_list_value_merge(
	          destination_range_list_value,
	          source_range_list_value,
	          &cdata_test_range_list_value_value_merge_function,
	          &error );

	cdata_test_range_list_value_value_merge_function_return_value = 1;

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
	result = libcdata_range_list_value_free(
	          &destination_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list_value",
	 destination_range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_free(
	          &source_range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_range_list_value",
	 source_range_list_value );

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
	if( source_range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &source_range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	if( destination_range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &destination_range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_value_check_range_overlap function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_value_check_range_overlap(
     void )
{
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_value_initialize(
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value->start = 0;
	range_list_value->size  = 0;
	range_list_value->end   = 32;

	/* Test regular cases
	 */
	result = libcdata_range_list_value_check_range_overlap(
	          range_list_value,
	          0,
	          32,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_check_range_overlap(
	          range_list_value,
	          64,
	          96,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_value_check_range_overlap(
	          NULL,
	          0,
	          32,
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
	result = libcdata_range_list_value_free(
	          &range_list_value,
	          &cdata_test_range_list_value_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

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
	if( range_list_value != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value,
		 &cdata_test_range_list_value_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_range_list_value_initialize",
	 cdata_test_range_list_value_initialize );

	CDATA_TEST_RUN(
	 "libcdata_range_list_value_free",
	 cdata_test_range_list_value_free );

	CDATA_TEST_RUN(
	 "libcdata_range_list_value_clone",
	 cdata_test_range_list_value_clone );

	CDATA_TEST_RUN(
	 "libcdata_range_list_value_merge",
	 cdata_test_range_list_value_merge );

	CDATA_TEST_RUN(
	 "libcdata_range_list_value_check_range_overlap",
	 cdata_test_range_list_value_check_range_overlap );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

