#pragma once

#include <set>

template <class T> class MedianStore
{
private:
    std::multiset<T> store;
    typename std::set<T>::const_iterator medianIterator;

public:
    void add(const T& element );
    double getMedian() const;
};
