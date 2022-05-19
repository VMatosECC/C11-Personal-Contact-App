// C11-Personal-Contact-App.cpp 

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct PersonalContact
{
    string  name;
    string  phone;
    string  email;
};

void showVector(vector<PersonalContact> v);
void findPersonByName(vector<PersonalContact> v);

int main()
{
    string nameValue, phoneValue, emailValue;
    PersonalContact p;
    vector<PersonalContact> v;

    //ask user for data
    do
    {
        cout << "\nEnter contact name [xxx end]: ";
        getline(cin, nameValue);
        if (nameValue == "xxx") break;
        cout << "Enter phone number:           ";
        getline(cin, phoneValue);
        cout << "Enter email:                  ";
        getline(cin, emailValue);

        p.name  = nameValue;
        p.phone = phoneValue;
        p.email = emailValue;

        v.push_back(p);

    } while (true);

    showVector(v);

    //search by name
    findPersonByName(v);
}

// ------------------------------------------------------

void showVector(vector<PersonalContact> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].name << "\t" << v[i].phone << "\t" << v[i].email << endl;
    }
}

void findPersonByName(vector<PersonalContact> v)
{
    bool found = false;
    string nameValue;
    do
    {
        cout << "\nEnter contact name [xxx end]: ";
        getline(cin, nameValue);
        if (nameValue == "xxx") break;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i].name == nameValue)
            {
                cout << v[i].name << "\t" << v[i].phone << "\t" << v[i].email << endl;
                found = true;
            }
        }
        if (!found) cout << "Person not found\n";
        found = false;

    } while (true);
}