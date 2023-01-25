#include <bits/stdc++.h>
using namespace std;
int digit[10];
int main(void) {
  int n , f;
  cin >> n >> f;

  for(int i = 1;i<=n;i++) {
    string w = to_string(i);
      for(int j = 0;j<w.length();j++) {
        digit[w[j] - '0']++;
      }
  }

  cout << digit[f];
} 