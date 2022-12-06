#include <iostream>
#include <string.h>


using namespace std;

class ValidateIP{
public:
	
	string getType(string &ip)
	{
		if(ip.find(".") >= 0 && check4(ip)) return "IPv4";
		if(ip.find(":") >= 0 && check6(ip)) return "IPv6";
		return "ERROR";
	}


	bool check4(string& ip)
	{
		int n = ip.length();
		int cnt = 0;


		char cs[1024] = {0};
		strcpy(cs,ip.c_str());
		for(int i = 0 ; i < n && cnt <= 3; )
		{
			int j = i , x = 0;
			while(j < n && cs[j] >= '0' && cs[j] <= '9' && x <= 255) 
				x = x * 10 + (cs[j++] - '0');
			if(i == j) 
				return false;
			if((j - i > 1 && cs[i] == '0') || (x  > 255))
				return false;
			i = j + 1;
			if(j == n ) 
				continue;
			if(cs[j] != '.')
				return false;
			cnt++;

		}
		return cnt == 3 && cs[0] != '.' && cs[n - 1] != '.';
	}


	bool check6(string& ip)
	{
		int n = ip.length();
		int cnt = 0;

		char cs[1024] = {0};
		strcpy(cs,ip.c_str());

		for(int i = 0 ; i < n && cnt <=7;)
		{
			int j = i;
			while(j < n && ((cs[j] >= 'a' && cs[j] <= 'f')|| (cs[j] >= 'A' && cs[j] <= 'F') || (cs[j] >= '0' && cs[j] <='9')))
				j++; 
			if(i == j || j -i > 4)
				return false;
			i = j + 1;

			if(j == n) 
				continue;
			if(cs[j] != ':')
				return false;
			cnt++;

		}
		return cnt == 7 && cs[0] != ':' && cs[n -1] != ':';
	}	
};


int main()
{
    string buffer;
    cin >> buffer;

	ValidateIP v;
    cout<< v.getType(buffer)<<endl;
    
    return 0;

}
