#include <stdexcept>

#include "medianstructure.h"

/**
 * Adds a new element to the store.
 * We would keep the iterator member pointing to the median element or in the case of even
 * number of elements to the first one of the two 'middle' elements.
 */
template <class T> void MedianStore<T>::add(const T& element ) {
    bool oddBefore = store.size() % 2;
    store.insert(element);

    if(1 == store.size()) {
        // This is the first element in the store. Initialize the median iterator.
        medianIterator = store.begin();
        return;
    }

    if(element >= *medianIterator) {
        // We have inserted on the right of the median. Our pointer needs incrementing
        // only if the number of elements has been even before the insert.
        // Note: We depend on std::multiset inserting equal elements "at the upper bound
        // of that range"
        if(!oddBefore) {
            ++medianIterator;
        }
    } else {
        // Similarly if inserting on the left of the median our pointer needs incrementing
        // if the number of elements has been odd before the insert.
        if(oddBefore) {
            medianIterator = std::prev(medianIterator);
        }
    }
}

template <class T> double MedianStore<T>::getMedian() const {
    if(store.empty()) {
        throw std::runtime_error("empty store");
    }

    // As by the definition of a median element we either return the 'middle' or
    // calculate the average of the two 'middle' elements.
    if(store.size() % 2) {
        return *medianIterator;
    }
    else {
        return static_cast<double>((*medianIterator + *(std::next(medianIterator)))) / 2;
    }
}

template class MedianStore<int>;
