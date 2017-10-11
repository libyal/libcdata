/*
 * Library tree_node type test program
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

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_tree_node_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_tree_node_value_clone_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Test value compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_tree_node_value_compare_function(
     intptr_t *first_value,
     intptr_t *second_value,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_tree_node_value_compare_function";

	if( first_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid first value.",
		 function );

		return( -1 );
	}
	if( second_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid second value.",
		 function );

		return( -1 );
	}
/* TODO implement */
	return( LIBCDATA_COMPARE_EQUAL );
}

/* Tests the libcdata_tree_node_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_initialize(
     void )
{
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_initialize(
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

	tree_node = (libcdata_tree_node_t *) 0x12345678UL;

	result = libcdata_tree_node_initialize(
	          &tree_node,
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

	tree_node = NULL;

#if defined( HAVE_CDATA_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_tree_node_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_tree_node_initialize(
		          &tree_node,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( tree_node != NULL )
			{
				libcdata_tree_node_free(
				 &tree_node,
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
			 "tree_node",
			 tree_node );

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
		/* Test libcdata_tree_node_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_tree_node_initialize(
		          &tree_node,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( tree_node != NULL )
			{
				libcdata_tree_node_free(
				 &tree_node,
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
			 "tree_node",
			 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_tree_node_free(
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

/* Tests the libcdata_tree_node_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_empty(
     void )
{
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_test_tree_node_empty
	 */
	result = libcdata_tree_node_empty(
	          tree_node,
	          &cdata_test_tree_node_value_free_function,
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
	result = libcdata_tree_node_empty(
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
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_clone(
     void )
{
	libcdata_tree_node_t *destination_tree_node = NULL;
	libcdata_tree_node_t *source_tree_node      = NULL;
	libcerror_error_t *error                    = NULL;
	int result                                  = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &source_tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_tree_node",
	 source_tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_tree_node_clone on initialized tree_node
	 */
	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_tree_node",
	 destination_tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &destination_tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_tree_node",
	 destination_tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_tree_node_clone on non-initialized tree_node
	 */
	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          NULL,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_tree_node",
	 destination_tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_clone(
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
	 "destination_tree_node",
	 destination_tree_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_tree_node = (libcdata_tree_node_t *) 0x12345678UL;

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
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

	destination_tree_node = NULL;

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
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
	result = libcdata_tree_node_free(
	          &source_tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_tree_node",
	 source_tree_node );

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
	if( source_tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &source_tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_value(
     void )
{
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	intptr_t *value                 = 0;
	int result                      = 0;
	int value_is_set                = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_value(
	          tree_node,
	          &value,
	          &error );

	CDATA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_is_set = result;

	/* Test error cases
	 */
	result = libcdata_tree_node_get_value(
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

	if( value_is_set != 0 )
	{
		result = libcdata_tree_node_get_value(
		          tree_node,
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
	}
	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_parent_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_parent_node(
     void )
{
	libcdata_tree_node_t *parent_node = 0;
	libcdata_tree_node_t *tree_node   = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_parent_node(
	          tree_node,
	          &parent_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_parent_node(
	          NULL,
	          &parent_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_parent_node(
	          tree_node,
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
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_previous_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_previous_node(
     void )
{
	libcdata_tree_node_t *previous_node = 0;
	libcdata_tree_node_t *tree_node     = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_previous_node(
	          tree_node,
	          &previous_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_previous_node(
	          NULL,
	          &previous_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_previous_node(
	          tree_node,
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
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_next_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_next_node(
     void )
{
	libcdata_tree_node_t *next_node = 0;
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_next_node(
	          tree_node,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_next_node(
	          NULL,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_next_node(
	          tree_node,
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
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( next_node != NULL )
	{
		libcdata_tree_node_free(
		 &next_node,
		 NULL,
		 NULL );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_number_of_sub_nodes function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_number_of_sub_nodes(
     void )
{
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int number_of_sub_nodes         = 0;
	int number_of_sub_nodes_is_set  = 0;
	int result                      = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_number_of_sub_nodes(
	          tree_node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	number_of_sub_nodes_is_set = result;

	/* Test error cases
	 */
	result = libcdata_tree_node_get_number_of_sub_nodes(
	          NULL,
	          &number_of_sub_nodes,
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

	if( number_of_sub_nodes_is_set != 0 )
	{
		result = libcdata_tree_node_get_number_of_sub_nodes(
		          tree_node,
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
	}
	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_leaf_node_list function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_leaf_node_list(
     void )
{
	libcdata_list_t *leaf_node_list = 0;
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int tree_node_value             = 1;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &tree_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "tree_node",
	 tree_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_set_value(
	          tree_node,
	          (intptr_t *) &tree_node_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_leaf_node_list(
	          tree_node,
	          &leaf_node_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "leaf_node_list",
	 leaf_node_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &leaf_node_list,
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
	result = libcdata_tree_node_get_leaf_node_list(
	          NULL,
	          &leaf_node_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "leaf_node_list",
	 leaf_node_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_leaf_node_list(
	          tree_node,
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

/* TODO tests tree node without value */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "tree_node",
	 tree_node );

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
	if( leaf_node_list != NULL )
	{
		libcdata_list_free(
		 &leaf_node_list,
		 NULL,
		 NULL );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
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
	 "libcdata_tree_node_initialize",
	 cdata_test_tree_node_initialize );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_free",
	 cdata_test_tree_node_free );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_empty",
	 cdata_test_tree_node_empty );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_clone",
	 cdata_test_tree_node_clone );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_value",
	 cdata_test_tree_node_get_value );

	/* TODO: add tests for libcdata_tree_node_set_value */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_parent_node",
	 cdata_test_tree_node_get_parent_node );

	/* TODO: add tests for libcdata_tree_node_set_parent_node */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_previous_node",
	 cdata_test_tree_node_get_previous_node );

	/* TODO: add tests for libcdata_tree_node_set_previous_node */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_next_node",
	 cdata_test_tree_node_get_next_node );

	/* TODO: add tests for libcdata_tree_node_set_next_node */

	/* TODO: add tests for libcdata_tree_node_get_nodes */

	/* TODO: add tests for libcdata_tree_node_set_nodes */

	/* TODO: add tests for libcdata_tree_node_append_node */

	/* TODO: add tests for libcdata_tree_node_append_value */

	/* TODO: add tests for libcdata_tree_node_insert_node */

	/* TODO: add tests for libcdata_tree_node_insert_value */

	/* TODO: add tests for libcdata_tree_node_replace_node */

	/* TODO: add tests for libcdata_tree_node_remove_node */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_number_of_sub_nodes",
	 cdata_test_tree_node_get_number_of_sub_nodes );

	/* TODO: add tests for libcdata_tree_node_get_sub_node_by_index */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_leaf_node_list",
	 cdata_test_tree_node_get_leaf_node_list );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

