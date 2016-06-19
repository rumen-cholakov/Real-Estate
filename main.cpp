#include <iostream>

#include "RealEstate.h"

using namespace std;

int main()
{
    Estate* e = new Flat("ww1w", "If", 25.9, 1430.52, 83, 13);

    Estate* e1 = new House("ww3w", "me", 25, 1430.52, 83, 13, 9.5);

    Estate* e2 = new Flat("wwqw3w", "Iff", 258.9, 140.52, 803, 11);

    Estate* e3 = new House("ww3w", "mee", 2, 130.52, 3, 13, 95);

    vector<Communication> v_com;
    v_com.push_back(water);
    v_com.push_back(electricity);
    v_com.push_back(telephone);
    v_com.push_back(road);
    v_com.push_back(sewer);
    Estate* p = new Plot("ww3w", "If", 25.9, 14300.52, v_com);


    vector<Communication> v_com1;
    v_com1.push_back(water);
    v_com1.push_back(none);
    v_com1.push_back(telephone);
    v_com1.push_back(road);
    v_com1.push_back(sewer);
    Estate* p1 = new Plot("www", "If", 257.9, 14300.52, v_com1);


    vector<Estate*> v;
    v.push_back(e);
    v.push_back(e1);
    v.push_back(e2);
    v.push_back(e3);
    v.push_back(p);
    v.push_back(p1);

    RealEstate r(v);

    //r.AddEstate();
    r.RemoveEstate();
    r.TypeSort();
    r.PrintAddress();

    vector<Estate*> test;

    test = r.searchAddress("no");
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchOwner();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchType();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchArea();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchCommunication();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchNumberFloors();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchNumberRooms();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchOnFloor();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    test = r.searchPrice();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }


    test = r.searchYardArea();
    for (int i = 0;i < test.size() ;i++ )
    {
            test[i]->print();
    }

    return 0;
}
