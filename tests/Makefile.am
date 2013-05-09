AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@

TESTS = \
	test_array.sh \
	test_list_element.sh \
	test_list.sh \
	test_range_list.sh \
	test_tree_node.sh \
	test_btree.sh

check_SCRIPTS = \
	test_array.sh \
	test_btree.sh \
	test_list.sh \
	test_list_element.sh \
	test_range_list.sh \
	test_tree_node.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	cdata_test_array \
	cdata_test_btree \
	cdata_test_list \
	cdata_test_list_element \
	cdata_test_range_list \
	cdata_test_tree_node

cdata_test_array_SOURCES = \
	cdata_test_array.c \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_unused.h

cdata_test_array_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

cdata_test_btree_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_btree.c

cdata_test_btree_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

cdata_test_list_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_list.c

cdata_test_list_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

cdata_test_list_element_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_list_element.c

cdata_test_list_element_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

cdata_test_range_list_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_range_list.c

cdata_test_range_list_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

cdata_test_tree_node_SOURCES = \
	cdata_test_libcerror.h \
	cdata_test_libcdata.h \
	cdata_test_libcstring.h \
	cdata_test_tree_node.c

cdata_test_tree_node_LDADD = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@ \
	../libcdata/libcdata.la

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

