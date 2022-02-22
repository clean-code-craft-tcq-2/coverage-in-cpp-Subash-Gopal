#include "CommonConstants.h"
#pragma once
class AlerterStrategy
{
public:
    virtual ~AlerterStrategy() {}

    virtual void DoAlert(BreachType BreachType) const = 0;
};

class SendAlertToControllerStrategy : public AlerterStrategy
{
public:
    void DoAlert(BreachType breachType) const override
    {
        //Alerts for all cooling types
        if (breachType != INVALID)
        {
            printf("%x : %x \n", HEADER, breachType);
        }
        //Incase invalid cooling type - alerts can be printed or notified
    }
};

class SendAlertToMailStrategy : public AlerterStrategy
{
    void DoAlert(BreachType breachType) const override
    {
        if ((breachType == TOO_LOW) || (breachType == TOO_HIGH))
        {
            std::cout << "To: " << RECEPIENT << "\n";
            std::cout << "Hi," << (temperatureBreachMapper.find(breachType))->second << "\n";
        }
        //Incase invalid cooling type - alerts can be printed or notified
    }
};