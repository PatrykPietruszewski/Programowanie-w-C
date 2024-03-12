#include <stdio.h>

int BinarySearch(int tab[], int left, int right, int target){
    
    if(tab[right]<target || tab[left] > target){
        return -1;
    }
    
    int m = left + (right-left)/2;
    
    if(tab[m] == target){
        return m;
    }
    else if(tab[m]>target){
        return BinarySearch(tab, left, m-1, target);
    }
    else if(tab[m]<target){
        return BinarySearch(tab, m+1, right, target);
    }
}

int main()
{
    int tab[10] ={
        1,2,3,4,5,6,7,8,9,10
    };
    
    printf("%d", BinarySearch(tab, 0, 9, 6));
    return 0;
}
