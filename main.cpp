#include <iostream>
#include "FibonacciHeap.h"

int main() {
    using namespace std;

    FibonacciHeap h;
    h.insert(h.make_node(7)->unite(h.make_node(30)));
    h.insert(h.make_node(24)->unite(h.make_node(26)->unite(h.make_node(35))->unite(h.make_node(89)))->unite(h.make_node(46)));
    h.insert(h.make_node(23));
    h.insert(h.make_node(17));
    h.insert(h.make_node(3)->unite(h.make_node(18)->unite(h.make_node(39)))->unite(h.make_node(52))->unite(h.make_node(41)->unite(h.make_node(44))));
    
    cout << "Initialized Fibonacci Heap:\n";
    h.display(h.min);

    // Extract Min Operation
    cout << "Extracted min: " << h.extract_min()->key << ". New Heap: \n";
    h.display(h.min);

    // decreasing 46 to 20
    cout << "Decreasing 46 to 20\n";
    h.decrease_key(h.min->child->left->child->right, 20);
    h.display(h.min);

    //decreasing 35 to 5
    cout << "Decreasing 35 to 5\n";
    h.decrease_key(h.min->child->left->child->child, 5);
    h.display(h.min);

    //decreasing 89 to 10;
    cout << "Decreasing 89 to 10\n";
    h.decrease_key(h.min->right->child->left->child->child, 10);
    h.display(h.min);

    cout << "Deleting 23\n";
    h.delete_node(h.min->right->child->right->child);
    h.display(h.min);
}