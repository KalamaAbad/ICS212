#include "record.h"


class llist
{

private:
    record *    start;
    char        filename[20];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    llist(const llist &obj) throw();
    ~llist();
    void addRecord(int, char [ ],char [ ]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    friend std::ostream& operator<<(std::ostream& output, const llist &obj);
    llist& operator=(const llist& obj);
};

