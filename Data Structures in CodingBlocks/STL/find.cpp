#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int arr[] = {1,2,45,3,11,100};
    int n= sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    //Search --> find()
    //find searches in sequential order like a linear search, useful for unordered list of numbers
   auto it = find(arr, arr+n, key);
    int index = it- arr;
    if(index == n) //If element not found -> returns the size of array, as it goes through last element.
    {
        cout<<key<<" element not found";
    } else{
        cout<<key<<" at index "<<index;
    }

    //Binary Search
    int ar[] = {23, 33, 40, 40, 40, 44, 56,231};
    n = sizeof(ar)/sizeof(n);
    cin>>key;
    //BinarySearch method gives a bool value if and element present or not
    bool check = binary_search(ar, ar+n, key);
    if(check){
        cout<<"Present"<<endl;
    } else {
        cout<<"Absent"<<endl;
    }

    //Lower bound gives the first occurrence of the element
    auto lb = lower_bound(ar, ar+n, 40);
    cout<<"LowerIndex of 40 "<<(lb - ar)<<endl;

    //Upper bound gives the last occurrence of the element
    auto ub = upper_bound(ar, ar+n, 40);
    cout<<"UpperIndex of 40 "<<(ub - ar)<<endl;

    //Finding no. of occurrence in Array
    cout<<ub-lb<<endl;
    return 0;
}
