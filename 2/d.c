// 2 d - Round Robin

#include <stdio.h>
int main()
{
  int i, j, n, bu[10], wt[10], tat[10], t, ct[10], max;
  float att = 0, awt = 0, temp = 0;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    printf("\nEnter burst time for process %d: ", i + 1);
    scanf("%d", &bu[i]);
    ct[i] = bu[i];
  }
  printf("\nEnter the size of time slice: ");
  scanf("%d", &t);
  max = bu[0];
  for (i = 1; i < n; i++)
  {
    if (max < bu[i])
    {
      max = bu[i];
    }
  }
  for (j = 0; j < (max / t) + 1; j++)
  {
    for (i = 0; i < n; i++)
    {
      if (bu[i] != 0)
      {
        if (bu[i] <= t)
        {
          tat[i] = temp + bu[i];
          temp = temp + bu[i];
          bu[i] = 0;
        }
        else
        {
          bu[i] = bu[i] - t;
          temp = temp + t;
        }
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    wt[i] = tat[i] - ct[i];
    att += tat[i];
    awt = wt[i];
  }
  printf("\n\t PROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
  for (i = 0; i < n; i++)
  {
    printf("\nP%d\t\t %d\t\t %d\t\t %d", i + 1, ct[i], wt[i], tat[i]);
  }
  printf("Average Turnaround Time=%f\n", att / n);
  printf("Average Waiting Time=%f\n", awt / n);
}