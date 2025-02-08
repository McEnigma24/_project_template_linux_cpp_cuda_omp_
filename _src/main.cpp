#include "__preprocessor__.h"
#include "time_stamp.h"

#define OPERATION_COUNTER
#define OPERATION_COUNTER_SHOW_LOG

#ifdef OPERATION_COUNTER_SHOW_LOG
#define OP_C_SHOW_LOG_LINE(...) __VA_ARGS__
#else
#define OP_C_SHOW_LOG_LINE(...)
#endif

template <typename T> class Operation_Counter
{
    T value;

  public:
    static uint64_t counter_add;
    static uint64_t counter_sub;
    static uint64_t counter_multi;
    static uint64_t counter_dev;
    static uint64_t counter_mod;

    Operation_Counter(const T& v) : value(v)
    {
        OP_C_SHOW_LOG_LINE(line("constructor"));
    }
    Operation_Counter(Operation_Counter&& v) : value(v.value)
    {
        OP_C_SHOW_LOG_LINE(line("move constructor"));
    }
    Operation_Counter(const Operation_Counter& other) : value(other.value)
    {
        OP_C_SHOW_LOG_LINE(line("copy constructor"));
    }
    Operation_Counter& operator=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator="));
        value = other_value;
        return *this;
    }
    Operation_Counter& operator=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator="));
        value = other.value;
        return *this;
    }

    Operation_Counter operator+(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator+"));
        return value + other.value;
    }
    Operation_Counter& operator+=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));
        value += other.value;
        return *this;
    }
    Operation_Counter operator+(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+"));
        return value + other_value;
    }
    Operation_Counter& operator+=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));
        value += other_value;
        return *this;
    }
    Operation_Counter& operator++()
    {
        OP_C_SHOW_LOG_LINE(line("operator++ pre"));
        value++;
        return *this;
    }
    Operation_Counter operator++(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator++ post"));
        Operation_Counter previous_value = *this;
        value++;
        return previous_value;
    }

    Operation_Counter operator-(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));
        return value - other.value;
    }
    Operation_Counter& operator-=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));
        value -= other.value;
        return *this;
    }
    Operation_Counter operator-(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));
        return value - other_value;
    }
    Operation_Counter& operator-=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));
        value -= other_value;
        return *this;
    }
    Operation_Counter& operator--()
    {
        OP_C_SHOW_LOG_LINE(line("operator-- pre"));
        value--;
        return *this;
    }
    Operation_Counter operator--(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator-- post"));
        Operation_Counter previous_value = *this;
        value--;
        return previous_value;
    }

    Operation_Counter operator*(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));
        return value * other.value;
    }
    Operation_Counter& operator*=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));
        value *= other.value;
        return *this;
    }
    Operation_Counter operator*(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));
        return value * other_value;
    }
    Operation_Counter& operator*=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));
        value *= other_value;
        return *this;
    }

    Operation_Counter operator/(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));
        return value / other.value;
    }
    Operation_Counter& operator/=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));
        value /= other.value;
        return *this;
    }
    Operation_Counter operator/(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));
        return value / other_value;
    }
    Operation_Counter& operator/=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));
        value /= other_value;
        return *this;
    }

    Operation_Counter operator%(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));
        return value % other.value;
    }
    Operation_Counter& operator%=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));
        value %= other.value;
        return *this;
    }
    Operation_Counter operator%(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));
        return value % other_value;
    }
    Operation_Counter& operator%=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));
        value %= other_value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& stream,
                                    const Operation_Counter& obj)
    {
        // line("stream"));
        stream << obj.value;
        return stream;
    }
};

// #define u64 Operation_Counter<u64>
// #define float Operation_Counter<float>

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
