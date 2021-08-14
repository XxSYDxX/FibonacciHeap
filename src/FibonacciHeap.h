#ifndef FibonacciHeap_h
#define FibonacciHeap_h
#include <string.h>

class FibonacciHeap {
private:
    struct node {
        int key, rank = 0;
        bool marked = false;
        node * parent = nullptr;
        node * child = nullptr;
        node * left = this;
        node * right = this;

        node * insertLeft(node *);
        node * isolate();
        node * unite(node *);
    };
    node * parent = nullptr;
    void consolidate(int);
    void cut(node *);
    void cascade_cut(node *);

public:
    node * min = nullptr;
    node * make_node(int);
    node * insert(node *);
    node * extract_min();
    void decrease_key(node *, int);
    void delete_node(node *);
    void display(node * n, std::string s="");

    FibonacciHeap(node * parent = nullptr) {
        this->parent = parent; 
    }
};

#endif