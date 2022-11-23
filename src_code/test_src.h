#ifndef _TEST_SRC_H_
#define _TEST_SRC_H_

#include <iostream>

using namespace std;

class Value {
private:
    int num;

public:
    Value(int base_num);
    int is_eq_num(int input_num);
}


#endif
