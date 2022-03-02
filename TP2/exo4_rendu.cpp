#include <iostream>
using namespace std;

void afficheTab(int tab[], int len){
    cout << "[ ";
    for(int i=0; i<len; i++){
        if(i==len-1){
            cout << tab[i];
        }
        else{
            cout << tab[i] << ", ";
        }
    }
    cout << " ]" << endl;
}

int countSmaller(int* tab, int val,  int len){
    int count = 0;
    for(int i=0; i<len; i++){
        if(tab[i]<val){
            count++;
        }
    }
    return count;
}

int countGreater(int* tab, int val,  int len){
    int count = 0;
    for(int i=0; i<len; i++){
        if(tab[i]>val){
            count++;
        }
    }
    return count;
}



void fusionTab(int* result, int* lower, int* greater, int pivot, int low_size, int great_size){
    int tailleTab = low_size + great_size + 1;
    int j = 0;
    for(int i = 0; i<tailleTab; i++){
        if(i<low_size){
            result[i] = lower[i];
        }
        else if(i==low_size){
            result[i] = pivot; 
        }
        else{
            result[i]=greater[j];
            j++;
        }
    }

}


void quickSort(int tab[], int len){
    if(len==0){
        return;
    }

    int pivot = tab[0];
    int index_lower=0;
    int index_greater=0;
    int l_size = countSmaller(tab, pivot, len);
    int lowerArray[l_size];
    int g_size = countGreater(tab, pivot, len);
    int greaterArray[g_size];
    
   
    for(int i=1; i<len ;i++){
        
        if(tab[i]<pivot){
            lowerArray[index_lower] = tab[i];
            index_lower ++;
            
        }
        else{
            greaterArray[index_greater] = tab[i];

            index_greater ++;
        }
    }


    //Recursif
    quickSort(lowerArray, l_size);
    quickSort(greaterArray, g_size);


    //Merge
    int j=0;
    for(int i = 0; i<len; i++){
        if(i<l_size){
            tab[i] = lowerArray[i];
        }
        else if(i==l_size){
            tab[i] = pivot; 
        }
        else{
            tab[i]=greaterArray[j];
            j++;
        }
        
    }

}



int main(){
    int len = 6;
    int arr[len]={4,6,1,3,5,10};
    quickSort(arr, len);
    afficheTab(arr, len);

    

    return 0;
}