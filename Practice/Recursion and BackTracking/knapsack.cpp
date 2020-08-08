#include <iostream>
using namespace std;
//Defunct function -> work needed,
int knapsack(int *weight, int *price,int n, int i, 
                    int capacity, int current, int sum){
    //base case
    if(i == n)
        return -1;
    // recursive case
    if(current == capacity)
        return sum;
    else if(current > capacity)
        return sum-price[i-1];

    return max( knapsack(weight, price, n, i+1, capacity, current+weight[i], sum+price[i]) ,
                knapsack(weight, price, n, i+1, capacity, current, sum) );
}

//working function.
int knapsackmain(int N, int C, int *weight, int *price) {
    //base case
    if(N==0)
        return 0;
    if(C==0)
        return 0;
    //recursive case
    int ans =0;
    int inc=0,exc =0;
    if(weight[N-1] <= C){
        inc = price[N-1] + knapsackmain(N-1, C-weight[N-1], weight, price);
    }
    exc = knapsackmain(N-1, C, weight, price);
    ans = max(inc, exc);
    return ans;
}

int main() {
    int weight[] = {2,5,3,4};
    int price[] = {40, 100, 60, 90};

    //cout<<knapsack(weight, price,4, 0, 7, 0, 0)<<endl;

    cout<<knapsackmain(4, 7, weight, price);
}
