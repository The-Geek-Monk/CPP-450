#include<iostream>
using namespace std;

void fun(int x)
{
	if (x==0)
	{
		return;
	}
	else{
		cout<<"Geeks"<<" ";
		fun(x-1);
		cout<<"for geeks"<<" ";
	}
	
}
int main()
{
	fun(3);
	return 0;
}
