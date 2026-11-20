/*
 * Library list type test program
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
#include "cdata_test_rwlock.h"
#include "cdata_test_unused.h"

#include "../libcdata/libcdata_list.h"
#include "../libcdata/libcdata_list_element.h"

int cdata_test_list_value_free_function_return_value    = 1;
int cdata_test_list_value_clone_function_return_value   = 1;
int cdata_test_list_value_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

/* Test value free function
 * Returns 1 if successful or -1 on error
 */
int cdata_test_list_value_free_function(
     int **value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_list_value_free_function";

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
	if( cdata_test_list_value_free_function_return_value != 1 )
	{
		return( cdata_test_list_value_free_function_return_value );
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
int cdata_test_list_value_clone_function(
     int **destination_value,
     int *source_value,
     libcerror_error_t **error )
{
	static char *function = "cdata_test_list_value_clone_function";

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
	if( cdata_test_list_value_clone_function_return_value != 1 )
	{
		return( cdata_test_list_value_clone_function_return_value );
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

/* Test element compare function
 * Returns LIBCDATA_COMPARE_LESS, LIBCDATA_COMPARE_EQUAL, LIBCDATA_COMPARE_GREATER if successful or -1 on error
 */
int cdata_test_list_element_compare_function(
     int *first_value,
     int *second_value,
     libcdata_error_t **error )
{
	static char *function = "cdata_test_list_value_compare_function";

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
	if( ( cdata_test_list_value_compare_function_return_value != LIBCDATA_COMPARE_LESS )
	 && ( cdata_test_list_value_compare_function_return_value != LIBCDATA_COMPARE_EQUAL )
	 && ( cdata_test_list_value_compare_function_return_value != LIBCDATA_COMPARE_GREATER ) )
	{
		return( cdata_test_list_value_compare_function_return_value );
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
				 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_list_t *list    = NULL;
#endif
	libcdata_list_t *list2  = NULL;

	libcerror_error_t *error = NULL;
	int *value1              = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libcdata_list_free(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          list2,
	          (intptr_t *) value1,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_free with the value_free_function failing in libcdata_list_element_free
	 */
	cdata_test_list_value_free_function_return_value = -1;

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	cdata_test_list_value_free_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	memory_free(
	 value1 );

	value1 = NULL;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

		/* Clean up
		 */
		result = libcdata_list_free(
		          &list,
		          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

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
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif
	return( 0 );
}

/* Tests the libcdata_list_empty function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_empty(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int result                        = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int *value1                       = NULL;
#endif

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

	/* Test regular cases
	 */
	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	/* Test error cases
	 */
	result = libcdata_list_empty(
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_empty with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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
	/* Test libcdata_list_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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
	/* Test libcdata_list_empty with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element
	 */
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

	/* The handle to the element is retained, if the failure is injected
	 * in libcdata_list_element_set_previous_element the element is orphaned
	 * with a dangling previous element and needs to be retrieved here
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		/* The element was already removed and freed by a successful
		 * libcdata_list_empty or is still owned by the list
		 */
		element1 = NULL;

		if( result == 1 )
		{
			result = libcdata_list_empty(
			          list,
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

		/* The failure was injected in libcdata_list_element_set_previous_element,
		 * the first element of the list was already removed and freed by
		 * libcdata_list_empty, while element1 is left with a (now dangling)
		 * previous element, clear it otherwise libcdata_list_element_free
		 * refuses to free the element
		 */
		result = libcdata_list_element_set_previous_element(
	                element1,
	                NULL,
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
	                (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	                &error );

		CDATA_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 1 );

		CDATA_TEST_ASSERT_IS_NULL(
		 "error",
		 error );

		element1 = NULL;
	}
	/* Test libcdata_list_empty with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element
	 */
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

	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_empty(
			          list,
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	/* Test libcdata_list_empty with the value_free_function failing in libcdata_list_element_free
	 */
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 4;

	result = libcdata_list_element_set_value(
	          element1,
	          (intptr_t *) value1,
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

	cdata_test_list_value_free_function_return_value = -1;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	cdata_test_list_value_free_function_return_value = 1;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	memory_free(
	 value1 );

	value1 = NULL;

	/* Test libcdata_list_empty with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
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

	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 2;

	result = libcdata_list_empty(
	          list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_empty(
			          list,
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
#endif
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1                       = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          source_list,
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

	/* Test libcdata_list_clone with initialized list
	 */
	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	/* Test libcdata_list_clone with non-initialized list
	 */
	result = libcdata_list_clone(
	          &destination_list,
	          NULL,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	destination_list = NULL;

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

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          NULL,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
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

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          NULL,
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_clone with malloc failing in libcdata_list_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	cdata_test_list_value_clone_function_return_value = 1;

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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_clone with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	/* Test libcdata_list_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	/* Test libcdata_list_clone with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_read after copying the element values
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( destination_list != NULL )
		{
			libcdata_list_free(
			 &destination_list,
			 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_clone with a corrupted source list
	 */
	( (libcdata_internal_list_t *) source_list )->number_of_elements = 2;

	result = libcdata_list_clone(
	          &destination_list,
	          source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          (int (*)(intptr_t **, intptr_t *, libcerror_error_t **)) &cdata_test_list_value_clone_function,
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

	( (libcdata_internal_list_t *) source_list )->number_of_elements = 1;

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &source_list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( source_list != NULL )
	{
		libcdata_list_free(
		 &source_list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1              = NULL;
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

	/* Test to retrieve the number of elements on an empty list
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

	/* Initialize test
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          list,
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

	/* Test to retrieve the number of elements on a non-empty list
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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1                           = NULL;
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

	/* Test to retrieve the first of element on an empty list
	 */
	result = libcdata_list_get_first_element(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	/* Test to retrieve the first of element on a non-empty list
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	libcdata_list_t *list                  = NULL;
	libcdata_list_element_t *element1      = NULL;
	libcdata_list_element_t *element2      = NULL;
	libcdata_list_element_t *test_element2 = NULL;
	libcerror_error_t *error               = NULL;
	int *value1                            = NULL;
	int *value2                            = NULL;
	int result                             = 0;

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	/* Test set first element on an empty list
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

	/* Test set first element on a non-empty list
	 */
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	test_element2 = element2;
	element2      = NULL;

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
	          test_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Reset the previous and next elements
	 */
	result = libcdata_list_element_set_elements(
	          element1,
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_elements(
	          test_element2,
	          NULL,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_internal_list_set_first_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_internal_list_set_first_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_element_set_elements(
			          element1,
			          NULL,
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

	/* Test libcdata_internal_list_set_first_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_internal_list_set_first_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_element_set_elements(
			          element1,
			          NULL,
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1                           = NULL;
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

	/* Test to retrieve the last of element on an empty list
	 */
	result = libcdata_list_get_last_element(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	/* Test to retrieve the last of element on a non-empty list
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	libcdata_list_t *list                  = NULL;
	libcdata_list_element_t *element1      = NULL;
	libcdata_list_element_t *element2      = NULL;
	libcdata_list_element_t *test_element2 = NULL;
	libcerror_error_t *error               = NULL;
	int *value1                            = NULL;
	int *value2                            = NULL;
	int result                             = 0;

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	/* Test set last element on an empty list
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

	/* Test set last element on a non-empty list
	 */
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	test_element2 = element2;
	element2      = NULL;

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
	          test_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Reset the previous and next elements
	 */
	result = libcdata_list_element_set_elements(
	          element1,
	          NULL,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_set_elements(
	          test_element2,
	          NULL,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_internal_list_set_last_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_internal_list_set_last_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_element_set_elements(
			          element1,
			          NULL,
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

	/* Test libcdata_internal_list_set_last_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_internal_list_set_last_element(
	          (libcdata_internal_list_t *) list,
	          element1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_element_set_elements(
			          element1,
			          NULL,
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element1,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *element_value                    = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
	int result                            = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	libcdata_list_t *list2                = NULL;
	libcdata_list_element_t *element2     = NULL;
#endif
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	/* Test regular cases
	 */
	result = libcdata_list_get_element_by_index(
	          list,
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

	/* Test error cases
	 */
	result = libcdata_list_get_element_by_index(
	          NULL,
	          1,
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
	          1,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_get_element_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_element_by_index(
	          list,
	          1,
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
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_element_by_index(
	          list,
	          1,
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_get_element_by_index on corrupted lists
	 */
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

	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          list2,
	          element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 6;

	list_element = NULL;

	result = libcdata_list_get_element_by_index(
	          list2,
	          2,
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

	/* Test libcdata_list_get_element_by_index with pthread_rwlock_rdlock failing in libcdata_list_element_get_next_element
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 1;

	list_element = NULL;

	result = libcdata_list_get_element_by_index(
	          list2,
	          2,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 4;

	list_element = NULL;

	result = libcdata_list_get_element_by_index(
	          list2,
	          1,
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

	( (libcdata_internal_list_t *) list2 )->last_element  = NULL;

	list_element = NULL;

	result = libcdata_list_get_element_by_index(
	          list2,
	          2,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 0;
	( (libcdata_internal_list_t *) list2 )->first_element       = NULL;

	result = libcdata_list_element_free(
	          &element2,
	          NULL,
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

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	if( list2 != NULL )
	{
		( (libcdata_internal_list_t *) list2 )->first_element = NULL;
		( (libcdata_internal_list_t *) list2 )->last_element  = NULL;
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 NULL,
		 NULL );
	}
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */
#endif
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
	int *element_value       = NULL;
	int *value1              = NULL;
	int *value2              = NULL;
	int *value3              = NULL;
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	result = libcdata_list_append_value(
	          list,
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

	/* Test regular cases
	 */
	result = libcdata_list_get_value_by_index(
	          list,
	          1,
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

	/* Test error cases
	 */
	result = libcdata_list_get_value_by_index(
	          NULL,
	          0,
	          (intptr_t **) &element_value,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test cdata_test_list_get_value_by_index with pthread_rwlock_rdlock failing in libcthreads_read_write_lock_grab_for_read
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          (intptr_t **) &element_value,
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
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 0;

	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          (intptr_t **) &element_value,
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

	/* Test cdata_test_list_get_value_by_index with pthread_rwlock_rdlock failing in libcdata_list_element_get_value
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 1;

	element_value = NULL;

	result = libcdata_list_get_value_by_index(
	          list,
	          0,
	          (intptr_t **) &element_value,
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
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
	int number_of_elements            = 0;
	int result                        = 0;

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	libcdata_list_t *list2            = NULL;
	libcdata_list_element_t *element4 = NULL;
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	/* Test regular cases
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

	element1 = NULL;

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

	element2 = NULL;

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

	/* Initialize test
	 */
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

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_element_set_value(
	          element3,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_prepend_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_prepend_element with pthread_rwlock_rdlock failing in libcdata_list_element_get_elements */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_prepend_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_prepend_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 2;

	result = libcdata_list_prepend_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_prepend_element on corrupted lists
	 */
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

	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libcdata_internal_list_t *) list2 )->first_element = element4;

	result = libcdata_list_prepend_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element  = element4;

	result = libcdata_list_prepend_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->last_element       = NULL;
	( (libcdata_internal_list_t *) list2 )->number_of_elements = 1;

	result = libcdata_list_prepend_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->first_element = element4;

	result = libcdata_list_prepend_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 0;
	( (libcdata_internal_list_t *) list2 )->first_element      = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element       = NULL;

	/* Test libcdata_list_prepend_element on a list element already part of a list
	 */
	result = libcdata_list_element_set_next_element(
	          element3,
	          element3,
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

	result = libcdata_list_element_set_next_element(
	          element3,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element4,
	          NULL,
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

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	if( element4 != NULL )
	{
		libcdata_list_element_free(
		 &element4,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( 0 );
}

/* Tests the libcdata_list_prepend_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_prepend_value(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
	int number_of_elements                = 0;
	int result                            = 0;

#if defined( HAVE_CDATA_TEST_MEMORY ) || defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_list_element_t *list_element = NULL;
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_prepend_value(
	          list,
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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_prepend_value(
	          list,
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
	result = libcdata_list_prepend_value(
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_prepend_value with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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

#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_prepend_value with pthread_rwlock_wrlock failing in libcdata_list_prepend_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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

	/* Test libcdata_list_prepend_value with pthread_rwlock_wrlock failing in libcdata_list_element_set_value
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 3;

	result = libcdata_list_prepend_value(
	          list,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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
			          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

			value3 = NULL;
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

		result = libcdata_list_remove_element(
		          list,
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	memory_free(
	 value3 );

	value3 = NULL;

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	int *value1                       = NULL;
	int *value2                       = NULL;
	int *value3                       = NULL;
	int number_of_elements            = 0;
	int result                        = 0;

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	libcdata_list_t *list2            = NULL;
	libcdata_list_element_t *element4 = NULL;
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	/* Test regular cases
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

	element2 = NULL;

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

	/* Initialize test
	 */
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

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_element_set_value(
	          element3,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

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

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_append_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_list_append_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_append_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_append_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

	/* Test libcdata_list_append_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 2;

	result = libcdata_list_append_element(
	          list,
	          element3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_append_element on corrupted lists
	 */
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

	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libcdata_internal_list_t *) list2 )->first_element = element4;

	result = libcdata_list_append_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element  = element4;

	result = libcdata_list_append_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->last_element         = NULL;
	( (libcdata_internal_list_t *) list2 )->number_of_elements   = 1;

	result = libcdata_list_append_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->first_element = element4;

	result = libcdata_list_append_element(
	          list2,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 0;
	( (libcdata_internal_list_t *) list2 )->first_element       = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element        = NULL;

	/* Test libcdata_list_append_element on a list element already part of a list
	 */
	result = libcdata_list_element_set_next_element(
	          element3,
	          element3,
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

	result = libcdata_list_element_set_next_element(
	          element3,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element4,
	          NULL,
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

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	if( element4 != NULL )
	{
		libcdata_list_element_free(
		 &element4,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	return( 0 );
}

/* Tests the libcdata_list_append_value function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_append_value(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcerror_error_t *error              = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
	int number_of_elements                = 0;
	int result                            = 0;

#if defined( HAVE_CDATA_TEST_MEMORY ) || defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_list_element_t *list_element = NULL;
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_append_value(
	          list,
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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_append_value(
	          list,
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
	result = libcdata_list_append_value(
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

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_append_value with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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

#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_append_value with pthread_rwlock_wrlock failing in libcdata_list_append_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_append_value(
	          list,
	          (intptr_t *) value3,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	memory_free(
	 value3 );

	value3 = NULL;

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

/* Tests the libcdata_internal_list_insert_element_find_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_list_insert_element_find_element(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcdata_list_element_t *element1     = NULL;
	libcdata_list_element_t *list_element = NULL;
	libcerror_error_t *error              = NULL;
	int *element_value                    = NULL;
	int *value1                           = NULL;
	int *value2                           = NULL;
	int element_index                     = 0;
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	/* Test find element on an empty list
	 */
	element_index = -1;
	list_element  = NULL;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	/* Test find element on a list with 1 elements where value is before the first element
	 */
	element_index = -1;
	list_element  = NULL;

	*value2 = -1;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a list with 1 elements where value is after the first element
	 */
	element_index = -1;
	list_element  = NULL;

	*value2 = 2;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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

	CDATA_TEST_ASSERT_IS_NULL(
	 "list_element",
	 list_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a list with 1 elements where value is the same as the first element
	 */
	element_index = -1;
	list_element  = NULL;

	*value2 = 1;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &element_index,
	          &list_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test find element on a list with 1 elements where value is the same as the first element
	 */
	element_index = -1;
	list_element  = NULL;

	*value2 = 1;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
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

	*value2 = 2;

	result = libcdata_internal_list_insert_element_find_element(
	          NULL,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
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
	memory_free(
	 value2 );

	value2 = NULL;

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_internal_list_insert_element_before_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_internal_list_insert_element_before_element(
     void )
{
	libcdata_list_t *list                  = NULL;
	libcdata_list_element_t *element1      = NULL;
	libcdata_list_element_t *element2      = NULL;
	libcdata_list_element_t *element3      = NULL;
	libcdata_list_element_t *test_element2 = NULL;
	libcerror_error_t *error               = NULL;
	int *value1                            = NULL;
	int *value2                            = NULL;
	int *value3                            = NULL;
	int result                             = 0;

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

	/* Test if insert of an element on an empty list succeeds
	 */
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          NULL,
	          element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	test_element2 = element2;
	element2      = NULL;

	/* Test if insert of an element before the first element succeeds
	 */
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          test_element2,
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

	/* Initialize test
	 */
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

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_element_set_value(
	          element3,
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

	/* Test error cases
	 */
	result = libcdata_internal_list_insert_element_before_element(
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

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_internal_list_insert_element_before_element with pthread_rwlock_rdlock failing in libcdata_list_element_get_previous_element */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          test_element2,
	          element3,
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

	/* Test libcdata_internal_list_insert_element_before_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          NULL,
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

	/* Test libcdata_internal_list_insert_element_before_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_elements */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          test_element2,
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

	/* Test libcdata_internal_list_insert_element_before_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          test_element2,
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

	/* Test libcdata_internal_list_insert_element_before_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 2;

	result = libcdata_internal_list_insert_element_before_element(
	          (libcdata_internal_list_t *) list,
	          test_element2,
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

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element3,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

/* Tests the libcdata_list_insert_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_insert_element(
     void )
{
	libcdata_list_t *list             = NULL;
	libcdata_list_element_t *element1 = NULL;
	libcerror_error_t *error          = NULL;
	int *value1                       = NULL;
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

	/* Test regular cases
	 */
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	result = libcdata_list_insert_element(
	          list,
	          element1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
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

	/* Test error cases
	 */
	result = libcdata_list_insert_element(
	          NULL,
	          element1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
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
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
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

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_insert_element_with_existing function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_insert_element_with_existing(
     void )
{
	libcdata_list_t *list                       = NULL;
	libcdata_list_element_t *duplicate_element2 = NULL;
	libcdata_list_element_t *element1           = NULL;
	libcdata_list_element_t *element2           = NULL;
	libcdata_list_element_t *element3           = NULL;
	libcdata_list_element_t *element4           = NULL;
	libcdata_list_element_t *element5           = NULL;
	libcdata_list_element_t *element8           = NULL;
	libcdata_list_element_t *existing_element   = NULL;
	libcerror_error_t *error                    = NULL;
	int *duplicate_value2                       = NULL;
	int *value1                                 = NULL;
	int *value2                                 = NULL;
	int *value3                                 = NULL;
	int *value4                                 = NULL;
	int *value5                                 = NULL;
	int *value8                                 = NULL;
	int number_of_elements                      = 0;
	int result                                  = 0;

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	libcdata_list_t *list2                     = NULL;
	libcdata_list_element_t *element6          = NULL;
	libcdata_list_element_t *element7          = NULL;
	libcdata_list_element_t *list_element      = NULL;
	intptr_t *value_ptr                        = NULL;
	int *value7                                = NULL;
	int element_index                          = 0;
#endif

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

	/* Test if insert of an element on an empty list succeeds
	 */
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

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_element_set_value(
	          element3,
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

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element3 = NULL;

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
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of an element before the first element succeeds
	 */
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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element1 = NULL;

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

	/* Test if insert of an element after the first element succeed
	 */
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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element2 = NULL;

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

	/* Test if insert of a duplicate element fails
	 */
	result = libcdata_list_element_initialize(
	          &duplicate_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_element2",
	 duplicate_element2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_value2 = (int *) memory_allocate(
	                            sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_value2",
	 duplicate_value2 );

	*duplicate_value2 = 2;

	result = libcdata_list_element_set_value(
	          duplicate_element2,
	          (intptr_t *) duplicate_value2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_value2 = NULL;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          duplicate_element2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_element",
	 existing_element );

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
	 3 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of an element after the last element succeeds
	 */
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

	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_list_element_set_value(
	          element4,
	          (intptr_t *) value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element4,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element4 = NULL;

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
	 4 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of a duplicate element succeeds
	 */
	result = libcdata_list_insert_element_with_existing(
	          list,
	          duplicate_element2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	duplicate_element2 = NULL;

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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Initialize test
	 */
	result = libcdata_list_element_initialize(
	          &element5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element5",
	 element5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value5 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value5",
	 value5 );

	*value5 = 5;

	result = libcdata_list_element_set_value(
	          element5,
	          (intptr_t *) value5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value5 = NULL;

	/* Test error cases
	 */
	result = libcdata_list_insert_element_with_existing(
	          NULL,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_insert_element_with_existing(
	          list,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with invalid value compare function
	 */
	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          NULL,
	          0,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test libcdata_list_insert_element_with_existing with unsupported insert flags
	 */
	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0x02,
	          &existing_element,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_element",
	 existing_element );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
			          list,
			          element5,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_element",
			 existing_element );

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
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 10;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
			          list,
			          element5,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_element",
			 existing_element );

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
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_rdlock failing in libcdata_list_element_get_elements */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_rdlock failing in libcdata_list_element_get_value */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 1;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Create an insert element with the value of the second list element
	 */
	result = libcdata_list_element_initialize(
	          &element7,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element7",
	 element7 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value7 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value7",
	 value7 );

	*value7 = 2;

	result = libcdata_list_element_set_value(
	          element7,
	          (intptr_t *) value7,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value7 = NULL;

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_rdlock
	 * failing in libcdata_list_element_get_elements of the existing element
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 5;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element7,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write (insert before existing element) */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 9;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element7,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element7,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element7",
	 element7 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_unlock
	 * failing in libcthreads_read_write_lock_release_for_write (append)
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 14;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

		CDATA_TEST_ASSERT_IS_NULL(
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Create an insert element with a value smaller than the value of the first list element
	 */
	result = libcdata_list_element_initialize(
	          &element8,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element8",
	 element8 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value8 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value8",
	 value8 );

	*value8 = 0;

	result = libcdata_list_element_set_value(
	          element8,
	          (intptr_t *) value8,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value8 = NULL;

	/* Test libcdata_list_insert_element_with_existing with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write (insert before the first element)
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 7;

	result = libcdata_list_insert_element_with_existing(
	          list,
	          element8,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_remove_element(
			          list,
			          element8,
			          &error );

			CDATA_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 1 );

			CDATA_TEST_ASSERT_IS_NULL(
			 "existing_element",
			 existing_element );

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
		 "existing_element",
		 existing_element );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
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
	 5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &element8,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element8",
	 element8 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_insert_element_with_existing on corrupted lists
	 */
	result = libcdata_list_element_initialize(
	          &element6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element6",
	 element6 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libcdata_internal_list_t *) list2 )->first_element = element6;;

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;;
	( (libcdata_internal_list_t *) list2 )->last_element  = element6;;

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;;
	( (libcdata_internal_list_t *) list2 )->last_element  = element6;;
	( (libcdata_internal_list_t *) list2 )->number_of_elements   = 1;;

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	( (libcdata_internal_list_t *) list2 )->first_element = element6;;

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	( (libcdata_internal_list_t *) list2 )->last_element  = NULL;

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 0;
	( (libcdata_internal_list_t *) list2 )->first_element       = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element        = NULL;

	/* Test libcdata_list_insert_element_with_existing on a list element already part of a list
	 */
	result = libcdata_list_element_set_next_element(
	          element6,
	          element6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_insert_element_with_existing(
	          list2,
	          element6,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_element,
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

	result = libcdata_list_element_set_next_element(
	          element6,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_internal_list_insert_element_find_element with an invalid value compare function
	 */
	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          NULL,
	          NULL,
	          0,
	          &element_index,
	          &existing_element,
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

	/* Test libcdata_internal_list_insert_element_find_element with unsupported insert flags
	 */
	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          NULL,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0x02,
	          &element_index,
	          &existing_element,
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

	/* Test libcdata_internal_list_insert_element_find_element with an unsupported compare function return value
	 */
	list_element = NULL;
	value_ptr    = NULL;

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

	result = libcdata_list_element_get_value(
	          list_element,
	          &value_ptr,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value_ptr",
	 value_ptr );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	cdata_test_list_value_compare_function_return_value = 9;

	result = libcdata_internal_list_insert_element_find_element(
	          (libcdata_internal_list_t *) list,
	          (intptr_t *) value_ptr,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &element_index,
	          &existing_element,
	          &error );

	cdata_test_list_value_compare_function_return_value = LIBCDATA_COMPARE_EQUAL;

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	result = libcdata_list_element_free(
	          &element6,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element6",
	 element6 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Clean up
	 */
	result = libcdata_list_element_free(
	          &element5,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element5",
	 element5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( duplicate_value2 != NULL )
	{
		memory_free(
		 duplicate_value2 );
	}
	if( duplicate_element2 != NULL )
	{
		libcdata_list_element_free(
		 &duplicate_element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value5 != NULL )
	{
		memory_free(
		 value5 );
	}
	if( element5 != NULL )
	{
		libcdata_list_element_free(
		 &element5,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value4 != NULL )
	{
		memory_free(
		 value4 );
	}
	if( element4 != NULL )
	{
		libcdata_list_element_free(
		 &element4,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value8 != NULL )
	{
		memory_free(
		 value8 );
	}
	if( element8 != NULL )
	{
		libcdata_list_element_free(
		 &element8,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	if( value7 != NULL )
	{
		memory_free(
		 value7 );
	}
	if( element7 != NULL )
	{
		libcdata_list_element_free(
		 &element7,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( element6 != NULL )
	{
		libcdata_list_element_free(
		 &element6,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

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
	int *value1              = NULL;
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
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_insert_value(
	          list,
	          (intptr_t *) value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
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
	result = libcdata_list_insert_value(
	          NULL,
	          (intptr_t *) value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
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

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	return( 0 );
}

/* Tests the libcdata_list_insert_value_with_existing function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_insert_value_with_existing(
     void )
{
	libcdata_list_t *list                 = NULL;
	libcerror_error_t *error              = NULL;
	intptr_t *existing_value              = NULL;
	int *duplicate_value2                 = NULL;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	int *duplicate_value3                 = NULL;
#endif
	int *value1                           = NULL;
	int *value2                           = NULL;
	int *value3                           = NULL;
	int *value4                           = NULL;
	int *value5                           = NULL;
	int result                            = 0;

#if defined( HAVE_CDATA_TEST_MEMORY ) || defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_list_element_t *list_element = NULL;
#endif

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

	/* Test if insert of an element on an empty list succeeds
	 */
	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value3 = NULL;

	/* Test if insert of an element before the first element succeeds
	 */
	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value1,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

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

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value2 = NULL;

	/* Test if insert of a duplicate element fails
	 */
	duplicate_value2 = (int *) memory_allocate(
	                            sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_value2",
	 duplicate_value2 );

	*duplicate_value2 = 2;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) duplicate_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test if insert of an element after the last element succeeds
	 */
	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value4,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

	/* Test if insert of a duplicate element succeeds
	 */
	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) duplicate_value2,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

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
	result = libcdata_list_insert_value_with_existing(
	          NULL,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	/* Test libcdata_list_insert_value_with_existing with an invalid existing value
	 */
	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          NULL,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "existing_value",
	 existing_value );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_CDATA_TEST_MEMORY )

	/* Test libcdata_list_insert_value_with_existing with malloc failing in libcdata_list_element_initialize
	 */
	cdata_test_malloc_attempts_before_fail = 0;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	if( cdata_test_malloc_attempts_before_fail != -1 )
	{
		cdata_test_malloc_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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
			 "existing_value",
			 existing_value );

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
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_MEMORY ) */

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Allocate a new value for an existing list element value
	 */
	duplicate_value3 = (int *) memory_allocate(
	                         sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "duplicate_value3",
	 duplicate_value3 );

	*duplicate_value3 = 2;

	/* Test libcdata_list_insert_value_with_existing with pthread_rwlock_destroy failing in libcdata_list_element_free
	 */
	cdata_test_pthread_rwlock_destroy_attempts_before_fail = 0;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) duplicate_value3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_destroy_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_destroy_attempts_before_fail = -1;

		if( result == 0 )
		{
			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "existing_value",
			 existing_value );

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
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libcdata_list_insert_value_with_existing with pthread_rwlock_rdlock failing in libcdata_list_element_get_value of the existing list element
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 5;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) duplicate_value3,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          LIBCDATA_INSERT_FLAG_UNIQUE_ENTRIES,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_rdlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_rdlock_attempts_before_fail = -1;

		if( result == 0 )
		{
			CDATA_TEST_ASSERT_IS_NOT_NULL(
			 "existing_value",
			 existing_value );

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
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}

	/* Test libcdata_list_insert_value_with_existing with pthread_rwlock_wrlock failing in libcdata_list_insert_value_with_existing
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_insert_value_with_existing(
	          list,
	          (intptr_t *) value5,
	          (int (*)(intptr_t *, intptr_t *, libcerror_error_t **)) &cdata_test_list_element_compare_function,
	          0,
	          &existing_value,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
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

			result = libcdata_list_remove_element(
			          list,
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
			 "existing_value",
			 existing_value );

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
		 "existing_value",
		 existing_value );

		CDATA_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Clean up
	 */
	memory_free(
	 value5 );

	value5 = NULL;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	if( duplicate_value3 != NULL )
	{
		memory_free(
		 duplicate_value3 );

		duplicate_value3 = NULL;
	}
#endif

	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	if( duplicate_value3 != NULL )
	{
		memory_free(
		 duplicate_value3 );
	}
#endif
	return( 0 );
}

/* Tests the libcdata_list_remove_element function
 * Returns 1 if successful or 0 if not
 */
int cdata_test_list_remove_element(
     void )
{
	libcdata_list_t *list                  = NULL;
	libcdata_list_element_t *element1      = NULL;
	libcdata_list_element_t *element2      = NULL;
	libcdata_list_element_t *element3      = NULL;
	libcdata_list_element_t *element4      = NULL;
	libcdata_list_t *list2                 = NULL;
	libcdata_list_element_t *element5      = NULL;
	libcdata_list_element_t *element6      = NULL;
	libcdata_list_element_t *test_element1 = NULL;
	libcdata_list_element_t *test_element2 = NULL;
	libcerror_error_t *error               = NULL;
	int *value1                            = NULL;
	int *value2                            = NULL;
	int *value3                            = NULL;
	int *value4                            = NULL;
	int number_of_elements                 = 0;
	int result                             = 0;

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )
	libcdata_list_element_t *list_middle   = NULL;
#endif

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

	value1 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value1",
	 value1 );

	*value1 = 1;

	result = libcdata_list_element_set_value(
	          element1,
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

	test_element1 = element1;
	element1      = NULL;

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

	value2 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value2",
	 value2 );

	*value2 = 2;

	result = libcdata_list_element_set_value(
	          element2,
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

	test_element2 = element2;
	element2      = NULL;

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

	value3 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value3",
	 value3 );

	*value3 = 3;

	result = libcdata_list_element_set_value(
	          element3,
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

	/* Test regular cases
	 */
	result = libcdata_list_remove_element(
	          list,
	          test_element2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_free(
	          &test_element2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "test_element2",
	 test_element2 );

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

	/* Test error cases
	 */
	result = libcdata_list_remove_element(
	          NULL,
	          test_element1,
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

#if defined( HAVE_CDATA_TEST_RWLOCK_HOOK )

	/* Test libcdata_list_remove_element with pthread_rwlock_wrlock failing in libcthreads_read_write_lock_grab_for_write
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 0;

	result = libcdata_list_remove_element(
	          list,
	          test_element1,
	          &error );

	if( cdata_test_pthread_rwlock_wrlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_wrlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_prepend_element(
			          list,
			          test_element1,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 3;

	result = libcdata_list_remove_element(
	          list,
	          test_element1,
	          &error );

	if( cdata_test_pthread_rwlock_unlock_attempts_before_fail != -1 )
	{
		cdata_test_pthread_rwlock_unlock_attempts_before_fail = -1;

		if( result == 1 )
		{
			result = libcdata_list_prepend_element(
			          list,
			          test_element1,
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

	/* Allocate a new list element
	 */
	result = libcdata_list_element_initialize(
	          &element5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element5",
	 element5 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_append_element(
	          list,
	          element5,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	element5 = NULL;

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

	result = libcdata_list_get_element_by_index(
	          list,
	          1,
	          &list_middle,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list_middle",
	 list_middle );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test libcdata_list_remove_element with pthread_rwlock_rdlock failing in libcdata_list_element_get_elements
	 */
	cdata_test_pthread_rwlock_rdlock_attempts_before_fail = 0;

	result = libcdata_list_remove_element(
	          list,
	          list_middle,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_elements
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 1;

	result = libcdata_list_remove_element(
	          list,
	          list_middle,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_previous_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 2;

	result = libcdata_list_remove_element(
	          list,
	          list_middle,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_wrlock failing in libcdata_list_element_set_next_element
	 */
	cdata_test_pthread_rwlock_wrlock_attempts_before_fail = 3;

	result = libcdata_list_remove_element(
	          list,
	          list_middle,
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

	/* Test libcdata_list_remove_element with pthread_rwlock_unlock failing in libcthreads_read_write_lock_release_for_write (middle list element)
	 */
	cdata_test_pthread_rwlock_unlock_attempts_before_fail = 4;

	result = libcdata_list_remove_element(
	          list,
	          list_middle,
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


#endif /* defined( HAVE_CDATA_TEST_RWLOCK_HOOK ) */

	/* Test remove of element not part of the list
	 */
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

	value4 = (int *) memory_allocate(
	                  sizeof( int ) );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "value4",
	 value4 );

	*value4 = 4;

	result = libcdata_list_element_set_value(
	          element4,
	          (intptr_t *) value4,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value4 = NULL;

/* TODO fix test */
#ifdef TODO
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
#endif

	result = libcdata_list_element_free(
	          &element4,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )

	/* Test libcdata_list_remove_element on corrupted lists
	 */
	result = libcdata_list_initialize(
	          &list2,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_element_initialize(
	          &element6,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NOT_NULL(
	 "element6",
	 element6 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	( (libcdata_internal_list_t *) list2 )->first_element = element6;

	result = libcdata_list_remove_element(
	          list2,
	          element6,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element  = element6;

	result = libcdata_list_remove_element(
	          list2,
	          element6,
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

	( (libcdata_internal_list_t *) list2 )->first_element = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element  = element6;
	( (libcdata_internal_list_t *) list2 )->number_of_elements = 1;

	result = libcdata_list_remove_element(
	          list2,
	          element6,
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

	( (libcdata_internal_list_t *) list2 )->first_element = element6;
	( (libcdata_internal_list_t *) list2 )->last_element  = NULL;

	result = libcdata_list_remove_element(
	          list2,
	          element6,
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

	( (libcdata_internal_list_t *) list2 )->number_of_elements = 0;
	( (libcdata_internal_list_t *) list2 )->first_element       = NULL;
	( (libcdata_internal_list_t *) list2 )->last_element        = NULL;

	result = libcdata_list_element_free(
	          &element6,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "element6",
	 element6 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libcdata_list_free(
	          &list2,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
	          &error );

	CDATA_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "list2",
	 list2 );

	CDATA_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	/* Clean up
	 */
	result = libcdata_list_free(
	          &list,
	          (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
	if( element5 != NULL )
	{
		libcdata_list_element_free(
		 &element5,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	if( element6 != NULL )
	{
		libcdata_list_element_free(
		 &element6,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list2 != NULL )
	{
		libcdata_list_free(
		 &list2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
#endif /* defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT ) */

	if( value4 != NULL )
	{
		memory_free(
		 value4 );
	}
	if( element4 != NULL )
	{
		libcdata_list_element_free(
		 &element4,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value3 != NULL )
	{
		memory_free(
		 value3 );
	}
	if( element3 != NULL )
	{
		libcdata_list_element_free(
		 &element3,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value2 != NULL )
	{
		memory_free(
		 value2 );
	}
	if( element2 != NULL )
	{
		libcdata_list_element_free(
		 &element2,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( value1 != NULL )
	{
		memory_free(
		 value1 );
	}
	if( element1 != NULL )
	{
		libcdata_list_element_free(
		 &element1,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
		 NULL );
	}
	if( list != NULL )
	{
		libcdata_list_free(
		 &list,
		 (int (*)(intptr_t **, libcerror_error_t **)) &cdata_test_list_value_free_function,
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
#endif

	CDATA_TEST_RUN(
	 "libcdata_list_get_last_element",
	 cdata_test_list_get_last_element );

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	CDATA_TEST_RUN(
	 "libcdata_internal_list_set_last_element",
	 cdata_test_internal_list_set_last_element );
#endif

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

#if defined( __GNUC__ ) && !defined( LIBCDATA_DLL_IMPORT )
	CDATA_TEST_RUN(
	 "libcdata_internal_list_insert_element_find_element",
	 cdata_test_internal_list_insert_element_find_element );

	CDATA_TEST_RUN(
	 "libcdata_internal_list_insert_element_before_element",
	 cdata_test_internal_list_insert_element_before_element );
#endif

	CDATA_TEST_RUN(
	 "libcdata_list_insert_element",
	 cdata_test_list_insert_element );

	CDATA_TEST_RUN(
	 "libcdata_list_insert_element_with_existing",
	 cdata_test_list_insert_element_with_existing );

	CDATA_TEST_RUN(
	 "libcdata_list_insert_value",
	 cdata_test_list_insert_value );

	CDATA_TEST_RUN(
	 "libcdata_list_insert_value_with_existing",
	 cdata_test_list_insert_value_with_existing );

	CDATA_TEST_RUN(
	 "libcdata_list_remove_element",
	 cdata_test_list_remove_element );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

