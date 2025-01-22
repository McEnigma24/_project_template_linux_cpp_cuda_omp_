#include "__preprocessor__.h"
#include "time_stamp.h"

namespace TESTING
{

}

class Test
{
    Test()
    {
        cout << "Test creation" << endl;
        cout << "next line\n";
    }
};

// COmment check
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
