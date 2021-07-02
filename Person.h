#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>
#include <stdio.h>

enum Country
{
  COUNTRY_DENMARK,
  COUNTRY_DOMINICAN_REPUBLIC,
  COUNTRY_FINLAND,
  COUNTRY_GERMANY,
  COUNTRY_POLAND,
  COUNTRY_SWEDEN,
  COUNTRY_UNDEFINED,
  MAX_COUNTRY,
};
typedef enum Country Country;

struct Person
{
  char *name;
  char *surname;
  Country country;
  struct Person *next;
};
typedef struct Person Person;

//Functions
Country strToCountry(const char*);
char* countryToStr(const Country);
bool isPersonValid(const Person*);

void readPersonList(const Person*, FILE*);
void freePersonList(Person*);

Person* readPersonListFromFile(FILE*);


#endif /* PERSON_H */
