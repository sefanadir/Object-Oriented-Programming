package javaapplication1;

public interface GTUSetInt<T> {

    public class GTUIterator<T> {

        private final T[] gtuiterator;
        private int index = 0, used = 0;

        /**
         * GTUIterator two parameter constructor
         *
         * @param ptr container
         * @param requiredIndex marked index
         * @param usedArea filled area in the container
         */
        public GTUIterator(T[] ptr, int requiredIndex, int usedArea) {
            gtuiterator = ptr;
            index = requiredIndex;
            used = usedArea;
        }

        /**
         * Returns true if this list iterator has more elements when traversing
         * the list in the forward direction
         *
         * @return true if the list iterator has more elements when traversing
         * the list in the forward direction
         */
        public boolean hasNext() {
            return index < used && index >= 0;
        }

        /**
         * Returns true if this list iterator has more elements when traversing
         * the list in the reverse direction.
         *
         * @return true if the list iterator has more elements when traversing
         * the list in the reverse direction
         *
         */
        public boolean hasPrevious() {
            return index < used && index >= 0;
        }

        /**
         * Returns the next element in the list and advances the cursor
         * position.
         *
         * @return the next element in the list
         */
        public T next() {
            return gtuiterator[index++];
        }

        /**
         * Returns the previous element in the list and moves the cursor
         * position backwards.
         *
         * @return the previous element in the list
         */
        public T previous() {
            return gtuiterator[index--];
        }
    }

    /**
     * This method tests whether container is empty
     *
     * @return If set is empty, return true. If set is not empty, return false.
     */
    abstract public boolean empty();

    /**
     * This method returns container size
     *
     * @return container size of container
     */
    abstract public int size();

    /**
     * This method return container maximum size
     *
     * @return maximum size of container
     */
    abstract public int maxsize();

    /**
     * Insert element, throws exception InvalidParameterException if the element
     * is already in the set
     *
     * @param insertVal element to be added to the container
     * @throws java.lang.Exception InvalidParameterException if the element is
     * already in the set
     */
    abstract public void insert(T insertVal) throws Exception;

    /**
     * This method erases element
     *
     * @param eraseVal element to be erased
     */
    abstract public void erase(Object eraseVal);

    /**
     * This method clears all content
     */
    abstract public void clear();

    /**
     * This method gets iterator to finding element
     *
     * @param findVal element to be found
     * @return iterator point to finding element
     */
    abstract public GTUIterator find(Object findVal);

    /**
     * This method counts elements with a specific value
     *
     * @param countVal searching element
     * @return if the element is available in the set, return 1. If the element
     * is not available in the set, return 0
     */
    abstract public int count(T countVal);

    /**
     * This element prints elements of container to screen
     */
    abstract public void printSet();

    /**
     * This method returns iterator to beginning
     *
     * @return iterator point to start of container
     */
    abstract public GTUIterator begin();

    /**
     * This method returns iterator to end
     *
     * @return iterator point to end of container
     */
    abstract public GTUIterator end();

    /**
     * The returned set is the intersection of this set and the given set.
     *
     * @param object searching object for intersection
     * @return set is the intersection of giving set
     */
    abstract public GTUSetInt<T> intersection(GTUSetInt<T> object);
}
