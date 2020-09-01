/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define int long long int
using namespace std;
// typedef int  long long int;
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0,bal=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')bal++;
            else
            {
                bal--;
                if(bal<0)bal=0,ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
