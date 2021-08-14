#include <iostream>
#include "FibonacciHeap.h"

int main() {
    using namespace std;

    FibonacciHeap h;
    h.insert(h.make_node(7)->unite(h.make_node(30)));
    h.insert(h.make_node(24)->unite(h.make_node(26)->unite(h.make_node(35))->unite(h.make_node(89)))->unite(h.make_node(46)));
    h.insert(h.make_node(23));
    h.insert(h.make_node(17));
    h.insert(h.make_node(3)->unite(h.make_node(18)->unite(h.make_node(39)))->unite(h.make_node(52))->unite(h.make_node(49)->unite(h.make_node(50))));
    h.insert(h.make_node(4)->unite(h.make_node(19)->unite(h.make_node(40)))->unite(h.make_node(53))->unite(h.make_node(80)->unite(h.make_node(444))));
    h.insert(h.make_node(5)->unite(h.make_node(20)->unite(h.make_node(41)))->unite(h.make_node(54))->unite(h.make_node(81)->unite(h.make_node(446))));
    
    cout << "Initialized Fibonacci Heap:\n";
    h.display(h.min);

    h.extract_min();
    h.display(h.min);

    h.decrease_key(h.min->child->left->child->left->child->left, 11);
    h.display(h.min);

    h.decrease_key(h.min->child->left->child->left->child->child, 25);
    h.display(h.min);

    h.decrease_key(h.min->child->left->child->left->child->child, 12);
    h.display(h.min);

    h.delete_node(h.min->left);
    h.display(h.min);
}