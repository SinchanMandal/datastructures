/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll int
ll ind;
ll rec(vector<ll>&arr,ll k)
{
 ll i,j;
    vector<ll>temp;
    ll sum=0;
    temp=arr;
    for(i=ind;i>=0;i--)
    { 
        
        vector<ll>temp2;
        for(j=0;j<temp.size();j++)
        {
            if(temp[j]&(1ll<<i))
            {
              //  cout<<"KN"<<endl;
                temp2.push_back(temp[j]);
            }
        }
        if(temp2.size()>=k)
        {
           // cout<<"KM"<<endl;
            sum|=(1ll<<i);
            temp=temp2;
        }
        
    }
    return sum;
    
    }
int main()
{
   ll n,k,x,i;vector<ll>a;
   cin>>n>>k;
   for(i=0;i<n;i++)
   {cin>>x;
       a.push_back(x);
   }
   ll mx=0,j;
   for(i=0;i<n;i++)
   {
       for(j=31;j>=0;j--)
       {
           if(a[i]&(1LL<<j))
           {
               mx=max(mx,j);
               break;
           }
       }
       
   }
   cout<<mx<<endl;
   ind=mx;
   ll ans=rec(a,k);
   cout<<ans<<endl;
}
