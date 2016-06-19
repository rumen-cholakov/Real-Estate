#include "RealEstate.h"

bool ErrorCheck(istream& s)
{
    if (!s)
    {
        s.clear();
        s.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid inputs! Please try again!";
        return true;
    }
    return false;
}

RealEstate::RealEstate()
{
}

RealEstate::RealEstate(vector<Estate*> v)
{
    this->r_estate = v;
}

RealEstate::~RealEstate()
{
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        delete r_estate[i];
    }
}

RealEstate::RealEstate(const RealEstate& other)
{
    this->r_estate.clear();
    for (int i = 0;i < other.r_estate.size() ;i++ )
    {
        if (other.r_estate[i]->GetType() == "Flat")
        {
            Estate* e = new Flat(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                  other.r_estate[i]->GetArea(), other.r_estate[i]->GetNum_rooms(), other.r_estate[i]->GetFloor());
            this->r_estate.push_back(e);
        }
        else if (other.r_estate[i]->GetType() == "House")
        {
            Estate* e = new House(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                  other.r_estate[i]->GetArea(), other.r_estate[i]->GetNum_rooms(), other.r_estate[i]->GetNum_floor(), other.r_estate[i]->GetYard_area());
            this->r_estate.push_back(e);
        }
        else
        {
            Estate* e = new Plot(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                  other.r_estate[i]->GetArea(), other.r_estate[i]->GetCom());
            this->r_estate.push_back(e);
        }
    }
}

RealEstate& RealEstate::operator=(const RealEstate& other)
{
    if (this == &other)
        return *this;
    else
    {
        this->r_estate.clear();
        for (int i = 0;i < other.r_estate.size() ;i++ )
        {
            if (other.r_estate[i]->GetType() == "Flat")
            {
                Estate* e = new Flat(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                      other.r_estate[i]->GetArea(), other.r_estate[i]->GetNum_rooms(), other.r_estate[i]->GetFloor());
                this->r_estate.push_back(e);
            }
            else if (other.r_estate[i]->GetType() == "House")
            {
                Estate* e = new House(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                      other.r_estate[i]->GetArea(), other.r_estate[i]->GetNum_rooms(), other.r_estate[i]->GetNum_floor(), other.r_estate[i]->GetYard_area());
                this->r_estate.push_back(e);
            }
            else
            {
                Estate* e = new Plot(other.r_estate[i]->GetAddress(), other.r_estate[i]->GetOwner(), other.r_estate[i]->GetPrice(),
                                      other.r_estate[i]->GetArea(), other.r_estate[i]->GetCom());
                this->r_estate.push_back(e);
            }
        }
    }
    return *this;
}

vector<Estate*> RealEstate::searchType()
{
    string type_search;
    cout << "Please input the type of estate you are searching for!";
    do
    {
        cout << "The possible types are: Flat, House, Plot.\nInput: ";
        getline(cin, type_search);
        if (type_search != "Flat" && type_search != "House" && type_search != "Plot")
            cout << "Invalid input! Please try again!";
    }while(type_search != "Flat" && type_search != "House" && type_search != "Plot");

    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetType() == type_search)
            v.push_back(r_estate[i]);
    }

    return v;
}

vector<Estate*> RealEstate::searchOwner()
{
    string owner_search;
    cout << "Please input the owner of estate you are searching for!";
    getline(cin, owner_search);

    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetOwner() == owner_search)
            v.push_back(r_estate[i]);
    }

    return v;
}

vector<Estate*> RealEstate::searchAddress(string removal = "no")
{
    string address_search;
    cout << "Please input the address of estate you are searching for!";
    getline(cin, address_search);
    vector<Estate*> v;
    if(removal == "no")
        for (int i = 0;i < this->r_estate.size() ;i++ )
        {
            int sub = this->r_estate[i]->GetAddress().find(address_search);

            if (this->r_estate[i]->GetAddress() == address_search || sub != -1 )
                v.push_back(r_estate[i]);
        }
    else
        for (int i = 0;i < this->r_estate.size() ;i++ )
        {
            if (this->r_estate[i]->GetAddress() == address_search )
                v.push_back(r_estate[i]);
        }

    return v;
}

vector<Estate*> RealEstate::searchArea()
{
    float bot_limArea, top_limArea;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the area of the estate you are searching for!";
        cin >> bot_limArea >> top_limArea;
    } while (ErrorCheck(cin));


    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetArea() >= bot_limArea && this->r_estate[i]->GetArea() <= top_limArea)
            v.push_back(r_estate[i]);
    }

    return v;
}

vector<Estate*> RealEstate::searchPrice()
{
    float bot_limPrice, top_limPrice;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the price of the estate you are searching for!";
        cin >> bot_limPrice >> top_limPrice;
    } while (ErrorCheck(cin));
    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetPrice() >= bot_limPrice && this->r_estate[i]->GetPrice() <= top_limPrice)
            v.push_back(r_estate[i]);
    }

    return v;
}

vector<Estate*> RealEstate::searchYardArea()
{
    float bot_limYardArea, top_limYardArea;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the yard area of the estate you are searching for!";
        cin >> bot_limYardArea >> top_limYardArea;
    } while (ErrorCheck(cin));
    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetYard_area() >= bot_limYardArea && this->r_estate[i]->GetYard_area() <= top_limYardArea)
            v.push_back(r_estate[i]);
    }

    return v;
}

vector<Estate*> RealEstate::searchNumberFloors()
{
    int bot_limNumberFloors, top_limNumberFloors;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the number of floors the estate you are searching for has!";
        cin >> bot_limNumberFloors >> top_limNumberFloors;
    } while (ErrorCheck(cin));
    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetNum_floor() >= bot_limNumberFloors && this->r_estate[i]->GetNum_floor() <= top_limNumberFloors)
            v.push_back(r_estate[i]);
    }
    return v;
}

vector<Estate*> RealEstate::searchOnFloor()
{
    int bot_limOnFloor, top_limOnFloor;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the floor on which the estate you are searching for is!";
        cin >> bot_limOnFloor >> top_limOnFloor;
    } while (ErrorCheck(cin));
    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetFloor() >= bot_limOnFloor && this->r_estate[i]->GetFloor() <= top_limOnFloor)
            v.push_back(r_estate[i]);
    }
    return v;
}

vector<Estate*> RealEstate::searchNumberRooms()
{
    int bot_limNumberRooms, top_limNumberRooms;
    do
    {
        cout << "Please input the bottom and upper limits, separated by a space, for the number of rooms the estate you are searching for has!";
        cin >> bot_limNumberRooms >> top_limNumberRooms;
    } while (ErrorCheck(cin));
    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if (this->r_estate[i]->GetNum_rooms() >= bot_limNumberRooms && this->r_estate[i]->GetNum_rooms() <= top_limNumberRooms)
            v.push_back(r_estate[i]);
    }
    return v;
}

vector<Estate*> RealEstate::searchCommunication()
{
    string answer;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please answer with yes or no!" << endl;
    vector<Communication> com;
    com.resize(5,none);
    do
    {
        cout << "Does the plot have water: ";
        getline(cin, answer);
        if (answer == "yes")
        {
            com[0] = water;
        }
        else if (answer == "no")
        {
            com[0] = none;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }

    } while (answer != "yes" && answer != "no");

    do
    {
        cout << "Does the plot have electricity: ";
        getline(cin, answer);
        if (answer == "yes")
        {
            com[1] = electricity;
        }
        else if (answer == "no")
        {
            com[1] = none;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    } while (answer != "yes" && answer != "no");

    do
    {
        cout << "Does the plot have telephone: ";
        getline(cin, answer);
        if (answer == "yes")
        {
            com[2] = telephone;
        }
        else if (answer == "no")
        {
            com[2] = none;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    } while (answer != "yes" && answer != "no");

    do
    {
        cout << "Does the plot have road: ";
        getline(cin, answer);
        if (answer == "yes")
        {
            com[3] = road;
        }
        else if (answer == "no")
        {
            com[3] = none;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    } while (answer != "yes" && answer != "no");

    do
    {
        cout << "Does the plot have sewer: ";
        getline(cin, answer);
        if (answer == "yes")
        {
            com[4] = sewer;
        }
        else if (answer == "no")
        {
            com[4] = none;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    } while (answer != "yes" && answer != "no");

    vector<Estate*> v;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        if ((this->r_estate[i])->GetCom() == com)
            v.push_back(r_estate[i]);
    }
    return v;
}

void RealEstate::AddEstate()
{
    string add_type;
    cout << "Please input the type of estate you are adding!";
    do
    {
        cout << "The possible types are: Flat, House, Plot.\nInput: ";
        getline(cin, add_type);
        if (add_type != "Flat" && add_type != "House" && add_type != "Plot")
            cout << "Invalid input! Please try again!";
    }while(add_type != "Flat" && add_type != "House" && add_type != "Plot");

    string add_address;
    cout << "Please input the address: ";
    getline(cin, add_address);
    string add_owner;
    cout << "Please input the owner: ";
    getline(cin, add_owner);
    float add_price;
    do
    {
        cout << "Please input the price: ";
        cin >> add_price;
    } while (ErrorCheck(cin));
    float add_area;

    do
    {
        cout << "Please input the area: ";
        cin >> add_area;
    } while (ErrorCheck(cin));
    if (add_type == "Flat")
    {
        int add_numRooms, add_floor;
        cout << "Please input the number of rooms: ";
        cin >> add_numRooms;
        cout << "Please input the floor the flat is on: ";
        cin >> add_floor;
        Estate* e = new Flat(add_address, add_owner, add_price, add_area, add_numRooms, add_floor);
        this->r_estate.push_back(e);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else if (add_type == "House")
    {
        int add_numRooms, add_numFloor;
        cout << "Please input the number of rooms: ";
        cin >> add_numRooms;
        cout << "Please input the number of floors the house has: ";
        cin >> add_numFloor;
        float add_yardArea;
        cout << "Please input the area of the yard: ";
        cin >> add_yardArea;
        Estate* e = new House(add_address, add_owner, add_price, add_area, add_numRooms, add_numFloor, add_yardArea);
        this->r_estate.push_back(e);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        vector<Communication> com;
        com.resize(5,none);
        Estate* e = new Plot(add_address, add_owner, add_price, add_area, com);
        e->SetCom();
        this->r_estate.push_back(e);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void RealEstate::RemoveEstate()
{
    cout << "To remove an estate you need to input its type, owner and address!";
    vector<Estate*> to_remove, to_remove1, to_remove2, to_remove3;
    to_remove1 = this->searchType();
    to_remove2 = this->searchAddress("remove");
    to_remove3 = this->searchOwner();


    for (int i = 0;i < to_remove1.size() ;i++ )
    {
        for (int j = 0;j < to_remove2.size() ;j++ )
        {
            if (to_remove1[i] == to_remove2[j])
                for (int k = 0;k < to_remove3.size() ;k++ )
                {
                    if (to_remove1[i] == to_remove1[k])
                    {
                        to_remove.push_back(to_remove1[j]);
                        break;
                    }

                }
        }
    }

    vector<int> pos;
    for (int i = 0;i < this->r_estate.size() ;i++ )
    {
        for (int j = 0;j < to_remove.size() ;j++ )
        {
            if (this->r_estate[i] == to_remove[j])
            {
                delete this->r_estate[i];
                pos.push_back(i);
                break;
            }
        }
    }

    for (int i = 0;i < pos.size() ;i++ )
    {
        this->r_estate.erase(this->r_estate.begin()+pos[1]);
    }

}

void RealEstate::TypeSort()
{
    vector<Estate*> v(this->searchType());
    int i, j, flag = 1;
    Estate* temp;
    int vLength = v.size( );
    for(i = 0; (i < vLength) && flag; i++)
    {
        flag = 0;
        for (j=0; j < (vLength -1); j++)
        {
            if (v[j+1]->GetPrice() > v[j]->GetPrice())
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                flag = 1;
            }
        }
    }
    for (int i = 0;i < vLength ;i++ )
    {
        v[i]->print();
    }
}

vector<Estate*> RealEstate::PrintAddress()
{
    vector<Estate*> v(this->searchAddress());
    int vLength = v.size( );
    for (int i = 0;i < vLength ;i++ )
    {
        v[i]->print();
    }
    return v;
}


















