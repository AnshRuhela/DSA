#include<bits/stdc++.h>
using namespace std;

void update(int i,int val,int arr[],int fin[],int n)
{
    while(i<=n)
    {
        fin[i]+=val;
        i=i+(i&(-i));
    }
}


int findLowerBound(int n,int fin[])
{
    int curr=0,prevSum=0;
    for(int i=log2(n);i>=0;i--)
    {
        if(fin[curr+(1<<i)]+prevSum<n)
        {
            curr=curr+(1<<i);
            prevSum+=fin[curr];
        }
    }
    return curr+1;
}


int main(){

    int n;
    cout<<"enter length of array\n";
    cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];
    int fin[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        update(i,arr[i],arr,fin,n);
    }
    cout<<"finwik tree\n";
    for(int i=1;i<=n;i++)
    {
        cout<<fin[i]<<" ";
    }
    cout<<endl;
    int q;
    cout<<"enter number of queries\n";
    cin>>q;
    while(q--)
    {
        int num;
        cout<<"enter number\n";
        cin>>num;
        cout<<findLowerBound(num,fin)<<endl;
    }

return 0;
}   
// 1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2