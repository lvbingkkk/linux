#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    //创建子进程
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        perror("fail to fork");
        exit(1);
    }
    else if(pid > 0)    //父进程代码区
    {
        printf("this a parent process\n");

        //使用pause 阻塞等待捕捉信号
        pause();            
                
    }
    else    //子进程代码区
    {
        printf("this is son process\n");
        
        //子进程让 父进程5s后退出
        sleep(5);
        kill(getppid(), SIGINT);
        // kill(getppid(), SIGKILL);
    }

    
    return 0;
}