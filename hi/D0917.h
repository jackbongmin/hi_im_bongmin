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
	// static : 정적 멤버
	static constexpr int Size = 5;
	int Test[D0917::Size]; // 정적 멤버는 클래스 이름으로 참조해야 합니다.
};

// uint8_t를 사용하려면 #include <stdint.h>가 필요
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

// PlayerState의 원래 타입을 StateType이라고 하자고 정하는 것
// using StateType = uint8_t;
// #include <type_traits> 필요
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