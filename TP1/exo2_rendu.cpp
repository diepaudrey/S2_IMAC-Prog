#include <iostream>

using namespace std;

int fibonacci(int n){
    int F_n;

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    F_n = fibonacci(n-1) + fibonacci(n-2);

    return F_n;
    
}

int main(){
    int fibo_n = fibonacci(13); //fibo_n = 233
    cout << fibo_n << endl;
    return 0;
}