/*
 *Q3.3 Imagine a(literial)stack of plates.If the stack gets too high,it might topple.Therefore,in real life,we would likely start a new stack when the
 *previous stack exceeds some threshold.Implement a data structure SetOfStacks that mimics this.SetOfStacks should be composed of serveral stacks,and
 *should create a new stack once the previous one exceeds capacity.SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
 *(that is,pop() should return the same values as if there were just a single stack).
 *FOLLOW UP
 *Implement a function popAt(int index) which performs a pop opration on a specific sub-stack.
 */

#include <iostream>
using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;
class stack {
private:
	int *buf;
	int cur;
	int capacity;
public:
	stack(int capa = STACK_SIZE) {
		buf = new int[capa];
		cur = -1;
		capacity = capa;
	}
	~stack() {
		delete[] buf;
	}
	void push(int val) {
		buf[++cur] = val;
	}
	void pop() {
		--cur;
	}
	int top() {
		return buf[cur];
	}
	bool empty() {
		return cur == -1;
	}
	bool full() {
		return cur == capacity - 1;
	}
};

class SetOfStacks {
private:
	stack *st;
	int cur;
	int capacity;
	
public:
	SetOfStacks(int capa = STACK_NUM) {
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}
	~SetOfStacks() {
		delete[] st;
	}
	void push(int val) {
		if (st[cur].full()) ++cur;
		st[cur].push(val);
	}
	void pop() {
		if (st[cur].empty()) --cur;
		return st[cur].pop();
	}
	bool empty() {
		if (cur == 0) return st[0].empty();
		else return false;
	}
	bool full() {
		if (cur == capacity - 1) return st[cur].full();
		else return false;
	}
};

class SetOfStacks1 {
private:
	stack *st;
	int cur;
	int capacity;

public:
	SetOfStacks1(int capa = STACK_NUM) {
		st = new stack[capa];
		cur = 0;
		capacity = capa;
	}
	~SetOfStacks1() {
		delete[] st;
	}
	void push(int val) {
		if (st[cur].full()) ++cur;
		st[cur].push(val);
	}
	void pop() {
		while (st[cur].empty()) --cur;
		st[cur].pop();
	}
	void popAt(int idx) {				//popAt method
		while (st[idx].empty()) --idx;
		st[idx].pop();
	}
	int top() {
		while (st[cur].empty()) --cur;
		return st[cur].top();
	}
	bool empty() {
		while (cur != -1 && st[cur].empty()) --cur;
		if (cur == -1) return true;
		else return false;
	}
	bool full() {
		if (cur == capacity - 1) return st[cur].full();
		else return false;
	}
};

int main() {
	/*SetOfStacks ss;
	for (int i = 0; i < 3*STACK_SIZE + 1; ++i)
	{
		ss.push(i);
	}
	while (!ss.empty()) {
		cout << ss.top() << endl;
		ss.top();
	}*/

	SetOfStacks1 ss1;
	for (int i = 0; i < 3 * STACK_SIZE + 1; ++i)
	{
		ss1.push(i);
	}
	for (int i = 0; i < STACK_SIZE; ++i)
	{
		ss1.popAt(0);
		ss1.popAt(2);
	}
	ss1.popAt(3);
	while (!ss1.empty())
	{
		cout << ss1.top() << endl;
		ss1.pop();
	}

	return 0;
}
