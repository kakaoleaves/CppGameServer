#pragma once
#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() { }
	LockStack(const LockStack&) = delete;
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> lock(_mutex);
		_stack.push(std::move(value));
		_cond.nofity_one();
	}
	bool Empty() // 사실 큰 의미는 없음
	{
		lock_guard<mutex> lock(_mutex);
		return _stack.empty();
	}
	bool TryPop(T& value)
	{
		lock_guard<mutex> lock(_mutex);
		if (_stack.empty())
			return false;

		value = std::move(_stack.top());
		_stack.pop();
		return true;
	}
	void WaitPop(T& value)
	{
		unique_lock<mutex> lock(_mutex);
		_cond.wait(lock, [this] { return !_stack.empty(); });

		value = std::move(_stack.top());
		_stack.pop();
	}
private:
	stack<T> _stack;
	mutex _mutex;
	condition_variable _cond;
};
