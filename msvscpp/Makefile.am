MSVSCPP_FILES = \
	cdata_test_array/cdata_test_array.vcproj \
	cdata_test_btree/cdata_test_btree.vcproj \
	cdata_test_list/cdata_test_list.vcproj \
	cdata_test_list_element/cdata_test_list_element.vcproj \
	cdata_test_range_list/cdata_test_range_list.vcproj \
	cdata_test_tree_node/cdata_test_tree_node.vcproj \
	libcdata/libcdata.vcproj \
	libcerror/libcerror.vcproj \
	libcstring/libcstring.vcproj \
	libcthreads/libcthreads.vcproj \
	libcdata.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

