#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int open,close,full;
    Node()
    {
        open=0;
        close=0;
        full=0;
    }
    Node(int open,int close,int full)
    {
        this->open=open;
        this->close=close;
        this->full=full;
    }
};


Node merge(Node left,Node right)
{
    Node temp(0,0,0);
    temp.full=left.full+right.full+min(left.open,right.close);
    temp.open=left.open+right.open-min(left.open,right.close);
    temp.close=left.close+right.close-min(left.open,right.close);
    return temp;
}

void build(string s,Node seg[],int low,int high,int ind)
{

    if(low==high)
    {
        if(s[low]=='(')
        {
            seg[ind] = Node(1,0,0);
        }
        else
        {
            seg[ind]= Node(0,1,0);
        }
        return;
    }
        int mid=(low+high)/2;
        build(s,seg,low,mid,ind*2+1);
        build(s,seg,mid+1,high,ind*2+2);
        seg[ind]=merge(seg[ind*2+1],seg[ind*2+2]);
}

Node query(int l,int r,int ind,int low,int high,Node seg[],string s)
{
    if(r<low ||  l>high)
    {
        return Node(0,0,0);
    }
    else if(low>=l && high<=r)
    {
        return seg[ind];
    }
    else
    {
        int mid=(low+high)/2;
        Node left=query(l,r,ind*2+1,low,mid,seg,s);
        Node right=query(l,r,ind*2+2,mid+1,high,seg,s);
        return merge(left,right);
    }
}



int main(){
    string s;
    cin>>s;
    int n=s.length();   
    Node seg[4*n];

    build(s,seg,0,n-1,0);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--; // making it 0 based indexing.
        r--;
        Node temp=query(l,r,0,0,n-1,seg,s);
        cout<<temp.full*2<<endl; /// *2 because utne number of bracket valid hai.
    }
/*
input : 
())(())(())( 
7 
1 1 
2 3 
1 2 
1 12 
8 12 
5 11 
2 10

outpt : 
0 
0 
2 
10 
4 
6 
6


*/
    
return 0;
}