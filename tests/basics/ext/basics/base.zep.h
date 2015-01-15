
extern zend_class_entry *basics_base_ce;

ZEPHIR_INIT_CLASS(Basics_Base);

PHP_METHOD(Basics_Base, test);

ZEPHIR_INIT_FUNCS(basics_base_method_entry) {
	PHP_ME(Basics_Base, test, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
