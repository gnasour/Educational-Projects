#include <stdio.h>

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    
    while(low < high || x!=v[mid]){
        mid = (low+high)/2;
        if(x < v[mid])
            high = mid-1;
        else{
            low = mid+1;
        }
        
    }
    if(x == v[mid])
        return mid;

    return -1;
}

int main(){
    int sorted_array[10] = {5,16,45,75,89,200,256,576};
    printf("%d\n", binsearch(45, sorted_array, 10));

}