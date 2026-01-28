// OpenMP_sum_arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <omp.h>

// Function headers
void printArray(const int* arr, int size);

int main()
{
    std::cout << "Adding arrays in parallel\n";

	const int size = 10000;
	const int chunkSize = 100;
	const int displaySize = 10;

	// The arrays to be added
    int a[size];
    int b[size];
    int c[size];

    int i;

    // Variables to measure time
    double start;
    double end;

	// Initialize arrays a and b
    for (i = 0; i < size; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
	}

    start = omp_get_wtime();

    // Add arrays a and b into array c in parallel
    #pragma omp parallel for shared(a, b, c) private(i) schedule(static, chunkSize)
    for (i = 0; i < size; i++)
    {
        c[i] = a[i] + b[i];
    }
    
    end = omp_get_wtime();

    // Display the first and last part of the result array a
    std::cout << "First " << displaySize << " elements of array a: ";
    printArray(a, displaySize);
    // Display the first and last part of the result array b
    std::cout << "First " << displaySize << " elements of array b: ";
    printArray(b, displaySize);

    // Display the first and last part of the result array c
    std::cout << "First " << displaySize << " elements of array c: ";
    printArray(c, displaySize);

    std::cout << "Elapsed time: " << end - start << std::endl;

    /*
    std::cout << "Last " << displaySize << " elements of array c: ";
    printArray(&c[size - displaySize], displaySize);
	*/
    
    return 0;
}

void printArray(const int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}