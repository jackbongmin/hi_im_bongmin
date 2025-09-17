#pragma once
#include "Animal.h"
#include "IFlyable.h"

class Eagle : public Animal, public IFlyable 
{
public:
	virtual void Move() override;	// 독수리는 Animal의 Move함수를 덮어쓸꺼다.

	virtual void MakeSound() override;

	virtual void Fly() override;

public:
	// 생성자, 소멸자는 상속의 대상이 아니다.
	Eagle() = default;
	Eagle(std::string InName)
		: Animal(InName)			// 부모 클래스인 Animal에서 생성자 처리하는 것과 똑같이 해라.
	{

	}
	virtual ~Eagle() {};
};

