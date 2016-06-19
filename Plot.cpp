#include "Plot.h"

Plot::Plot() : Estate()
{
    this->SetType("Plot");
    for (int i = 0;i < 5 ;i++ )
    {
        this->com.push_back(none);
    }
}

Plot::Plot(string ad, string ow, float ar, float pr, vector<Communication> v_com) : Estate(ad, ow, ar, pr)
{
    this->SetType("Plot");
    this->com = v_com;
}

Plot::Plot(const Plot& other) : Estate(other)
{
    this->com = other.com;
}

void Plot::print() const
{
    cout << "Address: " << this->GetAddress() << endl;
    cout << "Owner: " << this->GetOwner() << endl;
    cout << "Price: " << this->GetPrice() << endl;
    cout << "Area: " << this->GetArea() << endl;
    if(this->com[0] == 1)
        cout << "Water: yes" << endl;
    else
        cout << "Water: no" << endl;
    if(this->com[1] == 2)
        cout << "Electricity: yes" << endl;
    else
        cout << "Electricity: no" << endl;
    if(this->com[2] == 3)
        cout << "Telephone: yes" << endl;
    else
        cout << "Telephone: no" << endl;
    if(this->com[3] == 4)
        cout << "Road: yes" << endl;
    else
        cout << "Road: no" << endl;
    if(this->com[4] == 5)
        cout << "Sewer: yes" << endl;
    else
        cout << "Sewer: no" << endl;

}

void Plot::SetCom()
{
    string answer;
    cout << "Please answer with yes or no!" << endl;

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
}

vector<Communication> Plot::GetCom() const
{
    vector<Communication> v;
    for (int i = 0;i < this->com.size() ;i++ )
    {
        v.push_back(this->com[i]);
    }
    return v;
}













