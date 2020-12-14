//---------------------------------------------------
// Purpose: Declaration of pokemon class.
// Authors: John Gauch
//---------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

const bool DEBUG = false;

class pokemon
{
public:
    // Constructors
    pokemon();
    pokemon(int number, string name, int grade,
            string edition, float purchase, float sale);
    pokemon(const pokemon & param);
    ~pokemon();

    // Setters
    void setNumber(int number);
    void setName(string name);
    void setGrade(int grade);
    void setEdition(string edition);
    void setPurchasePrice(float purchase);
    void setSalePrice(float sale);

    // Getters
    int getNumber();
    string getName();
    int getGrade();
    string getEdition();
    float getPurchasePrice();
    float getSalePrice();

    // Other
    void read(ifstream & din);
    void write(ofstream & dout);
    void print();

private:
    int Number;
    string Name;
    int Grade;
    string Edition;
    float PurchasePrice;
    float SalePrice;
};
