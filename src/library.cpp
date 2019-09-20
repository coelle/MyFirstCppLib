#include "library.h"

namespace nco {
    std::string Summierer::addition(int a, int b) {
        std::string retVal{"Das ergibt "};
        retVal += std::to_string(a + b);
        return retVal;
    }
}