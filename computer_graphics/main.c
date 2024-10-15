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
    //randomize the start position
    for (i = 0; i < N; i++) {
        if (a[i] == NULL) {
            float x = (float)rand() / RAND_MAX;
            x = sqrt(x);
            float y = (float)rand() / RAND_MAX;
            //y = y;
            float xSize = (float)rand() / RAND_MAX;
            float ySize = (float)rand() / RAND_MAX;
            xSize = xSize / 2;

            a[i] = newForm(x, y, xSize, ySize);
        }
    }
}

void generateFibonacciFigure() {
    Form fibonacci[N];  // Array to store Fibonacci forms
    int i;

    for (i = 0; i < N; i++) {
        // Generate each form using Fibonacci logic here
        // Example placeholder logic (you can customize this):
        fibonacci[i] = newForm(0.0f, 0.0f, 1.0f, 1.0f);  // Example: create a new form

        // You can add more logic to set the size or position based on Fibonacci numbers
    }

    // Further drawing or processing logic goes here
}


// Function to display forms
void display() {
    int i;

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
        }
    }

    glFlush();

    // Increment and display the counter value
    counter++;
    printf("Counter: %d\n", counter);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glColor3f(1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(1024.0, -1024.0, 1024.0, -1024.0, 1024.0, -1024.0);
    //tem apenas left and right
    gluOrtho2D(1024.0, -1024.0, 1024.0, -1024.0/*, 1024.0, -1024.0*/);
}

int main(int argc, char** argv) {
    int i;

    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize(1024, 1024);
    init();
    glutCreateWindow("Window");

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
