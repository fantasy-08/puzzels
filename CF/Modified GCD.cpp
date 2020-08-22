
// Problem : C. Modified GCD
// Contest : Codeforces - Codeforces Beta Round #67 (Div. 2)
// URL : https://codeforces.com/contest/75/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
int a, b, l ,r;
set<int, greater<int> > t;
int main()
{
    scanf("%d %d", &a, &b);
    a = __gcd(a, b);
    for (int i = 1; i * i <= a; ++i)
        if (a % i == 0)
        {
            t.insert(i);
            t.insert(a / i);
        }
    scanf("%d", &b);
    while (b--)
    {
        scanf("%d %d", &l, &r);
        a = *lower_bound(t.begin(), t.end(), r, greater<int>());
        printf(a > r || a  < l ? "-1\n" : "%d\n", a);
    }
    return 0;
}