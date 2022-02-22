#include "CommonConstants.h"
#pragma once
class AlerterStrategy
{
public:
    virtual ~AlerterStrategy() {}
    virtual AlertStatus DoAlert(BreachType BreachType) const = 0;
    std::map<BreachType, const char *> temperatureBreachMapper{
        {TOO_LOW, "Temperature is too low"},
        {TOO_HIGH, "Temperature is too high"},
        {NORMAL, "Temperature is normal"},
        {INVALID, "Invalid Cooling type"}};
    const unsigned short HEADER = 0xfeed;
    const char *RECEPIENT = "a.b@c.com";
};

class SendAlertToControllerStrategy : public AlerterStrategy
{
public:
    AlertStatus DoAlert(BreachType breachType) const override
    {
        //Alert sent  for all cooling types
        //For invalid cooling type - alerts can be printed or notified based on the requirement
        AlertStatus result = ALERTNOTSENT;
        if (breachType != INVALID)
        {
            printAlert(breachType);
            result = ALERTED;
        }
        return result;
    }

    void printAlert(const BreachType breachType) const
    {
        printf("%x : %x \n", HEADER, breachType);
    }
};

class SendAlertToMailStrategy : public AlerterStrategy
{
public:
    AlertStatus checkBreachAndSendMail(BreachType breachType) const
    {
        //For invalid cooling type - alerts can be printed or notified based on the requirement
        AlertStatus result = ALERTNOTSENT;
        if (breachType == TOO_LOW)
        {           
            result = BREACHALERTED;
        }
        if(breachType == TOO_HIGH)
        {
            result = BREACHALERTED;
        }
        if(result == BREACHALERTED)
        {
            printAlert((temperatureBreachMapper.find(breachType))->second));
        }
        return result;
    }
    AlertStatus DoAlert(BreachType breachType) const override
    {
        return (breachType == NORMAL) ? ALERTNOTREQUIRED : checkBreachAndSendMail(breachType);
    }
    void printAlert(const std::string message) const
    {
        std::cout << "To: " << RECEPIENT << "\n";
        std::cout << "Hi, " << message << "\n";
    }
};
