/*
 * Library array type test program
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

#include "../libcdata/libcdata_array.h"

int cdata_test_array_entry_free_function_return_value    = 1;
int cdata_test_array_entry_clone_function_return_value   = 1;
int cdata_test_array_entry_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

/* Test entry free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_array_entry_free_function(
     int **entry,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_array_entry_free_function";

	if( entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid entry.",
		 function );

		return( -1 );
	}
	if( cdata_test_array_entry_free_function_return_value != 1 )
	{
		return( cdata_test_array_entry_free_function_return_value );
	}
	if( *entry != NULL )
	{
		memory_free(
		 *entry );

		*entry = NULL;
	}
	return( 1 );
}

/* Test entry clone function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_array_entry_clone_function(
     int **destination_entry,
     int *source_entry,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_array_entry_clone_function";

	if( destination_entry == NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_ARGUMENTS,
		 LIBCERROR_ARGUMENT_ERROR_INVALID_VALUE,
		 "%s: invalid destination entry.",
		 function );

		return( -1 );
	}
	if( *destination_entry != NULL )
	{
		libcerror_error_set(
		 error,
		 LIBCERROR_ERROR_DOMAIN_RUNTIME,
		 LIBCERROR_RUNTIME_ERROR_VALUE_ALREADY_SET,
		 "%s: invalid destination entry value already set.",
		 function );

		return( -1 );
	}
	if( cdata_test_array_entry_clone_function_return_value != 1 )
	{
		return( cdata_test_array_entry_clone_function_return_value );
	}
	if( source_entry == NULL )
	{
		*destination_entry = NULL;
	}
	else
	{
		*destination_entry = (int *) memory_allocate(
		                              sizeof( int ) );

		if( *destination_entry == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_MEMORY,
			 LIBCERROR_MEMORY_ERROR_INSUFFICIENT,
			 "%s: unable to create destination array.",
			 function );

			return( -1 );
		}
		**destination_entry = *source_entry;
	}
	return( 1 );
}

/* Test entry compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_array_entry_compare_function(
     int *first_value,
     int *second_value,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_array_entry_compare_function";

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
	if( ( cdata_test_array_entry_compare_function_return_value != LIBCDATA_COMPARE_LESS )
	 && ( cdata_test_array_entry_compare_function_return_value != LIBCDATA_COMPARE_EQUAL )
	 && ( cdata_test_array_entry_compare_function_return_value != LIBCDATA_COMPARE_GREATER ) )
	{
		return( cdata_test_array_entry_compare_function_return_value );
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

/* Tests the libcdata_array_initialize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_initialize(
     void )
{
	libcdata_array_t *array         = NULL;
	libcerror_error_t *error        = NULL;
	int result                      = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests = 3;
	int number_of_memset_fail_tests = 2;
	int test_number                 = 0;
#endif

	/* Test libcdata_array_initialize without entries
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_array_initialize with entries
	 */
	result = libcdata_array_initialize(
	          &array,
	          200,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_array_initialize(
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

	array = (libcdata_array_t *) 0x12345678UL;

	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	array = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_initialize(
	          &array,
	          -1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if INT_MAX == SSIZE_MAX

	result = libcdata_array_initialize(
	          &array,
	          INT_MAX,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#endif /* INT_MAX == SSIZE_MAX */

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* 1 fail in memory_allocate_structure
	 * 2 fail in memory_allocate of entries
	 * 3 fail in libcthreads_read_write_lock_initialize
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_array_initialize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_array_initialize(
		          &array,
		          10,
		          &error );

		if( cdata_test_malloc_attempts_before_fail != -1 )
		{
			cdata_test_malloc_attempts_before_fail = -1;

			if( array != NULL )
			{
				libcdata_array_free(
				 &array,
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
			 "array",
			 array );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	/* 1 fail in memset after memory_allocate_structure
	 * 2 fail in memset after memory_allocate of entries
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_array_initialize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_array_initialize(
		          &array,
		          10,
		          &error );

		if( cdata_test_memset_attempts_before_fail != -1 )
		{
			cdata_test_memset_attempts_before_fail = -1;

			if( array != NULL )
			{
				libcdata_array_free(
				 &array,
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
			 "array",
			 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_free function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK )
	libcdata_array_t *array  = NULL;
#endif

	/* Test error cases
	 */
	result = libcdata_array_free(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_array_free with pthread_rwlock_destroy failing in libcthreads_read_write_lock_free
	 */
	cdata_test_pthread_rwlock_destroy_attempts_before_fail = 0;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

		/* Clean up
		 */
		result = libcdata_array_free(
		          &array,
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		          &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "array",
		 array );

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
		 "array",
		 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
#endif
	return( 0 );
}

/* Tests the libcdata_array_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_empty(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to empty an array without an entry free function
	 */
	result = libcdata_array_empty(
	          array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	memory_free(
	 value1 );

	value1 = NULL;

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	/* Test to empty an array with an entry free function
	 */
	result = libcdata_array_empty(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Test error cases
	 */
	result = libcdata_array_empty(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	/* Test libcdata_array_empty with entry_free_function failing in libcdata_internal_array_clear
	 */
	cdata_test_array_entry_free_function_return_value = -1;

	result = libcdata_array_empty(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	cdata_test_array_entry_free_function_return_value = 1;

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

	/* Test libcdata_array_empty with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_empty(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	/* Test libcdata_array_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_empty(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_array_clear function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_array_clear(
     void )
{
	libcdata_internal_array_t *internal_array = NULL;
	libcerror_error_t *error                  = NULL;
	int *value1                               = NULL;
	int entry_index                           = 0;
	int result                                = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          (libcdata_array_t **) &internal_array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "internal_array",
	 internal_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          (libcdata_array_t *) internal_array,
	          &entry_index,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to clear an array without an entry free function
	 */
	result = libcdata_internal_array_clear(
	          internal_array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	memory_free(
	 value1 );

	value1 = NULL;

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          (libcdata_array_t *) internal_array,
	          &entry_index,
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

	/* Test to clear an array with an entry free function
	 */
	result = libcdata_internal_array_clear(
	          internal_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	result = libcdata_array_append_entry(
	          (libcdata_array_t *) internal_array,
	          &entry_index,
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

	/* Test error cases
	 */
	result = libcdata_internal_array_clear(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	/* Test libcdata_internal_array_clear with entry_free_function failing
	 */
	cdata_test_array_entry_free_function_return_value = -1;

	result = libcdata_internal_array_clear(
	          internal_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	cdata_test_array_entry_free_function_return_value = 1;

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
	result = libcdata_array_free(
	          (libcdata_array_t **) &internal_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "internal_array",
	 internal_array );

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
	if( internal_array != NULL )
	{
		libcdata_array_free(
		 (libcdata_array_t **) &internal_array,
	         (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_array_clear function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_clear(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *value1              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to clear an array without an entry free function
	 */
	result = libcdata_array_clear(
	          array,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	memory_free(
	 value1 );

	value1 = NULL;

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	/* Test to clear an array with an entry free function
	 */
	result = libcdata_array_clear(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	/* Test error cases
	 */
	result = libcdata_array_clear(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	/* Test libcdata_array_clear with entry_free_function failing in libcdata_internal_array_clear
	 */
	cdata_test_array_entry_free_function_return_value = -1;

	result = libcdata_array_clear(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	cdata_test_array_entry_free_function_return_value = 1;

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

	/* Test libcdata_array_clear with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_clear(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	/* Test libcdata_array_clear with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_clear(
	          array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
	         (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_clone function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_clone(
     void )
{
	libcdata_array_t *destination_array = NULL;
	libcdata_array_t *source_array      = NULL;
	libcerror_error_t *error            = NULL;
	int *value1                         = NULL;
	int entry_index                     = 0;
	int result                          = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &source_array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "source_array",
	 source_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          source_array,
	          &entry_index,
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

	/* Test libcdata_array_clone with initialized array
	 */
	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_free(
	          &destination_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_array_clone with non-initialized array
	 */
	result = libcdata_array_clone(
	          &destination_array,
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_array_clone(
	          NULL,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	destination_array = (libcdata_array_t *) 0x12345678UL;

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	destination_array = NULL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          NULL,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_array_clone with malloc failing in libcdata_array_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_array != NULL )
		{
			libcdata_array_free(
			 &destination_array,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
		 "destination_array",
		 destination_array );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

/* TODO: Test libcdata_array_initialize returning NULL destination_array */

	/* Test libcdata_array_clone with entry_clone_function failing
	 */
	cdata_test_array_entry_clone_function_return_value = -1;

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	cdata_test_array_entry_clone_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "destination_array",
	 destination_array );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_array != NULL )
		{
			libcdata_array_free(
			 &destination_array,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
		 "destination_array",
		 destination_array );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_array_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_clone(
	          &destination_array,
	          source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_array != NULL )
		{
			libcdata_array_free(
			 &destination_array,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
		 "destination_array",
		 destination_array );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_array_free(
	          &source_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "source_array",
	 source_array );

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
	if( destination_array != NULL )
	{
		libcdata_array_free(
		 &destination_array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( source_array != NULL )
	{
		libcdata_array_free(
		 &source_array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_array_resize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_array_resize(
     void )
{
	libcdata_internal_array_t *internal_array = NULL;
	libcerror_error_t *error                  = NULL;
	int result                                = 0;

#if defined( HAVE_CDATA_TEST_MEMORY )
	int number_of_malloc_fail_tests           = 2;
	int number_of_memset_fail_tests           = 2;
	int test_number                           = 0;
#endif

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          (libcdata_array_t **) &internal_array,
	          2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "internal_array",
	 internal_array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to resize an array to a larger number of entries
	 */
	result = libcdata_internal_array_resize(
	          internal_array,
	          35,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to resize an array to a smaller number of entries
	 */
	result = libcdata_internal_array_resize(
	          internal_array,
	          4,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_internal_array_resize(
	          NULL,
	          10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	result = libcdata_internal_array_resize(
	          internal_array,
	          -10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

#if INT_MAX == SSIZE_MAX

	result = libcdata_internal_array_resize(
	          internal_array,
	          INT_MAX,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

#endif /* INT_MAX == SSIZE_MAX */

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* 1 fail in memset after memory_allocate_structure
	 * 2 fail in memset after memory_allocate of entries
	 */
	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_internal_array_resize with malloc failing
		 */
		cdata_test_malloc_attempts_before_fail = test_number;

		result = libcdata_internal_array_resize(
		          internal_array,
		          99,
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	}
	/* 1 fail in memset after memory_allocate_structure
	 * 2 fail in memset after memory_allocate of entries
	 */
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libcdata_internal_array_resize with memset failing
		 */
		cdata_test_memset_attempts_before_fail = test_number;

		result = libcdata_internal_array_resize(
		          internal_array,
		          99,
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

	/* Clean up
	 */
	result = libcdata_array_free(
	          (libcdata_array_t **) &internal_array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "internal_array",
	 internal_array );

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
	if( internal_array != NULL )
	{
		libcdata_array_free(
		 (libcdata_array_t **) &internal_array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_array_resize function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_resize(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_array_resize(
	          array,
	          10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_array_resize(
	          NULL,
	          10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	/* Test libcdata_array_resize with malloc failing in libcdata_internal_array_resize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_resize(
		  array,
		  99,
		  (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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

	/* Test libcdata_array_resize with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_resize(
	          array,
	          10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	/* Test libcdata_array_resize with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_resize(
	          array,
	          10,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_reverse function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_reserve(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	intptr_t **entries       = NULL;
	int *entry_value         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_set_entry_by_index(
	          array,
	          0,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_set_entry_by_index(
	          array,
	          1,
	          (intptr_t *) value2,
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

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Check the order of the entries
	 */
	result = libcdata_array_get_entry_by_index(
	          array,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          2,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libcdata_array_reverse(
	          array,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Check the order of the entries
	 */
	result = libcdata_array_get_entry_by_index(
	          array,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          2,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_array_reverse(
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

	entries = ( (libcdata_internal_array_t *) array )->entries;

	( (libcdata_internal_array_t *) array )->entries = NULL;

	result = libcdata_array_reverse(
	          array,
	          &error );

	( (libcdata_internal_array_t *) array )->entries = entries;

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

	/* Test libcdata_array_reverse with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_reverse(
	          array,
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
	/* Test libcdata_array_reverse with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_reverse(
	          array,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( result );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_get_number_of_entries function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_number_of_entries(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int entry_index          = 0;
	int number_of_entries    = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to retrieve the number of entries on an empty array
	 */
	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_entries",
	 number_of_entries,
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

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
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

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test to retrieve the number of entries on a non-empty array
	 */
	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "number_of_entries",
	 number_of_entries,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_array_get_number_of_entries(
	          NULL,
	          &number_of_entries,
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

	result = libcdata_array_get_number_of_entries(
	          array,
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

	/* Test libcdata_array_get_number_of_entries with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
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
	/* Test libcdata_array_get_number_of_entries with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_get_number_of_entries(
	          array,
	          &number_of_entries,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_get_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_entry_by_index(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	intptr_t **entries       = NULL;
	int *entry_value         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
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

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test to retrieve an entry that is in bounds
	 */
	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libcdata_array_get_entry_by_index(
	          NULL,
	          0,
	          (intptr_t **) &entry_value,
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

	entries = ( (libcdata_internal_array_t *) array )->entries;

	( (libcdata_internal_array_t *) array )->entries = NULL;

	result = libcdata_array_get_entry_by_index(
	          array,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	( (libcdata_internal_array_t *) array )->entries = entries;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_get_entry_by_index(
	          array,
	          -1,
	          (intptr_t **) &entry_value,
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

	result = libcdata_array_get_entry_by_index(
	          array,
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

	/* Test libcdata_array_get_entry_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value,
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
	/* Test libcdata_array_get_entry_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_get_entry_by_index(
	          array,
	          1,
	          (intptr_t **) &entry_value,
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
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_get_entry_by_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_get_entry_by_value(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int *value4              = NULL;
	int *test_value2         = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_value2 = value2;
	value2      = NULL;

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test to retrieve an entry that exists
	 */
	entry_value = NULL;

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	/* Test to retrieve an entry that not exists
	 */
	entry_value = NULL;

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) value4,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "entry_value",
	 entry_value )

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	entry_value = NULL;

	result = libcdata_array_get_entry_by_value(
	          NULL,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
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

	result = libcdata_array_get_entry_by_value(
	          array,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
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

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) test_value2,
	          NULL,
	          (intptr_t **) &entry_value,
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

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
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

	/* Test libcdata_array_get_entry_by_value with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
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
	/* Test libcdata_array_get_entry_by_value with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_get_entry_by_value(
	          array,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          (intptr_t **) &entry_value,
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
	memory_free(
	 value4 );

	value4 = NULL;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_set_entry_by_index function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_set_entry_by_index(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	intptr_t **entries       = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to set an entry that is in bounds
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_set_entry_by_index(
	          array,
	          0,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_set_entry_by_index(
	          array,
	          1,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Initialize test
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	/* Test to set an entry that is out of bounds
	 */
	result = libcdata_array_set_entry_by_index(
	          array,
	          99,
	          (intptr_t *) value3,
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

	/* Test error cases
	 */
	result = libcdata_array_set_entry_by_index(
	          NULL,
	          2,
	          (intptr_t *) value3,
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

	entries = ( (libcdata_internal_array_t *) array )->entries;

	( (libcdata_internal_array_t *) array )->entries = NULL;

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) value3,
	          &error );

	( (libcdata_internal_array_t *) array )->entries = entries;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_set_entry_by_index(
	          array,
	          -1,
	          (intptr_t *) value3,
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

#if INT_MAX == SSIZE_MAX

	result = libcdata_array_set_entry_by_index(
	          array,
	          INT_MAX,
	          (intptr_t *) value3,
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

#endif /* INT_MAX == SSIZE_MAX */

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_set_entry_by_index with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_set_entry_by_index(
			          array,
			          2,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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
	/* Test libcdata_array_set_entry_by_index with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_set_entry_by_index(
	          array,
	          2,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_set_entry_by_index(
			          array,
			          2,
			          NULL,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	memory_free(
	 value3 );

	value3 = NULL;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_prepend_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_prepend_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to prepend an entry
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_prepend_entry(
	          array,
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

	/* Test to prepend another entry
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Initialize test
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	/* Test error cases
	 */
	result = libcdata_array_prepend_entry(
	          NULL,
	          (intptr_t *) value3,
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

	/* Test libcdata_array_prepend_entry with malloc failing in libcdata_internal_array_resize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          0,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_prepend_entry with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          0,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
	/* Test libcdata_array_prepend_entry with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_prepend_entry(
	          array,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          0,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	memory_free(
	 value3 );

	value3 = NULL;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_append_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_append_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test to append an entry
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test to append another entry
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Initialize test
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	/* Test error cases
	 */
	result = libcdata_array_append_entry(
	          NULL,
	          &entry_index,
	          (intptr_t *) value3,
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

	result = libcdata_array_append_entry(
	          array,
	          NULL,
	          (intptr_t *) value3,
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

	/* Test libcdata_array_append_entry with malloc failing in libcdata_internal_array_resize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          2,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_append_entry with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          2,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
	/* Test libcdata_array_append_entry with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          2,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 3 );

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	memory_free(
	 value3 );

	value3 = NULL;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_insert_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_insert_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value         = NULL;
	int *test_value2         = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int *value4              = NULL;
	int *value5              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of new entry on an empty array succeeds
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test if insert of new entry before the first element succeeds
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = NULL;

	/* Test if insert of new entry after the first element succeeds
	 */
	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Test if insert of duplicate entry fails
	 */
	test_value2 = (int *) memory_allocate(
	                       sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "test_value2",
	 test_value2 );

	*test_value2 = 2;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of new entry after the last element succeeds
	 */
	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value4,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	/* Test if insert of duplicate entry succeeds
	 */
	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) test_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "entry_index",
	 entry_index,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_value2 = NULL;

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
	result = libcdata_array_insert_entry(
	          NULL,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
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

	result = libcdata_array_insert_entry(
	          array,
	          NULL,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
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

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
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

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
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

	/* Test with entry_compare function failing
	 */
	cdata_test_array_entry_compare_function_return_value = -1;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	cdata_test_array_entry_compare_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test with entry_compare function returning unsupported value
	 */
	cdata_test_array_entry_compare_function_return_value = 5;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	cdata_test_array_entry_compare_function_return_value = 1;

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

	/* Test libcdata_array_insert_entry with malloc failing in libcdata_internal_array_resize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          entry_index,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 5 );

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
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_insert_entry with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          entry_index,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 5 );

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
	/* Test libcdata_array_insert_entry with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_insert_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_array_entry_compare_function,
	          0,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_remove_entry(
			          array,
			          entry_index,
			          (intptr_t **) &entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "entry_value",
			 entry_value );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "*entry_value",
			 *entry_value,
			 5 );

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	memory_free(
	 value5 );

	value5 = NULL;

	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( test_value2 != NULL )
	{
		memory_free(
		 test_value2 );
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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_array_remove_entry function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_array_remove_entry(
     void )
{
	libcdata_array_t *array  = NULL;
	libcerror_error_t *error = NULL;
	int *entry_value         = 0;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
	int entry_index          = 0;
	int result               = 0;

	/* Initialize test
	 */
	result = libcdata_array_initialize(
	          &array,
	          0,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "array",
	 array );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value2,
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

	result = libcdata_array_append_entry(
	          array,
	          &entry_index,
	          (intptr_t *) value3,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test to remove an entry that is in bounds
	 */
	entry_value = NULL;

	result = libcdata_array_remove_entry(
	          array,
	          1,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "entry_value",
	 entry_value );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "*entry_value",
	 *entry_value,
	 2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	memory_free(
	 entry_value );

	/* Test error cases
	 */
	entry_value = NULL;

	result = libcdata_array_remove_entry(
	          NULL,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "entry_value",
	 entry_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "entry_value",
	 entry_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          -1,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "entry_value",
	 entry_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_array_remove_entry(
	          array,
	          1000,
	          (intptr_t **) &entry_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "entry_value",
	 entry_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_array_remove_entry with malloc failing in libcdata_internal_array_resize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_array_remove_entry(
	          array,
	          0,
	          (intptr_t **) &entry_value,
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
		 "entry_value",
		 entry_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK )

	/* Test libcdata_array_remove_entry with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_array_remove_entry(
	          array,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_prepend_entry(
			          array,
			          (intptr_t *) entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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

		CDATA_TEST_ASSERT_IS_NULL(
		 "entry_value",
		 entry_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libcdata_array_remove_entry with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_array_remove_entry(
	          array,
	          0,
	          (intptr_t **) &entry_value,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_array_prepend_entry(
			          array,
			          (intptr_t *) entry_value,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

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

		CDATA_TEST_ASSERT_IS_NULL(
		 "entry_value",
		 entry_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK ) */

	/* Clean up
	 */
	result = libcdata_array_free(
	          &array,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "array",
	 array );

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
	if( array != NULL )
	{
		libcdata_array_free(
		 &array,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_array_entry_free_function,
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
	 "libcdata_array_initialize",
	 cdata_test_array_initialize );

	CDATA_TEST_RUN(
	 "libcdata_array_free",
	 cdata_test_array_free );

	CDATA_TEST_RUN(
	 "libcdata_array_empty",
	 cdata_test_array_empty );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_array_clear",
	 cdata_test_internal_array_clear );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_array_clear",
	 cdata_test_array_clear );

	CDATA_TEST_RUN(
	 "libcdata_array_clone",
	 cdata_test_array_clone );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	CDATA_TEST_RUN(
	 "libcdata_internal_array_resize",
	 cdata_test_internal_array_resize );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	CDATA_TEST_RUN(
	 "libcdata_array_resize",
	 cdata_test_array_resize );

	CDATA_TEST_RUN(
	 "libcdata_array_reverse",
	 cdata_test_array_reserve );

	CDATA_TEST_RUN(
	 "libcdata_array_get_number_of_entries",
	 cdata_test_array_get_number_of_entries );

	CDATA_TEST_RUN(
	 "libcdata_array_get_entry_by_index",
	 cdata_test_array_get_entry_by_index );

	CDATA_TEST_RUN(
	 "libcdata_array_get_entry_by_value",
	 cdata_test_array_get_entry_by_value );

	CDATA_TEST_RUN(
	 "libcdata_array_set_entry_by_index",
	 cdata_test_array_set_entry_by_index );

	CDATA_TEST_RUN(
	 "libcdata_array_prepend_entry",
	 cdata_test_array_prepend_entry );

	CDATA_TEST_RUN(
	 "libcdata_array_append_entry",
	 cdata_test_array_append_entry );

	CDATA_TEST_RUN(
	 "libcdata_array_insert_entry",
	 cdata_test_array_insert_entry );

	CDATA_TEST_RUN(
	 "libcdata_array_remove_entry",
	 cdata_test_array_remove_entry );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

