/*
 *i....C........Big_endian.....0...Little_endian.....1.
 *
 */

#include <stdio.h>
#include <stdlib.h>


int little()
{
    {
        union{

            int a;
            char b;
        }U;

        U.a = 1;
        return (U.b == 1);
    }
    
}


int main()
{

    if(little())
    {
        printf("Little\n"); 
    }
    else
    {
        printf("Big\n");     
    }

}

