#include <bits/stdc++.h> 
using namespace std; 
  
#define MAX 100001 
#define SQRSIZE 400 
   
int query_blk_sz; 

struct Query { 
  
    int L; 
    int R; 
    int x; 
}; 
  
int frequency[MAX]; 
  
int blocks[SQRSIZE]; 
  
// Block size 
int blk_sz; 
  
  
int getblocknumber(int ind) 
{ 
    return (ind) / blk_sz; 
} 
  
int getans(int k) 
{ 
    int ans = 0; 
    int left_blk, right_blk; 
    left_blk = 0; 
    right_blk = getblocknumber(k); 
  
    if (left_blk == right_blk) { 
        for (int i = 0; i <= k; i++) 
            ans += frequency[i]; 
    } 
    else { 
        for (int i = 0; i <  
             (left_blk + 1) * blk_sz; i++) 
            ans += frequency[i]; 
  
        for (int i = left_blk + 1;  
             i < right_blk; i++) 
            ans += blocks[i]; 
        for (int i = right_blk * blk_sz; 
             i <= k; i++) 
            ans += frequency[i]; 
    } 
    return ans; 
} 
  
void add(int ind, int a[]) 
{ 
    frequency[a[ind]]++; 
  
    int block_num = getblocknumber(a[ind]); 
  
    blocks[block_num]++; 
} 
void remove(int ind, int a[]) 
{ 
    frequency[a[ind]]--; 
  
    int block_num = getblocknumber(a[ind]); 
  
    blocks[block_num]--; 
} 
bool compare(Query x, Query y) 
{ 
    if (x.L / query_blk_sz !=  
        y.L / query_blk_sz) 
        return x.L / query_blk_sz <  
               y.L / query_blk_sz; 
  
    return x.R < y.R; 
} 
void queryResults(int a[], int n, 
                  Query q[], int m) 
{ 
  
    query_blk_sz = sqrt(m); 
  
    sort(q, q + m, compare); 
  
    int currL = 0, currR = 0; 
  
    for (int i = 0; i < m; i++) { 
  
        int L = q[i].L, R = q[i].R, 
                x = q[i].x; 
  
        while (currR <= R) { 
            add(currR, a); 
            currR++; 
        } 
        while (currL > L) { 
            add(currL - 1, a); 
            currL--; 
        } 
  
        while (currR > R + 1) 
  
        { 
            remove(currR - 1, a); 
            currR--; 
        } 
        while (currL < L) { 
            remove(currL, a); 
            currL++; 
        } 
        printf("query[%d, %d, %d] : %d\n",  
               L, R, x, getans(x)); 
    } 
} 
int main() 
{ 
  
    int arr[] = { 2, 0, 3, 1, 4, 2, 5, 11 }; 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    blk_sz = sqrt(N); 
    Query Q[] = { { 0, 2, 2 }, { 0, 3, 5 }, 
                { 5, 7, 10 } }; 
  
    int M = sizeof(Q) / sizeof(Q[0]); 
      
    queryResults(arr, N, Q, M); 
    return 0; 
} 