#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
char str[1024], *cp;
int pipefd[2],pipe2[2];
int arr[1002],arr1[1004];
int j = 0,a;
pid_t pid,pid2;
int status, died,died1;
pipe (pipefd);
pipe(pipe2);
switch(pid=fork())
{
case -1: printf("can't fork\n");
         exit(-1);
case 0 :close(1); 
        dup (pipefd[1]); 
        close (pipefd[0]);
        //execl ("/bin/cat","cat","f1.txt",NULL);
        for(int i=1;i<=10;i++)
        {
                //arr1[i]=i;
                write(pipefd[1],&i,sizeof(int));
        }
        write(pipefd[1],&j,sizeof(int));
        exit(0);
default:pid2=fork();
        if(pid2==0)
{
        close(0);
        dup(pipefd[0]);
        close(pipefd[1]);
        int nbytes;
        //for(int i=0;i<1000;i++)
        //{
        //      read(pipefd[0],arr,sizeof(int));
        //}
        //int a;
        read(pipefd[0],arr,sizeof(int)*11);
        for(int k=0;k<12;k++)
        {
                if(arr[k]==0)
                        break;
                else
                {
                        close(1);
                        dup(pipe2[1]);
                        close(pipe2[0]);
                        if(arr[k]%2!=0)
                        {
                                write(pipe2[1],&arr[k],sizeof(int));
                        }
                }
        }
        printf("%d %d %d\n",arr[0],arr[1],arr[2]);
        }
        else
        {
{
                pid_t pid3=fork();
                if(pid3==0)
                {
                        close(0);
                        dup(pipe2[0]);
                        close(pipe2[1]);
                        int arr2[13];
                        read(pipe2[0],arr2,sizeof(int)*11);
                        printf("%d %d",arr2[0],arr2[1]);
                }
        
        died=wait(&status);
        }
}
}
