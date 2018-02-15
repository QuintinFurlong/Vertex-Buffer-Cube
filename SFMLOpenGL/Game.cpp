#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

Vector3Class corners[] = { Vector3Class(-1.0f, 1.0f, -7.0f),Vector3Class(1.0f, 1.0f, -7.0f),
Vector3Class(-1.0f, 1.0f, -5.0f), Vector3Class(1.0f, 1.0f, -5.0f), Vector3Class(-1.0f, -1.0f, -7.0f),
Vector3Class(1.0f, -1.0f, -7.0f),Vector3Class(-1.0f, -1.0f, -5.0f), Vector3Class(1.0f, -1.0f, -5.0f) };

float vertices[] = { (corners[2].X()), (corners[2].Y()), (corners[2].Z()),
(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
(corners[7].X()), (corners[7].Y()), (corners[7].Z()),
(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
(corners[1].X()), (corners[1].Y()), (corners[1].Z()),
(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
(corners[4].X()), (corners[4].Y()), (corners[4].Z()),
(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
(corners[1].X()), (corners[1].Y()), (corners[1].Z()) };

float colors[] = { 1.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f,
1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 1.0f, 0.0f,
0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 1.0f,
1.0f, 1.0f, 0.0f,
1.0f, 1.0f, 0.0f,
1.0f, 1.0f, 0.0f,
0.0f, 1.0f, 1.0f,
0.0f, 1.0f, 1.0f };
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex2;

Vertex2 vertex[10];
GLubyte triangles[10];

/* Variable to hold the VBO identifier */
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/*glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);*/

	/* Vertices counter-clockwise winding */

	(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[7].X()), (corners[7].Y()), (corners[7].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),

		(corners[1].X()), (corners[1].Y()), (corners[1].Z()),
		(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[4].X()), (corners[4].Y()), (corners[4].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[1].X()), (corners[1].Y()), (corners[1].Z());

	vertex[0].coordinate[0] = corners[2].X();
	vertex[0].coordinate[1] = corners[2].Y();
	vertex[0].coordinate[2] = corners[2].Z();

	vertex[1].coordinate[0] = corners[3].X();
	vertex[1].coordinate[1] = corners[3].Y();
	vertex[1].coordinate[2] = corners[3].Z();

	vertex[2].coordinate[0] = corners[6].X();
	vertex[2].coordinate[1] = corners[6].Y();
	vertex[2].coordinate[2] = corners[6].Z();

	vertex[3].coordinate[0] = corners[7].X();
	vertex[3].coordinate[1] = corners[7].Y();
	vertex[3].coordinate[2] = corners[7].Z();

	vertex[4].coordinate[0] = corners[5].X();
	vertex[4].coordinate[1] = corners[5].Y();
	vertex[4].coordinate[2] = corners[5].Z();

	vertex[5].coordinate[0] = corners[3].X();
	vertex[5].coordinate[1] = corners[3].Y();
	vertex[5].coordinate[2] = corners[3].Z();

	vertex[6].coordinate[0] = corners[1].X();
	vertex[6].coordinate[1] = corners[1].Y();
	vertex[6].coordinate[2] = corners[1].Z();

	vertex[7].coordinate[0] = corners[2].X();
	vertex[7].coordinate[1] = corners[2].Y();
	vertex[7].coordinate[2] = corners[2].Z();

	vertex[8].coordinate[0] = corners[0].X();
	vertex[8].coordinate[1] = corners[0].Y();
	vertex[8].coordinate[2] = corners[0].Z();

	vertex[9].coordinate[0] = corners[6].X();
	vertex[9].coordinate[1] = corners[6].Y();
	vertex[9].coordinate[2] = corners[6].Z();

	vertex[10].coordinate[0] = corners[4].X();
	vertex[10].coordinate[1] = corners[4].Y();
	vertex[10].coordinate[2] = corners[4].Z();

	vertex[11].coordinate[0] = corners[5].X();
	vertex[11].coordinate[1] = corners[5].Y();
	vertex[11].coordinate[2] = corners[5].Z();

	vertex[12].coordinate[0] = corners[0].X();
	vertex[12].coordinate[1] = corners[0].Y();
	vertex[12].coordinate[2] = corners[0].Z();

	vertex[13].coordinate[0] = corners[1].X();
	vertex[13].coordinate[1] = corners[1].Y();
	vertex[13].coordinate[2] = corners[1].Z();



	vertex[0].color[0] = .5;
	vertex[0].color[1] = .5;
	vertex[0].color[2] = .5;

	vertex[1].color[0] = .5;
	vertex[1].color[1] = .5;
	vertex[1].color[2] = .5;

	vertex[2].color[0] = .5;
	vertex[2].color[1] = .5;
	vertex[2].color[2] = .5;

	vertex[3].color[0] = .5;
	vertex[3].color[1] = .5;
	vertex[3].color[2] = .5;

	vertex[4].color[0] = .5;
	vertex[4].color[1] = .5;
	vertex[4].color[2] = .5;

	vertex[5].color[0] = .5;
	vertex[5].color[1] = .5;
	vertex[5].color[2] = .5;

	vertex[6].color[0] = .5;
	vertex[6].color[1] = .5;
	vertex[6].color[2] = .5;

	vertex[7].color[0] = .5;
	vertex[7].color[1] = .5;
	vertex[7].color[2] = .5;

	vertex[8].color[0] = .5;
	vertex[8].color[1] = .5;
	vertex[8].color[2] = .5;

	vertex[9].color[0] = .5;
	vertex[9].color[1] = .5;
	vertex[9].color[2] = .5;

	vertex[10].color[0] = .5;
	vertex[10].color[1] = .5;
	vertex[10].color[2] = .5;

	vertex[11].color[0] = .5;
	vertex[11].color[1] = .5;
	vertex[11].color[2] = .5;

	vertex[12].color[0] = .5;
	vertex[12].color[1] = .5;
	vertex[12].color[2] = .5;

	vertex[13].color[0] = .5;
	vertex[13].color[1] = .5;
	vertex[13].color[2] = .5;



	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;
	triangles[6] = 6;   triangles[7] = 7;   triangles[8] = 8;
	triangles[9] = 9;   triangles[10] = 10;   triangles[11] = 11;
	triangles[12] = 12;   triangles[13] = 13;

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2) * POINTS, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * POINTS, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	//Change vertex data
	/*vertex[0].coordinate[0] += -0.0001f;
	vertex[0].coordinate[1] += -0.0001f;
	vertex[0].coordinate[2] += -0.0001f;*/

	Matrix3 m1;
	Vector3Class temp;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Rotation(1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Rotation(-1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.RotationX(1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.RotationX(-1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.RotationY(1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		//glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.RotationY(-1) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		//glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Translate(.01, .01) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		offset = offset + Vector3Class(.01, .01, 0);
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Translate(-.01, -.01) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		offset = offset + Vector3Class(-.01, -.01, 0);
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Scale(99, 99) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		glTranslatef(-offset.X(), -offset.Y(), -offset.Z());
		for (int inde = 0; inde < POINTS; inde++)
		{
			temp = m1.Scale(101, 101) * Vector3Class(vertex[inde].coordinate[0], vertex[inde].coordinate[1], vertex[inde].coordinate[2]);
			vertex[inde].coordinate[0] = temp.X();
			vertex[inde].coordinate[1] = temp.Y();
			vertex[inde].coordinate[2] = temp.Z();
		}
		glTranslatef(offset.X(), offset.Y(), offset.Z());
	}

	/*float temp[] = { (corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[7].X()), (corners[7].Y()), (corners[7].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[3].X()), (corners[3].Y()), (corners[3].Z()),
		(corners[1].X()), (corners[1].Y()), (corners[1].Z()),
		(corners[2].X()), (corners[2].Y()), (corners[2].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[6].X()), (corners[6].Y()), (corners[6].Z()),
		(corners[4].X()), (corners[4].Y()), (corners[4].Z()),
		(corners[5].X()), (corners[5].Y()), (corners[5].Z()),
		(corners[0].X()), (corners[0].Y()), (corners[0].Z()),
		(corners[1].X()), (corners[1].Y()), (corners[1].Z()) };*/

	//std::copy(temp, temp + 42, vertices);

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2) * POINTS, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex2), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex2), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLE_STRIP, POINTS, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	//glDrawElements(GL_TRIANGLE_STRIP, 14, GL_UNSIGNED_INT, &vertex_index);


	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

