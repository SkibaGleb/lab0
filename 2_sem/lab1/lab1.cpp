#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack<int> s;
	int elem;

	while (cin >> elem && elem != 0) {
		s.push(elem);
	}

	while (s.count() > 0) {
		int v = s.pop();
		if (v > 0) {
			cout << v << " ";
		}
	}
}