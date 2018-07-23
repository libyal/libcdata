/*
 * Library tree_node type test program
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
#include "cdata_test_rwlock.h"
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_tree_node.h"

int cdata_test_tree_node_value_free_function_return_value  = 1;
int cdata_test_tree_node_value_clone_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_tree_node_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_tree_node_value_free_function_return_value );
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

	return( cdata_test_tree_node_value_clone_function_return_value );
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
	if( *first_value > *second_value )
	{
		return( LIBCDATA_COMPARE_LESS );
	}
	else if( *first_value < *second_value )
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
	libcdata_tree_node_t *tree_node = NULL;
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
	          &cdata_test_tree_node_value_free_function,
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

	tree_node = NULL;

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
		          &tree_node,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( tree_node != NULL )
			{
				libcdata_tree_node_free(
				 &tree_node,
				 &cdata_test_tree_node_value_free_function,
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
		          &tree_node,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( tree_node != NULL )
			{
				libcdata_tree_node_free(
				 &tree_node,
				 &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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

	/* Test error cases
	 */
	result = libcdata_tree_node_free(
	          NULL,
	          &cdata_test_tree_node_value_free_function,
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
	parent_node = ( (libcdata_internal_tree_node_t *) tree_node )->parent_node;

	( (libcdata_internal_tree_node_t *) tree_node )->parent_node = (libcdata_tree_node_t *) 0x12345678;

	result = libcdata_tree_node_free(
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &error );

	( (libcdata_internal_tree_node_t *) tree_node )->parent_node = parent_node;

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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_tree_node_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_empty(
     void )
{
	libcdata_tree_node_t *sub_node1 = NULL;
	libcdata_tree_node_t *sub_node2 = NULL;
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

	result = libcdata_internal_tree_node_append_node(
	          (libcdata_internal_tree_node_t *) tree_node,
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
	          (libcdata_internal_tree_node_t *) tree_node,
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
	result = libcdata_internal_tree_node_empty(
	          (libcdata_internal_tree_node_t *) tree_node,
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
	result = libcdata_internal_tree_node_empty(
	          NULL,
	          &cdata_test_tree_node_value_free_function,
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
	          &cdata_test_tree_node_value_free_function,
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
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

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

	/* Test regular cases
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
	          &cdata_test_tree_node_value_free_function,
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
	          tree_node,
	          &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_empty(
	          tree_node,
	          &cdata_test_tree_node_value_free_function,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *sub_node1             = NULL;
	libcerror_error_t *error                    = NULL;
	int result                                  = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests             = 2;
	int test_number                             = 0;
#endif

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
	          source_tree_node,
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
	          &cdata_test_tree_node_value_free_function,
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
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
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
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	destination_tree_node = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          NULL,
	          &cdata_test_tree_node_value_clone_function,
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

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
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

	cdata_test_tree_node_value_clone_function_return_value = -1;

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	cdata_test_tree_node_value_clone_function_return_value = 1;

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

	/* 1. Test libcdata_tree_node_clone with malloc failing in libcdata_tree_node_initialize
	 * 2. Test libcdata_tree_node_clone with malloc failing in libcdata_tree_node_clone
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_tree_node_clone(
		          &destination_tree_node,
		          source_tree_node,
		          &cdata_test_tree_node_value_free_function,
		          &cdata_test_tree_node_value_clone_function,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( destination_tree_node != NULL )
			{
				libcdata_tree_node_free(
				 &destination_tree_node,
				 &cdata_test_tree_node_value_free_function,
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
			 "destination_tree_node",
			 destination_tree_node );

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
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	cdata_test_tree_node_value_clone_function_return_value = 1;

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

	/* Test libcdata_tree_node_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_tree_node != NULL )
		{
			libcdata_tree_node_free(
			 &destination_tree_node,
			 &cdata_test_tree_node_value_free_function,
			 &error );
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
	/* Test libcdata_tree_node_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
/* TODO fix flaky test
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_tree_node_clone(
	          &destination_tree_node,
	          source_tree_node,
	          &cdata_test_tree_node_value_free_function,
	          &cdata_test_tree_node_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_tree_node != NULL )
		{
			libcdata_tree_node_free(
			 &destination_tree_node,
			 &cdata_test_tree_node_value_free_function,
			 &error );
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
*/
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &source_tree_node,
	          &cdata_test_tree_node_value_free_function,
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
	if( destination_tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &destination_tree_node,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( source_tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &source_tree_node,
		 &cdata_test_tree_node_value_free_function,
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
	int *node_value                 = NULL;
	int result                      = 0;
	int tree_node_value1            = 1;

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
	          (intptr_t *) &tree_node_value1,
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
	result = libcdata_tree_node_get_value(
	          tree_node,
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

	/* Test libcdata_tree_node_get_value with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_value(
	          tree_node,
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
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_value(
	          tree_node,
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
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int tree_node_value1            = 1;

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
	result = libcdata_tree_node_set_value(
	          tree_node,
	          (intptr_t *) &tree_node_value1,
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
	result = libcdata_tree_node_set_value(
	          NULL,
	          (intptr_t *) &tree_node_value1,
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
	          tree_node,
	          (intptr_t *) &tree_node_value1,
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
	/* Test libcdata_tree_node_set_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_value(
	          tree_node,
	          (intptr_t *) &tree_node_value1,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	 * WARNING: after this test the lock is still active
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *parent_node   = NULL;
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
	result = libcdata_tree_node_get_nodes(
	          tree_node,
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
	          tree_node,
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
	          tree_node,
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
	          tree_node,
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
	          tree_node,
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
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_get_nodes(
	          tree_node,
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
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *parent_node   = NULL;
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
	result = libcdata_tree_node_set_nodes(
	          tree_node,
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
	          tree_node,
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
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_tree_node_set_nodes(
	          tree_node,
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
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

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
	          &cdata_test_tree_node_value_free_function,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &cdata_test_tree_node_value_free_function,
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
	/* Test libcdata_tree_node_append_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_tree_node_append_node(
	          node,
	          sub_node2,
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
	sub_node2 = NULL;

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	if( sub_node2 != NULL )
	{
		result = libcdata_tree_node_free(
		          &sub_node2,
		          &cdata_test_tree_node_value_free_function,
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
	}
	result = libcdata_tree_node_free(
	          &node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *node = NULL;
	libcerror_error_t *error   = NULL;
	int result                 = 0;
	int tree_node_value1       = 1;
	int tree_node_value2       = 2;

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
	result = libcdata_tree_node_append_value(
	          node,
	          (intptr_t *) &tree_node_value1,
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
	result = libcdata_tree_node_append_value(
	          NULL,
	          (intptr_t *) &tree_node_value1,
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
	          (intptr_t *) &tree_node_value2,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_append_value with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_append_value(
	          node,
	          (intptr_t *) &tree_node_value2,
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
	/* Test libcdata_tree_node_append_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_tree_node_append_value(
	          node,
	          (intptr_t *) &tree_node_value2,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_tree_node_insert_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_tree_node_insert_node(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcdata_tree_node_t *sub_node2 = NULL;
	libcdata_tree_node_t *sub_node3 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int tree_node_value1            = 1;
	int tree_node_value2            = 2;
	int tree_node_value3            = 3;

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

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) &tree_node_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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

	result = libcdata_tree_node_set_value(
	          sub_node2,
	          (intptr_t *) &tree_node_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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

	result = libcdata_tree_node_set_value(
	          sub_node3,
	          (intptr_t *) &tree_node_value3,
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
	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node1,
	          &cdata_test_tree_node_value_compare_function,
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

	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node2,
	          &cdata_test_tree_node_value_compare_function,
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

	/* Test error cases
	 */
	result = libcdata_internal_tree_node_insert_node(
	          NULL,
	          sub_node3,
	          &cdata_test_tree_node_value_compare_function,
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

	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          NULL,
	          &cdata_test_tree_node_value_compare_function,
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

	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node3,
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

	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node3,
	          &cdata_test_tree_node_value_compare_function,
	          0xff,
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
	result = libcdata_internal_tree_node_insert_node(
	          (libcdata_internal_tree_node_t *) node,
	          sub_node1,
	          &cdata_test_tree_node_value_compare_function,
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
	result = libcdata_tree_node_free(
	          &sub_node3,
	          &cdata_test_tree_node_value_free_function,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcdata_tree_node_t *sub_node2 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int tree_node_value1            = 1;
	int tree_node_value2            = 2;

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

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) &tree_node_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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

	result = libcdata_tree_node_set_value(
	          sub_node2,
	          (intptr_t *) &tree_node_value2,
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
	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node1,
	          &cdata_test_tree_node_value_compare_function,
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

	/* Test error cases
	 */
	result = libcdata_tree_node_insert_node(
	          NULL,
	          sub_node2,
	          &cdata_test_tree_node_value_compare_function,
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
	          &cdata_test_tree_node_value_compare_function,
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
	          sub_node2,
	          &cdata_test_tree_node_value_compare_function,
	          0,
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
	/* Test libcdata_tree_node_insert_node with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 5;

	result = libcdata_tree_node_insert_node(
	          node,
	          sub_node2,
	          &cdata_test_tree_node_value_compare_function,
	          0,
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
	sub_node2 = NULL;

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	if( sub_node2 != NULL )
	{
		result = libcdata_tree_node_free(
		          &sub_node2,
		          &cdata_test_tree_node_value_free_function,
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
	}
	result = libcdata_tree_node_free(
	          &node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *tree_node = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int tree_node_value1            = 1;
	int tree_node_value2            = 2;

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
	result = libcdata_tree_node_insert_value(
	          tree_node,
	          (intptr_t *) &tree_node_value1,
	          &cdata_test_tree_node_value_compare_function,
	          0,
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
	result = libcdata_tree_node_insert_value(
	          NULL,
	          (intptr_t *) &tree_node_value1,
	          &cdata_test_tree_node_value_compare_function,
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
	          tree_node,
	          (intptr_t *) &tree_node_value2,
	          &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_tree_node_insert_value with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_tree_node_insert_value(
	          tree_node,
	          (intptr_t *) &tree_node_value2,
	          &cdata_test_tree_node_value_compare_function,
	          0,
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
	/* Test libcdata_tree_node_insert_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
/* TODO fix flaky test
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 6;

	result = libcdata_tree_node_insert_value(
	          tree_node,
	          (intptr_t *) &tree_node_value2,
	          &cdata_test_tree_node_value_compare_function,
	          0,
	          &error );

fprintf( stdout, "X: %d\n", 100 - cdata_test_pthread_rwlock_unlock_attempts_before_fail );

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
*/
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *node             = NULL;
	libcdata_tree_node_t *parent_node      = NULL;
	libcdata_tree_node_t *replacement_node = NULL;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &parent_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	          &replacement_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "replacement_node",
	 replacement_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_tree_node_append_node(
	          parent_node,
	          node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
	result = libcdata_tree_node_replace_node(
	          node,
	          replacement_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_remove_node(
	          parent_node,
	          replacement_node,
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
	result = libcdata_tree_node_replace_node(
	          NULL,
	          replacement_node,
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

	/* Test replacement node is self
	 */
	result = libcdata_tree_node_append_node(
	          parent_node,
	          node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_replace_node(
	          node,
	          node,
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
	          parent_node,
	          node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test node already part of tree
	 */
	result = libcdata_tree_node_append_node(
	          parent_node,
	          node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_append_node(
	          parent_node,
	          replacement_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_replace_node(
	          node,
	          replacement_node,
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
	          parent_node,
	          node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_remove_node(
	          parent_node,
	          replacement_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &parent_node,
	          &cdata_test_tree_node_value_free_function,
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

	result = libcdata_tree_node_free(
	          &node,
	          &cdata_test_tree_node_value_free_function,
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

	result = libcdata_tree_node_free(
	          &replacement_node,
	          &cdata_test_tree_node_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "replacement_node",
	 replacement_node );

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
	if( replacement_node != NULL )
	{
		libcdata_tree_node_remove_node(
		 parent_node,
		 replacement_node,
		 NULL );

		libcdata_tree_node_free(
		 &replacement_node,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_remove_node(
		 parent_node,
		 node,
		 NULL );

		libcdata_tree_node_free(
		 &node,
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( parent_node != NULL )
	{
		libcdata_tree_node_free(
		 &parent_node,
		 &cdata_test_tree_node_value_free_function,
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
	libcdata_tree_node_t *node        = NULL;
	libcdata_tree_node_t *parent_node = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &parent_node,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "parent_node",
	 parent_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

	result = libcdata_tree_node_append_node(
	          parent_node,
	          node,
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
	result = libcdata_tree_node_remove_node(
	          parent_node,
	          node,
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
	result = libcdata_tree_node_remove_node(
	          NULL,
	          node,
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
	          parent_node,
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
	          &parent_node,
	          &cdata_test_tree_node_value_free_function,
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

	result = libcdata_tree_node_free(
	          &node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( parent_node != NULL )
	{
		libcdata_tree_node_free(
		 &parent_node,
		 &cdata_test_tree_node_value_free_function,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &tree_node,
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
		 NULL );
	}
	if( tree_node != NULL )
	{
		libcdata_tree_node_free(
		 &tree_node,
		 &cdata_test_tree_node_value_free_function,
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
	int tree_node_value1            = 1;

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
	          (intptr_t *) &tree_node_value1,
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
	          &cdata_test_tree_node_value_free_function,
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
		 &cdata_test_tree_node_value_free_function,
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_tree_node_empty",
	 cdata_test_internal_tree_node_empty );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

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
	 "libcdata_internal_tree_node_insert_node",
	 cdata_test_internal_tree_node_insert_node );

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

