#ifndef TIMER_H
#define TIMER_H

#include <memory>
#include <functional>
#include <thread>

namespace examples {


class timer
{
public:
    using timeout_cb_t = std::function<void(size_t timeout_count)>;
    timer() = default;
    timer(const timeout_cb_t& cb, size_t timeout_in_ms);

    void    callback_set(const timeout_cb_t& cb) { callback_ = cb; }
    void    timeout_set(size_t timeout_in_ms);

private:
    void    call_callback();
    void    timer_thread_function();

    timeout_cb_t    callback_;
    std::unique_ptr<std::thread> timeout_thread_ptr_;
    size_t          timeout_in_ms_ = 0;
    size_t          timeout_count_ = 0;
    bool            is_one_shot = false;
};

} // END namespace examples

#endif // TIMER_H
