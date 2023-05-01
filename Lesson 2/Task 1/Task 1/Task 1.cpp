
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

void client(atomic<int> &count) {
    for (int i = 1; i < 15; i++) {
        this_thread::sleep_for(1s);
        count.fetch_add(1, memory_order_acquire);
        cout << "Client number " << count.load() << " added\n";
    }
}
void worker(atomic<int> &count) {
    this_thread::sleep_for(2s);
    while (count != 0) {
        this_thread::sleep_for(2s);
        std::cout << "Client number " << count.load() << " deleted\n";
        count.fetch_sub(1, memory_order_acquire);
    }
}


int main()
{
    atomic<int> count = 0;
    thread t1(client, ref(count));
    thread t2(worker, ref(count));
    t1.detach();
    t2.join();
    return 0;
}