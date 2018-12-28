/*
 * Library range list type test program
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

#include "../libcdata/libcdata_range_list.h"

int cdata_test_range_list_value_free_function_return_value  = 1;
int cdata_test_range_list_value_clone_function_return_value = 1;
int cdata_test_range_list_value_merge_function_return_value = 1;
int cdata_test_range_list_value_split_function_return_value = 1;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_free_function(
     intptr_t **value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_free_function_return_value );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_clone_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_clone_function_return_value );
}

/* Test value merge function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_merge_function(
     intptr_t *destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_merge_function_return_value );
}

/* Test value split function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_split_function(
     intptr_t **destination_value CDATA_TEST_ATTRIBUTE_UNUSED,
     intptr_t *source_value CDATA_TEST_ATTRIBUTE_UNUSED,
     uint64_t split_range_offset CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error CDATA_TEST_ATTRIBUTE_UNUSED )
{
	CDATA_TEST_UNREFERENCED_PARAMETER( destination_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( source_value )
	CDATA_TEST_UNREFERENCED_PARAMETER( split_range_offset )
	CDATA_TEST_UNREFERENCED_PARAMETER( error )

	return( cdata_test_range_list_value_split_function_return_value );
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

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests   = 2;
	int number_of_memset_fail_tests   = 1;
	int test_number                   = 0;
#endif

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

	range_list = NULL;

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
		/* Test libcdata_range_list_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_range_list_initialize(
		          &range_list,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( range_list != NULL )
			{
				libcdata_range_list_free(
				 &range_list,
				 &cdata_test_range_list_value_free_function,
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
			 "range_list",
			 range_list );

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
		/* Test libcdata_range_list_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_range_list_initialize(
		          &range_list,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( range_list != NULL )
			{
				libcdata_range_list_free(
				 &range_list,
				 &cdata_test_range_list_value_free_function,
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
			 "range_list",
			 range_list );

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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 &cdata_test_range_list_value_free_function,
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
	int value1                        = 1;
	int value2                        = 2;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	/* Initialize test
	 */
	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_empty with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_range_list_empty(
	          range_list,
	          &cdata_test_range_list_value_free_function,
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
	/* Test libcdata_range_list_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_empty(
	          range_list,
	          &cdata_test_range_list_value_free_function,
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

/* Tests the libcdata_range_list_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_clone(
     void )
{
	libcdata_range_list_t *destination_range_list = NULL;
	libcdata_range_list_t *source_range_list      = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;

	/* Initialize test
	 */
	result = libcdata_range_list_initialize(
	          &source_range_list,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_range_list",
	 source_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          source_range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_clone on initialized range_list
	 */
	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_free(
	          &destination_range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_range_list_clone on non-initialized range_list
	 */
	result = libcdata_range_list_clone(
	          &destination_range_list,
	          NULL,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_clone(
	          NULL,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_range_list = (libcdata_range_list_t *) 0x12345678UL;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	destination_range_list = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_range_list_clone with malloc failing
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libcdata_range_list_clone with memcpy failing
	 */
	cdata_test_memcpy_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_memcpy_attempts_before_fail != -1 )
	{
		cdata_test_memcpy_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Test libcdata_range_list_clone with value_clone_function failing in libcdata_range_list_value_clone
	 */
	cdata_test_range_list_value_clone_function_return_value = -1;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	cdata_test_range_list_value_clone_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_range_list",
	 destination_range_list );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_range_list_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 &cdata_test_range_list_value_free_function,
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
		 "destination_range_list",
		 destination_range_list );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_range_list",
	 source_range_list );

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
	if( source_range_list != NULL )
	{
		libcdata_range_list_free(
		 &source_range_list,
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
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int number_of_elements            = 0;
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

	/* Test regular cases
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_get_number_of_elements with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_number_of_elements(
	          range_list,
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
	/* Test libcdata_range_list_get_number_of_elements with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_number_of_elements(
	          range_list,
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_range_list_get_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_first_element(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;
	int value1                            = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_get_first_element(
	          range_list,
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
	result = libcdata_range_list_get_first_element(
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

	result = libcdata_range_list_get_first_element(
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_get_first_element with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_first_element(
	          range_list,
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
	/* Test libcdata_range_list_get_first_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_first_element(
	          range_list,
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

/* Tests the libcdata_internal_range_list_set_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_set_first_element(
     void )
{
	libcdata_list_element_t *first_element = NULL;
	libcdata_range_list_t *range_list      = NULL;
	libcerror_error_t *error               = NULL;
	int result                             = 0;

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

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_set_first_element(
	          (libcdata_internal_range_list_t *) range_list,
	          first_element,
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
	result = libcdata_internal_range_list_set_first_element(
	          NULL,
	          first_element,
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

/* Tests the libcdata_range_list_get_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_last_element(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;
	int value1                            = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_get_last_element(
	          range_list,
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
	result = libcdata_range_list_get_last_element(
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

	result = libcdata_range_list_get_last_element(
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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_get_last_element with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_last_element(
	          range_list,
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
	/* Test libcdata_range_list_get_last_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_last_element(
	          range_list,
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

/* Tests the libcdata_internal_range_list_set_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_set_last_element(
     void )
{
	libcdata_list_element_t *last_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int result                            = 0;

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

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_set_last_element(
	          (libcdata_internal_range_list_t *) range_list,
	          last_element,
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
	result = libcdata_internal_range_list_set_last_element(
	          NULL,
	          last_element,
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

/* Tests the libcdata_internal_range_list_append_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_append_element(
     void )
{
	libcdata_list_element_t *element1 = NULL;
	libcdata_list_element_t *element2 = NULL;
	libcdata_list_element_t *element3 = NULL;
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
	result = libcdata_internal_range_list_append_element(
	          (libcdata_internal_range_list_t *) range_list,
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

	result = libcdata_internal_range_list_append_element(
	          (libcdata_internal_range_list_t *) range_list,
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

	/* Test error cases
	 */
	result = libcdata_internal_range_list_append_element(
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

	result = libcdata_internal_range_list_append_element(
	          (libcdata_internal_range_list_t *) range_list,
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
	result = libcdata_list_element_free(
	          &element3,
	          &cdata_test_range_list_value_free_function,
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
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_range_list_value_free_function,
		 NULL );
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

/* Tests the libcdata_internal_range_list_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_append_value(
     void )
{
	libcdata_range_list_t *range_list              = NULL;
	libcdata_range_list_value_t *range_list_value1 = NULL;
	libcdata_range_list_value_t *range_list_value2 = NULL;
	libcerror_error_t *error                       = NULL;
	int result                                     = 0;

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

	result = libcdata_range_list_value_initialize(
	          &range_list_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value1",
	 range_list_value1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_initialize(
	          &range_list_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value2",
	 range_list_value2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_append_value(
	          (libcdata_internal_range_list_t *) range_list,
	          range_list_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value1 = NULL;

	/* Test error cases
	 */
	result = libcdata_internal_range_list_append_value(
	          NULL,
	          range_list_value2,
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

	/* Test libcdata_range_list_append_value with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_internal_range_list_append_value(
	          (libcdata_internal_range_list_t *) range_list,
	          range_list_value2,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		range_list_value2 = NULL;
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
	if( range_list_value2 != NULL )
	{
		result = libcdata_range_list_value_free(
		          &range_list_value2,
		          &cdata_test_range_list_value_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "range_list_value2",
		 range_list_value2 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );
	}
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
	if( range_list_value2 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value2,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list_value1 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value1,
		 &cdata_test_range_list_value_free_function,
		 NULL );
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

/* Tests the libcdata_internal_range_list_insert_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_insert_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;
	int value2                        = 2;
	int value3                        = 3;
	int value4                        = 4;

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

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_insert_range(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_internal_range_list_insert_range(
	          (libcdata_internal_range_list_t *) range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_internal_range_list_insert_range(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          96,
	          (intptr_t *) &value3,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_internal_range_list_insert_range(
	          NULL,
	          128,
	          32,
	          (intptr_t *) &value4,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_internal_range_list_insert_range(
	          (libcdata_internal_range_list_t *) range_list,
	          (uint64_t) INT64_MAX + 1,
	          32,
	          (intptr_t *) &value4,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_internal_range_list_insert_range(
	          (libcdata_internal_range_list_t *) range_list,
	          128,
	          (uint64_t) INT64_MAX + 1,
	          (intptr_t *) &value4,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_range_list_insert_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;
	int value3                        = 3;

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

	/* Test regular cases
	 */
	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_insert_range(
	          NULL,
	          128,
	          32,
	          (intptr_t *) &value3,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_range_list_insert_range(
	          range_list,
	          (uint64_t) INT64_MAX + 1,
	          32,
	          (intptr_t *) &value3,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	/* Test libcdata_range_list_insert_range with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) &value3,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	/* Test libcdata_range_list_insert_range with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 6;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) &value3,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

/* Tests the libcdata_range_list_insert_range_list function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_insert_range_list(
     void )
{
	libcdata_range_list_t *range_list        = NULL;
	libcdata_range_list_t *source_range_list = NULL;
	libcerror_error_t *error                 = NULL;
	int result                               = 0;
	int value1                               = 1;

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

	result = libcdata_range_list_initialize(
	          &source_range_list,
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

	result = libcdata_range_list_insert_range(
	          source_range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_insert_range_list(
	          range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_insert_range_list(
	          NULL,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_range_list_insert_range_list(
	          range_list,
	          NULL,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	/* Test libcdata_range_list_insert_range_list with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_range_list_insert_range_list(
	          range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	/* Test libcdata_range_list_insert_range_list with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 6;

	result = libcdata_range_list_insert_range_list(
	          range_list,
	          source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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

	result = libcdata_range_list_free(
	          &source_range_list,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_range_list",
	 source_range_list );

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
	if( source_range_list != NULL )
	{
		libcdata_range_list_free(
		 &source_range_list,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_range_list_insert_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_insert_element(
     void )
{
	libcdata_list_element_t *element1           = NULL;
	libcdata_list_element_t *element2           = NULL;
	libcdata_list_element_t *element3           = NULL;
	libcdata_list_element_t *range_list_element = NULL;
	libcdata_range_list_t *range_list           = NULL;
	libcerror_error_t *error                    = NULL;
	int result                                  = 0;

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
	result = libcdata_internal_range_list_insert_element(
	          (libcdata_internal_range_list_t *) range_list,
	          NULL,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_element = element1;
	element1           = NULL;

	result = libcdata_internal_range_list_insert_element(
	          (libcdata_internal_range_list_t *) range_list,
	          range_list_element,
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

	/* Test error cases
	 */
	result = libcdata_internal_range_list_insert_element(
	          NULL,
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

	result = libcdata_internal_range_list_insert_element(
	          (libcdata_internal_range_list_t *) range_list,
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
	result = libcdata_list_element_free(
	          &element3,
	          &cdata_test_range_list_value_free_function,
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
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_range_list_value_free_function,
		 NULL );
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

/* Tests the libcdata_internal_range_list_insert_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_insert_value(
     void )
{
	libcdata_range_list_t *range_list              = NULL;
	libcdata_range_list_value_t *range_list_value1 = NULL;
	libcdata_range_list_value_t *range_list_value2 = NULL;
	libcerror_error_t *error                       = NULL;
	int result                                     = 0;

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

	result = libcdata_range_list_value_initialize(
	          &range_list_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value1",
	 range_list_value1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_value_initialize(
	          &range_list_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value2",
	 range_list_value2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_insert_value(
	          (libcdata_internal_range_list_t *) range_list,
	          NULL,
	          range_list_value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value1 = NULL;

	/* Test error cases
	 */
	result = libcdata_internal_range_list_insert_value(
	          NULL,
	          NULL,
	          range_list_value2,
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
	result = libcdata_range_list_value_free(
	          &range_list_value2,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value2",
	 range_list_value2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	if( range_list_value2 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value2,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list_value1 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value1,
		 &cdata_test_range_list_value_free_function,
		 NULL );
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

/* Tests the libcdata_internal_range_list_remove_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_remove_element(
     void )
{
	libcdata_list_element_t *element1 = NULL;
	libcdata_list_element_t *element2 = NULL;
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

	result = libcdata_internal_range_list_append_element(
	          (libcdata_internal_range_list_t *) range_list,
	          element1,
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
	result = libcdata_internal_range_list_remove_element(
	          (libcdata_internal_range_list_t *) range_list,
	          element1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element1,
	          &cdata_test_range_list_value_free_function,
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

	/* Test error cases
	 */
	result = libcdata_internal_range_list_remove_element(
	          NULL,
	          element2,
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

	result = libcdata_internal_range_list_remove_element(
	          (libcdata_internal_range_list_t *) range_list,
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
	result = libcdata_list_element_free(
	          &element2,
	          &cdata_test_range_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element2",
	 element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 &cdata_test_range_list_value_free_function,
		 NULL );
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

/* Tests the libcdata_internal_range_list_remove_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_remove_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_internal_range_list_remove_range(
	          (libcdata_internal_range_list_t *) range_list,
	          16,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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
	result = libcdata_internal_range_list_remove_range(
	          NULL,
	          0,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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

	result = libcdata_internal_range_list_remove_range(
	          (libcdata_internal_range_list_t *) range_list,
	          (uint64_t) INT64_MAX + 1,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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

	result = libcdata_internal_range_list_remove_range(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          (uint64_t) INT64_MAX + 1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_range_list_remove_range function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_remove_range(
     void )
{
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_remove_range(
	          range_list,
	          16,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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
	result = libcdata_range_list_remove_range(
	          NULL,
	          0,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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

	/* Test libcdata_range_list_remove_range with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_range_list_remove_range(
	          range_list,
	          0,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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
	/* Test libcdata_range_list_remove_range with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_range_list_remove_range(
	          range_list,
	          0,
	          16,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_split_function,
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_range_list_get_element_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_get_element_by_index(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;
	int value2                        = 2;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
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

	element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          1,
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

	/* Test error cases
	 */
	element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          NULL,
	          0,
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

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

/* Tests the libcdata_internal_range_list_get_element_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_get_element_at_offset(
     void )
{
	libcdata_list_element_t *element  = NULL;
	libcdata_range_list_t *range_list = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;
	int value1                        = 1;
	int value2                        = 2;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          70,
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

	element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          48,
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          NULL,
	          0,
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element",
	 element );

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

/* Tests the libcdata_internal_range_list_get_value_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_get_value_by_index(
     void )
{
	libcdata_range_list_t *range_list             = NULL;
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_by_index(
	          NULL,
	          0,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_value_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_value_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

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

/* Tests the libcdata_internal_range_list_get_value_at_offset function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_get_value_at_offset(
     void )
{
	libcdata_range_list_t *range_list             = NULL;
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int result                                    = 0;
	int value1                                    = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          70,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          16,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_at_offset(
	          NULL,
	          0,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list_value",
	 range_list_value );

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

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

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
	int value1                        = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          &range_start,
	          &range_size,
	          &value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_start",
	 range_start,
	 (uint64_t) 64 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_size",
	 range_size,
	 (uint64_t) 32 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          -1,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          NULL,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          &range_start,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          0,
	          &range_start,
	          &range_size,
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

	/* Test libcdata_range_list_get_range_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	/* Test libcdata_range_list_get_range_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 5;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	int value1                        = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          70,
	          &range_start,
	          &range_size,
	          &value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_start",
	 range_start,
	 (uint64_t) 64 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_size",
	 range_size,
	 (uint64_t) 32 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value",
	 value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          16,
	          &range_start,
	          &range_size,
	          &value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_get_range_at_offset with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          70,
	          &range_start,
	          &range_size,
	          &value,
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
	/* Test libcdata_range_list_get_range_at_offset with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          70,
	          &range_start,
	          &range_size,
	          &value,
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
	int value1                        = 1;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_range_is_present(
	          range_list,
	          64,
	          32,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_range_is_present(
	          range_list,
	          0,
	          32,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_range_list_range_is_present(
	          NULL,
	          64,
	          32,
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

	/* Test libcdata_range_list_range_is_present with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_range_is_present(
	          range_list,
	          64,
	          32,
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
	/* Test libcdata_range_list_range_is_present with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 1;

	result = libcdata_range_list_range_is_present(
	          range_list,
	          64,
	          32,
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
	int value1                        = 1;
	int value2                        = 2;

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

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) &value1,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) &value2,
	          &cdata_test_range_list_value_free_function,
	          &cdata_test_range_list_value_merge_function,
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
	result = libcdata_range_list_get_spanning_range(
	          range_list,
	          &range_start,
	          &range_size,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_start",
	 range_start,
	 (uint64_t) 0 );

	CDATA_TEST_ASSERT_EQUAL_UINT64(
	 "range_size",
	 range_size,
	 (uint64_t) 96 );

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

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_range_list_get_spanning_range with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_range_list_get_spanning_range(
	          range_list,
	          &range_start,
	          &range_size,
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
	/* Test libcdata_range_list_get_spanning_range with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_range_list_get_spanning_range(
	          range_list,
	          &range_start,
	          &range_size,
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
	 cdata_test_range_list_initialize );

	CDATA_TEST_RUN(
	 "libcdata_range_list_free",
	 cdata_test_range_list_free );

	CDATA_TEST_RUN(
	 "libcdata_range_list_empty",
	 cdata_test_range_list_empty );

	CDATA_TEST_RUN(
	 "libcdata_range_list_clone",
	 cdata_test_range_list_clone );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_number_of_elements",
	 cdata_test_range_list_get_number_of_elements );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_first_element",
	 cdata_test_range_list_get_first_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_set_first_element",
	 cdata_test_internal_range_list_set_first_element );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_last_element",
	 cdata_test_range_list_get_last_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_set_last_element",
	 cdata_test_internal_range_list_set_last_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_append_element",
	 cdata_test_internal_range_list_append_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_append_value",
	 cdata_test_internal_range_list_append_value );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_insert_range",
	 cdata_test_internal_range_list_insert_range );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_range",
	 cdata_test_range_list_insert_range );

	CDATA_TEST_RUN(
	 "libcdata_range_list_insert_range_list",
	 cdata_test_range_list_insert_range_list );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_insert_element",
	 cdata_test_internal_range_list_insert_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_insert_value",
	 cdata_test_internal_range_list_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_remove_element",
	 cdata_test_internal_range_list_remove_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_remove_range",
	 cdata_test_internal_range_list_remove_range );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_remove_range",
	 cdata_test_range_list_remove_range );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_get_element_by_index",
	 cdata_test_internal_range_list_get_element_by_index );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_get_element_at_offset",
	 cdata_test_internal_range_list_get_element_at_offset );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_get_value_by_index",
	 cdata_test_internal_range_list_get_value_by_index );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_get_value_at_offset",
	 cdata_test_internal_range_list_get_value_at_offset );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_by_index",
	 cdata_test_range_list_get_range_by_index );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_range_at_offset",
	 cdata_test_range_list_get_range_at_offset );

	CDATA_TEST_RUN(
	 "libcdata_range_list_range_is_present",
	 cdata_test_range_list_range_is_present );

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_spanning_range",
	 cdata_test_range_list_spanning_range );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

