#include <iostream>
#include <thread>

using namespace std;

void client(int &count) {
    for (int i = 1; i < 15; i++) {
        this_thread::sleep_for(1s);
        count++;
        cout << "Client number " << count << " added\n";
    }
}
void worker(int &count) {
    this_thread::sleep_for(2s);
    while(count != 0) {
        this_thread::sleep_for(2s);
        std::cout << "Client number " << count << " deleted\n";
        count--;
    }
}


int main()
{
    int count = 0;
    thread t1(client, ref(count));
    thread t2(worker, ref(count));
    t1.detach();
    t2.join();
    return 0;
}


