//#include "Test.h"
//#include "Actor.h"
//#include "Monster.h"
//#include "Player.h"
//
//void Test::TestBattle()
//{
//	Actor* Player = new Player("플레이어", 100.0f, 25.0f);
//	Actor* Enemy = new Monster1("고블린", 30.0f, 10.0f);
//
//	while (Player->IsAlive() && Enemy->IsAlive())
//	{
//		Player->Attack(Enemy);
//		if (!Enemy->IsAlive())
//		{
//			//캐스팅해서 돈주기
//			break;
//		}
//		Enemy->Attack(Player);
//	}
//
//	delete Enemy;
//	Enemy = nullptr;
//	delete Player;
//	Player = nullptr;
//}
