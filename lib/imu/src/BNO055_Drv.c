#include "BNO055_Drv.h"
#include "i2c_driver.h"

bool BNO055_Begin(void) // set it to OPERATION_MODE_NDOF
{
    const struct device *i2c_dev = I2C_Init();

    if(!i2c_dev)
    {
        return false;
    }
    // Command to read the BNO055 chip ID
    uint8_t cmd[2] = {0x00, 0x00}; // Register address for chip ID

    struct i2c_msg msgs[2];

    // First message: Write the register address to select the chip ID register
    msgs[0].buf = cmd;
    msgs[0].len = sizeof(cmd);
    msgs[0].flags = I2C_MSG_WRITE | I2C_MSG_STOP;

    // Second message: Read the chip ID
    uint8_t chip_id;
    msgs[1].buf = &chip_id;
    msgs[1].len = sizeof(chip_id);
    msgs[1].flags = I2C_MSG_READ | I2C_MSG_STOP;
    
    int ret = i2c_transfer(i2c_dev, &msgs[0], 1, BNO055_ADDRESS_A);
    if (ret)
    {
        printk("I2C transfer error: %d", ret);
        return false;
    }
    ret = i2c_transfer(i2c_dev, &msgs[1], 1, BNO055_ADDRESS_A);
    if (ret)
    {
        printk("I2C read error: %d", ret);
        return false;
    }
}

void BNO055_SetMode(BNO055_opmode_t mode)
{
    
}

BNO055_opmode_t getMode()
{

}

void BNO055_SetAxisRemap(BNO055_axis_remap_config_t remapcode)
{

}

void BNO055_SetAxisSign(BNO055_axis_remap_sign_t remapsign)
{

}

void BNO055_GetRevInfo(BNO055_rev_info_t *info)
{

}

void BNO055_GetExtCrystalUse(bool usextal)
{

}

void BNO055_GgetSystemStatus(uint8_t *system_status, uint8_t *self_test_result,
                    uint8_t *system_error)
{

}

void BNO055_GetCalibration(uint8_t *system, uint8_t *gyro, uint8_t *accel,
                    uint8_t *mag)
{

}