#include "mytest.h"

/*对test_src.h中Value类is_eq_num方法的测试
  使用Value类实例化一个对象，并使用构造函数给类成员num赋值；num值范围[5,10]；在区间外num值默认为5
  使用is_eq_num方法传入一个值，判断是否等于num值
  is_eq_num方法：
    传入参数值 不 在区间[5,10]返回-1（代码故意设置区间[4,10]）
    传入参数值等于num则返回1；否则返回0；
*/

//测试用例1；用例名称为testcase1
TEST_F(Test, testcase1)
{
    Value num(5);
	//EXPECT_EQ(a, b)：检查a与b是否相等。
    EXPECT_EQ(num.is_eq_num(5), 1); //预期结果is_eq_num返回1
}

//测试用例2；用例名称为testcase2
TEST_F(Test, testcase2)
{
    Value num(5);
    EXPECT_EQ(num.is_eq_num(7), 0); //预期结果is_eq_num返回0
}

TEST_F(Test, testcase3)
{
    Value num(7);
    EXPECT_EQ(num.is_eq_num(1), -1); //预期结果is_eq_num返回-1
}

TEST_F(Test, testcase4)
{
    Value num(5);
    EXPECT_EQ(num.is_eq_num(4), -1); //预期结果is_eq_num返回-1；
									 //执行结果返回0；
									 //此用例fail
}