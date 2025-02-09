#pragma once
#include "__preprocessor__.h"

#ifdef OPERATION_COUNTER

#ifdef OPERATION_COUNTER_SHOW_LOG
#define OP_C_SHOW_LOG_LINE(...) __VA_ARGS__
#else
#define OP_C_SHOW_LOG_LINE(...)
#endif // OPERATION_COUNTER_SHOW_LOG

struct Global_Operation_Counter
{
    static uint64_t counter_add;
    static uint64_t counter_sub;
    static uint64_t counter_multi;
    static uint64_t counter_dev;
    static uint64_t counter_mod;
    static uint64_t counter_comparisons;

    static void show()
    {
        nline;
        line("< Operation Counters >");
        var(counter_add);
        var(counter_sub);
        var(counter_multi);
        var(counter_dev);
        var(counter_mod);
        var(counter_comparisons);
        nline;
    }
};

template <typename T>
class Operation_Counter
{
    T value;

public:
    Operation_Counter() { memset(this, 0, sizeof(*this)); }
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

    bool operator==(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator=="));

        Global_Operation_Counter::counter_comparisons++;
        return value == other.value;
    }
    bool operator!=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator!="));

        Global_Operation_Counter::counter_comparisons++;
        return value != other.value;
    }
    bool operator>(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator>"));

        Global_Operation_Counter::counter_comparisons++;
        return value > other.value;
    }
    bool operator<(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator<"));

        Global_Operation_Counter::counter_comparisons++;
        return value < other.value;
    }
    bool operator>=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator>="));

        Global_Operation_Counter::counter_comparisons++;
        return value >= other.value;
    }
    bool operator<=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator<="));

        Global_Operation_Counter::counter_comparisons++;
        return value <= other.value;
    }

    Operation_Counter operator+(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator+"));

        Global_Operation_Counter::counter_add++;
        return value + other.value;
    }
    Operation_Counter& operator+=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));

        Global_Operation_Counter::counter_add++;
        value += other.value;
        return *this;
    }
    Operation_Counter operator+(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+"));

        Global_Operation_Counter::counter_add++;
        return value + other_value;
    }
    Operation_Counter& operator+=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));

        Global_Operation_Counter::counter_add++;
        value += other_value;
        return *this;
    }
    Operation_Counter& operator++()
    {
        OP_C_SHOW_LOG_LINE(line("operator++ pre"));

        Global_Operation_Counter::counter_add++;
        value++;
        return *this;
    }
    Operation_Counter operator++(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator++ post"));

        Global_Operation_Counter::counter_add++;
        Operation_Counter previous_value = *this;
        value++;
        return previous_value;
    }

    Operation_Counter operator-(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));

        Global_Operation_Counter::counter_sub++;
        return value - other.value;
    }
    Operation_Counter& operator-=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));

        Global_Operation_Counter::counter_sub++;
        value -= other.value;
        return *this;
    }
    Operation_Counter operator-(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));

        Global_Operation_Counter::counter_sub++;
        return value - other_value;
    }
    Operation_Counter& operator-=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));

        Global_Operation_Counter::counter_sub++;
        value -= other_value;
        return *this;
    }
    Operation_Counter& operator--()
    {
        OP_C_SHOW_LOG_LINE(line("operator-- pre"));

        Global_Operation_Counter::counter_sub++;
        value--;
        return *this;
    }
    Operation_Counter operator--(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator-- post"));

        Global_Operation_Counter::counter_sub++;
        Operation_Counter previous_value = *this;
        value--;
        return previous_value;
    }

    Operation_Counter operator*(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));

        Global_Operation_Counter::counter_multi++;
        return value * other.value;
    }
    Operation_Counter& operator*=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));

        Global_Operation_Counter::counter_multi++;
        value *= other.value;
        return *this;
    }
    Operation_Counter operator*(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));

        Global_Operation_Counter::counter_multi++;
        return value * other_value;
    }
    Operation_Counter& operator*=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));

        Global_Operation_Counter::counter_multi++;
        value *= other_value;
        return *this;
    }

    Operation_Counter operator/(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));

        Global_Operation_Counter::counter_dev++;
        return value / other.value;
    }
    Operation_Counter& operator/=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));

        Global_Operation_Counter::counter_dev++;
        value /= other.value;
        return *this;
    }
    Operation_Counter operator/(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));

        Global_Operation_Counter::counter_dev++;
        return value / other_value;
    }
    Operation_Counter& operator/=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));

        Global_Operation_Counter::counter_dev++;
        value /= other_value;
        return *this;
    }

    Operation_Counter operator%(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));

        Global_Operation_Counter::counter_mod++;
        return value % other.value;
    }
    Operation_Counter& operator%=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));

        Global_Operation_Counter::counter_mod++;
        value %= other.value;
        return *this;
    }
    Operation_Counter operator%(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));

        Global_Operation_Counter::counter_mod++;
        return value % other_value;
    }
    Operation_Counter& operator%=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));

        Global_Operation_Counter::counter_mod++;
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

// można liczyć jeszcze porównania

#define i8 Operation_Counter<i8>
#define i16 Operation_Counter<i16>
#define i32 Operation_Counter<i32>
#define i64 Operation_Counter<i64>

#define u8 Operation_Counter<u8>
#define u16 Operation_Counter<u16>
#define u32 Operation_Counter<u32>
#define u64 Operation_Counter<u64>

#define float Operation_Counter<float>
#define double Operation_Counter<double>

#endif // OPERATION_COUNTER