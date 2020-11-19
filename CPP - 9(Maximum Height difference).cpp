// C++ program to find the minimum possible 
// difference between maximum and minimum 
// elements when we have to add/subtract 
// every number by k 
#include <bits/stdc++.h> 
using namespace std; 

// Modifies the array by subtracting/adding 
// k to every element such that the difference 
// between maximum and minimum is minimized 
int getMinDiff(int arr[], int n, int k) 
{ 

	// Sort all elements 
	sort(arr, arr+n); 

	// Initialize result 
	int ans = arr[n-1] - arr[0]; 

	// Handle corner elements 
	int max = arr[0] + k; 
	int min = arr[n-1] - k; 
	if (min > max) 
	swap(min, max); 

	// Traverse middle elements 
	for (int i = 1; i < n-1; i ++) 
	{ 
		int sub = arr[i] - k; 
		int add = arr[i] + k; 

		// If both subtraction and addition 
		// do not change diff 
		if (sub >= min || add <= max) 
			continue; 

		// Either subtraction causes a smaller 
		// number or addition causes a greater 
		// number. Update small or big using 
		// greedy approach (If big - subtract 
		// causes smaller diff, update small 
		// Else update big) 
		if (max - sub <= add - min) 
			min = sub; 
		else
			max = add; 
	} 

	return min(ans, max-min); 
} 

// Driver function to test the above function 
int main() 
{ 
	int arr[] = {4, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int k = 10; 
	cout << "\nMaximum difference is "
		<< getMinDiff(arr, n, k); 
	return 0; 
} 

