#include <iostream>
using namespace std;

void afficheTab(int arr[], int lenArr){
    cout << "[ ";
    for(int i=0; i<lenArr; i++){
        if(i!= lenArr-1){
            cout << arr[i] << ", ";
        }
        else{
            cout << arr[i];
        }
    }
    cout << " ]" << endl;
}

void swap(int* val1, int* val2){
    int val3 = *val1; 
    *val1 = *val2;
    *val2= val3;
}


void selectionSort(int tab[], int longueur){
    int min;
    int min_index;
    
    for(int j=0; j<longueur-1; j++){
        min= tab[j];
        min_index = j;

        for(int i = j; i<longueur; i++){

            if(tab[i]<min){
                min = tab[i]; 
                min_index = i;
                
            }
        
        }
        swap(&tab[min_index], &tab[j]);

        
    }
    
    
}




int main(){
    int len = 6;
    int arr[len] = {4,9,1,0,-5,3};
    
    selectionSort(arr, len);
    afficheTab(arr, len);

    
    
    
    return 0;
}