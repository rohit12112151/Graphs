#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;
    bool visited;

    node(int val)
    {
        data=val;
        next=NULL;
        visited=false;
    }
};

void dfs(node*arr[],node*n,stack<node*>&st)
{
    n->visited=true;
    node*p=n;
    while(p!=NULL)
    {
        if(arr[p->data]->visited==0)dfs(arr,arr[p->data],st);
        p=p->next;
    }
    st.push(n);
}

void dfsp(node*arrt[],node*n)
{
    if(n->visited==false)cout<<n->data<<" ";
    n->visited=true;
    while(n!=NULL)
    {
        if(arrt[n->data]->visited==0)dfsp(arrt,arrt[n->data]);
        n=n->next;
    }
}

int main(){

  int n,m;
  cin>>n>>m;
  node*arr[n];
  node*arrt[n];
  for(int i=1;i<=n;i++)arr[i]=new node(i);
  for(int i=1;i<=n;i++)arrt[i]=new node(i);
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;

    node*p=new node(y);
    node*temp=arr[x];
    while(temp->next!=NULL)temp=temp->next;temp->next=p;
    

    node*p2=new node(x);
    temp=arrt[y];
    while(temp->next!=NULL)temp=temp->next;temp->next=p2;

     
  }


  stack<node*>st;
  for(int i=1;i<=n;i++)
  {
    if(arr[i]->visited==0)dfs(arr,arr[i],st);
  }

//   cout<<endl;

//   for(int i=1;i<=n;i++)
//   {
//     node*temp=arr[i];
//     while(temp!=NULL)
//     {
//       cout<<temp->data<<" ";temp=temp->next;
//     }cout<<endl;
//   }

// cout<<endl;

//   for(int i=1;i<=n;i++)
//   {
//     node*temp=arrt[i];
//     while(temp!=NULL)
//     {
//       cout<<temp->data<<" ";temp=temp->next;
//     }cout<<endl;
//   }

//   cout<<endl;


//   while(!st.empty())
//   {
//     cout<<st.top()->data<<" ";st.pop();
//   }

 

  while(!st.empty())
  {
    node*v=st.top();
    st.pop();
    if(arrt[v->data]->visited==0)
    {
      dfsp(arrt,v);
      cout<<endl;
    }
    
   }
     
return 0;
}