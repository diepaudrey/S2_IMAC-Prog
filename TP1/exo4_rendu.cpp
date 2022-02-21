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
    int evens[4]={0,0,0,0}; //on initilise le tableau à 0
    int ev_size = 0;
    int array[4] = {1,4,8,3};
    int arr_size = 3;

    allEvens(evens, array, ev_size, arr_size);

    for(int i=0; i<4; i++){
        cout << "valeur du tableau evens a l'indice " << i << " vaut " << evens[i] << endl;
    }

    return 0;
}