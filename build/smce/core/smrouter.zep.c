
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/imadige/SMCEframework-MVC
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmRouter) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmRouter, smce, core_smrouter, smce_core_smrouter_method_entry, 0);

	zend_declare_property_null(smce_core_smrouter_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(smce_core_smrouter_ce, SL("route"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(smce_core_smrouter_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

/**
 * run
 * 
 * @return requestArray
 */
PHP_METHOD(Smce_Core_SmRouter, run) {

	HashTable *_17, *_21;
	HashPosition _16, _20;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	zend_bool _2;
	zval *requestArray = NULL, *routeGetEx = NULL, *parse = NULL, *requestGetEx, *key = NULL, *value = NULL, *_0, *_1, *_3, *_4, *_5, *_6 = NULL, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, **_18, *_19, **_22;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(requestArray);
	array_init_size(requestArray, 3);
	add_assoc_stringl_ex(requestArray, SS("controller"), SL(""), 1);
	add_assoc_stringl_ex(requestArray, SS("view"), SL(""), 1);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("request"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_0)) {
		ZEPHIR_INIT_NVAR(requestArray);
		array_init_size(requestArray, 3);
		add_assoc_stringl_ex(requestArray, SS("controller"), SL("site"), 1);
		add_assoc_stringl_ex(requestArray, SS("view"), SL("index"), 1);
	} else {
		ZEPHIR_INIT_VAR(routeGetEx);
		array_init(routeGetEx);
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
		_2 = !zephir_array_isset_string(_1, SS("showScriptName"));
		if (!(_2)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
			zephir_array_fetch_string(&_4, _3, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 64 TSRMLS_CC);
			_2 = ZEPHIR_IS_FALSE(_4);
		}
		if (_2) {
			if (zephir_isset_property(this_ptr, SS("route") TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(routeGetEx);
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("route"), PH_NOISY_CC);
				zephir_fast_explode_str(routeGetEx, SL("/"), _5, LONG_MAX TSRMLS_CC);
				ZEPHIR_INIT_NVAR(requestArray);
				array_init_size(requestArray, 3);
				ZEPHIR_INIT_VAR(_6);
				if (zephir_array_isset_long(routeGetEx, 0)) {
					ZEPHIR_OBS_NVAR(_6);
					zephir_array_fetch_long(&_6, routeGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 70 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_STRING(_6, "", 1);
				}
				zephir_array_update_string(&requestArray, SL("controller"), &_6, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_LNVAR(_6);
				if (zephir_array_isset_long(routeGetEx, 1)) {
					ZEPHIR_OBS_NVAR(_6);
					zephir_array_fetch_long(&_6, routeGetEx, 1, PH_NOISY, "smce/core/smrouter.zep", 71 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_6);
					ZVAL_STRING(_6, "", 1);
				}
				zephir_array_update_string(&requestArray, SL("view"), &_6, PH_COPY | PH_SEPARATE);
			}
		} else {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("request"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&parse, "parse_url", &_7, _5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(requestGetEx);
			zephir_array_fetch_string(&_8, parse, SL("path"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 75 TSRMLS_CC);
			zephir_fast_explode_str(requestGetEx, SL("/"), _8, LONG_MAX TSRMLS_CC);
			ZEPHIR_INIT_NVAR(requestArray);
			array_init_size(requestArray, 3);
			ZEPHIR_INIT_LNVAR(_6);
			if (zephir_array_isset_long(requestGetEx, 0)) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_array_fetch_long(&_6, requestGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 78 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "", 1);
			}
			zephir_array_update_string(&requestArray, SL("controller"), &_6, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_6);
			if (zephir_array_isset_long(requestGetEx, 1)) {
				ZEPHIR_OBS_NVAR(_6);
				zephir_array_fetch_long(&_6, requestGetEx, 1, PH_NOISY, "smce/core/smrouter.zep", 79 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_STRING(_6, "", 1);
			}
			zephir_array_update_string(&requestArray, SL("view"), &_6, PH_COPY | PH_SEPARATE);
			_9 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
			zephir_array_fetch_string(&_10, _9, SL("router"), PH_READONLY, "smce/core/smrouter.zep", 81 TSRMLS_CC);
			zephir_array_fetch_long(&_11, requestGetEx, 0, PH_READONLY, "smce/core/smrouter.zep", 81 TSRMLS_CC);
			if (zephir_array_isset(_10, _11)) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
				zephir_array_fetch_string(&_13, _12, SL("router"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 83 TSRMLS_CC);
				ZEPHIR_OBS_VAR(_15);
				zephir_array_fetch_long(&_15, requestGetEx, 0, PH_NOISY, "smce/core/smrouter.zep", 83 TSRMLS_CC);
				zephir_array_fetch(&_14, _13, _15, PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 83 TSRMLS_CC);
				zephir_is_iterable(_14, &_17, &_16, 0, 0, "smce/core/smrouter.zep", 89);
				for (
				  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
				  ; zephir_hash_move_forward_ex(_17, &_16)
				) {
					ZEPHIR_GET_HMKEY(key, _17, _16);
					ZEPHIR_GET_HVALUE(value, _18);
					if (zephir_array_isset_long(requestGetEx, (zephir_get_numberval(key) + 2))) {
						zephir_array_fetch_long(&_19, requestGetEx, (zephir_get_numberval(key) + 2), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 86 TSRMLS_CC);
						zephir_array_update_zval(&requestArray, value, &_19, PH_COPY | PH_SEPARATE);
					}
				}
			} else {
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("router"), PH_NOISY_CC);
				zephir_array_fetch_string(&_13, _5, SL("router"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 90 TSRMLS_CC);
				zephir_array_fetch_string(&_14, _13, SL("all"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 90 TSRMLS_CC);
				zephir_is_iterable(_14, &_21, &_20, 0, 0, "smce/core/smrouter.zep", 96);
				for (
				  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
				  ; zephir_hash_move_forward_ex(_21, &_20)
				) {
					ZEPHIR_GET_HMKEY(key, _21, _20);
					ZEPHIR_GET_HVALUE(value, _22);
					if (zephir_array_isset_long(requestGetEx, (zephir_get_numberval(key) + 2))) {
						zephir_array_fetch_long(&_19, requestGetEx, (zephir_get_numberval(key) + 2), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 93 TSRMLS_CC);
						zephir_array_update_zval(&requestArray, value, &_19, PH_COPY | PH_SEPARATE);
					}
				}
			}
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
		zephir_array_fetch_string(&_3, _2, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 116 TSRMLS_CC);
		_1 = ZEPHIR_IS_TRUE(_3);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_6, &_5, 0, 0, "smce/core/smrouter.zep", 121);
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
		zephir_is_iterable(myArray, &_10, &_9, 0, 0, "smce/core/smrouter.zep", 126);
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
		zephir_array_fetch_string(&_3, _2, SL("showScriptName"), PH_NOISY | PH_READONLY, "smce/core/smrouter.zep", 144 TSRMLS_CC);
		_1 = ZEPHIR_IS_TRUE(_3);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_VSV(_4, baseUrl, "/", controllerView);
		zephir_concat_self(&str, _4 TSRMLS_CC);
		zephir_is_iterable(myArray, &_6, &_5, 0, 0, "smce/core/smrouter.zep", 149);
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
		zephir_is_iterable(myArray, &_10, &_9, 0, 0, "smce/core/smrouter.zep", 154);
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

