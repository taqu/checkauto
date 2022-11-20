#include "SugoiDekai.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>

namespace check
{
void SugoiDekai::zeros()
{
    ::memset(data_, 0, sizeof(uint8_t) * Size);
}

void SugoiDekai::fill()
{
    std::random_device device;
    std::minstd_rand engine(device());
    for(uint32_t i = 0; i < Size; ++i) {
        data_[i] = static_cast<uint8_t>(engine());
    }
}

void SugoiDekai::print()
{
    for(uint32_t i = 0; i < Size; ++i) {
        if(0 == (i % 1024)) {
            std::cout << static_cast<uint32_t>(data_[i]);
        }
    }
    std::cout << std::endl;
}

void print(SugoiDekai data)
{
    data.print();
}
} // namespace check
