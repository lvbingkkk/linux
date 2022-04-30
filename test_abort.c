#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h> //close
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    int num = 0;
    while (1)
    {
        printf("hello world\n");
        sleep(1);
        num++;
    
    
        if (num == 5)
        {
            //
            abort();
        }
    }
    
    return 0;
}