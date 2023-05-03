#include <vector>
#include <iostream>
#include <future>
#include <algorithm>


using namespace std;

void find_min(vector<int> & V, int i, promise<int> prom)
{
	int min = i;
	for (int j = i; j < V.size(); j++) {
		if (V[j] < V[min]) {
			min = j;
		}
	}
	prom.set_value(min);
}

void Async_sort(vector<int>&V) {
	for (int i = 0; i < V.size(); i++) {
		promise<int> P1;
		future<int> F1 = P1.get_future();
		future<void> res = async(find_min, ref(V), i, move(P1));
		int res_min = F1.get();
		if (res_min > i) {
			swap(V[i], V[res_min]);
		}
	}
}


int main()
{
    vector<int> V = { 13, 65, 2, 5, 33, 9, 1, 8, 15, 42, 6, 10, 7, 26, 4 };
	Async_sort(V);
	cout << "Sort: ";
	for (auto& x : V) {
		this_thread::sleep_for(200ms);
		cout << x << " ";
	}
    return 0;
}
