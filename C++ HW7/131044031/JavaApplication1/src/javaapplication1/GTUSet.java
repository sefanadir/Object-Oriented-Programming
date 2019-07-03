package javaapplication1;

import java.lang.reflect.Array;

public class GTUSet<T> implements GTUSetInt<T> {

    protected int maxArea, usedArea;
    protected T[] container;

    public GTUSet() {
        maxArea = 9999;
        usedArea = 0;
        container = (T[]) new Object[maxArea];
    }

    /**
     * GTUSet one parameter constructor
     *
     * @param ptr container
     */
    public GTUSet(Class<T[]> ptr) {
        maxArea = 9999;
        usedArea = 0;
        container = ptr.cast(Array.newInstance(ptr.getComponentType(), maxArea));
    }

    /**
     * GTUSet two parameter constructor
     *
     * @param ptr container
     * @param ptrArea usedArea
     */
    public GTUSet(T[] ptr, int ptrArea) {
        maxArea = 9999;
        usedArea = ptrArea;
        container = ptr;
    }

    /**
     * This method tests whether container is empty
     *
     * @return If set is empty, return true. If set is not empty, return false.
     */
    @Override
    public boolean empty() {
        return usedArea == 0;
    }

    /**
     * This method returns container size
     *
     * @return container size of container
     */
    @Override
    public int size() {
        return usedArea;
    }

    /**
     * This method return container maximum size
     *
     * @return maximum size of container
     */
    @Override
    public int maxsize() {
        return maxArea;
    }

    /**
     * Insert element, throws exception InvalidParameterException if the element
     * is already in the set
     *
     * @param insertVal element to be added to the container
     * @throws java.lang.Exception InvalidParameterException if the element is
     * already in the set
     */
    @Override
    public void insert(T insertVal) throws Exception {

        if (count(insertVal) == 0) {
            if (usedArea > maxArea) {
                reallocatedContainer();
            }
            container[usedArea] = insertVal;
            ++usedArea;
            sortContainer();
        } else {
            throw new Exception("the element is already in the set");
        }
    }

    /**
     * This method erases element
     *
     * @param eraseVal element to be erased
     */
    @Override
    public void erase(Object eraseVal) {
        if (count((T) eraseVal) == 1) {
            int oldUsedArea = usedArea;
            --usedArea;
            int area = 0, count = 0;
            while (count < oldUsedArea) {
                if (container[count] != eraseVal) {
                    container[area] = container[count];
                    ++area;
                }
                ++count;
            }
        }
    }

    /**
     * This method clears all content
     */
    @Override
    public void clear() {
        container = null;
        usedArea = 0;
    }

    /**
     * This method counts elements with a specific value
     *
     * @param countVal searching element
     * @return if the element is available in the set, return 1. If the element
     * is not available in the set, return 0
     */
    @Override
    public int count(T countVal) {
        int findElement = 0;
        for (int i = 0; i < usedArea; ++i) {
            if (container[i] == countVal) {
                ++findElement;
            }
        }
        if (findElement == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    /**
     * This method gets iterator to finding element
     *
     * @param findVal element to be found
     * @return iterator point to finding element
     */
    @Override
    public GTUSetInt.GTUIterator<T> find(Object findVal) {

        GTUSetInt.GTUIterator<T> findTarget;
        int findIndex = 0;
        for (int i = 0; i < usedArea; ++i) {
            if (container[i] == findVal) {
                findIndex = i;
            }
        }
        findTarget = new GTUSetInt.GTUIterator<>(container, findIndex, usedArea);
        return findTarget;
    }

    /**
     * This method returns iterator to beginning
     *
     * @return iterator point to start of container
     */
    @Override
    public GTUSetInt.GTUIterator<T> begin() {
        GTUSetInt.GTUIterator<T> beginOfSet;
        beginOfSet = new GTUSetInt.GTUIterator<>(container, 0, usedArea);
        return beginOfSet;
    }

    /**
     * This method returns iterator to end
     *
     * @return iterator point to end of container
     */
    @Override
    public GTUSetInt.GTUIterator<T> end() {
        GTUSetInt.GTUIterator<T> endOfSet;
        endOfSet = new GTUSetInt.GTUIterator<>(container, usedArea - 1, usedArea);
        return endOfSet;
    }

    /**
     * sort elements of set from big to small
     */
    public void sortContainer() {
        for (int i = 0; i < usedArea; ++i) {
            for (int j = i + 1; j < usedArea; ++j) {
                if (container[i].equals(container[j])) {
                    T temp = container[i];
                    container[i] = container[j];
                    container[j] = temp;
                }
            }
        }
    }

    /**
     * This element prints elements of container to screen
     */
    @Override
    public void printSet() {
        for (int i = 0; i < usedArea; ++i) {
            if (container[i] != null) {
                System.out.println(container[i]);
            }
        }
    }

    /**
     * The returned set is the intersection of this set and the given set.
     *
     * @param object searching object for intersection
     * @return set is the intersection of giving set
     */
    @Override
    public GTUSetInt<T> intersection(GTUSetInt<T> object) {

        GTUSetInt.GTUIterator<T> it_1 = begin();
        GTUSetInt.GTUIterator<T> it_2 = object.begin();
        T[] set1 = (T[]) new Object[size()];
        T[] set2 = (T[]) new Object[object.size()];
        int intersectionUsed;
        if (size() > object.size()) {
            intersectionUsed = object.size();
        } else {
            intersectionUsed = size();
        }
        T[] set3 = (T[]) new Object[intersectionUsed];
        int index = 0;

        while (it_1.hasNext()) {
            set1[index] = it_1.next();
            ++index;
        }
        index = 0;
        while (it_2.hasNext()) {
            set2[index] = it_2.next();
            ++index;
        }
        index = 0;
        for (int i = 0; i < size(); ++i) {
            for (int j = 0; j < object.size(); ++j) {
                if (set1[i] == set2[j]) {
                    set3[index] = set1[i];
                    ++index;
                }
            }
        }
        GTUSetInt<T> intersectionSet = new GTUSet<>(set3, intersectionUsed);
        return intersectionSet;
    }

    /**
     * This method reallocates area to container, If used area is full
     */
    private void reallocatedContainer() {
        T[] temp = container;
        maxArea *= 2;
        container = null;
        container = (T[]) new Object[maxArea];
        System.arraycopy(temp, 0, container, 0, usedArea);
    }
}
