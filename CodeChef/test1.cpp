#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,m;
        cin >>n>>m;
        int a[n][m];
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>a[i][j];
            }
        }
        int c=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x=0,y=0;
                int mn = min(min(i,j),min(n-i-1,m-j-1));
                for (int k = 1; k <= mn; k++)
                {
                    if(a[i][j-k]==a[i][k+j])
                        x++;
                    if(a[i-k][j]==a[i+k][j])
                        y++;
                }
                c+=min(x,y)+1;
            }
        }
        cout<<c<<endl;
    }
}
