#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
 
int T, N, A[maxn];
 
int main()
{
 
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
        if(N & 1) printf("Second\n");
        else{
            sort(A + 1, A + N + 1);
            bool ok = 1;
            for(int i = 1; i < N; i += 2)
                if(A[i] != A[i + 1]) ok = 0;
            if(!ok) printf("First\n");
            else printf("Second\n");
        }
    }
 
    return 0;
}