// OpenMP_Select_num_threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

int main()
{
	// Variables for the threads
	int num_threads;
	int tid;

	// Variables to measure time elapsed
	double start;
	double end;

    std::cout << "Changing the number of threads\n";

	std::cout << "Enter the number of threads to use: ";
	std::cin >> num_threads;

	#ifdef _OPENMP
		omp_set_num_threads(num_threads);
	#endif

	// Store the initial timestamp ( just before running the threads )
	start = omp_get_wtime();

	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		std::cout << "This is thread number: " << tid << std::endl;
		std::cout << "Thread " << tid << " finished." << std::endl;
	}

	// Store the final timestamp when the threads finish
	end = omp_get_wtime();

	// The time elapsed is the difference between the timestamps
	std::cout << "Total time elapsed: " << end - start << std::endl;

	return 0;
}