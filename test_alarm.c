#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    unsigned int sec;
    sec = alarm(5);   //5秒后发出 SIGALRM 信号,默认终止调用该函数的进程.
    printf("sec = %d\n", sec);  //头次调用返回0

    sleep(3);

    sec = alarm(6); //如果alarm之前没设置其他时钟,则返回0;如果设置了则返回剩余时间;.如果第一个时钟未到时间就遇到第二个时钟,则第一个时钟清除,按照第二个时间向下运行
    printf("sec = %d\n", sec);

    while (1)
    {
        printf("hello world!\n");
        sleep(1);
    }
    
    return 0;
}