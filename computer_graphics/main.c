#include "form.h"
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>

#define N 10


Form figs[N];
int counter;
int windowX = 500;
int windowY = 500;

void generateRandomFigures(Form* figs, float percentual) {

    for (int i = 0; i < N; i++) {
        if (figs[i] != NULL) {
            deleteForm(figs[i]);
            figs[i] = NULL;
        }
    }

    for (int i = 0; i < N; i++) {

        int figureType = (rand() % 5);

        switch (figureType) {
        case 0:
            figs[i] = newRectangle(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 1:
            figs[i] = newTriangleIso(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 2:
            figs[i] = newSquare(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 3:
            //Hexagon
            figs[i] = newHexagon(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 4:
            figs[i] = newCircle(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        default:
            figs[i] = newRectangle(
                ((float)rand() / RAND_MAX) * windowX - 1,
                ((float)rand() / RAND_MAX) * windowY - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        }
        setBackgroundColor(figs[i], (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);


    }

}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		printf("Clicou na posicao (%d, %d)\n", x, y);
        generateRandomFigures(figs, 100);
		glutPostRedisplay();
    }
}


void displayForms() {
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);


    generateRandomFigures(figs, 90);

    counter++;

    printf("Contador: %d\n", counter);

    for (int i = 0; i < N; i++) {
        if (figs[i] != NULL) {
            drawForm(figs[i]);
        }
    }
}

void init(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.0, 1.0);
}

void reShape(int width, int height) {
    glViewport(0, 0, width, height);
    init(width, height);
}

void setupOpenGL() {
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(windowX, windowY);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Janela para figs");
    init(windowX, windowY);
    glutDisplayFunc(displayForms);
    glutReshapeFunc(reShape);
    glutMouseFunc(mouseClick);
    glutMainLoop();
}

int main(int argc, char** argv) {
    for (int i = 0; i < N; i++) {
        figs[i] = NULL;
    }

    srand(time(NULL));
    generateRandomFigures(figs, 70);
    counter = 0;


    for (int i = 0; i < N; i++) {
        if (figs[i] != NULL) {
            printf("Figura %d: ", i);
            printfForm(figs[i]);
            printf("\n");
        }
    }

    glutInit(&argc, argv);
    setupOpenGL();

    return 0;
}