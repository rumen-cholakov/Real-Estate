#include "Estate.h"

Estate::Estate()
{
    this->type = "";
    this->address = "";
    this->owner = "";
    this->area = 0;
    this->price = 0;
}

Estate::Estate(string ad, string ow, float ar, float pr)
{
    this->type = "Estate";
    this->address = ad;
    this->owner = ow;
    this->area = ar;
    this->price = pr;
}

Estate::Estate(const Estate& e)
{
    this->type = e.type;
    this->address = e.address;
    this->owner = e.owner;
    this->area = e.area;
    this->price = e.price;
}
