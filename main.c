#include "Person.h"

int main()
{
  puts("Enter people data (end with EOF):");
  Person *head = readPersonListFromFile(stdin);

  FILE *file = fopen("../file.txt", "w");
  readPersonList(head, file);
  
  freePersonList(head);

  return 0;
}
