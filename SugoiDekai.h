#ifndef INC_SUGOIDEKAI_H_
#define INC_SUGOIDEKAI_H_
#include <cstdint>

namespace check
{
struct SugoiDekai
{
    static constexpr uint32_t Size = 1024;
    void zeros();
    void fill();
    void print();

    uint8_t data_[Size];
};

void print(SugoiDekai data);
} // namespace check
#endif // INC_SUGOIDEKAI_H_
