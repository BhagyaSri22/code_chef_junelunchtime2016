# include <iostream>
# include <map>
# include <math.h>

using namespace std;
//map<long int,long int>m;
long int fun(map<long int,long int>& m,long int n)
{
	long int p=n;
	// Print the number of 2s that divide n
    while (n%2 == 0)
    {
        //printf("%d ", 2);
        m[2]++;
        if(m[2]%2==0)return 2;
        n = n/2;
    }

    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i < p && n>0 ; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            //printf("%d ", i);
             m[i]++;
        if(m[i]%2==0)return i;
            n = n/i;
        }
    }
	return -1;
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
    {m[n]++;
        if(m[n]%2==0)return n;}
       // printf ("%d ", n);

}

long int a[100];
int main()
{
long int t,n,x;
int flag;
cin>>t;
while(t--)
{
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
//m.resize(0);
map<long int,long int>m;
flag=0;
for(int i=0;i<n;i++)
{
x=fun(m,a[i]);
if(x>0){flag=1;break;}
}
map<long int,long int>::iterator it;

cout<<x<<endl;
/*
for(it=m.begin();it!=m.end();it++)
{
	cout<<it->first<<'-'<<it->second<<'\n';
}*/
//else cout<<"x"<<endl;
}//whilt-t ends
	return 0;
}