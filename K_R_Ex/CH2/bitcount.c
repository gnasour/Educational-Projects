/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void
bitcount (unsigned x)
{
  int i = 0;

  for (i; x != 0; x &= (x - 1))
    {
      i++;
    }

  printf ("%d\n", i);
}

int
main ()
{
  unsigned x = 56;

  for (int i = 0; x > 0; x &= (x - 1))
    {

    }

  return 0;
}
