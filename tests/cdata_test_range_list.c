/*
 * Library range list type testing program
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
int cdata_test_range_list_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( 1 );
}

/* Tests the libcdata_range_list_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_initialize(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Test libcdata_range_list_initialize without entries
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_range_list_free(
	          &range_list,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_initialize(
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

	range_list = (libcdata_range_list_t *) 0x12345678UL;

	result = libcdata_range_list_initialize(
	          &range_list,
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

	range_list = NULL;

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_range_list_initialize with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_range_list_initialize(
	          &range_list,
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
		 "range_list",
		 range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_range_list_initialize with memset failing
	 */
	cdata_test_memset_attempts_before_fail = 0;

	result = libcdata_range_list_initialize(
	          &range_list,
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
		 "range_list",
		 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_range_list_free(
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

/* Tests the libcdata_range_list_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_empty(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test range_list empty
	 */
	result = libcdata_range_list_empty(
	          range_list,
	          &cdata_test_range_list_value_free_function,
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
	result = libcdata_range_list_empty(
	          NULL,
	          &cdata_test_range_list_value_free_function,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_number_of_elements function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_number_of_elements(
     void )
{
	libcdata_range_list_t *range_list    = NULL;
	libcerror_error_t *error = NULL;
	int number_of_elements   = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test retrieve number of elements
	 */
	result = libcdata_range_list_get_number_of_elements(
	          range_list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 0 );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_get_number_of_elements(
	          NULL,
	          &number_of_elements,
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

	result = libcdata_range_list_get_number_of_elements(
	          range_list,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_insert_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_insert_range(
	          NULL,
	          0,
	          1024,
	          (intptr_t *) &value1,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_remove_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_remove_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test remove range
	 */

	/* Test error cases
	 */
	result = libcdata_range_list_remove_range(
	          NULL,
	          0,
	          1024,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_range_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_range_by_index(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	intptr_t *value                   = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_get_range_by_index(
	          NULL,
	          0,
	          &range_start,
	          &range_size,
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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_range_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_range_at_offset(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	intptr_t *value                   = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_get_range_at_offset(
	          NULL,
	          0,
	          &range_start,
	          &range_size,
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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_range_is_present function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_range_is_present(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_range_is_present(
	          NULL,
	          0,
	          1024,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_spanning_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_spanning_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	uint64_t range_size               = 0;
	uint64_t range_start              = 0;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "range_list",
         range_list );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_range_list_get_spanning_range(
	          NULL,
	          &range_start,
	          &range_size,
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
	result = libcdata_range_list_free(
	          &range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "range_list",
         range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
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
	 "libcdata_range_list_initialize",
	 cdata_test_range_list_initialize )

	CDATA_TEST_RUN(
	 "libcdata_range_list_free",
	 cdata_test_range_list_free )

	CDATA_TEST_RUN(
	 "libcdata_range_list_empty",
	 cdata_test_range_list_empty )

	/* TODO add tests for libcdata_range_list_clone */

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_number_of_elements",
	 cdata_test_range_list_get_number_of_elements )

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_range",
	 cdata_test_range_list_insert_range )

	/* TODO add tests for libcdata_range_list_insert_range_list */

	CDATA_TEST_RUN(
	 "libcdata_range_list_remove_range",
	 cdata_test_range_list_remove_range )

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_by_index",
	 cdata_test_range_list_get_range_by_index )

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_at_offset",
	 cdata_test_range_list_get_range_at_offset )

	CDATA_TEST_RUN(
	 "libcdata_range_list_range_is_present",
	 cdata_test_range_list_range_is_present )

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_spanning_range",
	 cdata_test_range_list_spanning_range )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

