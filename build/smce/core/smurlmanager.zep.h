
extern zend_class_entry *smce_core_smurlmanager_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmUrlManager);

PHP_METHOD(Smce_Core_SmUrlManager, __construct);
PHP_METHOD(Smce_Core_SmUrlManager, parseUrl);
PHP_METHOD(Smce_Core_SmUrlManager, buildQueryString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smurlmanager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, requestUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smurlmanager_buildquerystring, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smurlmanager_method_entry) {
	PHP_ME(Smce_Core_SmUrlManager, __construct, arginfo_smce_core_smurlmanager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Smce_Core_SmUrlManager, parseUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmUrlManager, buildQueryString, arginfo_smce_core_smurlmanager_buildquerystring, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
