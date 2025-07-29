#include<bits/stdc++.h>
using namespace std;


void build(int freq[],int sag[],int low,int high, int ind)
{
    if(low==high)
    {
        sag[ind]=freq[low];
        return ;
    }
    int mid=(low+high)/2;
    build(freq,sag,low,mid,ind*2+1);
    build(freq,sag,mid+1,high,ind*2+2);
    sag[ind]=sag[ind*2+1]+sag[ind*2+2];
}


int query(int l,int r,int low,int high,int ind,int freq[],int sag[])
{
    if(low>r || high<l)
    {
        return 0;
    }
    else if(low>=l && high<=r)
    {
        return sag[ind];
    }
    else
    {
        int mid=(low+high)/2;
        int left=query(l,r,low,mid,ind*2+1,freq,sag);
        int right=query(l,r,mid+1,high,ind*2+2,freq,sag);
        return left+right;
    }
}

void update(int i,int val,int low,int high,int ind,int freq[],int sag[])
{
    if(low==high)
    {
        sag[ind]+=val;
        return;
    }

    int mid=(low+high)/2;
    if(i<=mid)
    {
        update(i,val,low,mid,ind*2+1,freq,sag);
    }
    else
    {
        update(i,val,mid+1,high,ind*2+2,freq,sag);
    }
    sag[ind]=sag[ind*2+1]+sag[ind*2+2];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    maxi++; // maxi++ jisse update me high maxi-1 pass ho .
    int freq[maxi]={0};
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    int sag[4*maxi]={0};

    build(freq,sag,0,maxi-1,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int elem=arr[i];
        freq[elem]--;
        update(elem,-1,0,maxi-1,0,freq,sag); // we passed -1 as val kuki sagment me minus karni hai.
        ans+=query(1,elem-1,0,maxi-1,0,freq,sag);
    }

    cout<<ans;




return 0;
}