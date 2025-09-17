#pragma once
#include <type_traits>

class D0917
{
public:
	void TestPolymorphism();
	void TestVirtualFunction();

	void TestPractice1();
	void TestAbstractClass();
	void TestEnumClass();

private:
	// static : ���� ���
	static constexpr int Size = 5;
	int Test[D0917::Size]; // ���� ����� Ŭ���� �̸����� �����ؾ� �մϴ�.
};

// uint8_t�� ����Ϸ��� #include <stdint.h>�� �ʿ�
enum class PlayerState : uint8_t
{
	None = 0,
	OnGround = 1 << 0,
	Jumping = 1 << 1,
	Stunned = 1 << 2,
	Poisoned = 1 << 3,
	Invisible = 1 << 4,
	Invincible = 1 << 5,
	Flying = 1 << 6
};

// PlayerState�� ���� Ÿ���� StateType�̶�� ���ڰ� ���ϴ� ��
// using StateType = uint8_t;
// #include <type_traits> �ʿ�
using StateType = std::underlying_type_t<PlayerState>;

inline PlayerState operator|(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<int>(Left) | static_cast<int>(Right));
};

inline PlayerState operator&(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<int>(Left) & static_cast<int>(Right));
};

inline PlayerState operator~(PlayerState Value)
{
	return static_cast<PlayerState>(~static_cast<int>(Value));
}

inline PlayerState& operator|=(PlayerState& Left, PlayerState Right)
{
	Left = Left | Right;
	return Left;
}

inline PlayerState& operator&=(PlayerState& Left, PlayerState Right)
{
	Left = Left & Right;
	return Left;
}