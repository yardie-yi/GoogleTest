#include "aui_mcu_test.h"
#include "common.h"
/*
* API接口测试
*/

//mcu init() test
TEST_F(McuTest, Mcu_test_001)
{
    bool ret = true;

    char s[6] = "J721E";

    ret = rpmsg_char_init(s);
    cout << "ret::" << ret << endl;

    TouchScreen* touch_screen = new TouchScreen(4096, 4096, 1920, 1080, TOUCH_DEVICE_NAME);
    Mcu* mcu = new Mcu(IPC_MCU_DEVICE, DeviceType::IPC);

    mcu->get_device()->print_packet(true);
    mcu->print_msg(Mcu::MsgType::SHAKE_HAND_AVM, true);
    mcu->print_msg(Mcu::MsgType::SHAKE_HAND_MCU, true);
    mcu->print_msg(Mcu::MsgType::APA_CONTROL_AVM, true);

    unsigned char data[1] = { 0 };
    mcu->send_msg(Mcu::FrameType::CMD, Mcu::MsgType::SHAKE_HAND_AVM, data, 1);


    sleep(10);

    //uint8_t msg_data[3] = { 0 };
    //msg_data[0] = 0x02;
    //mcu->send_msg(Mcu::FrameType::MSG, Mcu::MsgType::APA_CONTROL_MCU, msg_data, sizeof(msg_data));
    
    sleep(20);

    send_pps_control(mcu);


    sleep(20);

    //delete mcu;
    EXPECT_EQ(ret, true);
}