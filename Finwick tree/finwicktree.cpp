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

// prefix sum
int query(int i,int fin[])
{
    int sum=0;
    while(i>0)
    {
        sum+=fin[i];
        i=i-(i&(-i));
    }
    return sum;
}

int rangeSum(int l,int r,int fin[])
{
    return query(r,fin)-query(l-1,fin);
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
    int q;
    cout<<"enter number of queries\n";
    cin>>q;
    while(q--)
    {
        int type;
        cout<<"enter type of query\n";
        cin>>type;
        if(type==1)
        {
            int i;
            cout<<"enter index\n";
            cin>>i;
            cout<<query(i,fin)<<endl;
        }
        else if(type==2)
        {
            int i,val;
            cout<<"enter index and value\n";
            cin>>i>>val;
            update(i,val,arr,fin,n);
            cout<<"updated\n";
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<"enter range\n";
            cout<<rangeSum(l,r,fin)<<endl;
        }
    }

return 0;
}   