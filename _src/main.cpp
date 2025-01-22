#include "__preprocessor__.h"
#include "time_stamp.h"

class Test
{
    Test() { cout << "Test creation" << endl; }
};

void func() { cout << "test" << endl; }

int main(int argc, char *argv[])
{
    time_stamp("It just works");

    if (true)
        {
            cout << "test" << endl;
        }

    return 0;
}
