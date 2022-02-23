#include <iostream>
#include <string>
#include "AlerterStrategy.h"
class BatteryValidator
{

private:
    double inputValue;
    int coolingType;
    AlerterStrategy *alerterStrategy_;
    BreachType inferBreach(double inputValue, double lowerLimit, double upperLimit);
    int coolingTypeValidator(int coolingType);

public:
    BatteryValidator(double inputValue, int coolingType, AlerterStrategy *alerterStrategy = nullptr) : inputValue(inputValue), coolingType(coolingType), alerterStrategy_(alerterStrategy)
    {
    }
    ~BatteryValidator()
    {
        delete this->alerterStrategy_;
    }
    void setCoolingType(int coolingType) { this->coolingType = coolingType; }
    int getCoolingType() { return coolingType; }
    void setInputValue(int inputValue) { this->inputValue = inputValue; }

    void setStrategy(AlerterStrategy *alerterStrategy)
    {
        delete this->alerterStrategy_;
        this->alerterStrategy_ = alerterStrategy;
    }

   
    BreachType classifyTemperatureBreach(int coolingType, double inputValue);
    AlertStatus validateBattery();
};
