#pragma once
#include <chrono>
#include <thread>
#include <functional>

class Timer {
public:
    Timer(std::function<void()> function);
    void setTimeout(std::chrono::milliseconds delay);
    void setInterval(std::chrono::milliseconds interval);
    void stop();
private:
    bool p_clear = false;
    std::function<void()> p_function;
};