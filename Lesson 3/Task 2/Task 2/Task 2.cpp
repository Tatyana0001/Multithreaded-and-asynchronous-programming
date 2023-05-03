#include <future>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template<typename Iterator>
void parallel_for_each(Iterator first, Iterator last, function<void(int)> func)
{
	unsigned long const length = distance(first, last);
	unsigned long const max_chunk_size = 25;
	if (length <= max_chunk_size)
	{
		for_each(first, last, func);
	}
	else
	{
		Iterator mid_point = first;
		advance(mid_point, length / 2);
		future<void> first_half_result = async(launch::async, parallel_for_each<Iterator>, first, mid_point, func);
		future<void> second_half_result = async(launch::async, parallel_for_each<Iterator>, mid_point, last, func);
	}
}

int main()
{
	vector<int> V(1000);
	generate(V.begin(), V.end(), []() {return rand() % 10; });
	auto start = chrono::high_resolution_clock::now();
	for_each(V.begin(), V.end(), [](int i) {i++; });
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> res = end - start;
	cout << res.count() << endl;

	vector<int> V1(1000);
	generate(V1.begin(), V1.end(), []() {return rand() % 10; });
	auto start1 = chrono::high_resolution_clock::now();
	parallel_for_each(V1.begin(), V1.end(), [](int i) {i++; });
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double> res1 = end1 - start1;
	cout << res1.count() << endl;

	return 0;
}