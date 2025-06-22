#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
private:
public:
	class iterator {
	private:
		MutantStack<T>* stk;
		int i;
	public:
		iterator();
		iterator(MutantStack<T>& stk, int i);
		iterator(const iterator& o);
		iterator& operator=(const iterator& o);
		~iterator();
		int getI() const;
		MutantStack<T>* getStk() const;

		T& operator*();
		iterator& operator++();
		iterator& operator--();
		bool operator!=(const iterator& o);
	};
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"
