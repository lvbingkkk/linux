#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>

int main(int argc, char const *argv[])
{
    //使用ftok函数获取键值
    key_t mykey;
    if ((mykey = ftok(".", 100)) == -1)
    {
        perror("fail to ftok");
        exit(1);
    }
    
    printf("key = %#x\n", mykey);

    //通过shmget函数创建共享内存,返回一个共享内存标识符
    int shmid;
    if ((shmid = shmget(mykey, 500, IPC_CREAT | 0666)) == -1)
    {
        perror("FAIL TO SHMGET");
        exit(1);
    }

    printf("shmid = %d\n", shmid);
    system("ipcs -m");
    
    return 0;
}