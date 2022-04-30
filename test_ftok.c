#include <stdio.h>
#include <stdlib.h>
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
    
    printf("key = %#x\n", mykey);

    
    return 0;
}