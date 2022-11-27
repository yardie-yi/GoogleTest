#include "ts_test.h"
#include <time.h>
/*
 *对算法源码ApaInfoProcessIF.h中ApaInfoProcessIF类方法InputAIJacintoParkSpaceVec进行测试.
 *bool InputAIJacintoParkSpaceVec(std::vector<float>& parkSpaceDetect, CAM_DIRECTION camDir, int armTime);
 *vector<float>，模型数据，长度为16
 *CAM_DIRECTION，为摄像头编号，范围为0~3
 *int32_t，时间戳，单位为ms
*/

//该例子仅单纯调用算法接口，没有按照正常流程去调用。该接口必定返回失败。

//测试用例1；用例名称为testcase1
TEST_F(TsTest, testcase1)
{
    bool result;
    time_t rawtime;
    struct tm *now_time;
    ApaInfoProcessIF apa_info;
    vector<float>parkSpaceDetect(16, 0.01);

    time(&rawtime);
    now_time = localtime(&rawtime);

    result = apa_info.InputAIJacintoParkSpaceVec(parkSpaceDetect, CAM_DIRECTION_LEFT, now_time->tm_sec);
    EXPECT_EQ(result, 1);
}
