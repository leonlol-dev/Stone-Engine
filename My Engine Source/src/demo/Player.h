#include <leonsengine/myEngine.h>

using namespace myengine;

struct Player : Component
{
	void onInit();
	void onTick();
	void onCollision(std::shared_ptr<SphereCollider> sc);

};