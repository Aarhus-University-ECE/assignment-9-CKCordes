#include "search.h"

#include <stdbool.h>

bool search(int a[], int n, int x) {
    // Base case 1
    if (n == 0) {
        return false;
    }
    // Base case 2
    else if (n > 0 && a[n - 1] == x) {
        return true;
    }
    // Recursive step

    else if (n > 0 && a[n - 1] != x) {
        return search(a, n - 1, x);
    }
}
