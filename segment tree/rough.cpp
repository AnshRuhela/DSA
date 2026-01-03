#include<bits/stdc++.h>
using namespace std;

class segmentTree
{
    private:
    vector<int>seg;
    public:
    segmentTree(int n)
    {
        seg.resize((4*n)+1);
    }

    void buildTree(vector<int>arr,int low,int high,int ind)
    {
        if(low==high)
        {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        buildTree(arr,low,mid,ind*2+1);
        buildTree(arr,mid+1,high,ind*2+2);
        seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
    }

    int query(vector<int>arr,int low,int high,int l,int r,int ind)
    {
        if(l>high || r<low)
        {
            return INT_MAX;
        }
        else if(low>=l && high<=r)
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


    void update(vector<int>arr,int low,int high,int i,int val,int ind)
    {
        if(arr[i]!=val)
        {
            arr[i]=val;
        }

        if(low==high)
        {
            seg[ind]=val;
        }
        int mid=(low+high)/2;
        if(i<=mid)
        {
            update(arr,low,mid,i,val,ind*2+1);
        }
        else
        {
            update(arr,mid+1,high,i,val,ind*2+2);
        }
        seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
    }

};

int main(){

return 0;
}