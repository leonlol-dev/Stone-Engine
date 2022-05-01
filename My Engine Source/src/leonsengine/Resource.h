#pragma once
#include <string>
#include <memory>


namespace myengine
{	
	struct Resources;

	///This is the resource class, which is used by the resources class to store an individual resouce.
	///
	///It only has one function, which is getPath(); this function essentially returns the path the file (resource) is located at and stores it. 
	struct Resource
	{
		virtual void onInit();

		///This gets the path of the resource.
		std::string getPath();

	private:
		//friend struct resources
		friend struct myengine::Resources;
		//std path
		std::string path;
		//self weak ptrs
		std::weak_ptr<Resource> self;
		//resources
		std::weak_ptr<Resources> resources;
	};
}

