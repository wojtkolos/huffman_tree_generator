#pragma once

#include <iostream>
#include <queue>
#include <map>



// A Huffman tree node
class MinHeapNode {
public:
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }

    char getData() { return this->data; }
    unsigned getFreq() { return this->freq; }

    MinHeapNode* getLeft() { return this->left; }
    MinHeapNode* getRight() { return this->right; }


    void setLeft(MinHeapNode* l) { this->left = l; }
    void setRight(MinHeapNode* r) { this->right = r; }
private:
    char data;
    unsigned freq;

    MinHeapNode* left, * right;
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r);
};

class HuffmanTree {
public:
    HuffmanTree(std::map<char, int> mp);
    
    void print(MinHeapNode* root, std::string str);
    void createTree();

private:
    
    std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;
};