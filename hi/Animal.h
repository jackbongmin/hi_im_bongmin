#pragma once
#include <string>

//
//	���� Ŭ���� ������
//	Name : std::string
//	Energy : float
//	Age : int
//
//	������ �����̸�(Move) �������� �Һ��Ѵ�.
//	������ �Ҹ��� ���� �� �ִ�.(MakeSound)
//	������ ������(Eat) �������� �����Ѵ�.
//	������ ���� �ڸ�(Sleep) ���̰� �����ϰ� �������� ���� ȸ���ȴ�.
//	������ ��� ������ ����� �� �ִ�.(ShoInfo)
//

class Animal
{
public:

	inline const std::string& GetName() const { return Name; }

	inline const int GetAge() const { return Age; }

	// Energy�� �ܺο����� �б� �����̴�.
	inline const float GetEnergy() const { return Energy; } // getter



	Animal() = default;
	Animal(std::string InName)
		: Name(InName)
	{} // ª�� ���� �Լ��� ������ ����� �־ �ȴ�.(�ڵ� inline ó��)
	virtual ~Animal() {}

	virtual void Move();	// Move�� �����Լ���.
	virtual void MakeSound();
	void Eat();
	void Sleep();
	void ShowInfo();

protected:

	inline void SetEnergy(float InEnergy)			// setter
	{
		// Energy�� ������ 0.0f ~ 1.0f�̴�.
		if (InEnergy < 0)
		{
			Energy = 0.0f;
		}
		else if (InEnergy > 1.0f)
		{
			Energy = 1.0f;
		}
		else
		{
			Energy = InEnergy;
		}
	}
	
	std::string Name = "����";

	int Age = 0;
	
	float Energy = 1.0f;	// 0.0f ~ 1.0f : 1.0f�϶� 100% 

};

