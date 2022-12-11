#include "common.h"

void _copy_bytes(uint8_t* src, uint8_t* dst, int length, bool big_endian)
{
    if (big_endian)
    {
        memcpy(dst, src, length);
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            dst[i] = src[length - i - 1];
        }
    }
}

void short_2_byte(uint16_t value, uint8_t* bytes, bool big_endian)
{
    uint8_t* data = (uint8_t*)(&value);
    _copy_bytes(data, bytes, 2, big_endian);
}

void SendApaPPSControl(PPSApaParkDataMsg data, Mcu* mcu_)
{
    int size = sizeof(PPSApaParkDataMsg);
    uint8_t* msg_data = new uint8_t[size];
    int index = 0;

    short_2_byte(data.number, &msg_data[index], false);
    index += 2;

    short_2_byte(data.id, &msg_data[index], false);
    index += 2;

    short_2_byte((uint16_t)data.data.x, &msg_data[index], false);
    index += 2;

    short_2_byte((uint16_t)data.data.y, &msg_data[index], false);
    index += 2;

    short_2_byte((uint16_t)data.data.angle, &msg_data[index], false);
    index += 2;

    short_2_byte((uint16_t)data.data.phi, &msg_data[index], false);
    index += 2;

    msg_data[index] = data.data.is_key_goal;
    index += 1;

    msg_data[index] = data.data.gear;
    index += 1;

    mcu_->send_msg(Mcu::FrameType::MSG, Mcu::MsgType::APA_PPS_CONTROL, msg_data, size);
    delete []msg_data;
    msg_data = NULL;
}

void send_pps_control(Mcu* mcu_)
{
    for (int i = 0; i < 300; i++)
    {
        PPSApaParkDataMsg dataMsg;
        dataMsg.number = 300;
        dataMsg.id = i;
        dataMsg.data.angle = 10;
        dataMsg.data.gear = 1;
        dataMsg.data.is_key_goal = true;
        dataMsg.data.phi = 0x3564;
        dataMsg.data.x = 0x2244;
        dataMsg.data.y = 0x8542;

        SendApaPPSControl(dataMsg, mcu_);
    }
}

Size *get_size_with_datamng(string cfg)
{
    Size *size;
    xml_document doc;
    xml_parse_result result = doc.load_file(cfg.data());
    if (result.status == status_ok)
    {
        const char* str = NULL;
        xml_node rootNode = doc.child("aiui");
        if (rootNode)
        {
            str = rootNode.attribute("width").value();
            if (str != NULL && strlen(str) > 0)
            {
                size->width = atoi(str);
            }
            str = rootNode.attribute("height").value();
            if (str != NULL && strlen(str) > 0)
            {
                size->height = atoi(str);
            }
        }
    }
    return size;
}