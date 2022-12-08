#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "mcu.h"

using namespace std;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef struct _PPSApaParkData
{
    int16_t x;
    int16_t y;
    int16_t angle;
    int16_t phi;
    uint8_t is_key_goal;
    uint8_t gear;
}PPSApaParkData;

typedef struct _PPSApaParkDataMsg
{
    uint16_t number;
    uint16_t id;
    PPSApaParkData data;
}PPSApaParkDataMsg;

void SendApaPPSControl(PPSApaParkDataMsg data, Mcu* mcu_);
void send_pps_control(Mcu* mcu_);