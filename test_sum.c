#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...) {
    va_list args;  // Declare the argument list
    int total = 0;

    va_start(args, count);  // Initialize with the last fixed argument
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);  // Retrieve the next argument (type: int)
    }
    va_end(args);  // Clean up the argument list

    return total;
}

int main() {
    printf("Sum of 1, 2, 3: %d\n", sum(3, 1, 2, 3)); // Output: 6
    printf("Sum of 4, 5, 6, 7: %d\n", sum(4, 4, 5, 6, 7)); // Output: 22
    return 0;
}
