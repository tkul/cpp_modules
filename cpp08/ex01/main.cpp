#include "Span.hpp"
#include <ctime>

static void printTitle(const std::string &title) {
	std::cout << "\n==== " << title << " ====\n";
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	printTitle("Basic usage");
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printNumbers();
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Overflow test");
	try {
		Span sp2(2);
		sp2.addNumber(1);
		sp2.addNumber(2);
		sp2.printNumbers();
		std::cout << "Attempting to add third number..." << std::endl;
		sp2.addNumber(3);
	} catch (std::exception &e) {
		std::cout << "Caught expected: " << e.what() << std::endl;
	}

	printTitle("Not enough numbers test");
	try {
		Span sp3(3);
		sp3.addNumber(42);
		sp3.printNumbers();
		std::cout << "Trying shortestSpan with only one element..." << std::endl;
		std::cout << sp3.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught expected: " << e.what() << std::endl;
	}

	printTitle("Bulk insertion test");
	try {
		std::vector<int> vec;
		vec.push_back(2);
		vec.push_back(4);
		vec.push_back(7);
		vec.push_back(11);
		Span sp4(10);
		sp4.addNumbers(vec.begin(), vec.end());
		sp4.addNumber(20);
		sp4.addNumber(30);

		sp4.printNumbers();

		std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp4.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Bulk insertion overflow test");
	try {
		Span sp5(3);
		std::vector<int> big;
		big.push_back(1);
		big.push_back(2);
		big.push_back(3);
		big.push_back(4);
		big.push_back(5);

		std::cout << "Numbers to add: ";
		for (size_t i = 0; i < big.size(); ++i) {
			std::cout << big[i] << " ";
		}
		std::cout << std::endl;
		sp5.addNumbers(big.begin(), big.end());
	} catch (std::exception &e) {
		std::cout << "Caught expected: " << e.what() << std::endl;
	}

	printTitle("Large dataset test");
	try {
		const unsigned int N = 10000;
		Span sp6(N);
		unsigned int i;
		for (i = 0; i < N; ++i) {
			sp6.addNumber(std::rand());
		}

		std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
		std::cout << "Longest span : " << sp6.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	printTitle("Done");
	return 0;
}

