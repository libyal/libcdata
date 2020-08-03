dnl Checks for required headers and functions
dnl
dnl Version: 20191221

dnl Function to detect if libcdata dependencies are available
AC_DEFUN([AX_LIBCDATA_CHECK_LOCAL],
  [dnl No additional checks.
  ])

dnl Function to check if DLL support is needed
AC_DEFUN([AX_LIBCDATA_CHECK_DLL_SUPPORT],
  [AS_IF(
    [test "x$enable_shared" = xyes],
    [AS_CASE(
      [$host],
      [*cygwin* | *mingw* | *msys*],
      [AC_DEFINE(
        [HAVE_DLLMAIN],
        [1],
        [Define to 1 to enable the DllMain function.])
      AC_SUBST(
        [HAVE_DLLMAIN],
        [1])

      AC_SUBST(
        [LIBCDATA_DLL_EXPORT],
        ["-DLIBCDATA_DLL_EXPORT"])

      AC_SUBST(
        [LIBCDATA_DLL_IMPORT],
        ["-DLIBCDATA_DLL_IMPORT"])
      ])
    ])
  ])

