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


int main(){
    //initialisation
    int lenArr = 6;
    int arr[6] = {0,1,2,4,4,5};
    int indRes;

    //valeur à changer pour tester
    int toSearch=4;
    indRes = binarySearch(arr, lenArr, toSearch);
    cout << toSearch <<  " est à l'indice " << indRes << endl;


    return 0;
}