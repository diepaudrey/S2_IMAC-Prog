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
    //Mofidier la valeur de rang;
    int n = 13;
    int fibo_n = fibonacci(n); //fibo_n = 233
    cout << "Le rang " << n << " de la suite de fibonacci vaut :" << fibo_n << endl;
    return 0;
}