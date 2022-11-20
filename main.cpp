#include "SugoiDekai.h"
#include <vector>

int main(void)
{
    int i;
    using namespace check;
    static constexpr uint32_t NumSamples = 1000;
    std::vector<SugoiDekai> data;
    data.resize(NumSamples);
    { // Initialize
        for(auto& d: data) {
            d.zeros();
        }
    }

    { // Bad usage 1 --- case 1
        for(auto d: data) {
            d.fill();
        }
    }

    { // Bad usage 2 --- case 2
        for(size_t i = 0; i < data.size(); ++i) {
            auto d = data[i];
            d.fill();
        }
    }

    { // Bad usage 3 --- case 3
        for(const auto& d: data) {
            print(d);
        }
    }

    { // Bad usage 4 --- case 4
        for(SugoiDekai d: data) {
            d.fill();
        }
    }

    { // Bad usage 5 --- case 5
        for(size_t i = 0; i < data.size(); ++i) {
            SugoiDekai d = data[i];
            d.fill();
        }
    }

    { // Bad usage 6 --- case 6
        for(const SugoiDekai& d: data) {
            print(d);
        }
    }
    return 0;
}
