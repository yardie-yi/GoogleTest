#include "ts_test.h"

/*
 *对算法源码ApaInfoProcessIF.h中ApaInfoProcessIF类方法InputAIJacintoParkSpaceVec进行测试.
 *bool InputAIJacintoParkSpaceVec(std::vector<float>& parkSpaceDetect, CAM_DIRECTION camDir, int armTime);
 *vector<float>，模型数据，长度为16
 *CAM_DIRECTION，为摄像头编号，范围为0~3
 *int32_t，时间戳，单位为ms
*/

//测试用例1；用例名称为testcase1
TEST_F(Test, testcase1)
{
    ApaInfoProcessIF apa_info;
	//EXPECT_EQ(a, b)：检查a与b是否相等。
    EXPECT_EQ(num.is_eq_num(5), 1);
}

//测试用例2；用例名称为testcase2
TEST_F(Test, testcase2)
{
    Value num(5);
    EXPECT_EQ(num.is_eq_num(7), 0);
}

TEST_F(Test, testcase3)
{
    Value num(7);
    EXPECT_EQ(num.is_eq_num(1), -1);
}

TEST_F(Test, testcase4)
{
    Value num(7);
    EXPECT_EQ(num.is_eq_num(5), 1);
}
