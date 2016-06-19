#ifndef REALESTATE_H
#define REALESTATE_H

#include "Flat.h"
#include "House.h"
#include "Plot.h"


class RealEstate
{
    public:
        RealEstate();
        RealEstate(vector<Estate*>);
        ~RealEstate();
        RealEstate(const RealEstate& other);
        RealEstate& operator=(const RealEstate& other);

        void AddEstate();
        void RemoveEstate();

        void TypeSort();
        vector<Estate*> PrintAddress();

        vector<Estate*> searchType();
        vector<Estate*> searchOwner();
        vector<Estate*> searchAddress(string);
        vector<Estate*> searchArea();
        vector<Estate*> searchPrice();
        vector<Estate*> searchYardArea();
        vector<Estate*> searchNumberRooms();
        vector<Estate*> searchNumberFloors();
        vector<Estate*> searchOnFloor();
        vector<Estate*> searchCommunication();

    private:
        vector<Estate*> r_estate;
};

#endif // REALESTATE_H
