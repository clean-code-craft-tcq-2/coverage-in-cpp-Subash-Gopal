#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "BatteryValidator.h"

TEST_CASE("Tests classifyTemperatureBreach with PASSIVE_COOLING type")
{
   BatteryValidator *batteryValidatortests = new BatteryValidator(0, PASSIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(PASSIVE_COOLING, 0) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(PASSIVE_COOLING, 35) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(PASSIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
};
TEST_CASE("Tests classifyTemperatureBreach with HI_ACTIVE_COOLING type")
{
   BatteryValidator *batteryValidatortests = new BatteryValidator(0, HI_ACTIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(HI_ACTIVE_COOLING, 0) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(HI_ACTIVE_COOLING, 45) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(HI_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
};
TEST_CASE("Tests classifyTemperatureBreach with MED_ACTIVE_COOLING type")
{
   BatteryValidator *batteryValidatortests = new BatteryValidator(0, MED_ACTIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 0) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 40) == NORMAL);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == TOO_LOW);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) == TOO_HIGH);
};

TEST_CASE("Tests classifyTemperatureBreach with Invalid Cooling Types")
{
   BatteryValidator *batteryValidatortests = new BatteryValidator(0, 3 , new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 0) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 40) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) == INVALID);
  
  batteryValidatortests->setCoolingType(100);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 0) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 20) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, -1) == INVALID);
  REQUIRE(batteryValidatortests->classifyTemperatureBreach(MED_ACTIVE_COOLING, 34) == INVALID);
};



TEST_CASE("infers the breach according to limits for passive cooling type")
{
  BatteryValidator *batteryValidatortest1 = new BatteryValidator(0, PASSIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest1->setInputValue(35);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest1->setInputValue(-1);
  REQUIRE(batteryValidatortest1->validateBattery() == BREACHALERTED);

  batteryValidatortest1->setInputValue(36);
  REQUIRE(batteryValidatortest1->validateBattery() == BREACHALERTED);

  batteryValidatortest1->setStrategy(new SendAlertToControllerStrategy);
  
  batteryValidatortest1->setInputValue(0);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTED);

  batteryValidatortest1->setInputValue(35);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTED);

  batteryValidatortest1->setInputValue(-1);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTED);

  batteryValidatortest1->setInputValue(36);
  REQUIRE(batteryValidatortest1->validateBattery() == ALERTED);

  delete batteryValidatortest1;
};
TEST_CASE("infers the breach according to limits for HI_ACTIVE_COOLING")
{
  BatteryValidator *batteryValidatortest2 = new BatteryValidator(0, HI_ACTIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest2->setInputValue(45);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest2->setInputValue(-1);
  REQUIRE(batteryValidatortest2->validateBattery() == BREACHALERTED);

  batteryValidatortest2->setInputValue(46);
  REQUIRE(batteryValidatortest2->validateBattery() == BREACHALERTED);

  batteryValidatortest2->setStrategy(new SendAlertToControllerStrategy);
  batteryValidatortest2->setInputValue(0);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTED);

  batteryValidatortest2->setInputValue(45);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTED);

  batteryValidatortest2->setInputValue(-1);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTED);

  batteryValidatortest2->setInputValue(46);
  REQUIRE(batteryValidatortest2->validateBattery() == ALERTED);

  delete batteryValidatortest2;
};
TEST_CASE("infers the breach according to limits for MED_ACTIVE_COOLING")
{
  BatteryValidator *batteryValidatortest3 = new BatteryValidator(0, MED_ACTIVE_COOLING, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest3->setInputValue(40);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTNOTREQUIRED);

  batteryValidatortest3->setInputValue(-1);
  REQUIRE(batteryValidatortest3->validateBattery() == BREACHALERTED);

  batteryValidatortest3->setInputValue(41);
  REQUIRE(batteryValidatortest3->validateBattery() == BREACHALERTED);

  batteryValidatortest3->setStrategy(new SendAlertToControllerStrategy);
  batteryValidatortest3->setInputValue(0);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTED);

  batteryValidatortest3->setInputValue(40);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTED);

  batteryValidatortest3->setInputValue(-1);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTED);

  batteryValidatortest3->setInputValue(41);
  REQUIRE(batteryValidatortest3->validateBattery() == ALERTED);

  delete batteryValidatortest3;
};
TEST_CASE("Test for invalid cooling type")
{
  BatteryValidator *batteryValidatortest4 = new BatteryValidator(-4, 5, new SendAlertToMailStrategy);
  REQUIRE(batteryValidatortest4->validateBattery() == ALERTNOTSENT);

  batteryValidatortest4->setStrategy(new SendAlertToControllerStrategy);
  REQUIRE(batteryValidatortest4->validateBattery() == ALERTNOTSENT);

  batteryValidatortest4->setStrategy(new SendAlertToControllerStrategy);
  REQUIRE(batteryValidatortest4->validateBattery() == ALERTNOTSENT);

  delete batteryValidatortest4;
};

//
