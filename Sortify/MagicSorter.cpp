#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    // Even Ascending
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]%2==0 && arr[j]%2==0 && arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    // Odd Descending
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]%2!=0 && arr[j]%2!=0 && arr[i]<arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    cout<<"Result:\n";

    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            cout<<arr[i]<<" ";
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
            cout<<arr[i]<<" ";
    }
}