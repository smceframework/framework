
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


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/smceframework
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmHelper) {

	ZEPHIR_REGISTER_CLASS(Smce\\Core, SmHelper, smce, core_smhelper, smce_core_smhelper_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Smce_Core_SmHelper, array_first) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *command, *myArray, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &command, &myArray);



	ZEPHIR_CALL_FUNCTION(&_0, "array_filter", &_1, myArray, command);
	zephir_check_call_status();
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", &_2, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_SmHelper, array_last) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zval *command, *myArray, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &command, &myArray);



	ZEPHIR_CALL_FUNCTION(&_0, "array_filter", &_1, myArray, command);
	zephir_check_call_status();
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("end", &_2, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_SmHelper, array_sort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *command, *myArray;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &command, &myArray);



	Z_SET_ISREF_P(myArray);
	ZEPHIR_CALL_FUNCTION(NULL, "usort", &_0, myArray, command);
	Z_UNSET_ISREF_P(myArray);
	zephir_check_call_status();
	RETVAL_ZVAL(myArray, 1, 0);
	RETURN_MM();

}

