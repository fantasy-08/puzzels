#include<bits/stdc++.h>
#define int long long int
using namespace std;
string num;
vector<int>val;
void go(int pos,int bit,int v)
{
	if(pos==num.size())	
	{
		val.push_back(v);
		return ;
	}
	for(int i=0;i<num.size();i++)
	{
		if(((bit>>i)&1)==0)
		{
			go(pos+1,bit|(1<<i),v*10+(num[i]-'0'));
		}
	}
}
int32_t main()
{
	cin>>num;
	bool neg=false;
	if(num[0]=='-')num=num.substr(1),neg=true;
	go(0,0,0);
	int Temp;
	if(neg)
	{
		Temp=*max_element(val.begin(),val.end());
		Temp=-Temp;
	}
	else
	{
		Temp=*min_element(val.begin(),val.end());
	}
	cout<<Temp;
}