#include "Person.h"
#include "string.h"
#include "stddef.h"

static const char *COUNTRIES_STR[] =
{
  "Denmark",
  "Dominican Republic",
  "Finland",
  "Germany",
  "Poland",
  "Sweden"
};

//Functions
Country strToCountry(const char *str)
{
  for(size_t i = 0; i < COUNTRY_UNDEFINED; ++i)
  {
    if(!strcmp(str, COUNTRIES_STR[i]))
    {
      return i;
    }
  }
  return COUNTRY_UNDEFINED;
}


