#ifndef PERSON_H
#define PERSON_H

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
  char *name_;
  char *surname_;
  Country country_;
  struct Person *next_;
};
typedef struct Person Person;

Country strToCountry(const char*);

#endif /* PERSON_H */
