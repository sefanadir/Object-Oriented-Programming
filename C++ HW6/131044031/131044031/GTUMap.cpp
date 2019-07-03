#include "GTUMap.h"
namespace sefanadir {

    template<class K, class V>
    GTUMap<K, V>::GTUMap() {
        GTUSet<pair<K, V>>::maxArea = 9999;
        GTUSet<pair<K, V>>::usedArea = 0;
        shared_ptr<pair<K, V >> temp(new pair<K, V>[GTUSet<pair<K, V>>::maxArea], default_delete < pair<K, V>[]>());
        GTUSet<pair<K, V>>::container = temp;
    }

    template<class K, class V>
    V& GTUMap<K, V>::operator[](const K& k) {
        for (int i = 0; i < GTUSet<pair < K, V>>::usedArea; ++i) {
            if (k == GTUSet<pair < K, V>>::container.get()[i].first)
                return GTUSet<pair < K, V>>::container.get()[i].second;
        }
    }
}