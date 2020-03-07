#include <queue>
#include <deque>
using namespace std;

class MaxQueue {
	//�����뷴�����������O��1���ģ����Ƿ�����ʱ���ֵ�ȷ�ǡ���
	//�õ���ƽ̯��������Ϊ������n������ÿ����ֻ�ܽ�һ�κͳ�һ�Σ��ǣ�ִ��n�β����Ļ���������2n�Σ�ƽ��ÿ��������2�Σ�Ҳ����O��1��
private:
	queue<int> q;
	deque<int> maxValueQueue;
public:
	MaxQueue() {
		// 1 12 3 4 5 6
		// 1 12 12 12 12 12

		//stack
		//1 12 3 45
		//1 12 12 45

		//queue
		//1 12 34 1 13 12
		//34 13 12
	}

	int max_value() {
		return maxValueQueue.empty() ? -1 : maxValueQueue.front();
	}

	void push_back(int value) {
		q.push(value);
		while (!maxValueQueue.empty() && maxValueQueue.back() < value)
		{
			maxValueQueue.pop_back();
		}
		maxValueQueue.push_back(value);
	}

	int pop_front() {
		if (q.empty())
		{
			return -1;
		}
		int ret = q.front();
		q.pop();
		if (ret == maxValueQueue.front())
		{
			maxValueQueue.pop_front();
		}
		return ret;
	}
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */