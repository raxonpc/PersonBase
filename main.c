#include "Person.h"

int main()
{
  puts("Enter people data (end with EOF):");
  Person *head = readPersonListFromFile(stdin);

  FILE *file = fopen("../data.csv", "w");
  readPersonList(head, file);
  
  freePersonList(head);

  fclose(file);

  return 0;
}
