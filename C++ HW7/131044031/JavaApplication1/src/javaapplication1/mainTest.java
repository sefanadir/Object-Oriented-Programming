package javaapplication1;

import javafx.util.Pair;

public class mainTest {

    /**
     * This method tests GTUSetInt, GTUIterator, GTUSet and GTUMap class
     *
     * @param args the command line arguments
     * @throws java.lang.Exception InvalidParameterException if the element is
     * already in the set
     */
    public static void main(String[] args) throws Exception {
        System.out.println("-----------GTUSet------------");
        GTUSetInt<Integer> gtuSet1 = new GTUSet<>(Integer[].class);
        GTUSetInt<Double> gtuSet2 = new GTUSet<>(Double[].class);
        GTUSetInt<String> gtuSet3 = new GTUSet<>(String[].class);
        GTUSetInt<Integer> gtuSet4 = new GTUSet<>(Integer[].class);
        System.out.println("---------Integer Set---------");
        try {
            gtuSet1.insert(7);
            gtuSet1.insert(5);
            gtuSet1.insert(3);
            gtuSet1.insert(2);
            gtuSet4.insert(27);
            gtuSet4.insert(5);
            gtuSet4.insert(13);
            gtuSet4.insert(2);
            gtuSet1.printSet();

            System.out.println("---------Double  Set---------");
            gtuSet2.insert(5.7);
            gtuSet2.insert(1.5);
            gtuSet2.insert(3.3);
            gtuSet2.insert(4.2);
            gtuSet2.printSet();

            System.out.println("---------String  Set---------");
            gtuSet3.insert("java");
            gtuSet3.insert("lisp");
            gtuSet3.insert("perl");
            gtuSet3.insert("python");
            gtuSet3.printSet();

            System.out.println("-----Integer Set empty()-----");
            if (gtuSet1.empty()) {
                System.out.println("This set is empty");
            } else {
                System.out.println("This set isn't empty");
            }

            System.out.println("-----Integer Set size()------");
            System.out.println(gtuSet1.size());

            System.out.println("-----Integer Set maxsize()---");
            System.out.println(gtuSet1.maxsize());

            System.out.println("-----String Set erase()------");
            gtuSet3.printSet();
            System.out.println("-----python erasing----------");
            gtuSet3.erase("python");
            gtuSet3.printSet();

            System.out.println("-----Double Set count()------");
            gtuSet2.printSet();
            if (gtuSet2.count(3.3) == 1) {
                System.out.println("Double Set has 3.3");
            }
            System.out.println("------GTUSet Iterator--------");
            System.out.println("------String Set find()------");
            GTUSetInt.GTUIterator<Integer> findSet;
            findSet = gtuSet3.find("java");
            System.out.println(findSet.next());

            System.out.println("------Integer Set begin()----");
            GTUSetInt.GTUIterator<Integer> beginSet;
            beginSet = gtuSet1.begin();
            System.out.println(beginSet.next());

            System.out.println("------Double Set end()-------");
            GTUSetInt.GTUIterator<Integer> endSet;
            endSet = gtuSet2.end();
            System.out.println(endSet.next());

            System.out.println("------Double Set hasPrevious(),previous()----");
            endSet = gtuSet2.end();
            while (endSet.hasPrevious()) {
                System.out.println(endSet.previous());
            }
            System.out.println("------String Set hasNext(),next()------------");
            beginSet = gtuSet3.begin();
            while (beginSet.hasNext()) {
                System.out.println(beginSet.next());
            }
            System.out.println("-------------------GTUMap--------------------");
            GTUMap<Integer, String> map1 = new GTUMap(Pair[].class);
            GTUMap<Integer, Integer> map2 = new GTUMap(Pair[].class);
            GTUMap<String, String> map3 = new GTUMap(Pair[].class);
            GTUMap<Integer, String> map4 = new GTUMap(Pair[].class);

            Pair<Integer, String> map1_pair1 = new Pair<>(1, "sefa");
            Pair<Integer, String> map1_pair2 = new Pair<>(2, "nadir");
            Pair<Integer, String> map1_pair3 = new Pair<>(3, "yıldız");
            Pair<Integer, String> map1_pair4 = new Pair<>(4, "sefa");
            Pair<Integer, String> map1_pair5 = new Pair<>(2, "nadir");
            Pair<Integer, String> map1_pair6 = new Pair<>(3, "yıldız");
            Pair<Integer, String> map1_pair7 = new Pair<>(7, "mustafa");
            Pair<Integer, String> map1_pair8 = new Pair<>(8, "ahmet");
            Pair<Integer, String> map1_pair9 = new Pair<>(9, "tuna");
            Pair<Integer, Integer> map2_pair1 = new Pair<>(1, 4);
            Pair<Integer, Integer> map2_pair2 = new Pair<>(2, 8);

            Pair<String, String> map3_pair1 = new Pair<>("cetvel", "silgi");

            System.out.println("------GTUMap <Integer, String> insert()------");
            map1.insert(map1_pair3);
            map1.insert(map1_pair2);
            map1.insert(map1_pair1);

            map4.insert(map1_pair4);
            map4.insert(map1_pair5);
            map4.insert(map1_pair6);
            map4.insert(map1_pair7);
            map4.insert(map1_pair8);
            map4.insert(map1_pair9);
            System.out.println("------GTUMap <Integer, String> at()----------");
            System.out.println(map1.at(1));
            System.out.println(map1.at(2));
            System.out.println(map1.at(3));

            System.out.println("------GTUMap <Integer, Integer> insert()-----");
            map2.insert(map2_pair2);
            map2.insert(map2_pair1);
            System.out.println("------GTUMap <Integer, String> at()----------");
            System.out.println(map2.at(1));
            System.out.println(map2.at(2));

            System.out.println("------GTUMap <String, String> insert()-------");
            map3.insert(map3_pair1);
            System.out.println("------GTUMap <String, String> at()-----------");
            System.out.println(map3.at("cetvel"));
            System.out.println(" ");
            System.out.println("------GTUMap <Integer, String> empty()-------");
            if (map1.empty()) {
                System.out.println("map1 is empty");
            } else {
                System.out.println("map1 isn't empty");
            }
            System.out.println(" ");
            System.out.println("------GTUMap <Integer, String> size()--------");
            System.out.println(map1.size());
            System.out.println(" ");
            System.out.println("------GTUMap <Integer, String> maxsize()-----");
            System.out.println(map1.maxsize());
            System.out.println(" ");
            System.out.println("-----GTUMap <Integer, String> erase()--------");
            System.out.println("-----Pair(3, yıldız) erasing-----------------");
            map1.erase(map1_pair3);
            System.out.println(" ");
            System.out.println("-----GTUMap <String, String> count()---------");

            if (map3.count(map3_pair1) == 1) {
                System.out.println("map3 has Pair(\"cetvel\", \"silgi\")");
            }
            System.out.println(" ");
            System.out.println("--GTUMap <Integer, String> hasNext(),next()--");
            GTUSetInt.GTUIterator<Pair<Integer, String>> beginMap;

            beginMap = map1.begin();
            while (beginMap.hasNext()) {
                System.out.println(beginMap.next());
            }
            System.out.println(" ");

            System.out.println("---------------Intersection Set--------------");
            GTUSetInt<Integer> intersectionSet;
            System.out.println("---------------Set1--------------------------");
            gtuSet4.printSet();
            System.out.println("---------------Set2--------------------------");
            gtuSet1.printSet();
            intersectionSet = gtuSet4.intersection(gtuSet1);
            System.out.println("---------------Intersection------------------");
            intersectionSet.printSet();

            System.out.println("---------------Intersection Map--------------");
            GTUMap<Integer, String> intersectionMap;
            System.out.println("---------------Map1--------------------------");
            map1.printSet();
            System.out.println("---------------Map2--------------------------");
            map4.printSet();
            intersectionMap = map1.intersection(map4);
            System.out.println("---------------Intersection------------------");
            intersectionMap.printSet();

        } catch (Exception e) {
            System.out.println("Exception caught: " + e);
        }
    }
}
