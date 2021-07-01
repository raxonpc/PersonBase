#include "Person.h"

int main(int argc, char* argv[])
{
  FILE *file = NULL;
  Person *head = NULL;
  if(argc > 1)
  {
    file = fopen(argv[1], "r");
    if(file)
    {
      head = readPersonListFromFile(file);
      fclose(file);
    }
  }
  if(!file)
  {
    puts("Could not open a file");
  }

  readPersonList(head, NULL);

  return 0;
}
