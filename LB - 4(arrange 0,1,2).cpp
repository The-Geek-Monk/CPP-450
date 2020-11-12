#include <bits/stdc++.h> 
using namespace std; 
void sort012(int arr[],int n)
{
	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		switch(arr[mid]){
			case 0: swap(arr[low++],arr[mid++]);
			break;
			case 1: mid++;
			break;
			case 2: swap(arr[mid],arr[high--]);
			break;
		}	
	}
	
	
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main() 
{ 
    int n;
    cin>>n;
    
    while(n--)
    {
         int num;
         cin>> num;
        int arr[num];
        for(int i=0;i<num;i++)
        cin>>arr[i];
        sort012(arr, num); 
      
        print(arr, num); 
        cout<<endl;
    }  
    return 0; 
}
