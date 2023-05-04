#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    int dist;
    node *next;
    // bool visited;

    node(int val, int d)
    {
        data = val;
        dist = d;
        // visited=false;
        next = NULL;
    }
};

void DAG(node *arr[], int n, node *start)
{
    int relax[n];
    for (int i = 1; i <= n; i++)
        relax[i] = INT_MAX;
    relax[start->data] = 0;
    // start->visited=true;
    queue<int> q;
    q.push(start->data);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        node *temp = arr[a];
        temp = temp->next;
        while (temp != NULL)
        {
            if (relax[temp->data] > temp->dist + relax[a])
            {
                relax[temp->data] = temp->dist + relax[a];
                q.push(temp->data);
            }
            // if(arr[temp->data]->visited==false)
            temp = temp->next;
        }

        // cout << "good";
    }
    // cout << "god";
    for(int i=1;i<=n;i++)cout<<relax[i]<<" ";
}

int main()
{

    int n, m;
    cin >> n >> m;
    node *arr[n];
    for (int i = 1; i <= n; i++)
        arr[i] = new node(i, 0);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        node *p = new node(y, z);


        // node *temp = arr[x];
        // while (temp->next != NULL)
        //     temp = temp->next;
        // temp->next = p;


        p->next=arr[x]->next;
        arr[x]->next=p;
    }
    DAG(arr,n,arr[1]);
    // for (int i = 1; i <= n; i++)
    // {
    //     node *temp = arr[i];
    //     while (temp != NULL)
    //     {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }

    return 0;
}