#include "Line.hpp"

Line::Line(int x1, int y1, int x2, int y2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}
void Line::draw(void)
{   

	//ref -> https://discourse.glfw.org/t/a-very-basic-issue-with-draw-line/804/2
	GLFWwindow* window;

	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		exit( EXIT_FAILURE );
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow( 400, 400, "LearnOpenGL", NULL, NULL );
	if (!window)
	{
		fprintf( stderr, "Failed to open GLFW window\n" );
		glfwTerminate();
		exit( EXIT_FAILURE );
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval( 1 );

	// set up view
	glViewport( 0, 0, 400, 400 );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
	glOrtho(0.0,400.0,0.0,400.0,0.0,1.0); // this creates a canvas you can do 2D drawing on


	// Main loop
	while( !glfwWindowShouldClose(window) )
	{
		// Draw gears
		glClearColor ( 1.0f, 1.0f, 1.0f, 1.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPointSize(10);
		glLineWidth(6); 
		glColor3f(1.0, 0.5, 0.0);
		glBegin(GL_LINES);
		glVertex3f(x1,y1,0.0);
		glVertex3f(x2,y2,0.0);
		glEnd();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwTerminate();
	
}

void Line::move(int x, int y)
{
    this->x1 += x;
    this->x2 += x;
    this->y1 += y;
    this->y2 += y;
}

void Line::scale(double scaleBy)
{
    this->x2 *= scaleBy;
}

void Line::writeToFile(std::ofstream &out)
{
    out << "Line " << this->x1 << " " << this->y1 << " " << this->x2 << " " << this->y2 << std::endl;
}

void Line::readFromFile(std::ifstream &in)
{
    in >> this->x1 >> this->y1 >> this->x2 >> this->y2;
}

int Line::getx1(void)
{
    return this->x1;
}
int Line::getx2(void)
{
    return this->x2;
}
int Line::gety1(void)
{
    return this->y1;
}
int Line::gety2(void)
{
    return this->y2;
}