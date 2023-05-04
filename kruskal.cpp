#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int start;
    node*next;
    int dist;

    node(int i,int val,int d)
    {
        data=val;
        start=i;
        dist=d;
        next=NULL;
    }

};

bool operator < (node n1,node n2)
{
    return n1.dist<n2.dist;
}

int find(int arr[],int index)
{
    if(arr[index]==index)return index;
    return find(arr,arr[index]);
}

void unn(int arr[],int a,int b)
{
    int x=find(arr,a);
    int y=find(arr,b);
    if(x==y)return;
    arr[y]=x;
}

void mst(int arr[],priority_queue<node>&pq)
{
   while(!pq.empty())
   {
     node top=pq.top();pq.pop();
    int x=find(arr,arr[top.start]);
    int y=find(arr,arr[top.data]);
    if(x==y)continue;
    cout<<top.start<<" "<<top.data<<" "<<-top.dist<<endl;
    arr[y]=x;
   }
}

int main(){

    priority_queue<node>pq;
 
    int n,m;
    cin>>n>>m;
    int arr[n];
    for (int i = 1; i <=n; i++)arr[i]=i;
    
    
    // node*con[n];
    // for(int i=1;i<=n;i++)con[i]=new node(i,i,0);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        // node*p=new node(x,y,z);
        // node*temp=con[x];
        // while(temp->next!=NULL)temp=temp->next;temp->next=p;
        pq.push(node(x,y,-z));
    }
 cout<<endl;
    mst(arr,pq);


     
return 0;
}