#include <iostream>
using namespace std;

int fibo(int n){
    //Base case
    if(n==0 || n==1)
        return n;
    //Recursive case
    int f1 = fibo(n-1);
    int f2 = fibo(n-2);
    return f1+f2;
}

int factorial(int n){
    //Base Case
    if(n==0)
        return 1;
    //Recursive case;
    return n*factorial(n-1);
}

bool sortedornot(int arr[], int i){
    //base case
    if(i==0)
        return true;
    if(arr[i] < arr[i-1])
        return false;
    //recursive case
    if(sortedornot(arr, i-1) == false)
        return false;
    else 
        return true;
}
bool isSorted(int a[], int n){
    //Base case
    if(n==0 || n==1)
        return true;
    //Recursive case
    if( a[0] <= a[1] && isSorted(a+1, n-1))
        return true;
    return false;
}

int naive_power(int a, int b){
    //base case
    if(b==0)
        return 1;
    //Recursive case
    return a * naive_power(a, b-1);
}
int fast_power(int a, int b) {
    //base case
    if(b==0)
        return 1;
    //recursive case
    int smaller_ans = fast_power(a, b/2);
    smaller_ans *= smaller_ans;
    if(b&1) { //odd
        smaller_ans *= a;
    } 
    return smaller_ans; //even
}

/*
   Code written before the recursive call -> executes in Top Down 
   Code written after the recursive call -> executes in Bottom Up 
*/

//Top to Bottom
void printDec(int n){ //Printing in Decreasing Order
    //base case
    if(n==0)
        return;
    //recursive case
    cout<<n<<" ";
    printDec(n-1);
}

//Bottom Up Direction
void printInc(int n){ //Printing order in Increasing Order
    //base case
    if(n==0)
        return;
    //recursive case
    printInc(n-1);
    cout<<n<<" ";
}

int main() {
    cout<<factorial(6)<<endl;
    cout<<fibo(6)<<endl;
    int arr[] = {1, 2, 3, 4 ,5};
    cout<<sortedornot(arr, 4)<<endl;
    cout<<isSorted(arr, 5)<<endl;

    cout<<naive_power(2,3)<<endl;
    cout<<fast_power(2,4)<<endl;
    
    printDec(5);
    cout<<endl;
    printInc(5);
    cout<<endl;

}
