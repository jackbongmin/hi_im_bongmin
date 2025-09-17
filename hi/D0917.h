#pragma once
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

inline PlayerState operator|(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<int>(Left) | static_cast<int>(Right));
};

inline PlayerState operator&(PlayerState Left, PlayerState Right)
{
	return static_cast<PlayerState>(static_cast<int>(Left) & static_cast<int>(Right));
};
