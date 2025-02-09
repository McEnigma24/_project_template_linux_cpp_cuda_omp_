#include "__preprocessor__.h"
#include "__time_stamp__.h"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    UTILS::clear_terminal();
    time_stamp("It just works");

    Global_Operation_Counter::show();

    u64 a = 10;
    a += 10;

    Global_Operation_Counter::show();
    Global_Operation_Counter::reset();
    Global_Operation_Counter::show();

    return 0;
}
