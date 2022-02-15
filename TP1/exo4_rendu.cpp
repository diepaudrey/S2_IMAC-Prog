#include <iostream>

using namespace std;



void allEvens(int evens[], int array[], int evenSize, int arraySize){
    if(arraySize >= 0){

        if(array[arraySize]%2==0){
            evens[evenSize] = array[arraySize];
            evenSize ++;

        }
    
        allEvens(evens, array, evenSize, arraySize-1);
    }
}

int main(){
    int evens[4]={0,0,0,0};
    int array[4] = {1,4,8,3};

    allEvens(evens, array, 0, 3);

    for(int i=0; i<4; i++){
        cout << "valeur à l'indice " << i << " vaut " << evens[i] << endl;
    }

    return 0;
}