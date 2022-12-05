#include "chimchar.h"

using namespace std;

Chimchar::Chimchar()
{
    this->type = "Fire";
    this->weight = 0.5;
}

Chimchar::~Chimchar()
{
    cout << "Chimchar destructor" << endl;
}

void Chimchar::printData()
{
    cout << "Chimchar data" << endl;
    cout << "Type" << this->type << endl;
    cout << "Weigth" << this->weight << endl;
}