#include "Eagle.h"

void Eagle::Fly()
{
	printf("[%s]�� �����մϴ�.\n", Name.c_str());
	SetEnergy(Energy - 0.3f);
}
