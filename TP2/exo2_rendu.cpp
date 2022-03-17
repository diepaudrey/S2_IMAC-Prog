#include <iostream>
using namespace std;

void swap(int* val1, int* val2){
    int val3 = *val1; 
    *val1 = *val2;
    *val2= val3;
}

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



void insertionSort(int tab[], int len){
    int key;
    int j;
    for(int i=1; i<len; i++){
        key = tab[i];
        j=i-1;

        while(j>=0 && tab[j]>key){

            tab[j+1] = tab[j];

            j--;

        }
        tab[j+1] = key;
       
    }


}




int main(){
    int arr[4]={1,3,0,-3};
    insertionSort(arr, 4);
    afficheTab(arr,4);
    
    return 0;
}