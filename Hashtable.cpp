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
      delete [] *it;
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
  char * temp = new char[size + 1];
  strcpy(temp, value);

  int index = hash(temp);
  this->table[index]->push_back(temp);
  printf("Added %s at %d\n", temp, index);
  // printf("Index %d new size = %ld", index, this->table[index]->size());
}

bool Hashtable::remove(const char * value)
{
  int vectorIndex = this->contains(value) - 1;
  if(vectorIndex == 0)
  {
    return false;
  }

  int tableIndex = hash(value);
  std::vector<const char *> * v = this->table[tableIndex];

  //printf("Will delete %s at index %d\n", *(v->begin() + vectorIndex - 1), vectorIndex - 1);
  try
  {
    v->erase(v->begin() + vectorIndex);
  }
  catch(int e )
  {
    printf("Deletion Error: %d", e);
  }

  return true;
}

int Hashtable::contains(const char * value)
{
  int index = hash(value);
  std::vector<const char *> * v = this->table[index];

  index = 0;
  for(std::vector<const char *>::iterator it = v->begin(); it != v->end(); it++)
  {
    index++;
    const char *t_val = *it;
    if(strcmp(t_val, value) == 0)
    {
      return index;
    }
  }

  return 0;
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

