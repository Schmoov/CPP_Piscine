#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "~~~~~~~~~~\n" << std::endl;
	std::list<int> lst;
	lst.push_front(5);
	lst.push_front(17);
	std::cout << lst.front() << std::endl;
	lst.pop_front();
	std::cout << lst.size() << std::endl;
	lst.push_front(3);
	lst.push_front(5);
	lst.push_front(737);
	lst.push_front(0);
	std::list<int>::iterator itL = lst.begin();
	std::list<int>::iterator iteL = lst.end();
	++itL;
	--itL;
	while (itL != iteL)
	{
		std::cout << *itL << std::endl;
		++itL;
	}

	std::cout << "~~~~~~~~~~\n" << std::endl;
	MutantStack<std::string> ms;
	ms.push("Uno");
	std::cout << ms.top() << std::endl;
	std::cout << ms.size() << std::endl;
	ms.push("TWO");
	std::cout << ms.top() << std::endl;
	std::cout << *ms.begin() << std::endl;
	ms.pop();
	std::cout << *ms.begin() << std::endl;
	return 0;
}
