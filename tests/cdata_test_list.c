/*
 * Library list type test program
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

#include "../libcdata/libcdata_list.h"
#include "../libcdata/libcdata_list_element.h"

int cdata_test_list_value_free_function_return_value  = 1;
int cdata_test_list_value_clone_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_list_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_list_value_free_function_return_value );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_list_value_clone_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_list_value_clone_function_return_value );
}

/* Test element compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_list_element_compare_function(
     intptr_t *first_value,
     intptr_t *second_value,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_list_element_compare_function";

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

/* Tests the libcdata_list_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_initialize(
     void )
{
	libcdata_list_t *list           = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 2;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_list_initialize(
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

	list = (libcdata_list_t *) 0x12345678UL;

	result = libcdata_list_initialize(
	          &list,
	          &error );

	list = NULL;

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
		/* Test libcdata_list_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_list_initialize(
		          &list,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( list != NULL )
			{
				libcdata_list_free(
				 &list,
				 &cdata_test_list_value_free_function,
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
			 "list",
			 list );

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
		/* Test libcdata_list_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_list_initialize(
		          &list,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( list != NULL )
			{
				libcdata_list_free(
				 &list,
				 &cdata_test_list_value_free_function,
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
			 "list",
			 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_free(
     void )
{
#if defined( HAVE_CDATA_TEST_RWLOCK )
	libcdata_list_t *list    = NULL;
#endif

	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_list_free(
	          NULL,
	          &cdata_test_list_value_free_function,
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

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_free with pthread_rwlock_destroy failing in libcthreads_read_write_lock_free
	 */
	cdata_test_pthread_rwlock_destroy_attempts_before_fail = 0;

	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

		/* Clean up
		 */
		result = libcdata_list_free(
		          &list,
		          &cdata_test_list_value_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "list",
		 list );

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
		 "list",
		 list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
#if defined( HAVE_CDATA_TEST_RWLOCK )
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
#endif
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_list_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_list_empty(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_list_empty(
	          (libcdata_internal_list_t *) list,
	          &cdata_test_list_value_free_function,
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
	result = libcdata_internal_list_empty(
	          NULL,
	          &cdata_test_list_value_free_function,
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
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_list_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_empty(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_empty(
	          list,
	          &cdata_test_list_value_free_function,
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
	result = libcdata_list_empty(
	          NULL,
	          &cdata_test_list_value_free_function,
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

	/* Test libcdata_list_empty with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_empty(
	          list,
	          &cdata_test_list_value_free_function,
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
	/* Test libcdata_list_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_empty(
	          list,
	          &cdata_test_list_value_free_function,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_clone(
     void )
{
	libcdata_list_t *destination_list = NULL;
	libcdata_list_t *source_list      = NULL;
	libcerror_error_t *error          = NULL;
	int element_value2                = 2;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &source_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_list",
	 source_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          source_list,
	          (intptr_t *) &element_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_clone with intialized list
	 */
	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_list",
	 destination_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &destination_list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_list",
	 destination_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_clone with non-intialized list
	 */
	result = libcdata_list_clone(
	          &destination_list,
	          NULL,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_list",
	 destination_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_list_clone(
	          NULL,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_list",
	 destination_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_list = (libcdata_list_t *) 0x12345678UL;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	destination_list = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          NULL,
	          &cdata_test_list_value_clone_function,
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

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_clone with malloc failing in libcdata_list_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 &cdata_test_list_value_free_function,
			 &error );
		}
	}
	else
	{
		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "destination_list",
		 destination_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

/* TODO: Test libcdata_list_initialize returning NULL destination_list */

	/* Test libcdata_list_clone with value_clone_function failing
	 */
	cdata_test_list_value_clone_function_return_value = -1;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	cdata_test_list_value_clone_function_return_value = 1;

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

	/* Test libcdata_list_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 &cdata_test_list_value_free_function,
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
	/* Test libcdata_list_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 5;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          &cdata_test_list_value_free_function,
	          &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 &cdata_test_list_value_free_function,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &source_list,
	          &cdata_test_list_value_free_function,
	          &error );

/* TODO this fails on MacOS and CygWin with "Resource busy"
	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );
*/
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_list",
	 source_list );

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
	if( source_list != NULL )
	{
		libcdata_list_free(
		 &source_list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_get_number_of_elements function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_get_number_of_elements(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int number_of_elements   = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to retrieve the number of entries on an empty list
	 */
	result = libcdata_list_get_number_of_elements(
	          list,
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

	/* Test to retrieve the number of entries on a non-empty list
	 */
/* TODO implement */

	/* Test error cases
	 */
	result = libcdata_list_get_number_of_elements(
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

	result = libcdata_list_get_number_of_elements(
	          list,
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

	/* Test libcdata_list_get_number_of_elements with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_number_of_elements(
	          list,
	          &number_of_elements,
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
	/* Test libcdata_list_get_number_of_elements with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_number_of_elements(
	          list,
	          &number_of_elements,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_get_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_get_first_element(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcdata_list_element_t *list_element = NULL;
	libcerror_error_t *error              = NULL;
	int element_value2                    = 2;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_get_first_element(
	          list,
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

	/* Test error cases
	 */
	result = libcdata_list_get_first_element(
	          NULL,
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

	result = libcdata_list_get_first_element(
	          list,
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

	/* Test libcdata_list_get_first_element with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_first_element(
	          list,
	          &list_element,
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
	/* Test libcdata_list_get_first_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_first_element(
	          list,
	          &list_element,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_list_set_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_list_set_first_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_list_set_first_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_internal_list_set_first_element(
	          (libcdata_internal_list_t *) list,
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
	result = libcdata_internal_list_set_first_element(
	          NULL,
	          element1,
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
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element1",
	 element1 );

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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_set_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_set_first_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_set_first_element(
	          list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_set_first_element(
	          list,
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
	result = libcdata_list_set_first_element(
	          NULL,
	          element1,
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

	/* Test libcdata_list_set_first_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_set_first_element(
	          list,
	          element1,
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
	/* Test libcdata_list_set_first_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 1;

	result = libcdata_list_set_first_element(
	          list,
	          element1,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element1",
	 element1 );

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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_list_get_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_get_last_element(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcdata_list_element_t *list_element = NULL;
	libcerror_error_t *error              = NULL;
	int element_value2                    = 2;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_get_last_element(
	          list,
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

	/* Test error cases
	 */
	result = libcdata_list_get_last_element(
	          NULL,
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

	result = libcdata_list_get_last_element(
	          list,
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

	/* Test libcdata_list_get_last_element with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_last_element(
	          list,
	          &list_element,
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
	/* Test libcdata_list_get_last_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_last_element(
	          list,
	          &list_element,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_list_set_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_list_set_last_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_list_set_last_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_internal_list_set_last_element(
	          (libcdata_internal_list_t *) list,
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
	result = libcdata_internal_list_set_last_element(
	          NULL,
	          element1,
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
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element1",
	 element1 );

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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_set_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_set_last_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_set_last_element(
	          list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_set_last_element(
	          list,
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
	result = libcdata_list_set_last_element(
	          NULL,
	          element1,
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

	/* Test libcdata_list_set_last_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_set_last_element(
	          list,
	          element1,
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
	/* Test libcdata_list_set_last_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 1;

	result = libcdata_list_set_last_element(
	          list,
	          element1,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element1",
	 element1 );

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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_list_get_element_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_get_element_by_index(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcdata_list_element_t *list_element = NULL;
	libcerror_error_t *error              = NULL;
	int element_value2                    = 2;
	int result                            = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_get_element_by_index(
	          list,
	          0,
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

	/* Test error cases
	 */
	result = libcdata_list_get_element_by_index(
	          NULL,
	          0,
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

	result = libcdata_list_get_element_by_index(
	          list,
	          -1,
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

	result = libcdata_list_get_element_by_index(
	          list,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_list_get_element_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_element_by_index(
	          list,
	          0,
	          &list_element,
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
	/* Test libcdata_list_get_element_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_element_by_index(
	          list,
	          0,
	          &list_element,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_get_value_by_index(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	intptr_t *element_value  = NULL;
	int element_value2       = 2;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          &element_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element_value",
	 element_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_list_get_value_by_index(
	          NULL,
	          0,
	          &element_value,
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

	/* Test cdata_test_list_get_value_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          &element_value,
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
	/* Test cdata_test_list_get_value_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          &element_value,
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
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_prepend_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_prepend_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcdata_list_element_t *element2 = NULL;
	libcdata_list_element_t *element3 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element2",
	 element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_prepend_element(
	          list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_prepend_element(
	          list,
	          element2,
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
	result = libcdata_list_prepend_element(
	          NULL,
	          element3,
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

	result = libcdata_list_prepend_element(
	          list,
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

	/* Test libcdata_list_prepend_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
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
	/* Test libcdata_list_prepend_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
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
#else
	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element3,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_prepend_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_prepend_value(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int element_value1       = 1;
	int element_value2       = 2;
	int element_value3       = 3;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_prepend_value(
	          NULL,
	          (intptr_t *) &element_value3,
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

	/* Test libcdata_list_prepend_value with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value3,
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

	/* Test libcdata_list_prepend_value with pthread_rwlock_wrlock failing in libcdata_list_prepend_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) &element_value3,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_append_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_append_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcdata_list_element_t *element2 = NULL;
	libcdata_list_element_t *element3 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element2",
	 element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_append_element(
	          list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          list,
	          element2,
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
	result = libcdata_list_append_element(
	          NULL,
	          element3,
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

	result = libcdata_list_append_element(
	          list,
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

	/* Test libcdata_list_append_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_append_element(
	          list,
	          element3,
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
	/* Test libcdata_list_append_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_list_append_element(
	          list,
	          element3,
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
#else
	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element3,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_append_value(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int element_value1       = 1;
	int element_value2       = 2;
	int element_value3       = 3;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value2,
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
	result = libcdata_list_append_value(
	          NULL,
	          (intptr_t *) &element_value3,
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

	/* Test libcdata_list_append_value with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value3,
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

	/* Test libcdata_list_append_value with pthread_rwlock_wrlock failing in libcdata_list_append_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) &element_value3,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_insert_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_insert_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcdata_list_element_t *element2 = NULL;
	libcdata_list_element_t *element3 = NULL;
	libcerror_error_t *error          = NULL;
	int element_value1                = 1;
	int element_value2                = 2;
	int element_value3                = 3;
	int result                        = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          element1,
	          (intptr_t *) &element_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element2",
	 element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          element2,
	          (intptr_t *) &element_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_value(
	          element3,
	          (intptr_t *) &element_value3,
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
	result = libcdata_list_insert_element(
	          list,
	          element1,
	          &cdata_test_list_element_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element1 = NULL;

	result = libcdata_list_insert_element(
	          list,
	          element2,
	          &cdata_test_list_element_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element2 = NULL;

	/* Test error cases
	 */
	result = libcdata_list_insert_element(
	          NULL,
	          element3,
	          &cdata_test_list_element_compare_function,
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

	result = libcdata_list_insert_element(
	          list,
	          NULL,
	          &cdata_test_list_element_compare_function,
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

	result = libcdata_list_insert_element(
	          list,
	          element3,
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

	result = libcdata_list_insert_element(
	          list,
	          element3,
	          &cdata_test_list_element_compare_function,
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

	( (libcdata_internal_list_element_t *) element3 )->previous_element = (libcdata_list_element_t *) 0x12345678UL;;

	result = libcdata_list_insert_element(
	          list,
	          element3,
	          &cdata_test_list_element_compare_function,
	          0,
	          &error );

	( (libcdata_internal_list_element_t *) element3 )->previous_element = NULL;

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

	/* Test libcdata_list_insert_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_insert_element(
	          list,
	          element3,
	          &cdata_test_list_element_compare_function,
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
	/* Test libcdata_list_insert_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 6;

	result = libcdata_list_insert_element(
	          list,
	          element3,
	          &cdata_test_list_element_compare_function,
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
	element3 = NULL;

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	if( element3 != NULL )
	{
		result = libcdata_list_element_free(
		          &element3,
		          &cdata_test_list_value_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "element3",
		 element3 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_insert_value(
     void )
{
	libcdata_list_t *list    = NULL;
	libcerror_error_t *error = NULL;
	int element_value1       = 0;
	int element_value2       = 2;
	int element_value3       = 3;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_list_insert_value(
	          list,
	          (intptr_t *) &element_value1,
	          &cdata_test_list_element_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_insert_value(
	          list,
	          (intptr_t *) &element_value2,
	          &cdata_test_list_element_compare_function,
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
	result = libcdata_list_insert_value(
	          NULL,
	          (intptr_t *) &element_value3,
	          &cdata_test_list_element_compare_function,
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

	/* Test libcdata_list_insert_value with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_insert_value(
	          list,
	          (intptr_t *) &element_value3,
	          &cdata_test_list_element_compare_function,
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
	/* Test libcdata_list_insert_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_insert_value(
	          list,
	          (intptr_t *) &element_value3,
	          &cdata_test_list_element_compare_function,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_remove_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_remove_element(
     void )
{
	libcdata_list_t *list                    = NULL;
	libcdata_list_element_t *element1        = NULL;
	libcdata_list_element_t *element1_backup = NULL;
	libcdata_list_element_t *element2        = NULL;
	libcdata_list_element_t *element3        = NULL;
	libcdata_list_element_t *element3_backup = NULL;
	libcdata_list_element_t *element4        = NULL;
	libcerror_error_t *error                 = NULL;
	int number_of_elements                   = 0;
	int result                               = 0;

	/* Initialize test
	 */
	result = libcdata_list_initialize(
	          &list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element1",
	 element1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element1_backup = element1;

	result = libcdata_list_append_element(
	          list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element1 = NULL;

	result = libcdata_list_element_initialize(
	          &element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element2",
	 element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          list,
	          element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element2 = NULL;

	result = libcdata_list_element_initialize(
	          &element3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element3",
	 element3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element3_backup = element3;

	result = libcdata_list_append_element(
	          list,
	          element3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element3 = NULL;

	result = libcdata_list_element_initialize(
	          &element4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element4",
	 element4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test remove element part of the list
	 */
	result = libcdata_list_get_number_of_elements(
	          list,
	          &number_of_elements,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_elements",
	 number_of_elements,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_remove_element(
	          list,
	          element1_backup,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1_backup,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element1_backup",
	 element1_backup );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_get_number_of_elements(
	          list,
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

	/* Test remove element of element not part of the list
	 */
#ifdef TODO
/* TODO implement tracking the list an element is part of */

	result = libcdata_list_remove_element(
	          list,
	          element4,
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

#endif /* TODO */

	/* Test error cases
	 */
	result = libcdata_list_remove_element(
	          NULL,
	          element3,
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

	result = libcdata_list_remove_element(
	          list,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_remove_element(
	          list,
	          element3_backup,
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
	/* Test libcdata_list_remove_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * WARNING: after this test the lock is still active
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_list_remove_element(
	          list,
	          element3_backup,
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
	result = libcdata_list_element_free(
	          &element3_backup,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element3_backup",
	 element3_backup );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list",
	 list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element4,
	          &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element4",
	 element4 );

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
	if( element4 != NULL )
	{
		libcdata_list_element_free(
		 &element4,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 &cdata_test_list_value_free_function,
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
	 "libcdata_list_initialize",
	 cdata_test_list_initialize );

	CDATA_TEST_RUN(
	 "libcdata_list_free",
	 cdata_test_list_free );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_list_empty",
	 cdata_test_internal_list_empty );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_list_empty",
	 cdata_test_list_empty );

	CDATA_TEST_RUN(
	 "libcdata_list_clone",
	 cdata_test_list_clone );

	CDATA_TEST_RUN(
	 "libcdata_list_get_number_of_elements",
	 cdata_test_list_get_number_of_elements );

	CDATA_TEST_RUN(
	 "libcdata_list_get_first_element",
	 cdata_test_list_get_first_element );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_list_set_first_element",
	 cdata_test_internal_list_set_first_element );

	CDATA_TEST_RUN(
	 "libcdata_list_set_first_element",
	 cdata_test_list_set_first_element );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_list_get_last_element",
	 cdata_test_list_get_last_element );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_list_set_last_element",
	 cdata_test_internal_list_set_last_element );

	CDATA_TEST_RUN(
	 "libcdata_list_set_last_element",
	 cdata_test_list_set_last_element );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_list_get_element_by_index",
	 cdata_test_list_get_element_by_index );

	CDATA_TEST_RUN(
	 "libcdata_list_get_value_by_index",
	 cdata_test_list_get_value_by_index );

	CDATA_TEST_RUN(
	 "libcdata_list_prepend_element",
	 cdata_test_list_prepend_element );

	CDATA_TEST_RUN(
	 "libcdata_list_prepend_value",
	 cdata_test_list_prepend_value );

	CDATA_TEST_RUN(
	 "libcdata_list_append_element",
	 cdata_test_list_append_element );

	CDATA_TEST_RUN(
	 "libcdata_list_append_value",
	 cdata_test_list_append_value );

	CDATA_TEST_RUN(
	 "libcdata_list_insert_element",
	 cdata_test_list_insert_element );

	CDATA_TEST_RUN(
	 "libcdata_list_insert_value",
	 cdata_test_list_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_list_remove_element",
	 cdata_test_list_remove_element );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

