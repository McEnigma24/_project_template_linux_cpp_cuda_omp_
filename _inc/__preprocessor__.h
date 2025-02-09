#pragma once
#include <chrono>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>

using namespace std;

#define path_run_time_config "../run_time_config"

#define var(x) cout << #x << " = " << x << '\n';
#define varr(x) cout << #x << " = " << x << ' ';
#define line(x) cout << x << '\n';
#define linee(x) cout << x << ' ';
#define nline cout << '\n';

int my_sum(int a, int b);

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define null nullptr
#define pow2(x) ((x) * (x))
#define base_0(x) (x - 1)

#define c_init(x) x(_##x)
#define cc_init(x) this->x = x;
#define member_assign(a, b, member) a.member = b.member;
#define THIS_OTHER(x) this->x = other.x;

#define add_endl(string, how_many)                                             \
    for (u16 i{}; i < how_many; i++)                                           \
        string += "\n";

#define OUTPUT_TO_FILE(path, content)                                          \
    {                                                                          \
        ofstream file(path);                                                   \
        file << content;                                                       \
        file.close();                                                          \
    }

#define FATAL_ERROR(x)                                                         \
    {                                                                          \
        const string fatal = "FATAL ERROR - " + std::to_string(__LINE__) +     \
                             " : " + __FILE__ + " -> " + x + "\n";             \
        cout << fatal;                                                         \
        exit(EXIT_FAILURE);                                                    \
    }
#define ASSERT_ER_IF_TRUE(x)                                                   \
    if (x)                                                                     \
    FATAL_ERROR(#x)
#define ASSERT_ER_IF_NULL(x)                                                   \
    if (x == null)                                                             \
    FATAL_ERROR(#x)

#define SAFETY_CHECK(x) x;

#define delay_input std::this_thread::sleep_for(std::chrono::milliseconds(50));
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));

struct UTILS
{

    static void clear_terminal()
    {
#ifdef _WIN32
        int status = std::system("cls"); // Windows
#else
        int status = std::system("clear"); // Linux / macOS
#endif
    }

    struct str
    {
        static std::vector<std::string> split_string(const std::string& input,
                                                     char delimiter)
        {
            std::vector<std::string> result;
            std::string segment;
            std::istringstream stream(input);

            while (std::getline(stream, segment, delimiter))
            {
                result.push_back(segment);
            }

            return result;
        }
        static std::string to_lower_case(const std::string& input)
        {
            std::string result;
            result.reserve(input.size());
            for (char c : input)
            {
                result += static_cast<char>(
                    std::tolower(static_cast<unsigned char>(c)));
            }

            return result;
        }
    };

    struct vec
    {
        template <typename T>
        static void print_on_by_one(const std::vector<T>& vec)
        {
            for (auto& v : vec)
            {
                cout << v << "\n";
            }
        }

        template <typename T>
        static bool contains(const T& value, const std::vector<T>& vec)
        {
            return std::find(vec.begin(), vec.end(), value) != vec.end();
        }

        template <typename T>
        static void remove_by_value(const T& value, std::vector<T>& vec)
        {
            auto it = std::find(vec.begin(), vec.end(), value);

            if (it != vec.end())
            {
                vec.erase(it);
            }
        }
    };
};

#define OPERATION_COUNTER
#define OPERATION_COUNTER_SHOW_LOG

#ifdef OPERATION_COUNTER
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

        counter_add++;
        return value + other.value;
    }
    Operation_Counter& operator+=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));

        counter_add++;
        value += other.value;
        return *this;
    }
    Operation_Counter operator+(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+"));

        counter_add++;
        return value + other_value;
    }
    Operation_Counter& operator+=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator+="));

        counter_add++;
        value += other_value;
        return *this;
    }
    Operation_Counter& operator++()
    {
        OP_C_SHOW_LOG_LINE(line("operator++ pre"));

        counter_add++;
        value++;
        return *this;
    }
    Operation_Counter operator++(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator++ post"));

        counter_add++;
        Operation_Counter previous_value = *this;
        value++;
        return previous_value;
    }

    Operation_Counter operator-(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));

        counter_sub++;
        return value - other.value;
    }
    Operation_Counter& operator-=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));

        counter_sub++;
        value -= other.value;
        return *this;
    }
    Operation_Counter operator-(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-"));

        counter_sub++;
        return value - other_value;
    }
    Operation_Counter& operator-=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator-="));

        counter_sub++;
        value -= other_value;
        return *this;
    }
    Operation_Counter& operator--()
    {
        OP_C_SHOW_LOG_LINE(line("operator-- pre"));

        counter_sub++;
        value--;
        return *this;
    }
    Operation_Counter operator--(int)
    {
        OP_C_SHOW_LOG_LINE(line("operator-- post"));

        counter_sub++;
        Operation_Counter previous_value = *this;
        value--;
        return previous_value;
    }

    Operation_Counter operator*(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));

        counter_multi++;
        return value * other.value;
    }
    Operation_Counter& operator*=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));

        counter_multi++;
        value *= other.value;
        return *this;
    }
    Operation_Counter operator*(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*"));

        counter_multi++;
        return value * other_value;
    }
    Operation_Counter& operator*=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator*="));

        counter_multi++;
        value *= other_value;
        return *this;
    }

    Operation_Counter operator/(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));

        counter_dev++;
        return value / other.value;
    }
    Operation_Counter& operator/=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));

        counter_dev++;
        value /= other.value;
        return *this;
    }
    Operation_Counter operator/(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/"));

        counter_dev++;
        return value / other_value;
    }
    Operation_Counter& operator/=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator/="));

        counter_dev++;
        value /= other_value;
        return *this;
    }

    Operation_Counter operator%(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));

        counter_mod++;
        return value % other.value;
    }
    Operation_Counter& operator%=(const Operation_Counter& other)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));

        counter_mod++;
        value %= other.value;
        return *this;
    }
    Operation_Counter operator%(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%"));

        counter_mod++;
        return value % other_value;
    }
    Operation_Counter& operator%=(const T& other_value)
    {
        OP_C_SHOW_LOG_LINE(line("operator%="));

        counter_mod++;
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

template <typename T> uint64_t Operation_Counter::counter_add = 0;
template <typename T> uint64_t Operation_Counter::counter_sub = 0;
template <typename T> uint64_t Operation_Counter::counter_multi = 0;
template <typename T> uint64_t Operation_Counter::counter_dev = 0;
template <typename T> uint64_t Operation_Counter::counter_mod = 0;

#define u64 Operation_Counter<u64>
#define float Operation_Counter<float>
#endif