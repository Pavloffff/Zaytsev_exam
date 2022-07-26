#include <iostream>
#include <list>
#include <iterator>

#define list std::list<int>
#define iterator list::iterator

int check(list* listA, list* listB)
{
    iterator a = listA->begin();
    iterator b = listB->begin();
    int cur = 0;
    while (cur < listA->size() && cur < listB->size()) {
        if (*a < *b) {
            return -1;
        }
        if (*a > *b) {
            return 1;
        }
        a++;
        b++;
        cur++;
    }
    if (listA->size() < listB->size()) {
        return -1;
    }
    if (listA->size() > listB->size()) {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    list listA = {1, 2, 3};
    list listB = {1, 2, 4};
    std::cout << check(&listB, &listA) << "\n";
    return 0;
}