#pragma once

#include <set>

/**
 * A store for numeric values.
 */
template <class T> class MedianStore
{
private:
    std::multiset<T> store;
    typename std::set<T>::const_iterator medianIterator;

public:
    /**
     * @brief add
     * Adds a new element to the store.
     * @param element
     * The new element to be added.
     */
    void add(const T& element );
    /**
     * @brief getMedian
     * Returns the current median of the elements already inserted.
     * @return
     * The current median value
     */
    double getMedian() const;
};
