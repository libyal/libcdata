#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libcdata/.libs/libcdata.1.dylib && test -f ./pycdata/.libs/pycdata.so;
then
	install_name_tool -change /usr/local/lib/libcdata.1.dylib ${PWD}/libcdata/.libs/libcdata.1.dylib ./pycdata/.libs/pycdata.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

