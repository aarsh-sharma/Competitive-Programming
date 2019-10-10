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

	int n;
	cin>>n;
	int a[n];
	
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	int nested_depth = 0, pos, max_sequence = 0, pos_for_max;
	int temp_depth = 0, temp_max_seq = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 1){
			temp_depth++;
			if(temp_depth > nested_depth){
				nested_depth = temp_depth;
				pos = i+1;
			}
		}
		else{
			temp_depth--;
		}
		if(temp_depth){
			temp_max_seq++;
		}
		else{
			if(temp_max_seq > max_sequence){
				max_sequence = temp_max_seq + 1;
				pos_for_max = i - max_sequence + 2;
			}
			temp_max_seq = 0;
		}
	}
	cout<<nested_depth<<" "<<pos<<" "<<max_sequence<<" "<<pos_for_max;
	return 0;
}
