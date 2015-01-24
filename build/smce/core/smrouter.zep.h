
extern zend_class_entry *smce_core_smrouter_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmRouter);

PHP_METHOD(Smce_Core_SmRouter, setRequest);
PHP_METHOD(Smce_Core_SmRouter, setRouter);
PHP_METHOD(Smce_Core_SmRouter, setRoute);
PHP_METHOD(Smce_Core_SmRouter, run);
PHP_METHOD(Smce_Core_SmRouter, createUrl);
PHP_METHOD(Smce_Core_SmRouter, redirect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smrouter_setrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smrouter_setrouter, 0, 0, 1)
	ZEND_ARG_INFO(0, router)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smrouter_setroute, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smrouter_createurl, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerView)
	ZEND_ARG_INFO(0, myArray)
	ZEND_ARG_INFO(0, baseUrl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smrouter_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerView)
	ZEND_ARG_INFO(0, myArray)
	ZEND_ARG_INFO(0, baseUrl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smrouter_method_entry) {
	PHP_ME(Smce_Core_SmRouter, setRequest, arginfo_smce_core_smrouter_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmRouter, setRouter, arginfo_smce_core_smrouter_setrouter, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmRouter, setRoute, arginfo_smce_core_smrouter_setroute, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmRouter, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmRouter, createUrl, arginfo_smce_core_smrouter_createurl, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmRouter, redirect, arginfo_smce_core_smrouter_redirect, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
