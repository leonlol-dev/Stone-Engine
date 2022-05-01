#pragma once

#include <memory>
#include <vector>
#include <SDL.h>


namespace myengine
{
	struct Entity;
	struct Environment;
	struct Screen;
	struct Keyboard;
	struct Transform;
	struct SphereCollider;
	struct Trigger;
	struct Resources;
	struct Camera;

	/// This is the game's core. 
	///
	/// The core is essentially the main part of the game engine. It handles many things such as the game loop, keyboard, environment, screen, resources, collision and entities.
	/// @note The game is centred around the Core. 

	struct Core
	{
		///Initialise SDL, AL, environment, keyboard, screen, resources and camera.
		static std::shared_ptr<Core> initialize();

		///Adds an entity.
		std::shared_ptr<Entity> addEntity();
		
		///Gets the environment (delta time).
		std::shared_ptr<Environment> getEnvironment();

		///Returns the keyboard for input.
		std::shared_ptr<Keyboard> getKeyboard();

		///Get screen for width and height.
		///@note This is needed for the Projection Matrix.
		std::shared_ptr<Screen> getScreen();

		///Returns the resources vector.
		std::shared_ptr<Resources> getResources();

		///Returns the camera.
		std::shared_ptr<Camera> getCamera();

		///Returns SDL_Window, which is the game's window.
		SDL_Window* getWindow(); 
		
		///Registers a collider within our engine.
		///@param sphere This is the Sphere Collider.
		void registerCollider(std::shared_ptr<SphereCollider> sphere);

		///Unregisters the colliders once destroyed.
		///@param sphere This is the Sphere Collider.
		void unregisterCollider(SphereCollider* sphere);

		///Registers a camera.
		///@param sphere This is the Camera.
		void registerCamera(std::shared_ptr<Camera> cam);

		///Unregisters a camera once destroyed.
		///@param sphere This is the Camera.
		void unregisterCamera(Camera* cam);

		///Start core.
		void start();
		
		///Stop Core (exit game).
		void stop();

	private:
		friend struct Trigger;
		std::vector<std::shared_ptr<Entity> > entities;
		std::weak_ptr<Core> self;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Resources> resources;
		std::vector<std::shared_ptr <SphereCollider> > sphereColliders;
		std::shared_ptr<Camera>  camera;
	
		bool running;
		SDL_Window* window;
		std::shared_ptr<Environment> environment;
		

	};
}