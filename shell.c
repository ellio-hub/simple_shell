#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
#include <signal.h>


int read_args(char* args[])
{
size_t len = 50;
char *line = NULL;
char *e = "exit";
int l = 0;
int i = 0;
while (l <= 1)
{
printf("($)");
l = getline(&line, &len, stdin);
}
line[l-1] = '\0';
if (line == e)
exit(0);
args[i] = strtok(line, " ");
while (args[i] != NULL)
{
i++;
args[i] = strtok(NULL, " ");
}
return (1);
}
int execute(char* args[])
{
pid_t pid = fork();
if (pid == 0)
execvp(args[0], args);
else
waitpid(pid,0,0);
return (1);
}
int main (void)
{
signal(SIGINT,SIG_IGN);  
char* args[100];
while(read_args(args))
execute(args);
}
