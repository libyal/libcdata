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
	/bin/rm -f libcdata.h
	/bin/rm -f libcdata/definitions.h
	/bin/rm -f libcdata/features.h
	/bin/rm -f libcdata/types.h
	/bin/rm -f Makefile

