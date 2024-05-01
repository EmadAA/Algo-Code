#include <iostream>
using namespace std;
int main()
{
    int n,steps=1;
    cout<< "enter number of size: "<<endl;
    cin>>n;
    int num[n];
    cout<< "enter the element"<<endl;
    for (int i=0; i<n; i++)
    {
        cin>>num[i];
    }
    for(int i=0 ; i<n; i++)
    {
        int x=num[i];
        int j=i-1;
        while(j>=0 && num[j]>x)
        {
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=x;
        cout<<"step "<<steps<<" -> ";
        for (int i=0; i<n; i++)
        {
            cout<<num[i]<<" ";
        }
        steps++;
        cout<<endl;
    }
    cout<<"total number of steps : "<<steps-1<<endl;
    return 0;
}
