#include "sum.h"

#include <assert.h>

int sum(int a[], int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive step

    else {
        return a[n - 1] + sum(a, n - 1);
    }
}
