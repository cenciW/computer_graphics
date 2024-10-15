#include "form.h"
#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include <math.h>

#define PI 3.14159265

// this struct is encapsulated
struct form {
	int type;
	float x, y;             // initial point of the form
	float xSize, ySize;     // sides 
	float r, g, b;
};

Form newForm(int type, float x, float y, float xSize, float ySize) {
	Form f = (Form)malloc(sizeof(struct form));

	if (f == NULL) {
		fprintf(stderr, "Erro ao alocar memória para a nova forma.\n");
		exit(EXIT_FAILURE);
	}


    f->x = x;
    f->y = y;
    f->xSize = xSize;
    f->ySize = ySize;
    f->type = type;
   
	f->r = 1.0;
	f->g = 1.0;
	f->b = 1.0;
	return f;
}



Form newFormC(int type, float x, float y, float xSize, float ySize) {
	return newForm(type, x - (xSize / 2), y - (ySize / 2), xSize, ySize);
}

Form newRectangle(float x, float y, float xSize, float ySize) {
	
	Form rectangle = newForm(RECTANGLE, x, y, xSize, ySize);
	return rectangle;
}

Form newSquare(float x, float y, float side) {
	Form square = newForm(SQUARE, x, y, side, side);
	return square;
}

Form newTriangleIsos(float x, float y, float xSize, float ySize) {
	return newForm(TRIANGLE_ISOS, x, y, xSize, ySize);
}

Form newLine(float x, float y, float xSize, float ySize) {
	return newForm(LINE, x, y, xSize, ySize);
}

Form newCircle(float x, float y, float radius) {
	return newForm(CIRCLE,x, y, radius, radius);
}


void deleteForm(Form f) {
	free(f);
}

void updateForm(Form f, float dx, float dy) {
	f->x += dx;
	f->y += dy;
}

void setBackgroundColor(Form f, float r, float g, float b) {
	f->r = r;
	f->g = g;
	f->b = b;
}


void printfForm(Form f) {
	printf("Graphical Form BBox: (%.2f,%.2f), (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f) |\n R: %.2f, G: %.2f, B: %.2f\t\n",
		f->x, f->y,
		f->x, f->y + f->ySize,
		f->x + f->xSize, f->y + f->ySize,
		f->x + f->xSize, f->y, f->r, f->g, f->b);


	printf("Center(%.2f,%.2f) Size{%.2f,%.2f}\n",
		f->x + (f->xSize / 2), f->y + (f->ySize / 2),
		f->xSize, f->ySize);

}

void drawBox(Form f) {
	glColor3f(f->r, f->g, f->b);
	glBegin(GL_POLYGON);
		glVertex2f(f->x, f->y);
		glVertex2f(f->x, f->y + f->ySize);
		glVertex2f(f->x + f->xSize, f->y + f->ySize);
		glVertex2f(f->x + f->xSize, f->y);
	glEnd();

	glColor3f(rand() / (RAND_MAX * 1), rand() / (RAND_MAX * 1), rand() / (RAND_MAX * 1));
	glBegin(GL_LINE_LOOP);
		glVertex2f(f->x, f->y);
		glVertex2f(f->x, f->y + f->ySize);
		glVertex2f(f->x + f->xSize, f->y + f->ySize);
		glVertex2f(f->x + f->xSize, f->y);
	glEnd();

	glFlush();

}

void drawTriangleIso(Form f) {
	glColor3f(f->r, f->g, f->b);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(f->x, f->y);
	glVertex2f(f->x + (f->xSize/2.0), f->y + f->ySize);
	glVertex2f(f->x + f->xSize, f->y);
	glEnd();

	glColor3f(rand() / (RAND_MAX * 1), rand() / (RAND_MAX * 1), rand() / (RAND_MAX * 1));
	glBegin(GL_LINE_LOOP);
	glVertex2f(f->x, f->y);
	glVertex2f(f->x + (f->xSize / 2.0), f->y + f->ySize);
	glVertex2f(f->x + f->xSize, f->y);
	glEnd();

	glFlush();

}

void drawCircle(Form f, float radius, float faces) {

	float centerX = f->x + (f->xSize / 2);
	float centerY = f->y + (f->xSize / 2);

	float step = (2 * PI) / faces;

	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * PI; i += step) {
		float x = centerX + radius * cos(i);
		float y = centerY + radius * sin(i);

		glVertex2f(x, y);
	}
	printf("Center(%.2f,%.2f) Size{%.2f,%.2f}\n",
		centerX, centerY,
		radius, radius);	

	glEnd();
	glFlush();

}

void drawForm(Form f) {
	switch (f->type) {
	case RECTANGLE:
		drawBox(f);
		break;
	case SQUARE:
		drawBox(f);
		break;
	case TRIANGLE_ISOS:
		drawTriangleIso(f);		
		break;
	case LINE:
		//drawLine(f);
		break;
	case CIRCLE:
		drawCircle(f, f->xSize / 2, 50);
		break;
	}
}
