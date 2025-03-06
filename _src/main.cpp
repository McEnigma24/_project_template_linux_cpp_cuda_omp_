#include "__preprocessor__.h"
#include "__time_stamp__.h"

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