#include "aui_shader_test.h"


/*
* API接口测试
*/

//Shader init()接口测试
TEST_F(ShaderTest_API, shader_api_test_001)
{
    int ret;
    string name = "xxx";
    Shader Shader_test(name);
    ret = Shader_test.init();
    cout << "init ret is" << ret << endl;
    EXPECT_EQ(ret, 1);
}

//Shader get_shader_by_name接口测试
TEST_F(ShaderTest_API, shader_api_test_002)
{
    int ret;
    string name = "xxx";
    Shader* get_shader = NULL;
    Shader Shader_test(name);
    ret = Shader_test.init();
    EXPECT_EQ(ret, 1);

    get_shader = Shader_test.get_shader_by_name(name);
    if(get_shader == NULL) {
        EXPECT_EQ(1, 0);
    }
}

//Shader get_shader_by_name接口测试;未初始化init；直接调用get_shader_by_name；预期结果为失败；但运行结果为成功
TEST_F(ShaderTest_API, shader_api_test_003)
{
    int ret;
    bool result = true;
    string name = "xxx";
    Shader* get_shader = NULL;
    Shader Shader_test(name);

    get_shader = Shader_test.get_shader_by_name(name);
    if(get_shader == NULL) {
        result = true;
        EXPECT_EQ(result, true);
    } else {
        result = false;
        EXPECT_EQ(result, true);
    }
}

//Shader init()接口压力测试
TEST_F(ShaderTest_API, shader_api_test_004)
{
    int ret;
    bool result = true;
    int error_num = 0;
    string name = "xxx";
    Shader Shader_test(name);
    for (int i = 0; i < 1000; i++) {
        ret = Shader_test.init();
        if (ret != 1) {
            error_num++;
        }
    }

    if (error_num > 3) {
        cout << "error_num over 3 times" << endl;
        result = false;
    }
    EXPECT_EQ(result, true);
}

//Shader get_shader_by_name接口压力测试
TEST_F(ShaderTest_API, shader_api_test_005)
{
    int ret;
    bool result = true;
    int error_num = 0;
    string name = "xxx";
    Shader* get_shader = NULL;
    Shader Shader_test(name);
    ret = Shader_test.init();
    EXPECT_EQ(ret, 1);

    for (int i = 0; i < 1000; i++) {
        get_shader = Shader_test.get_shader_by_name(name);
        if (get_shader == NULL) {
            error_num ++;
        }
    }

    if (error_num > 3) {
        cout << "error_num over 3 times" << endl;
        result = false;
    }
    EXPECT_EQ(result, true);
}