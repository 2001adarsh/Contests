#include <iostream>
using namespace std;
void tower_of_hanoi(int n, char from_disk, char to_disk, char aux_disk) {
    if(n==0)
        return ;
    //recursive case
    tower_of_hanoi(n-1, from_disk, aux_disk, to_disk);
    cout<<"move plate "<<n<<" from "<<from_disk<<" to "<<aux_disk<<endl;
    tower_of_hanoi(n-1, aux_disk, to_disk, from_disk); 
}

int main() {
    tower_of_hanoi(2, 'A', 'C', 'B');
}
