#include "__preprocessor__.h"
#include "time_stamp.h"

class U64
{
    u64 value;

  public:
    U64(const u64 &v) : value(v) { line("constructor"); }
    U64(U64 &&v) : value(v.value) { line("move constructor"); }
    U64(const U64 &other) : value(other.value) { line("copy constructor"); }
    U64 &operator=(const U64 &other)
    {
        line("operator=");
        value = other.value;
        return *this;
    }

    U64 operator+(const U64 &other)
    {
        line("operator+");
        return value + other.value;
    }

    U64 &operator+=(const U64 &other)
    {
        line("operator+=");
        value += other.value;
        return *this;
    }
    U64 &operator++()
    {
        line("operator++ pre");
        value++;
        return *this;
    }
    U64 operator++(int)
    {
        line("operator++ post");
        U64 previous_value = *this;
        value++;
        return previous_value;
    }

    U64 operator-(const U64 &other)
    {
        line("operator-");
        return value - other.value;
    }

    U64 &operator-=(const U64 &other)
    {
        line("operator-=");
        value -= other.value;
        return *this;
    }
    U64 &operator--()
    {
        line("operator-- pre");
        value--;
        return *this;
    }
    U64 operator--(int)
    {
        line("operator-- post");
        U64 previous_value = *this;
        value--;
        return previous_value;
    }

    friend std::ostream &operator<<(std::ostream &stream, const U64 &obj)
    {
        // line("stream");
        stream << obj.value;
        return stream;
    }
};

// #define u64 U64

int main(int argc, char *argv[])
{
    UTILS::clear_terminal();
    time_stamp("It just works");

    U64 a = 100;
    U64 b = 10;
    b = 100;
    b += 1;
    var(b);

    var(++b);
    var(b++);
    var(b + 10);

    var(b);

    a += b;
    var(a);

    return 0;
}
