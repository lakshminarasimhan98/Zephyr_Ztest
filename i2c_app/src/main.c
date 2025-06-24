#ifndef CONFIG_ZTEST

#include <zephyr/kernel.h>
#include "i2c_logic.h"
//#include <zephyr/sys/printk.h>


int main(void)
{
    int ret;

    ret = i2c_dev_init();

    ret = i2c_dev_write();

    ret = i2c_dev_read();

    return ret;

}

#endif //CONFIG_ZTEST
