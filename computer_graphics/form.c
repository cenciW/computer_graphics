#include "form.h"
#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>

#define PI 3.1415


Form newForm(float x, float y, float xSize, float ySize, int type) {
    Form f = (Form)malloc(sizeof(struct form));
	if (f == NULL) {
		printf("Error allocating memory\n");
		exit(1);
	}

    f->x = x;
    f->y = y;
    f->xSize = xSize;
    f->ySize = ySize;

    f->r = 1.0;
    f->g = 1.0;
    f->b = 1.0;

    f->type = type;

    return f;
}

Form newFormC(float x, float y, float xSize, float ySize, int type) {
    return newForm(x - (xSize / 2), y - (ySize / 2), xSize, ySize, type);
}

Form newRectangle(float x, float y, float xSize, float ySize) {
    return newForm(x, y, xSize, ySize, RECTANGLE);
}

Form newSquare(float x, float y, float side) {
    return newForm(x, y, side, side, SQUARE);
}

Form newTriangleIso(float x, float y, float xSize, float ySize) {
    return newForm(x, y, xSize, ySize, TRIANGLE_ISO);
}

Form newHexagon(float x, float y, float xSize, float ySize) {
    return newForm(x, y, xSize, ySize, HEXAGON);
}

Form newCircle(float x, float y, float radius) {
    return newForm(x, y, radius, radius, CIRCLE);
}

Form newTriangleEq(float x, float y, float side) {
    return newForm(x, y, side, side, EQ_TRIANGLE);
}

void setBackgroundColor(Form f, float r, float g, float b) {
    f->r = r;
    f->g = g;
    f->b = b;
}

void deleteForm(Form f) {
    free(f);
}

void updateForm(Form f, float dx, float dy) {
    f->x += dx;
    f->y += dy;
}


void printfForm(Form f) {
    printf("Graphical Form BBox: (%.2f,%.2f), (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\t",
        f->x, f->y,
        f->x, f->y + f->ySize,
        f->x + f->xSize, f->y + f->ySize,
        f->x + f->xSize, f->y);


    printf("Center(%.2f,%.2f) Size{%.2f,%.2f}\n",
        f->x + (f->xSize / 2), f->y + (f->ySize / 2),
        f->xSize, f->ySize);

}

void drawRectangle(Form f) {
    glColor3f(f->r, f->g, f->b);
    glBegin(GL_POLYGON);
    glVertex2f(f->x, f->y);
    glVertex2f(f->x, f->y + f->ySize);
    glVertex2f(f->x + f->xSize, f->y + f->ySize);
    glVertex2f(f->x + f->xSize, f->y);
    glEnd();


    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
    glBegin(GL_LINE_LOOP);
    glVertex2f(f->x, f->y);
    glVertex2f(f->x, f->y + f->ySize);
    glVertex2f(f->x + f->xSize, f->y + f->ySize);
    glVertex2f(f->x + f->xSize, f->y);
    glEnd();


    glFlush();
}

void drawTriangle(Form f) {
    glColor3f(f->r, f->g, f->b);
    glBegin(GL_TRIANGLES);

    // Vértices do triângulo isósceles
    glVertex2f(f->x, f->y - f->ySize);                     // Vértice inferior (meio, embaixo)
    glVertex2f(f->x - (f->xSize / 2), f->y);               // Vértice superior esquerdo
    glVertex2f(f->x + (f->xSize / 2), f->y);               // Vértice superior direito

    glEnd();

    // Desenha o contorno
    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
    glBegin(GL_LINE_LOOP);
    glVertex2f(f->x, f->y - f->ySize);                     // Vértice inferior
    glVertex2f(f->x - (f->xSize / 2), f->y);               // Vértice superior esquerdo
    glVertex2f(f->x + (f->xSize / 2), f->y);               // Vértice superior direito
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

    glEnd();
    glFlush();

}

void drawEquilateralTriangle(Form f) {
    float halfSide = f->xSize / 2;
    float height = (sqrt(3) / 2) * f->xSize;

    glColor3f(f->r, f->g, f->b);
    glBegin(GL_TRIANGLES);

    // Inverted Y coordinates for proper orientation
    glVertex2f(f->x - halfSide, f->y + height);  // Base esquerda
    glVertex2f(f->x + halfSide, f->y + height);  // Base direita
    glVertex2f(f->x, f->y);                      // Vértice inferior

    glEnd();

    // Desenha o contorno
    glColor3f((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
    glBegin(GL_LINE_LOOP);
    glVertex2f(f->x - halfSide, f->y + height);
    glVertex2f(f->x + halfSide, f->y + height);
    glVertex2f(f->x, f->y);
    glEnd();

    glFlush();
}

void drawForm(Form f) {

    switch (f->type) {
    case RECTANGLE:
        drawRectangle(f);
        break;
    case TRIANGLE_ISO:
        drawTriangle(f);
        break;
    case SQUARE:
        drawRectangle(f);
        break;
    case HEXAGON:
        drawCircle(f, f->xSize / 2, 6);
        break;
    case CIRCLE:
        drawCircle(f, f->xSize / 2, 50);
        break;
    case EQ_TRIANGLE:
        drawEquilateralTriangle(f);
        break;
    }
}
