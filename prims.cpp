#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int dist;
    bool visited;
    node*next;

    node(int val,int d)
    {
        data=val;
        dist=d;
        visited=false;
        next=NULL;
    }
};

class qu{
    public:
    int start;
    int end;
    int dist;

    qu(int s,int e,int d)
    {
        start=s;end=e;dist=d;
    }
};

bool operator < (node n1,node n2)
{
    return n1.dist<n2.dist;
}

void mst(node*arr[],node*n)
{
    // int size=sizeof(arr)/sizeof(arr[1]);
    // node*final[size];
    // for(int i=1;i<=size;i++)final[i]=new node(i,0);
priority_queue<node>pq;
    queue<qu>q;

    n->visited=true;
    n=n->next;
    while(n!=NULL){
        // if(arr[n->data]->visited==0)
        pq.push(node(n->data,n->dist));
        n=n->next;
    }
    
    while(!pq.empty())
    {
        node t=pq.top();pq.pop();
        node*p=arr[t.data];
        node*st=p->next;

        while(p->dist!=t.dist)
        p=p->next;

        //  arr[p->data]->visited=true;
        if(arr[t.data]->visited!=arr[p->data]->visited)
         q.push(qu(p->data,t.data,p->dist));
      
      while(st!=NULL)
      {
        if(arr[st->data]->visited==0)
        {
            pq.push(node(st->data,st->dist));
        }
        st=st->next;
      }

      arr[t.data]->visited=true;
        
    }

    cout<<endl;

  while(!q.empty())
  {
    cout<<q.front().start<<" "<<q.front().end<<" "<<-(q.front().dist)<<endl;
    q.pop();
  }
    
}

int main(){

//  priority_queue<node>pq;

//  pq.push(node(3,-6));
//  pq.push(node(5,-3));
//  pq.push(node(7,-7));
//  pq.push(node(2,-9));
//  pq.push(node(1,-1));
//  pq.push(node(3,-4));

//  while(!pq.empty())
//  {
//     cout<<pq.top().data<<" "<<-pq.top().dist<<endl;pq.pop();
//  }
  

 int n,m;
 cin>>n>>m;
 node*arr[n];
 for(int i=1;i<=n;i++)
 {
    arr[i]=new node(i,0);
 }

 for(int i=0;i<m;i++)
 {
    int x,y,z;
    cin>>x>>y>>z;
    node*p1=new node(y,-z);
    node*temp=arr[x];
    while(temp->next!=NULL)temp=temp->next;temp->next=p1;

    node*p2=new node(x,-z);
    temp=arr[y];
    while(temp->next!=NULL)temp=temp->next;temp->next=p2;

    
 }

 mst(arr,arr[1]);


// for(int i=1;i<=n;i++)
// {
//     node*temp=arr[i];
//     cout<<temp->data<<"-->"<<" ";temp=temp->next;
//     while(temp!=NULL){cout<<temp->data<<"'"<<temp->dist<<" ";temp=temp->next;}cout<<endl;
// }
   
//    int arr[7];cout<<sizeof(arr)/sizeof(arr[1]);
return 0;
}