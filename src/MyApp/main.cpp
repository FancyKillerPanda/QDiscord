#include "MyLibrary/SomeClass.h"

#include <iostream>

int main( int /*argc*/, char* /*argv*/[] )
{
	SomeClass a( 50 );
	std::cout << "Hello, world!\n";
	std::cout << "Value: " << a.Value() << "\n";

	return 0;
}

#if defined( _WIN32 )

#include <Windows.h>

int WINAPI WinMain( HINSTANCE /*instance*/, HINSTANCE /*prev_instance*/, LPSTR /*cmd_line*/, int /*cmd_show*/ )
{
	return main( __argc, __argv );
}

#endif // _WIN32
