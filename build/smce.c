
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "smce.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *smce_base_csmbase_ce;
zend_class_entry *smce_core_smacl_ce;
zend_class_entry *smce_core_smdbcriteria_ce;
zend_class_entry *smce_core_smexception_ce;
zend_class_entry *smce_core_smhelper_ce;
zend_class_entry *smce_core_smoutput_ce;
zend_class_entry *smce_core_smrouter_ce;
zend_class_entry *smce_core_smurlmanager_ce;

ZEND_DECLARE_MODULE_GLOBALS(smce)

static PHP_MINIT_FUNCTION(smce)
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

	ZEPHIR_INIT(Smce_Base_CSmBase);
	ZEPHIR_INIT(Smce_Core_SmACL);
	ZEPHIR_INIT(Smce_Core_SmDbCriteria);
	ZEPHIR_INIT(Smce_Core_SmException);
	ZEPHIR_INIT(Smce_Core_SmHelper);
	ZEPHIR_INIT(Smce_Core_SmOutput);
	ZEPHIR_INIT(Smce_Core_SmRouter);
	ZEPHIR_INIT(Smce_Core_SmUrlManager);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(smce)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_smce_globals *zephir_globals TSRMLS_DC)
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

	zephir_globals->test.my_setting_1 = 1;
	zephir_globals->test.my_setting_2 = 100;
	zephir_globals->test.my_setting_3 = 7.5;
	zephir_globals->my_setting_1 = 1;
	zephir_globals->my_setting_2 = 10;
	zephir_globals->my_setting_3 = 15.2;

}

static PHP_RINIT_FUNCTION(smce)
{

	zend_smce_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(smce)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(smce)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SMCE_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SMCE_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SMCE_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SMCE_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SMCE_ZEPVERSION);
	php_info_print_table_end();

	php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "setting1", "value1");
	php_info_print_table_row(2, "setting2", "value2");
	php_info_print_table_end();
	php_info_print_table_start();
	php_info_print_table_header(2, "Directive", "Value");
	php_info_print_table_row(2, "setting3", "value3");
	php_info_print_table_row(2, "setting4", "value4");
	php_info_print_table_end();

}

static PHP_GINIT_FUNCTION(smce)
{
	php_zephir_init_globals(smce_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(smce)
{

}

zend_module_entry smce_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SMCE_EXTNAME,
	NULL,
	PHP_MINIT(smce),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(smce),
#else
	NULL,
#endif
	PHP_RINIT(smce),
	PHP_RSHUTDOWN(smce),
	PHP_MINFO(smce),
	PHP_SMCE_VERSION,
	ZEND_MODULE_GLOBALS(smce),
	PHP_GINIT(smce),
	PHP_GSHUTDOWN(smce),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SMCE
ZEND_GET_MODULE(smce)
#endif
