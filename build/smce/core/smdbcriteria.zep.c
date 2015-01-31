
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"

ZEPHIR_INIT_CLASS(Smce_Core_SmDbCriteria) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmDbCriteria, smce, core_smdbcriteria, smce_core_smdbcriteria_method_entry, 0);

	zend_declare_property_null(smce_core_smdbcriteria_ce, SL("criteria"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_SmDbCriteria, select) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "select", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, condition) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "conditions", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, limit) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "limit", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, offset) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "offset", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, order) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "order", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, from) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "from", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, group) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "group", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, having) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "having", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, join) {

	zval *critical, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &critical);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "joins", 1);
	zephir_update_property_array(this_ptr, SL("criteria"), _0, critical TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmDbCriteria, push) {


	RETURN_MEMBER(this_ptr, "criteria");

}

PHP_METHOD(Smce_Core_SmDbCriteria, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("criteria"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

