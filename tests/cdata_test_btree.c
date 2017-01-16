/*
 * Library balanced tree type test program
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

/* Test value compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_btree_value_compare_function(
     intptr_t *first_value,
     intptr_t *second_value,
     libcdata_error_t **error )
{
	static char *function    = "cdata_test_btree_value_compare_function";
	int first_compare_value  = 0;
	int second_compare_value = 0;

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
	/* This is necessary otherwise the comparision messes up
	 * as in e.g. 5 > 6 is true.
         */
	first_compare_value  = (int) *first_value;
	second_compare_value = (int) *second_value;

	if( first_compare_value < second_compare_value )
	{
		return( LIBCDATA_COMPARE_LESS );
	}
	else if( first_compare_value > second_compare_value )
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
	libcdata_btree_t *btree  = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

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

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	btree = NULL;

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

	/* Test libcdata_btree_initialize with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_btree_initialize(
	          &btree,
	          10,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "btree",
		 btree );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_btree_initialize with memset failing
	 */
	cdata_test_memset_attempts_before_fail = 0;

	result = libcdata_btree_initialize(
	          &btree,
	          10,
	          &error );

	if( cdata_test_memset_attempts_before_fail != -1 )
	{
		cdata_test_memset_attempts_before_fail = -1;
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
	libcerror_error_t *error = NULL;
	int number_of_values     = 0;
	int result               = 0;

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_get_value_by_index(
     void )
{
	libcerror_error_t *error = NULL;
	intptr_t *value          = NULL;
	int result               = 0;

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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_insert_value(
     void )
{
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *existing_value         = NULL;
	intptr_t *value                  = NULL;
	int result                       = 0;
	int value_index                  = 0;

	/* Test error cases
	 */
	result = libcdata_btree_insert_value(
	          NULL,
	          &value_index,
	          value,
	          &cdata_test_btree_value_compare_function,
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

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_remove_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_remove_value(
     void )
{
	libcdata_tree_node_t *upper_node = NULL;
	libcerror_error_t *error         = NULL;
	intptr_t *value                  = NULL;
	int result                       = 0;
	int value_index                  = 0;

	/* Test error cases
	 */
	result = libcdata_btree_remove_value(
	          NULL,
	          upper_node,
	          &value_index,
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
	 "libcdata_btree_initialize",
	 cdata_test_btree_initialize )

	CDATA_TEST_RUN(
	 "libcdata_btree_free",
	 cdata_test_btree_free )

	CDATA_TEST_RUN(
	 "libcdata_btree_get_number_of_values",
	 cdata_test_btree_get_number_of_values )

	CDATA_TEST_RUN(
	 "libcdata_btree_get_value_by_index",
	 cdata_test_btree_get_value_by_index )

	/* TODO add test for libcdata_btree_get_value_by_value */

	CDATA_TEST_RUN(
	 "libcdata_btree_insert_value",
	 cdata_test_btree_insert_value )

	/* TODO add test for libcdata_btree_replace_value */

	CDATA_TEST_RUN(
	 "libcdata_btree_remove_value",
	 cdata_test_btree_remove_value )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

