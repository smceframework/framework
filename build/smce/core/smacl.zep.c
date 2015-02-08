
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
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmACL) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmACL, smce, core_smacl, smce_core_smacl_method_entry, 0);

	zend_declare_property_null(smce_core_smacl_ce, SL("ip"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(smce_core_smacl_ce, SL("loginState"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $accessRules
 * @param $view
 *
 * @return bool
 */
PHP_METHOD(Smce_Core_SmACL, rules) {

	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _4, _12;
	HashTable *_2;
	HashPosition _1;
	zval *accessRules, *view, *ip = NULL, *loginState = NULL, *value = NULL, *_0, **_3, *_5 = NULL, *_6, *_8 = NULL, *_9, *_10, *_13 = NULL, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &accessRules, &view, &ip, &loginState);

	if (!ip) {
		ZEPHIR_INIT_VAR(ip);
		ZVAL_STRING(ip, "", 1);
	}
	if (!loginState) {
		ZEPHIR_INIT_VAR(loginState);
		ZVAL_STRING(loginState, "", 1);
	}


	zephir_update_property_this(this_ptr, SL("ip"), ip TSRMLS_CC);
	zephir_array_fetch_string(&_0, accessRules, SL("actions"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 28 TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "smce/core/smacl.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		_4 = zephir_array_isset_string(accessRules, SS("ip"));
		if (_4) {
			zephir_array_fetch_string(&_6, accessRules, SL("ip"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 30 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "ipadresssearch", &_7, _6);
			zephir_check_call_status();
			_4 = ZEPHIR_IS_TRUE(_5);
		}
		if (_4) {
			RETURN_MM_BOOL(1);
		}
		zephir_array_fetch_string(&_9, accessRules, SL("users"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 35 TSRMLS_CC);
		zephir_array_fetch_string(&_10, accessRules, SL("redirect"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 35 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "logincontrol", &_11, _9, _10, loginState);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(_8)) {
			RETURN_MM_BOOL(0);
		}
		_12 = zephir_array_isset_string(accessRules, SS("expression"));
		if (_12) {
			zephir_array_fetch_string(&_14, accessRules, SL("expression"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 42 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_13, this_ptr, "expressioncontrol", &_15, _14);
			zephir_check_call_status();
			_12 = ZEPHIR_IS_TRUE(_13);
		}
		if (_12) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * @param $ipAdress
 *
 * @return bool
 */
PHP_METHOD(Smce_Core_SmACL, ipAdressSearch) {

	zval *ipAdress, *_0;

	zephir_fetch_params(0, 1, 0, &ipAdress);



	if (Z_TYPE_P(ipAdress) == IS_ARRAY) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("ip"), PH_NOISY_CC);
		RETURN_BOOL(zephir_fast_in_array(_0, ipAdress TSRMLS_CC));
	}
	RETURN_BOOL(0);

}

/**
 * @param $users
 * @param $redirect
 *
 * @redirect url
 */
PHP_METHOD(Smce_Core_SmACL, loginControl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _0;
	zval *users = NULL, *redirect = NULL, *loginState, *router, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &users, &redirect, &loginState);

	if (!users) {
		ZEPHIR_INIT_VAR(users);
		ZVAL_STRING(users, "", 1);
	}
	if (!redirect) {
		ZEPHIR_INIT_VAR(redirect);
		ZVAL_STRING(redirect, "", 1);
	}


	_0 = ZEPHIR_IS_STRING(users, "@");
	if (_0) {
		_0 = ZEPHIR_IS_EMPTY(loginState);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(router);
		object_init_ex(router, smce_core_smrouter_ce);
		if (zephir_has_constructor(router TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, router, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_1);
		if (ZEPHIR_IS_STRING(redirect, "")) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "site/login", 1);
		} else {
			ZEPHIR_CPY_WRT(_1, redirect);
		}
		ZEPHIR_CALL_METHOD(NULL, router, "redirect", NULL, _1);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	} else {
		RETURN_MM_BOOL(1);
	}

}

/**
 * @param $expression
 *
 * @return bool
 */
PHP_METHOD(Smce_Core_SmACL, expressionControl) {

	zval *expression;

	zephir_fetch_params(0, 1, 0, &expression);



	if (ZEPHIR_IS_TRUE_IDENTICAL(expression)) {
		RETURN_BOOL(1);
	}
	RETURN_BOOL(0);

}

