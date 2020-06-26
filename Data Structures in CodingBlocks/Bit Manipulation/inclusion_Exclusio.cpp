#include <iostream>
using namespace std;
#define ll long long
//Property of Inclusion and exclusion

int main() {
    ll t;
    cin>>t;
    ll primes[] = {2,3,5,7,11,13,17,19};

    while(t--){
        ll n;
        cin>>n;
        ll segments = (1<<8)-1; //2^N -1 here N is primes.size()
        ll ans = 0;

        for(ll i =1; i<=segments; i++){
            ll denom = 1ll;
            ll setBits = __builtin_popcount(i);

            for(ll j=0; j<=7; j++){  //we are excluding 000000, since we want atlest 1 prime number to be there to divide n.
                if(i&(1<<j)){ //checking if jth bit is 1
                    denom *= primes[j];
                }
            }
            if(setBits&1){ //odd number of setBits
                ans+= n/denom;
            }else{
                ans -= n/denom;
            }
        }
        cout<<ans<<endl;
    }    
}
