#include "Person.h"

int main(int argc, char* argv[])
{
  if(argc > 1)
  {
    FILE *file = fopen(argv[1], "r");
    if(file)
    {
      char* str = readUntil('.', file);
      printf("Read string: %s\n", str);
    }
  }

  return 0;
}
