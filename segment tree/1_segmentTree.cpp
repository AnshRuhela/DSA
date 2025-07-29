#include<bits/stdc++.h>
using namespace std;

void buildTree(int seg[],int arr[],int low,int high,int ind)
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    buildTree(seg,arr,low,mid,2*ind+1);
    buildTree(seg,arr,mid+1,high,ind*2+2);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

// querry for returning the minimum from in range of (l-r)
int query(int seg[],int arr[],int low,int high,int l,int r,int ind)
{
     if(r<low || l>high) // no overlap
     {
        return INT_MAX;
     }
     else if(l<=low && high<=r)
     {
        return seg[ind];
     }
     else
     {
        int mid=(low+high)/2;
        int left=query(seg,arr,low,mid,l,r,ind*2+1);
        int right=query(seg,arr,mid+1,high,l,r,ind*2+2);
        return min(left,right);
     }
}


void update(int seg[],int arr[],int low,int high,int i,int val,int ind)
{
    if(arr[i]!=val) // array ki value update kardi.
    {
        arr[i]=val;
    }
    if(low==high)
    {
        seg[ind]=val;
        return;
    }
    int mid=(low+high)/2;
    if(i<=mid) // goto left
    {
        update(seg,arr,low,mid,i,val,ind*2+1);
    }
    else // goto right
    {
        update(seg,arr,mid+1,high,i,val,ind*2+2);
    }
    seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
}


int main(){
    int n;
    cout<<"enter array length\n";
    cin>>n;
    cout<<"enter array\n";
    int arr[n];
    int seg[(4*n)+1];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    buildTree(seg,arr,0,n-1,0);

    while(1)
    {
        int flag;
        cout<<"1 for query,  2 for update,  0 for exit\n";
        cin>>flag;
        if(flag==0)
        break;
        if(flag==1)
        {
            int l,r;
            cout<<"enter range \n";
            cin>>l;
            cin>>r;
            cout<<"minimum in range is : "<<query(seg,arr,0,n-1,l,r,0)<<endl;
        }
        else if(flag==2)
        {
            int i,val;
            cout<<"enter index and value\n";
            cin>>i;
            cin>>val;
            update(seg,arr,0,n-1,i,val,0);
            cout<<"updated array is : ";
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            break;
        }
    }
    return 0;
}