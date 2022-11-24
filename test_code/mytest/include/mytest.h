#ifndef _MYTEST_H_
#define _MYTEST_H_

#include "gtest/gtest.h"

using namespace std;

//TestCase级别事件
//SetUp()在每个TestCase执行之前会执行，而TearDown()在每个TestCase执行之后会进行
class Test:public ::testing::Test {
    public:
        virtual void SetUp();//在每个用例执行之前都会执行此处的代码，可将每个用例重复性的代码放于此方法
        virtual void TearDown();//在每个用例执行之后都会执行此处的代码，可将每个用例重复性的代码放于此方法
} 


#edif