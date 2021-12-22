#pragma once

#include <iostream>
#include <map>
#include <vector>


class OccurrencesCounter {
public:
    OccurrencesCounter(std::vector<std::string> inp);
    std::map<char, int> getMap() { return count; }
    void calculate();
    void print();
private:
    std::vector<std::string> vec;
    std::map<char, int> count;
};