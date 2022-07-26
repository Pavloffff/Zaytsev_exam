#include <iostream>
#include <deque>

#define deque std::deque<int>

deque *reverse(deque *d)
{
    int x = 0;
    if (!d->empty()) {
        x = d->front();
        d->pop_front();
        reverse(d);
        d->push_back(x);
    }
    return d;
}

int main(int argc, char const *argv[])
{
    deque d = {1, 2, 3, 4, 5, 6, 7, 8 ,9, 0};
    for (int i: d) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    d = *(reverse(&d));
    for (int i: d) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
