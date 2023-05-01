#include <iostream>
#include <mutex>

using namespace std;

class Data {
public:
    int x = 0;
    mutex mt;
    Data(int x) : x(x) { };
};

void swap_lock(Data& d1, Data& d2) {
    lock(d1.mt, d2.mt);
    lock_guard<mutex> la{ d1.mt, adopt_lock };
    lock_guard<mutex> lb{ d2.mt, adopt_lock };
    swap(d1.x, d2.x);
}

void swap_scoped_lock(Data& d1, Data& d2) {
    scoped_lock sl{ d1.mt, d2.mt };
    swap(d1.x, d2.x);
}

void swap_unique_lock(Data& d1, Data& d2) {
    unique_lock<mutex> la{ d1.mt, defer_lock };
    unique_lock<mutex> lb{ d2.mt, defer_lock };
    lock(la, lb);
    swap(d1.x, d2.x);
}


int main()
{
    Data d1(13);
    Data d2(90);

    cout << "d1.x = " << d1.x << "\n" << "d2.x = " << d2.x << "\n";

    swap_lock(d1, d2);
    cout << "Lock:\nd1.x = " << d1.x << "\n" << "d2.x = " << d2.x << "\n";
    
    swap_scoped_lock(d1, d2);
    cout << "Scoped_lock:\nd1.x = " << d1.x << "\n" << "d2.x = " << d2.x << "\n";

    swap_unique_lock(d1, d2);
    cout << "Unique_lock:\nd1.x = " << d1.x << "\n" << "d2.x = " << d2.x << "\n";

    return 0;
}