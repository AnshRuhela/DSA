#include<bits/stdc++.h>
using namespace std;

void buildTree(int arr[],int seg[],int orr,int low , int high,int ind)
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return;
    }

    int mid=(high+low)/2;
    buildTree(arr,seg,!orr,low,mid,ind*2+1);
    buildTree(arr,seg,!orr,mid+1,high,ind*2+2 );
    
    if(orr)
    {
        seg[ind]=seg[ind*2+1]|seg[ind*2+2];
    }
    else{
        seg[ind]=seg[ind*2+1]^seg[ind*2+2];
    }
}

void update(int arr[],int seg[],int i,int val,int low,int high,int orr,int ind)
{

    if(low==high)
    {
        seg[ind]=val;
        return;
    }

    int mid=(low+high)/2;
    if(i<=mid)
    {
        update(arr,seg,i,val,low,mid,!orr,ind*2+1);
    }
    else
    {
        update(arr,seg,i,val,mid+1,high,!orr,ind*2+2);
    }

    if(orr)
    {
        seg[ind]=seg[ind*2+1]|seg[ind*2+2];
    }
    else{
        seg[ind]=seg[ind*2+1]^seg[ind*2+2];
    }
}

int main(){

    int n;
    cin>>n;
    int q;
    cin>>q;
    int size=pow(2,n);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int seg[4*n+1];
    
    int orr;
    if(n%2==0)
    {
        orr=0;
        buildTree(arr,seg,orr,0,size-1,0);
    }
    else
    {
        orr=1;
        buildTree(arr,seg,orr,0,size-1,0);
    }

    while(q)
    {
        int i,val;
        cin>>i;
        i--; // user given 1 based indxing we created it 0 based
        cin>>val; 
        update(arr,seg,i,val,0,size-1,orr,0); // orr upar set hogya hoga.
        cout<<seg[0]<<endl;
        q--;
    }


return 0;
}