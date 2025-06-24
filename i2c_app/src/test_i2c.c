#include <zephyr/ztest.h>
#include "i2c_logic.h"

ZTEST_SUITE(i2c_tests, NULL, NULL, NULL, NULL, NULL);

ZTEST(i2c_tests, test_i2c_dev_init)
{
    zassert_equal(i2c_dev_init(), 0, "Failed to initialize I2C");
}

ZTEST(i2c_tests, test_i2c_dev_write)
{
    zassert_equal(i2c_dev_write(), 0, "Failed to perform I2C write");
}

ZTEST(i2c_tests, test_i2c_dev_read)
{
    zassert_equal(i2c_dev_read(), 0, "Failed to perform I2C read");
}

ZTEST(i2c_tests, test_no_i2c_dev_init)
{
    zassert_equal(i2c_dev_init(), -1, "Failed to initialize I2C device");
}
