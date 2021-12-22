#include "Tree.h"



bool compare::operator()(MinHeapNode* l, MinHeapNode* r)
{
    return (l->getFreq() > r->getFreq());
}



HuffmanTree::HuffmanTree(std::map<char, int> mp) {
    for (std::map<char, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
        minHeap.push(new MinHeapNode(itr->first, itr->second));
    }
}



// Prints huffman codes from 
// the root of Huffman Tree. 
void HuffmanTree::print(MinHeapNode* root, std::string str)
{
    if (!root)
        return;
    if (root->getData() != '$')
        std::cout << root->getData() << ": " << str << "\n";

    print(root->getLeft(), str + "0");
    print(root->getRight(), str + "1");
}


// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanTree::createTree()
{
    MinHeapNode* left, * right, * top;
    // Iterate while size of heap doesn't become 1 
    while (minHeap.size() != 1) {

        // Extract the two minimum 
        // freq items from min heap 
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();


        top = new MinHeapNode('$', left->getFreq() + right->getFreq());

        top->setLeft(left);
        top->setRight(right);

        minHeap.push(top);
    }

    print(minHeap.top(), "");
}