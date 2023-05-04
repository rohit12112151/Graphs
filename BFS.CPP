#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    bool visited;
    node*next;

    node(int val)
    {
        data=val;
        visited=false;
        next=NULL;
    }
};


void bfs(node*arr[],int i)
{
    // queue<node*>q;

    //   q.push(c);
    //   while(!q.empty())
    //   {
    //     node*t=arr[q.front()->data];
    //     q.pop();
    //     if(t->visited==0)
    //     cout<<t->data<<" ";
    //     t->visited=true;
    //     while(t!=NULL)
    //     {
    //         if(t->visited!=true)
    //         { 
    //             q.push(t);
    //         }
    //          t=t->next;
    //   cout<<"done";
    //     }
    //   }


    // queue<node*>q;
    // q.push(arr[i]);

    // while(!q.empty())
    // {
    // node*t=arr[q.front()->data];
    // if(q.front()->visited==false)
    //   {cout<<q.front()->data<<" ";q.front()->visited=true;}
    //   while(t!=NULL)
    //   {
    //      if(t->visited==false)q.push(t);t=t->next;
    //   }
    //   q.pop();
    // }


    queue<node*>q;
    q.push(arr[i]);
    while(!q.empty())
    {
      node*t=arr[q.front()->data];
      node*n=t;
      if(t->visited==false)
      {
        cout<<q.front()->data<<" ";
        while(n!=NULL)
        {
          if(n->visited==false)
          {
            q.push(n);
          }
          n=n->next;
        }
      }
      t->visited=true;
      q.pop();
    }

}

int main(){
  cout<<"enter no. of vertex qnd edges : ";
  
   int n,m;
   cin>>n>>m;

   node*arr[n];
   for(int i=1;i<=n;i++)arr[i]=new node(i);
cout<<"start entering edges : ";
   for(int i=0;i<m;i++)
   {
    int x,y;
    cin>>x>>y;
    node*p=new node(x);
    node*p2=new node(y);

   node*temp=arr[x];
   while(temp->next!=NULL)temp=temp->next;temp->next=p2;
    // p->next=arr[y]->next;
    // arr[y]->next=p;

    temp=arr[y];
   while(temp->next!=NULL)temp=temp->next;temp->next=p;


    // p2->next=arr[x]->next;
    // arr[x]->next=p2;

   }
    for(int i=1;i<=n;i++)
      if(arr[i]->visited==0)
      bfs(arr,i);
      // bfs(arr,arr[1]);
    // for(int i=1;i<=n;i++)
    // {
    //     node*temp=arr[i];
    //     while(temp!=NULL)
    //     {
    //         cout<<temp->data<<" ";temp=temp->next;
    //     }
    //     cout<<endl;
    // }

return 0;
}