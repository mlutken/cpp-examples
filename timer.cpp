#include "timer.h"

#include <chrono>

namespace examples {

timer::timer(const timeout_cb_t &cb, size_t timeout_in_ms)
    : callback_(cb)
{
    timeout_set(timeout_in_ms);
}

void timer::timeout_set(size_t timeout_in_ms)
{
    timeout_in_ms_ = timeout_in_ms;
    timeout_thread_ptr_ = std::make_unique<std::thread>(&timer::timer_thread_function, this);
    timeout_thread_ptr_->detach();

}

void timer::call_callback()
{
    timeout_count_++;
    if (callback_) {
        callback_(timeout_count_);
    }
}

void timer::timer_thread_function()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(timeout_in_ms_));
    call_callback();

    if (!is_one_shot) {
        timeout_set(timeout_in_ms_);
    }
}


} // END namespace examples
