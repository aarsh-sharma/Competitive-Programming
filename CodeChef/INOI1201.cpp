#include<bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d",&a)
typedef long long ll;

int main() {
	int n;
	sc(n);
	int a[n], b[n], atotal = 0;
	for (int i = 0; i< n;i++) {
		int temp = 0;
		sc(a[i]);
		atotal += a[i];
		for(int j = 0;j<2;j++) {
			int temp2;
			sc(temp2);
			temp += temp2;
		}
		temp += a[i];
		b[i] = temp;
	}
	ll min = 1000000000;
	for (int i = 0;i< n;i++) {
        // cout<<(b[i] + atotal - a[i])<<endl;
		if((b[i] + atotal - a[i]) < min)
            min = b[i] + atotal - a[i];
	}
	for(int i = 0; i < n; i++) {
		if(min < b[i])
			min = b[i];
	}
	cout<<min;
}