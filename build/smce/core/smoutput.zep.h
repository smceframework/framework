
extern zend_class_entry *smce_core_smoutput_ce;

ZEPHIR_INIT_CLASS(Smce_Core_SmOutput);

PHP_METHOD(Smce_Core_SmOutput, setContentType);
PHP_METHOD(Smce_Core_SmOutput, setFileName);
PHP_METHOD(Smce_Core_SmOutput, put);
PHP_METHOD(Smce_Core_SmOutput, putFile);
PHP_METHOD(Smce_Core_SmOutput, getHeader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smoutput_setcontenttype, 0, 0, 0)
	ZEND_ARG_INFO(0, mimeType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smoutput_setfilename, 0, 0, 1)
	ZEND_ARG_INFO(0, fileName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smoutput_put, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_smce_core_smoutput_putfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(smce_core_smoutput_method_entry) {
	PHP_ME(Smce_Core_SmOutput, setContentType, arginfo_smce_core_smoutput_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmOutput, setFileName, arginfo_smce_core_smoutput_setfilename, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmOutput, put, arginfo_smce_core_smoutput_put, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmOutput, putFile, arginfo_smce_core_smoutput_putfile, ZEND_ACC_PUBLIC)
	PHP_ME(Smce_Core_SmOutput, getHeader, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
