// https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1

int size;
int search(int arr[], int start, int last) {
    int mid1 = (start+last)/2;
    int mid2 = mid1 + 1;
    
    if (arr[mid1] == 0 && arr[mid2] == 1) {
        return mid2;
    } else if (arr[mid1] == 0 && arr[mid2] == 0) {
        return search(arr, mid2, last);
    } else if (arr[mid1] == 1 && arr[mid2] == 1) {
        return search(arr, start, mid1);
    } else {
        
    }
    
}



int transitionPoint(int arr[], int n) {
    size = n;
    
    if (arr[0] == 1) return 0;
    if (arr[n-1] == 0) return -1;

    return search(arr, 0, n-1);
    // code here
}