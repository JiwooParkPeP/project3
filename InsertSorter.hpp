// Ji Woo Park
// February 8th, 2022
// Assignment 7
// File ASorter/InsertSorter.hpp

#ifndef SmartInsertSorter_HPP_
#define SmartInsertSorter_HPP_

#include "ASorter.hpp"

template<class T>
class InsertSorter : public ASorter<T> {
protected:
    virtual void split(ASeq<T>&, int lo, int &mid, int hi) override;
    virtual void join(ASeq<T>&, int lo, int mid, int hi) override;
};

template<class T>
void InsertSorter<T>::split(ASeq<T> &, int, int &mid, int hi) {
// Post: mid == hi.
    mid = hi;
}

template<class T>
void InsertSorter<T>::join(ASeq<T> &a, int lo, int mid, int hi) {
    int j = mid;
    T key = a[mid];
    for (int i = mid - 1; i >= 0; i--) {
        if (key <= a[i]) {
            a[j--] = a[i];
        }
        a[j] = key;
    }


}

// Pre: mid == hi && sorted(a[lo..hi - 1]).
// Post: sorted(a[lo..hi]).



#endif
