#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    bool visited;
    node *next;
    int dist;

    node(int val, int d)
    {
        data = val;
        visited = false;
        next = NULL;
        dist = d;
    }
};

// bool operator < (node n1,node n2)
// {
//     return n1.dist<n2.dist;
// }

class p
{
public:
    int index;
    int dis;
    p(int i, int d)
    {
        index = i;
        dis = d;
    }
};
bool operator<(p p1, p p2)
{
    return p1.dis < p2.dis;
}

void dijkastra(node *arr[],int k, node *start, node *end)
{
    
    int relax[k];
    for (int i = 1; i <= k; i++)
        relax[i] = INT_MAX;

    priority_queue<p> pq;

    relax[start->data] = 0;
    pq.push(p(start->data, relax[start->data]));

    while (!pq.empty())
    {
        p top = pq.top();
        pq.pop();
        // cout<<top.index<<" ";
        node *temp = arr[top.index];
        temp->visited = true;

        while (temp != NULL)
        {
            if (arr[temp->data]->visited == false)
            {
                if (relax[temp->data] > temp->dist - top.dis)//"-" is for putting smallest in top of pq;
                {
                    relax[temp->data] = temp->dist - top.dis;
                }
                pq.push(p(temp->data, -relax[temp->data]));
            }
            temp = temp->next;
        }

        if ((top.index) == (end->data))
        {
            cout <<endl<<relax[end->data];
            return;
        }
    } 
 
}

int main()
{

    int n, m;
    cin >> n >> m;
    node *arr[n];
    for (int i = 1; i <= n; i++)
        arr[i] = new node(i, 0);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        node *p = new node(y, z);
        node *temp = arr[x];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;

        temp = arr[y];
        node *p2 = new node(x, z);
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p2;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     node*temp=arr[i];
    //     while(temp!=NULL){cout<<temp->data<<" ";temp=temp->next;}cout<<endl<<endl;
    // }
    dijkastra(arr,n,arr[3], arr[2]);

    return 0;
}