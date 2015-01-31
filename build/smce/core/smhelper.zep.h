
extern zend_class_entry *smce_core_smhelper_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmHelper);

PHP_METHOD(Smce_Core_SmHelper, array_first);
PHP_METHOD(Smce_Core_SmHelper, array_last);
PHP_METHOD(Smce_Core_SmHelper, array_sort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smhelper_array_first, 0, 0, 2)
	ZEND_ARG_INFO(0, command)
	ZEND_ARG_INFO(0, myArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smhelper_array_last, 0, 0, 2)
	ZEND_ARG_INFO(0, command)
	ZEND_ARG_INFO(0, myArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smhelper_array_sort, 0, 0, 2)
	ZEND_ARG_INFO(0, command)
	ZEND_ARG_INFO(0, myArray)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smhelper_method_entry) {
	PHP_ME(Smce_Core_SmHelper, array_first, arginfo_smce_core_smhelper_array_first, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_SmHelper, array_last, arginfo_smce_core_smhelper_array_last, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Smce_Core_SmHelper, array_sort, arginfo_smce_core_smhelper_array_sort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
