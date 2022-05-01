#include <leonsengine/myEngine.h>

using namespace myengine;

struct Enemy : Component
{
	Enemy(bool _spin);
	void onInit();
	void onTick();
	void onCollision(std::shared_ptr<SphereCollider> sc);

private:
	std::shared_ptr<ModelRenderer> modelrend;

	std::shared_ptr<Model> skeleton;
	std::shared_ptr<Texture> skeletontex;

	std::shared_ptr<AudioSource> audio1;
	std::shared_ptr<AudioClip> s;
	bool spin;
	bool hasEntered;

};