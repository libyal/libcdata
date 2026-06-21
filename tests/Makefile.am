AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBCDATA_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

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
	cdata_test_extern.h \
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
	cdata_test_extern.h \
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
	cdata_test_extern.h \
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
	cdata_test_extern.h \
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
	cdata_test_extern.h \
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
	cdata_test_extern.h \
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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: \
	package.m4 \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

