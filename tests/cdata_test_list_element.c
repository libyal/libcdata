/*
 * Library list element type test program
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

/* Tests the libcdata_list_element_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_initialize(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

	/* Test libcdata_list_element_initialize without entries
	 */
	result = libcdata_list_element_initialize(
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NOT_NULL(
         "list_element",
         list_element );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libcdata_list_element_free(
	          &list_element,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CDATA_TEST_ASSERT_IS_NULL(
         "list_element",
         list_element );

        CDATA_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libcdata_list_element_initialize(
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

	list_element = (libcdata_list_element_t *) 0x12345678UL;

	result = libcdata_list_element_initialize(
	          &list_element,
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

	list_element = NULL;

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_element_initialize with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_element_initialize(
	          &list_element,
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
		 "list_element",
		 list_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_list_element_initialize with memset failing
	 */
	cdata_test_memset_attempts_before_fail = 0;

	result = libcdata_list_element_initialize(
	          &list_element,
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
		 "list_element",
		 list_element );

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
	if( list_element != NULL )
	{
		libcdata_list_element_free(
		 &list_element,
		 NULL,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_element_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_free(
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

/* Tests the libcdata_list_element_get_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_get_value(
     void )
{
	libcerror_error_t *error = NULL;
	intptr_t *value          = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_get_value(
	          NULL,
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

/* Tests the libcdata_list_element_set_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_set_value(
     void )
{
	libcerror_error_t *error = NULL;
	intptr_t *value          = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_set_value(
	          NULL,
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

/* Tests the libcdata_list_element_get_previous_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_get_previous_element(
     void )
{
	libcdata_list_element_t *previous_element = NULL;
	libcerror_error_t *error                  = NULL;
	int result                                = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_get_previous_element(
	          NULL,
	          &previous_element,
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

/* Tests the libcdata_list_element_set_previous_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_set_previous_element(
     void )
{
	libcdata_list_element_t *previous_element = NULL;
	libcerror_error_t *error                  = NULL;
	int result                                = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_set_previous_element(
	          NULL,
	          previous_element,
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

/* Tests the libcdata_list_element_get_next_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_get_next_element(
     void )
{
	libcdata_list_element_t *next_element = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_get_next_element(
	          NULL,
	          &next_element,
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

/* Tests the libcdata_list_element_set_next_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_set_next_element(
     void )
{
	libcdata_list_element_t *next_element = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_set_next_element(
	          NULL,
	          next_element,
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

/* Tests the libcdata_list_element_get_elements function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_get_elements(
     void )
{
	libcdata_list_element_t *next_element     = NULL;
	libcdata_list_element_t *previous_element = NULL;
	libcerror_error_t *error                  = NULL;
	int result                                = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_get_elements(
	          NULL,
	          &previous_element,
	          &next_element,
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

/* Tests the libcdata_list_element_set_elements function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_element_set_elements(
     void )
{
	libcdata_list_element_t *next_element     = NULL;
	libcdata_list_element_t *previous_element = NULL;
	libcerror_error_t *error                  = NULL;
	int result                                = 0;

	/* Test error cases
	 */
	result = libcdata_list_element_set_elements(
	          NULL,
	          previous_element,
	          next_element,
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
	 "libcdata_list_element_initialize",
	 cdata_test_list_element_initialize )

	CDATA_TEST_RUN(
	 "libcdata_list_element_free",
	 cdata_test_list_element_free )

	CDATA_TEST_RUN(
	 "libcdata_list_element_get_value",
	 cdata_test_list_element_get_value )

	CDATA_TEST_RUN(
	 "libcdata_list_element_set_value",
	 cdata_test_list_element_set_value )

	CDATA_TEST_RUN(
	 "libcdata_list_element_get_previous_element",
	 cdata_test_list_element_get_previous_element )

	CDATA_TEST_RUN(
	 "libcdata_list_element_set_previous_element",
	 cdata_test_list_element_set_previous_element )

	CDATA_TEST_RUN(
	 "libcdata_list_element_get_next_element",
	 cdata_test_list_element_get_next_element )

	CDATA_TEST_RUN(
	 "libcdata_list_element_set_next_element",
	 cdata_test_list_element_set_next_element )

	CDATA_TEST_RUN(
	 "libcdata_list_element_get_elements",
	 cdata_test_list_element_get_elements )

	CDATA_TEST_RUN(
	 "libcdata_list_element_set_elements",
	 cdata_test_list_element_set_elements )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

