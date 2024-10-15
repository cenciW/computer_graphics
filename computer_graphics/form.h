#ifndef __FORM_H__
#define __FORM_H__

#define RECTANGLE 0
#define SQUARE 1
#define TRIANGLE_ISOS 2
//#define TRIANGLE_EQUI 4
#define LINE 3
#define CIRCLE 4

/*
*  This interface provides clients with handles to form objects,
*  but does not give any information about the internal representation.
*  (The struct is specified only by its tag name.)
*/

typedef struct form* Form;

// create a new form by given the original point and the sides
Form newForm(int type, float x, float y, float xSize, float ySize);

// create a new form by given the center point and the sides
Form newFormC(int type, float x, float y, float xSize, float ySize);

// create a new form by given the original point and the sides
Form newRectangle(float x, float y, float xSize, float ySize);

Form newSquare(float x, float y, float side);

Form newTriangleIsos(float x, float y, float xSize, float ySize);

Form newLine(float x, float y, float xSize, float ySize);

Form newCircle(float x, float y, float radius);

void drawForm(Form f);



// delete form
void deleteForm(Form f);

// update a form position - moving by (dx,dy)
void updateForm(Form f, float dx, float dy);

void setBackgroundColor(Form f, float r, float g, float b);

void printfForm(Form f);

#endif

