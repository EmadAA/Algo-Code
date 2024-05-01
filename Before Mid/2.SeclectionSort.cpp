#include<bits/stdc++.h>
using namespace std;

int main()
    {
      int n ;
      cin >> n ;
      int Arr[n] ;
      for(int i=0 ; i<n ; i++)
      {
          cin >> Arr[i] ;
      }
      for(int i=0 ; i<n ; i++)
      {
          for(int j=i+1 ; j<n ; j++)
          {
              if(Arr[i] > Arr[j])
              {
                  swap(Arr[i] , Arr[j]);
              }
          }
      }
      for(int i=0 ; i<n ; i++)
      {
          cout << Arr[i] << " ";
      }
      cout << endl;


    return 0;
    }
