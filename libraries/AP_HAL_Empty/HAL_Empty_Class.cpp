
#include <AP_HAL.h>

#include "HAL_Empty_Class.h"
#include "AP_HAL_Empty_Private.h"

using namespace Empty;

static EmptyUARTDriver uartADriver;
static EmptyUARTDriver uartBDriver;
static EmptyUARTDriver uartCDriver;
static EmptyI2CDriver  i2cDriver;
static EmptySPIDeviceManager spiDeviceManager;
static EmptyAnalogIn analogIn;
static EmptyStorage storageDriver;
static EmptyConsoleDriver consoleDriver(&uartADriver);
static EmptyGPIO gpioDriver;
static EmptyRCInput rcinDriver;
static EmptyRCOutput rcoutDriver;
static EmptyScheduler schedulerInstance;

HAL_Empty::HAL_Empty() :
    AP_HAL::HAL(
        &uartADriver,
        &uartBDriver,
        &uartCDriver,
        &i2cDriver,
        &spiDeviceManager,
        &analogIn,
        &storageDriver,
        &consoleDriver,
        &gpioDriver,
        &rcinDriver,
        &rcoutDriver,
        &schedulerInstance),
    _member(new EmptyPrivateMember(123))
{}

void HAL_Empty::init(int argc,char* const argv[]) const {
    /* initialize all drivers and private members here.
     * up to the programmer to do this in the correct order.
     * Scheduler should likely come first. */
    scheduler->init(NULL);
    uartA->begin(115200);
    _member->init();
}

const HAL_Empty AP_HAL_Empty;
