#include <GL/glut.h>
#include <math.h>
#define N 10

// Function prototypes
void generateFibonacciSequence(int fibonacci[]);
void generateGoldenSpiral(void);

// Fibonacci array to store the sequence
int fibonacci[N];

// Function to generate the Fibonacci sequence
void generateFibonacciSequence(int fibonacci[]) {
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i = 2; i < N; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

// Function to draw a quarter-circle (arc)
void drawArc(float x, float y, float radius, float startAngle, float endAngle) {
    glBegin(GL_LINE_STRIP);
    for (float angle = startAngle; angle <= endAngle; angle += 0.01f) {
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

// Function to generate the golden spiral using the Fibonacci sequence
void generateGoldenSpiral(void) {
    float x = 0.0f, y = 0.0f; // Initial position (bottom-left corner)
    float angle = 0.0f;       // Rotation angle (0, 90, 180, 270 degrees)
    int fibonacci[N];

    // Generate the Fibonacci sequence
    generateFibonacciSequence(fibonacci);

    // Draw the squares and arcs
    for (int i = 0; i < N; i++) {
        float size = (float)fibonacci[i]; // Size of the current square

        // Draw the square (optional: to visualize the structure)
        glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + cos(angle) * size, y + sin(angle) * size);
        glVertex2f(x + cos(angle) * size - sin(angle) * size, y + sin(angle) * size + cos(angle) * size);
        glVertex2f(x - sin(angle) * size, y + cos(angle) * size);
        glEnd();

        // Draw the arc (quarter circle)
        drawArc(x, y, size, angle, angle + M_PI_2);  // Draw 90-degree arc

        // Update position for the next square and arc
        switch (i % 4) {
        case 0: // Move right
            x += size;
            break;
        case 1: // Move up
            y += size;
            break;
        case 2: // Move left
            x -= size;
            break;
        case 3: // Move down
            y -= size;
            break;
        }

        // Rotate the angle by 90 degrees for the next square and arc
        angle += M_PI_2;
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Golden Spiral");

    // Set the display callback
    glutDisplayFunc(generateGoldenSpiral);

    // Set the initial color and viewport
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Set the coordinate system

    // Start the main loop
    glutMainLoop();

    return 0;
}
