#include "TesterObject.h"
#include "KeyStateTest.h"

TesterObject::TesterObject()
{

	
	UpdateObject::SubmitUpdateRegistration();
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_T, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_T, INPUT_EVENT_TYPE::KEY_RELEASE);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_B, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_B, INPUT_EVENT_TYPE::KEY_RELEASE);

	AlarmObject::SubmitAlarmRegistration(1.0f, AlarmObjectManager::ALARM_0);
	AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_1);
	AlarmObject::SubmitAlarmRegistration(3.0f, AlarmObjectManager::ALARM_2);
	AlarmObject::SubmitAlarmRegistration(4.0f, AlarmObjectManager::ALARM_3);
	AlarmObject::SubmitAlarmRegistration(5.0f, AlarmObjectManager::ALARM_4);

	CollisionObject::SubmitCollisionRegistration<TesterObject>(this);

}

void TesterObject::Update()
{

}

void TesterObject::KeyPressed(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_T:
		DebugMsg::out("\nT key pressed by tester object");
		//InputObject::SubmitInputDeregistration(AZUL_KEY::KEY_B, INPUT_EVENT_TYPE::KEY_RELEASE);
		break;
	case AZUL_KEY::KEY_B:
		DebugMsg::out("\nB key pressed by tester object");
	}
}

void TesterObject::KeyReleased(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_T:
		DebugMsg::out("\nT key released by tester object");
		//InputObject::SubmitInputDeregistration(AZUL_KEY::KEY_T, INPUT_EVENT_TYPE::KEY_RELEASE);
		break;
	case AZUL_KEY::KEY_B:
		DebugMsg::out("\nB key released by tester object");
	}
}

void TesterObject::Alarm0()
{
	if (!alarm_three_off)
	{
		//DebugMsg::out("\n\nTesterObject Alarm ZERO\nRemoving Alarm Three");
		AlarmObject::SubmitAlarmDeregistration(AlarmObjectManager::ALARM_3);
		alarm_three_off = true;
	}
	else
	{
		//DebugMsg::out("\n\nTesterObject Alarm ZERO");
	}
	AlarmObject::SubmitAlarmRegistration(1.0f, AlarmObjectManager::ALARM_0);
}

void TesterObject::Alarm1()
{
	//DebugMsg::out("\n\nTesterObject Alarm ONE");
	AlarmObject::SubmitAlarmDeregistration(AlarmObjectManager::ALARM_0);

}

void TesterObject::Alarm2()
{
	//DebugMsg::out("\n\nTesterObject Alarm TWO");
}

void TesterObject::Alarm3()
{
	//DebugMsg::out("\n\nTesterObject Alarm THREE");
}

void TesterObject::Alarm4()
{
	//DebugMsg::out("\n\nTesterObject Alarm FOUR");
}