#include "sum.h"

#include <assert.h>

int sum(int a[], int n) {
    // assert(n >= 0);
    if (n == 0) {
        return 0;
    } else {
        return a[n - 1] + sum(a, n - 1);
    }
}