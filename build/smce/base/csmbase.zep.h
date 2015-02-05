
extern zend_class_entry *smce_base_csmbase_ce;

ZEPHIR_INIT_CLASS(Smce_Base_CSmBase);

PHP_METHOD(Smce_Base_CSmBase, setSmRouter);
PHP_METHOD(Smce_Base_CSmBase, setControllerView);
PHP_METHOD(Smce_Base_CSmBase, isController);
PHP_METHOD(Smce_Base_CSmBase, baseUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_base_csmbase_setsmrouter, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_base_csmbase_setcontrollerview, 0, 0, 1)
	ZEND_ARG_INFO(0, requestArray)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_base_csmbase_method_entry) {
	PHP_ME(Smce_Base_CSmBase, setSmRouter, arginfo_smce_base_csmbase_setsmrouter, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_CSmBase, setControllerView, arginfo_smce_base_csmbase_setcontrollerview, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_CSmBase, isController, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Base_CSmBase, baseUrl, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
