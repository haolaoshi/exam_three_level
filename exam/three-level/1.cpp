#include <iostream>
#include <string>
#include <cmath>


using namespace std;

long long convertToDec(char c)
{
    long long decNum;
    if(c > 'a' && c <= 'z')
        decNum = c - 87;
    else if(c >= 'A' && c <= 'Z')
        decNum = c - 29;
    else if(c >= '0' && c <= '9')
        decNum = c - 48;
    return decNum;
}

char convertToDec(long long c)
{
    long long objchar;

    if(c >= 10 && c <= 35)
        objchar = c + 87;
    else if(c>= 36 && c <= 61)
        objchar = c + 29;
    else if(c >= 0 && c <= 9)
        objchar = c + 48;
    return objchar;
}

int main()
{
    int src;
    int obj;
    string num;

    while(cin>>src>>obj>>num)
    {
        bool isNegative = false;
        if(num[0] == '-')
        {
            num.erase(0);
            isNegative = true;
        }

        long long decNum = 0;
        for(long long i = 0 ; i < num.size(); i++)
            decNum += convertToDec(num[i]) * pow(src,num.size()-1 -i);


        string strTmp;
        long long tmp;
        while(decNum >0)
        {
            tmp = decNum % obj;
            strTmp = convertToDec(tmp) + strTmp;
            decNum /= obj;
        }

        if(isNegative)
            strTmp = '-'+strTmp;

        cout <<strTmp <<endl;
    }

    return 0;
}

