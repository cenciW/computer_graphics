#ifndef _FORM_H
#define _FORM_H

#define RECTANGLE 0
#define SQUARE 1
#define TRIANGLE_ISO 2
#define HEXAGON 3
#define CIRCLE 4

typedef struct form* Form;

struct form {
    int type;
    float x;
    float y;
    float xSize, ySize;

    float r, g, b;
};

//Form newForm(float x, float y, float xSize, float ySize);
//Form newFormC(float x, float y, float xSize, float ySize);

Form newRectangle(float x, float y, float xSize, float ySize);
Form newSquare(float x, float y, float side);
Form newTriangleIso(float x, float y, float xSize, float ySize);
Form newHexagon(float x, float y, float xSize, float ySize);
Form newCircle(float x, float y, float radius);

void deleteForm(Form f);
void updateForm(Form f, float dx, float dy);
void printfForm(Form f);
void drawForm(Form f);
void setBackgroundColor(Form f, float r, float g, float b);
#endif