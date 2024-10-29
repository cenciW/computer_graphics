#include "form.h"
#include "DBForms.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


int counter;
int windowX = 500;
int windowY = 500;



// delete a random figure
//void delete(int button, int state, int x, int y) {
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//        printf("-> LEFT button pressed!\n");
//        deleteForm(figs[(int)rand() / N)]);
//    }
//    
//}


//void generateRandomFiguresXY(Form* figs, float percentual, float x, float y) {
//
//    for (int i = 0; i < N; i++) {
//        if (figs[i] != NULL) {
//            deleteForm(figs[i]);
//            figs[i] = NULL;
//        }
//    }
//
//    for (int i = 0; i < N; i++) {
//
//        int figureType = (rand() % 5);
//
//        switch (figureType) {
//        case 0:
//            figs[i] = newRectangle(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        case 1:
//            figs[i] = newTriangleIso(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        case 2:
//            figs[i] = newSquare(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        case 3:
//            //Hexagon
//            figs[i] = newHexagon(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        case 4:
//            figs[i] = newCircle(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        default:
//            figs[i] = newRectangle(
//                x,
//                y,
//                ((float)rand() / RAND_MAX) * 50 - 1,
//                ((float)rand() / RAND_MAX) * 50 - 1);
//            break;
//        }
//        setBackgroundColor(figs[i], (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
//    }
//
//}

void mouseClick(int button, int state, int x, int y) {
    printf("Clik in a mouse button... Window (X,Y) = (%i,%i)\n", x, y);
    
    	y = windowY - y;
    
    	printf("World (X, Y) = (% i, % i)\n", x, y);
    
    	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    		printf("-> LEFT button pressed!\n");
            Form f = createRandomForm(windowX);

            setBackgroundColor(f, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);

            if (!insertDBForm(createRandomForm(windowX))) {
                printf("Memory full.");
                deleteForm(f);
            }
    	}

        if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
            printf("-> RIGHT button pressed!\n");
            deleteRandomDBForm();
        }

}


void displayForms() {
    srand(time(NULL));
    glClear(GL_COLOR_BUFFER_BIT);


    //generateRandomFigures(figs, 90);

    counter++;

    printf("Counter: %d\n", counter);

    drawDBForms();
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
    glutCreateWindow("Window to Random Forms");
    init(windowX, windowY);
    glutDisplayFunc(displayForms);
    glutReshapeFunc(reShape);
    glutMouseFunc(mouseClick);
    glutMainLoop();
}

int main(int argc, char** argv) {
    

    srand(time(NULL));

    initDBForms(10);

    /*generateRandomFigures(figs, 70);*/
    counter = 0;

    //populateDBForms(windowX);
    printDBForms();


    

    glutInit(&argc, argv);
    setupOpenGL();

    return 0;
}