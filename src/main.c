#include <zephyr.h>
#include <kernel.h>
#include "i2c_driver.h"
#include "BNO055_Drv.h"


void main(void)
{
    // I2C_Init();
    BNO055_Begin();

    while (1)
    {
        /* code */
    }
    
}
// #include <zephyr.h>
// #include <device.h>
// #include <drivers/i2c.h>
// #include <drivers/gpio.h>
// #include <logging/log.h>


// LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

// // #define I2C_DEV DT_LABEL(DT_INST(1, st_stm32_i2c))
// struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});

// void main(void)
// {
//     const struct device *i2c_dev;

//     i2c_dev = device_get_binding("I2C_2");

//     if (!i2c_dev)
//     {
//         printk("I2C device not found: %s", "I2C_2");
//         return;
//     }

//     printk("I2C device found: %s", "I2C_2");

// // Command to read the BNO055 chip ID
//     uint8_t cmd[2] = {0x00, 0x00}; // Register address for chip ID

//     struct i2c_msg msgs[2];

//     // First message: Write the register address to select the chip ID register
//     msgs[0].buf = cmd;
//     msgs[0].len = sizeof(cmd);
//     msgs[0].flags = I2C_MSG_WRITE | I2C_MSG_STOP;

//     // Second message: Read the chip ID
//     uint8_t chip_id;
//     msgs[1].buf = &chip_id;
//     msgs[1].len = sizeof(chip_id);
//     msgs[1].flags = I2C_MSG_READ | I2C_MSG_STOP;
    
//     int ret = i2c_transfer(i2c_dev, &msgs[0], 1, BNO055_ADDRESS_A);
//     if (ret)
//     {
//         printk("I2C transfer error: %d", ret);
//     }
//     ret = i2c_transfer(i2c_dev, &msgs[1], 1, BNO055_ADDRESS_A);
//     if (ret)
//     {
//         printk("I2C read error: %d", ret);
//         return;
//     }

//     printk("BNO055 Chip ID: 0x%x", chip_id);

//     while (1)
//     {
//         k_sleep(K_SECONDS(1));
//     }
// }
