#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <sys/types.h>
using namespace std;
int main()
{
char str[1024], *cp;
int pipefd[2];
pid_t pid,pid2;
int status, died,died1;
pipe (pipefd);
switch(pid=fork())
{
case -1: cout<<"can't fork\n";
         exit(-1);
case 0 :close(1); 
        dup (pipefd[1]); 
        close (pipefd[0]);
        execl ("/bin/cat","cat","f1.txt",NULL);

default://died1=wait(&status);
        cout<<"hello";
        pid2=fork();
        if(pid2==0)
        {
                close(0); 
                dup (pipefd[0]);
                close (pipefd[1]);
                execl("/bin/grep","grep","-i","abc",NULL);
        }
        else if(pid2==-1)
        {
                        cout<<"cant fork";
                exit(-1);
        }
        else
        {
                died=wait(&status);
                return 0;
        }
}
//return 0;
}
