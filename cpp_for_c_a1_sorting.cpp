
#include "cpp_for_c_a1_sorting.h"
#include <iostream>
#include <algorithm>
#include <execution>

#include <memory>
#include <cstdlib>

#include "example_utils.h"

// https://berthub.eu/articles/posts/c++-1/
// https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range#19728404

using namespace std;


// -------------------
// -- Sorting in C ---
// -------------------

int compare_function_c(const void* a, const void* b)
{
  if(*(int*)a < *(int*)b)
    return -1;
  else if(*(int*)a > *(int*)b)
    return 1;
  else
    return 0;
}

void cpp_for_c_a1_sorting_in_c(std::vector<int>&& vec_to_sort)
{
    qsort(&vec_to_sort[0], vec_to_sort.size(), sizeof(int), compare_function_c);
}

// ---------------------
// -- Sorting in C++ ---
// ---------------------

void cpp_for_c_a1_sorting_in_cpp(std::vector<int>&& vec_to_sort)
{
	std::sort(vec_to_sort.begin(), vec_to_sort.end());
//	std::sort(vec_to_sort.begin(), vec_to_sort.end(),[](int lhs, int rhs) {return lhs < rhs;});
}

// ------------------------------
// -- Sorting in C++ Parallel ---
// ------------------------------
void cpp_for_c_a1_sorting_in_cpp_parallel(std::vector<int>&& vec_to_sort)
{
	std::sort(std::execution::par, vec_to_sort.begin(), vec_to_sort.end());
}

// ---------------------
// -- "Main" Sorting ---
// ---------------------

int cpp_for_c_a1_sorting(int /*argc*/, char** /*argv*/)
{
    cerr << "Sorting in C\n";
    cerr << "RAND_MAX: " << RAND_MAX << "\n";
	size_t count_to_sort = 10000000;

	// Create vector with lots of random integers
    std::vector<int> vec_c;
    vec_c.reserve(count_to_sort);
    while(count_to_sort--) {
        vec_c.push_back(rand()*rand());
    }

    std::vector<int> vec_cpp = vec_c;
    std::vector<int> vec_cpp_par = vec_c;

    time_me_ms_print("sorting in c           ", [&]() { cpp_for_c_a1_sorting_in_c(std::move(vec_c));} );
    time_me_ms_print("sorting in cpp         ", [&]() { cpp_for_c_a1_sorting_in_cpp(std::move(vec_cpp));} );
    time_me_ms_print("sorting in cpp parallel", [&]() { cpp_for_c_a1_sorting_in_cpp_parallel(std::move(vec_cpp_par));} );
    return 0;
}
