#include <iostream>

using namespace std;
int main(){
    int A[10] = {1};
    int B[10] = {100};
    // we cannot do B = A
    // : Array names are constant not modifiable l-value, you can't modify it.
    B[0] = A[0];
    A[0] = 2;
    if (B[0] == 1){
        cout << "deep copy" << endl;
    }
    else{
        cout << "shallow copy" << endl;
    }
}