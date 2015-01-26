
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
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

	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool _3, _6, _13;
	HashTable *_1;
	HashPosition _0;
	zval *accessRules, *view, *ip = NULL, *loginState = NULL, *value = NULL, **_2, *_4 = NULL, *_5, *_7 = NULL, *_8, *_10, *_11, *_14 = NULL, *_15;

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
	zephir_update_property_this(this_ptr, SL("loginState"), loginState TSRMLS_CC);
	zephir_is_iterable(accessRules, &_1, &_0, 0, 0, "smce/core/smacl.zep", 46);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(value, _2);
		_3 = zephir_array_isset_string(value, SS("actions"));
		if (_3) {
			ZEPHIR_INIT_NVAR(_4);
			zephir_fast_strtolower(_4, view);
			zephir_array_fetch_string(&_5, value, SL("actions"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 29 TSRMLS_CC);
			_3 = zephir_fast_in_array(_4, _5 TSRMLS_CC);
		}
		if (_3) {
			_6 = zephir_array_isset_string(value, SS("ip"));
			if (_6) {
				zephir_array_fetch_string(&_8, value, SL("ip"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 31 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_7, this_ptr, "ipadresssearch", &_9, _8);
				zephir_check_call_status();
				_6 = ZEPHIR_IS_TRUE(_7);
			}
			if (_6) {
				RETURN_MM_BOOL(1);
			}
			zephir_array_fetch_string(&_10, value, SL("users"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 36 TSRMLS_CC);
			zephir_array_fetch_string(&_11, value, SL("redirect"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 36 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "logincontrol", &_12, _10, _11);
			zephir_check_call_status();
			_13 = zephir_array_isset_string(value, SS("expression"));
			if (_13) {
				zephir_array_fetch_string(&_15, value, SL("expression"), PH_NOISY | PH_READONLY, "smce/core/smacl.zep", 38 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_14, this_ptr, "expressioncontrol", &_16, _15);
				zephir_check_call_status();
				_13 = ZEPHIR_IS_TRUE(_14);
			}
			if (_13) {
				RETURN_MM_BOOL(1);
			}
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
	zephir_nts_static zend_class_entry *_2 = NULL;
	zend_bool _0;
	zval *users = NULL, *redirect = NULL, *controller, *_1, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &users, &redirect);

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
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("loginState"), PH_NOISY_CC);
		_0 = ZEPHIR_IS_EMPTY(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(controller);
		if (!_2) {
			_2 = zend_fetch_class(SL("Smce\\Core\\SmController"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(controller, _2);
		if (zephir_has_constructor(controller TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, controller, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_3);
		if (ZEPHIR_IS_STRING(redirect, "")) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "site/login", 1);
		} else {
			ZEPHIR_CPY_WRT(_3, redirect);
		}
		ZEPHIR_CALL_METHOD(NULL, controller, "redirect", NULL, _3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

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

