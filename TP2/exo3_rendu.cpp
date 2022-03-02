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



void bubbleSort(int tab[], int len){

   for(int j=len-1; j>0; j--){
       for(int i=0; i<j;i++){
            if(tab[i]>tab[i+1]){
                swap(&tab[i],&tab[i+1]);
            }
        }
   }
   
}



int main(){
    int len = 5;
    int arr[len]={-3,6,-5,2,1};
    bubbleSort(arr, len);
    afficheTab(arr, len);
    

    return 0;
}
