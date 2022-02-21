#include <iostream>

using namespace std;

int search(int value, int array[], int size){
    if(size<0){
        return -1;
    }
    if(array[size]==value){
        return size;
    }
    return search(value, array, size-1);
    
    
}

int main(){
    //Parametre a modifier
    int array[5]= {1,6,5,12,4};
    int valeur_cherch = 6;
    int size_tab = 5;
    int indice = search(valeur_cherch, array, size_tab);


    if(indice == -1){
        cout << "La valeur " << valeur_cherch << " n'est pas dans le tableau " << endl;
    }
    else {
        cout << "La valeur " << valeur_cherch << " est a l'indice " << indice << " du tableau " << endl;
    }
    

    return 0;
}