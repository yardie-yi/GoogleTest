#include "mytest.h"

/*对test_src.h中Value类is_eq_num方法的测试
  使用Value类实例化一个对象，并使用构造函数给类成员num赋值
  使用is_eq_num方法传入一个值，判断是否等于num值
  预期结果：
    传入参数值在区间[5,10]内放回-1（代码故意设置区间[4,10]）
    传入参数值等于num则返回1；否则返回0；
*/


TEST_F(Test, testcase1)
{
    Value num(5);
    EXPECT_EQ(num.is_eq_num(5), 1);
}

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