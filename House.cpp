#include "House.h"

House::House() : Estate()
{
    this->num_rooms = 0;
    this->num_floor = 0;
    this->yard_area = 0;
}

House::House(string ad, string ow, float ar, float pr, int nr, int f, float y_r) : Estate(ad, ow, ar, pr)
{
    this->SetType("House");
    this->num_rooms = nr;
    this->num_floor = f;
    this->yard_area = y_r;
}

House::House(const House& other) : Estate(other)
{
    this->num_rooms = other.num_rooms;
    this->num_floor = other.num_floor;
    this->yard_area = other.yard_area;
}

void House::print() const
{
    cout << "Address: " << this->GetAddress() << endl;
    cout << "Owner: " << this->GetOwner() << endl;
    cout << "Price: " << this->GetPrice() << endl;
    cout << "Area of the house: " << this->GetArea() << endl;
    cout << "Number of rooms: " << this->num_rooms << endl;
    cout << "Number of floors: " << this->num_floor << endl;
    cout << "Area of the yard: " << this->yard_area << endl;
}
