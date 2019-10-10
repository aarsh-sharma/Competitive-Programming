// #include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
inline ll rand(ll l, ll r){
  return l + rng() % (r - l + 1);
}


const int N = 1e5;

int main(int argc, char *argv[]) {
  // registerGen(argc, argv + 1);
  // int n = rand(1, N);
  int n = N-10;
  string path = "<^>v";
  for (int i = 0; i < n; ++i)
  {
    int choice = rand(0, 3);
    cout << path[choice];
    // cout << ">";
  }
  cout << "\n";
}