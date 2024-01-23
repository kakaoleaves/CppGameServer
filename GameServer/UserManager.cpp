#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave()
{
	// userLock
	lock_guard<mutex> guard(_mutex);

	// accountLock
	Account* account = AccountManager::GetInstance()->GetAccount(100);

	// TODO
}