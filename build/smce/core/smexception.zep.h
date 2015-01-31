
extern zend_class_entry *smce_core_smexception_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmException);

PHP_METHOD(Smce_Core_SmException, getName);

ZEPHIR_INIT_FUNCS(smce_core_smexception_method_entry) {
	PHP_ME(Smce_Core_SmException, getName, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
