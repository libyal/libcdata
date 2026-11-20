/*
 * Library balanced tree type test program
 *
 * Copyright (C) 2006-2026, Joachim Metz <joachim.metz@gmail.com>
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
#include "cdata_test_rwlock.h"
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_btree.h"

/* Test values to hold in a btree
 * The values are inserted in descending order, so value 26 is stored
 * at index 0, value 5 at index 21 and value 1 at index 25,
 * with the maximum number of values set to 26 inserting value 1 splits the root node
 */
static int cdata_test_btree_test_values[ 26 ] = {
	26, 25, 24, 23, 22, 21, 20,
	19, 18, 17, 16, 15, 14, 13,
	12, 11, 10, 9, 8, 7, 6, 5,
	4, 3, 2, 1 };

/* Additional test values that are all smaller than the test values
 * used for injecting failures in insert functions
 */
static int cdata_test_btree_other_values[ 56 ] = {
	-1, -2, -3, -4, -5, -6,
	-7, -8, -9, -10, -11, -12,
	-13, -14, -15, -16, -17, -18,
	-19, -20, -21, -22, -23, -24,
	-25, -26, -27, -28, -29, -30,
	-31, -32, -33, -34, -35, -36,
	-37, -38, -39, -40, -41, -42,
	-43, -44, -45, -46, -47, -48,
	-49, -50, -51, -52, -53, -54,
	-55, -56 };

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_btree_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Test value compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_btree_value_compare_function(
     int *first_value,
     int *second_value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_btree_value_compare_function";

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

/* Tests the libcdata_btree_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_initialize(
     void )
{
	libcdata_btree_t *btree         = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 6;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test libcdata_btree_initialize without entries
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          100,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_btree_free(
	          &btree,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_btree_initialize(
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

	btree = (libcdata_btree_t *) 0x12345678UL;

	result = libcdata_btree_initialize(
	          &btree,
	          0,
	          &error );

	btree = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_btree_initialize(
	          &btree,
	          -1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* 1 fail in memory_allocate_structure
	 * 2 fail in libcdata_array_initialize - memory_allocate_structure
	 * 3 fail in libcdata_array_initialize - memory_allocate of entries
	 * 4 fail in libcdata_array_initialize - libcthreads_read_write_lock_initialize
	 * 5 fail in libcdata_tree_node_initialize - memory_allocate_structure
	 * 6 fail in libcdata_tree_node_initialize - libcthreads_read_write_lock_initialize
	 * 7 fail in libcthreads_read_write_lock_initialize
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_btree_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_btree_initialize(
		          &btree,
		          10,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( btree != NULL )
			{
				libcdata_btree_free(
				 &btree,
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
			 "btree",
			 btree );

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
		/* Test libcdata_btree_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_btree_initialize(
		          &btree,
		          10,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( btree != NULL )
			{
				libcdata_btree_free(
				 &btree,
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
			 "btree",
			 btree );

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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_free(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcerror_error_t *error         = NULL;
	int result                       = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_tree_node_t *upper_node = NULL;
	intptr_t *existing_value         = NULL;
	int number_of_destroy_fail_tests = 6;
	int test_number                  = 0;
	int value_index                  = 0;
#endif

	/* Test error cases
	 */
	result = libcdata_btree_free(
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_free with pthread_rwlock_destroy failing in libcthreads_read_write_lock_free
	 */
	for( test_number = 0;
	     test_number < number_of_destroy_fail_tests;
	     test_number++ )
	{
		/* Create a btree holding a single value
		 */
		result = libcdata_btree_initialize(
		          &btree,
		          26,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_destroy_attempts_before_fail = test_number;

		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          &error );

		if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
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
		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_get_number_of_values function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_get_number_of_values(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	int number_of_values             = 0;
	int result                       = 0;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int number_of_rdlock_fail_tests  = 4;
	int test_number                  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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
	result = libcdata_btree_get_number_of_values(
	          btree,
	          &number_of_values,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_values",
	 number_of_values,
	 26 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_btree_get_number_of_values(
	          NULL,
	          &number_of_values,
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

	result = libcdata_btree_get_number_of_values(
	          btree,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_get_number_of_values with pthread_rwlock_rdlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_rdlock_fail_tests;
	     test_number++ )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number;

		result = libcdata_btree_get_number_of_values(
		          btree,
		          &number_of_values,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
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
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_get_value_by_index(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	intptr_t *test_value             = NULL;
	int result                       = 0;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int number_of_rdlock_fail_tests  = 3;
	int test_number                  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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
	result = libcdata_btree_get_value_by_index(
	          btree,
	          0,
	          &test_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "value",
	 *( int * ) test_value,
	 26 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test a value stored in a sub node
	 */
	test_value = NULL;

	result = libcdata_btree_get_value_by_index(
	          btree,
	          21,
	          &test_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "value",
	 *( int * ) test_value,
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_value = NULL;

	result = libcdata_btree_get_value_by_index(
	          btree,
	          25,
	          &test_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "value",
	 *( int * ) test_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	test_value = NULL;

	result = libcdata_btree_get_value_by_index(
	          NULL,
	          0,
	          &test_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	test_value = NULL;

	result = libcdata_btree_get_value_by_index(
	          btree,
	          -1,
	          &test_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	test_value = NULL;

	result = libcdata_btree_get_value_by_index(
	          btree,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_value",
	 test_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_get_value_by_index with pthread_rwlock_rdlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_rdlock_fail_tests;
	     test_number++ )
	{
		test_value = NULL;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number;

		result = libcdata_btree_get_value_by_index(
		          btree,
		          0,
		          &test_value,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "test_value",
			 test_value );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "test_value",
			 test_value );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_get_value_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_get_value_by_value(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	int result                       = 0;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int number_of_rdlock_fail_tests  = 20;
	int test_number                  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "existing_value",
	 *( int * ) existing_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test a value stored in a sub node
	 */
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "existing_value",
	 *( int * ) existing_value,
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "existing_value",
	 *( int * ) existing_value,
	 26 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_other_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	upper_node = NULL;

	result = libcdata_btree_get_value_by_value(
	          NULL,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_get_value_by_value(
	          btree,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          NULL,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          NULL,
	          &existing_value,
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

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
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

	/* Test retrieving a value that does not exist
	 * with a NULL existing value
	 */
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_other_values[ 42 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_get_value_by_value with pthread_rwlock_rdlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_rdlock_fail_tests;
	     test_number++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number;

		result = libcdata_btree_get_value_by_value(
		          btree,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "upper_node",
			 upper_node );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "existing_value",
			 existing_value );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
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
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_insert_value(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	int result                       = 0;
	int value1                       = 5;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests  = 20;
	int number_of_memset_fail_tests  = 2;
	int test_number                  = 0;
#endif
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int number_of_rdlock_fail_tests  = 12;
	int number_of_dupfail_tests      = 20;
	int number_of_wrlock_fail_tests  = 8;
	int test_number2                 = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases */

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	/* Note: upper_node may be NULL,
	 * inserting a value that triggers a node split
	 * can result in a NULL upper node
	 */
	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "existing_value",
	 *( int * ) existing_value,
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* 1-2 fail in libcdata_list_element_initialize
	 * 3-4 fail in libcdata_btree_node_insert_value
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		/* Test libcdata_btree_insert_value with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_other_values[ test_number ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			/* Note: upper_node may be NULL,
			 * inserting a value that triggers a node split
			 * can result in a NULL upper node
			 */
			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* 1-4 fail in libcdata_list_element_initialize
	 * 5-8 fail in libcdata_btree_node_insert_value
	 * 9-10 fail in libcdata_array_append_entry
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		/* Test libcdata_btree_insert_value with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = 4 + test_number;

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_other_values[ 4 + test_number ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			/* Note: upper_node may be NULL,
			 * inserting a value that triggers a node split
			 * can result in a NULL upper node
			 */
			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 */
	for( test_number2 = 0;
	     test_number2 < number_of_rdlock_fail_tests;
	     test_number2++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number2;

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_other_values[ 35 + test_number2 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			/* Note: upper_node may be NULL,
			 * inserting a value that triggers a node split
			 * can result in a NULL upper node
			 */
			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * with an existing value to reach the list element value retrieval failure
	 */
	for( test_number2 = 0;
	     test_number2 < number_of_dupfail_tests;
	     test_number2++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number2;

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &value1,
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 0 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "existing_value",
			 existing_value );
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
	}
	/* Test libcdata_btree_insert_value with pthread_rwlock_wrlock failing
	 */
	for( test_number2 = 0;
	     test_number2 < number_of_wrlock_fail_tests;
	     test_number2++ )
	{
		upper_node     = NULL;
		existing_value = NULL;

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = test_number2;

		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_other_values[ 47 + test_number2 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			/* Note: upper_node may be NULL,
			 * inserting a value that triggers a node split
			 * can result in a NULL upper node
			 */
			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );
		}
		else
		{
			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_value",
			 existing_value );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Free the btree and create a deterministic tree state for
	 * testing the remaining error branches of
	 * libcdata_btree_insert_value
	 */
	#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	/* Create a btree holding the test values,
	 * so the root node is split into sub nodes
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 26;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * in libcdata_tree_node_get_value after the new value was inserted
	 * into the leaf node
	 *
	 * With the test values in place the target leaf node holds a single
	 * value, so no node split takes place. The failing lock is the 19th
	 * pthread_rwlock_rdlock call during the insert, so set the counter
	 * to 18
	 */
	upper_node     = NULL;
	existing_value = NULL;

	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 18;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_other_values[ 55 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		/* Note: upper_node may be NULL,
		 * inserting a value that triggers a node split
		 * can result in a NULL upper node
		 */
		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * in libcdata_list_get_number_of_elements after the new value was
	 * inserted into the leaf node
	 *
	 * The failing lock is the 20th pthread_rwlock_rdlock call
	 * during the insert, so set the counter to 19
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 26;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	upper_node     = NULL;
	existing_value = NULL;

	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 19;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_other_values[ 55 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_btree_insert_value with pthread_rwlock_wrlock failing
	 * in libcdata_array_append_entry after the new value was inserted
	 * into the leaf node
	 *
	 * The failing lock is the 5th pthread_rwlock_wrlock call
	 * during the insert, so set the counter to 4
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 26;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	upper_node     = NULL;
	existing_value = NULL;

	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 4;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_other_values[ 55 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Free the btree and create a deterministic tree state for
	 * the node split failure tests
	 *
	 * Inserting the 26th value (test_values[25]) into a single-level
	 * tree with 25 values causes a node split.
	 * A failing pthread_rwlock_rdlock in the first
	 * libcdata_btree_node_get_sub_node_by_value call after the split
	 * results in a failed insert
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	upper_node     = NULL;
	existing_value = NULL;

	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * in the first libcdata_btree_node_get_sub_node_by_value call after
	 * the libcdata_btree_node_split call, where the values list exceeded
	 * the maximum number of values
	 *
	 * The 26th value (test_values[25]) causes the leaf node to split.
	 * The failing lock is the 155th pthread_rwlock_rdlock call during
	 * the insert and occurs in the first
	 * libcdata_btree_node_get_sub_node_by_value call after the split, so
	 * set the counter to 154
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 154;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Free the btree and create a deterministic tree state for
	 * the node split failure tests
	 *
	 * Inserting the 26th value (test_values[25]) into a single-level
	 * tree with 25 values causes a node split.
	 * A failing pthread_rwlock_rdlock in the second
	 * libcdata_btree_node_get_sub_node_by_value call after the split
	 * results in a failed insert
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	upper_node     = NULL;
	existing_value = NULL;

	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * in the first libcdata_btree_node_get_sub_node_by_value call after
	 * the node split
	 *
	 * The 26th value (test_values[25]) causes the leaf node to split and all
	 * pthread_rwlock_rdlock calls of the libcdata_btree_node_split call
	 * succeed. The failing lock is the 157th pthread_rwlock_rdlock call
	 * during the insert and occurs in the first
	 * libcdata_btree_node_get_sub_node_by_value call after the split,
	 * so set the counter to 156
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 156;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Free the btree and create a deterministic tree state for
	 * the node split failure tests
	 *
	 * Inserting the 26th value (test_values[25]) into a single-level
	 * tree with 25 values causes a node split.
	 * A failing pthread_rwlock_rdlock in the second
	 * libcdata_btree_node_get_sub_node_by_value call after the split
	 * results in a failed insert
	 */
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          NULL );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	upper_node     = NULL;
	existing_value = NULL;

	/* Test libcdata_btree_insert_value with pthread_rwlock_rdlock failing
	 * in the second libcdata_btree_node_get_sub_node_by_value call after
	 * the node split
	 *
	 * The 26th value (test_values[25]) causes the leaf node to split and all
	 * pthread_rwlock_rdlock calls of the first libcdata_btree_node_get_sub_node_by_value
	 * call after the split succeed. The failing lock is the 158th
	 * pthread_rwlock_rdlock call during the insert and occurs in the second
	 * libcdata_btree_node_get_sub_node_by_value call after the split,
	 * so set the counter to 157
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 157;

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test error cases
	 */
	result = libcdata_btree_insert_value(
	          NULL,
	          &value_index,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_insert_value(
	          btree,
	          NULL,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &value1,
	          NULL,
	          &upper_node,
	          &existing_value,
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

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          NULL,
	          &existing_value,
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

	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
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
	result = libcdata_btree_free(
	          &btree,
	          &cdata_test_btree_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "btree",
	 btree );

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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_replace_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_replace_value(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	int replacement_value_index      = 0;
	int replacement_value1           = 100;
	int result                       = 0;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int number_of_rdlock_fail_tests  = 6;
	int number_of_wrlock_fail_tests  = 4;
	int test_number                  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases */

	/* Test replacing a value stored in a sub node
	 */
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	replacement_value_index = 0;
	value_index             = 21;

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "replacement_value_index",
	 replacement_value_index,
	 21 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "value_index",
	 value_index,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	value_index = 0;

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          NULL,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          btree,
	          NULL,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          NULL,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          NULL,
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          NULL,
	          (intptr_t *) &replacement_value1,
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

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &replacement_value_index,
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

	/* Test replacing a value using an upper node with sub nodes
	 */
	value_index = 0;

	result = libcdata_btree_replace_value(
	          btree,
	          ( (libcdata_internal_btree_t *) btree )->root_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

	/* Test replacing a value using a value index out of bounds
	 */
	value_index = 9999;

	result = libcdata_btree_replace_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          &replacement_value_index,
	          (intptr_t *) &replacement_value1,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_replace_value with pthread_rwlock_rdlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_rdlock_fail_tests;
	     test_number++ )
	{
		/* Create a btree holding the test values,
		 * so the root node is split into sub nodes
		 */
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );

		result = libcdata_btree_initialize(
		          &btree,
		          26,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		for( value_index = 0;
		     value_index < 26;
		     value_index++ )
		{
			result = libcdata_btree_insert_value(
			          btree,
			          &value_index,
			          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
			          &upper_node,
			          &existing_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
		upper_node     = NULL;
		existing_value = NULL;

		result = libcdata_btree_get_value_by_value(
		          btree,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "upper_node",
		 upper_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		replacement_value_index = 0;
		value_index             = 21;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number;

		result = libcdata_btree_replace_value(
		          btree,
		          upper_node,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          &replacement_value_index,
		          (intptr_t *) &replacement_value1,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "replacement_value_index",
			 replacement_value_index,
			 21 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "value_index",
			 value_index,
			 -1 );
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

		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
	/* Test libcdata_btree_replace_value with pthread_rwlock_wrlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_wrlock_fail_tests;
	     test_number++ )
	{
		/* Create a btree holding the test values,
		 * so the root node is split into sub nodes
		 */
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );

		result = libcdata_btree_initialize(
		          &btree,
		          26,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		for( value_index = 0;
		     value_index < 26;
		     value_index++ )
		{
			result = libcdata_btree_insert_value(
			          btree,
			          &value_index,
			          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
			          &upper_node,
			          &existing_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
		upper_node     = NULL;
		existing_value = NULL;

		result = libcdata_btree_get_value_by_value(
		          btree,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "upper_node",
		 upper_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		replacement_value_index = 0;
		value_index             = 21;

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = test_number;

		result = libcdata_btree_replace_value(
		          btree,
		          upper_node,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          &replacement_value_index,
		          (intptr_t *) &replacement_value1,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "replacement_value_index",
			 replacement_value_index,
			 21 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "value_index",
			 value_index,
			 -1 );
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

		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 * Note: when testing pthread_rwlock failures
	 * the btree is already freed by the last test loop
	 */
	if( btree != NULL )
	{
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_remove_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_remove_value(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	int result                       = 0;
	int value_index                  = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	/* Cover the libcdata_array_set_entry_by_index failure
	 * (the 5th pthread_rwlock_wrlock call during the remove)
	 * in addition to the earlier lock failures
	 */
	int number_of_rdlock_fail_tests  = 7;
	int number_of_wrlock_fail_tests  = 5;
	int test_number                  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_btree_initialize(
	          &btree,
	          26,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "btree",
	 btree );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Insert the test values so the root node is split into sub nodes
	 */
	for( value_index = 0;
	     value_index < 25;
	     value_index++ )
	{
		result = libcdata_btree_insert_value(
		          btree,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_btree_insert_value(
	          btree,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 25 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases */

	/* Test removing a value stored in a sub node
	 */
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_index = 21;

	result = libcdata_btree_remove_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "value_index",
	 value_index,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test removing a value using an upper node with sub nodes
	 */
	value_index = 0;

	result = libcdata_btree_remove_value(
	          btree,
	          ( (libcdata_internal_btree_t *) btree )->root_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
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

	/* Test removing a value using a value index out of bounds
	 */
	value_index = 9999;

	result = libcdata_btree_remove_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
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

	/* Note: removing a value that triggers a root node flatten
	 * is not tested. The flatten operation does not update
	 * the root node of the btree, so the btree is left in an
	 * undefined state that cannot be further tested
	 */

	/* Test error cases
	 */
	upper_node     = NULL;
	existing_value = NULL;

	result = libcdata_btree_get_value_by_value(
	          btree,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_index = 0;

	result = libcdata_btree_remove_value(
	          btree,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_other_values[ 0 ] ),
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

	result = libcdata_btree_remove_value(
	          NULL,
	          upper_node,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
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

	result = libcdata_btree_remove_value(
	          btree,
	          NULL,
	          &value_index,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
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

	result = libcdata_btree_remove_value(
	          btree,
	          upper_node,
	          NULL,
	          (intptr_t *) &( cdata_test_btree_test_values[ 0 ] ),
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

	result = libcdata_btree_remove_value(
	          btree,
	          upper_node,
	          &value_index,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_remove_value with pthread_rwlock_rdlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_rdlock_fail_tests;
	     test_number++ )
	{
		/* Create a btree holding the test values,
		 * so the root node is split into sub nodes
		 */
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );

		result = libcdata_btree_initialize(
		          &btree,
		          26,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		for( value_index = 0;
		     value_index < 26;
		     value_index++ )
		{
			result = libcdata_btree_insert_value(
			          btree,
			          &value_index,
			          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
			          &upper_node,
			          &existing_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
		upper_node     = NULL;
		existing_value = NULL;

		result = libcdata_btree_get_value_by_value(
		          btree,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "upper_node",
		 upper_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		value_index = 21;

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = test_number;

		result = libcdata_btree_remove_value(
		          btree,
		          upper_node,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "value_index",
			 value_index,
			 -1 );
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

		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
	/* Test libcdata_btree_remove_value with pthread_rwlock_wrlock failing
	 */
	for( test_number = 0;
	     test_number < number_of_wrlock_fail_tests;
	     test_number++ )
	{
		/* Create a btree holding the test values,
		 * so the root node is split into sub nodes
		 */
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );

		result = libcdata_btree_initialize(
		          &btree,
		          26,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		for( value_index = 0;
		     value_index < 26;
		     value_index++ )
		{
			result = libcdata_btree_insert_value(
			          btree,
			          &value_index,
			          (intptr_t *) &( cdata_test_btree_test_values[ value_index ] ),
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
			          &upper_node,
			          &existing_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );
		}
		upper_node     = NULL;
		existing_value = NULL;

		result = libcdata_btree_get_value_by_value(
		          btree,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &existing_value,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "upper_node",
		 upper_node );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		value_index = 21;

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = test_number;

		result = libcdata_btree_remove_value(
		          btree,
		          upper_node,
		          &value_index,
		          (intptr_t *) &( cdata_test_btree_test_values[ 21 ] ),
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "value_index",
			 value_index,
			 -1 );
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

		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          NULL );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 * Note: when testing pthread_rwlock failures
	 * the btree is already freed by the last test loop
	 */
	if( btree != NULL )
	{
		result = libcdata_btree_free(
		          &btree,
		          &cdata_test_btree_value_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );
	}
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
	if( btree != NULL )
	{
		libcdata_btree_free(
		 &btree,
		 &cdata_test_btree_value_free_function,
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
	 "libcdata_btree_initialize",
	 cdata_test_btree_initialize );

	CDATA_TEST_RUN(
	 "libcdata_btree_free",
	 cdata_test_btree_free );

	CDATA_TEST_RUN(
	 "libcdata_btree_get_number_of_values",
	 cdata_test_btree_get_number_of_values );

	CDATA_TEST_RUN(
	 "libcdata_btree_get_value_by_index",
	 cdata_test_btree_get_value_by_index );

	CDATA_TEST_RUN(
	 "libcdata_btree_get_value_by_value",
	 cdata_test_btree_get_value_by_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_insert_value",
	 cdata_test_btree_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_replace_value",
	 cdata_test_btree_replace_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_remove_value",
	 cdata_test_btree_remove_value );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}
