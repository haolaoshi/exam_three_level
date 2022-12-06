#include <stdio.h>



int strcpy(char* dst, const char* src)
{


    if(src == NULL || dst == NULL)
    {
        fprintf(stderr,"null is %s or %s\n",dst,src);
        return -1;
    }

    while(*src != '\0'   && dst ) 
    {
        *dst++ = *src++;
    }

   if(*src != '\0')
   {
      fprintf(stderr,"dst is too small \n");

   }
   *dst = '\0';

   return 0;
}


int main()
{
    char *p;// = "hello world!";
    char t[103] = {0};


    strcpy(t,p);

    printf("%s\n",t);

}
