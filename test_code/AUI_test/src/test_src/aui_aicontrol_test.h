#ifndef _AUI_AICONTROL_TEST_H_
#define _AUI_AICONTROL_TEST_H_

#include <gtest/gtest.h>
#include "aicontrol.h"
#include "common.h"

using namespace std;

//TestCase级别事件
//SetUp()在每个TestCase执行之前会执行，而TearDown()在每个TestCase执行之后会进行
class AiControlTest_API : public ::testing::Test {
    public:
        //在每个用例执行之前都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void SetUp() override
        {
            cout << "------------------" << endl;
            cout << "SetUp()" << endl; 
        }

        //在每个用例执行之后都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void TearDown() override
        {
            cout << "TearDown()" << endl; 
            cout << "------------------" << endl;
        }
};

//TestCase级别事件
//SetUp()在每个TestCase执行之前会执行，而TearDown()在每个TestCase执行之后会进行
class AiControlAndDatamng : public ::testing::Test {
    public:
        //在每个用例执行之前都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void SetUp() override
        {
            cout << "------------------" << endl;
            cout << "SetUp()" << endl; 
        }

        //在每个用例执行之后都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void TearDown() override
        {
            cout << "TearDown()" << endl; 
            cout << "------------------" << endl;
        }
};

//TestCase级别事件
//SetUp()在每个TestCase执行之前会执行，而TearDown()在每个TestCase执行之后会进行
class DatamngTest : public ::testing::Test {
    public:
        //在每个用例执行之前都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void SetUp() override
        {
            cout << "------------------" << endl;
            cout << "SetUp()" << endl; 
        }

        //在每个用例执行之后都会执行此处的代码，可将每个用例重复性的代码放于此方法
        void TearDown() override
        {
            cout << "TearDown()" << endl; 
            cout << "------------------" << endl;
        }
};
#endif