#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/msg.h>    //msgget()
#include <sys/ipc.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //使用ftok函数获取键值
    key_t mykey;
    if ((mykey = ftok(".", 100)) == -1)
    {
        perror("fail to ftok");
        exit(1);
    }

    //使用msgget函数创建一个 消息队列.
    int msqid;
    if ((msqid = msgget(mykey, IPC_CREAT | 0666)) == -1)
    {
        perror("FAIL TO MSGGET");
        exit(1);
    }
    

    printf("msqid = %d\n",msqid);
    printf("key = %#x\n", mykey);

    system("ipcs -q");

    printf("*******************\n");
    
    //通过msgctl 函数删除消息队列
    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("FAIL TO MSGCTL");
        exit(1);
    }
    
    system("ipcs -q");
    
    return 0;
}