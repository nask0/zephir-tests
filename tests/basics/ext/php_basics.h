
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BASICS_H
#define PHP_BASICS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_BASICS_NAME        "basics"
#define PHP_BASICS_VERSION     "0.0.1"
#define PHP_BASICS_EXTNAME     "basics"
#define PHP_BASICS_AUTHOR      "Atanas Beloborodov <nask0@cod3r.net>"
#define PHP_BASICS_ZEPVERSION  "0.5.9a"
#define PHP_BASICS_DESCRIPTION "Extension that shows very basics of Zephir language"



ZEND_BEGIN_MODULE_GLOBALS(basics)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(basics)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(basics)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(basics_globals_id, zend_basics_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (basics_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_basics_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(basics_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(basics_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def basics_globals
#define zend_zephir_globals_def zend_basics_globals

extern zend_module_entry basics_module_entry;
#define phpext_basics_ptr &basics_module_entry

#endif
