#include <exception>
#include <string>

namespace myengine
{
	///The Exception class handles the error messages throughout the game engine.
	

	class Exception : public std::exception
	{
	public:

		///This gives an error to the player/developer.
		///@param message This is the message that the user will get. 
		Exception(std::string message);
		~Exception() throw();

		///Returns what the error/exception was.
		const char* what();

	private:
		std::string message;
	};
}