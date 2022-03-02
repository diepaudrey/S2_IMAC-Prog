#include <iostream>
using namespace std;

void merge(int first[], int second[], int result[], int lenFst, int lenSnd);

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

void splitAndMerge(int arr[], int lenArr)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if(lenArr<=1){
        return;
    }

	// initialisation
    int lenFst = lenArr/2;
    int first[lenFst];
    int lenSnd = lenArr - lenArr/2;
    int second[lenSnd];
	
	// split
    for(int i=0; i<lenFst; i++){
        first[i]=arr[i];
        //cout << first[i] << endl;
    }
    int j=lenArr/2;
    for(int i=0; i<lenSnd; i++){
        second[i]=arr[j];
        j++;
    }


	// recursiv splitAndMerge of lowerArray and greaterArray
    splitAndMerge(first, lenFst);
    splitAndMerge(second, lenSnd);


	// merge
    merge(first, second, arr, lenFst, lenSnd);
    

}

void merge(int first[], int second[], int result[], int lenFst, int lenSnd)
{
    int lenRes = lenFst + lenSnd; // longueur de result

    int r = 0; //index pour result
    int f=0; // index pour first
    int s=0; // index pour second

    while(r<lenRes){
        if(first[f]<second[s] && f<lenFst){
            result[r] = first[f];
            f++;
        }
        else if(s<lenSnd){
            result[r] = second[s];
            s++;
        }
        r++;
    }
    
}

int main(){
    int lenArr = 6;
    int arr[lenArr] = {125,8,0,-125,8,52};
    
    splitAndMerge(arr, lenArr);
    afficheTab(arr,lenArr);

    return 0;
}