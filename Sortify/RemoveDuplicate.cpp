#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter Size: ";
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Unique Elements: ";

    for(int i=0;i<n;i++)
    {
        int count=0;

        for(int j=0;j<i;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
        }

        if(count==0)
            cout<<arr[i]<<" ";
    }
}