#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a = 5;
	int *p = &a;

	//Generic Pointer / Void Pointer
	void *p0;
	p0 = p;
	// Since it is not mapped with any type, we cannot derefernce the void pointer
	//we could just take the address only and not the value.
	cout << p0 << endl ; //<< *p0; ->This will give error.
	//Arithmetic also not possible on Generic Pointers.

	//Pointer to Pointer
	int x = 5;
	int *p1 = &x;
	int **q = &p1;
	cout << *q << endl;	//displays address of pointer p
	cout << **q << endl; //displays the value



	return 0;
}