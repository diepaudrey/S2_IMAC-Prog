#include <iostream>

using namespace std;

int search(int value, int array[],int size){
    if(size<0){
        return -1;
    }
    if(array[size]==value){
        return size;
    }
    return search(value, array, size-1);
    
    
}

int main(){
    int array[5]= {1,6,5,12,4};
    int indice = search(6, array, 5);
    cout << indice << endl;

    return 0;
}