
#include "std_function_example1.h"
#include <iostream>
#include "timer.h"

using namespace std;
using namespace examples;

class my_class {
public:

    my_class()
//        : timer_([this](size_t timeout_count) {timeout(timeout_count);}, 1770)
    {
        timer_.callback_set([this](size_t timeout_count) {timeout(timeout_count);});
        timer_.timeout_set(1770);
    }

    void timeout(size_t timeout_count)
    {
        cerr << "Timeout number " << timeout_count << " reached. Do something ...\n";
    }
private:
    timer timer_;
};

int std_function_example1(int /*argc*/, char** /*argv*/)
{
    using namespace std::chrono;
    using namespace std::chrono_literals;
    cerr << "std::function example 1" << endl;

    cerr << "Create my_class that that calls it's timeout() function in x ms\n";
    my_class c;

    // Main loop do other work
    const seconds time_to_run = 10s;
    const auto start_time_point = steady_clock::now();
    const auto end_time_point = start_time_point + time_to_run;

    while (end_time_point > steady_clock::now()) {
        const seconds seconds_passed = duration_cast<seconds>(steady_clock::now() - start_time_point);
        cerr << "Dispatch messages and do work() Seconds: " << seconds_passed.count() << "\n";
        std::this_thread::sleep_for(1s);
    }

    return 0;
}

// https://newbedev.com/how-to-convert-std-chrono-time-point-to-string
// https://github.com/HowardHinnant/date
