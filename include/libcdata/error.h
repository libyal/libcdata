/*
 * The error code definitions for libcdata
 *
 * Copyright (c) 2006-2013, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBCDATA_ERROR_H )
#define _LIBCDATA_ERROR_H

#include <libcdata/types.h>

/* External error type definition hides internal structure
 */
typedef intptr_t libcdata_error_t;

/* The error domains
 */
enum LIBCDATA_ERROR_DOMAINS
{
	LIBCDATA_ERROR_DOMAIN_ARGUMENTS			= (int) 'a',
	LIBCDATA_ERROR_DOMAIN_CONVERSION		= (int) 'c',
	LIBCDATA_ERROR_DOMAIN_COMPRESSION		= (int) 'C',
	LIBCDATA_ERROR_DOMAIN_IO			= (int) 'I',
	LIBCDATA_ERROR_DOMAIN_INPUT			= (int) 'i',
	LIBCDATA_ERROR_DOMAIN_MEMORY			= (int) 'm',
	LIBCDATA_ERROR_DOMAIN_OUTPUT			= (int) 'o',
	LIBCDATA_ERROR_DOMAIN_RUNTIME			= (int) 'r',
};

/* The argument error codes
 * to signify errors regarding arguments passed to a function
 */
enum LIBCDATA_ARGUMENT_ERROR
{
	LIBCDATA_ARGUMENT_ERROR_GENERIC			= 0,

	/* The argument contains an invalid value
	 */
	LIBCDATA_ARGUMENT_ERROR_INVALID_VALUE		= 1,

	/* The argument contains a value less than zero
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_LESS_THAN_ZERO	= 2,

	/* The argument contains a value zero or less
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_ZERO_OR_LESS	= 3,

	/* The argument contains a value that exceeds the maximum
	 * for the specific type
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_EXCEEDS_MAXIMUM	= 4,

	/* The argument contains a value that is too small
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_TOO_SMALL		= 5,

	/* The argument contains a value that is too large
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_TOO_LARGE		= 6,

	/* The argument contains a value that is out of bounds
	 */
	LIBCDATA_ARGUMENT_ERROR_VALUE_OUT_OF_BOUNDS	= 7,

	/* The argument contains a value that is not supported
	 */
	LIBCDATA_ARGUMENT_ERROR_UNSUPPORTED_VALUE	= 8,

	/* The argument contains a value that conficts with another argument
	 */
	LIBCDATA_ARGUMENT_ERROR_CONFLICTING_VALUE	= 9
};

/* The conversion error codes
 * to signify errors regarding conversions
 */
enum LIBCDATA_CONVERSION_ERROR
{
	LIBCDATA_CONVERSION_ERROR_GENERIC		= 0,

	/* The conversion failed on the input
	 */
	LIBCDATA_CONVERSION_ERROR_INPUT_FAILED		= 1,

	/* The conversion failed on the output
	 */
	LIBCDATA_CONVERSION_ERROR_OUTPUT_FAILED		= 2
};

/* The compression error codes
 * to signify errors regarding compression
 */
enum LIBCDATA_COMPRESSION_ERROR
{
	LIBCDATA_COMPRESSION_ERROR_GENERIC		= 0,

	/* The compression failed
	 */
	LIBCDATA_COMPRESSION_ERROR_COMPRESS_FAILED	= 1,

	/* The decompression failed
	 */
	LIBCDATA_COMPRESSION_ERROR_DECOMPRESS_FAILED	= 2
};

/* The input/output error codes
 * to signify errors regarding input/output
 */
enum LIBCDATA_IO_ERROR
{
	LIBCDATA_IO_ERROR_GENERIC			= 0,

	/* The open failed
	 */
	LIBCDATA_IO_ERROR_OPEN_FAILED			= 1,

	/* The close failed
	 */
	LIBCDATA_IO_ERROR_CLOSE_FAILED			= 2,

	/* The seek failed
	 */
	LIBCDATA_IO_ERROR_SEEK_FAILED			= 3,

	/* The read failed
	 */
	LIBCDATA_IO_ERROR_READ_FAILED			= 4,

	/* The write failed
	 */
	LIBCDATA_IO_ERROR_WRITE_FAILED			= 5,

	/* Access denied
	 */
	LIBCDATA_IO_ERROR_ACCESS_DENIED			= 6,

	/* The resource is invalid i.e. a missing file
	 */
	LIBCDATA_IO_ERROR_INVALID_RESOURCE		= 7,

	/* The ioctl failed
	 */
	LIBCDATA_IO_ERROR_IOCTL_FAILED			= 8,

	/* The unlink failed
	 */
	LIBCDATA_IO_ERROR_UNLINK_FAILED			= 9
};

/* The input error codes
 * to signify errors regarding handing input data
 */
enum LIBCDATA_INPUT_ERROR
{
	LIBCDATA_INPUT_ERROR_GENERIC			= 0,

	/* The input contains invalid data
	 */
	LIBCDATA_INPUT_ERROR_INVALID_DATA		= 1,

	/* The input contains an unsupported signature
	 */
	LIBCDATA_INPUT_ERROR_SIGNATURE_MISMATCH		= 2,

	/* A checksum in the input did not match
	 */
	LIBCDATA_INPUT_ERROR_CHECKSUM_MISMATCH		= 3,

	/* A value in the input did not match a previously
	 * read value or calculated value
	 */
	LIBCDATA_INPUT_ERROR_VALUE_MISMATCH		= 4
};

/* The memory error codes
 * to signify errors regarding memory
 */
enum LIBCDATA_MEMORY_ERROR
{
	LIBCDATA_MEMORY_ERROR_GENERIC			= 0,

	/* There is insufficient memory available
	 */
	LIBCDATA_MEMORY_ERROR_INSUFFICIENT		= 1,

	/* The memory failed to be copied
	 */
	LIBCDATA_MEMORY_ERROR_COPY_FAILED		= 2,

	/* The memory failed to be set
	 */
	LIBCDATA_MEMORY_ERROR_SET_FAILED		= 3
};

/* The runtime error codes
 * to signify errors regarding runtime processing
 */
enum LIBCDATA_RUNTIME_ERROR
{
	LIBCDATA_RUNTIME_ERROR_GENERIC			= 0,

	/* The value is missing
	 */
	LIBCDATA_RUNTIME_ERROR_VALUE_MISSING		= 1,

	/* The value was already set
	 */
	LIBCDATA_RUNTIME_ERROR_VALUE_ALREADY_SET	= 2,

	/* The creation and/or initialization of an internal structure failed
	 */
	LIBCDATA_RUNTIME_ERROR_INITIALIZE_FAILED	= 3,

	/* The resize of an internal structure failed
	 */
	LIBCDATA_RUNTIME_ERROR_RESIZE_FAILED		= 4,

	/* The free and/or finalization of an internal structure failed
	 */
	LIBCDATA_RUNTIME_ERROR_FINALIZE_FAILED		= 5,

	/* The value could not be determined
	 */
	LIBCDATA_RUNTIME_ERROR_GET_FAILED		= 6,

	/* The value could not be set
	 */
	LIBCDATA_RUNTIME_ERROR_SET_FAILED		= 7,

	/* The value could not be appended/prepended
	 */
	LIBCDATA_RUNTIME_ERROR_APPEND_FAILED		= 8,

	/* The value could not be copied
	 */
	LIBCDATA_RUNTIME_ERROR_COPY_FAILED		= 9,

	/* The value could not be removed
	 */
	LIBCDATA_RUNTIME_ERROR_REMOVE_FAILED		= 10,

	/* The value could not be printed
	 */
	LIBCDATA_RUNTIME_ERROR_PRINT_FAILED		= 11,

	/* The value was out of bounds
	 */
	LIBCDATA_RUNTIME_ERROR_VALUE_OUT_OF_BOUNDS	= 12,

	/* The value exceeds the maximum for its specific type
	 */
	LIBCDATA_RUNTIME_ERROR_VALUE_EXCEEDS_MAXIMUM	= 13,

	/* The value is unsupported
	 */
	LIBCDATA_RUNTIME_ERROR_UNSUPPORTED_VALUE	= 14,

	/* An abort was requested
	 */
	LIBCDATA_RUNTIME_ERROR_ABORT_REQUESTED		= 15
};

/* The output error codes
 */
enum LIBCDATA_OUTPUT_ERROR
{
	LIBCDATA_OUTPUT_ERROR_GENERIC			= 0,

	/* There is insuficient space to write the output
	 */
	LIBCDATA_OUTPUT_ERROR_INSUFFICIENT_SPACE	= 1
};

#endif

