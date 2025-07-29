#include<bits/stdc++.h>
using namespace std;


class SegmentTree
{
    private:
    vector<int>seg;
    public:

    SegmentTree(int n)
    {
         seg.resize((4*n)+1);
    }

    void buildTree(int arr[],int low,int high,int ind)
    {
        if(low==high)
        {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        buildTree(arr,low,mid,2*ind+1);
        buildTree(arr,mid+1,high,ind*2+2);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }

    // querry for returning the minimum from in range of (l-r)
    int query(int arr[],int low,int high,int l,int r,int ind)
    {
        if(r<low || l>high) // no overlap
        {
            return INT_MAX;
        }
        else if(l<=low && r>=high)
        {
            return seg[ind];
        }
        else
        {
            int mid=(low+high)/2;
            int left=query(arr,low,mid,l,r,ind*2+1);
            int right=query(arr,mid+1,high,l,r,ind*2+2);
            return min(left,right);
        }
    }

    void update(int arr[],int low,int high,int i,int val,int ind)
    {
        if(arr[i]!=val) // update the array value.
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
            update(arr,low,mid,i,val,ind*2+1);
        }
        else // goto right
        {
            update(arr,mid+1,high,i,val,ind*2+2);
        }
        seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
    }
};




int main(){
    int n1;
    cout<<"enter array1 length\n";
    cin>>n1;
    cout<<"enter array1\n";
    int arr1[n1];
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }

    int n2;
    cout<<"enter array2 length\n";
    cin>>n2;
    cout<<"enter array2\n";
    int arr2[n2];
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    SegmentTree t1(n1);
    t1.buildTree(arr1,0,n1-1,0);
    SegmentTree t2(n2);
    t2.buildTree(arr2,0,n2-1,0);


    while(1)
    {
        int flag;
        cout<<"1 for query,  2 for update,  0 for exit\n";
        cin>>flag;
        if(flag==0)
        break;
        if(flag==1)
        {
            int l1,r1,l2,r2;
            cout<<"enter array 1 querry\n";
            cin>>l1>>r1;
            cout<<"enter array 2 querry\n";
            cin>>l2>>r2;
            int mini=INT_MAX;
            mini=min(mini,min(t1.query(arr1,0,n1-1,l1,r1,0),t2.query(arr2,0,n2-1,l2,r2,0)));
           cout<<"minimum in both is : "<<mini<<endl;
        }
        else if(flag==2)
        {
           int arrno,ind,val;
           cout<<"enter array no , index and value\n";
           cin>>arrno>>ind>>val;
           if(arrno==1)
           {
            t1.update(arr1,0,n1-1,ind,val,0);
           }
           else
           {    
            t2.update(arr2,0,n2-1,ind,val,0);
           }
        }
        else{
            break;
        }
    }
    return 0;
}