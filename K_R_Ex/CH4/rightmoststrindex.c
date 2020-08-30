#include <stdio.h>
#include <string.h>

#define MAX 1000

int strindex(char *, char *);

int main()
{

  char string[] = "This is a test string a test poppers";
  printf("%d\n", rightmoststrindex(string, "string"));

  return 0;
}

int rightmoststrindex(char *string, const char *pattern)
{

  int i;
  int right_most_index;
  int pattern_len = strlen(pattern);
  int string_len = strlen(string);
  for (i = string_len; i != -1; i--)
  {
    if (pattern[pattern_len - 1] == string[i])
    {
      int j;
      i--;
      for (j = pattern_len - 2; j != -1 && i != -1; j--, i--)
      {
        if (pattern[j] != string[i])
        {
          break;
        }
        else if (j == 0 && pattern[j] == string[i])
        {
          return i;
        }
      }
    }
  }

  return -1;
}
