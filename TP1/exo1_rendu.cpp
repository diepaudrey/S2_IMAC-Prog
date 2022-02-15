#include <iostream>

using namespace std;

int power(int value, int n){
    int result;
    if(n==1){
        return value;
    }
    result = value*power(value, n-1);
    return result;
    
}

int main(){
    int test = power(2,5); //test = 32
    cout << test << endl;
    return 0;
}