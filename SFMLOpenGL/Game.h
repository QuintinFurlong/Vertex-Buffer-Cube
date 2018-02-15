#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Vector3.h>
#include <Matrix3.h>

using namespace std;
using namespace sf;
//using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
	static const int POINTS = 36;
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	Vector3Class offset{ 0, 0, 6 };
};