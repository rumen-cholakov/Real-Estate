#ifndef ESTATE_H
#define ESTATE_H

#include<iostream>
#include<string>
#include <vector>
#include <limits>

using namespace std;

enum Communication { none = 0, water, electricity, telephone, road, sewer };

class Estate
{
    public:
        Estate();
        Estate(string, string, float, float);
        Estate(const Estate&);

        virtual void print()const = 0 ;

        string GetAddress() const { return address; }
        void SetAddress(string val) { address = val; }

        string GetOwner() const { return owner; }
        void SetOwner(string val) { owner = val; }

        float GetPrice() const { return price; }
        void SetPrice(float val) { price = val; }

        float GetArea() const { return area; }
        void SetArea(float val) { area = val; }

        string GetType() const { return type; }
        void SetType(string val) { type = val; }

        virtual int GetNum_rooms() const { return 0; }
        virtual int GetFloor() const { return 0; }
        virtual int GetNum_floor() const { return 0; }
        virtual float GetYard_area() const { return 0; }
        virtual vector<Communication> GetCom() const
        {
            vector<Communication> v;
            return v;
        };

        virtual void SetNum_rooms( int val) {}
        virtual void SetNum_floor( int val) {}
        virtual void SetYard_area(float val) {}
        virtual void SetFloor( int val) {}
        virtual void SetCom() {};

    private:
        string type;
        string address;
        string owner;
        float price;
        float area;
};

#endif // ESTATE_H
