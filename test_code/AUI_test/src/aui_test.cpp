#include "aui_test.h"


/*
* API接口测试
*/

//init()接口测试
TEST_F(ShaderTest_API, shader_api_test_001)
{
    int ret;
    string name = "xxx";
    Shader Shader_test(name);
    ret = Shader_test.init();
    cout << "init ret is" << ret << endl;
    EXPECT_EQ(ret, 1);
}

//get_shader_by_name接口测试
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

//get_shader_by_name接口测试;未初始化init；直接调用get_shader_by_name；预期结果为失败；但运行结果为成功
TEST_F(ShaderTest_API, shader_api_test_003)
{
    int ret;
    string name = "xxx";
    Shader* get_shader = NULL;
    Shader Shader_test(name);

    get_shader = Shader_test.get_shader_by_name(name);
    if(get_shader == NULL) {
        EXPECT_EQ(1, 0);
    }
}