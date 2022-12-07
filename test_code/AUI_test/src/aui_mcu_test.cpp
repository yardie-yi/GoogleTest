#include "aui_mcu_test.h"

/*
* API接口测试
*/

//mcu init() test
TEST_F(McuTest, Mcu_test_001)
{
    bool ret;
    Mcu* mcu = new Mcu(IPC_MCU_DEVICE, DeviceType::IPC);

    unsigned char data[1] = { 0 };
    mcu->send_msg(Mcu::FrameType::CMD, Mcu::MsgType::SHAKE_HAND_AVM, data, 1);

    mcu->get_device()->print_packet(false);
    
    delete mcu;
    EXPECT_EQ(ret, true);
}