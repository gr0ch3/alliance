AC_DEFUN(AM_ALLIANCE,
[AC_REQUIRE([AM_INIT_AUTOMAKE])
echo 'ALLIANCE configuration ....'
if [ test "${ALLIANCE_TOP}" = "" ] ; then
   echo '${ALLIANCE_TOP} not defined'
   exit 1
fi
if [ test -d ${ALLIANCE_TOP} ] ; then
   echo '${ALLIANCE_TOP} =' ${ALLIANCE_TOP}
else
   echo 'Bad directory for ${ALLIANCE_TOP} =' ${ALLIANCE_TOP}
   exit 1
fi
INCLUDES="-I${ALLIANCE_TOP}/include $INCLUDES"
LIBS="-L${ALLIANCE_TOP}/lib $LIBS"
AC_SUBST(INCLUDES)
AC_SUBST(LIBS)

INSTALL_DATA='${INSTALL} -m 664'
AC_SUBST(INSTALL_DATA)
INSTALL_PROGRAM='${INSTALL} -m 775'
AC_SUBST(INSTALL_PROGRAM)]

AC_DEFINE_UNQUOTED(ALLIANCE_VERSION, "5.0")
)
