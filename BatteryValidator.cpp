#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>
#include "BatteryValidator.h"

BreachType BatteryValidator::inferBreach(double inputValue, double lowerLimit, double upperLimit)
{
    if (inputValue < lowerLimit)
    {
        return TOO_LOW;
    }
    if (inputValue > upperLimit)
    {
        return TOO_HIGH;
    }
    return NORMAL;
}

BreachType BatteryValidator::classifyTemperatureBreach(
    int coolingType, double inputValue)
{
    int lowerLimit = limits[coolingType][LOWER_LIMIT_INDEX];
    int upperLimit = limits[coolingType][UPPER_LIMIT_INDEX];
    return inferBreach(inputValue, lowerLimit, upperLimit);
}

int BatteryValidator::coolingTypeValidator(int coolingType)
{
    if (NUMBER_OF_COOLINGTYPES > coolingType)
    {
        return coolingType;
    }
    else
    {
        return INVALID;
    }
}
AlertStatus BatteryValidator::validateBattery()
{
    int currentCoolingType = coolingTypeValidator(getCoolingType());
    AlertStatus result = ALERTNOTSENT;
    if (currentCoolingType == INVALID)
    {
        result = this->alerterStrategy_->DoAlert(INVALID);
    }
    else
    {
        BreachType breachType = classifyTemperatureBreach(currentCoolingType, inputValue);
        result = this->alerterStrategy_->DoAlert(breachType);
    }
    return result;
}
