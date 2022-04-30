#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>


void handler(int sig)
{
    if(sig == SIGINT)
    {
        printf("SIGINT正在处理\n");
    }
    if(sig == SIGQUIT)
    {
        printf("SIGQUIT正在处理\n");
    }
    if(sig == SIGTSTP)
    {
        printf("SIGTSTP正在处理\n");
    }
}

int main(int argc, char const *argv[])
{
    
    //以用户自定义方式处理信号
#if 1
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        perror("Fail to signal");
        exit(1);
    }
    if (signal(SIGQUIT, handler) == SIG_ERR)
    {
        perror("FAIL TO SIGNAL");
        exit(1);
    }
    if (signal(SIGTSTP, handler) == SIG_ERR)     
    {
        perror("FAIL TO SIGNAL");
        exit(1);
    }   
    
#endif

    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }    
    
    return 0;
}
