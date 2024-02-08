#pragma once
// 온갖 매크로를 모아놓은 헤더파일

/*-------------
     Crash
-------------*/

// 주어진 cause로 크래시를 발생시킨다.
#define CRASH(cause)						\
{											\
	uint32* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

// condition이 false일 경우 크래시를 발생시킨다.
#define ASSERT_CRASH(condition)				\
{											\
	if (!(condition))						\
	{										\
		CRASH("ASSERT_CRASH");				\
		__analysis_assume(condition);		\
	}										\
}