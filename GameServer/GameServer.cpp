#include "pch.h"
#include <iostream>
#include "Corepch.h"
#include <thread>

void HelloThread() 
{
	cout << "Hello Thread" << endl;
}

void HelloThread2(int32 num)
{
	cout << num << endl;
}

int main()
{
	thread t1;
	auto id = t1.get_id(); cout << id << endl; // 0
	t1 = thread(HelloThread);
	id = t1.get_id(); cout << id << endl; // new id
	int32 cnt = t1.hardware_concurrency(); cout << "CPU Core Count: " << cnt << endl;
	if (t1.joinable()) t1.join();

	cout << "===================================" << endl;

	vector<thread> threads;
	for (int32 i = 0; i < 10; ++i)
		threads.push_back(thread(HelloThread2, i));

	for (auto& t : threads)
		if (t.joinable()) t.join();

	cout << "Main Thread" << endl;

	return 0;
}