
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/variables.h"


ZEPHIR_INIT_CLASS(Basics_Base) {

	ZEPHIR_REGISTER_CLASS(Basics, Base, basics, base, basics_base_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Basics_Base, test) {

	zval *testArray = NULL, *_0 = NULL, *_1, *_2;
	int i = 0, arrayLength = 0;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(testArray);
	array_init(testArray);

	ZEPHIR_INIT_NVAR(testArray);
	array_init_size(testArray, 8);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "Hello Universe !", 1);
	zephir_array_fast_append(testArray, _0);
	zephir_array_fast_append(testArray, ZEPHIR_GLOBAL(global_true));
	zephir_array_fast_append(testArray, ZEPHIR_GLOBAL(global_false));
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_LONG(_0, 86);
	zephir_array_fast_append(testArray, _0);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_DOUBLE(_0, 12.22);
	zephir_array_fast_append(testArray, _0);
	zephir_array_fast_append(testArray, ZEPHIR_GLOBAL(global_null));
	arrayLength = zephir_fast_count_int(testArray TSRMLS_CC);
	while (1) {
		if (!(i < arrayLength)) {
			break;
		}
		php_printf("%s", "typeof testArray[");
		php_printf("%d", i);
		php_printf("%s", "] : ");
		ZEPHIR_INIT_NVAR(_0);
		zephir_array_fetch_long(&_1, testArray, i, PH_NOISY | PH_READONLY, "basics/base.zep", 15 TSRMLS_CC);
		zephir_gettype(_0, _1 TSRMLS_CC);
		zend_print_zval(_0, 0);
		php_printf("%s", "<br />");
		zephir_array_fetch_long(&_2, testArray, i, PH_NOISY | PH_READONLY, "basics/base.zep", 17 TSRMLS_CC);
		zephir_var_dump(&_2 TSRMLS_CC);
		php_printf("%s", "<br />");
		php_printf("%s", "<br />");
		i++;
	}
	RETURN_CCTOR(testArray);

}

