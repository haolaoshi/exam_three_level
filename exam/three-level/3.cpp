#include <iostream>
#include <vector>


using namespace std;


class Solution{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() == 0)
            return 0;
        int ans = 0;
        int start = prices[0], end = prices[0];
        for(int i =0; i< prices.size(); i++)
        {
            if(prices[i] < start)
            {
                ans = max(ans, end - start);
                start = prices[i];
                end = prices[i];
            }
            else
            {
                end = max(end,prices[i]);
            }
        }
        ans = max(ans, end - start);
        return ans;
    }
};

int main()
{
    int m , d;
    cin>>m;
    cin>>d;
    vector<int> inbuf;
    string str;
    cin>>str;
    for(char c: str)
    {
        if(c == ',' ) continue;
        if(c >= '0' && c <='9')
            inbuf.push_back(c - '0');
    }

    Solution s;
    cout<<"Solution="<<m * s.maxProfit(inbuf)<<endl; 
   
   return 0;
}
