#ifndef FLAT_H
#define FLAT_H

#include <Estate.h>


class Flat : public Estate
{
    public:
        Flat();
        Flat(string, string, float, float, int, int);
        Flat(const Flat& other);
        void print()const;

        int GetNum_rooms() const { return num_rooms; }
        void SetNum_rooms( int val) { num_rooms = val; }

        int GetFloor() const { return floor; }
        void SetFloor( int val) { floor = val; }

    private:
         int num_rooms;
         int floor;
};

#endif // FLAT_H
