#include <stdexcept>

#include "medianstructure.h"

template <class T> void MedianStore<T>::add(const T& element ) {
    bool oddBefore = store.size() % 2;
    store.insert(element);

    if(1 == store.size()) {
        // This is the first element in the store. Initialize the median iterator.
        medianIterator = store.begin();
        return;
    }

    if(element >= *medianIterator) {
        if(!oddBefore) {
            ++medianIterator;
        }
    } else {
        if(oddBefore) {
            medianIterator = std::prev(medianIterator);
        }
    }
}

template <class T> double MedianStore<T>::getMedian() const {
    if(store.empty()) {
        throw std::runtime_error("empty store");
    }

    if(store.size() % 2) {
        return *medianIterator;
    }
    else {
        return static_cast<double>((*medianIterator + *(std::next(medianIterator)))) / 2;
    }
};

template class MedianStore<int>;
