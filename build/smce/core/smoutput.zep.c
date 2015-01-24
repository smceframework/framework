
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/imadige/SMCEframework-MVC
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmOutput) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmOutput, smce, core_smoutput, smce_core_smoutput_method_entry, 0);

	zend_declare_property_null(smce_core_smoutput_ce, SL("header"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(smce_core_smoutput_ce, SL("fileName"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param $mimeType
 *
 * @return this
 */
PHP_METHOD(Smce_Core_SmOutput, setContentType) {

	zval *mimeType = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &mimeType);

	if (!mimeType) {
		ZEPHIR_INIT_VAR(mimeType);
		ZVAL_STRING(mimeType, "", 1);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "Content-Type: ", mimeType);
	zephir_update_property_this(this_ptr, SL("header"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * @param $mimeType
 *
 * @return this
 */
PHP_METHOD(Smce_Core_SmOutput, setFileName) {

	zval *fileName;

	zephir_fetch_params(0, 1, 0, &fileName);



	zephir_update_property_this(this_ptr, SL("fileName"), fileName TSRMLS_CC);
	RETURN_THISW();

}

/**
 * @param $data
 *
 * echo
 */
PHP_METHOD(Smce_Core_SmOutput, put) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *data, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("fileName"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fileName"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Content-disposition: attachment; filename=", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, _2);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, _1);
	zephir_check_call_status();
	zend_print_zval(data, 0);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param $data
 *
 * echo
 */
PHP_METHOD(Smce_Core_SmOutput, putFile) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval *file, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file);



	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("fileName"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("fileName"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Content-disposition: attachment; filename=", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, _2);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("header"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_3, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "readfile", &_4, file);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 *
 * @return $header
 */
PHP_METHOD(Smce_Core_SmOutput, getHeader) {


	RETURN_MEMBER(this_ptr, "header");

}

