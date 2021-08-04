# include <stdio.h> 

int binarySearch(int A[], int left, int right, int target);
void quicksort(int A[], int left, int right);
int split(int A[], int left, int right);
void swap(int* a, int* b);
void printArray(int A[], int left, int right);

int main(int argc, char* argv[]) {
    int A[] = {5, 7, 32, 11, 5, 3, 2, 100};
    int nA = sizeof(A) / sizeof(A[0]);

    quicksort(A, 0, nA - 1);
    printArray(A, 0, nA - 1);

    int target = 7;
    int targetIndex = binarySearch(A, 0, nA - 1, target);
    printf("%d", targetIndex);
}

int binarySearch(int A[], int left, int right, int target) {
    while (left <= right) {
        // mid is left middle index 
        int mid = left + (right - left) / 2;

        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Not found 
    return -1;
}

void quicksort(int A[], int left, int right) {
    if (left >= right) {
        return;
    }

    int splitIndex = split(A, left, right);
    
    quicksort(A, left, splitIndex - 1);
    quicksort(A, splitIndex + 1, right);
}

int split(int A[], int left, int right) {
    // Select A[right] as pivot 

    int finalIndex = left;

    // Get pivot final index 
    for (int i = left; i < right; i++) {
        // Place smaller elements at left 
        if (A[i] < A[right]) {
            swap(&A[i], &A[finalIndex]);
            finalIndex++;
        }
    }

    // Place pivot at final index 
    swap(&A[right], &A[finalIndex]);
    
    return finalIndex;
}

void swap(int* a, int* b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

void printArray(int A[], int left, int right) {

    for (int i = left; i <= right; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}