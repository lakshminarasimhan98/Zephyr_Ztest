#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>
#include "i2c_logic.h"

/* Use the DT label for I2C1 */
#define I2C_NODE DT_NODELABEL(i2c1)

#if !DT_NODE_HAS_STATUS(I2C_NODE, okay)
#error "i2c1 is not enabled in the device tree"
#endif

const struct device *i2c_dev = DEVICE_DT_GET(I2C_NODE);

/* Dummy target device address (7-bit) */
uint8_t dev_addr = 0x3C;

int i2c_dev_init(void)
{
    if (!device_is_ready(i2c_dev)) {
        printk("I2C device not ready\n");
        return -1;
    }

    printk("I2C device ready: %s\n", i2c_dev->name);

    return 0;
}

int i2c_dev_write(void)
{

    /* Dummy data to send */
    uint8_t tx_data[] = { 0xA5, 0x5A };

    int ret;

    /* Write 2 bytes to the device */
    ret = i2c_write(i2c_dev, tx_data, sizeof(tx_data), dev_addr);

    if (ret == 0) {
        printk("I2C write successful\n");
    } else {
        printk("I2C write failed: %d\n", ret);
    }


    return ret;
}

int i2c_dev_read(void)
{
    int ret;
    uint8_t rx_data[2];

    /* Try reading 2 bytes from device */
    ret = i2c_read(i2c_dev, rx_data, sizeof(rx_data), dev_addr);
    if (ret == 0) {
        printk("I2C read successful: 0x%02X 0x%02X\n", rx_data[0], rx_data[1]);
    } else {
        printk("I2C read failed: %d\n", ret);
    }

    return ret;

}
