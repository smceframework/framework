
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Base_SmBase) {

	ZEPHIR_REGISTER_CLASS(Smce\\Base, SmBase, smce, base_smbase, smce_base_smbase_method_entry, 0);

	zend_declare_property_null(smce_base_smbase_ce, SL("config"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(smce_base_smbase_ce, SL("controller"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(smce_base_smbase_ce, SL("view"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * 
 * @param request
 *
 * @return SmRouter requestArray
 * 
 */
PHP_METHOD(Smce_Base_SmBase, setSmRouter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *request, *SmRouter, *_GET, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_INIT_VAR(SmRouter);
	object_init_ex(SmRouter, smce_core_smrouter_ce);
	if (zephir_has_constructor(SmRouter TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, SmRouter, "__construct", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, SmRouter, "setrequest", NULL, request);
	zephir_check_call_status();
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	if (zephir_array_isset_string(_GET, SS("route"))) {
		zephir_array_fetch_string(&_0, _GET, SL("route"), PH_NOISY | PH_READONLY, "smce/base/smbase.zep", 37 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, SmRouter, "setroute", NULL, _0);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	if (zephir_array_isset_string(_1, SS("urlrouter"))) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
		zephir_array_fetch_string(&_0, _2, SL("urlrouter"), PH_NOISY | PH_READONLY, "smce/base/smbase.zep", 41 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, SmRouter, "setrouter", NULL, _0);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(SmRouter, "run", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 *
 * @param requestArray
 *
 * @void
 * 
 */
PHP_METHOD(Smce_Base_SmBase, setControllerView) {

	int _3;
	HashTable *_1;
	HashPosition _0;
	zval *requestArray, *key = NULL, *value = NULL, **_2, *_GET, *_4 = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &requestArray);



	zephir_is_iterable(requestArray, &_1, &_0, 0, 0, "smce/base/smbase.zep", 62);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
		_3 = zephir_maybe_separate_zval(&_GET);
		zephir_array_update_zval(&_GET, key, &value, PH_COPY | PH_SEPARATE);
		if (_3) {
			ZEND_SET_SYMBOL(&EG(symbol_table), "_GET", _GET);
		}
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_array_fetch_string(&_5, requestArray, SL("controller"), PH_NOISY | PH_READONLY, "smce/base/smbase.zep", 62 TSRMLS_CC);
	zephir_fast_strtolower(_4, _5);
	zephir_update_static_property_ce(smce_base_smbase_ce, SL("controller"), &_4 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_4);
	zephir_array_fetch_string(&_6, requestArray, SL("view"), PH_NOISY | PH_READONLY, "smce/base/smbase.zep", 63 TSRMLS_CC);
	zephir_fast_strtolower(_4, _6);
	zephir_update_static_property_ce(smce_base_smbase_ce, SL("view"), &_4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 *
 *
 *
 * @void
 * 
 */
PHP_METHOD(Smce_Base_SmBase, isController) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_static_property_ce(smce_base_smbase_ce, SL("controller") TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "ucfirst", &_2, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _1, "Controller");
	if (zephir_class_exists(_3, 1 TSRMLS_CC)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 *
 *
 * @return baseUrl
 * 
 */
PHP_METHOD(Smce_Base_SmBase, baseUrl) {

	zval *_SERVER, *_0, _1, _2;


	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_array_fetch_string(&_0, _SERVER, SL("SCRIPT_NAME"), PH_NOISY | PH_READONLY, "smce/base/smbase.zep", 99 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/index.php", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "", 0);
	zephir_fast_str_replace(return_value, &_1, &_2, _0 TSRMLS_CC);
	return;

}

