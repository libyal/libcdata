/*
 * Library balanced tree values list test program
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
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "cdata_test_libcdata.h"
#include "cdata_test_libcerror.h"
#include "cdata_test_macros.h"
#include "cdata_test_memory.h"
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_btree_values_list.h"
#include "../libcdata/libcdata_list.h"
#include "../libcdata/libcdata_list_element.h"

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

int cdata_test_btree_values_list_value_free_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_btree_values_list_value_free_function(
     int **value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_btree_values_list_value_free_function";

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
	if( cdata_test_btree_values_list_value_free_function_return_value != 1 )
	{
		return( cdata_test_btree_values_list_value_free_function_return_value );
	}
	if( *value != NULL )
	{
		memory_free(
		 *value );

		*value = NULL;
	}
	return( 1 );
}

/* Tests the libcdata_btree_values_list_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_values_list_free(
     void )
{
	libcdata_list_t *values_list = NULL;
	libcerror_error_t *error     = NULL;
	int result                   = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &values_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list",
	 values_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_btree_values_list_free(
	          &values_list,
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
	result = libcdata_btree_values_list_free(
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
	if( values_list != NULL )
	{
		libcdata_list_free(
		 &values_list,
		 NULL,
		 &error );
	}
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_values_list_remove_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_values_list_remove_element(
      void )
{
	libcdata_list_t *values_list          = NULL;
	libcdata_list_element_t *element      = NULL;
	libcdata_list_element_t *test_element = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int number_of_elements                = 0;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &values_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list",
	 values_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 10;

	result = libcdata_list_element_set_value(
	          element,
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

	result = libcdata_list_append_element(
	          values_list,
	          element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element = NULL;

	result = libcdata_list_element_initialize(
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 20;

	result = libcdata_list_element_set_value(
	          element,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list,
	          element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element = NULL;

	result = libcdata_list_get_number_of_elements(
	          values_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_get_last_element(
	          values_list,
	          &test_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_element",
	 test_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* libcdata_btree_values_list_remove_element will free the element but not the value.
	 */
	result = libcdata_btree_values_list_remove_element(
	          values_list,
	          &test_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_element",
	 test_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_get_number_of_elements(
	          values_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
	memory_free(
	 value2 );

	value2 = NULL;

	/* Test error cases
	 */
	result = libcdata_btree_values_list_remove_element(
	          NULL,
	          &test_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_btree_values_list_remove_element(
	          values_list,
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
	result = libcdata_list_free(
	          &values_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list",
	 values_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

 on_error:
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
	if( test_element != NULL )
	{
		libcdata_list_element_free(
		 &test_element,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
		 &error );
	}
	if( element != NULL )
	{
		libcdata_list_element_free(
		 &element,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
		 &error );
	}
	if( values_list != NULL )
	{
		libcdata_list_free(
		 &values_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
		 &error );
	}
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libcdata_btree_values_list_replace_element_with_previous function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_btree_values_list_replace_element_with_previous(
      void )
{
	libcdata_list_t *values_list          = NULL;
	libcdata_list_element_t *element      = NULL;
	libcdata_list_element_t *test_element = NULL;
	libcerror_error_t *error              = NULL;
	int *replacement_value                = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int number_of_elements                = 0;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &values_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "values_list",
	 values_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 100;

	result = libcdata_list_element_set_value(
	          element,
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

	result = libcdata_list_append_element(
	          values_list,
	          element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element = NULL;

	result = libcdata_list_element_initialize(
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 200;

	result = libcdata_list_element_set_value(
	          element,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          values_list,
	          element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element = NULL;

	result = libcdata_list_get_number_of_elements(
	          values_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_get_last_element(
	          values_list,
	          &test_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_element",
	 test_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_btree_values_list_replace_element_with_previous(
	          values_list,
	          &test_element,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_element",
	 test_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test regular cases
	 */
	/* libcdata_btree_values_list_replace_element_with_previous will free the element but not the value.
	 */
	result = libcdata_btree_values_list_replace_element_with_previous(
	          values_list,
	          &test_element,
	          (intptr_t **) &replacement_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_element",
	 test_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "replacement_value",
	 replacement_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "replacement_value",
	 (int) *replacement_value,
	 100 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_get_number_of_elements(
	          values_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Clean up
	 */
	memory_free(
	 value2 );

	value2 = NULL;

	/* Test error cases
	 */
	result = libcdata_btree_values_list_replace_element_with_previous(
	          NULL,
	          &test_element,
	          (intptr_t **) &replacement_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_btree_values_list_replace_element_with_previous(
	          values_list,
	          NULL,
	          (intptr_t **) &replacement_value,
	          &error );

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
	result = libcdata_list_free(
	          &values_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "values_list",
	 values_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

 on_error:
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
	if( element != NULL )
	{
		libcdata_list_element_free(
		 &element,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
		 &error );
	}
	if( values_list != NULL )
	{
		libcdata_list_free(
		 &values_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_btree_values_list_value_free_function,
		 &error );
	}
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
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
	 "libcdata_btree_values_list_free",
	 cdata_test_btree_values_list_free );

	CDATA_TEST_RUN(
	 "libcdata_btree_values_list_remove_element",
	 cdata_test_btree_values_list_remove_element );

	CDATA_TEST_RUN(
	 "libcdata_btree_values_list_replace_element_with_previous",
	 cdata_test_btree_values_list_replace_element_with_previous );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

on_error:
	return( EXIT_FAILURE );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */
}
