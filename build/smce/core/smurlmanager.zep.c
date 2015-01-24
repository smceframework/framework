
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/imadige/SMCEframework-MVC
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmUrlManager) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmUrlManager, smce, core_smurlmanager, smce_core_smurlmanager_method_entry, 0);

	zend_declare_property_string(smce_core_smurlmanager_ce, SL("requestUri"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $requestUri
 */
PHP_METHOD(Smce_Core_SmUrlManager, __construct) {

	zval *requestUri = NULL, *_SERVER, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &requestUri);

	if (!requestUri) {
		ZEPHIR_INIT_VAR(requestUri);
		ZVAL_STRING(requestUri, "", 1);
	}


	if (!(ZEPHIR_IS_EMPTY(requestUri))) {
		zephir_update_property_this(this_ptr, SL("requestUri"), requestUri TSRMLS_CC);
	} else {
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_array_fetch_string(&_0, _SERVER, SL("REQUEST_URI"), PH_NOISY | PH_READONLY, "smce/core/smurlmanager.zep", 22 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("requestUri"), _0 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 *
 *
 * @return parse_url()
 */
PHP_METHOD(Smce_Core_SmUrlManager, parseUrl) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("requestUri"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_url", &_1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param $params
 *
 * @return $url
 */
PHP_METHOD(Smce_Core_SmUrlManager, buildQueryString) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL, *query = NULL, *parse = NULL, *_GET, *_0, *_1, *_2 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params);

	if (!params) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	}


	ZEPHIR_INIT_VAR(query);
	array_init(query);
	zephir_get_global(&_GET, SS("_GET") TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_GET))) {
		ZEPHIR_CPY_WRT(query, _GET);
	}
	if (zephir_array_isset_string(query, SS("controller"))) {
		zephir_array_unset_string(&query, SS("controller"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(query, SS("view"))) {
		zephir_array_unset_string(&query, SS("view"), PH_SEPARATE);
	}
	if (zephir_array_isset_string(query, SS("p"))) {
		zephir_array_unset_string(&query, SS("p"), PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_array_merge(_0, &(query), &(params) TSRMLS_CC);
	ZEPHIR_CPY_WRT(query, _0);
	ZEPHIR_CALL_METHOD(&parse, this_ptr, "parseurl", NULL);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, parse, SL("path"), PH_NOISY | PH_READONLY, "smce/core/smurlmanager.zep", 70 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "http_build_query", &_3, query);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VSV(_4, _1, "?", _2);
	ZEPHIR_RETURN_CALL_FUNCTION("urldecode", &_5, _4);
	zephir_check_call_status();
	RETURN_MM();

}

