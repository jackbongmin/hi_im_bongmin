#include "D0922.h"
#include "Map.h"
#include "BattleShip.h"
#include <random>
#include "BinarySearchTree.h"

void D0922::TestBattleShip()
{
	//Map::IsValidPoition(10, 20);	// static 함수는 이렇게 사용 가능

	srand(time(0));

	BattleShip Game;
	Game.Play();

}

void D0922::TestTree()
{
	BinarySearchTree bst;
	bst.Insert(30);
	bst.Insert(50);
	bst.Insert(10);
	bst.PrintPreOrder();
}
