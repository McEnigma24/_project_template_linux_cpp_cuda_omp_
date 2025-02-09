#include "__preprocessor__.h"
#include "__time_stamp__.h"

struct test
{
    float a;
    double b;
    u64 c;
    i64 d;
};

int main(int argc, char* argv[])
{
    UTILS::clear_terminal();
    srand(time(NULL));
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
        vector<u64> tmp(100);

        for (auto& n : tmp)
        {
            n += rand() % 100;
        }

        test just_testing;
        just_testing.a = 0;
        just_testing.b = 0;
        just_testing.c = 0;
        just_testing.d = 0;

        just_testing.a *= 10;
        just_testing.b *= 10;
        just_testing.c *= 10;
        just_testing.d *= 10;

        u64 a = 10;
        u64 b = 10;

        if (a <= b)
        {
            cout << "good\n";
        }
        if (a <= b)
        {
            cout << "good\n";
        }
    }

    Global_Operation_Counter::show();

    return 0;
}
