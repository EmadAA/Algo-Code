//#include <bits/stdc++.h>
//using namespace std;
//
//void Merge(int arr[], int n, int L, int Mid, int H)
//{
//    int Copy[n];
//    int i = L, j = Mid + 1, k = L;
//    while (i <= Mid && j <= H)
//    {
//        if (arr[i] < arr[j])
//        {
//            Copy[k] = arr[i];
//            k++;
//            i++;
//        }
//        else
//        {
//            Copy[k] = arr[j];
//            k++;
//            j++;
//        }
//    }
//    for (; i <= Mid; i++)
//    {
//        Copy[k] = arr[i];
//        k++;
//    }
//    for (; j <= H; j++)
//    {
//        Copy[k] = arr[j];
//        k++;
//    }
//    for (int a = L; a < k; a++)
//    {
//        arr[a] = Copy[a];
//    }
//}
//
//void mergeSort(int arr[], int n, int L, int H)
//{
//    if (L < H)
//    {
//        int Mid = (L + H) / 2;
//        mergeSort(arr, n, L, Mid);
//        mergeSort(arr, n, Mid + 1, H);
//        Merge(arr, n, L, Mid, H);
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    int arr[n];
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arr[i];
//    }
//    mergeSort(arr, n, 0, n - 1);
//    for (int i = 0; i < n; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}
#include<bits/stdc++.h>//Preprocessor Command/Detector

using namespace std ;// Using Declaration
int n;
void Merge(int arr[],int n, int l, int mid, int h)
{
    int temp[n];
    int i=l;
    int j=mid+1;
    int k=l;

    while(i<=mid && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=  arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    for(; i<=mid; i++)
    {
        temp[k]=arr[i];
    }
    for(; j<=h; j++)
    {
        temp[k]=arr[j];
    }

    for(int a=0; a<n ; a++)
    {
        arr[a]=temp[a];
    }
}

void mergesort(int arr[],int n,  int l, int h)
{
    if(l<h)
    {
        int mid= (l+h)/2;
        mergesort(arr,n,l,mid);
        mergesort(arr,n,mid+1,h);
        Merge(arr,n,l,mid,h);
    }
}





int main() //main function
{
    cin>>n;
    int arr[n];
    for(int i=0; i<n;  i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,n,0, n-1);

    for(int i=0; i<n;  i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;// means program successfully executed

}
