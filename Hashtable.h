#include <stdio.h>
#include <vector>

#define TABLE_SIZE 26

class Hashtable
{
  private:
    std::vector<const char *> * table[TABLE_SIZE];

    int hash(const char * value);
  public:
    Hashtable();

    ~Hashtable();
    Hashtable(const Hashtable & other);
    Hashtable& operator =(const Hashtable & other);

    void add(const char * value);
    bool contains(const char * value);
};