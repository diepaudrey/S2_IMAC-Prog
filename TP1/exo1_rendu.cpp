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
    //Modifier les valeurs pour tester
    int entier = 2;
    int exposant = 5; 
    int test = power(entier,exposant); //test = 32
    cout << entier <<  " a la puissance " << exposant << " vaut : " << test << endl;
    return 0;
}