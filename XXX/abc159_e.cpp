
// Problem : E - Dividing Chocolate
// Contest : AtCoder - AtCoder Beginner Contest 159
// URL : https://atcoder.jp/contests/abc159/tasks/abc159_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

 
#if __has_include("debug.h")
    #include "debug.h"
#else
    #include<bits/stdc++.h>
    using namespace std;
 
    #define p(str) 7
    #define o(str) 42
    #define fundri 108
    #define d(...) 1729
#endif
 
typedef unsigned int ui;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const bool testcases = 0;
#define ff first
#define ss second
#define nl cout<<'\n'
#define pb push_back
#define pop pop_back
#define sz(cont) cont.size()
#define all(s) s.begin(),s.end()
#define lb(a,x) lower_bound(all(a),x)
#define ub(a,x) upper_bound(all(a),x)
#define test int __T__=1;if(testcases)cin>>__T__;while(__T__--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define make_unique(vec) sort(all(vec));vec.erase(unique(all(vec)),vec.end())
#define sort_by(cont,expr) sort(all(cont),[&](const auto &lhs,const auto &rhs){return expr;})
 
// copied macro - start
template<typename T>struct number_iterator : iterator<random_access_iterator_tag,T>
{T u;number_iterator(T v): u(v){}operator T&(){return u;}T operator *()const{return u;}};
template<typename T>struct number_range
{T l,r;number_range(T b,T e):l(b),r(e){}number_iterator<T> begin(){return l;}number_iterator<T> end(){return r;}};
template<typename T>number_range<T> range(T e){return number_range<T>(0,e);}
template<typename T>number_range<T> range(T b,T e){if(b>e)return number_range<T>(-b+1,-e+1);return number_range<T>(b,e);}
// copied macro - end
 
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,l,r) for(int i=l;i<r;i++)
#define rrep(i,n) for(int i=n;~i;i--)
#define rloop(i,r,l) for(int i=r;i>l;i--)
 
ll seed;auto random_address=[]{char *p=new char;delete p;return (uint64_t)p;};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()*(random_address()|1));
inline int rnd(int l=0,int r=INT_MAX){return uniform_int_distribution<int>(l,r)(rng);}
 
template<typename T,typename U>inline bool exist(T cont,U val){return cont.find(val)!=cont.end();}
template<typename T>bool isPrime(T n){for(T i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
template<typename TAIL>inline void inp(TAIL& T){cin>>T;}
template<typename HEAD,typename... TAIL>inline void inp(HEAD &H,TAIL&... T){cin>>H;inp(T...);}
template<typename T>inline bool in_range(T a,T l,T r){return (a>=l&&a<=r);}
template<typename T,typename U>inline istream& operator >>(istream& in,pair<T,U> &a){in>>a.ff>>a.ss;return in;}
template<typename T>inline istream& operator >>(istream& in,vector<T> &a){for(auto &x : a)in>>x;return in;}
 
/***
   * __builtin_clz(num) --> clz = count leading zero’s
   * __builtin_ctz(num) --> ctz = count trailing zeros
   * inline int RightOne(int x){return (__builtin_ctz(x)+1);}
   * inline int LeftOne(int x){return (__builtin_clz(INT_MAX) - __builtin_clz(x)+1);}
***/
int num_to_bits[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int popcount(ll num){int nibble;ll ans=0;do{nibble=num&0xf;ans+=num_to_bits[nibble];num>>=4;}while(num);return ans;}
inline void set(int &x,int pos){x|=(1LL<<pos);}
inline void reset(int &x,int pos){x&=~(1LL<<pos);}
inline bool atpos(int x,int pos){return ((x&(1LL<<pos))!=0);}
 
 
vector<string> a;
 
int main()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time, end_time;
    start_time = std::chrono::high_resolution_clock::now();
 
    #ifdef DHRUV_GHEEWALA
        freopen("INPUT.txt","r",stdin);
        freopen("OUTPUT.txt","w",stdout);
        freopen("DEBUG.txt","w",stderr);
    #endif
   
    fast;
    int h,w,k,n;
    test{
 
    inp(h,w,k);
    a.resize(h);
    rep(i,h)
        cin>>a[i];
 
    vector<vi> b(w);
    int _k,min_cut=INT_MAX;
    for(int mask : range(0,1<<(h-1)))
    {
        // n is total segments
        // hence n-1 will be total horizontal cuts
        n=popcount(mask)+1;
        rep(i,w)
            b[i].assign(n,0);
 
        for(int i : range(w))
        {
            ll sum;
            sum=_k=0;
            for(int j : range(h))
            {
                sum+=a[j][i]-'0';
                if(atpos(mask,j))
                {
                    b[i][_k++]=sum;
                    sum=0;
                }
            }
            b[i][_k]=sum;
            // d(i,b[i]);
        }
 
        vi sum(n,0);
        int ver_cut=0;
        bool f;
        d(b);
        rep(i,w)
        {
            f=0;
            for(int j : range(n))
            {
                if(b[i][j]>k)
                {
                    ver_cut=w*h;
                    break;
                }
                if(sum[j]+b[i][j]>k)
                {
                    f=1;
                    break;
                }
                sum[j]+=b[i][j];
            }
            if(f)
            {
                ver_cut++;
                for(int j : range(n))
                    sum[j]=0;
                i--;
            }
        }
        d(mask,ver_cut,n);
        min_cut=min(min_cut,ver_cut+n-1);
    }
    cout<<min_cut,nl;
 
    fundri;
    }
 
    end_time = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
    o("\n\n======\n");
    if(elapsed_time<10000)
        o("Elapsed Time: "<<elapsed_time<<" ms\n");
    else
        o("Elapsed Time: "<<elapsed_time/1000<<" s\n");
 
    return 0;
}