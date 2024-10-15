#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include "form.h"
#define N 100


// Array of pointers to form objects
Form a[N];
Form f;

struct form {
	int type;
	float x, y;             // initial point of the form
	float xSize, ySize;     // sides 
	float r, g, b;          // color components
};

// Counter variable
int counter = 0;


int windowY = 900;
int windowX = 900;

// Function to display forms
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the Y-axis and X-axis (vertical and horizontal line through the center)
	glColor3f(1.0, 1.0, 1.0); // Set color to red for the X-axis
	glBegin(GL_LINES);
	glVertex2f(-1.0, 0.0); // Left side of the window
	glVertex2f(1.0, 0.0);  // Right side of the window
	glVertex2f(0.0, -1.0); // Bottom of the window
	glVertex2f(0.0, 1.0);  // Top of the window
	glEnd();

	// Draw the forms
	for (int i = 0; i < N; i++) {
		drawForm(a[i]);
	}

	glFlush();

	// Increment and display the counter value
	counter++;
	printf("Counter: %d\n", counter);
}

Form createRandomForm() {
	Form f;
	switch (rand() % 5)
	{
	case 0:
		f = newRectangle(((float)rand() / RAND_MAX * windowX),
				((float)rand() / RAND_MAX * windowY),
			((float)rand() / RAND_MAX) * 50 - 1,
			((float)rand() / RAND_MAX) * 50 - 1);
		break;
	case 1:
		f = newSquare(((float)rand() / RAND_MAX * windowX),
					((float)rand() / RAND_MAX * windowY),
			((float)rand() / RAND_MAX)*50 - 1);
			
		break;
	case 2:
		f = newTriangleIsos(((float)rand() / RAND_MAX * windowX),
				((float)rand() / RAND_MAX * windowY),
			((float)rand() / RAND_MAX) * 50 - 1,
			((float)rand() / RAND_MAX) * 50 - 1);
		break;
	case 3:
		f = newLine(((float)rand() / RAND_MAX * windowX),
				((float)rand() / RAND_MAX * windowY),
				rand() % windowX,
				rand() % windowY);
		break;
	case 4:
		f = newCircle(((float)rand() / RAND_MAX * windowX),
				((float)rand() / RAND_MAX * windowY),
			((float)rand() / RAND_MAX) * 50 - 1);
		break;
	default:
		f = newRectangle(((float)rand() / RAND_MAX * windowX),
				((float)rand() / RAND_MAX * windowY),
			((float)rand() / RAND_MAX) * 50 - 1,
			((float)rand() / RAND_MAX) * 50 - 1);
		break;
	}
	setBackgroundColor(f, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);

	return f;

}

void init(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, -1.0, 1.0);
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	init(w, h);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	windowX = w;
	windowY = h;
}

void configOpenGL() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowX, windowY);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tela de figuras malucas");
	init(windowX, windowY);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}




int main(int argc, char** argv) {
	for (int i = 0; i < N; i++) {
		a[i] = NULL;
	}


	srand(time(NULL));
	//generateRandomForms(a, 70);

	for (int i = 0; i < N; i++) {
		a[i] = createRandomForm();
		if (a[i] != NULL) {
			printf("Figura %d: ", i);
			printfForm(a[i]);
			printf("\n");
		}
	}

	glutInit(&argc, argv);
	configOpenGL();

	return 0;
}
