#pragma once

#include <chrono>

//-----------------------------------------------------------------------------
// Class Clock
//-----------------------------------------------------------------------------
class Clock
{
public:
    Clock() = default;
    ~Clock() = default;

    double getElapsedTime();

    void sleep(float t);
    void reset();

private:
    std::chrono::steady_clock::time_point m_start;
};


