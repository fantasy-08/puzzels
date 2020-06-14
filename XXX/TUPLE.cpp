//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
vector<vector<pair<int,char>>>l,r;
bool is_one=true,is_two=true;
void gen_permutation  (int [], bool);
void print_permutation(bool);
void ANSWER_1(int []);
void answer_is_two(int [], int []);
void solve(){
	l.clear(),r.clear();
	int ini[3],final[3];
	FOR(i,3)cin>>ini[i];
	FOR(i,3)cin>>final[i];
	//answer 0
	if(ini[0]==final[0] && ini[1]==final[1] && ini[2]==final[2])
	{
		cout<<0<<endl;
		return ;
	}
	//answer 1
	gen_permutation(ini,true);
	ANSWER_1(final);
	if(is_one==true)return;
	
	//check for TWO!
	gen_permutation(final,false);
	
	answer_is_two(ini,final);
	if(is_two==true)return ;
	
	//NOT TWO THEREFORE THREE!!
	//3 is the answer
	cout<<3<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}

//function
void answer_is_two(int ini[],int final[])
{
	//l and r take both equation and solve;
	for(auto fp:l)
	{
		vector<int>second_point(3,0);
		bool done=false;
		for(int k=2;k<=3;k++)
		{
			if(done==true)break;
			for(int i=0;i<3;i++)
			{
				if(fp[i].se=='n')
				{
					second_point[i]=fp[i].ft;
				}
				else if(fp[i].se=='p')
				{
					second_point[i]=fp[i].ft+k;
				}
				else
					second_point[i]=fp[i].ft*k;
			}
			for(int i=0;i<3;i++)
				if(second_point[i]!=ini[i])
					done=true;
		}
		if(done==false)continue;
		for(int i=0;i<3;i++)
		{
			second_point[i]-=ini[i];//direction vector;
		}
		for(auto sp:r)
		{
			vector<int>second_point_r(3,0);
			bool done1=false;
			for(int k=2;k<=3;k++)
			{
				if(done1==true)break;
				for(int i=0;i<3;i++)
				{
					if(sp[i].se=='n')
					{
						second_point_r[i]=sp[i].ft;
					}
					else if(fp[i].se=='p')
					{
						second_point_r[i]=sp[i].ft+k;
					}
					else
						second_point_r[i]=sp[i].ft*k;
				}
				for(int i=0;i<3;i++)
					if(second_point_r[i]!=final[i])
						done1=true;
			}
			if(done1==false)continue;
			for(int i=0;i<3;i++)
			{
				second_point_r[i]-=final[i];//direction vector;
			}
			int ans_is_two_chk=0;
			for(int i=0;i<3;i++)
			{	
				if(second_point_r[i]==0 || second_point[i]==0)break;			
				int den=second_point_r[i]-second_point[i];
				if(den==0)
				{
					break;
				}
				int num=(ini[i]*second_point_r[i])-(final[i]*second_point[i]);
				if(num%den==0)
				{
					ans_is_two_chk+=1;
				}
				else
				{
					break;
				}
			}
			if(ans_is_two_chk==3)
			{
				cout<<2<<endl;
				// cout<<fp[0].ft<<"-"<<fp[0].se<<", "<<fp[1].ft<<"-"<<fp[1].se<<", "<<fp[2].ft<<"-"<<fp[2].se<<endl;
				// cout<<sp[0].ft<<"-"<<sp[0].se<<", "<<sp[1].ft<<"-"<<sp[1].se<<", "<<sp[2].ft<<"-"<<sp[2].se<<endl;
				return ;
			}
		}
	}
	is_two=false;
}
void gen_permutation(int arr[],bool L)
{
	if(L==true)
	l.pb({{arr[0],'p'},{arr[1],'p'},{arr[2],'p'}}),l.pb({{arr[0],'m'},{arr[1],'m'},{arr[2],'m'}});
	else 
	r.pb({{arr[0],'p'},{arr[1],'p'},{arr[2],'p'}}),r.pb({{arr[0],'m'},{arr[1],'m'},{arr[2],'m'}});
	//on one + t
	for(int i=0;i<3;i++)
	{
		pair<int,char>X,Y,Z;
		for(int j=0;j<3;j++)
		{
			if(i!=j)
			{
				if(j==0)      X.ft=arr[0],X.se='n';
				else if(j==1) Y.ft=arr[1],Y.se='n';
				else          Z.ft=arr[2],Z.se='n';
			}
		}
		if(i==0)      X.ft=arr[0],X.se='p';
		else if(i==1) Y.ft=arr[1],Y.se='p';
		else          Z.ft=arr[2],Z.se='p';
		if(L)l.pb({X,Y,Z});
		else r.pb({X,Y,Z});
		if(i==0)      X.ft=arr[0],X.se='m';
		else if(i==1) Y.ft=arr[1],Y.se='m';
		else          Z.ft=arr[2],Z.se='m';
		if(L)l.pb({X,Y,Z});
		else r.pb({X,Y,Z});
	}
	//on two
	for(int i=0;i<3;i++)
	{
		vector<pair<int,char>>temp(3),temp_m(3);
		for(int j=0;j<3;j++)
		{
			if(i==j)continue;
			//addition
			temp[i].ft=arr[i];
			temp[i].se='p';
			temp[j].ft=arr[j];
			temp[j].se='p';
			//multiply
			temp_m[i].ft=arr[i];
			temp_m[i].se='m';
			temp_m[j].ft=arr[j];
			temp_m[j].se='m';
			//no operation
			for(int k=0;k<3;k++)
			{
				if(k!=i && k!=j)
				{
					temp[k].ft=arr[k];
					temp[k].se='n';
					temp_m[k].ft=arr[k];
					temp_m[k].se='n';
				}
			}
		}
		if(L)
			l.pb(temp),l.pb(temp_m);
		else 
			r.pb(temp),r.pb(temp_m);
	}	
}
void ANSWER_1(int final[])
{
	for(auto v:l)
	{
		if(v[0].se=='p' && v[1].se=='p' && v[2].se=='p')
		{
			int t=final[0]-v[0].ft;
			if((v[1].ft+t==final[1]) && (v[2].ft+t==final[2]))
			{
				cout<<1<<endl;
				return ;
			}
			continue;
		}
		if(v[0].se=='m' && v[1].se=='m' && v[2].se=='m')
		{
			if(v[0].ft==0 || v[1].ft==0 || v[2].ft==0)
			{
				int len=0;
				int arr[3];
				if(v[0].ft!=0)
				{
					if(final[1]%v[1].ft==0)
					arr[len]=final[0]/v[0].ft,len++;
				} 
				if(v[1].ft!=0)
				{
					if(final[1]%v[1].ft==0)
					{
						arr[len]=final[1]/v[1].ft;
						len++;
					}
				} 
				if(v[2].ft!=0)
				{
					if(final[1]%v[1].ft==0)
					arr[len]=final[2]/v[2].ft,len++;
				} 
				if(len==1)
				{
					cout<<1<<endl;
					return ;
				}
				if(len==2)
				{
					if(arr[0]==arr[1]){
						cout<<1<<endl;
						return ;
					}
				}
				continue;
			}
			if(final[0]%v[0].ft || final[1]%v[1].ft || final[2]%v[2].ft) continue;
			int t1=final[0]/v[0].ft;
			int t2=final[1]/v[1].ft;
			int t3=final[2]/v[2].ft;
			if(t1==t2 && t2==t3 && t3==t1)
			{
				cout<<1<<endl;
				return ;
			}
			continue;
		}
		int t1=INT_MAX,t2=INT_MAX;
		bool is_ans_1=true;
		bool is_zero=false;
		for(int i=0;i<3;i++)
		{
			if(v[i].se=='n')
			{
				if(v[i].ft!=final[i])
				{
					is_ans_1=false;
					break;
				}
			}
			else if(v[i].se=='p')
			{
				if(t1==INT_MAX)
				{
					t1=final[i]-v[i].ft;
				}
				else
				{
					t2=final[i]-v[i].ft;
				}
			}
			else
			{
				if(v[i].ft==0)
				{
					is_zero=true;
					if(t1!=INT_MAX) t2=t1;
					else t1=0;
					continue;
				}
				if(final[i]%v[i].ft)
				{
					is_ans_1=false;
					break;
				}
				if(t1==INT_MAX)
				{
					t1=final[i]/v[i].ft;
				}
				else
				{
					t2=final[i]/v[i].ft;
				}
			}
		}
		if(is_zero==true && is_ans_1==true)
		{
			cout<<1<<endl;
			return ;
		}
		if(is_ans_1==false)continue;
		if(t1==t2)
		{
			cout<<1<<endl;
			return ;
		}
	}	
	is_one=false;
}
void print_permutation(bool L)
{
	if(L)
	{
		int s=1;
		for(auto v:l)
		{
			cout<<s<<" ";
			s++;
			for(auto value:v)
			{
				cout<<value.ft<<"->"<<value.second<<", ";
			}
			cout<<endl;
		}
	}
	else
	{
		int s=1;
		for(auto v:r)
		{
			cout<<s<<" ";
			s++;
			for(auto value:v)
			{
				cout<<value.ft<<"->"<<value.second<<", ";
			}
			cout<<endl;
		}
	}
}