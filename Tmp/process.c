#include<stdio.h>
#include<sys/socket.h>
#include<syslog.h>
#include<trace.h>

int main()
{

  int pid = fork();
  printf("%d", pid);

}
