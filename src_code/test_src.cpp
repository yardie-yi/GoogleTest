#include "test_src.h"

Value::Value(int base_num) 
{
    if ((base_num < 5) || (base_num > 10)) {
        num = 5;
    } else {
        num = base_num;
    }
}

int Value::is_eq_num(int input_num)
{
    if ((input_num < 4) || (input_num > 10)) {
        cout << "input error number and return -1!!!!!!!!!!!" << endl;
        return -1;
    } else {
        if (input_num == num) {
            cout << "input num is eq base num!!! and return 1" << endl;
            return 1;
        } else {
            cout << "input num is not eq base num !! and return 0" << endl;
            return 0;
        }
    }
}
