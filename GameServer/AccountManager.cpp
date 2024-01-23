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


	// ����
	mutex m1;
	mutex m2;

	lock(m1, m2); // m1, m2 ��� ��

	// adopt_lock : �̹� ���� �ɷ��ִٰ� ����
	lock_guard<mutex> g1(m1, adopt_lock);
	lock_guard<mutex> g2(m2, adopt_lock);

}