// 7 a - Page Replacement FIFO

#include <stdio.h>
int main()
{
  int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
  printf("Enter the length of reference string -- ");
  scanf("%d", &n);
  printf("\n Enter reference string --");
  for (i = 0; i < n; i++)
    scanf("%d", &rs[i]);
  printf("Enter no of frames--");
  scanf("%d", &f);
  for (i = 0; i < f; i++)
    m[i] = -1;
  printf(" the page replacement process is --\n");
  for (i = 0; i < n; i++)
  {
    for (k = 0; k < f; k++)
    {
      if (m[k] == rs[i])
        break;
    }
    if (k == f)
    {
      m[count++] = rs[i];
      pf++;
    }
    for (j = 0; j < f; j++)
      printf("\t %d", m[j]);
    if (k == f)
      printf("\t PF no-- %d", pf);
    printf("\n");
    if (count == f)
      count = 0;
  }
  printf("The no of page faults using FIFO are %d", pf);
}