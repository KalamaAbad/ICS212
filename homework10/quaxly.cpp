#include "quaxly.h"

using namespace std;

Quaxly::Quaxly()
{
    this->type = "water";
    this->weight = 0.5;
}

Quaxly::~Quaxly()
{
    cout << "Quaxly destructor" << endl;
}

void Quaxly::printData()
{
    cout << "Quaxly data" << endl;
    cout << "Type" << this->type << endl;
    cout << "Weigth" << this->weight << endl;
}