#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <string.h>

int main(int argc, char const *argv[])
{
    char recv[128] = "wo ai bei jing";
    // bzero(recv, sizeof(recv));

    // memset(recv, 'a', 4);
    // memset(recv, '0', 4);
    memset(recv, 0, 4);

    printf("the value of bzeroed is [%c]\n", recv[3]);
    printf("the size of recv is %d\n", sizeof(recv));

    
    return 0;
}