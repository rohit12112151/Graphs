#include<bits/stdc++.h>
using namespace std;

int noofedges(int*arr,int n,int m)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(*(arr+i*m+j)==1)count++;
        }
    }
    return count;
}

int vertexwithhighestadj(int*arr,int n,int m)
{
    int edges=0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
    int count=0;
        for(int j=0;j<m;j++)
        {
           if(*(arr+i*m+j)==1)
           {
            count++;
           }
        }
        if(count>edges)
        {
            edges=count;
            ans=i;
        }
    }
    return ans+1;
}

int vertexwithminincoming(int*arr,int n,int m)
{
    int ans=INT16_MAX;
    int index=-1;
    int j;
    for(int i=0;i<n;i++)
    {
     int count=0;
        for(j=0;j<m;j++)
        {
            if(*(arr+j*m+i)==1)count++;
        // ans=max(ans,count);

        }
        if(ans>count && count!=0)
        {
            ans=count;
            index=i;
        }
    }
    return index+1;
}

void vertexwithnoincoming(int*arr,int n,int m)
{
     int ans=INT16_MAX;
    int index=-1;
    
    for(int i=0;i<n;i++)
    {
     int count=0;
        for(int j=0;j<m;j++)
        {
            if(*(arr+j*m+i)==1)count++;
        // ans=max(ans,count);

        }
        if(count==0)
        {
           cout<<i+1<<" ";
        }
    }
    return ;
}

void  vertexhavingconnectionwithallother(int*arr ,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
            if(*(arr+j*m+i)==1)count++;
        }
        if(count==n)cout<<i+1<<" ";
    }
}

int main(){
    cout<<"enter no. of rows and column : ";
     int m,n;
     cin>>n>>m;
     cout<<"enter elements of matrix :"<<endl;
     int arr[n][m];
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
     }
     cout<<"total no. of edges in graph : ";
     cout<<noofedges((int*)arr,n,m)<<endl;
     cout<<"vertex with highest no. of conections : ";
     cout<<vertexwithhighestadj((int*)arr,n,m)<<endl;
     cout<<"vertex with minimum no. of incoming : ";
     cout<<vertexwithminincoming((int*)arr,n,m)<<endl;
     cout<<"vertex with no incoming : ";
     vertexwithnoincoming((int*)arr,n,m);
     cout<<endl<<"vertex with connection with all others : ";
     vertexhavingconnectionwithallother((int*)arr,n,m);

     
return 0;
}