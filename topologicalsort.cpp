// #include<bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int data;
//     node*next;
//     bool visited;
    

//     node(int val)
//     {
//         data=val;
//         next=NULL;
//         visited=false;
        
//     }
// };

// void dfs(node*arr[],node*n,stack<node*>&st)
// {
//     n->visited=true;

//     // if(n->next==NULL)
//     // {
//     //     st.push(n);
//     //     return;
//     // }
//     node*p=n;
//     while(p!=NULL)
//     {
//         if(arr[p->data]->visited==false)dfs(arr,arr[p->data],st);
//           p=p->next;
//     }
//     st.push(n);


// }



// int main(){

//     int n,m;
//     cin>>n>>m;
//     node*arr[n];
//     for(int i=1;i<=n;i++)arr[i]=new node(i);
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         node*p=new node(y);
//         p->next=arr[x]->next;
//         arr[x]->next=p;

//     }



//     stack<node*>st;

//     for(int i=1;i<=n;i++)
//     {
//         if(arr[i]->visited==0)
//         dfs(arr,arr[i],st);
//     }

    

    

//     while(!st.empty())
//     {
//         cout<<st.top()->data<<" ";st.pop();
//     }
     
     
// return 0;
// }







#include <algorithm> // for sort()
#include <iostream>
#include <vector> // for 2D vector
using namespace std;
 
// Driver function to sort the 2D vector
// on basis of a particular column
// bool sortcol(const vector<int>& v1, const vector<int>& v2)
// {
//     return v1[1] < v2[1];
// }
 
// Driver Code
int main()
{
    // Initializing 2D vector "vect" with
    // values
    vector<vector<int> > vect{ { 3, 5, 1 },
                               { 7, 2, 9 },
                               { 4, 8, 6 }
                                };
 
    // Number of rows;
    int m = vect.size();
 
    // Number of columns (Assuming all rows
    // are of same size). We can have different
    // sizes though (like Java).
    int n = vect[0].size();
 
    // Displaying the 2D vector before sorting
    cout << "The Matrix before sorting is:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
 
    // Use of "sort()" for sorting on basis
    // of 2nd column
    sort(vect.begin(), vect.end());
 
    // Displaying the 2D vector after sorting
    cout << "The Matrix after sorting is:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
    return 0;
}