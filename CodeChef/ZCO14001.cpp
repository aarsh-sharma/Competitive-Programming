#include<bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )

const double pi=acos(-1.0);

typedef long long int ll;
typedef unsigned long long int ull;


int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n, h, temp;
	cin>>n>>h;
	int a[n];
	vector<int> v1;
	
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	do
	{
		cin>>temp;
		v1.push_back(temp);
	} while (temp);
	int pick = 0, pos = 0;
	
	for(int i = 0; i < v1.size(); i++)
	{
		if(v1[i] == 1){
			if(pos > 0)
				pos--;
		}
		else if(v1[i] == 2){
			if(pos < n-1)
				pos++;
		}
		else if(v1[i] == 3){
			if(a[pos] > 0){
				if(pick == 0){
					pick++;
					a[pos]--;
				}
			}
		}
		else if(v1[i] == 4){
			if(a[pos]<h){
				if(pick == 1){
					pick--;
					a[pos]++;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	
	
	
	return 0;
}
