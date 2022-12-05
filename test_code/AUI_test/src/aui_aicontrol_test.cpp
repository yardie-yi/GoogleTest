#include "aui_aicontrol_test.h"

/*
* API接口测试
*/

//AiControl init() test
TEST_F(AiControlTest_API, AiControl_api_test_001)
{
    bool ret;
    ret = AiControl::init();
    EXPECT_EQ(ret, true);
}

//AiControl get_main_form() 容错测试
//未初始化init();直接调用get_main_form
TEST_F(AiControlTest_API, AiControl_api_test_002)
{
    bool result = true;

    AiControl* form = AiControl::get_main_form();
    if(form == NULL) {
        result = false;
        EXPECT_EQ(result, true);
    }

    EXPECT_EQ(result, true);
}

//AiControl set_size() get_size() test
TEST_F(AiControlTest_API, AiControl_api_test_003)
{
    bool ret;
    bool result;

    cout << "init AiControl; set size.width and size.height equal 0" << endl;
    ret = AiControl::init();
    EXPECT_EQ(ret, true);

    AiControl* form = AiControl::get_main_form();
    AiSize size;
    size = form->get_size();
    if ((size.width != 0) || (size.height != 0)) {
        cout << "get error size" << endl;
        result = false;
        EXPECT_EQ(result, true);
    }

    form->set_size(1920, 1080);
    size = form->get_size();
    if ((size.width != 1920) || (size.height != 1080)) {
        cout << "get error size" << endl;
        result = false;
        EXPECT_EQ(result, true);
    }
}
