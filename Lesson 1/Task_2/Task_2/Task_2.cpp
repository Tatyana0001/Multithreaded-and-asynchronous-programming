#include <vector>
#include <iostream>
#include <random>
#include <thread>
#include <mutex>

using namespace std;
once_flag o_flag;

void once_print() {
    cout << "\t\t1000\t\t10000\t\t100000\t\t1000000\n";
}
void print(vector<double> &durations, int threat_count) {
    call_once(o_flag, once_print);
    cout << threat_count<< " потоков\t";
    for (auto& i : durations) {
        cout << i << "\t";
    }
    cout << "\n";
}

vector<int> sum_vectors(vector<int>&V1, vector<int>&V2, vector<int> &V_result, int start, int end) {
    for (int i = start; i < end; ++i) {
        V_result[i] = V1[i] + V2[i];
    }
    return V_result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Количество аппаратных ядер - " << thread::hardware_concurrency() << "\n\n";
    mt19937 gen;
    uniform_int_distribution<int> dis(0, 1'000'000);
    auto rand_num([=]() mutable {return dis(gen); });
    vector<double> durations;
    for (int threat_count = 1; threat_count <= 16; threat_count *= 2) {
        durations.clear();
        for (int i = 1000; i <= 1000000; i *= 10) {
            vector<int>V1(i);
            vector<int>V2(i);
            vector<int>V_result(i, 0);
            vector<thread> threads;
            generate(V1.begin(), V1.end(), rand_num);
            generate(V2.begin(), V2.end(), rand_num);
            auto start = chrono::high_resolution_clock::now();
            for (int V_start = 0; V_start < V1.size(); V_start += (V1.size() / threat_count)) {
                int V_end = V_start + (V1.size() / threat_count);
                if (V_end > V1.size()) {
                    V_end = V1.size();
                }
                threads.push_back(thread(sum_vectors, ref(V1), ref(V2), ref(V_result), V_start, V_end));
            }
            for (auto& thr : threads) {
                thr.join();
            }
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            durations.push_back(time.count());
        }
     print(durations, threat_count);
    }
    return 0;
}

