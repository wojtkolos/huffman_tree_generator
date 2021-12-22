#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#include "OccurrencesCounter.h"
#include "Tree.h"

std::vector<std::string> read(std::string fname)
{
    std::vector<std::string> vec;
    std::ifstream file(fname);
    if (file.is_open()) {
        std::string s;
        while (file >> s) {
            vec.push_back(s);
        }
        file.close();
    }
    return vec;
}




int main()
{
    OccurrencesCounter h (read("test.txt"));
    h.calculate();

    HuffmanTree tree(h.getMap());
    tree.createTree();


    return 0;

}