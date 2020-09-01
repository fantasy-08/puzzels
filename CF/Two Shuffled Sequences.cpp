/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main()
{
    int n;
    cin>>n;
    map<int,int>M;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        M[t]++;
    }
    vector<int>Inc,Dec;
    for(auto v:M)
    {
        if(v.second>2)
        {
            cout<<"NO";
            return 0;
        }
        else
        {
            Inc.push_back(v.first);
            if(v.second==2)
                Dec.push_back(v.first);
        }
    }
    reverse(Dec.begin(),Dec.end());
    cout<<"YES\n";
    cout<<Inc.size()<<endl;
    for(auto v:Inc)cout<<v<<" ";
    cout<<endl;
    cout<<Dec.size()<<endl;
    for(auto v:Dec)cout<<v<<" ";
    return 0;
}
