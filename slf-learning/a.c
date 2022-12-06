#include <stdio.h>
/*程序员的自我修养*/
extern int shared;

int main()
{
    int a = 100;
    swap(&a,&shared);
//    printf("%d , %d\n",a,shared);
}
