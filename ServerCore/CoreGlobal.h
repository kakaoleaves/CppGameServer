#pragma once

extern class ThreadManager* GThreadManager;

// main에서 new, delete 해주는 대신, 엔진에서 관리하기 위함
// Manager의 순서를 맞춰줘야 하는 경우 고려
class CoreGlobal
{
public:
	CoreGlobal();
	~CoreGlobal();
};