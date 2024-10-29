#ifndef _FORM_H
#define _FORM_H

#define RECTANGLE 0
#define SQUARE 1
#define TRIANGLE_ISO 2
#define HEXAGON 3
#define CIRCLE 4
#define EQ_TRIANGLE 5

typedef struct form* Form;

struct form {
    int type;
    float x;
    float y;
    float xSize, ySize; // xSize ser� usado como lado no tri�ngulo equil�tero

    float r, g, b;
};

// Fun��es para criar novas formas geom�tricas
Form newRectangle(float x, float y, float xSize, float ySize);
Form newSquare(float x, float y, float side);
Form newTriangleIso(float x, float y, float xSize, float ySize);
Form newHexagon(float x, float y, float xSize, float ySize);
Form newCircle(float x, float y, float radius);
Form newTriangleEq(float x, float y, float side); // Tamanho do lado do tri�ngulo equil�tero

// Fun��es para manipula��o de formas
void deleteForm(Form f);
void updateForm(Form f, float dx, float dy);
void printfForm(Form f);
void drawForm(Form f);
void setBackgroundColor(Form f, float r, float g, float b);

#endif
