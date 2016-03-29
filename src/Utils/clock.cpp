#include "Utils/clock.h"
#include <cstdint>
#include <thread>

//-----------------------------------------------------------------------------
// Get functions
//-----------------------------------------------------------------------------
double Clock::getElapsedTime()
{
    std::chrono::duration<double> diff = std::chrono::steady_clock::now() - m_start;
    return diff.count();
}

//-----------------------------------------------------------------------------
// Other functions
//-----------------------------------------------------------------------------
void Clock::sleep(float t)
{
    std::uint64_t inMicro = std::uint64_t(1e6f * t);
    std::chrono::microseconds duration(inMicro);
    std::this_thread::sleep_for(duration);
}

void Clock::reset()
{
    m_start = std::chrono::steady_clock::now();
}
