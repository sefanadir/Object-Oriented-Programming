#ifndef GTUSETBASE_H
#define GTUSETBASE_H
#include <iostream>
#include <memory>
using namespace std;
namespace sefanadir {

    class Exception : public exception {
    public:
        Exception(string temp) : inform(temp) { }
        virtual const char* what() const throw () {
            return inform.c_str();
        }
    private:
        string inform;
    };

    template <typename T>
    class GTUSetBase {
    public:

        class GTUIterator {
        public:
            GTUIterator(shared_ptr<T>& ptr);
            GTUIterator(T & val);
            GTUIterator(T *val);
            GTUIterator & operator++();
            GTUIterator & operator++(int);
            GTUIterator & operator--();
            GTUIterator & operator--(int);
            T *operator->();
            T &operator*();
            GTUIterator & operator=(const GTUIterator& rightSide);
            bool operator==(const GTUIterator& rightSide);
            bool operator!=(const GTUIterator& rightSide);
        protected:
            T* gtuiterator;
        };
        GTUSetBase();
        virtual bool empty() const = 0;
        virtual unsigned int size() const = 0;
        virtual unsigned int maxsize() const = 0;
        virtual void insert(const T& insertVal) throw(Exception)= 0;
        virtual unsigned int erase(const T& eraseVal) = 0;
        virtual void clear() = 0;
        virtual GTUIterator find(const T& findVal) = 0;
        virtual unsigned int count(const T& countVal) const = 0;
        virtual GTUIterator begin() = 0;
        virtual GTUIterator end() = 0;
    };
}
#endif /* GTUSET_BASE_H */