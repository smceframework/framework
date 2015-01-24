
extern zend_class_entry *smce_core_smdbcriteria_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmDbCriteria);

PHP_METHOD(Smce_Core_SmDbCriteria, select);
PHP_METHOD(Smce_Core_SmDbCriteria, condition);
PHP_METHOD(Smce_Core_SmDbCriteria, limit);
PHP_METHOD(Smce_Core_SmDbCriteria, offset);
PHP_METHOD(Smce_Core_SmDbCriteria, order);
PHP_METHOD(Smce_Core_SmDbCriteria, from);
PHP_METHOD(Smce_Core_SmDbCriteria, group);
PHP_METHOD(Smce_Core_SmDbCriteria, having);
PHP_METHOD(Smce_Core_SmDbCriteria, join);
PHP_METHOD(Smce_Core_SmDbCriteria, push);
PHP_METHOD(Smce_Core_SmDbCriteria, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_select, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_condition, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_order, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_from, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_group, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_having, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smdbcriteria_join, 0, 0, 1)
	ZEND_ARG_INFO(0, critical)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smdbcriteria_method_entry) {
	PHP_ME(Smce_Core_SmDbCriteria, select, arginfo_smce_core_smdbcriteria_select, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, condition, arginfo_smce_core_smdbcriteria_condition, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, limit, arginfo_smce_core_smdbcriteria_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, offset, arginfo_smce_core_smdbcriteria_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, order, arginfo_smce_core_smdbcriteria_order, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, from, arginfo_smce_core_smdbcriteria_from, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, group, arginfo_smce_core_smdbcriteria_group, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, having, arginfo_smce_core_smdbcriteria_having, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, join, arginfo_smce_core_smdbcriteria_join, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, push, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmDbCriteria, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
