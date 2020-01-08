/*
 * Library balanced tree type test program
 *
 * Copyright (C) 2006-2020, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libcdata/libcdata_btree.h"

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
     libcdata_error_t **error )
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
	int number_of_malloc_fail_tests = 7;
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
	libcerror_error_t *error = NULL;
	int result               = 0;

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_get_number_of_values function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_get_number_of_values(
     void )
{
	libcdata_btree_t *btree  = NULL;
	libcerror_error_t *error = NULL;
	int number_of_values     = 0;
	int result               = 0;

	/* Initialize test
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
	libcdata_btree_t *btree  = NULL;
	libcerror_error_t *error = NULL;
	intptr_t *value          = NULL;
	int result               = 0;

	/* Initialize test
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

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_btree_get_value_by_index(
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

	result = libcdata_btree_get_value_by_index(
	          btree,
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

	result = libcdata_btree_get_value_by_index(
	          btree,
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
	int value1                       = 1;

	/* Initialize test
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

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_btree_get_value_by_value(
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

	result = libcdata_btree_get_value_by_value(
	          btree,
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

	result = libcdata_btree_get_value_by_value(
	          btree,
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
	int value1                       = 1;
	int value_index                  = 0;

	/* Initialize test
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

	/* Test regular cases
	 */

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
	int replacement_value            = 2;
	int replacement_value_index      = 0;
	int result                       = 0;
	int value_index                  = 0;
	int value1                       = 1;

	/* Initialize test
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

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_btree_replace_value(
	          NULL,
	          upper_node,
	          &value_index,
	          (intptr_t *) &value1,
	          &replacement_value_index,
	          (intptr_t *) &replacement_value,
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
	          (intptr_t *) &value1,
	          &replacement_value_index,
	          (intptr_t *) &replacement_value,
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
	          (intptr_t *) &value1,
	          &replacement_value_index,
	          (intptr_t *) &replacement_value,
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
	          (intptr_t *) &replacement_value,
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
	          (intptr_t *) &value1,
	          NULL,
	          (intptr_t *) &replacement_value,
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
	          (intptr_t *) &value1,
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

/* Tests the libcdata_btree_remove_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_remove_value(
     void )
{
	libcdata_btree_t *btree          = NULL;
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	int result                       = 0;
	int value_index                  = 0;
	int value1                       = 1;

	/* Initialize test
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

	/* Test regular cases
	 */

	/* Test error cases
	 */
	result = libcdata_btree_remove_value(
	          NULL,
	          upper_node,
	          &value_index,
	          (intptr_t *) &value1,
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
	          (intptr_t *) &value1,
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
	          (intptr_t *) &value1,
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

