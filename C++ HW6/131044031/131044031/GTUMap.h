#ifndef GTUMAP_H
#define GTUMAP_H
#include "GTUSet.h"
#include <utility>
namespace sefanadir {
    template<class K, class V>
    class GTUMap : public GTUSet<std::pair<K, V>>
    {
        public:
        GTUMap();
        V& operator[](const K & k);
    };
}
#endif /* GTUMAP_H */

