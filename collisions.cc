// got 100/100 :D
# include <iostream>
using namespace std;
 
int main()
{
int t,n,m,c,collisions;
cin>>t;
while(t--)
{
cin>>n>>m;
char l[n][m];
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
cin>>l[i][j];
collisions=0;
for(int col=0;col<m;col++)
{
c=0;
for(int i=0;i<n;i++)if(l[i][col]=='1')c++;
collisions+=c*(c-1)/2;
}
cout<<collisions<<endl;
}//end of t-while
return 0;
} 
