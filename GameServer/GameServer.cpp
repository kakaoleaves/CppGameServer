#include "pch.h"
#include "Corepch.h"
#include <iostream>
#include <atomic>
#include <mutex>
#include "windows.h"
#include <future>
#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

LockQueue<int32> q;
LockStack<int32> s;

void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		q.Push(value);

		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void Pop()
{
	while (true)
	{
		int32 value;
		q.WaitPop(OUT value);
		cout << value << endl;
	}
}

int main()
{
	thread t1(Push);
	thread t2(Pop);
	thread t3(Pop);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}