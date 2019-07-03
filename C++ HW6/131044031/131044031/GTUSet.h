#ifndef GTUSET_H
#define GTUSET_H
#include "GTUSetBase.h"
#include "GTUSetBase.cpp"
namespace sefanadir {

    template<typename T>
    class GTUSet : public GTUSetBase<T> {
    public:
        GTUSet();
        virtual bool empty() const override;
        virtual unsigned int size() const override;
        virtual unsigned int maxsize() const override;
        virtual void insert(const T& insertVal) throw(Exception) override;
        virtual unsigned int erase(const T& eraseVal) override;
        virtual void clear() override;
        virtual typename GTUSetBase<T>::GTUIterator find(const T& findVal) override;
        virtual unsigned int count(const T& countVal) const override;
        virtual typename GTUSetBase<T>::GTUIterator begin() override;
        virtual typename GTUSetBase<T>::GTUIterator end() override;
        void printContainer() const;

    protected:
        shared_ptr<T> container;
        int maxArea, usedArea;
        void sortContainer() const;
        void reallocatedContainer();
    };
}
#endif /* GTUSET_H */

