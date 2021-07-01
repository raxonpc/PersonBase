#include "Person.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

static char *COUNTRIES_STR[] =
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

char* countryToStr(const Country country)
{
  if(country < 0 || country >= COUNTRY_UNDEFINED)
  {
    return "Undefined";
  }
  return COUNTRIES_STR[country];
}

bool isPersonValid(const Person *person)
{
  return person->name != NULL 
    && person->surname != NULL;
}

void readPersonList(const Person *head, FILE *file)
{
  if(file == NULL)
  {
    file = stdout;
  }
  while(head)
  {
    fputs("List:\n", file);
    if(isPersonValid(head))
    {
      fprintf(file, "Name: %s\nSurname: %s\nCountry: %s\n",
          head->name, head->surname, countryToStr(head->country));
      head = head->next;
    }
  }
}

char* readUntil(char delimiter, FILE *file)
{
  if(!file)
  {
    return NULL;
  }
  char buffer[1024] = {0};
  char ch = '\0';
  int count = 0;
  while((ch = fgetc(file)) != EOF && ch != delimiter)
  {
    buffer[count++] = ch;
  }
  char* str = malloc(sizeof(char) * count + 1);
  strcpy(str, buffer);
  return str;
}
