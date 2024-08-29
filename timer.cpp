#include "timer.hpp"

Timer::Timer(std::function<void()> function) {
    this->m_function = function;
}

void Timer::setTimeout(std::chrono::milliseconds delay) {
    this->m_clear = false;
    std::thread t([this, delay]() {
        std::this_thread::sleep_for(delay);
        {
            std::lock_guard<std::mutex> lock(this->m_mutex);
            if (this->m_clear)
                return;
        }
        m_function();
    });
    t.detach();
}

void Timer::setInterval(std::chrono::milliseconds interval) {
    this->m_clear = false;
    std::thread t([this, interval]() {
        while (true) {
            std::this_thread::sleep_for(interval);
            {
                std::lock_guard<std::mutex> lock(this->m_mutex);
                if (this->m_clear)
                    return;
            }
            m_function();
        }
    });
    t.detach();
}

void Timer::stop() {
    {
        std::lock_guard<std::mutex> lock(this->m_mutex);
        this->m_clear = true;
    }
}