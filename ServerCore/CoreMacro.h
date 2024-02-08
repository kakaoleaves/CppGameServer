#pragma once
// �°� ��ũ�θ� ��Ƴ��� �������

/*-------------
     Crash
-------------*/

// �־��� cause�� ũ���ø� �߻���Ų��.
#define CRASH(cause)						\
{											\
	uint32* crash = nullptr;				\
	__analysis_assume(crash != nullptr);	\
	*crash = 0xDEADBEEF;					\
}

// condition�� false�� ��� ũ���ø� �߻���Ų��.
#define ASSERT_CRASH(condition)				\
{											\
	if (!(condition))						\
	{										\
		CRASH("ASSERT_CRASH");				\
		__analysis_assume(condition);		\
	}										\
}