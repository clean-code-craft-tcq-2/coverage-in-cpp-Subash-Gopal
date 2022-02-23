#pragma once

typedef enum {
    NORMAL,
    TOO_LOW,
    TOO_HIGH,
    INVALID
} BreachType;

typedef enum {
    ALERTNOTREQUIRED,
    ALERTNOTSENT,
    BREACHALERTED,
    ALERTED
} AlertStatus;

const int PASSIVE_COOLING = 0;
const int HI_ACTIVE_COOLING = 1;
const int MED_ACTIVE_COOLING = 2;

const int NUMBER_OF_COOLINGTYPES = 3;
const int NUMBER_OF_TEMPLIMITS = 2;
const int LOWER_LIMIT_INDEX = 0;
const int UPPER_LIMIT_INDEX = 1;
const int limits[NUMBER_OF_COOLINGTYPES][NUMBER_OF_TEMPLIMITS] = {{0, 35},
                                                                  {0, 45},
                                                                  {0, 40}};
