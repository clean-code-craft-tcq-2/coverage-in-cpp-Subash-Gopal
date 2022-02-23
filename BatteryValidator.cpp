#include <vector>
#include <algorithm>
#include <map>
#include <assert.h>
#include "BatteryValidator.h"

BreachType BatteryValidator::inferBreach(double inputValue, double lowerLimit, double upperLimit) {
    if (inputValue < lowerLimit) { return TOO_LOW; }
    if (inputValue > upperLimit) { return TOO_HIGH;}
    return NORMAL;
}

BreachType BatteryValidator::classifyTemperatureBreach(int coolingType, double inputValue) {
    if (INVALID == coolingTypeValidator(coolingType)){
        return INVALID;
    }
    else {
        int lowerLimit = limits[coolingType][LOWER_LIMIT_INDEX];
        int upperLimit = limits[coolingType][UPPER_LIMIT_INDEX];
        return inferBreach(inputValue, lowerLimit, upperLimit);
    }
}

int BatteryValidator::coolingTypeValidator(int coolingType) {
    return (NUMBER_OF_COOLINGTYPES > coolingType)? coolingType : INVALID;
}

AlertStatus BatteryValidator::validateBattery() {
    AlertStatus result = ALERTNOTSENT;
    BreachType breachType = classifyTemperatureBreach(getCoolingType(), inputValue);
    result = this->alerterStrategy_->DoAlert(breachType);
    return result;
}
