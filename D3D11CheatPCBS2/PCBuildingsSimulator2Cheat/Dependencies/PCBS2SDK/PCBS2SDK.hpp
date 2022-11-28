#pragma once
#include "../PCBS2SDK/IlToCppIncludes.h"
#include "../Il2CppResolve/Includes.hpp" //Unity Il2Cpp Includes :D
#include "../Il2CppResolve/Main.hpp" //Main Include to Init Il2Cpp :D

bool InitIl2Cpp() //Intialization Il2Cpp For Working Cheat on PCBS 2 :D 
{
	if (IL2CPP::Initialize(true) && IL2CPP::Thread::Attach(IL2CPP::Domain::Get()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool SetMoney(int money)
{
	Unity::CGameObject* game = Unity::GameObject::Find("CarrerStatus");
	Unity::CComponent* component_statmoney = game->GetMemberValue<Unity::CComponent*>("State"); //Component Money(CarrerStatus.cs) :D
	if (!component_statmoney) {
		return false;
	}
	component_statmoney->SetMemberValue<int>("m_cash", money); //Money Set :D
	return true;
}
void SetLevel(int level_xp)
{
	//Soon :D
}
