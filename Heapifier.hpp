// File: ASorter/Heapifier.hpp

#ifndef Heapifier_HPP_
#define Heapifier_HPP_

#include "ASeq.hpp"

// ========= siftUp =========
template<class T>
void siftUp(ASeq<T> &a, int lo, int i) {
// Pre: maxHeap(a[lo..i - 1]).
// Post: maxHeap(a[lo..i]).
    T temp = a[i];
    int parent = (i + lo - 1) / 2;
    while (lo < i && a[parent] < temp) {
        cerr << "siftUp: Exercise for the student." << endl;
        throw -1;
    }
    a[i] = temp;
}

// ========= siftDown =========
template<class T>
void siftDown(ASeq<T> &a, int lo, int i, int hi) {
    // Pre: maxHeap(a[i + 1..hi]).
// Pre: lo <= i <= hi.
// Post: maxHeap(a[i..hi]).
    int child = 2 * i - lo + 1; // Index of left child.
    bool done = hi < child;
    while (!done) {
        if (child < hi && a[child] < a[child + 1]) {
            child++;
        } else {
            done = true;
        }
        if (a[i] < a[child]) {
            T temp = a[i];
            a[i] = a[child];
            a[child] = temp;
            i = child;
            child = 2 * child - lo + 1;
            done = hi < child;
        } else {
            done = true;
        }
    }
}


#endif
