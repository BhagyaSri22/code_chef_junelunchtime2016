#include <iostream>
using namespace std;
//long int n;
void f(int i,int j,long int g[1000][1000],long int *c,long int m,long int n)
{
	if(g[i][j]==1)return;
	int sum=0;
	g[i][j]=1;
	if(i-1>=0 && g[i-1][j]==1)sum++;
	if(i+1<m && g[i+1][j]==1)sum++;
	if(j-1>=0 && g[i][j-1]==1)sum++;
	if(j+1<m && g[i][j+1]==1)sum++;
	*c+=sum;
	//cout<<"sum val"<<sum<<' ';
}

int main()
{
long int t,m,n,l,si,sj,ll,lb,count;
cin>>t;
while(t--)
{
cin>>n>>m;
long int *c=&count;
count=0;//intialise
/*
vector<long int>v(n,0);//doent matter mxn nxm
vector< vector<long int> >g;
for(int i=0;i<m;i++)g.push_back(v);
*/
long int g[1000][1000];
for(int i=0;i<1000;i++)
{for(int j=0;j<1000;j++)
	g[i][j]=0;//cout<<g[i][j]<<' ';
//cout<<endl; 
}

//layer wise
l=(m+1)/2;
//cout<<l<<"l val";
for(int x=0;x<l;x++)
{
	si=sj=x;lb=m-2*x;ll=n-2*x;
f(si,sj,g,c,m,n);f(si+lb-1,sj,g,c,m,n);f(si,sj+ll-1,g,c,m,n);f(si+lb-1,sj+ll-1,g,c,m,n);
}
for(int x=0;x<l;x++)
{
si=sj=x;lb=m-2*x;ll=n-2*x;
//f(si,sj,g,c,m,n);f(si+lb-1,sj,g,c,m,n);f(si,sj+ll-1,g,c,m,n);f(si+lb-1,sj+ll-1,g,c,m,n);
//cout<<endl;
//top side of square
for(int j=sj;j<sj+ll;j++)
{
	f(si,j,g,c,m,n);
}//cout<<endl;
//bottom side of square
for(int j=sj;j<sj+ll;j++)
{
	f(si+lb-1,j,g,c,m,n);
}//cout<<endl;
//left side
for(int i=si;i<si+lb;i++)
{
	f(i,sj,g,c,m,n);
}//cout<<endl;
//right side of square
for(int i=si;i<si+lb;i++)
{
	f(i,sj+ll-1,g,c,m,n);
}//cout<<endl;

}//l;ayer loop
cout<<*c<<endl;
/*for(int i=0;i<m;i++)
{for(int j=0;j<n;j++)
	cout<<g[i][j]<<' ';
cout<<endl; }*/
}//end while
return 0;
}
