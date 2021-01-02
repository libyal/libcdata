/*
 * Library tree_node type test program
 *
 * Copyright (C) 2006-2021, Joachim Metz <joachim.metz@gmail.com>
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
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "cdata_test_libcdata.h"
#include "cdata_test_libcerror.h"
#include "cdata_test_macros.h"
#include "cdata_test_memory.h"
#include "cdata_test_rwlock.h"
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_tree_node.h"

int cdata_test_tree_node_value_free_function_return_value  = 1;
int cdata_test_tree_node_value_clone_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_tree_node_value_free_function(
     intptr_t **value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_tree_node_value_free_function";

	if( value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid value.",
		 function );

		return( -1 );
	}
	if( cdata_test_tree_node_value_free_function_return_value != 1 )
	{
		return( cdata_test_tree_node_value_free_function_return_value );
	}
	if( *value != NULL )
	{
		memory_free(
		 *value );

		*value = NULL;
	}
	return( 1 );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_tree_node_value_clone_function(
     int **destination_value,
     int *source_value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_tree_node_value_clone_function";

	if( destination_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination value.",
		 function );

		return( -1 );
	}
	if( *destination_value != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid destination value value already set.",
		 function );

		return( -1 );
	}
	if( cdata_test_tree_node_value_clone_function_return_value != 1 )
	{
		return( cdata_test_tree_node_value_clone_function_return_value );
	}
	if( source_value == NULL )
	{
		*destination_value = NULL;
	}
	else
	{
		*destination_value = (int *) memory_allocate(
		                              sizeof( int ) );

		if( *destination_value == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create destination value.",
			 function );

			return( -1 );
		}
		**destination_value = *source_value;
	}
	return( 1 );
}

/* Test value compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_tree_node_value_compare_function(
     int *first_value,
     int *second_value,
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
	if( *first_value < *second_value )
	{
		return( LIBCDATA_COMPARE_LESS );
	}
	else if( *first_value > *second_value )
	{
		return( LIBCDATA_COMPARE_GREATER );
	}
	return( LIBCDATA_COMPARE_EQUAL );
}

/* Tests the libcdata_tree_node_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_initialize(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 2;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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

	node = (libcdata_tree_node_t *) 0x12345678UL;

	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	node = NULL;

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

	/* 1 fail in memory_allocate_structure
	 * 2 fail in libcthreads_read_write_lock_initialize
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_tree_node_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_tree_node_initialize(
		          &node,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( node != NULL )
			{
				libcdata_tree_node_free(
				 &node,
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
			 "node",
			 node );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* 1 fail in memset after memory_allocate_structure
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_tree_node_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_tree_node_initialize(
		          &node,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( node != NULL )
			{
				libcdata_tree_node_free(
				 &node,
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
			 "node",
			 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *parent_node = NULL;
	libcdata_tree_node_t *node        = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_free(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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

	/* Test tree node connected to other nodes
	 */
	parent_node = ( (libcdata_internal_tree_node_t *) node )->parent_node;

	( (libcdata_internal_tree_node_t *) node )->parent_node = (libcdata_tree_node_t *) 0x12345678;

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	( (libcdata_internal_tree_node_t *) node )->parent_node = parent_node;

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
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_empty(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcdata_tree_node_t *sub_node2 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node2 = NULL;

	/* Test regular cases
	 */
	result = libcdata_tree_node_empty(
	          node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node2 = NULL;

	/* Test error cases
	 */
	result = libcdata_tree_node_empty(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_empty with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_empty(
	          node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_empty(
	          node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *destination_node = NULL;
	libcdata_tree_node_t *source_node      = NULL;
	libcdata_tree_node_t *sub_node1        = NULL;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests        = 2;
	int test_number                        = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &source_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_node",
	 source_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          source_node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	/* Test libcdata_tree_node_clone on initialized node
	 */
	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &destination_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_tree_node_clone on non-initialized node
	 */
	result = libcdata_tree_node_clone(
	          &destination_node,
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_clone(
	          NULL,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_node = (libcdata_tree_node_t *) 0x12345678UL;

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	destination_node = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          NULL,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	cdata_test_tree_node_value_clone_function_return_value = -1;

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	cdata_test_tree_node_value_clone_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* 1. Test libcdata_tree_node_clone with malloc failing in libcdata_tree_node_initialize
	 * 2. Test libcdata_tree_node_clone with malloc failing in libcdata_tree_node_clone
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_tree_node_clone(
		          &destination_node,
		          source_node,
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( destination_node != NULL )
			{
				libcdata_tree_node_free(
				 &destination_node,
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
			 "destination_node",
			 destination_node );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

/* TODO: Test libcdata_tree_node_initialize returning NULL destination_node */

	/* Test libcdata_tree_node_clone with value_clone_function failing
	 */
	cdata_test_tree_node_value_clone_function_return_value = -1;

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	cdata_test_tree_node_value_clone_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_node",
	 destination_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_node != NULL )
		{
			libcdata_tree_node_free(
			 &destination_node,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
			 &error );
		}
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "destination_node",
		 destination_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_tree_node_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
/* TODO this test causes libcdata_tree_node_free to fail on Ubuntu 14.04 determine why
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_tree_node_clone(
	          &destination_node,
	          source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_node != NULL )
		{
			libcdata_tree_node_free(
			 &destination_node,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
			 &error );
		}
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "destination_node",
		 destination_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
*/
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &source_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_node",
	 source_node );

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
	if( destination_node != NULL )
	{
		libcdata_tree_node_free(
		 &destination_node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( source_node != NULL )
	{
		libcdata_tree_node_free(
		 &source_node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *node = NULL;
	libcerror_error_t *error   = NULL;
	int *node_value            = NULL;
	int *value1                = NULL;
	int result                 = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_value(
	          node,
	          (intptr_t **) &node_value,
	          &error );

	CDATA_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node_value",
	 node_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_value(
	          NULL,
	          (intptr_t **) &node_value,
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

	result = libcdata_tree_node_get_value(
	          node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_value with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_value(
	          node,
	          (intptr_t **) &node_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_value(
	          node,
	          (intptr_t **) &node_value,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_value(
     void )
{
	libcdata_tree_node_t *node = NULL;
	libcerror_error_t *error   = NULL;
	int *value1                = NULL;
	int *value2                = NULL;
	int result                 = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Initialize test
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 1;

	/* Test error cases
	 */
	result = libcdata_tree_node_set_value(
	          NULL,
	          (intptr_t *) value2,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_value with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) value2,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_set_value(
			          node,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
	/* Test libcdata_tree_node_set_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) value2,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_set_value(
			          node,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	memory_free(
	 value2 );

	value2 = NULL;

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *parent_node = NULL;
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_parent_node with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_parent_node(
	          tree_node,
	          &parent_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_parent_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_parent_node(
	          tree_node,
	          &parent_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_parent_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_parent_node(
     void )
{
	libcdata_tree_node_t *parent_node = NULL;
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
	result = libcdata_tree_node_set_parent_node(
	          tree_node,
	          parent_node,
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
	result = libcdata_tree_node_set_parent_node(
	          NULL,
	          parent_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_parent_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_parent_node(
	          tree_node,
	          parent_node,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_set_parent_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_parent_node(
	          tree_node,
	          parent_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *previous_node = NULL;
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_previous_node with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_previous_node(
	          tree_node,
	          &previous_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_previous_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_previous_node(
	          tree_node,
	          &previous_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_previous_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_previous_node(
     void )
{
	libcdata_tree_node_t *previous_node = NULL;
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
	result = libcdata_tree_node_set_previous_node(
	          tree_node,
	          previous_node,
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
	result = libcdata_tree_node_set_previous_node(
	          NULL,
	          previous_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_previous_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_previous_node(
	          tree_node,
	          previous_node,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_set_previous_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_previous_node(
	          tree_node,
	          previous_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *next_node = NULL;
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_next_node with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_next_node(
	          tree_node,
	          &next_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_next_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_next_node(
	          tree_node,
	          &next_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_next_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_next_node(
     void )
{
	libcdata_tree_node_t *next_node = NULL;
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
	result = libcdata_tree_node_set_next_node(
	          tree_node,
	          next_node,
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
	result = libcdata_tree_node_set_next_node(
	          NULL,
	          next_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_next_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_next_node(
	          tree_node,
	          next_node,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_set_next_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_next_node(
	          tree_node,
	          next_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_nodes function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_nodes(
     void )
{
	libcdata_tree_node_t *next_node     = NULL;
	libcdata_tree_node_t *node          = NULL;
	libcdata_tree_node_t *parent_node   = NULL;
	libcdata_tree_node_t *previous_node = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_nodes(
	          node,
	          &parent_node,
	          &previous_node,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_nodes(
	          NULL,
	          &parent_node,
	          &previous_node,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_nodes(
	          node,
	          NULL,
	          &previous_node,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_nodes(
	          node,
	          &parent_node,
	          NULL,
	          &next_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "next_node",
	 next_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_nodes(
	          node,
	          &parent_node,
	          &previous_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "previous_node",
	 previous_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_nodes with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_nodes(
	          node,
	          &parent_node,
	          &previous_node,
	          &next_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_nodes with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_nodes(
	          node,
	          &parent_node,
	          &previous_node,
	          &next_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_nodes function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_nodes(
     void )
{
	libcdata_tree_node_t *next_node     = NULL;
	libcdata_tree_node_t *node          = NULL;
	libcdata_tree_node_t *parent_node   = NULL;
	libcdata_tree_node_t *previous_node = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_set_nodes(
	          node,
	          parent_node,
	          previous_node,
	          next_node,
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
	result = libcdata_tree_node_set_nodes(
	          NULL,
	          parent_node,
	          previous_node,
	          next_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_nodes with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_nodes(
	          node,
	          parent_node,
	          previous_node,
	          next_node,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_set_nodes with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_nodes(
	          node,
	          parent_node,
	          previous_node,
	          next_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_first_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_first_sub_node(
     void )
{
	libcdata_tree_node_t *first_sub_node = NULL;
	libcdata_tree_node_t *node           = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_first_sub_node(
	          node,
	          &first_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "first_sub_node",
	 first_sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_first_sub_node(
	          NULL,
	          &first_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "first_sub_node",
	 first_sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_first_sub_node(
	          node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_first_sub_node with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_first_sub_node(
	          node,
	          &first_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_first_sub_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_first_sub_node(
	          node,
	          &first_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_tree_node_set_first_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_set_first_sub_node(
     void )
{
	libcdata_tree_node_t *first_sub_node = NULL;
	libcdata_tree_node_t *node           = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_tree_node_set_first_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          first_sub_node,
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
	result = libcdata_internal_tree_node_set_first_sub_node(
	          NULL,
	          first_sub_node,
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
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_tree_node_get_last_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_last_sub_node(
     void )
{
	libcdata_tree_node_t *last_sub_node = NULL;
	libcdata_tree_node_t *node          = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_last_sub_node(
	          node,
	          &last_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "last_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_last_sub_node(
	          NULL,
	          &last_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "last_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_last_sub_node(
	          node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_last_sub_node with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_last_sub_node(
	          node,
	          &last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_last_sub_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_last_sub_node(
	          node,
	          &last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_tree_node_set_last_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_set_last_sub_node(
     void )
{
	libcdata_tree_node_t *last_sub_node = NULL;
	libcdata_tree_node_t *node          = NULL;
	libcerror_error_t *error            = NULL;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_tree_node_set_last_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          last_sub_node,
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
	result = libcdata_internal_tree_node_set_last_sub_node(
	          NULL,
	          last_sub_node,
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
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_sub_nodes function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_sub_nodes(
     void )
{
	libcdata_tree_node_t *first_sub_node = NULL;
	libcdata_tree_node_t *last_sub_node  = NULL;
	libcdata_tree_node_t *node           = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_sub_nodes(
	          node,
	          &first_sub_node,
	          &last_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "first_sub_node",
	 first_sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "last_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_sub_nodes(
	          NULL,
	          &first_sub_node,
	          &last_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "first_sub_node",
	 first_sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "last_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_sub_nodes(
	          node,
	          NULL,
	          &last_sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "last_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_get_sub_nodes(
	          node,
	          &first_sub_node,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "first_sub_node",
	 last_sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_sub_nodes with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_sub_nodes(
	          node,
	          &first_sub_node,
	          &last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_sub_nodes with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_sub_nodes(
	          node,
	          &first_sub_node,
	          &last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_set_sub_nodes function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_set_sub_nodes(
     void )
{
	libcdata_tree_node_t *first_sub_node = NULL;
	libcdata_tree_node_t *last_sub_node  = NULL;
	libcdata_tree_node_t *node           = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_set_sub_nodes(
	          node,
	          first_sub_node,
	          last_sub_node,
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
	result = libcdata_tree_node_set_sub_nodes(
	          NULL,
	          first_sub_node,
	          last_sub_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_set_sub_nodes with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_sub_nodes(
	          node,
	          first_sub_node,
	          last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_set_sub_nodes with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_sub_nodes(
	          node,
	          first_sub_node,
	          last_sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_internal_tree_node_append_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_append_node(
     void )
{
	libcdata_tree_node_t *first_sub_node = NULL;
	libcdata_tree_node_t *last_sub_node  = NULL;
	libcdata_tree_node_t *node           = NULL;
	libcdata_tree_node_t *sub_node1      = NULL;
	libcdata_tree_node_t *sub_node2      = NULL;
	libcdata_tree_node_t *sub_node3      = NULL;
	libcerror_error_t *error             = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */

	/* Test first sub node already set without exiting sub nodes
	 */
	first_sub_node = ( (libcdata_internal_tree_node_t *) node )->first_sub_node;

	( (libcdata_internal_tree_node_t *) node )->first_sub_node = (libcdata_tree_node_t *) 0x12345678;

	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node3,
	          &error );

	( (libcdata_internal_tree_node_t *) node )->first_sub_node = first_sub_node;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test last sub node already set without exiting sub nodes
	 */
	last_sub_node = ( (libcdata_internal_tree_node_t *) node )->last_sub_node;

	( (libcdata_internal_tree_node_t *) node )->last_sub_node = (libcdata_tree_node_t *) 0x12345678;

	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node3,
	          &error );

	( (libcdata_internal_tree_node_t *) node )->last_sub_node = last_sub_node;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test regular cases
	 */
	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node2 = NULL;

	/* Test error cases
	 */
	result = libcdata_internal_tree_node_append_node(
	          NULL,
	          sub_node3,
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

	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
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

	/* Test node already part of tree
	 */
	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node1,
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

	/* Test first sub node already set with exiting sub nodes
	 */
/* TODO implement */

	/* Test last sub node already set with exiting sub nodes
	 */
/* TODO implement */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &sub_node3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( sub_node3 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_tree_node_append_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_append_node(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcdata_tree_node_t *sub_node2 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_append_node(
	          NULL,
	          sub_node2,
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

	result = libcdata_tree_node_append_node(
	          node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_append_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node2,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
/* TODO fix double free of sub_node2 */
#ifdef TODO
	/* Test libcdata_tree_node_append_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node2,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
#endif
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &sub_node2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_append_value(
     void )
{
	libcdata_tree_node_t *node     = NULL;
	libcerror_error_t *error       = NULL;
	int *value1                    = NULL;
	int *value2                    = NULL;
	int result                     = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	libcdata_tree_node_t *sub_node = NULL;
#endif

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_append_value(
	          node,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Initialize test
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 1;

	/* Test error cases
	 */
	result = libcdata_tree_node_append_value(
	          NULL,
	          (intptr_t *) value2,
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_tree_node_append_value with malloc failing in libcdata_tree_node_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_tree_node_append_value(
	          node,
	          (intptr_t *) value2,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_get_last_sub_node(
			          node,
			          &sub_node,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			result = libcdata_tree_node_free(
			          &sub_node,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Clean up
	 */
	memory_free(
	 value2 );

	value2 = NULL;

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_tree_node_insert_node_find_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_insert_node_find_sub_node(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *sub_node  = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcerror_error_t *error        = NULL;
	int *sub_node_value             = NULL;
	int *value1                     = NULL;
	int *value2                     = NULL;
	int result                      = 0;
	int sub_node_index              = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	/* Test find sub node on an empty tree node
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "sub_node_index",
	 sub_node_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	/* Test find sub node on a tree node with 1 sub nodes where value is before the first sub node
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	*value2 = -1;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "sub_node_index",
	 sub_node_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_get_value(
	          sub_node,
	          (intptr_t **) &sub_node_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node_value",
	 sub_node_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*sub_node_value",
	 *sub_node_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find sub node on a tree node with 1 sub nodes where value is after the first sub node
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	*value2 = 2;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "sub_node_index",
	 sub_node_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find sub node on a tree node with 1 sub nodes where value is the same as the first sub node
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	*value2 = 1;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "sub_node_index",
	 sub_node_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_get_value(
	          sub_node,
	          (intptr_t **) &sub_node_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node_value",
	 sub_node_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*sub_node_value",
	 *sub_node_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find sub node on a tree node with 1 sub nodes where value is the same as the first sub node
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	*value2 = 1;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &sub_node_index,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "sub_node_index",
	 sub_node_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	sub_node_index = -1;
	sub_node       = NULL;

	*value2 = 2;

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          NULL,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
	          &sub_node,
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

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          NULL,
	          &sub_node,
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

	result = libcdata_internal_tree_node_insert_node_find_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &sub_node_index,
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
	memory_free(
	 value2 );

	value2 = NULL;

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_internal_tree_node_insert_node_before_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_insert_node_before_sub_node(
     void )
{
	libcdata_tree_node_t *node           = NULL;
	libcdata_tree_node_t *sub_node1      = NULL;
	libcdata_tree_node_t *sub_node2      = NULL;
	libcdata_tree_node_t *sub_node3      = NULL;
	libcdata_tree_node_t *test_sub_node2 = NULL;
	libcerror_error_t *error             = NULL;
	int *value1                          = NULL;
	int *value2                          = NULL;
	int *value3                          = NULL;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a sub node on an empty tree node succeeds
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_tree_node_set_value(
	          sub_node2,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	result = libcdata_internal_tree_node_insert_node_before_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          NULL,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_sub_node2 = sub_node2;
	sub_node2      = NULL;

	/* Test if insert of a sub node before the first sub node succeeds
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	result = libcdata_internal_tree_node_insert_node_before_sub_node(
	          (libcdata_internal_tree_node_t *) node,
	          test_sub_node2,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_tree_node_set_value(
	          sub_node3,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test error cases
	 */
	result = libcdata_internal_tree_node_insert_node_before_sub_node(
	          NULL,
	          NULL,
	          sub_node3,
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

	result = libcdata_internal_tree_node_insert_node_before_sub_node(
	          (libcdata_internal_tree_node_t *) node,
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
	          &sub_node3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( sub_node3 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_tree_node_insert_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_insert_node(
     void )
{
	libcdata_tree_node_t *duplicate_sub_node2 = NULL;
	libcdata_tree_node_t *node                = NULL;
	libcdata_tree_node_t *sub_node1           = NULL;
	libcdata_tree_node_t *sub_node2           = NULL;
	libcdata_tree_node_t *sub_node3           = NULL;
	libcdata_tree_node_t *sub_node4           = NULL;
	libcdata_tree_node_t *sub_node5           = NULL;
	libcerror_error_t *error                  = NULL;
	int *duplicate_value2                     = NULL;
	int *value1                               = NULL;
	int *value2                               = NULL;
	int *value3                               = NULL;
	int *value4                               = NULL;
	int *value5                               = NULL;
	int number_of_sub_nodes                   = 0;
	int result                                = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a sub node on an empty tree node succeeds
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_tree_node_set_value(
	          sub_node3,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node3 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a sub node before the first sub node succeeds
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a sub node after the first sub node succeed
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_tree_node_set_value(
	          sub_node2,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node2 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a duplicate sub node fails
	 */
	result = libcdata_tree_node_initialize(
	          &duplicate_sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_sub_node2",
	 duplicate_sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_value2 = (int *) memory_allocate(
	                            sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_value2",
	 duplicate_value2 );

	*duplicate_value2 = 2;

	result = libcdata_tree_node_set_value(
	          duplicate_sub_node2,
	          (intptr_t *) duplicate_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_value2 = NULL;

	result = libcdata_tree_node_insert_node(
	          node,
	          duplicate_sub_node2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a sub node after the last sub node succeeds
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node4",
	 sub_node4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_tree_node_set_value(
	          sub_node4,
	          (intptr_t *) value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node4,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node4 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a duplicate sub node succeeds
	 */
	result = libcdata_tree_node_insert_node(
	          node,
	          duplicate_sub_node2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_sub_node2 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node5",
	 sub_node5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value5 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value5",
	 value5 );

	*value5 = 5;

	result = libcdata_tree_node_set_value(
	          sub_node5,
	          (intptr_t *) value5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value5 = NULL;

	/* Test error cases
	 */
	result = libcdata_tree_node_insert_node(
	          NULL,
	          sub_node5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
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

	result = libcdata_tree_node_insert_node(
	          node,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_insert_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node5,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
	/* Test libcdata_tree_node_insert_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 7;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node5,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &sub_node5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node5",
	 sub_node5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( duplicate_value2 != NULL )
	{
		memory_free(
		 duplicate_value2 );
	}
	if( duplicate_sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &duplicate_sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value5 != NULL )
	{
		memory_free(
		 value5 );
	}
	if( sub_node5 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node5,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value4 != NULL )
	{
		memory_free(
		 value4 );
	}
	if( sub_node4 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node4,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( sub_node3 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_insert_value(
     void )
{
	libcdata_tree_node_t *node     = NULL;
	libcerror_error_t *error       = NULL;
	int *value1                    = NULL;
	int *value2                    = NULL;
	int result                     = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	libcdata_tree_node_t *sub_node = NULL;
#endif

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_insert_value(
	          node,
	          (intptr_t *) value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Initialize test
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 1;

	/* Test error cases
	 */
	result = libcdata_tree_node_insert_value(
	          NULL,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_tree_node_insert_value with malloc failing in libcdata_tree_node_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_tree_node_insert_value(
	          node,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_get_last_sub_node(
			          node,
			          &sub_node,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			result = libcdata_tree_node_remove_node(
			          node,
			          sub_node,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			result = libcdata_tree_node_free(
			          &sub_node,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Clean up
	 */
	memory_free(
	 value2 );

	value2 = NULL;

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_replace_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_replace_node(
     void )
{
	libcdata_tree_node_t *node              = NULL;
	libcdata_tree_node_t *replacement_node1 = NULL;
	libcdata_tree_node_t *replacement_node2 = NULL;
	libcdata_tree_node_t *sub_node1         = NULL;
	libcdata_tree_node_t *sub_node2         = NULL;
	libcdata_tree_node_t *test_sub_node1    = NULL;
	libcdata_tree_node_t *test_sub_node2    = NULL;
	libcerror_error_t *error                = NULL;
	int result                              = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_sub_node1 = sub_node1;
	sub_node1      = NULL;

	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_sub_node2 = sub_node2;
	sub_node2      = NULL;

	/* Test regular cases
	 */
	result = libcdata_tree_node_initialize(
	          &replacement_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "replacement_node1",
	 replacement_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_replace_node(
	          test_sub_node1,
	          replacement_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1         = test_sub_node1;
	test_sub_node1    = replacement_node1;
	replacement_node1 = sub_node1;
	sub_node1         = NULL;

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &replacement_node1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "replacement_node1",
	 replacement_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "replacement_node1",
	 error );

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &replacement_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "replacement_node2",
	 replacement_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_replace_node(
	          NULL,
	          replacement_node2,
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

	result = libcdata_tree_node_replace_node(
	          test_sub_node2,
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

	/* Test replacement node is self
	 */
	result = libcdata_tree_node_replace_node(
	          test_sub_node2,
	          test_sub_node2,
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

	/* Test node already part of tree
	 */
	result = libcdata_tree_node_replace_node(
	          test_sub_node2,
	          test_sub_node1,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_replace_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_replace_node(
	          test_sub_node2,
	          replacement_node2,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			sub_node2         = test_sub_node2;
			test_sub_node2    = replacement_node2;
			replacement_node2 = sub_node2;
			sub_node2         = NULL;
		}
	}
	else
	{
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
	/* Test libcdata_tree_node_replace_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_tree_node_replace_node(
	          test_sub_node2,
	          replacement_node2,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			sub_node2         = test_sub_node2;
			test_sub_node2    = replacement_node2;
			replacement_node2 = sub_node2;
			sub_node2         = NULL;
		}
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &replacement_node2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "replacement_node2",
	 replacement_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( replacement_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &replacement_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( replacement_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &replacement_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_remove_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_remove_node(
     void )
{
	libcdata_tree_node_t *node           = NULL;
	libcdata_tree_node_t *sub_node1      = NULL;
	libcdata_tree_node_t *sub_node2      = NULL;
	libcdata_tree_node_t *sub_node3      = NULL;
	libcdata_tree_node_t *sub_node4      = NULL;
	libcdata_tree_node_t *test_sub_node1 = NULL;
	libcdata_tree_node_t *test_sub_node2 = NULL;
	libcerror_error_t *error             = NULL;
	int *value1                          = NULL;
	int *value2                          = NULL;
	int *value3                          = NULL;
	int *value4                          = NULL;
	int number_of_sub_nodes              = 0;
	int result                           = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node",
	 node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_sub_node1 = sub_node1;
	sub_node1      = NULL;

	result = libcdata_tree_node_initialize(
	          &sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node2",
	 sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_tree_node_set_value(
	          sub_node2,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_sub_node2 = sub_node2;
	sub_node2      = NULL;

	result = libcdata_tree_node_initialize(
	          &sub_node3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node3",
	 sub_node3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_tree_node_set_value(
	          sub_node3,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node3 = NULL;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_remove_node(
	          node,
	          test_sub_node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_free(
	          &test_sub_node2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_sub_node2",
	 test_sub_node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_remove_node(
	          NULL,
	          test_sub_node1,
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

	result = libcdata_tree_node_remove_node(
	          node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_remove_node with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_remove_node(
	          node,
	          test_sub_node1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_append_node(
			          node,
			          test_sub_node1,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_tree_node_remove_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 6;

	result = libcdata_tree_node_remove_node(
	          node,
	          test_sub_node1,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_tree_node_append_node(
			          node,
			          test_sub_node1,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
	}
	else
	{
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
	result = libcdata_tree_node_get_number_of_sub_nodes(
	          node,
	          &number_of_sub_nodes,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Test remove of sub node not part of the tree node
	 */
	result = libcdata_tree_node_initialize(
	          &sub_node4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node4",
	 sub_node4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_tree_node_set_value(
	          sub_node4,
	          (intptr_t *) value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	result = libcdata_tree_node_remove_node(
	          node,
	          sub_node4,
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

	result = libcdata_tree_node_free(
	          &sub_node4,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node4",
	 sub_node4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node",
	 node );

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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( sub_node3 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_sub_nodes",
	 number_of_sub_nodes,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_number_of_sub_nodes with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          tree_node,
	          &number_of_sub_nodes,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_number_of_sub_nodes with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_number_of_sub_nodes(
	          tree_node,
	          &number_of_sub_nodes,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_tree_node_get_sub_node_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_tree_node_get_sub_node_by_index(
     void )
{
	libcdata_tree_node_t *sub_node  = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
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

	result = libcdata_tree_node_initialize(
	          &sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node1",
	 sub_node1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          tree_node,
	          sub_node1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	sub_node1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_sub_node_by_index(
	          tree_node,
	          0,
	          &sub_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_tree_node_get_sub_node_by_index(
	          NULL,
	          0,
	          &sub_node,
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

	result = libcdata_tree_node_get_sub_node_by_index(
	          tree_node,
	          -1,
	          &sub_node,
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

	result = libcdata_tree_node_get_sub_node_by_index(
	          tree_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_sub_node_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_sub_node_by_index(
	          tree_node,
	          0,
	          &sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_sub_node_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_sub_node_by_index(
	          tree_node,
	          0,
	          &sub_node,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	int *value1                     = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_tree_node_set_value(
	          tree_node,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_get_leaf_node_list with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_leaf_node_list(
	          tree_node,
	          &leaf_node_list,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;
	}
	else
	{
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
	/* Test libcdata_tree_node_get_leaf_node_list with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_tree_node_get_leaf_node_list(
	          tree_node,
	          &leaf_node_list,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;
	}
	else
	{
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	if( leaf_node_list != NULL )
	{
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
	}
	result = libcdata_tree_node_free(
	          &tree_node,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_tree_node_value_free_function,
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

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_value",
	 cdata_test_tree_node_set_value );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_parent_node",
	 cdata_test_tree_node_get_parent_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_parent_node",
	 cdata_test_tree_node_set_parent_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_previous_node",
	 cdata_test_tree_node_get_previous_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_previous_node",
	 cdata_test_tree_node_set_previous_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_next_node",
	 cdata_test_tree_node_get_next_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_next_node",
	 cdata_test_tree_node_set_next_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_nodes",
	 cdata_test_tree_node_get_nodes );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_nodes",
	 cdata_test_tree_node_set_nodes );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_first_sub_node",
	 cdata_test_tree_node_get_first_sub_node );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_set_first_sub_node",
	 cdata_test_internal_tree_node_set_first_sub_node );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_last_sub_node",
	 cdata_test_tree_node_get_last_sub_node );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_set_last_sub_node",
	 cdata_test_internal_tree_node_set_last_sub_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_sub_nodes",
	 cdata_test_tree_node_get_sub_nodes );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_set_sub_nodes",
	 cdata_test_tree_node_set_sub_nodes );

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_append_node",
	 cdata_test_internal_tree_node_append_node );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_append_node",
	 cdata_test_tree_node_append_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_append_value",
	 cdata_test_tree_node_append_value );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_insert_node_find_sub_node",
	 cdata_test_internal_tree_node_insert_node_find_sub_node );

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_insert_node_before_sub_node",
	 cdata_test_internal_tree_node_insert_node_before_sub_node );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_tree_node_insert_node",
	 cdata_test_tree_node_insert_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_insert_value",
	 cdata_test_tree_node_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_replace_node",
	 cdata_test_tree_node_replace_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_remove_node",
	 cdata_test_tree_node_remove_node );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_number_of_sub_nodes",
	 cdata_test_tree_node_get_number_of_sub_nodes );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_sub_node_by_index",
	 cdata_test_tree_node_get_sub_node_by_index );

	CDATA_TEST_RUN(
	 "libcdata_tree_node_get_leaf_node_list",
	 cdata_test_tree_node_get_leaf_node_list );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

