#include <leonsengine/myEngine.h>

using namespace myengine;

struct Player : Component
{
	void onInit();
	void onTick();

private:
	std::shared_ptr<TriangleRenderer> tri;
	


};