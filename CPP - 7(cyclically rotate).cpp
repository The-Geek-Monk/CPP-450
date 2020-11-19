#include <stdio.h>
#include<iostream>
using namespace std;

int main() {
	//code
	int num,n;
	cin>>num;
	while((num--)>0)
	{
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int temp = arr[n-1]; //remember last element
        for(int i=n-1;i>=0;i--)
        {
            arr[i+1] = arr[i]; //move all element to the right except last one
        }
        arr[0] = temp; //assign remembered value to first element
        //output: 1 2 3 4 5 because elements are shifted back by right shift
        for(int i=0;i<n;i++)
            cout << arr[i] <<" ";
	    cout<<endl;
	}
	
	return 0;
}
