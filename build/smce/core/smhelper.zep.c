
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"


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

PHP_METHOD(Smce_Core_SmHelper, array_filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *command, *myArray;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &command, &myArray);



	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", &_0, myArray, command);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Smce_Core_SmHelper, array_flatten) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *myArray, *array_re, *rarray, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &myArray);



	ZEPHIR_INIT_VAR(array_re);
	array_init(array_re);
	ZEPHIR_INIT_VAR(rarray);
	object_init_ex(rarray, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("recursivearrayiterator") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, myArray);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, rarray, "__construct", NULL, _0);
	zephir_check_call_status();
	zephir_is_iterable(rarray, &_2, &_1, 0, 0, "smce/core/smhelper.zep", 34);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(value, _3);
		zephir_array_append(&array_re, value, PH_SEPARATE, "smce/core/smhelper.zep", 31);
	}
	RETURN_CCTOR(array_re);

}

PHP_METHOD(Smce_Core_SmHelper, array_get) {

	HashTable *_3;
	HashPosition _2;
	zval *myArray = NULL, *params, *prEx = NULL, *_0, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &myArray, &params);

	ZEPHIR_SEPARATE_PARAM(myArray);


	if (Z_TYPE_P(params) == IS_NULL) {
		RETVAL_ZVAL(myArray, 1, 0);
		RETURN_MM();
	}
	if (zephir_array_isset(myArray, params)) {
		zephir_array_fetch(&_0, myArray, params, PH_NOISY | PH_READONLY, "smce/core/smhelper.zep", 49 TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_explode_str(_1, SL("."), params, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "smce/core/smhelper.zep", 55);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(prEx, _4);
		zephir_array_fetch(&_0, myArray, prEx, PH_NOISY | PH_READONLY, "smce/core/smhelper.zep", 52 TSRMLS_CC);
		ZEPHIR_CPY_WRT(myArray, _0);
	}
	RETVAL_ZVAL(myArray, 1, 0);
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

