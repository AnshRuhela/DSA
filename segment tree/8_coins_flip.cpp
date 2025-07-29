#include<bits/stdc++.h>
using namespace std;

class ST
{
    private:
    vector<int>sag,lazy;
    public:
    ST(int n)
    {
        sag.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int low,int high,int ind,int arr[])
    {
        if(low==high)
        {
            sag[ind]=arr[low];
            return;
        }    
        int mid=(low+high)/2;
        build(low,mid,ind*2+1,arr);
        build(mid+1,high,ind*2+2,arr);
        sag[ind]=sag[ind*2+1]+sag[ind*2+2];
    }

    int query(int low,int high,int ind,int l,int r)
    {

        if(lazy[ind]!=0)
        {
            sag[ind]=(high-low+1)-sag[ind];
            if(low!=high)
            {
                lazy[ind*2+1]=!lazy[ind*2+1];
                lazy[ind*2+2]=!lazy[ind*2+2];
            }
            lazy[ind]=0;
        }


        if(r<low || l>high)
        {
            return 0;
        }
        else if(low >= l && high <= r)
        {
            return sag[ind];
        }
        else
        {
            int mid=(low+high)/2;
            int left=query(low,mid,ind*2+1,l,r);
            int right=query(mid+1,high,ind*2+2,l,r);
            return left+right;
        }
    }

    void update(int low,int high,int ind,int l,int r)
    {
        if(lazy[ind]!=0)
        {
            sag[ind]=(high-low+1)-sag[ind];
            if(low!=high)
            {
                lazy[ind*2+1]=!lazy[ind*2+1];
                lazy[ind*2+2]=!lazy[ind*2+2];
            }
            lazy[ind]=0;
        }
        if(r<low || l>high)
        {
            return ;
        }
        else if(low >= l && high <= r)
        {
            sag[ind]=(high-low+1)-sag[ind];
            if(low!=high)
            {
                lazy[ind*2+1]=!lazy[ind*2+1]; // it means agar even times flip hua yani uske liye to updte hi nahi karna hai.
                lazy[ind*2+2]=!lazy[ind*2+2];
            }
        }
        else
        {
            int mid=(low+high)/2;
            update(low,mid,ind*2+1,l,r);
            update(mid+1,high,ind*2+2,l,r);
            sag[ind]=sag[ind*2+1]+sag[ind*2+2];
        }
    }
    

};

int main(){

    int n;
    cout<<"enter length of array\n";
    cin>>n;

    int arr[n];
    cout<<"enter array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ST sag(n);
    sag.build(0,n-1,0,arr);
    cout<<"fdf";
    int q;
    cout<<"enter number of queries\n";
    cin>>q;
    while(q--)
    {
        int type;
        cout<<"enter type of querry\n";
        cin>>type;
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<"enter range\n";
            cout<<sag.query(0,n-1,0,l,r)<<endl;
        }
        else
        {
            cout<<"enter range \n";
            int l,r;
            cin>>l>>r;
            sag.update(0,n-1,0,l,r);
            cout<<"updated\n";
        }
    }


    return 0;
}   