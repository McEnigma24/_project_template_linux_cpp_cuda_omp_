#include "__preprocessor__.h"
#include "time_stamp.h"

int main(int argc, char* argv[])
{
    UTILS::clear_terminal();
    time_stamp("It just works");

    if (false)
    {
        u64 a = 100;
        u64 b = 10;
        b = 100;
        b += 1;
        var(b);

        var(++b);
        var(b++);
        var(b + 10);

        var(b);

        a += b;
        var(a);
    }

    if (true)
    {
        OP_C_SHOW_LOG_LINE(float a = 10.f);
        var(a);
        a += 10.f;
        var(a);
        a -= 5.f;
        var(a);
        a /= 2.f;
        var(a);
        a *= 18.f;
        var(a);
    }

    return 0;
}
