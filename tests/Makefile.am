AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBCDATA_DLL_IMPORT@

TESTS = \
	test_api_functions.sh \
	test_api_types.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_api_types.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	cdata_test_array \
	cdata_test_btree \
	cdata_test_error \
	cdata_test_list \
	cdata_test_list_element \
	cdata_test_range_list \
	cdata_test_support \
	cdata_test_tree_node

cdata_test_array_SOURCES = \
	cdata_test_array.c \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_unused.h

cdata_test_array_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_btree_SOURCES = \
	cdata_test_btree.c \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_unused.h

cdata_test_btree_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_error_SOURCES = \
	cdata_test_error.c \
	cdata_test_libcdata.h \
	cdata_test_macros.h \
	cdata_test_unused.h

cdata_test_error_LDADD = \
	../libcdata/libcdata.la

cdata_test_list_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_list.c \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_unused.h

cdata_test_list_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_list_element_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_list_element.c \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_unused.h

cdata_test_list_element_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_range_list_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_range_list.c \
	cdata_test_unused.h

cdata_test_range_list_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_support_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_macros.h \
	cdata_test_support.c \
	cdata_test_unused.h

cdata_test_support_LDADD = \
	../libcdata/libcdata.la

cdata_test_tree_node_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_tree_node.c \
	cdata_test_unused.h

cdata_test_tree_node_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

