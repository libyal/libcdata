#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libcdata/.libs/libcdata.1.dylib && test -f ./pycdata/.libs/pycdata.so
then
	install_name_tool -change /usr/local/lib/libcdata.1.dylib ${PWD}/libcdata/.libs/libcdata.1.dylib ./pycdata/.libs/pycdata.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

