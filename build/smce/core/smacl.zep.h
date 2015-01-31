
extern zend_class_entry *smce_core_smacl_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmACL);

PHP_METHOD(Smce_Core_SmACL, rules);
PHP_METHOD(Smce_Core_SmACL, ipAdressSearch);
PHP_METHOD(Smce_Core_SmACL, loginControl);
PHP_METHOD(Smce_Core_SmACL, expressionControl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smacl_rules, 0, 0, 2)
	ZEND_ARG_INFO(0, accessRules)
	ZEND_ARG_INFO(0, view)
	ZEND_ARG_INFO(0, ip)
	ZEND_ARG_INFO(0, loginState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smacl_ipadresssearch, 0, 0, 1)
	ZEND_ARG_INFO(0, ipAdress)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smacl_logincontrol, 0, 0, 0)
	ZEND_ARG_INFO(0, users)
	ZEND_ARG_INFO(0, redirect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smacl_expressioncontrol, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smacl_method_entry) {
	PHP_ME(Smce_Core_SmACL, rules, arginfo_smce_core_smacl_rules, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmACL, ipAdressSearch, arginfo_smce_core_smacl_ipadresssearch, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Core_SmACL, loginControl, arginfo_smce_core_smacl_logincontrol, ZEND_ACC_PROTECTED)
	PHP_ME(Smce_Core_SmACL, expressionControl, arginfo_smce_core_smacl_expressioncontrol, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
