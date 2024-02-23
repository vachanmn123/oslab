// 1 - Forking Process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t child_pid;
  int status;
  // Create a child process
  child_pid = fork();
  if (child_pid < 0)
  {
    perror("Fork Failed\n");
    exit(1);
  }
  else if (child_pid == 0)
  {
    printf("Child Process (PID: %d) is running!\n", getpid());
    execlp("/bin/ls", "ls", "-l", NULL);
    perror("Exec failed");
    exit(1);
  }
  else
  {
    printf("Parent Process (PID: %d) created a child (PID:% d)\n ", getpid(), child_pid);
    wait(&status);
    if (WIFEXITED(status))
    {
      printf("Child Process (PID: %d) exited with status %d\n", child_pid, WEXITSTATUS(status));
    }
    else
    {
      printf("Child process (PID: %d) did not exitnormally\n", child_pid);
    }
  }
  return 0;
}