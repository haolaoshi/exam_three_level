#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


struct code{
    int off;
    int len;
    char nextChar;
};


#define maxWindow 10
vector<code> vt;

int main()
{
    string str;
    cin>>str;
//    str="abcdbbccaaabaeaaabaee";
    int w1,w2;

    for(int i =0; i < str.length(); i++)
    {
        if((i +1) <= maxWindow) 
            w1 = i;
        else
            w1 = maxWindow;

        if((i + w1) < str.length())
            w2 = w1;
        else
            w2 = str.length() - i;

        printf("%d  %d  %d\n",w1,w2,i);

        string str1 = str.substr(i - w1, w1);
        string str2 = str.substr(i, w2);
        cout<<str1<<","<<str2<<endl;


        int off = -1;
        while(true)
        {
            if(w2 == 0) 
                break;

            string str3 = str2.substr(0,w2);

            off = str1.find(str3);
            cout<<str3<<"::"<<off<<"::"<<i + w2 <<endl;

            if(off != -1) 
                break;

            w2--;
            if(w2 <= 0) 
                break;

        }

        if(off != -1)
        {

            code cd;
            cd.len =w2;
            cd.off =w1 -off;
            cd.nextChar = str[i + w2];
            vt.push_back(cd);
            i+= w2;
        }

        else
        {
            code cd;
            cd.len = 0;
            cd.off = 0;
            cd.nextChar = str[i+w2];
            vt.push_back(cd);
        }
    }

    for(int i =0; i < vt.size(); i++)
    {
        printf("(%d,%d,%c)",vt[i].off,vt[i].len,vt[i].nextChar);
    }

    printf("\n");


}
