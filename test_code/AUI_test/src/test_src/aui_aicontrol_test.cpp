#include "aui_aicontrol_test.h"

//AiControl init() test
TEST_F(AiControlTest_API, AiControl_api_test_001)
{
    bool ret;
    ret = AiControl::init();
    EXPECT_EQ(ret, true);
}

//AiControl init() stress test
TEST_F(AiControlTest_API, AiControl_api_test_002)
{
    bool ret = true;
    int error_num = 0;
    for (int i = 0; i < 1000; i++) {
        ret = AiControl::init();
        if (ret == false) {
            error_num++;
        }
    }

    if (error_num > 3) {
        cout << "error_num over 3 times" << endl;
        ret = false;
    }
    EXPECT_EQ(ret, true);
}

//AiControl get_main_form() 测试
TEST_F(AiControlTest_API, AiControl_api_test_003)
{
    bool result = true;

    AiControl* form = AiControl::get_main_form();
    if(form == NULL) {
        result = false;
        EXPECT_EQ(result, true);
    }

    EXPECT_EQ(result, true);
}

//AiControl get_main_form() 压力测试
TEST_F(AiControlTest_API, AiControl_api_test_004)
{
    bool result = true;
    AiControl* form = NULL;
    int error_num = 0;

    for (int i = 0; i < 1000; i++) {
        form = AiControl::get_main_form();
        if(form == NULL) {
            error_num++;
        }       
    }

    if(error_num  > 3) {
        cout << "error_num over 3 times" << endl;
        result = false;
    }

    EXPECT_EQ(result, true);
}

//AiControl set_size() get_size() test
TEST_F(AiControlTest_API, AiControl_api_test_005)
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

//AiControl datamng module test
TEST_F(AiControlAndDatamng, AiControlAndDatamng_test_001)
{
    bool ret;
    bool result;
    Size *get_size;

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

    get_size = get_size_with_datamng("/app/config/aiui_cfg.xml");
    EXPECT_EQ(get_size->width, 1920);
    EXPECT_EQ(get_size->height, 1080);

    form->set_size(get_size->width, get_size->height);
    size = form->get_size();
    if ((size.width != get_size->width) || (size.height != get_size->height)) {
        cout << "get error size" << endl;
        result = false;
        EXPECT_EQ(result, true);
    }
}

//datamng module test & xml loda_file
TEST_F(DatamngTest, DatamngTest_001)
{
    bool ret = true;
    string file = "/app/config/aiui_cfg.xml";
    xml_document doc;
    xml_parse_result result = doc.load_file(file.data());
    if (result.status == status_ok) {
        ret = true;
    } else {
        ret = false;
    }
    EXPECT_EQ(ret, true);
}

//datamng module test & xml loda_file
TEST_F(DatamngTest, DatamngTest_002)
{
    bool ret = true;
    string file = "no_exit.xml";
    xml_document doc;
    xml_parse_result result = doc.load_file(file.data());
    if (result.status == status_file_not_found) {
        ret = true;
    } else {
        ret = false;
    }
    EXPECT_EQ(ret, true);
}

//datamng module test & xml loda_file
TEST_F(DatamngTest, DatamngTest_003)
{
    bool ret = true;
    string file = "";
    xml_document doc;
    xml_parse_result result = doc.load_file(file.data());
    if (result.status == status_file_not_found) {
        ret = true;
    } else {
        ret = false;
    }
    EXPECT_EQ(ret, true);
}

//正常的测试需要构造doc.load_file(cfg.data())返回所有状态的场景