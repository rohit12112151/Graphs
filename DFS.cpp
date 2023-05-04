#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    bool visits;
    node *next;

    node(int d)
    {
        data = d;
        visits = false;
        next = NULL;
    }
};

void dfs(node *arr[], int size, node *n)
{

    if (n->visits == 0)
        cout << n->data << " ";
    n->visits = true;
    // for(int i=1;i<=size;i++)
    while (n != NULL)
    {
        if (arr[n->data]->visits == 0)
        {
            dfs(arr, size, arr[n->data]);
        }
        else
            n = n->next;
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    node *arr[m];
    for (int i = 1; i <= m; i++)
        arr[i] = new node(i);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        node *p = new node(y);
        node *p2 = new node(x);

        p->next = arr[x]->next;
        arr[x]->next = p;

        p2->next = arr[y]->next;
        arr[y]->next = p2;
    }
    for (int i = 1; i <= n; i++)
        dfs(arr, m + 1, arr[i]);




    // for(int i=1;i<=n;i++)
    // {
    //     node*temp=arr[i];
    //     while(temp!=NULL)
    //     {
    //         cout<<temp->data<<" ";temp=temp->next;
    //     }
    // }

    return 0;
}