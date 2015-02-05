
extern zend_class_entry *smce_base_smbase_ce;

ZEPHIR_INIT_CLASS(Smce_Base_SmBase);

PHP_METHOD(Smce_Base_SmBase, setSmRouter);
PHP_METHOD(Smce_Base_SmBase, setControllerView);
PHP_METHOD(Smce_Base_SmBase, isController);
PHP_METHOD(Smce_Base_SmBase, baseUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_base_smbase_setsmrouter, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_base_smbase_setcontrollerview, 0, 0, 1)
	ZEND_ARG_INFO(0, requestArray)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_base_smbase_method_entry) {
	PHP_ME(Smce_Base_SmBase, setSmRouter, arginfo_smce_base_smbase_setsmrouter, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_SmBase, setControllerView, arginfo_smce_base_smbase_setcontrollerview, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_SmBase, isController, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_SmBase, baseUrl, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
