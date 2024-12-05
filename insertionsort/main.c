#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right);

long long mergeAndCount(int arr[], int temp[], int left, int right) {
    if (left == right) {
        return 0;
    }

    int mid = (left + right) / 2;
    long long invCount = 0;

    invCount += mergeAndCount(arr, temp, left, mid);       
    invCount += mergeAndCount(arr, temp, mid + 1, right);  
    invCount += merge(arr, temp, left, mid, right);        

    return invCount;
}

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1; 
    int k = left;    
    long long invCount = 0;

    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); 
        }
    }

    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long countSwaps(int arr[], int n) {
    int temp[n]; 
    return mergeAndCount(arr, temp, 0, n - 1);
}

int main() {
    int t; 
    scanf("%d", &t);

    while (t--) {
        int n; 
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        printf("%lld\n", countSwaps(arr, n));
    }

    return 0;
}
