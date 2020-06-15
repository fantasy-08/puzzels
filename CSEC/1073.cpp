
// Problem : Towers
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1073
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// https://cses.fi/problemset/task/1073/
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  multiset<int> s;
  while (n--) {
    cin >> x;
    auto it = s.lower_bound(x + 1);
    if (it == s.end()) s.insert(x);
    else {
      s.erase(it);
      s.insert(x);
    }
  }
  cout << s.size() << endl;
}