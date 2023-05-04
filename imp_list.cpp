#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int d)
    {
        data=d;
        next=NULL;
    }
};

int totaledges(node*arr[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        node*temp=arr[i];
        while(temp!=NULL)
        {
            count++;temp=temp->next;
        }
    }
    return count;
}

int vertexwithhighestadj(node*arr[],int n)
{
    int ans=0;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        int count=0;
        node*temp=arr[i];
        while(temp!=NULL)
        {
            count++;temp=temp->next;
        }
        // ans=max(ans,count);
        if(count>ans)
        {
            ans=count;index=i;
        }
    }
    return index+1;
}

int vertexwithminincoming(node*arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
        }
    }
}

int main(){
 
   int n;
   cin>>n;
   node*arr[n]={NULL};

   for(int i=0;i<n;i++)
   {
   int val=1;
      while(val>=0)
      {
        cin>>val;
        if(val==-1)break;
        if(val>n-1)
        {
            // cout<<"enter valid";
            continue;
        }
        node*p=new node(val);
        if(arr[i]==NULL)arr[i]=p;
        else{
            node*temp=arr[i];
            p->next=arr[i];
            arr[i]=p;

        }
      }
   }

//    for(int i=0;i<n;i++)
//    {
//     node*temp=arr[i];
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";temp=temp->next;
//     }
//     cout<<endl;
//    }

cout<<totaledges(arr,n)<<endl;
cout<<vertexwithhighestadj(arr,n);
     
return 0;
}