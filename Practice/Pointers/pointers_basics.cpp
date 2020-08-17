#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//1. Basic Initialisation

	int a = 5;
	int *p; //or, int *p = &a;
	p = &a; //allocating p with address of a.

	printf("%d\n", p); //address of a, that is stored in p
	printf("%d\n", a);
	printf("%d\n", *p); //value at address of p. Derefrencing Variable.

	// This is called dereferencing
	*p = 12; //will modify the value at which it is pointing

	printf("%d\n", a);
	int b = 7;
	*p = b; //Will this change value of p to add. of b? No, it will only change the value at a.
	//p = &b; //this will change the address p is pointing to.

	//2. Pointer Arithmetic
	printf("Address of p : %d\n", p);
	printf("Address of p+1: %d\n", p + 1); // it will inc by 4bytes.
	printf("Value at p+1: %d\n", *(p + 1) ); //Garbage value, because we haven't given any.
	//Multiplication and Division not allowed in Pointers.


	return 0;
}