#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <string.h>

int main(int argc, char const *argv[])
{
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("fail to pipe");
        exit(1);
    }

    pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fail to fork");
        exit(1);
    }
    else if (pid > 0)
    {
        char buf[128] = {};
        pid_t ppid;
        ppid = getpid();
        printf("the size of buf is: %lu\n", sizeof(buf));

        printf("the pid is: %d\n", pid);
        printf("the ppid is: %d\n", ppid);

        while (1)
        {
            //标注输入端输入
            fgets(buf, sizeof(buf), stdin);
            //去掉 回车
            buf[strlen(buf) -1] = '\0';

            if (write(pipefd[1], buf, sizeof(buf)) == -1)
            {
                perror("fail to write");
                exit(1);
            }            
        }        
    }
    else
    {
        char buff[128] = "";
        while (1)
        {
            if(read(pipefd[0], buff, sizeof(buff)) == -1)
            {
                perror("fail to read");
                exit(1);
            }

            printf("from parent: %s\n", buff);
        }
        
    }
    
    
    

    
    return 0;
}