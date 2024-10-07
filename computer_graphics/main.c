#include <stdlib.h>
#include <stdio.h>
#include <gl/glut.h>
#include "form.h"
#define N 10

// Array of pointers to form objects
Form a[N];
Form f;

struct form {
    float x, y;             // initial point of the form
    float xSize, ySize;     // sides 
};

// Counter variable
int counter = 0;

// Function to generate random forms
void generateRandomForms() {
    int i;

    for (i = 0; i < N; i++) {
        if (a[i] == NULL) {
            float x = (float)rand() / RAND_MAX;
            float y = (float)rand() / RAND_MAX;
            float xSize = (float)rand() / RAND_MAX;
            float ySize = (float)rand() / RAND_MAX;

            a[i] = newForm(x, y, xSize, ySize);
        }
    }
}

// Function to display forms
void display() {
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    for (i = 0; i < N; i++) {
        if (a[i] != NULL) {
            // Generate random RGB values for the color
            float r = (float)rand() / RAND_MAX;
            float g = (float)rand() / RAND_MAX;
            float b = (float)rand() / RAND_MAX;

            // Set the color for the outline
            glColor3f(r, g, b);

            // Draw the outline of the form as a line loop
            glBegin(GL_LINE_LOOP);
            glVertex2f(a[i]->x, a[i]->y);
            glVertex2f(a[i]->x, a[i]->y + a[i]->ySize);
            glVertex2f(a[i]->x + a[i]->xSize, a[i]->y + a[i]->ySize);
            glVertex2f(a[i]->x + a[i]->xSize, a[i]->y);
            glEnd();

            // Set the color for the fill
            glColor3f(r, g, b);

            // Draw the form as a polygon
            glBegin(GL_POLYGON);
            glVertex2f(a[i]->x, a[i]->y);
            glVertex2f(a[i]->x, a[i]->y + a[i]->ySize);
            glVertex2f(a[i]->x + a[i]->xSize, a[i]->y + a[i]->ySize);
            glVertex2f(a[i]->x + a[i]->xSize, a[i]->y);
            glEnd();

            // Draw: IFSP - 2024
            //I
            //glColor3f(0.0, 1.0, 0.0); // Set the color to green
            glLineWidth(2.0); // Set the line width to 2
            glBegin(GL_POLYGON);
            glVertex2f(0.1, 0.6);
            glVertex2f(0.1, 0.1);
            glVertex2f(0.2, 0.1);
            glVertex2f(0.2, 0.6);
            glEnd();

            //F
            f = newForm(.51, .51, .5, .5);
            //glColor3f(0.0, 1.0, 0.0); // Set the color to green
            glLineWidth(2.0); // Set the line width to 2
            glBegin(GL_POLYGON);
            glVertex2f(0.3, 0.1);
            glVertex2f(0.3, 0.6);
            glVertex2f(0.5, 0.6);
            glVertex2f(0.5, 0.5);
            glVertex2f(0.4, 0.5);
            glVertex2f(0.4, 0.4);
            glVertex2f(0.5, 0.4);
            glVertex2f(0.5, 0.3);
            glVertex2f(0.4, 0.3);
            glVertex2f(0.4, 0.1);
            //glVertex2f(0.3, 0.1);
            glEnd();


            /*
            //glVertex2f(0.1, 0.15);
            //glVertex2f(0.2, 0.1);
            //glVertex2f(0.2, 0.2);
            //glVertex2f(0.3, 0.2);
            //glVertex2f(0.3, 0.1);
            //glVertex2f(0.2, 0.1);
            //glVertex2f(0.2, 0.0);
            //glVertex2f(0.1, 0.0);
            //glVertex2f(0.1, 0.1);*/



        }
    }

    glFlush();

    // Increment and display the counter value
    counter++;
    printf("Counter: %d\n", counter);
}

int main(int argc, char** argv) {
    int i;

    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 1024);
    glutCreateWindow("Tela");

    //// Simple example: create one form, print it and delete it at the end
    //Form* f = newForm(0, 0, 5, 5);  // Note: Form* to indicate a pointer
    //printfForm(f);
    //deleteForm(f);

    // Initialize array of pointers to forms to NULL
    for (i = 0; i < N; i++)
        a[i] = NULL;

    // Generate random forms
    generateRandomForms();

    // Print the content of the array
    for (i = 0; i < N; i++) {
        if (a[i] != NULL) {
            printfForm(a[i]);
        }
    }

   
    // Draw the forms before starting the graphics
    display();

    // Register display callback function
    glutDisplayFunc(display);


    // Update a form and display the new positions
    printf("Updating form: ");
    printfForm(a[2]);
    updateForm(a[2], 1.0, 1.0);
    printfForm(a[2]);
    updateForm(a[2], 1.0, 1.0);
    printfForm(a[2]);
    updateForm(a[2], 0.0, -4.0);
    printfForm(a[2]);

    // Start the GLUT main loop
    glutMainLoop();

    // Delete forms when done
    for (i = 0; i < N; i++) {
        if (a[i] != NULL) {
            deleteForm(a[i]);
            a[i] = NULL;
        }
    }


    return 0;
}
