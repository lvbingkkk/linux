#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    //创建一个信号集
    sigset_t set;

    //初始化一个空的信号集
    sigemptyset(&set);     
    //将指定信号添加到集合中
    sigaddset(&set, SIGINT);

    while (1)
    {
        //将set信号集添加到 信号阻塞集中
        sigprocmask(SIG_BLOCK, &set, NULL);
        for(i=0; i<=5; i++)
        {
            printf("SIGINT signal is blocked\n");
            sleep(1);
        }

        //将set信号集从 信号阻塞集中 删除
        sigprocmask(SIG_UNBLOCK, &set, NULL);
        for(i=0; i<=5; i++)
        {
            printf("SIGINT signal is unblocked\n");
            sleep(1);
        }
    }
    

    
    return 0;
}