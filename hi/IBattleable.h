#pragma once

class IBattleable
{
public:
	virtual void Battle() = 0;

	virtual ~IBattleable() {};
};