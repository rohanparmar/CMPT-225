#include <iostream>
#include <time.h>
#include "Stack.h"

using namespace std;

double elapsed_time(clock_t start, clock_t finish)
{
    // returns elapsed time in milliseconds
    return (finish - start) / (double)(CLOCKS_PER_SEC / 1000);
}

int main()
{
    clock_t start, end;
    const float elements = 1000;

    start = clock();

    for (int i = elements; i > 0; i--)
    {
        // code for insert
    }

    end = clock();

    float insert_time = elapsed_time(start, end);
}