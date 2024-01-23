#include "pch.h"
#include "AccountManager.h"
#include "UserManager.h"

void AccountManager::ProcessLogin()
{
	// accountLock
	lock_guard<mutex> guard(_mutex);

	// userLock
	User* user = UserManager::GetInstance()->GetUser(100);

	// TODO


	// 참고
	mutex m1;
	mutex m2;

	lock(m1, m2); // m1, m2 모두 락

	// adopt_lock : 이미 락이 걸려있다고 가정
	lock_guard<mutex> g1(m1, adopt_lock);
	lock_guard<mutex> g2(m2, adopt_lock);

}