#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "mcu.h"
#include <pugixml/pugixml.hpp>
#include <pugixml/pugiconfig.hpp>

using namespace std;
using namespace pugi;

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

/*
enum class DeviceType
{
    UART,
    IPC,
};
*/
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

class Mcu_control {
public:
    Mcu_control();

};

struct Size {
    int width;
    int height;
};

Size *get_size_with_datamng(string cfg);