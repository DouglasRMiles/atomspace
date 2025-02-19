# No CMakeLists.txt in dir:
#ADD_SUBDIRECTORY (wires)

ADD_GUILE_MODULE (FILES
	opencog.scm
	opencog/base/apply.scm
	opencog/base/atom-cache.scm
	opencog/base/core-docs.scm
	opencog/base/debug-trace.scm
	opencog/base/file-utils.scm
	opencog/base/repl-shell.scm
	opencog/base/tv.scm
	opencog/base/types.scm
	opencog/base/utilities.scm
	MODULE_DESTINATION "${GUILE_SITE_DIR}"
	DEPENDS opencog_atom_types
)

# Actually, each of these are distinct modules, and really
# should be listed separately, one module each. But, as it
# happens, the ADD_GUILE_MODULE macro still does the right
# thing for a mass listing like this, so .. OK. Whatever.
ADD_GUILE_MODULE (FILES
	opencog/exec.scm
	opencog/extension.scm
	opencog/logger.scm
	opencog/randgen.scm
	opencog/query.scm
	opencog/test-runner.scm
	opencog/type-utils.scm
	opencog/uuid.scm
	MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
)

# Need to recompile persist.scm whenever storage_types.scm changes
# However, no matter what I do, I can't get the rebuild to trigger.
# In other words, the persist module is badly broken.
ADD_GUILE_MODULE (FILES
	opencog/persist.scm
	MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
	DEPENDS storage_types
)

ADD_GUILE_MODULE (FILES
	opencog/persist-file.scm
	MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
)

# These guile modules spew "libBlahBlah.so not found" errors,
# if the user failed to actually build the needed component.
# So, do not install them if the component is missing.
IF (HAVE_GEARMAN)
	ADD_GUILE_MODULE (FILES
		opencog/dist-gearman.scm
		MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
	)
ENDIF (HAVE_GEARMAN)

IF (HAVE_SQL_STORAGE)
	ADD_GUILE_MODULE (FILES
		opencog/persist-sql.scm
		MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
	)
ENDIF (HAVE_SQL_STORAGE)

IF (HAVE_CYTHON)
	ADD_GUILE_MODULE (FILES
		opencog/python.scm
		MODULE_DESTINATION "${GUILE_SITE_DIR}/opencog"
	)
ENDIF (HAVE_CYTHON)
