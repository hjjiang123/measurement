#include <iostream>
#include "xxhash32.h"
using namespace std;

int main(){
    uint32_t myseed = 1;
    XXHash32 myhash(myseed);
    const char* pointerToSomeBytes = "fefedfde";
    myhash.add((void *)pointerToSomeBytes,     32);
    // and compute hash:
    uint32_t result = myhash.hash();

    // or all of the above in one single line:
    uint32_t result2 = XXHash32::hash((void *)pointerToSomeBytes, 32, myseed,17);
    cout<<result2<<endl;
}