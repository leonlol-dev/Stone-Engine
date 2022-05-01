#pragma once
#include <memory>
#include <string>
#include <vector>


namespace myengine
{
	struct Resource;

	///This is the resources system within our game engine. It handles all of the resources within our game engine.
	///
	///The resources class works by going through each resource and checking if it already exists, if it doesn't it stores it within the resources vector. 
	///This is memory efficient and can save a lot of memory for our engine. 
	

	struct Resources
	{	
		///This loads the resource and adds the resource to the resources manager.
		///@param _path The path the resource is located at.
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			std::shared_ptr<T> rtn;

			for (size_t ri = 0; ri < resources.size(); ri++)
			{
				std::shared_ptr<Resource> r = resources.at(ri);
				if (r->path != path) continue;
				rtn = std::dynamic_pointer_cast<T>(r);
				if (rtn) return rtn;
			}

			rtn = std::make_shared<T>();
			rtn->path = _path;
			rtn->resources = self;
			rtn->onInit();
			resources.push_back(rtn);
			return rtn;
		}

	private:
		std::string path;
		std::weak_ptr<Resources> self;
		std::vector <std::shared_ptr<Resource>> resources;
	};


}