#include <iostream>
using namespace std;

/* A group of N friends, want to go to party, they can either go single
or with couple on a bike. How many ways are there to go in a party.
*/

int friends(int n){
    //base case
    if(n==0 || n==1)
        return 1;
    else if(n<0)
        return 0;
    //recurrence relation
    return  (1*friends(n-1) + ( (n-1) * friends(n-2) )); //n-1 comes from (n-1)C(1) 
                                            //as no. of ways to select a friend from n-1 friends.
}

int main() {
    cout<<friends(3)<<endl;
}
