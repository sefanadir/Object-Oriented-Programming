#include "requiredIncludes.h"
#include <memory>
template <class T>
shared_ptr<GTUSet<T>> setIntersection(GTUSet<T>&, GTUSet<T>&);

int main(int argc, char** argv) {

    try {
        cout << "---------------GTUSET---------------" << endl;
        GTUSet<double> gtuSet1;
        GTUSet<string> gtuSet2;
        GTUSet<string> gtuSet3;

        gtuSet3.insert("ab");
        gtuSet3.insert("zn");
        gtuSet3.insert("ef");
        gtuSet3.insert("km");

        gtuSet2.insert("ab");
        gtuSet2.insert("cd");
        gtuSet2.insert("de");
        gtuSet2.insert("ef");
        cout << "string sets" << endl;
        gtuSet2.printContainer();

        gtuSet1.insert(1.7);
        gtuSet1.insert(5.9);
        gtuSet1.insert(2.6);
        gtuSet1.insert(6.2);
        cout << "double sets" << endl;
        gtuSet1.printContainer();

        cout << "double set size    :" << gtuSet1.size() << endl;
        cout << "double set max size:" << gtuSet1.maxsize() << endl;

        cout << "erase 2.6 value" << endl;
        gtuSet1.erase(2.6);
        gtuSet1.printContainer();

        if (!gtuSet1.empty())
            cout << "Set is not empty" << endl;
        else
            cout << "Set is empty" << endl;

        double countVal = 5.9;
        if (gtuSet1.count(countVal))
            cout << countVal << " is a element of set" << endl;
        else
            cout << countVal << " isn't element of set" << endl;
        cout << "-----------GTUSet Iterator----------" << endl;
        for (GTUSet<double>::GTUIterator it = gtuSet1.begin(); it != gtuSet1.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
        cout << "find element 1.7 with find()" << endl;
        GTUSet<double>::GTUIterator it = gtuSet1.find(1.7);
        cout << *it << endl;

        gtuSet1.erase(1.7);
        cout << "set size after erase(1.7):" << gtuSet1.size() << endl;

        gtuSet1.clear();
        cout << "set size after clear()   :" << gtuSet1.size() << endl;

        cout << "---------------GTUMAP---------------" << endl;
        GTUMap<double, double> gtuMaps1;
        gtuMaps1.insert(pair<double, double>(1.7, 4.5));
        gtuMaps1.insert(pair<double, double>(1.2, 1.5));
        gtuMaps1.insert(pair<double, double>(2.7, 4.5));
        gtuMaps1.insert(pair<double, double>(3.2, 7.5));
        gtuMaps1.insert(pair<double, double>(4.7, 5.5));
        gtuMaps1.insert(pair<double, double>(5.2, 9.5));
        cout << "pair<double, double>(1.7, 4.5)" << endl;
        cout << gtuMaps1[1.7] << endl;
        cout << "pair<double, double>(1.2, 1.5)" << endl;
        cout << gtuMaps1[1.2] << endl;

        cout << "<double, double> map size    :" << gtuMaps1.size() << endl;
        cout << "<double, double> map max size:" << gtuMaps1.maxsize() << endl;

        GTUMap<string, int> gtuMaps2;
        gtuMaps2.insert(pair<string, int>("ali", 14));
        gtuMaps2.insert(pair<string, int>("veli", 13));
        gtuMaps2.insert(pair<string, int>("ahmet", 17));

        cout << "pair<string, int>(ali, 14)" << endl;
        cout << gtuMaps2["ali"] << endl;
        cout << "pair<string, int>(veli, 13)" << endl;
        cout << gtuMaps2["veli"] << endl;

        cout << "<string, int> map size    :" << gtuMaps2.size() << endl;
        cout << "<string, int> map max size:" << gtuMaps2.maxsize() << endl;

        gtuMaps1.erase(pair<double, double>(5.2, 9.5));
        if (!gtuMaps1.empty())
            cout << "Map is not empty" << endl;
        else
            cout << "Map is empty" << endl;

        if (gtuMaps1.count(pair<double, double>(5.2, 9.5)))
            cout << "pair<double, double>(5.2, 9.5) is a element of set" << endl;
        else
            cout << "pair(5.2, 9.5) isn't element of set" << endl;
        cout << "-----------GTUMap Iterator----------" << endl;
        for (GTUMap<string, int>::GTUIterator its = gtuMaps2.begin(); its != gtuMaps2.end(); ++its)
            cout << its->first << " ";
        cout << endl;

        for (GTUMap<string, int>::GTUIterator its = gtuMaps2.begin(); its != gtuMaps2.end(); ++its)
            cout << gtuMaps2[its->first] << " ";
        cout << endl;
        cout << "----------Intersection Set----------" << endl;
        cout<<"set 1: ";
        gtuSet2.printContainer();
        cout<<"set 2: ";
        gtuSet3.printContainer();
        shared_ptr<GTUSet<string>> intersectionSet = setIntersection(gtuSet2, gtuSet3);
        cout << "intersection:";
        intersectionSet.get()->printContainer();

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

template <class T>
shared_ptr<GTUSet<T>> setIntersection(GTUSet<T>& object1, GTUSet<T>& object2) {
    shared_ptr<GTUSet < T >> intersection(new GTUSet< T >);
    GTUSet< T > setObject;
    for (typename GTUSet<T>::GTUIterator iterator1 = object1.begin(); iterator1 != object1.end(); ++iterator1) {
        for (typename GTUSet<T>::GTUIterator iterator2 = object2.begin(); iterator2 != object2.end(); ++iterator2) {
            if (*iterator1 == *iterator2) {
                setObject.insert(*iterator1);
            }
        }
    }
    intersection.get()[0] = setObject;
    return intersection;
}