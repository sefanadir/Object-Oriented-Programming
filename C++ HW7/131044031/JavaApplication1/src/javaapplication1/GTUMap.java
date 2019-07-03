package javaapplication1;

import javafx.util.Pair;

public class GTUMap<K, V> extends GTUSet<javafx.util.Pair<K, V>> {

    /**
     * GTUMap one parameter constructor
     *
     * @param ptr container
     */
    public GTUMap(Class<Pair<K, V>[]> ptr) {
        super(ptr);
    }

    /**
     * GTUMap two parameter constructor
     *
     * @param ptr container
     * @param ptrArea usedArea
     */
    public GTUMap(Pair<K, V>[] ptr, int ptrArea) {
        super(ptr, ptrArea);
    }

    /**
     * If k matches the key of an element in the set, the method returns a
     * reference to its mapped value.
     *
     * @param k key of pair
     * @return value of pair
     */
    public V at(K k) {
        for (int i = 0; i < usedArea; ++i) {
            if (k == container[i].getKey()) {
                return container[i].getValue();
            }
        }
        return null;
    }

    /**
     * This method gets iterator to finding element
     *
     * @param findVal element to be found
     * @return iterator point to finding element
     */
    @Override
    public GTUIterator<Pair<K, V>> find(Object findVal) {

        for (int i = 0; i < usedArea; ++i) {
            if (container[i].getKey() == findVal) {
                GTUSetInt.GTUIterator<Pair<K, V>> findTarget;
                findTarget = new GTUSetInt.GTUIterator<>(container, i, usedArea);
                return findTarget;
            }
        }
        return null;
    }

    /**
     * This method erases element
     *
     * @param eraseVal element to be erased
     */
    @Override
    public void erase(Object eraseVal) {
        eraseVal = (K) eraseVal;
        int oldUsedArea = usedArea;
        --usedArea;
        int area = 0, count = 0;
        while (count < oldUsedArea) {
            if (container[count].getKey() != eraseVal) {
                container[area] = container[count];
                ++area;
            }
            ++count;
        }
    }

    /**
     * The returned set is the intersection of this map and the given map.
     *
     * @param object searching object for intersection
     * @return set is the intersection of giving set
     * @throws java.lang.Exception
     */
    public GTUMap<K, V> intersection(GTUMap<K, V> object) throws Exception {
        GTUIterator<Pair<K, V>> it_1 = begin();
        GTUIterator<Pair<K, V>> it_2 = object.begin();
        GTUMap<K, V> map1 = new GTUMap(Pair[].class);
        GTUMap<K, V> map2 = new GTUMap(Pair[].class);
        GTUMap<K, V> intersectionMap = new GTUMap(Pair[].class);
        
        while (it_1.hasNext()) {
            map1.insert(it_1.next());
        }
   
        while (it_2.hasNext()) {
            map2.insert(it_2.next());
        }
        
        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < object.size(); ++j) {
                if(map1.container[i].getKey()==map2.container[j].getKey()){
                    intersectionMap.insert(map1.container[i]);
                }
            }
        }
        return intersectionMap;
    }
}
