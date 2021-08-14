#include <iostream>
#include "FibonacciHeap.h"
using namespace std;

// Inserts n to the left of the node
FibonacciHeap::node * FibonacciHeap::node::insertLeft(node * n) {
    left->right = n;
    n->right = this;
    n->left = left;
    left = n;

    n->parent = this->parent;
    return this;
}

// Removes it from its parent and siblings (keeps children though)
FibonacciHeap::node * FibonacciHeap::node::isolate() {
    if (parent) {
        parent->rank--;
        if (this->parent->child == this) {
            if (this->right != this) {
                this->parent->child = this->right;
            } else {
                this->parent->child = nullptr;
                this->parent = nullptr;
                return this;
            }
        }
    }

    this->parent = nullptr;
    this->left->right = this->right;
    this->right->left = this->left;

    this->left = this;
    this->right = this;
    return this;
}

// includes chd as a child of the node
FibonacciHeap::node * FibonacciHeap::node::unite(node * chd) {
    node * prt = new node;
    prt = this;
    chd->isolate()->parent = prt;

    if (!prt->child) {
        prt->child = chd;
    }

    prt->child->insertLeft(chd);
    rank++;
    return this;
}

FibonacciHeap::node * FibonacciHeap::make_node(int key) {
    node * n = new node;
    n->key = key;
    n->parent = parent;
    return n;
}

// public insertion operation (to the left of min)
FibonacciHeap::node * FibonacciHeap::insert(node * n) {
    if (min) {
        min->insertLeft(n);
        if (n->key < min->key) {
            min = n;
        }
    } else {
        min = n;
    }
    return min;
} 

FibonacciHeap::node * FibonacciHeap::extract_min() {
    node * nh = new node, * curr = new node;
    nh = min;
    curr = nh;
    int rank = 0;
    do {
        if (curr->rank > rank)
            rank = curr->rank;
        curr = curr->right;
    } while (curr != nh);

    // When multiple nodes have the max rank, the rank of the tree
    // increases by at least (the # of nodes with the max rank -1)
    do {
        if (curr->rank == rank)
            rank++;
        curr = curr->right;
    } while (curr != nh);

    min = min->right;
    nh->isolate();

    node *chdptr = new node, *nxtchd = new node;
    chdptr = nh->child;
    nxtchd = chdptr;

    if (nxtchd) {
        do {
            nxtchd->parent = nullptr;
            node * temp = new node;
            *temp = *nxtchd;
            min->insertLeft(nxtchd);

            if (nxtchd->key < min->key) {
                min = nxtchd;
            }

            nxtchd = temp->right;
        } while (nxtchd != chdptr);
    }

    consolidate(rank);
    return nh;
}

void FibonacciHeap::consolidate(int rank) {
    node * ranks[rank+1]{};
    
    while (true) {
        node * minptr = new node, * curr = new node;
        minptr = min;
        curr = minptr;
        bool dupl_ranks = false;
        do {
            if (ranks[curr->rank]) {
                if (ranks[curr->rank] != curr) {
                    dupl_ranks = true;
                }
            } else {
                ranks[curr->rank] = curr;
            }
            curr = curr->right;
        } while (minptr != curr);

        if (!dupl_ranks)
            break;

        node *temp = new node;
        for (int i = 0; i <= rank; i++) {
            minptr = min;
            curr = minptr;
            do {
                *temp = *curr;
                if (curr->rank == i) {
                    if (ranks[i] && ranks[i] != curr) {
                        node * prt = new node, * chd = new node;
                        if (curr->key < ranks[i]->key){
                            prt = curr;
                            chd = ranks[i];
                        } else {
                            prt = ranks[i];
                            chd = curr;
                        }
                        if (chd == min) {
                            min = prt;
                        }
                        prt->unite(chd);
                        if (!ranks[i+1]) {
                            ranks[i+1] = prt;
                        }
                        ranks[i] = nullptr;
                        break;
                    }
                }
                curr = temp->right;
            } while (minptr != curr);
        }
    }
}

void FibonacciHeap::decrease_key(node * n, int k) {
    n->key = k;
    node *p = new node;
    p = n->parent;

    if (p && p->key > k) {
        cut(n);
        cascade_cut(p);
    }

    if (k < min->key) {
            min = n;
    }
}

void FibonacciHeap::cut(node * n) {
    n->marked = false;
    min->insertLeft(n->isolate());
}

void FibonacciHeap::cascade_cut(node * n) {
    node *p = new node;
    p = n->parent;

    if (p) {
        if (!n->marked)
            n->marked = true;
        else {
            cut(n);
            cascade_cut(p);
        }
    }
}

void FibonacciHeap::delete_node(node * n) {
    decrease_key(n, INT32_MIN);
    extract_min();
}

void FibonacciHeap::display(node * n, std::string s) {
    node * ptr = n;
    if (ptr) {
        do {
            string t = s;
            cout << s;
            if (ptr->right != n) {
                cout << char(195) << char(196);
                t = s + char(179) + "  ";
            } else {
                cout << char(192) << char(196);
                t = s + "   ";
            }
            cout <<" " << ptr->key << endl;
            display(ptr->child, t);
            ptr = ptr->right;
        } while (ptr != n);
    }
}