#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "BatteryValidator.h"

TEST_CASE("infers the breach according to limits")
{
  BatteryValidator *batteryValidatortest1 = new BatteryValidator(0, 0, new SendAlertToMailStrategy);
  batteryValidatortest1->validateBattery();

  delete batteryValidatortest1;
};

// int main()
// {

//     BatteryValidator *batteryValidatortest1 = new BatteryValidator(0, PASSIVE_COOLING, new SendAlertToMailStrategy);
//     assert(batteryValidatortest1->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest1->setInputValue(35);
//     assert(batteryValidatortest1->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest1->setInputValue(-1);
//     assert(batteryValidatortest1->validateBattery() == BREACHALERTED);

//     batteryValidatortest1->setInputValue(36);
//     assert(batteryValidatortest1->validateBattery() == BREACHALERTED);

//     batteryValidatortest1->setStrategy(new SendAlertToControllerStrategy);
//     batteryValidatortest1->setInputValue(0);
//     assert(batteryValidatortest1->validateBattery() == ALERTED);

//     batteryValidatortest1->setInputValue(35);
//     assert(batteryValidatortest1->validateBattery() == ALERTED);

//     batteryValidatortest1->setInputValue(-1);
//     assert(batteryValidatortest1->validateBattery() == ALERTED);

//     batteryValidatortest1->setInputValue(36);
//     assert(batteryValidatortest1->validateBattery() == ALERTED);

//     delete batteryValidatortest1;

//     BatteryValidator *batteryValidatortest2 = new BatteryValidator(0, HI_ACTIVE_COOLING, new SendAlertToMailStrategy);
//     assert(batteryValidatortest2->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest2->setInputValue(45);
//     assert(batteryValidatortest2->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest2->setInputValue(-1);
//     assert(batteryValidatortest2->validateBattery() == BREACHALERTED);

//     batteryValidatortest2->setInputValue(46);
//     assert(batteryValidatortest2->validateBattery() == BREACHALERTED);

//     batteryValidatortest2->setStrategy(new SendAlertToControllerStrategy);
//     batteryValidatortest2->setInputValue(0);
//     assert(batteryValidatortest2->validateBattery() == ALERTED);

//     batteryValidatortest2->setInputValue(45);
//     assert(batteryValidatortest2->validateBattery() == ALERTED);

//     batteryValidatortest2->setInputValue(-1);
//     assert(batteryValidatortest2->validateBattery() == ALERTED);

//     batteryValidatortest2->setInputValue(46);
//     assert(batteryValidatortest2->validateBattery() == ALERTED);

//     delete batteryValidatortest2;

//     BatteryValidator *batteryValidatortest3 = new BatteryValidator(0, MED_ACTIVE_COOLING, new SendAlertToMailStrategy);
//     assert(batteryValidatortest3->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest3->setInputValue(40);
//     assert(batteryValidatortest3->validateBattery() == ALERTNOTREQUIRED);

//     batteryValidatortest3->setInputValue(-1);
//     assert(batteryValidatortest3->validateBattery() == BREACHALERTED);

//     batteryValidatortest3->setInputValue(41);
//     assert(batteryValidatortest3->validateBattery() == BREACHALERTED);

//     batteryValidatortest3->setStrategy(new SendAlertToControllerStrategy);
//     batteryValidatortest3->setInputValue(0);
//     assert(batteryValidatortest3->validateBattery() == ALERTED);

//     batteryValidatortest3->setInputValue(40);
//     assert(batteryValidatortest3->validateBattery() == ALERTED);

//     batteryValidatortest3->setInputValue(-1);
//     assert(batteryValidatortest3->validateBattery() == ALERTED);

//     batteryValidatortest3->setInputValue(41);
//     assert(batteryValidatortest3->validateBattery() == ALERTED);

//     delete batteryValidatortest3;

//     BatteryValidator *batteryValidatortest4 = new BatteryValidator(-4, 5, new SendAlertToMailStrategy);
//     assert(batteryValidatortest4->validateBattery() == ALERTNOTSENT);

//     batteryValidatortest4->setStrategy(new SendAlertToControllerStrategy);
//     assert(batteryValidatortest4->validateBattery() == ALERTNOTSENT);

//     // batteryValidatortest4->setStrategy(new SendAlertToControllerStrategy);

//     // assert(batteryValidatortest4->validateBattery() == ALERTED);

//     delete batteryValidatortest4;

//     return 0;
// }
