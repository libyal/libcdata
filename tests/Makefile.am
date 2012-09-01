AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@MEMWATCH_CPPFLAGS@

TESTS = \
	test_array.sh

check_SCRIPTS = \
	test_array.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	cdata_test_array

cdata_test_array_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_array.c

cdata_test_array_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la \
        @MEMWATCH_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

