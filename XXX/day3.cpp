
#include <iostream>
#define lli long long int
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,flag=0,temp=0;
	    cin>>n;
	    //cout<<"in";
	    while(1){
	        temp=~n;
	        if(temp==0)break;
	        n-=temp;
	        flag=~flag;
	    }
	    cout<<flag<<endl;
	}
	return 0;
}

