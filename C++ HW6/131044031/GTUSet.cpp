#include "GTUSet.h"
namespace sefanadir {

    template<class T>
    GTUSet<T>::GTUSet() : maxArea(9999), usedArea(0) {
        shared_ptr<T> temp(new T[maxArea], default_delete < T[]>());
        container = temp;
    }

    template<class T>
    bool GTUSet<T>::empty() const {
        if (usedArea == 0)
            return true;
        else
            return false;
    }

    template<typename T>
    unsigned int GTUSet<T>::size() const {
        return usedArea;
    }

    template<typename T>
    unsigned int GTUSet<T>::maxsize() const {
        return maxArea;
    }

    template<class T>
    void GTUSet<T>::insert(const T& insertVal) throw (Exception) {
        if (!count(insertVal)) {
            if (usedArea > maxArea) {
                reallocatedContainer();
            }
            container.get()[usedArea] = insertVal;
            ++usedArea;
            sortContainer();
        }
        else{
            throw Exception("the same data can not be added");
        }
    }

    template<class T>
    unsigned int GTUSet<T>::erase(const T& eraseVal) {
        /*exceptıon fırlatılacak*/
        if (count(eraseVal)) {
            int oldUsedArea = usedArea;
            --usedArea;
            int area = 0, count = 0;
            while (count < oldUsedArea) {
                if (container.get()[count] != eraseVal) {
                    container.get()[area] = container.get()[count];
                    ++area;
                }
                ++count;
            }
        }
    }

    template<class T>
    void GTUSet<T>::clear() {
        container.reset(new T[maxArea], default_delete < T[]>());
        usedArea = 0;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::find(const T& findVal) {
        for (int i = 0; i < usedArea; ++i) {
            if (container.get()[i] == findVal)
                return typename GTUSetBase<T>::GTUIterator(container.get()[i]);
        }
    }

    template<typename T>
    unsigned int GTUSet<T>::count(const T& countVal) const {
        int findElement = 0;
        for (int i = 0; i < usedArea; ++i) {
            if (container.get()[i] == countVal)
                ++findElement;
        }
        if (findElement == 1)
            return 1;
        else
            return 0;
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::begin() {
        return typename GTUSetBase<T>::GTUIterator(container);
    }

    template<typename T>
    typename GTUSetBase<T>::GTUIterator GTUSet<T>::end() {
        T* endPointer = container.get();
        for (int i = 0; i < usedArea; i++)
            ++endPointer;
        return typename GTUSetBase<T>::GTUIterator(endPointer);
    }

    template<typename T>
    void GTUSet<T>::sortContainer() const {
        for (int i = 0; i < usedArea; ++i) {
            for (int j = i + 1; j < usedArea; ++j) {
                if (container.get()[i] > container.get()[j]) {
                    T temp = container.get()[i];
                    container.get()[i] = container.get()[j];
                    container.get()[j] = temp;
                }
            }
        }
    }

    template<typename T>
    void GTUSet<T>::printContainer() const {
        for (int i = 0; i < usedArea; ++i) {
            cout << container.get()[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    void GTUSet<T>::reallocatedContainer() {
        shared_ptr<T> temp(new T[usedArea], default_delete < T[]>());
        temp = container;
        maxArea *= 2;
        shared_ptr<T> newArea(new T[maxArea], default_delete < T[]>());
        container = newArea;
        for (int i = 0; i < usedArea; i++) {
            container.get()[i] = temp.get()[i];
        }
    }
}
