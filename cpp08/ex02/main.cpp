#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <stack>

static void header(const std::string &t) {
	std::cout << "\n===== " << t << " =====" << std::endl;
}

int main() {
	header("Basic push / top / pop");
	MutantStack<int> ms;
	ms.push(10);
	ms.push(20);
	ms.push(30);

	std::cout << "Top: " << ms.top() << std::endl;
	ms.pop();
	std::cout << "Top after pop: " << ms.top() << std::endl;
	std::cout << "Size: " << ms.size() << std::endl;

	header("Fill more elements");
	for (int i = 0; i < 5; ++i)
		ms.push(i * 3);
		
	std::cout << "Size now: " << ms.size() << std::endl;
	std::cout << "Top now: " << ms.top() << std::endl;

	header("Iterate (forward)");
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	header("Modify through iterator (add 1)");
	for (it = ms.begin(); it != ms.end(); ++it)
		*it += 1;
	for (it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	header("String MutantStack test");
	MutantStack<std::string> sms;
	sms.push("hello");
	sms.push("mutant");
	sms.push("stack");
	MutantStack<std::string>::iterator sit = sms.begin();
	while (sit != sms.end()) {
		std::cout << *sit << std::endl;
		++sit;
	}

	return 0;
}
