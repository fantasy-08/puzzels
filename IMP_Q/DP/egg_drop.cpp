#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k) {
  if(k<=1)
      return k;
  if(n==1) {
    return k;
  }
  
  int ans = INT_MAX;
  for(int i=1;i<=k;i++) {
    int temp = max(eggDrop(n-1,k-1), eggDrop(n, k-i));
    ans = min(ans, temp);
  }
  
  return ans;
}

int main() {
 
  
  
  return 0;
}
