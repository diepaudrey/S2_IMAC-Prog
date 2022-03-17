#include <iostream>
using namespace std; 

int binarySearch(int arr[], int lenArr, int toSearch)
{
    //initialisation
    int start = 0;
    int end = lenArr; 
    int mid;
    int foundIndex;

    //boucle
    while(start < end){
        mid = (start + end)/2;
        if(toSearch > arr[mid]){
            start = mid + 1;
        }
        else if(toSearch < arr[mid]){
            end = mid;
        }
        else{
            foundIndex = mid;
            return foundIndex;
        }
    }

	return -1;
}

int binarySearchMin(int arr[],int lenArr, int toSearch, int& indexMin){
    int start = 0;
    int end = lenArr;
    int mid; 
    while(start < end){
        mid = (start + end)/2;
        if(arr[mid] < toSearch){
            start = mid +1;
        }
        else{
            end = mid;
        }

    }
    indexMin = start;
    return indexMin;
}

int binarySearchMax(int arr[],int lenArr, int toSearch, int& indexMax){
    int start = 0;
    int end = lenArr;
    int mid; 
    while(start < end){
        mid = (start + end)/2;
        if(arr[mid] > toSearch){
            end = mid;
        }
        else{
            start = mid + 1 ;
        }

    }
    indexMax = end -1;
    return indexMax;
}

void binarySearchAll(int arr[], int lenArr, int toSearch, int& indexMin, int& indexMax)
{
   //initialisation
    int start = 0;
    int end = lenArr; 
    int mid;
    int verify = -1; //pour vérifier si toSearch est dans le tableau


    //boucle indexMin
    while(start < end){
        mid = (start + end)/2;
        if(toSearch > arr[mid]){
            start = mid + 1;
        }
        else if(toSearch < arr[mid]){
            end = mid;
        }
        else{
            indexMin = mid;
            end = mid;

            verify = 0;
        }
    }
    

    //boucle indexMax
    start = (lenArr)/2;
    end = lenArr;

      while(start < end){
        mid = (start + end)/2;
        if(toSearch > arr[mid]){
            start = mid + 1;
        }
        else if(toSearch < arr[mid]){
            end = mid;
        }
        else{
            indexMax = mid;
            start++;

            verify = 0;
        }
    }

    //si toSearch n'est pas dans le tableau
    if(verify == -1){
        indexMin = -1;
        indexMax = -1;
    }

}


int main(){
    //initialisation
    int lenArr = 6;
    int arr[6] = {0,2,4,4,4,6};
    int indexMin;
    int indexMax;
    
    // valeur à changer pour tester
    int toSearch=4;

    //fonction et affichage
    binarySearchAll(arr, lenArr, toSearch, indexMin, indexMax);
    cout << "index minimum : " << indexMin << endl;
    cout << "index maximum : " << indexMax << endl;

    return 0;
}