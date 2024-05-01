#include <bits/stdc++.h>
using namespace std;

void Merge(int a[],int b[],int c[],int n, int m)
{

    int i=0,j=0,k=0;
    while(i<n && j< m)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    for(; i<n; i++)
    {
        c[k]=a[i];
        k++;
    }
    for(; j<m; j++)
    {
        c[k]=b[j];
        k++;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m],c[n+m];

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int j=0; j<m; j++)
    {
        cin>>b[j];
    }
    Merge(a,b,c,n,m);
    for(int k=0; k<n+m; k++)
    {
        cout<<c[k]<<" ";
    }
    return 0;
}

