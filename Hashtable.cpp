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
    this->table[c]->clear();
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
  return value[0] % TABLE_SIZE;
}

void Hashtable::add(const char * value)
{
  int index = hash(value);
  this->table[index]->push_back(value);
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
