// lower_bound/upper_bound example
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int s = m_queue.size();
		m_queue.push(x);
        for(int i=0; i<s; ++i) {
			m_queue.push(m_queue.front());
            m_queue.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
		m_queue.pop();
    }

    // Get the top element.
    int top() {
		return m_queue.front();
    }

    // Return whether the stack is empty.
    bool empty() {
		return m_queue.empty();
    }
private:
    queue<int> m_queue;
};

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
		m_stack_back.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
		if(m_stack_front.empty())
			this->move_back_2_front();
		m_stack_front.pop();
    }

    // Get the front element.
    int peek(void) {
		if(m_stack_front.empty())
			this->move_back_2_front();

		return m_stack_front.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return m_stack_back.empty() && m_stack_front.empty();
    }
private:
	void move_back_2_front(){
		while(!m_stack_back.empty()){
			m_stack_front.push(m_stack_back.top());
			m_stack_back.pop();
		}
	}
private:
	stack<int> m_stack_back;
	stack<int> m_stack_front;
};

int main () {
	Queue m;
	m.push(2);
	m.push(3);
	m.push(7);
	m.push(9);
	cout<< m.peek() <<endl;
	m.pop();
	cout<< m.peek() <<endl;
	return 0;
}
