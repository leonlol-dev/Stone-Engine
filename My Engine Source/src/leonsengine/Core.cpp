#include "Core.h"
#include "Entity.h"
#include <GL/glew.h>
#include "screen.h"
#include "Environment.h"
#include <iostream>
#include "TriangleRenderer.h"
#include "Keyboard.h"
#include "Transform.h"
#include "Resource.h"
#include "Resources.h"
#include "Camera.h"

#include <AL/al.h>
#include <AL/alc.h>


namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;
		rtn->running = false;
		rtn->screen = std::make_shared<Screen>();
		rtn->resources = std::make_shared<Resources>();
		rtn->environment = std::make_shared<Environment>();
		rtn->keyboard = std::make_shared<Keyboard>();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}


		rtn->window = SDL_CreateWindow("My Engine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->screen->getWidth(), rtn->screen->getHeight(),
			SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);



		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}
		
		ALCdevice* device = alcOpenDevice(NULL);
		if (!device)
		{
			throw std::exception();
		}
		ALCcontext* context = alcCreateContext(device, NULL);
		if (!context)
		{
			alcCloseDevice(device);
			throw std::exception();
		}
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::exception();
		}

	
		return rtn;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->self = rtn;
		rtn->core = self;
		rtn->transform = rtn->addComponent<Transform>();
		entities.push_back(rtn);
		return rtn;
	}

	std::shared_ptr<Environment> Core::getEnvironment()
	{
		return environment;
	}

	std::shared_ptr<Keyboard> Core::getKeyboard()
	{
		return keyboard;
	}

	SDL_Window* Core::getWindow()
	{
		return window;
	}

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{	
		return camera;
	}

	void Core::unregisterCamera(Camera* cam)
	{
		camera.reset();
	}


	void Core::registerCollider(std::shared_ptr<SphereCollider> sphere)
	{
		sphereColliders.push_back(sphere);
	}

	void Core::unregisterCollider(SphereCollider* sphere)
	{
		for (size_t ci = 0; ci < sphereColliders.size(); ci++)
		{
			if (sphereColliders[ci].get() == sphere)
			{
				sphereColliders.erase(sphereColliders.begin() + ci);
				ci--;
			}
		}


	}

	void Core::registerCamera(std::shared_ptr<Camera> cam)
	{
		camera = cam;
	}

	void Core::start()
	{
		running = true;

		//on Start
		for (size_t ei = 0; ei < entities.size(); ei++)
		{
			entities.at(ei)->begin();
		}

		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}

				else if (event.type == SDL_KEYDOWN)
				{
					keyboard->keyCodes.push_back(event.key.keysym.sym);
				}

				else if (event.type == SDL_KEYUP)
				{
					keyboard->removeKey(event.key.keysym.sym);
				}
			}
			std::cout << environment->calculateDeltaTme() << std::endl;
			
			//Update world
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->tick();
			}

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glEnable(GL_DEPTH_TEST);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


			//Display
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->display();
			}


			//Render
			SDL_GL_SwapWindow(window);

		}
	}

	void Core::stop()
	{
		running = false;

		// Remember to close after use
		//alcMakeContextCurrent(NULL);
		//alcDestroyContext(context);
		//alcCloseDevice(device);

	}

}