template<typename T>
MutantStack<T>::iterator::iterator() : stk(0), i(-1) {}
template<typename T>
MutantStack<T>::iterator::iterator(MutantStack<T>& stk, int i) : stk(&stk), i(i) {}
template<typename T>
MutantStack<T>::iterator::iterator(const iterator& o) : stk(o.getStk()), i(o.getI()) {}
template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator=(const iterator& o) {
	stk = o.getStk();
	i = o.getI();
	return *this;
}
template<typename T>
MutantStack<T>::iterator::~iterator() {}
template<typename T>
int MutantStack<T>::iterator::getI() const {return i;}
template<typename T>
MutantStack<T>* MutantStack<T>::iterator::getStk() const {return stk;}

template<typename T>
T& MutantStack<T>::iterator::operator*() {
	std::stack<T> tmp;
	int left = i;
	while (left--) {
		tmp.push(stk->top());
		stk->pop();
	}
	T& res = stk->top();
	while (tmp.size()) {
		stk->push(tmp.top());
		tmp.pop();
	}
	return res;
}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator++() {i++; return *this;}

template<typename T>
typename MutantStack<T>::iterator& MutantStack<T>::iterator::operator--() {i--; return *this;};

template<typename T>
bool MutantStack<T>::iterator::operator!=(const iterator& o) {return i!=o.getI();};

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {return MutantStack<T>::iterator(*this, 0);}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {return MutantStack<T>::iterator(*this, this->size());}
