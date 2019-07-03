#include "GTUSetBase.h"
namespace sefanadir {

    template<typename T>
    GTUSetBase<T>::GTUSetBase() {

    }

    template<typename T>
    GTUSetBase<T>::GTUIterator::GTUIterator(shared_ptr<T>& ptr) {
        gtuiterator = ptr.get();
    }

    template<typename T>
    GTUSetBase<T>::GTUIterator::GTUIterator(T & val) {
        gtuiterator = &val;
    }

    template<typename T>
    GTUSetBase<T>::GTUIterator::GTUIterator(T * val) {
        gtuiterator = val;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator++() {
        gtuiterator++;
        return *this;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator++(int) {
        GTUSetBase<T>::GTUIterator tempGtuIterator = *this;
        gtuiterator++;
        return tempGtuIterator;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator--() {
        gtuiterator--;
        return *this;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator--(int) {
        GTUSetBase<T>::GTUIterator tempGtuIterator = *this;
        gtuiterator--;
        return tempGtuIterator;
    }

    template<typename T>
    T* GTUSetBase<T>::GTUIterator::operator->() {
        return gtuiterator;
    }

    template<typename T>
    T &GTUSetBase<T>::GTUIterator::operator*() {
        return *gtuiterator;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator& GTUSetBase<T>::GTUIterator::operator=(const GTUIterator& rightSide) {
        gtuiterator = rightSide.gtuiterator;
        return *this;
    }

    template<typename T>
    bool GTUSetBase<T>::GTUIterator::operator==(const GTUIterator& rightSide) {
        return gtuiterator = rightSide.gtuiterator;
    }

    template<typename T>
    bool GTUSetBase<T>::GTUIterator::operator!=(const GTUIterator& rightSide) {
        return gtuiterator != rightSide.gtuiterator;
    }
}