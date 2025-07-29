#include<bits/stdc++.h>
using namespace std;


class ST
{
    private:
    vector<int>st,lazy;
    public : 
    ST(int n)
    {
        st.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind,int low,int high,int arr[])
    {
        if(low==high)
        {
            st[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(ind*2+1,low,mid,arr);
        build(ind*2+2,mid+1,high,arr);
        st[ind]=st[ind*2+1]+st[ind*2+2];
    }

    void update(int ind,int low,int high,int l,int r,int val)
    {
        // first of all update the previous remaining updates and propagate downwards.
        if(lazy[ind]!=0)
        {
            st[ind]+=(high-low+1)*lazy[ind]; // (high-low) are the number of nodes it is have in downward.
            // propagate the lazy node downward for the ramaining nodes to get updated.
            if(low!=high) // means there are children below it 
            {
                lazy[2*ind+1]+=lazy[ind];
                lazy[2*ind+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        // if no overlap case
        if(l>high || r<low)
        {
              return;
        }

        // if complete overlap

        else if(low>=l && high<=r)
        {
            st[ind]+=(high-low+1)*val;

            // lazy propogate.
            if(low!=high)
            {
                lazy[ind*2+1]+=val;
                lazy[ind*2+2]+=val;
            }
            return;
        
        }
        else
        {
            int mid=(high+low)/2;
            update(ind*2+1,low,mid,l,r,val);
            update(ind*2+2,mid+1,high,l,r,val);
            st[ind]=st[ind*2+1]+st[ind*2+2];
        }
    }

    int query(int low,int high,int ind , int l,int r)
    {

        // just extra thing is, if any lazy update left compete it 

        if(lazy[ind]!=0)
        {
            st[ind]+=(high-low+1)*lazy[ind];
            if(low!=high)
            {
                lazy[ind*2+1]+=lazy[ind];
                lazy[ind*2+2]+=lazy[ind];
            }
            lazy[ind]=0;
        }

        if(r<low && l>high) // no overlap
        {
            return 0;
        }
        else if(low>=l && high<=r) // complete overlap
        {   
            return st[ind];
        }
        else // partial overlap
        {
            int mid=(low+high)/2;
            int left=query(low,mid,ind*2+1,l,r);
            int right=query(mid+1,high,ind*2+2,l,r);
            return left+right;
        }   
    }


};

int main(){

    int n;
    cout<<"enter length of array\n";
    cin>>n;
    int arr[n];
    cout<<"enter length\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    ST seg(n);
    seg.build(0,0,n-1,arr);
    cout<<"enter no of queries\n";
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cout<<"enter type of query\n";
        cin>>type;
        if(type==1)
        {
            int l,r;
            cin>>l>>r;
            cout<<seg.query(0,n-1,0,l,r);
        }
        else
        {
            int l,r,val;
            cin>>l>>r>>val;
            seg.update(0,0,n-1,l,r,val);
        }
    }
    
return 0;
}