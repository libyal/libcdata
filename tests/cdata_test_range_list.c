/*
 * Library range list type test program
 *
 * Copyright (C) 2006-2019, Joachim Metz <joachim.metz@gmail.com>
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
#include <memory.h>
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
     int **value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_range_list_value_free_function";

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
	if( cdata_test_range_list_value_free_function_return_value != 1 )
	{
		return( cdata_test_range_list_value_free_function_return_value );
	}
	if( *value != NULL )
	{
		memory_free(
		 *value );

		*value = NULL;
	}
	return( 1 );
}

/* Test value clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_clone_function(
     int **destination_value,
     int *source_value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_range_list_value_clone_function";

	if( destination_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination value.",
		 function );

		return( -1 );
	}
	if( *destination_value != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid destination value value already set.",
		 function );

		return( -1 );
	}
	if( cdata_test_range_list_value_clone_function_return_value != 1 )
	{
		return( cdata_test_range_list_value_clone_function_return_value );
	}
	if( source_value == NULL )
	{
		*destination_value = NULL;
	}
	else
	{
		*destination_value = (int *) memory_allocate(
		                              sizeof( int ) );

		if( *destination_value == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create destination value.",
			 function );

			return( -1 );
		}
		**destination_value = *source_value;
	}
	return( 1 );
}

/* Test value merge function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_merge_function(
     int *destination_value,
     int *source_value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_range_list_value_merge_function";

	if( destination_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination value.",
		 function );

		return( -1 );
	}
	if( source_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid source value.",
		 function );

		return( -1 );
	}
	if( cdata_test_range_list_value_merge_function_return_value != 1 )
	{
		return( cdata_test_range_list_value_merge_function_return_value );
	}
	return( 1 );
}

/* Test value split function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_range_list_value_split_function(
     int **destination_value,
     int *source_value,
     uint64_t split_range_offset CDATA_TEST_ATTRIBUTE_UNUSED,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_range_list_value_split_function";

	CDATA_TEST_UNREFERENCED_PARAMETER( split_range_offset )

	if( destination_value == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination value.",
		 function );

		return( -1 );
	}
	if( *destination_value != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid destination value value already set.",
		 function );

		return( -1 );
	}
	if( cdata_test_range_list_value_split_function_return_value != 1 )
	{
		return( cdata_test_range_list_value_split_function_return_value );
	}
	if( source_value == NULL )
	{
		*destination_value = NULL;
	}
	else
	{
		*destination_value = (int *) memory_allocate(
		                              sizeof( int ) );

		if( *destination_value == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create destination value.",
			 function );

			return( -1 );
		}
		**destination_value = *source_value;
	}
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_range_list_empty(
	          range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test error cases
	 */
	result = libcdata_range_list_empty(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			value1 = (int *) memory_allocate(
			                  sizeof( int ) );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "value1",
			 value1 );

			*value1 = 1;

			result = libcdata_range_list_insert_range(
			          range_list,
			          0,
			          32,
			          (intptr_t *) value1,
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			value1 = NULL;
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
	/* Test libcdata_range_list_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_range_list_empty(
	          range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			value1 = (int *) memory_allocate(
			                  sizeof( int ) );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "value1",
			 value1 );

			*value1 = 1;

			result = libcdata_range_list_insert_range(
			          range_list,
			          0,
			          32,
			          (intptr_t *) value1,
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
			          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "error",
			 error );

			value1 = NULL;
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
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                                   = NULL;
	int result                                    = 0;

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          source_range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test libcdata_range_list_clone on initialized range_list
	 */
	result = libcdata_range_list_clone(
	          &destination_range_list,
	          source_range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_memcpy_attempts_before_fail != -1 )
	{
		cdata_test_memcpy_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_range_list != NULL )
		{
			libcdata_range_list_free(
			 &destination_range_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( source_range_list != NULL )
	{
		libcdata_range_list_free(
		 &source_range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
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

	/* Test to retrieve the number of elements on an empty range list
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

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test to retrieve the number of elements on a non-empty range list
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
	 1 );

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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_range_list_get_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_first_element(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
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

	/* Test to retrieve the first of element on an empty range list
	 */
	result = libcdata_range_list_get_first_element(
	          range_list,
	          &list_element,
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

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test to retrieve the first of element on a non-empty range list
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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_range_list_set_first_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_set_first_element(
     void )
{
	libcdata_list_element_t *element1 = NULL;
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

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_set_first_element(
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

	result = libcdata_internal_range_list_set_first_element(
	          (libcdata_internal_range_list_t *) range_list,
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
	result = libcdata_internal_range_list_set_first_element(
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
	result = libcdata_list_element_free(
	          &element1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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

	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

/* Tests the libcdata_range_list_get_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_range_list_get_last_element(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
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

	/* Test to retrieve the last of element on an empty range list
	 */
	result = libcdata_range_list_get_last_element(
	          range_list,
	          &list_element,
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

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test to retrieve the last of element on a non-empty range list
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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_range_list_set_last_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_set_last_element(
     void )
{
	libcdata_list_element_t *element1 = NULL;
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

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_set_last_element(
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

	result = libcdata_internal_range_list_set_last_element(
	          (libcdata_internal_range_list_t *) range_list,
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
	result = libcdata_internal_range_list_set_last_element(
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
	result = libcdata_list_element_free(
	          &element1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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

	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list_value1 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_internal_range_list_insert_range_find_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_insert_range_find_element(
     void )
{
	libcdata_list_element_t *list_element         = NULL;
	libcdata_range_list_t *range_list             = NULL;
	libcdata_range_list_value_t *range_list_value = NULL;
	libcerror_error_t *error                      = NULL;
	int *value1                                   = NULL;
	int *value2                                   = NULL;
	int *value3                                   = NULL;
	int *value4                                   = NULL;
	int *value5                                   = NULL;
	int element_index                             = 0;
	int result                                    = 0;

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

	/* Test find element on an empty range list
	 */
	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          16,
	          32,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_range_list_insert_range(
	          range_list,
	          192,
	          32,
	          (intptr_t *) value4,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	value5 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value5",
	 value5 );

	*value5 = 5;

	result = libcdata_range_list_insert_range(
	          range_list,
	          256,
	          32,
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value5 = NULL;

	/* Test find element on a range list with 5 elements where range overlap with the first range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          16,
	          32,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range is before the second range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          48,
	          56,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range overlap with the second range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          80,
	          112,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range is before the third range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          112,
	          120,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 2 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range overlap with the third range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          146,
	          176,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 2 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range is before the fourth range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          176,
	          184,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 3 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Set the current element
	 */
	list_element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          2,
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

	/* Test find element on a range list with 5 elements where range is before the fifth range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          240,
	          248,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 4 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &range_list_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "range_list_value",
	 range_list_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*( range_list_value->value )",
	 *( (int *) range_list_value->value ),
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a range list with 5 elements where range is after the fifth range list element
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          304,
	          312,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "element_index",
	 element_index,
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_range_list_insert_range_find_element(
	          NULL,
	          0,
	          32,
	          &element_index,
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

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          32,
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

	result = libcdata_internal_range_list_insert_range_find_element(
	          (libcdata_internal_range_list_t *) range_list,
	          0,
	          32,
	          &element_index,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value5 != NULL )
	{
		memory_free(
		 value5 );
	}
	if( value4 != NULL )
	{
		memory_free(
		 value4 );
	}
	if( value3 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_internal_range_list_check_range_overlap function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_range_list_check_range_overlap(
     void )
{
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

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

	/* Test with range that fully overlaps the range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          list_element,
	          48,
	          112,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with range that overlaps the start of the range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          list_element,
	          48,
	          80,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with range that overlaps the end of the range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          list_element,
	          80,
	          112,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with range before the range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          list_element,
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

	/* Test with range after the range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          list_element,
	          128,
	          160,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test with non-existing range list element
	 */
	result = libcdata_internal_range_list_check_range_overlap(
	          (libcdata_internal_range_list_t *) range_list,
	          NULL,
	          48,
	          112,
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
	result = libcdata_internal_range_list_check_range_overlap(
	          NULL,
	          list_element,
	          48,
	          112,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	libcerror_error_free(
	 &error );

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *duplicate_value2                 = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
	int *value4                           = NULL;
	int *value5                           = NULL;
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

	/* Test if insert of a range on an empty list succeeds
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test if insert of a range before the first element succeeds
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test if insert of an element after the first element succeed
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Test if insert of an element after the last element succeeds
	 */
	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_range_list_insert_range(
	          range_list,
	          192,
	          32,
	          (intptr_t *) value4,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	/* Test if insert of a duplicate element succeeds
	 */
	duplicate_value2 = (int *) memory_allocate(
	                            sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_value2",
	 duplicate_value2 );

	*duplicate_value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) duplicate_value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	memory_free(
	 duplicate_value2 );

	duplicate_value2 = NULL;

	/* Initialize test
	 */
	value5 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value5",
	 value5 );

	*value5 = 5;

	/* Test error cases
	 */
	result = libcdata_range_list_insert_range(
	          NULL,
	          256,
	          32,
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
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
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
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
	          256,
	          32,
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_internal_range_list_remove_element(
			          (libcdata_internal_range_list_t *) range_list,
			          list_element,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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
	/* Test libcdata_range_list_insert_range with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * with a new range
	 */
	/* Note that libcdata_range_list_free will also call pthread_rwlock_unlock
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_range_list_insert_range(
	          range_list,
	          256,
	          32,
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_internal_range_list_remove_element(
			          (libcdata_internal_range_list_t *) range_list,
			          list_element,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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
	/* Test libcdata_range_list_insert_range with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 * with an overlapping range
	 */
	/* Note that libcdata_range_list_free will also call pthread_rwlock_unlock
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_range_list_insert_range(
	          range_list,
	          32,
	          512,
	          (intptr_t *) value5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			value5 = NULL;
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
	if( value5 != NULL )
	{
		memory_free(
		 value5 );

		value5 = NULL;
	}
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( duplicate_value2 != NULL )
	{
		memory_free(
		 duplicate_value2 );
	}
	if( value5 != NULL )
	{
		memory_free(
		 value5 );
	}
	if( value4 != NULL )
	{
		memory_free(
		 value4 );
	}
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	libcdata_range_list_t *range_list  = NULL;
	libcdata_range_list_t *range_list1 = NULL;
	libcerror_error_t *error           = NULL;
	int *value1                        = NULL;
	int result                         = 0;

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
	          &range_list1,
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list1,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_range_list_insert_range_list(
	          range_list,
	          range_list1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
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
	          range_list1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
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
/* TODO replace NULL by (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function, */
	result = libcdata_range_list_free(
	          &range_list1,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "range_list1",
	 range_list1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list1 != NULL )
	{
		libcdata_range_list_free(
		 &range_list1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list_value1 != NULL )
	{
		libcdata_range_list_value_free(
		 &range_list_value1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
		 NULL );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_internal_range_list_remove_range(
	          (libcdata_internal_range_list_t *) range_list,
	          16,
	          16,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test regular cases
	 */
	result = libcdata_range_list_remove_range(
	          range_list,
	          16,
	          16,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, uint64_t, libcerror_error_t **)) &cdata_test_range_list_value_split_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	list_element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          1,
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

	list_element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          1,
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

/* TODO compare element value
	result = libcdata_list_element_get_value(
	          list_element,
	          (intptr_t **) &element_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element_value",
	 element_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*element_value",
	 *element_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );
*/

	/* Test error cases
	 */
	list_element = NULL;

	result = libcdata_internal_range_list_get_element_by_index(
	          NULL,
	          1,
	          &list_element,
	          &error );

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

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &list_element,
	          &error );

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

	result = libcdata_internal_range_list_get_element_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          1,
	          NULL,
	          &error );

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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	libcdata_list_element_t *list_element = NULL;
	libcdata_range_list_t *range_list     = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	list_element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          80,
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

	list_element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          48,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	list_element = NULL;

	result = libcdata_internal_range_list_get_element_at_offset(
	          NULL,
	          80,
	          &list_element,
	          &error );

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

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          -1,
	          &list_element,
	          &error );

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

	result = libcdata_internal_range_list_get_element_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          80,
	          NULL,
	          &error );

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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                                   = NULL;
	int *value2                                   = NULL;
	int *value3                                   = NULL;
	int result                                    = 0;

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_by_index(
	          (libcdata_internal_range_list_t *) range_list,
	          1,
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

/* TODO compare element value */

	/* Test error cases
	 */
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_by_index(
	          NULL,
	          1,
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
	          1,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                                   = NULL;
	int *value2                                   = NULL;
	int *value3                                   = NULL;
	int result                                    = 0;

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          80,
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

/* TODO compare element value */

	range_list_value = NULL;

	result = libcdata_internal_range_list_get_value_at_offset(
	          (libcdata_internal_range_list_t *) range_list,
	          48,
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
	          80,
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
	          80,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          1,
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
	          1,
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
	          1,
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
	          1,
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
	          1,
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

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          1,
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
	/* Test libcdata_range_list_get_range_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 1;

	result = libcdata_range_list_get_range_by_index(
	          range_list,
	          1,
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

	/* Clean up
	 */
	result = libcdata_range_list_free(
	          &range_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          &error );

CDATA_TEST_FPRINT_ERROR( error );

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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test regular cases
	 */
	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          80,
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

/* TODO compare element value */

	result = libcdata_range_list_get_range_at_offset(
	          range_list,
	          48,
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
	          80,
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
	          80,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

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
	          48,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_range_list_insert_range(
	          range_list,
	          0,
	          32,
	          (intptr_t *) value1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_range_list_insert_range(
	          range_list,
	          64,
	          32,
	          (intptr_t *) value2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_range_list_insert_range(
	          range_list,
	          128,
	          32,
	          (intptr_t *) value3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_range_list_value_merge_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

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
	 (uint64_t) 160 );

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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
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
	if( range_list != NULL )
	{
		libcdata_range_list_free(
		 &range_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_range_list_value_free_function,
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

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_first_element",
	 cdata_test_range_list_get_first_element );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_set_first_element",
	 cdata_test_internal_range_list_set_first_element );

#endif /* #if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_range_list_get_last_element",
	 cdata_test_range_list_get_last_element );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

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
	 "libcdata_internal_range_list_remove_element",
	 cdata_test_internal_range_list_remove_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_insert_range_find_element",
	 cdata_test_internal_range_list_insert_range_find_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_range_list_check_range_overlap",
	 cdata_test_internal_range_list_check_range_overlap );

	/* TODO add tests for libcdata_internal_range_list_insert_range_before_element */

	/* TODO add tests for libcdata_internal_range_list_merge_overlapping_ranges */

	/* TODO add tests for libcdata_internal_range_list_merge_range */

	/* TODO add tests for libcdata_internal_range_list_insert_range_merge */

	/* TODO add tests for libcdata_internal_range_list_insert_range_revert */

	/* TODO add tests for libcdata_internal_range_list_insert_range_revert_merge */

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

