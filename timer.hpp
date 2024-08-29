#pragma once
#include <chrono>
#include <functional>
#include <mutex>
#include <thread>

class Timer {
  public:
    Timer(std::function<void()> function);
    void setTimeout(std::chrono::milliseconds delay);
    void setInterval(std::chrono::milliseconds interval);
    void stop();

  private:
    bool m_clear = false;
    std::mutex m_mutex;
    std::function<void()> m_function;
};