//---------------------------------------------------
// Purpose: Implementation of pokemon class.
// Authors: John Gauch
//---------------------------------------------------

#include "pokemon.h"

string trim(string str)
{
    // Remove unwanted spaces at end of string
    int pos = str.length()-1;
    while ((pos > 0) && (isspace(str[pos]))) pos--;
    str.erase(pos+1);
    return str;
}

pokemon::pokemon()
{
    Number = 0;
    Name = "none";
    Grade = 0;
    Edition = "none";
    PurchasePrice = 0;
    SalePrice = 0;

}

pokemon::pokemon(int number, string name, int grade,
                 string edition, float purchase, float sale)
{
    Number = number;
    Name = name;
    Grade = grade;
    Edition = edition;
    PurchasePrice = purchase;
    SalePrice = sale;
}

pokemon::pokemon(const pokemon & param)
{
    Number = param.Number;
    Name = param.Name;
    Grade = param.Grade;
    Edition = param.Edition;
    PurchasePrice = param.PurchasePrice;
    SalePrice = param.SalePrice;
}

pokemon::~pokemon()
{
}

void pokemon::setNumber(int number)
{
    if (number >= 1 && number <= 102)
        Number = number;
    else
        cout << "Invalid pokemon number\n";
}

void pokemon::setName(string name)
{
    name = trim(name);
    if (name.length() > 0)
        Name = name;
    else
        cout << "Invalid pokemon name\n";
}

void pokemon::setGrade(int grade)
{
    if (grade >= 1 && grade <= 10)
        Grade = grade;
    else
        cout << "Invalid pokemon grade\n";
}

void pokemon::setEdition(string edition)
{
    edition = trim(edition);
    if (edition == "First" || edition == "Shadowless" || edition == "Unlimited")
        Edition = edition;
    else
        cout << "Invalid pokemon edition\n";
}

void pokemon::setPurchasePrice(float purchase)
{
    if (purchase >= 0)
        PurchasePrice = purchase;
    else
        cout << "Invalid pokemon purchase price\n";
}

void pokemon::setSalePrice(float sale)
{
    if (sale >= 0)
        SalePrice = sale;
    else
        cout << "Invalid pokemon sale price\n";
}

int pokemon::getNumber()
{
    return Number;
}

string pokemon::getName()
{
    return Name;
}

int pokemon::getGrade()
{
    return Grade;
}

string pokemon::getEdition()
{
    return Edition;
}

float pokemon::getPurchasePrice()
{
    return PurchasePrice;
}

float pokemon::getSalePrice()
{
    return SalePrice;
}

void pokemon::read(ifstream & din)
{
    string line;
    getline(din, line);
    if (din.eof()) return;
    setNumber(stoi(line));

    getline(din, line);
    if (din.eof()) return;
    setName(line);

    getline(din, line);
    if (din.eof()) return;
    setGrade(stoi(line));

    getline(din, line);
    if (din.eof()) return;
    setEdition(line);

    getline(din, line);
    if (din.eof()) return;
    setPurchasePrice(stof(line));

    getline(din, line);
    if (din.eof()) return;
    setSalePrice(stof(line));

    getline(din, line);
}

void pokemon::write(ofstream & dout)
{
    dout << Number << endl;
    dout << Name << endl;
    dout << Grade << endl;
    dout << Edition << endl;
    dout << PurchasePrice << endl;
    dout << SalePrice << endl;
    dout << endl;
}

void pokemon::print()
{
    cout << "Number:          " << Number << endl;
    cout << "Name:            " << Name << endl;
    cout << "Grade:           " << Grade << endl;
    cout << "Edition          " << Edition << endl;
    cout << "Purchase Price:  $"
         << fixed << setprecision(2) << PurchasePrice << endl;
    cout << "Sale Price:      $"
         << fixed << setprecision(2) << SalePrice << endl;
    cout << endl;
}