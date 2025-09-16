#include "Eagle.h"

void Eagle::Fly()
{
	printf("[%s]가 비행합니다.\n", Name.c_str());
	SetEnergy(Energy - 0.3f);
}
