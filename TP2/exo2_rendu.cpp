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
    int result[len];
    result[0]=tab[0];
    int j;
    for(int i=1; i<len; i++){
        j=i;
        if(tab[i]<result[j-1]){
            while(j>0 && tab[i]<result[j-1]){

                result[j] = result[j-1];
    
                j = j-1;
            }

        }
        result[j] = tab[i];
       
    }
    afficheTab(result, len);


}





int main(){
    int arr[4]={1,3,0,-3};
    insertionSort(arr, 4);
    

    return 0;
}