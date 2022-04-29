#ifndef EXAMPLE_UTILS_H
#define EXAMPLE_UTILS_H

#include <string>
#include <functional>
#include <chrono>



std::chrono::nanoseconds    time_me             (const std::function<void()>& function_to_time );
std::chrono::milliseconds   time_me_ms          (const std::function<void()>& function_to_time );
void                        time_me_ms_print    (const std::string& msg, const std::function<void()>& function_to_time );


#endif // EXAMPLE_UTILS_H
