dnl Functions for libcthreads
dnl
dnl Version: 20130503

dnl Function to detect if libcthreads is available
dnl ac_libcthreads_dummy is used to prevent AC_CHECK_LIB adding unnecessary -l<library> arguments
AC_DEFUN([AX_LIBCTHREADS_CHECK_LIB],
 [dnl Check if parameters were provided
 AS_IF(
  [test "x$ac_cv_with_libcthreads" != x && test "x$ac_cv_with_libcthreads" != xno && test "x$ac_cv_with_libcthreads" != xauto-detect],
  [AS_IF(
   [test -d "$ac_cv_with_libcthreads"],
   [CFLAGS="$CFLAGS -I${ac_cv_with_libcthreads}/include"
   LDFLAGS="$LDFLAGS -L${ac_cv_with_libcthreads}/lib"],
   [AC_MSG_WARN([no such directory: $ac_cv_with_libcthreads])
   ])
  ])

 AS_IF(
  [test "x$ac_cv_with_libcthreads" = xno],
  [ac_cv_libcthreads=no],
  [dnl Check for a pkg-config file
  AS_IF(
   [test "x$cross_compiling" != "xyes" && test "x$PKGCONFIG" != "x"],
   [PKG_CHECK_MODULES(
    [libcthreads],
    [libcthreads >= 20120425],
    [ac_cv_libcthreads=yes],
    [ac_cv_libcthreads=no])
   ])

  AS_IF(
   [test "x$ac_cv_libcthreads" = xyes],
   [ac_cv_libcthreads_CPPFLAGS="$pkg_cv_libcthreads_CFLAGS"
   ac_cv_libcthreads_LIBADD="$pkg_cv_libcthreads_LIBS"],
   [dnl Check for headers
   AC_CHECK_HEADERS([libcthreads.h])

   AS_IF(
    [test "x$ac_cv_header_libcthreads_h" = xno],
    [ac_cv_libcthreads=no],
    [dnl Check for the individual functions
    ac_cv_libcthreads=yes

    AC_CHECK_LIB(
     cthreads,
     libcthreads_get_version,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])

    dnl Thread functions
    AC_CHECK_LIB(
     cthreads,
     libcthreads_thread_create,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_thread_exit,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])

    dnl Lock functions
    AC_CHECK_LIB(
     cthreads,
     libcthreads_lock_initialize,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_lock_free,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_lock_grab,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_lock_release,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])

    dnl Read/Write lock functions
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_initialize,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_free,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_grab_for_read,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_grab_for_write,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_release_for_read,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])
    AC_CHECK_LIB(
     cthreads,
     libcthreads_read_write_lock_release_for_write,
     [ac_cv_libcthreads_dummy=yes],
     [ac_cv_libcthreads=no])

    ac_cv_libcthreads_LIBADD="-lcthreads"
    ])
   ])
  ])

 AS_IF(
  [test "x$ac_cv_libcthreads" = xyes],
  [AC_DEFINE(
   [HAVE_LIBCTHREADS],
   [1],
   [Define to 1 if you have the `cthreads' library (-lcthreads).])
  ])

 AS_IF(
  [test "x$ac_cv_libcthreads" = xyes],
  [ac_cv_libcthreads_locking=libcthreads],
  [ac_cv_libcthreads_locking=no])

 AS_IF(
  [test "x$ac_cv_libcthreads" = xyes],
  [AC_SUBST(
   [HAVE_LIBCTHREADS],
   [1]) ],
  [AC_SUBST(
   [HAVE_LIBCTHREADS],
   [0])
  ])
 ])

dnl Function to detect if libcthreads dependencies are available
AC_DEFUN([AX_LIBCTHREADS_CHECK_LOCAL],
 [AS_IF(
  [test "x$ac_cv_enable_winapi" = xno],
  [dnl Check for enabling pthread support
  AX_PTHREAD_CHECK_ENABLE
   ac_cv_libcthreads_locking=$ac_cv_pthread],
  [ac_cv_libcthreads_locking="winapi"])

 ac_cv_libcthreads_CPPFLAGS="-I../libcthreads";
 ac_cv_libcthreads_LIBADD="../libcthreads/libcthreads.la";

 ac_cv_libcthreads=local
 ])

dnl Function to detect how to enable libcthreads
AC_DEFUN([AX_LIBCTHREADS_CHECK_ENABLE],
 [AX_COMMON_ARG_WITH(
  [libcthreads],
  [libcthreads],
  [search for libcthreads in includedir and libdir or in the specified DIR, or no if to use local version],
  [auto-detect],
  [DIR])

 dnl Check for a shared library version
 AX_LIBCTHREADS_CHECK_LIB

 dnl Check if the dependencies for the local library version
 AS_IF(
  [test "x$ac_cv_libcthreads" != xyes],
  [AX_LIBCTHREADS_CHECK_LOCAL

  AC_DEFINE(
   [HAVE_LOCAL_LIBCTHREADS],
   [1],
   [Define to 1 if the local version of libcthreads is used.])
  AC_SUBST(
   [HAVE_LOCAL_LIBCTHREADS],
   [1])
  ])

 AM_CONDITIONAL(
  [HAVE_LOCAL_LIBCTHREADS],
  [test "x$ac_cv_libcthreads" = xlocal])
 AS_IF(
  [test "x$ac_cv_libcthreads_CPPFLAGS" != "x"],
  [AC_SUBST(
   [LIBCTHREADS_CPPFLAGS],
   [$ac_cv_libcthreads_CPPFLAGS])
  ])
 AS_IF(
  [test "x$ac_cv_libcthreads_LIBADD" != "x"],
  [AC_SUBST(
   [LIBCTHREADS_LIBADD],
   [$ac_cv_libcthreads_LIBADD])
  ])

 AS_IF(
  [test "x$ac_cv_libcthreads" = xyes],
  [AC_SUBST(
   [ax_libcthreads_pc_libs_private],
   [-lcthreads])
  ])

 AS_IF(
  [test "x$ac_cv_libcthreads" = xyes],
  [AC_SUBST(
   [ax_libcthreads_spec_requires],
   [libcthreads])
  AC_SUBST(
   [ax_libcthreads_spec_build_requires],
   [libcthreads-devel])
  ])
 ])
