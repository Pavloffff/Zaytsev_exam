#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	char c;
	int inp, a, b;
	while (c != EOF) {
		c = getchar();
		if (isdigit(c)) {
			ungetc(c, stdin); // символ идет на поток ввода, откуда мы считываем число
        	scanf("%d", &inp);
        	s.push(inp);	
		} else if (c == '+') {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(a + b);
		} else if (c == '-') {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(a - b);
		} else if (c == '*') {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(a * b);
		} else if (c == '/') {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(a / b);
		}
	}
    printf("\n%d\n", s.top());
	return 0;
}
