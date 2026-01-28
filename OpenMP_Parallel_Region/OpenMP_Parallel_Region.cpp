// OpenMP_Parallel_Region.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

int main()
{
    std::cout << "Parallel regions!\n";

	int threads_count;
	int tid;

	#pragma omp parallel private(tid)
	{
		tid = omp_get_thread_num();
		std::cout << "This is thread = " << tid << "\n";

		if (tid == 0) {
			threads_count = omp_get_num_threads();
			std::cout << "Number of threads = " << threads_count << "\n";
		}
	}

	return 0;
}