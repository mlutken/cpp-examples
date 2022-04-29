
#include "example1.h"

#include <iostream>

using namespace std;

class MyClass {
public:

    int float_to_int(float value)
    {
        return static_cast<int>(value);
    }
};

int example1()
{
    cerr << "Hello World!" << endl;

    MyClass c;

    return 0;
}

