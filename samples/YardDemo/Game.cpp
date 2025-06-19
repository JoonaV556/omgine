#include <iostream>
#include <string>
#include <Engine.h>

using namespace std;

// This is entry point of example game app

int main(int argc, char *argv[])
{

    Engine *engine = new Engine();
    engine->Run();
    return 0;
}
