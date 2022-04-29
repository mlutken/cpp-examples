#include "example_utils.h"

#include <iostream>

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

std::chrono::nanoseconds time_me(const std::function<void()>& function_to_time )
{
    const auto timepoint_start = steady_clock::now();
    function_to_time();
    return steady_clock::now() - timepoint_start;
}

milliseconds time_me_ms(const std::function<void ()>& function_to_time)
{
    return duration_cast<milliseconds>(time_me(function_to_time));
}

void time_me_ms_print(const string& msg, const std::function<void ()>& function_to_time)
{
    milliseconds elapsed = time_me_ms(function_to_time);
    cerr << "Timing '" << msg << "' took " << elapsed.count() << " ms\n";
}
