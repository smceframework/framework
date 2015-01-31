
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Smce_Core_SmRouter) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmRouter, smce, core_smrouter, smce_core_smrouter_method_entry, 0);

	zend_declare_property_null(smce_core_smrouter_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(smce_core_smrouter_ce, SL("route"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(smce_core_smrouter_ce, SL("request"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(smce_core_smrouter_ce, SL("requestArray"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $request
 * 
 * 
 */
PHP_METHOD(Smce_Core_SmRouter, setRequest) {

	zval *request;

	zephir_fetch_params(0, 1, 0, &request);



	zephir_update_property_this(this_ptr, SL("request"), request TSRMLS_CC);

}

/**
 * @param $router
 * 
 * 
 */
PHP_METHOD(Smce_Core_SmRouter, setRouter) {

	zval *router;

	zephir_fetch_params(0, 1, 0, &router);



	zephir_update_property_this(this_ptr, SL("router"), router TSRMLS_CC);

}

/**
 * @param $route
 * 
 * 
 */
PHP_METHOD(Smce_Core_SmRouter, setRoute) {

	zval *route;

	zephir_fetch_params(0, 1, 0, &route);



	zephir_update_property_this(this_ptr, SL("route"), route TSRMLS_CC);

}

PHP_METHOD(Smce_Core_SmRouter, scriptNameIsFalse) {

	zval *requestArray = NULL, *routeGetEx, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestArray"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(requestArray, _0);
	if (zephir_isset_property(this_ptr, SS("route") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(routeGetEx);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("route"), PH_NOISY_CC);
		zephir_fast_explode_str(routeGetEx, SL("/"), _0, LONG_MAX TSRMLS_CC);
		ZEPHIR_INIT_NVAR(requestArray);
		array_init_size(requestArray, 3);
		ZEPHIR_INIT_VAR(_1);
		if (zephir_array_isset_long(routeGetEx, 0)) {
			ZEPHIR_OBS_NVAR(_1);
			zephir_array_fetch_long(&_1, routeGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 56 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "", 1);
		}
		zephir_array_update_string(&requestArray, SL("controller"), &_1, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_LNVAR(_1);
		if (zephir_array_isset_long(routeGetEx, 1)) {
			ZEPHIR_OBS_NVAR(_1);
			zephir_array_fetch_long(&_1, routeGetEx, 1, PH_NOISY, "smce/core/smrouter.zep", 57 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "", 1);
		}
		zephir_array_update_string(&requestArray, SL("view"), &_1, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(requestArray);

}

PHP_METHOD(Smce_Core_SmRouter, scriptNameIsTrue) {

	HashTable *_12, *_16;
	HashPosition _11, _15;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *requestArray = NULL, *parse = NULL, *requestGetEx, *key = NULL, *value = NULL, *_0, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8, *_9, *_10, **_13, *_14, **_17;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestArray"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(requestArray, _0);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&parse, "parse_url", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(requestGetEx);
	zephir_array_fetch_string(&_2, parse, SL("path"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 69 TSRMLS_CC);
	zephir_fast_explode_str(requestGetEx, SL("/"), _2, LONG_MAX TSRMLS_CC);
	ZEPHIR_INIT_NVAR(requestArray);
	array_init_size(requestArray, 3);
	ZEPHIR_INIT_VAR(_3);
	if (zephir_array_isset_long(requestGetEx, 0)) {
		ZEPHIR_OBS_NVAR(_3);
		zephir_array_fetch_long(&_3, requestGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 72 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "", 1);
	}
	zephir_array_update_string(&requestArray, SL("controller"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_3);
	if (zephir_array_isset_long(requestGetEx, 1)) {
		ZEPHIR_OBS_NVAR(_3);
		zephir_array_fetch_long(&_3, requestGetEx, 1, PH_NOISY, "smce/core/smrouter.zep", 73 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "", 1);
	}
	zephir_array_update_string(&requestArray, SL("view"), &_3, PH_COPY | PH_SEPARATE);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("router"), PH_READONLY, "smce/core/smrouter.zep", 75 TSRMLS_CC);
	zephir_array_fetch_long(&_6, requestGetEx, 0, PH_READONLY, "smce/core/smrouter.zep", 75 TSRMLS_CC);
	if (zephir_array_isset(_5, _6)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, _7, SL("router"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 77 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_10);
		zephir_array_fetch_long(&_10, requestGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 77 TSRMLS_CC);
		zephir_array_fetch(&_9, _8, _10, PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 77 TSRMLS_CC);
		zephir_is_iterable(_9, &_12, &_11, 0, 0, "smce/core/smrouter.zep", 84);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HMKEY(key, _12, _11);
			ZEPHIR_GET_HVALUE(value, _13);
			if (zephir_array_isset_long(requestGetEx, (zephir_get_numberval(key) + 2))) {
				zephir_array_fetch_long(&_14, requestGetEx, (zephir_get_numberval(key) + 2), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 80 TSRMLS_CC);
				zephir_array_update_zval(&requestArray, value, &_14, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		zephir_array_fetch_string(&_8, _7, SL("router"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 85 TSRMLS_CC);
		zephir_array_fetch_string(&_9, _8, SL("all"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 85 TSRMLS_CC);
		zephir_is_iterable(_9, &_16, &_15, 0, 0, "smce/core/smrouter.zep", 91);
		for (
		  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HMKEY(key, _16, _15);
			ZEPHIR_GET_HVALUE(value, _17);
			if (zephir_array_isset_long(requestGetEx, (zephir_get_numberval(key) + 2))) {
				zephir_array_fetch_long(&_14, requestGetEx, (zephir_get_numberval(key) + 2), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 88 TSRMLS_CC);
				zephir_array_update_zval(&requestArray, value, &_14, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(requestArray);

}

/**
 * run
 * 
 * @return requestArray
 */
PHP_METHOD(Smce_Core_SmRouter, run) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _2;
	zval *requestArray = NULL, *_0, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestArray"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(requestArray, _0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("request"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_1)) {
		ZEPHIR_INIT_NVAR(requestArray);
		array_init_size(requestArray, 3);
		add_assoc_stringl_ex(requestArray, SS("controller"), SL("site"), 1);
		add_assoc_stringl_ex(requestArray, SS("view"), SL("index"), 1);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		_2 = !zephir_array_isset_string(_0, SS("showScriptName"));
		if (!(_2)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
			zephir_array_fetch_string(&_4, _3, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 112 TSRMLS_CC);
			_2 = ZEPHIR_IS_FALSE(_4);
		}
		if (_2) {
			ZEPHIR_CALL_METHOD(&requestArray, this_ptr, "scriptnameisfalse", NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&requestArray, this_ptr, "scriptnameistrue", NULL);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(requestArray);

}

/**
 * @param $controllerView
 * @param $array
 * @param $baseUrl
 * 
 * @return url
 */
PHP_METHOD(Smce_Core_SmRouter, createUrl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_14 = NULL;
	HashTable *_6, *_10;
	HashPosition _5, _9;
	zend_bool _1;
	zval *controllerView = NULL, *myArray = NULL, *baseUrl, *str, *key = NULL, *value = NULL, *_0, *_2, *_3, *_4 = NULL, **_7, *_8 = NULL, **_11, _12 = zval_used_for_init, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &controllerView, &myArray, &baseUrl);

	if (!controllerView) {
		ZEPHIR_INIT_VAR(controllerView);
		ZVAL_STRING(controllerView, "", 1);
	}
	if (!myArray) {
		ZEPHIR_INIT_VAR(myArray);
		array_init(myArray);
	}


	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	_1 = zephir_array_isset_string(_0, SS("showScriptName"));
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 135 TSRMLS_CC);
		_1 = ZEPHIR_IS_TRUE(_3);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_6, &_5, 0, 0, "smce/core/smrouter.zep", 140);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SV(_8, "/", value);
			zephir_concat_self(&str, _8 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/index.php?route=", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_10, &_9, 0, 0, "smce/core/smrouter.zep", 145);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(key, _10, _9);
			ZEPHIR_GET_HVALUE(value, _11);
			ZEPHIR_SINIT_NVAR(_12);
			ZVAL_STRING(&_12, "&%s=%s", 0);
			ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_14, &_12, key, value);
			zephir_check_call_status();
			zephir_concat_self(&str, _13 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(str);

}

/**
 * @param $controllerView
 * @param $array
 * @param $baseUrl
 * 
 * @header url
 */
PHP_METHOD(Smce_Core_SmRouter, redirect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	HashTable *_6, *_10;
	HashPosition _5, _9;
	zend_bool _1;
	zval *controllerView = NULL, *myArray = NULL, *baseUrl, *str, *key = NULL, *value = NULL, *_0, *_2, *_3, *_4 = NULL, **_7, *_8 = NULL, **_11, _12 = zval_used_for_init, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &controllerView, &myArray, &baseUrl);

	if (!controllerView) {
		ZEPHIR_INIT_VAR(controllerView);
		ZVAL_STRING(controllerView, "", 1);
	}
	if (!myArray) {
		ZEPHIR_INIT_VAR(myArray);
		array_init(myArray);
	}


	ZEPHIR_INIT_VAR(str);
	ZVAL_STRING(str, "", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
	_1 = zephir_array_isset_string(_0, SS("showScriptName"));
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		zephir_array_fetch_string(&_3, _2, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 163 TSRMLS_CC);
		_1 = ZEPHIR_IS_TRUE(_3);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_6, &_5, 0, 0, "smce/core/smrouter.zep", 168);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(key, _6, _5);
			ZEPHIR_GET_HVALUE(value, _7);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SV(_8, "/", value);
			zephir_concat_self(&str, _8 TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/index.php?route=", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_10, &_9, 0, 0, "smce/core/smrouter.zep", 173);
		for (
		  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
		  ; zephir_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(key, _10, _9);
			ZEPHIR_GET_HVALUE(value, _11);
			ZEPHIR_SINIT_NVAR(_12);
			ZVAL_STRING(&_12, "&%s=%s", 0);
			ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_14, &_12, key, value);
			zephir_check_call_status();
			zephir_concat_self(&str, _13 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SV(_4, "Location: ", str);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_15, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Smce_Core_SmRouter, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	add_assoc_stringl_ex(_0, SS("controller"), SL(""), 1);
	add_assoc_stringl_ex(_0, SS("view"), SL(""), 1);
	zephir_update_property_this(this_ptr, SL("requestArray"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

