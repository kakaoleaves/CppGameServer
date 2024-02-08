#include "pch.h"
#include "Corepch.h"
#include <iostream>
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <future>
#include "ThreadManager.h"

CoreGlobal Core;

void ThreadMain()
{
	while (true)
	{
		cout << "Hello I am thread..." << LThreadId << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		GThreadManager->Launch(ThreadMain);
	}

	GThreadManager->Join();

	return 0;
}