#include "Hashtable.h"

Hashtable::Hashtable()
{
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    this->table[c] = new std::vector<const char *>();
  }

  printf("Initialized!\n");
}

Hashtable::~Hashtable()
{
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    std::vector<const char *> *v = this->table[c];
    for(std::vector<const char *>::iterator it = v->begin(); it != v->end(); it++)
    {
      delete *it;
    }
    delete this->table[c];
  }
  printf("Deinitialized!\n");
}

Hashtable::Hashtable(const Hashtable & other)
{
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    this->table[c] = other.table[c];
  }
}

Hashtable& Hashtable::operator =(const Hashtable & other)
{
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    this->table[c] = other.table[c];
  }

  return *this;
}

int Hashtable::hash(const char * value)
{
  // printf("Hash of %s = %d\n", value, value[0]);
  int val = (value[0] - 'A') % TABLE_SIZE;
  return val;
}

void Hashtable::add(const char * value)
{
  int size = strlen(value);
  char * temp = new char[size];
  strcpy(temp, value);

  int index = hash(temp);
  this->table[index]->push_back(temp);
  printf("Added %s at %d\n", temp, index);
  // printf("Index %d new size = %ld", index, this->table[index]->size());
}

bool Hashtable::contains(const char * value)
{
  int index = hash(value);
  std::vector<const char *> * v = this->table[index];

  for(std::vector<const char *>::iterator it = v->begin(); it != v->end(); it++)
  {
    const char *t_val = *it;
    if(strcmp(t_val, value) == 0)
    {
      return true;
    }
  }

  return false;
}

int Hashtable::countOccupiedBuckets()
{
  int count = 0;
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    if(this->table[c]->size() > 0)
      count++;
  }
  return count;
}

int Hashtable::countElements()
{
  int count = 0;
  for(int c = 0; c < TABLE_SIZE; c++)
  {
    if(this->table[c]->size() > 0)
      count += this->table[c]->size();
  }
  return count;
}

