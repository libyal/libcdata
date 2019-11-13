/*
 * Library balanced tree type test program
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
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_btree_node.h"
#include "../libcdata/libcdata_btree_values_list.h"

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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_btree_node_get_sub_node_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_node_get_sub_node_by_value(
     void )
{
	libcdata_list_t *values_list1                 = NULL;
	libcdata_list_element_t *values_list_element  = NULL;
	libcdata_list_element_t *values_list_element1 = NULL;
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *sub_node                = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

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
	libcdata_tree_node_t *node = NULL;
	libcerror_error_t *error   = NULL;
	int result                 = 0;
	int value1                 = 1;
	int value2                 = 2;

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
	libcdata_tree_node_t *sub_node1 = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;
	int value1                      = 1;
	int value2                      = 2;

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
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int replacement_value                         = 99;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

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
	libcdata_tree_node_t *node                    = NULL;
	libcdata_tree_node_t *sub_node1               = NULL;
	libcdata_tree_node_t *sub_node2               = NULL;
	libcerror_error_t *error                      = NULL;
	int replacement_value                         = 99;
	int result                                    = 0;
	int value1                                    = 1;
	int value2                                    = 2;

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
	libcdata_tree_node_t *node = NULL;
	libcerror_error_t *error   = NULL;
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

	/* TODO add tests for libcdata_btree_node_flatten_node */

	/* TODO add tests for libcdata_btree_node_remove_sub_node */

	CDATA_TEST_RUN(
	 "libcdata_btree_node_remove_value",
	 cdata_test_btree_node_remove_value );

	CDATA_TEST_RUN(
	 "libcdata_btree_node_split",
	 cdata_test_btree_node_split );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

