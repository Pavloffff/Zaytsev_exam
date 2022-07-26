#include <bits/stdc++.h>
using namespace std; 

int main(int argc, char const *argv[])
{
	stack<int> s;
	char c;
	int a, b;
	while (c != EOF) {
		c = getchar();
		if (c == '0' || c == '1') {
			s.push(c - '0');
		} else if (c == '+') {
			a = (int)(s.top());
			s.pop();
			b = (int)(s.top());
			s.pop();
			s.push(a || b);
		} else if (c == '*') {
			a = (int)(s.top());
			s.pop();
			b = (int)(s.top());
			s.pop();
			s.push(a && b);
		}
	}
	printf("\n%d\n", s.top());
	return 0;
}
