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

#include "../libcdata/libcdata_btree_node.h"
#include "../libcdata/libcdata_btree_values_list.h"
#include "../libcdata/libcdata_types.h"

int cdata_test_btree_value_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

static int cdata_test_btree_node_other_values[70] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
	21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
	31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
	51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 68, 69, 70 };

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
	if( ( cdata_test_btree_value_compare_function_return_value != LIBCDATA_COMPARE_LESS )
	 && ( cdata_test_btree_value_compare_function_return_value != LIBCDATA_COMPARE_EQUAL )
	 && ( cdata_test_btree_value_compare_function_return_value != LIBCDATA_COMPARE_GREATER ) )
	{
		return( cdata_test_btree_value_compare_function_return_value );
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_btree_node_get_sub_node_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_get_sub_node_by_value(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_t *values_list2                 = NULL;
	libcdata_list_element_t *values_list_element  = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *node2                   = NULL;
	libcdata_tree_node_t *sub_node                = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value0                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int rdlock_fail_test_number                   = 0;
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

	/* Test regular cases - with value compare function on node without value list elements and sub nodes
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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

	/* Test error cases - node where number of values list elements does not correspond with the number of sub nodes
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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

	/* Test regular cases - with value compare function
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases - without value compare function
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          NULL,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value2,
	          NULL,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular case - value smaller than first value list element
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value0,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error case - value compare function returns error
	 */
	cdata_test_btree_value_compare_function_return_value = -1;

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	cdata_test_btree_value_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test error case - value compare function returns unsupported value
	 */
	cdata_test_btree_value_compare_function_return_value = 5;

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	cdata_test_btree_value_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Initialize test - node with value list element without value
	 */
	result = libcdata_list_initialize(
	          &values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list2",
	 values_list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list2,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_initialize(
	          &node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_tree_node_set_value(
	          node2,
	          (intptr_t *) values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list2 = NULL;

	/* Test error case - invalid values list element missing value
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          node2,
	          (intptr_t *) &value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "sub_node",
	 sub_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_get_sub_node_by_value with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 9;
	     rdlock_fail_test_number++ )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_get_sub_node_by_value(
		          node,
		          (intptr_t *) &value2,
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &sub_node,
		          &values_list_element,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 0 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "values_list_element",
			 values_list_element );

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
			 "sub_node",
			 sub_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "values_list_element",
			 values_list_element );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test error cases
	 */
	result = libcdata_btree_node_get_sub_node_by_value(
	          NULL,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
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

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
	          &values_list_element,
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

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          NULL,
	          &values_list_element,
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

	result = libcdata_btree_node_get_sub_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &sub_node,
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
	          &node,
	          &libcdata_btree_values_list_free,
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
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node2 != NULL )
	{
		libcdata_tree_node_free(
		 &node2,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_get_upper_node_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_get_upper_node_by_value(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_t *values_list2                 = NULL;
	libcdata_list_element_t *values_list_element  = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_list_element_t *values_list_element2 = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcdata_tree_node_t *upper_node              = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int rdlock_fail_test_number                   = 0;
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

	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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

	result = libcdata_list_initialize(
	          &values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list2",
	 values_list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element2",
	 values_list_element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element2,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list2,
	          values_list_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element2 = NULL;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list2 = NULL;

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

	/* Test error cases - node where number of values list elements does not correspond with the number of sub nodes
	 */
	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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
	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          (intptr_t *) &value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &values_list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

/* TODO update docstring to indicate upper_node is set when value is not available */
	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "upper_node",
	 upper_node );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list_element",
	 values_list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_get_upper_node_by_value with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 13;
	     rdlock_fail_test_number++ )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_get_upper_node_by_value(
		          node,
		          (intptr_t *) &value1,
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &upper_node,
		          &values_list_element,
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
			 "values_list_element",
			 values_list_element );

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
			 "upper_node",
			 upper_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "values_list_element",
			 values_list_element );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test error cases
	 */
	result = libcdata_btree_node_get_upper_node_by_value(
	          NULL,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &values_list_element,
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

	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          &upper_node,
	          &values_list_element,
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

	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          NULL,
	          &upper_node,
	          &values_list_element,
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

	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
	          NULL,
	          &values_list_element,
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

	result = libcdata_btree_node_get_upper_node_by_value(
	          node,
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
	result = libcdata_tree_node_free(
	          &node,
	          &libcdata_btree_values_list_free,
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
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element2 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element2,
		 NULL,
		 NULL );
	}
	if( values_list2 != NULL )
	{
		libcdata_list_free(
		 &values_list2,
		 NULL,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_append_value(
     void )
{
	libcdata_tree_node_t *node  = NULL;
	libcdata_tree_node_t *node2 = NULL;
	libcerror_error_t *error    = NULL;
	int result                  = 0;
	int value1                  = 1;
	int value2                  = 2;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int malloc_fail_test_number = 0;
	int memset_fail_test_number = 0;
#endif

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int wrlock_fail_test_number = 0;
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
	result = libcdata_btree_node_append_value(
	          node,
	          (intptr_t *) &value1,
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
	result = libcdata_btree_node_append_value(
	          NULL,
	          (intptr_t *) &value2,
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

	/* Test libcdata_btree_node_append_value with malloc failing in libcdata_list_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_btree_node_append_value(
	          node,
	          (intptr_t *) &value2,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_btree_node_append_value with pthread_rwlock_wrlock failing
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 6;
	     wrlock_fail_test_number++ )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_append_value(
		          node2,
		          (intptr_t *) &value1,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_btree_node_append_value with malloc failing
	 */
	for( malloc_fail_test_number = 0;
	     malloc_fail_test_number < 6;
	     malloc_fail_test_number++ )
	{
		cdata_test_malloc_attempts_before_fail = malloc_fail_test_number;

		result = libcdata_btree_node_append_value(
		          node2,
		          (intptr_t *) &value2,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
	          &node2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_btree_node_append_value with memset failing
	 */
	for( memset_fail_test_number = 0;
	     memset_fail_test_number < 6;
	     memset_fail_test_number++ )
	{
		cdata_test_memset_attempts_before_fail = memset_fail_test_number;

		result = libcdata_btree_node_append_value(
		          node2,
		          (intptr_t *) &value1,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          &libcdata_btree_values_list_free,
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
	if( node2 != NULL )
	{
		libcdata_tree_node_free(
		 &node2,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_insert_value(
     void )
{
	libcdata_tree_node_t *node      = NULL;
	libcdata_tree_node_t *node2     = NULL;
	libcdata_tree_node_t *sub_node1 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int value1                      = 1;
	int value2                      = 2;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int malloc_fail_test_number = 0;
	int memset_fail_test_number = 0;
#endif

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int rdlock_fail_test_number = 0;
	int wrlock_fail_test_number = 0;
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
	result = libcdata_btree_node_insert_value(
	          node,
	          (intptr_t *) &value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
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
	result = libcdata_btree_node_insert_value(
	          NULL,
	          (intptr_t *) &value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
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

	result = libcdata_btree_node_insert_value(
	          node,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
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

	/* Test libcdata_btree_node_insert_value with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 8;
	     rdlock_fail_test_number++ )
	{
		/* Free the node between tests
		 */
		result = libcdata_tree_node_free(
		          &node2,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_insert_value(
		          node2,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
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

	/* Test libcdata_btree_node_insert_value with pthread_rwlock_wrlock failing
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 8;
	     wrlock_fail_test_number++ )
	{
		/* Free the node between tests
		 */
		result = libcdata_tree_node_free(
		          &node2,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_insert_value(
		          node2,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_btree_node_insert_value with malloc failing
	 */
	for( malloc_fail_test_number = 0;
	     malloc_fail_test_number < 8;
	     malloc_fail_test_number++ )
	{
		/* Free the node between tests
		 */
		result = libcdata_tree_node_free(
		          &node2,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_malloc_attempts_before_fail = malloc_fail_test_number;

		result = libcdata_btree_node_insert_value(
		          node2,
		          (intptr_t *) &cdata_test_btree_node_other_values[ malloc_fail_test_number ],
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

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

	/* Test libcdata_btree_node_insert_value with memset failing
	 */
	for( memset_fail_test_number = 0;
	     memset_fail_test_number < 8;
	     memset_fail_test_number++ )
	{
		/* Free the node between tests
		 */
		result = libcdata_tree_node_free(
		          &node2,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "node2",
		 node2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_memset_attempts_before_fail = memset_fail_test_number;

		result = libcdata_btree_node_insert_value(
		          node2,
		          (intptr_t *) &cdata_test_btree_node_other_values[ memset_fail_test_number ],
		          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node2,
	          &libcdata_btree_values_list_free,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "node2",
	 node2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

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

	/* Test error cases - node with sub nodes
	 */
	result = libcdata_btree_node_insert_value(
	          node,
	          (intptr_t *) &value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_btree_value_compare_function,
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
	          &libcdata_btree_values_list_free,
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
	if( node2 != NULL )
	{
		libcdata_tree_node_free(
		 &node2,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_replace_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_replace_value(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_tree_node_t *empty_node              = NULL;
	libcdata_tree_node_t *leaf_node               = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *parent_node             = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int replacement_value                         = 99;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int rdlock_fail_test_number = 0;
	int wrlock_fail_test_number = 0;
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

	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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

	/* Test error cases - node where number of values list elements does not correspond with the number of sub nodes
	 */
	result = libcdata_btree_node_replace_value(
	          node,
	          (intptr_t *) &value1,
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
	result = libcdata_btree_node_replace_value(
	          node,
	          (intptr_t *) &value1,
	          (intptr_t *) &replacement_value,
	          &error );

/* TODO determine if function should return 0 for non-existing value instead */
	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_replace_value with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 15;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &parent_node,
		          &libcdata_btree_values_list_free,
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

		leaf_node = NULL;
		empty_node = NULL;
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
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          parent_node,
		          leaf_node,
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
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          parent_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_replace_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          (intptr_t *) &replacement_value,
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

	/* Test libcdata_btree_node_replace_value with pthread_rwlock_wrlock failing
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 3;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &parent_node,
		          &libcdata_btree_values_list_free,
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

		leaf_node = NULL;
		empty_node = NULL;
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
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          parent_node,
		          leaf_node,
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
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          parent_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_replace_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &parent_node,
	          &libcdata_btree_values_list_free,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test error cases
	 */
	result = libcdata_btree_node_replace_value(
	          NULL,
	          (intptr_t *) &value2,
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

	result = libcdata_btree_node_replace_value(
	          node,
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

	result = libcdata_btree_node_replace_value(
	          node,
	          (intptr_t *) &value1,
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
	          &node,
	          &libcdata_btree_values_list_free,
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
	if( leaf_node != NULL )
	{
		libcdata_tree_node_free(
		 &leaf_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( empty_node != NULL )
	{
		libcdata_tree_node_free(
		 &empty_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( parent_node != NULL )
	{
		libcdata_tree_node_free(
		 &parent_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( sub_node2 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node2,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_remove_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_remove_value(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_t *values_list2                 = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_list_element_t *values_list_element2 = NULL;
	libcdata_tree_node_t *empty_node              = NULL;
	libcdata_tree_node_t *grand_node              = NULL;
	libcdata_tree_node_t *leaf_node               = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *parent_node             = NULL;
	libcdata_tree_node_t *root_node               = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int replacement_value                         = 99;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;
	int value3                                    = 100000;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int destroy_fail_test_number = 0;
	int rdlock_fail_test_number  = 0;
	int wrlock_fail_test_number  = 0;
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

	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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

	result = libcdata_list_initialize(
	          &values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list2",
	 values_list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element2",
	 values_list_element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element2,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list2,
	          values_list_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element2 = NULL;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) values_list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list2 = NULL;

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

	/* Test error cases - node where number of values list elements does not correspond with the number of sub nodes
	 */
	result = libcdata_btree_node_remove_value(
	          node,
	          (intptr_t *) &value2,
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

	/* Test error cases - existing value and missing replacement value
	 */
	result = libcdata_btree_node_remove_value(
	          node,
	          (intptr_t *) &value1,
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

	/* Test regular cases - non-existing value
	 */
#ifdef TODO
/* TODO fix test */
	result = libcdata_btree_node_remove_value(
	          node,
	          (intptr_t *) &value2,
	          (intptr_t *) &replacement_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
#endif

	/* Test regular cases - existing value
	 */
	result = libcdata_btree_node_remove_value(
	          node,
	          (intptr_t *) &value1,
	          (intptr_t *) &replacement_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_rdlock failing
	 * where the value is found in the node
	 * The test number is used to dial the failing pthread_rwlock_rdlock
	 * including the one in libcdata_list_element_get_previous_element
	 * called via libcdata_btree_values_list_replace_element_with_previous
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 60;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		leaf_node = NULL;
		empty_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          (intptr_t *) &replacement_value,
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

			/* The tree is in an inconsistent state, but the root node
			 * is still the top of the tree, free it to release everything
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			parent_node = NULL;
			leaf_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_rdlock failing
	 * on a leaf node without sub nodes
	 * The test number is used to dial the failing pthread_rwlock_rdlock
	 * including the one in libcdata_list_element_get_previous_element
	 * called via libcdata_btree_values_list_replace_element_with_previous
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 40;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		parent_node = NULL;
		leaf_node = NULL;
		empty_node = NULL;
		grand_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          root_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ 11 ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ 12 ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ 13 ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ 13 ],
		          (intptr_t *) &replacement_value,
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

			/* The root node is still the top of the tree,
			 * free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			parent_node = NULL;
			leaf_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_wrlock failing
	 * where the value is found in the node
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 2;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		leaf_node = NULL;
		empty_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

			/* The root node is still the top of the tree,
			 * free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			parent_node = NULL;
			leaf_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_rdlock failing
	 * where the value is not found in the tree
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 50;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		parent_node = NULL;
		leaf_node = NULL;
		empty_node = NULL;
		grand_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

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
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "grand_node",
		 grand_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          empty_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          grand_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_tree_node_append_node(
		          parent_node,
		          leaf_node,
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
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          parent_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          parent_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ rdlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          empty_node,
		          (intptr_t *) &value3,
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 0 );

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

			/* The tree is in an inconsistent state, the leaf node
			 * is still connected to the tree so freeing it is refused
			 */
			result = libcdata_tree_node_free(
			          &leaf_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "leaf_node",
			 leaf_node );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );

			/* The root node is still the top of the tree,
			 * free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			leaf_node = NULL;
			parent_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_wrlock failing
	 * where the value is not found in the tree
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 12;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		parent_node = NULL;
		leaf_node = NULL;
		empty_node = NULL;
		grand_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

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
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "grand_node",
		 grand_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          empty_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          grand_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_tree_node_append_node(
		          parent_node,
		          leaf_node,
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
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          parent_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          parent_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          empty_node,
		          (intptr_t *) &value3,
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 0 );

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

			/* The tree is in an inconsistent state, the leaf node
			 * is still connected to the tree so freeing it is refused
			 */
			result = libcdata_tree_node_free(
			          &leaf_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "leaf_node",
			 leaf_node );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );

			/* The root node is still the top of the tree,
			 * free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			leaf_node = NULL;
			parent_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_destroy failing
	 * where the value is not found in the tree
	 */
	for( destroy_fail_test_number = 0;
	     destroy_fail_test_number < 10;
	     destroy_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		parent_node = NULL;
		leaf_node = NULL;
		empty_node = NULL;
		grand_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

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
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "grand_node",
		 grand_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          empty_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_list_initialize(
		          &values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list2",
		 values_list2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_set_value(
		          grand_node,
		          (intptr_t *) values_list2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list2 = NULL;

		result = libcdata_tree_node_append_node(
		          parent_node,
		          leaf_node,
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
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          parent_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          grand_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ destroy_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          parent_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ destroy_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ destroy_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_destroy_attempts_before_fail = destroy_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          empty_node,
		          (intptr_t *) &value3,
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 0 );

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

			/* Free the leaf node, depending on where the failure
			 * occurred it is either still connected to the tree
			 * or it has become the top of the tree
			 */
			result = libcdata_tree_node_free(
			          &leaf_node,
			          &libcdata_btree_values_list_free,
			          &error );

			if( result == -1 )
			{
				/* The leaf node is still connected to the tree,
				 * the root node is the top, free it instead
				 */
				CDATA_TEST_ASSERT_IS_NOT_NULL(
				 "leaf_node",
				 leaf_node );

				CDATA_TEST_ASSERT_IS_NOT_NULL(
				 "error",
				 error );

				libcerror_error_free(
				 &error );

				result = libcdata_tree_node_free(
				          &root_node,
				          &libcdata_btree_values_list_free,
				          &error );

				CDATA_TEST_ASSERT_EQUAL_INT(
				 "result",
				 result,
				 1 );

				CDATA_TEST_ASSERT_IS_NULL(
				 "root_node",
				 root_node );

				CDATA_TEST_ASSERT_IS_NULL(
				 "error",
				 error );
			}
			else
			{
				CDATA_TEST_ASSERT_EQUAL_INT(
				 "result",
				 result,
				 1 );

				CDATA_TEST_ASSERT_IS_NULL(
				 "leaf_node",
				 leaf_node );

				CDATA_TEST_ASSERT_IS_NULL(
				 "error",
				 error );
			}

			root_node = NULL;
			parent_node = NULL;
			leaf_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_remove_value with pthread_rwlock_wrlock failing
	 * where the value is found in a leaf node
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 10;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &root_node,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		parent_node = NULL;
		leaf_node = NULL;
		empty_node = NULL;
		grand_node = NULL;
		/* Initialize test
		 */
		result = libcdata_tree_node_initialize(
		          &root_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "root_node",
		 root_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "leaf_node",
		 leaf_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_initialize(
		          &empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "empty_node",
		 empty_node );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          leaf_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_append_node(
		          root_node,
		          empty_node,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_btree_node_append_value(
		          root_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_remove_value(
		          leaf_node,
		          (intptr_t *) &cdata_test_btree_node_other_values[ wrlock_fail_test_number ],
		          (intptr_t *) &replacement_value,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

			/* The root node is still the top of the tree,
			 * free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &root_node,
			          &libcdata_btree_values_list_free,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "root_node",
			 root_node );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			parent_node = NULL;
			leaf_node = NULL;
			empty_node = NULL;
			grand_node = NULL;
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test error cases
	 */
	result = libcdata_btree_node_remove_value(
	          NULL,
	          (intptr_t *) &value2,
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

	result = libcdata_btree_node_remove_value(
	          node,
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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          &libcdata_btree_values_list_free,
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
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element2 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element2,
		 NULL,
		 NULL );
	}
	if( values_list2 != NULL )
	{
		libcdata_list_free(
		 &values_list2,
		 NULL,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( grand_node != NULL )
	{
		libcdata_tree_node_free(
		 &grand_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( leaf_node != NULL )
	{
		libcdata_tree_node_free(
		 &leaf_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( empty_node != NULL )
	{
		libcdata_tree_node_free(
		 &empty_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( parent_node != NULL )
	{
		libcdata_tree_node_free(
		 &parent_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( root_node != NULL )
	{
		libcdata_tree_node_free(
		 &root_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_split function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_split(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_element_t *values_list_element1  = NULL;
	libcdata_list_element_t *values_list_element2  = NULL;
	libcdata_tree_node_t *node                     = NULL;
	libcdata_tree_node_t *node2                    = NULL;
	libcerror_error_t *error                       = NULL;
	int result                                     = 0;
	int values_index                               = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int malloc_fail_test_number = 0;
	int memset_fail_test_number = 0;
#endif

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int destroy_fail_test_number  = 0;
	int rdlock_fail_test_number   = 0;
	int wrlock_fail_test_number   = 0;
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

	/* Test error cases
	 */
result = libcdata_btree_node_split(
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

	/* Add the test values
	 */
for( values_index = 0;
     values_index < 70;
     values_index++ )
{
	result = libcdata_btree_node_append_value(
	          node,
	          (intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
}

	/* Test regular cases
	 */
result = libcdata_btree_node_split(
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
	 * Note the node has sub nodes after the split,
	 * so another split will fail
	 */
result = libcdata_btree_node_split(
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

	/* Clean up
	 */
result = libcdata_tree_node_free(
          &node,
          &libcdata_btree_values_list_free,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_split with pthread_rwlock_rdlock failing
		*/
	for( rdlock_fail_test_number = 0;
		rdlock_fail_test_number < 6;
		rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
			*/
result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Initialize test
			*/
result = libcdata_tree_node_initialize(
				&node,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NOT_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Add the test values
			*/
		for( values_index = 0;
			values_index < 70;
			values_index++ )
		{
			result = libcdata_btree_node_append_value(
					node,
					(intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
					&error );

			CDATA_TEST_ASSERT_EQUAL_INT(
				"result",
				result,
				1 );

			CDATA_TEST_ASSERT_IS_NULL(
				"error",
				error );
		}

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_split(
				node,
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

			/* The split may have failed midway, but the node
			 * is still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
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
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */


#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_split with pthread_rwlock_wrlock failing
		*/
	for( wrlock_fail_test_number = 0;
		wrlock_fail_test_number < 2;
		wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
			*/
result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Initialize test
			*/
result = libcdata_tree_node_initialize(
				&node,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NOT_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Add the test values
			*/
		for( values_index = 0;
			values_index < 70;
			values_index++ )
		{
			result = libcdata_btree_node_append_value(
					node,
					(intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
					&error );

			CDATA_TEST_ASSERT_EQUAL_INT(
				"result",
				result,
				1 );

			CDATA_TEST_ASSERT_IS_NULL(
				"error",
				error );
		}

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_split(
				node,
				&error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

			/* The split may have failed midway, but the node
			 * is still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
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
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */


#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_btree_node_split with malloc failing
		*/
	for( malloc_fail_test_number = 0;
		malloc_fail_test_number < 6;
		malloc_fail_test_number++ )
	{
		/* Free the tree between tests
			*/
result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Initialize test
			*/
result = libcdata_tree_node_initialize(
				&node,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NOT_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Add the test values
			*/
		for( values_index = 0;
			values_index < 70;
			values_index++ )
		{
			result = libcdata_btree_node_append_value(
					node,
					(intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
					&error );

			CDATA_TEST_ASSERT_EQUAL_INT(
				"result",
				result,
				1 );

			CDATA_TEST_ASSERT_IS_NULL(
				"error",
				error );
		}

		cdata_test_malloc_attempts_before_fail = malloc_fail_test_number;

		result = libcdata_btree_node_split(
				node,
				&error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

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

			/* The split may have failed midway, but the node
			 * is still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
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
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */


#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_btree_node_split with memset failing
		*/
	for( memset_fail_test_number = 0;
		memset_fail_test_number < 6;
		memset_fail_test_number++ )
	{
		/* Free the tree between tests
			*/
result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Initialize test
			*/
result = libcdata_tree_node_initialize(
				&node,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NOT_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Add the test values
			*/
		for( values_index = 0;
			values_index < 70;
			values_index++ )
		{
			result = libcdata_btree_node_append_value(
					node,
					(intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
					&error );

			CDATA_TEST_ASSERT_EQUAL_INT(
				"result",
				result,
				1 );

			CDATA_TEST_ASSERT_IS_NULL(
				"error",
				error );
		}

		cdata_test_memset_attempts_before_fail = memset_fail_test_number;

		result = libcdata_btree_node_split(
				node,
				&error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

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

			/* The split may have failed midway, but the node
			 * is still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
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
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */


#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_split with pthread_rwlock_destroy failing
		*/
	for( destroy_fail_test_number = 0;
		destroy_fail_test_number < 100;
		destroy_fail_test_number++ )
	{
		/* Free the tree between tests
			*/
result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Initialize test
			*/
result = libcdata_tree_node_initialize(
				&node,
				&error );

	CDATA_TEST_ASSERT_EQUAL_INT(
		"result",
		result,
		1 )

	CDATA_TEST_ASSERT_IS_NOT_NULL(
		"node",
		node )

	CDATA_TEST_ASSERT_IS_NULL(
		"error",
		error )

		/* Add the test values
			*/
		for( values_index = 0;
			values_index < 70;
			values_index++ )
		{
			result = libcdata_btree_node_append_value(
					node,
					(intptr_t *) &cdata_test_btree_node_other_values[ values_index ],
					&error );

			CDATA_TEST_ASSERT_EQUAL_INT(
				"result",
				result,
				1 );

			CDATA_TEST_ASSERT_IS_NULL(
				"error",
				error );
		}

		cdata_test_pthread_rwlock_destroy_attempts_before_fail = destroy_fail_test_number;

		result = libcdata_btree_node_split(
				node,
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

			/* The split may have failed midway, but the node
			 * is still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
				&node,
				&libcdata_btree_values_list_free,
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
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */


	/* Clean up
	 */
result = libcdata_tree_node_free(
          &node,
          &libcdata_btree_values_list_free,
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
	if( values_list_element2 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element2,
		 NULL,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( node2 != NULL )
	{
		libcdata_tree_node_free(
		 &node2,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_flatten_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_flatten_node(
    void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_t *values_list2                 = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_list_element_t *values_list_element2 = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int destroy_fail_test_number = 0;
	int rdlock_fail_test_number  = 0;
	int wrlock_fail_test_number  = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

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

	result = libcdata_tree_node_set_value(
	          node,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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

	/* Test regular cases - with a single sub node
	 */
	result = libcdata_btree_node_flatten_node(
	          &node,
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
	          &node,
	          &libcdata_btree_values_list_free,
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

	result = libcdata_list_initialize(
	          &values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list1",
	 values_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list_element1",
	 values_list_element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          values_list_element1,
	          (intptr_t *) &value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list1,
	          values_list_element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list_element1 = NULL;

	result = libcdata_tree_node_set_value(
	          sub_node1,
	          (intptr_t *) values_list1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	values_list1 = NULL;

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
	          sub_node1,
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

	/* Test regular cases - node with multiple sub nodes
	 */
	result = libcdata_btree_node_flatten_node(
	          &node,
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
	          &node,
	          &libcdata_btree_values_list_free,
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
	result = libcdata_btree_node_flatten_node(
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

	/* Test libcdata_btree_node_flatten_node with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 3;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node1,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "sub_node1",
		 sub_node1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_free(
		          &sub_node2,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          node,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          sub_node1,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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
		          sub_node1,
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

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_flatten_node(
		          &node,
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

			/* The flatten may have failed midway, the node is
			 * still the top of the tree or it has been replaced
			 * by the top sub node, free it to release the entire tree
			 */
			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node1 = NULL;
			sub_node2 = NULL;
		}
	}

	/* Test libcdata_btree_node_flatten_node with pthread_rwlock_wrlock failing
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 5;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node1,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "sub_node1",
		 sub_node1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_free(
		          &sub_node2,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          node,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          sub_node1,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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
		          sub_node1,
		          sub_node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

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

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_flatten_node(
		          &node,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			/* On success the flatten replaces node with the sub node,
			 * the sub node handles no longer point to valid nodes
			 */
			sub_node1 = NULL;
			sub_node2 = NULL;
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

			/* The flatten may have failed midway, the sub node may still
			 * be connected to the node or it may have been detached from
			 * the tree, try to free it to release the orphaned sub tree,
			 * if it is still connected to the node this fails and freeing
			 * the node releases the entire tree instead
			 */
			result = libcdata_tree_node_free(
			          &sub_node1,
			          &libcdata_btree_values_list_free,
			          &error );

			if( result != 1 )
			{
				if( error != NULL )
				{
					libcerror_error_free(
					 &error );
				}

				sub_node1 = NULL;
			}

			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node2 = NULL;
		}
	}

	/* Test libcdata_btree_node_flatten_node with pthread_rwlock_destroy failing
	 */
	for( destroy_fail_test_number = 0;
	     destroy_fail_test_number < 10;
	     destroy_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node1,
		          &libcdata_btree_values_list_free,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "sub_node1",
		 sub_node1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_tree_node_free(
		          &sub_node2,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          node,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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

		result = libcdata_list_initialize(
		          &values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list1",
		 values_list1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_initialize(
		          &values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "values_list_element1",
		 values_list_element1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_element_set_value(
		          values_list_element1,
		          (intptr_t *) &value1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		result = libcdata_list_append_element(
		          values_list1,
		          values_list_element1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list_element1 = NULL;

		result = libcdata_tree_node_set_value(
		          sub_node1,
		          (intptr_t *) values_list1,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		values_list1 = NULL;

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
		          sub_node1,
		          sub_node2,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

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

		cdata_test_pthread_rwlock_destroy_attempts_before_fail = destroy_fail_test_number;

		result = libcdata_btree_node_flatten_node(
		          &node,
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

			/* On success the flatten replaces node with the sub node,
			 * the sub node handles no longer point to valid nodes
			 */
			sub_node1 = NULL;
			sub_node2 = NULL;
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

			/* The flatten may have failed midway, the sub node may still
			 * be connected to the node or it may have been detached from
			 * the tree, try to free it to release the orphaned sub tree,
			 * if it is still connected to the node this fails and freeing
			 * the node releases the entire tree instead
			 */
			result = libcdata_tree_node_free(
			          &sub_node1,
			          &libcdata_btree_values_list_free,
			          &error );

			if( result != 1 )
			{
				if( error != NULL )
				{
					libcerror_error_free(
					 &error );
				}

				sub_node1 = NULL;
			}

			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node2 = NULL;
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &node,
	          &libcdata_btree_values_list_free,
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
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( sub_node1 != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node1,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( values_list_element2 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element2,
		 NULL,
		 NULL );
	}
	if( values_list2 != NULL )
	{
		libcdata_list_free(
		 &values_list2,
		 NULL,
		 NULL );
	}
	if( values_list_element1 != NULL )
	{
		libcdata_list_element_free(
		 &values_list_element1,
		 NULL,
		 NULL );
	}
	if( values_list1 != NULL )
	{
		libcdata_list_free(
		 &values_list1,
		 NULL,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_btree_node_remove_sub_node function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_remove_sub_node(
    void )
{
	libcdata_tree_node_t *node     = NULL;
	libcdata_tree_node_t *sub_node = NULL;
	libcerror_error_t *error       = NULL;
	int result                     = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int destroy_fail_test_number = 0;
	int rdlock_fail_test_number  = 0;
	int wrlock_fail_test_number  = 0;
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

	result = libcdata_tree_node_initialize(
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

	result = libcdata_tree_node_append_node(
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

	sub_node = NULL;

	/* Test regular cases
	 */
	result = libcdata_tree_node_get_first_sub_node(
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

	result = libcdata_btree_node_remove_sub_node(
	          node,
	          &sub_node,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_btree_node_remove_sub_node with pthread_rwlock_rdlock failing
	 */
	for( rdlock_fail_test_number = 0;
	     rdlock_fail_test_number < 10;
	     rdlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_tree_node_append_node(
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

		result = libcdata_tree_node_get_first_sub_node(
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

		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = rdlock_fail_test_number;

		result = libcdata_btree_node_remove_sub_node(
		          node,
		          &sub_node,
		          &error );

		if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

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

			/* The removal may have failed midway, the node is
			 * still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_sub_node with pthread_rwlock_wrlock failing
	 */
	for( wrlock_fail_test_number = 0;
	     wrlock_fail_test_number < 10;
	     wrlock_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_tree_node_append_node(
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

		result = libcdata_tree_node_get_first_sub_node(
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

		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = wrlock_fail_test_number;

		result = libcdata_btree_node_remove_sub_node(
		          node,
		          &sub_node,
		          &error );

		if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

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

			/* The removal may have failed midway, the node is
			 * still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node = NULL;
		}
	}

	/* Test libcdata_btree_node_remove_sub_node with pthread_rwlock_destroy failing
	 */
	for( destroy_fail_test_number = 0;
	     destroy_fail_test_number < 10;
	     destroy_fail_test_number++ )
	{
		/* Free the tree between tests
		 */
		result = libcdata_tree_node_free(
		          &node,
		          &libcdata_btree_values_list_free,
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
		          &sub_node,
		          &libcdata_btree_values_list_free,
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

		result = libcdata_tree_node_append_node(
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

		result = libcdata_tree_node_get_first_sub_node(
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

		cdata_test_pthread_rwlock_destroy_attempts_before_fail = destroy_fail_test_number;

		result = libcdata_btree_node_remove_sub_node(
		          node,
		          &sub_node,
		          &error );

		if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
		{
			cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

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

			/* The removal may have failed midway, the node is
			 * still the top of the tree, free it to release
			 * the entire tree
			 */
			result = libcdata_tree_node_free(
			          &node,
			          &libcdata_btree_values_list_free,
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

			sub_node = NULL;
		}
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Initialize test
	 */
	result = libcdata_tree_node_initialize(
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
	result = libcdata_btree_node_remove_sub_node(
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

	result = libcdata_btree_node_remove_sub_node(
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

	/* Clean up
	 */
	result = libcdata_tree_node_free(
	          &sub_node,
	          &libcdata_btree_values_list_free,
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

	/* Test error cases
	 */
	sub_node = NULL;

	result = libcdata_btree_node_remove_sub_node(
	          node,
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

	sub_node = (libcdata_tree_node_t *) 0x12345678UL;

	result = libcdata_btree_node_remove_sub_node(
	          node,
	          &sub_node,
	          &error );

	sub_node = NULL;

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
	          &libcdata_btree_values_list_free,
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
	if( sub_node != NULL )
	{
		libcdata_tree_node_free(
		 &sub_node,
		 &libcdata_btree_values_list_free,
		 NULL );
	}
	if( node != NULL )
	{
		libcdata_tree_node_free(
		 &node,
		 &libcdata_btree_values_list_free,
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
	 "libcdata_btree_node_get_sub_node_by_value",
	 cdata_test_btree_node_get_sub_node_by_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_get_upper_node_by_value",
	 cdata_test_btree_node_get_upper_node_by_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_append_value",
	 cdata_test_btree_node_append_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_insert_value",
	 cdata_test_btree_node_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_replace_value",
	 cdata_test_btree_node_replace_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_flatten_node",
	 cdata_test_btree_node_flatten_node );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_remove_sub_node",
	 cdata_test_btree_node_remove_sub_node );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_remove_value",
	 cdata_test_btree_node_remove_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_split",
	 cdata_test_btree_node_split );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */
}

