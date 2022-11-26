#include <gtest/gtest.h>

int main(int argc, char **argv)
{
	//将测试结果在可执行文件路径生成Test_result.xml文件
    ::testing::GTEST_FLAG(output) = "xml:Test_tauristarPlatform_result.xml";
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); //运行测试用例
}
