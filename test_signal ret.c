#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>

void *ret_handler;

void handler(int sig)
{
    printf("*************************\n");
    printf("nihao beijing\n");
    printf("welcome to china\n");
    printf("**************************\n");

    //以当前信号上次处理方式,即默认方式处理信号
    if (signal(SIGINT, ret_handler) == SIG_ERR)
    {
        perror("fail to signal");
        exit(1);
    }
    
}

int main(int argc, char const *argv[])
{
    
    if((ret_handler = signal(SIGINT, handler)) == SIG_ERR)
    {
        perror("fail to signal");
        exit(1);
    }
        
    while (1)
    {
        printf("hello world\n");
        sleep(1);
    }    
    
    return 0;
}
