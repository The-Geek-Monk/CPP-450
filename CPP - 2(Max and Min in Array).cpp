//maximum and minimum element in an array
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max,min;
	max=min=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
		if(a[i]<min)
			min=a[i];
		
	}
	cout<<"max"<<max<<"\t"<<"min"<<min;
	return 0;

}
