#include <vector>
#include <algorithm>
using namespace std;

class CustomStack {
private:
	int* mystack;
	int max_size;
	int cur_size;
public:
	CustomStack(int maxSize) {
		mystack = new int[maxSize];
		max_size = maxSize;
		cur_size = 0;
	}

	void push(int x) {
		if (cur_size < max_size)
		{
			mystack[cur_size++] = x;
		}
	}

	int pop() {
		if (cur_size == 0)
		{
			return -1;
		}
		return mystack[--cur_size];
	}

	void increment(int k, int val) {
		for (int i = 0; i < min(k, cur_size); i++)
		{
			mystack[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */