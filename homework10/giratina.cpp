#include "giratina.h"

using namespace std;

Giratina::Giratina()
{
    this->type = "Ghost-Dragon";
    this->weight = 2000;
}

Giratina::~Giratina()
{
    cout << "Giratina destructor" << endl;
}

void Giratina::printData()
{
    cout << "Giratina data" << endl;
    cout << "Type" << this->type << endl;
    cout << "Weigth" << this->weight << endl;
}