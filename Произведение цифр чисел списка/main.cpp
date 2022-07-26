#include <iostream>
#include <list>
#include <iterator>

#define list std::list<int>
#define iterator list::iterator

int mulDigit(int x)
{
    int res = 1;
    while (x > 0) {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int mulDigitList(list *l)
{
    iterator it = l->begin();
    int c = 0, res = 1;
    while (c < l->size()) {
        res *= mulDigit(*it);
        it++;
        c++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    list l = {221, 121, 568, 189, 148};
    std::cout << mulDigitList(&l) << "\n";
    return 0;
}
