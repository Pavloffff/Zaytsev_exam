#include <iostream>
#include <stack>

#define stack std::stack<int>

int removeMax(stack *s)
{
	stack tmp;
	int max = s->top();
	while(!(s->empty())) {
        tmp.push(s->top());
        if (tmp.top() > max) {
				max = tmp.top();
			}
        s->pop();
	}
	int n = 0;
	while (!tmp.empty()) {
		if((tmp.top() == max) && (n == 0)) {
			n++;
			tmp.pop();
		}
		else {
            s->push(tmp.top());
			tmp.pop();
		}
	}
	return max;
}

stack *sort(stack *s)
{
	stack res;
	while(!s->empty()){
		res.push(removeMax(s));
	}
	*s = res;
    return s;
}

int main(int argc, char const *argv[])
{
    stack s({5, 3, 1214, 2, 0, 700, 411});
    s = *sort(&s);
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
    return 0;
}
