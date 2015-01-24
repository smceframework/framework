
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


/**
 *
 * @author Samed Ceylan
 * @link http://www.samedceylan.com/
 * @copyright 2015 SmceFramework
 * @github https://github.com/imadige/SMCEframework-MVC
 */
ZEPHIR_INIT_CLASS(Smce_Core_SmException) {

	ZEPHIR_REGISTER_CLASS_EX(Smce\\Core, SmException, smce, core_smexception, zend_exception_get_default(TSRMLS_C), smce_core_smexception_method_entry, 0);

	return SUCCESS;

}

/**
 *
 * @return name
 *
 */
PHP_METHOD(Smce_Core_SmException, getName) {


	RETURN_STRING("Core/SmException", 1);

}

