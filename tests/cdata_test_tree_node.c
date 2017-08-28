/*
 * Library tree node type test program
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

	/* Test libcdata_tree_node_initialize without entries
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
	 cdata_test_tree_node_initialize )

	CDATA_TEST_RUN(
	 "libcdata_tree_node_free",
	 cdata_test_tree_node_free )

	/* TODO add tests for libcdata_tree_node_empty */
	/* TODO add tests for libcdata_tree_node_clone */
	/* TODO add tests for libcdata_tree_node_get_value */
	/* TODO add tests for libcdata_tree_node_set_value */
	/* TODO add tests for libcdata_tree_node_get_parent_node */
	/* TODO add tests for libcdata_tree_node_set_parent_node */
	/* TODO add tests for libcdata_tree_node_get_previous_node */
	/* TODO add tests for libcdata_tree_node_set_previous_node */
	/* TODO add tests for libcdata_tree_node_get_next_node */
	/* TODO add tests for libcdata_tree_node_set_next_node */
	/* TODO add tests for libcdata_tree_node_get_nodes */
	/* TODO add tests for libcdata_tree_node_set_nodes */
	/* TODO add tests for libcdata_tree_node_append_value */
	/* TODO add tests for libcdata_tree_node_insert_node */
	/* TODO add tests for libcdata_tree_node_insert_value */
	/* TODO add tests for libcdata_tree_node_replace_node */
	/* TODO add tests for libcdata_tree_node_remove_node */
	/* TODO add tests for libcdata_tree_node_get_number_of_sub_nodes */
	/* TODO add tests for libcdata_tree_node_get_sub_node_by_index */
	/* TODO add tests for libcdata_tree_node_get_leaf_node_list */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

