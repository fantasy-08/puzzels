#include<bits/stdc++.h>
#define int long long int
#define pb push_back
using namespace std;
vector<int>adj[100001];

int dp[10001][2][2];

int go(int node,bool vis,bool com)
{

	if(dp[node][vis][com]!=-1)return dp[node][vis][com];
    if(com)
    {
        int ans=1;
        for(auto child:adj[node])
        {
            ans+=go(child,true,false);
        }
        return dp[node][vis][com]=ans;
    }
    
    int A=1;
    for(auto child:adj[node])
    {
    	A+=go(child,true,false);	
    }
    int B=0;
    if(vis)
    {
	    for(auto child:adj[node])
	    {
	    	B+=go(child,false,false);
	    }    	
    }
    else
    {
    	B=INT_MAX;
    	for(auto child:adj[node])
    	{
    		int temp=go(child,false,true);
    		for(auto C2:adj[node])
    		{
    			if(C2==child)continue;
    			
    			temp+=go(C2,false,false);
    		} 
    		B=min(B,temp);   		
    	}
    }
    
    return dp[node][vis][com]=min(A,B);
}

void print(int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(auto v:adj[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
}
int32_t main()
{   
	memset(dp,-1,sizeof(dp)); 
    int node;
    cin>>node;
    
    queue<int>q;
    q.push(node);
    
    while(q.size())
    {
        int Node=q.front();
        q.pop();
        int n,temp;
        cin>>n;
        
        while(n--)
        {
            node++;
            cin>>temp;
            adj[Node].pb(node);
            q.push(node);
        }
    }
    
    
    int M;
    cin>>M;
    
    int my=go(1,false,false);
    // print(node);		
    if(adj[1].size()==0)
    {
        my=1;
    }
    cout<<my<<" ";
    if(my<=M)
    {
        cout<<"Mission Successful\n";
    }
    else
    {
        cout<<"Mission Unsuccessful\n";
    }
    
    return 0;
}
