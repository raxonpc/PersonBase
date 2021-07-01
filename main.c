#include "Person.h"

int main(int argc, char* argv[])
{
  if(argc > 1)
  {
    FILE *file = fopen(argv[1], "r");
    if(file)
    {
      Person* person = readPersonFromFile(file);
      getc(stdin); //breakpoint
    }
  }

  return 0;
}
