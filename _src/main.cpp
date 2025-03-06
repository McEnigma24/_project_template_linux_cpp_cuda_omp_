#include "__preprocessor__.h"
#include "__time_stamp__.h"

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string format_number(T number)
{
    std::string str = std::to_string(number);

    // Sprawdzenie, czy liczba jest zmiennoprzecinkowa
    size_t dot_pos = str.find('.');
    if (dot_pos != std::string::npos)
    {
        // Oddziel część przed kropką
        std::string integer_part = str.substr(0, dot_pos);
        std::string fractional_part = str.substr(dot_pos + 1);

        // Formatowanie części całkowitej
        std::string formatted_integer;
        int count = 0;
        for (int i = integer_part.length() - 1; i >= 0; --i)
        {
            formatted_integer.insert(formatted_integer.begin(), integer_part[i]);
            count++;
            if (count == 3 && i != 0)
            {
                formatted_integer.insert(formatted_integer.begin(), '`');
                count = 0;
            }
        }

        // Złożenie wyniku
        return formatted_integer + "." + fractional_part;
    }
    else
    {
        // Jeśli liczba jest całkowita
        std::string integer_part = str;

        // Formatowanie części całkowitej
        std::string formatted_integer;
        int count = 0;
        for (int i = integer_part.length() - 1; i >= 0; --i)
        {
            formatted_integer.insert(formatted_integer.begin(), integer_part[i]);
            count++;
            if (count == 3 && i != 0)
            {
                formatted_integer.insert(formatted_integer.begin(), '`');
                count = 0;
            }
        }

        return formatted_integer;
    }
}

class test
{
    int tab[100];
};

#ifdef BUILD_EXECUTABLE
int main(int argc, char* argv[])
{
    srand(time(NULL));
    // CORE::clear_terminal();
    time_stamp("It just works");

    CORE::str::split_string("Hello, World!", ' ');
    var(CORE::str::to_lower_case("Hello, World!"));

    show_sizeof(test);
    show_sizeof_many(test, 100);

    int num = 123456789;
    double num2 = 1234567.89123;

    std::cout << "Formatted integer: " << format_number(num) << std::endl;
    std::cout << "Formatted float: " << format_number(num2) << std::endl;

    return 0;
}
#endif