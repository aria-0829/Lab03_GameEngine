#include <iostream>
#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine::Instance().Initialize(); 
	Engine::Instance().GameLoop(); 
	Engine::Instance().Destroy(); 

	return 0;
}