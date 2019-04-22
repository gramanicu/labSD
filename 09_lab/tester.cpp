
#include "./BinarySearchTree.h"
#include <iostream>
int main() {
    BinarySearchTree<int> bst;
    for(int i=0; i<=10; i++) {
        bst.insertKey(i);
    }


    std::cout << bst.searchKey(0) << "\n";
    std::cout << bst.searchKey(5) << "\n";
    std::cout << bst.searchKey(11) << "\n";

    std::vector<int> v = bst.inOrderDisplay();

    for(auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Min value is " << bst.findMin() << "\n";
    std::cout << "Max value is " << bst.findMax() << "\n";
    std::cout << "Num of levels is " << bst.findLevels() << "\n";

    bst.removeKey(6);


    std::vector<int> v1 = bst.inOrderDisplay();

    for(auto& i : v1) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}