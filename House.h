#ifndef HOUSE_H
#define HOUSE_H

#include <Estate.h>


class House : public Estate
{
    public:
        House();
        House(string, string, float, float, int, int, float);
        House(const House& other);
        void print()const;

        int GetNum_rooms() const { return num_rooms; }
        void SetNum_rooms( int val) { num_rooms = val; }

        int GetNum_floor() const { return num_floor; }
        void SetNum_floor( int val) { num_floor = val; }

        float GetYard_area() const { return yard_area; }
        void SetYard_area(float val) { yard_area = val; }

    private:
         int num_rooms;
         int num_floor;
         float yard_area;
};

#endif // HOUSE_H
