// 6 c - First Fit

#include <stdio.h>
#define MAX 25
int main()
{
  int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp;
  static int bf[MAX], ff[MAX];
  printf("\n\t Memory Management scheme-first fit:\n");
  printf("enter the number of blocks:");
  scanf("%d", &nb);
  printf("enter the number of files:\n");
  scanf("%d", &nf);
  for (i = 1; i <= nb; i++)
  {
    printf("block %d:", i);
    scanf("%d", &b[i]);
  }
  printf("enter the size of files:-\n");
  for (i = 1; i <= nf; i++)
  {
    printf("file %d:", i);
    scanf("%d", &f[i]);
  }
  for (i = 1; i <= nf; i++)
  {
    for (j = 1; j <= nb; j++)
    {
      if (bf[j] != 1)
      {
        temp = b[j] - f[i];
        if (temp >= 0)
        {
          ff[i] = j;
          break;
        }
      }
    }
    frag[i] = temp;
    bf[ff[i]] = 1;
  }
  printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragment");
  for (i = 1; i <= nf; i++)
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
  return 0;
}