AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBCDATA_DLL_IMPORT@

TESTS = \
	test_library.sh

check_SCRIPTS = \
	test_library.sh \
	test_manpage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	cdata_test_array \
	cdata_test_btree \
	cdata_test_btree_node \
	cdata_test_btree_values_list \
	cdata_test_error \
	cdata_test_list \
	cdata_test_list_element \
	cdata_test_range_list \
	cdata_test_range_list_value \
	cdata_test_support \
	cdata_test_tree_node

cdata_test_array_SOURCES = \
	cdata_test_array.c \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_rwlock.c cdata_test_rwlock.h \
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
	cdata_test_rwlock.c cdata_test_rwlock.h \
	cdata_test_unused.h

cdata_test_btree_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_btree_node_SOURCES = \
	cdata_test_btree_node.c \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_unused.h

cdata_test_btree_node_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_btree_values_list_SOURCES = \
	cdata_test_btree_values_list.c \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_unused.h

cdata_test_btree_values_list_LDADD = \
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
	cdata_test_rwlock.c cdata_test_rwlock.h \
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
	cdata_test_rwlock.c cdata_test_rwlock.h \
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
	cdata_test_rwlock.c cdata_test_rwlock.h \
	cdata_test_unused.h

cdata_test_range_list_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

cdata_test_range_list_value_SOURCES = \
	cdata_test_libcdata.h \
	cdata_test_libcerror.h \
	cdata_test_macros.h \
	cdata_test_memory.c cdata_test_memory.h \
	cdata_test_range_list_value.c \
	cdata_test_unused.h

cdata_test_range_list_value_LDADD = \
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
	cdata_test_rwlock.c cdata_test_rwlock.h \
	cdata_test_tree_node.c \
	cdata_test_unused.h

cdata_test_tree_node_LDADD = \
	../libcdata/libcdata.la \
	@LIBCERROR_LIBADD@

DISTCLEANFILES = \
	Makefile \
	Makefile.in

