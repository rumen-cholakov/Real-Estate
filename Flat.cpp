#include "Flat.h"

Flat::Flat() : Estate()
{
    this->num_rooms = 0;
    this->floor = 0;
}

Flat::Flat(string ad, string ow, float ar, float pr, int nr, int f) : Estate(ad, ow, ar, pr)
{
    this->SetType("Flat");
    this->num_rooms = nr;
    this->floor = f;
}

Flat::Flat(const Flat& other) : Estate(other)
{
    this->num_rooms = other.num_rooms;
    this->floor = other.floor;
}

void Flat::print() const
{
    cout << "Address: " << this->GetAddress() << endl;
    cout << "Owner: " << this->GetOwner() << endl;
    cout << "Price: " << this->GetPrice() << endl;
    cout << "Area: " << this->GetArea() << endl;
    cout << "Number of rooms: " << this->num_rooms << endl;
    cout << "Floor: " << this->floor << endl;
}
