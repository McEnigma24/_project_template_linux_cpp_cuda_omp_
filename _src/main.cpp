#include "__preprocessor__.h"
#include "__time_stamp__.h"

int main(int argc, char* argv[])
{
    UTILS::clear_terminal();
    time_stamp("It just works");

    if (true)
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
        float a = 10.f;
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

    if (true)
    {
        var(Global_Operation_Counter::counter_add);
        var(Global_Operation_Counter::counter_sub);
        var(Global_Operation_Counter::counter_multi);
        var(Global_Operation_Counter::counter_dev);
        var(Global_Operation_Counter::counter_mod);
    }

    return 0;
}
