/*
 * Library range list type test program
 *
 * Copyright (C) 2006-2018, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libcdata/libcdata_range_list.h"

int cdata_test_range_list_value_free_function_return_value  = 1;
int cdata_test_range_list_value_clone_function_return_value = 1;
int cdata_test_range_list_value_merge_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_free_function_return_value );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_clone_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_clone_function_return_value );
}

/* Test value merge function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_merge_function(
     intptr_t *destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_merge_function_return_value );
}

/* Tests the libcdata_range_list_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_initialize(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests   = 1;
	int number_of_memset_fail_tests   = 1;
	int test_number                   = 0;
#endif

	/* Test libcdata_range_list_initialize without entries
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_initialize(
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

	range_list = (libcdata_range_list_t *) 0x12345678UL;

	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	range_list = NULL;

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
		/* Test libcdata_range_list_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_range_list_initialize(
		          &range_list,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( range_list != NULL )
			{
				libcdata_range_list_free(
				 &range_list,
				 &cdata_test_range_list_value_free_function,
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
			 "range_list",
			 range_list );

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
		/* Test libcdata_range_list_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_range_list_initialize(
		          &range_list,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( range_list != NULL )
			{
				libcdata_range_list_free(
				 &range_list,
				 &cdata_test_range_list_value_free_function,
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
			 "range_list",
			 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_range_list_free(
	          NULL,
	          &cdata_test_range_list_value_free_function,
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

/* Tests the libcdata_range_list_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_empty(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_empty(
	          range_list,
	          &cdata_test_range_list_value_free_function,
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
	result = libcdata_range_list_empty(
	          NULL,
	          &cdata_test_range_list_value_free_function,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_clone(
     void )
{
	libcdata_range_list_t *destination_range_list = NULL;
	libcdata_range_list_t *source_range_list      = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &source_range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_range_list",
	 source_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_clone on initialized range_list
	 */
	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_free(
	          &destination_range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_clone on non-initialized range_list
	 */
	result = libcdata_range_list_clone(
	          &destination_range_list,
	          NULL,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_clone(
	          NULL,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_range_list = (libcdata_range_list_t *) 0x12345678UL;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	destination_range_list = NULL;

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

	/* Test libcdata_range_list_clone with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libcdata_range_list_clone with memcpy failing
	 */
	cdata_test_memcpy_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_memcpy_attempts_before_fail != -1 )
	{
		cdata_test_memcpy_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_range_list",
	 source_range_list );

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
	if( source_range_list != NULL )
	{
		libcdata_range_list_free(
		 &source_range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_number_of_elements function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_number_of_elements(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int number_of_elements            = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_get_number_of_elements(
	          range_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_get_number_of_elements(
	          NULL,
	          &number_of_elements,
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

	result = libcdata_range_list_get_number_of_elements(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_range_list_set_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_set_first_element(
     void )
{
	libcdata_list_element_t *first_element = NULL;
	libcdata_range_list_t *range_list      = NULL;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_set_first_element(
	          range_list,
	          first_element,
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
	result = libcdata_range_list_set_first_element(
	          NULL,
	          first_element,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_set_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_set_last_element(
     void )
{
	libcdata_list_element_t *last_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_set_last_element(
	          range_list,
	          last_element,
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
	result = libcdata_range_list_set_last_element(
	          NULL,
	          last_element,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_append_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_append_element(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_append_element(
	          NULL,
	          element,
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

	result = libcdata_range_list_append_element(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_append_value(
     void )
{
	libcdata_range_list_t *range_list  = NULL;
	libcdata_range_list_value_t *value = NULL;
	libcerror_error_t *error           = NULL;
	int result                         = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_append_value(
	          range_list,
	          value,
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
	result = libcdata_range_list_append_value(
	          NULL,
	          value,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_range_list_insert_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_insert_range(
	          NULL,
	          0,
	          1024,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_insert_range_list function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_range_list(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_insert_range_list(
	          NULL,
	          NULL,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_range_list_insert_range_list(
	          range_list,
	          NULL,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_range_list_insert_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_element(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_insert_element(
	          NULL,
	          NULL,
	          element,
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

	result = libcdata_range_list_insert_element(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_value(
     void )
{
	libcdata_range_list_t *range_list  = NULL;
	libcdata_range_list_value_t *value = NULL;
	libcerror_error_t *error           = NULL;
	int result                         = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_range_list_insert_value(
	          range_list,
	          NULL,
	          value,
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
	result = libcdata_range_list_insert_value(
	          NULL,
	          NULL,
	          value,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_remove_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_remove_element(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_remove_element(
	          NULL,
	          element,
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

	result = libcdata_range_list_remove_element(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_range_list_remove_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_remove_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_remove_range(
	          NULL,
	          0,
	          1024,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_range_list_get_element_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_element_by_index(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_element_by_index(
	          NULL,
	          0,
	          &element,
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

	result = libcdata_range_list_get_element_by_index(
	          range_list,
	          -1,
	          &element,
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

	result = libcdata_range_list_get_element_by_index(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_element_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_element_at_offset(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_element_at_offset(
	          NULL,
	          0,
	          &element,
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

	result = libcdata_range_list_get_element_at_offset(
	          range_list,
	          -1,
	          &element,
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

	result = libcdata_range_list_get_element_at_offset(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_value_by_index(
     void )
{
	libcdata_range_list_t *range_list  = NULL;
	libcdata_range_list_value_t *value = NULL;
	libcerror_error_t *error           = NULL;
	int result                         = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_value_by_index(
	          NULL,
	          0,
	          &value,
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

	result = libcdata_range_list_get_value_by_index(
	          range_list,
	          -1,
	          &value,
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

	result = libcdata_range_list_get_value_by_index(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_value_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_value_at_offset(
     void )
{
	libcdata_range_list_t *range_list  = NULL;
	libcdata_range_list_value_t *value = NULL;
	libcerror_error_t *error           = NULL;
	int result                         = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_value_at_offset(
	          NULL,
	          0,
	          &value,
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

	result = libcdata_range_list_get_value_at_offset(
	          range_list,
	          -1,
	          &value,
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

	result = libcdata_range_list_get_value_at_offset(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_range_list_get_range_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_range_by_index(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	intptr_t *value                   = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_range_by_index(
	          NULL,
	          0,
	          &range_start,
	          &range_size,
	          &value,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          -1,
	          &range_start,
	          &range_size,
	          &value,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          NULL,
	          &range_size,
	          &value,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          &range_start,
	          NULL,
	          &value,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          &range_start,
	          &range_size,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_range_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_range_at_offset(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	intptr_t *value                   = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_range_at_offset(
	          NULL,
	          0,
	          &range_start,
	          &range_size,
	          &value,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_range_is_present function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_range_is_present(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_range_is_present(
	          NULL,
	          0,
	          1024,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_spanning_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_spanning_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list",
	 range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_get_spanning_range(
	          NULL,
	          &range_start,
	          &range_size,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list",
	 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
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
	 "libcdata_range_list_initialize",
	 cdata_test_range_list_initialize );

	CDATA_TEST_RUN(
	 "libcdata_range_list_free",
	 cdata_test_range_list_free );

	CDATA_TEST_RUN(
	 "libcdata_range_list_empty",
	 cdata_test_range_list_empty );

	CDATA_TEST_RUN(
	 "libcdata_range_list_clone",
	 cdata_test_range_list_clone );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_number_of_elements",
	 cdata_test_range_list_get_number_of_elements );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_range_list_set_first_element",
	 cdata_test_range_list_set_first_element );

	CDATA_TEST_RUN(
	 "libcdata_range_list_set_last_element",
	 cdata_test_range_list_set_last_element );

	CDATA_TEST_RUN(
	 "libcdata_range_list_append_element",
	 cdata_test_range_list_append_element );

	CDATA_TEST_RUN(
	 "libcdata_range_list_append_value",
	 cdata_test_range_list_append_value );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_range",
	 cdata_test_range_list_insert_range );

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_range_list",
	 cdata_test_range_list_insert_range_list );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_element",
	 cdata_test_range_list_insert_element );

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_value",
	 cdata_test_range_list_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_range_list_remove_element",
	 cdata_test_range_list_remove_element );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_remove_range",
	 cdata_test_range_list_remove_range );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_element_by_index",
	 cdata_test_range_list_get_element_by_index );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_element_at_offset",
	 cdata_test_range_list_get_element_at_offset );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_value_by_index",
	 cdata_test_range_list_get_value_by_index );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_value_at_offset",
	 cdata_test_range_list_get_value_at_offset );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_by_index",
	 cdata_test_range_list_get_range_by_index );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_at_offset",
	 cdata_test_range_list_get_range_at_offset );

	CDATA_TEST_RUN(
	 "libcdata_range_list_range_is_present",
	 cdata_test_range_list_range_is_present );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_spanning_range",
	 cdata_test_range_list_spanning_range );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

