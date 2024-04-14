AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCTHREADS_CPPFLAGS@ \
	@PTHREAD_CPPFLAGS@ \
	@LIBCDATA_DLL_EXPORT@

lib_LTLIBRARIES = libcdata.la

libcdata_la_SOURCES = \
	libcdata.c \
	libcdata_array.c libcdata_array.h \
	libcdata_btree.c libcdata_btree.h \
	libcdata_btree_node.c libcdata_btree_node.h \
	libcdata_btree_values_list.c libcdata_btree_values_list.h \
	libcdata_definitions.h \
	libcdata_error.c libcdata_error.h \
	libcdata_extern.h \
	libcdata_libcerror.h \
	libcdata_libcthreads.h \
	libcdata_list.c libcdata_list.h \
	libcdata_list_element.c libcdata_list_element.h \
	libcdata_range_list.c libcdata_range_list.h \
	libcdata_range_list_value.c libcdata_range_list_value.h \
	libcdata_support.c libcdata_support.h \
	libcdata_tree_node.c libcdata_tree_node.h \
	libcdata_types.h \
	libcdata_unused.h

libcdata_la_LIBADD = \
	@LIBCERROR_LIBADD@ \
	@LIBCTHREADS_LIBADD@ \
	@PTHREAD_LIBADD@

libcdata_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libcdata_definitions.h.in \
	libcdata.rc \
	libcdata.rc.in

DISTCLEANFILES = \
	libcdata_definitions.h \
	libcdata.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libcdata ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libcdata_la_SOURCES)

