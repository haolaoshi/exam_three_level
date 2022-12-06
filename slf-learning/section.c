#include <stdio.h>
/*程序员的自我修养*/
int global_init_var = 84;
int un_assignment;

void funcl(int i)
{
    printf("%d\n",i);
}
int main(void)
{
    static int static_var = 85;
    static int static_var2;
    int a = 1;
    int b;
    funcl(un_assignment + static_var2 + a + b );
    return 0;
}
