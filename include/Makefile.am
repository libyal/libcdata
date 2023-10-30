include_HEADERS = \
	libcdata.h

pkginclude_HEADERS = \
	libcdata/definitions.h \
	libcdata/error.h \
	libcdata/extern.h \
	libcdata/features.h \
	libcdata/types.h

EXTRA_DIST = \
	libcdata.h.in \
	libcdata/definitions.h.in \
	libcdata/features.h.in \
	libcdata/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libcdata.h
	-rm -f libcdata/definitions.h
	-rm -f libcdata/features.h
	-rm -f libcdata/types.h
	-rm -f Makefile

