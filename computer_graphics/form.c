#include "form.h"
#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>

// this struct is encapsulated
struct form {
	float x, y;             // initial point of the form
	float xSize, ySize;     // sides 
};

Form newForm(float x, float y, float xSize, float ySize) {
	Form f = (Form)malloc(sizeof(struct form));

	f->x = x;
	f->y = y;
	f->xSize = xSize;
	f->ySize = ySize;

	return f;
}

Form newFormC(float x, float y, float xSize, float ySize) {
	return newForm(x - (xSize / 2), y - (ySize / 2), xSize, ySize);
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
