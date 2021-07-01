#include "Person.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>

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
  fputs("----------List----------\n", file);
  while(head)
  {
    if(isPersonValid(head))
    {
      fprintf(file, "Name: %s\nSurname: %s\nCountry: %s\n",
          head->name, head->surname, countryToStr(head->country));
      head = head->next;
    }
  }
}

void freeStrings(int count, ...)
{
  va_list args;
  va_start(args, count);
  for(int i = 0; i< count; ++i)
  {
    char* arg = va_arg(args, char*);
    free(arg);
  }
  va_end(args);
}

void freePerson(Person *person)
{
  if(person)
  {
    freeStrings(2, person->name, person->surname);
    free(person);
  }
}

void freePersonList(Person *head)
{
  Person* current = head;
  while(head)
  {
    current = head->next;
    freePerson(head);
    head = current;
  }
}  

char* readUntil(char delimiter, FILE *file)
{
  if(!file || feof(file))
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

Person* readPersonFromFile(FILE *file)
{
  char* name = readUntil(',', file);
  char* surname = readUntil(',', file);
  char* country = readUntil('\n', file);
  if(!name || !surname || !country)
  {
    freeStrings(3, name, surname, country);
    return NULL;
  }
  Person* person = malloc(sizeof(Person));
  person->name = name;
  person->surname = surname;
  person->country = strToCountry(country);
  free(country);
  person->next = NULL;
  return person;
}  

Person* readPersonListFromFile(FILE *file)
{
  if(!file)
  {
    return NULL;
  }
  Person* head = NULL;
  Person** current = &head;
  while(!feof(file))
  {
    *current = readPersonFromFile(file);
    if(!current)
    {
      break;
    }
    current = &(*current)->next;
  }
  return head;
}
