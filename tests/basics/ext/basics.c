
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "basics.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *basics_base_ce;

ZEND_DECLARE_MODULE_GLOBALS(basics)

static PHP_MINIT_FUNCTION(basics)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Basics_Base);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(basics)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_basics_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(basics)
{

	zend_basics_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(basics)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(basics)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_BASICS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BASICS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_BASICS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_BASICS_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_BASICS_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(basics)
{
	php_zephir_init_globals(basics_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(basics)
{

}

zend_module_entry basics_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BASICS_EXTNAME,
	NULL,
	PHP_MINIT(basics),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(basics),
#else
	NULL,
#endif
	PHP_RINIT(basics),
	PHP_RSHUTDOWN(basics),
	PHP_MINFO(basics),
	PHP_BASICS_VERSION,
	ZEND_MODULE_GLOBALS(basics),
	PHP_GINIT(basics),
	PHP_GSHUTDOWN(basics),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BASICS
ZEND_GET_MODULE(basics)
#endif
