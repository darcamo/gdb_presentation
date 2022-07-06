

#include <cstdlib>
#include <ctime>
#include <cstdio>

int main() {
    srand(time(NULL));

    constexpr unsigned int arraySize = 20;
    int array[arraySize];

    for(unsigned int i = 0; i < arraySize; i++) {
        auto denominator = int(rand() % 200);
        array[i]         = 1 / denominator;
    }

    printf("Fim\n");
    return 0;
}
