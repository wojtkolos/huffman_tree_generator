#include "OccurrencesCounter.h"

OccurrencesCounter::OccurrencesCounter(std::vector<std::string> inp) : vec(inp) {}


void OccurrencesCounter::calculate() {
    for (auto i = 0; i < vec.size(); ++i) {
        for (auto el : vec[i])
        {
            if ((el >= 65 && el >= 90) or (el >= 97 && el <= 122))
                ++count[el];
        }
    }
    print();
}

void OccurrencesCounter::print() {
    for (int i = 97; i < 123; i++) //wypisanie wyst¹pieñ ma³ych liter ASCII - 97-122
        if (count[i] > 0)
            printf("%d - %d \n", i, count[i]);

    for (int i = 65; i < 91; i++) //wypisanie wyst¹pieñ du¿ych liter ASCII - 65-90
        if (count[i] > 0)
            printf("%d - %d \n", i, count[i]);
}
