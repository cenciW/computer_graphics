//#include <GL/glut.h>
//#include <math.h>
//
//#define PI 3.14159265
//#define N 50
//int x_atual = 0;  // urrent x position
//int y_atual = 0;  // Current y position
//
//// Tamanho da janela
//float sc_x = 500;
//float sc_y = 500;
//
//// Proporção Áurea (aproximada)
////#define PHI 1.61803398875
//
//// Função para desenhar um quadrado
//void drawSquare(float x, float y, float side) {
//    glBegin(GL_LINE_LOOP);
//    glVertex2f(x, y);
//    glVertex2f(x, y + side);
//    glVertex2f(x + side, y+side);
//    glVertex2f(x + side, y);
//    glEnd();
//    glFlush();
//}
//
//
//// Função para calcular fibonacci
//float* fibonacci() {
//    float* fib = (float*)malloc(N * sizeof(float));
//    if (fib == NULL) {  // Verificar se a alocação de memória foi bem-sucedida
//        printf("Erro ao alocar memória.\n");
//        exit(1);
//    }
//
//	fib[0] = 0;
//	fib[1] = 1;
//	for (int i = 2; i < N; i++) {
//		fib[i] = fib[i - 1] + fib[i - 2];
//		printf("fib[%d]: %f\n", i, fib[i]);
//	}
//	return fib;
//}
//
//// Função para desenhar o arco
////void drawArc(float x, float y, float r) {
////    glBegin(GL_LINE_LOOP);
////    for (float i = 0; i < PI / 2; i += 0.01) {
////        glVertex2f((cos(i) + x) * r, (sin(i) + y) * r);
////    }
////    glEnd();
////    glFlush();
////}
//
//
//void drawFib() {
//    float* fib = fibonacci();  // Get Fibonacci sequence
//	x_atual = 0;  // Reset x position
//	y_atual = 0;  // Reset y position
//    for (int i = 1; i < N; i++) {
//        // Set color and draw square based on direction
//        //0 % 4 = 0
//		//1 % 4 = 1
//		//2 % 4 = 2
//        switch (i % 4) {
//        case 1:  // Move left
//            glColor3f(1.0, 1.0, 0.0);  // Yellow
//            drawSquare(x_atual, y_atual, fib[i]);
//			//drawArc(x_atual+fib[i-1], y_atual, fib[i]);
//            x_atual = x_atual - fib[i+1];  // Update y
//			y_atual = y_atual - fib[i-1];  // Update x
//            printf("ENTREI no case 0: %f, x_atual = %f [ %f\n", x_atual, fib[i]);
//            break;
//        case 2:  // Move down
//            glColor3f(0.0, 1.0, 0.0);  // Green
//            drawSquare(x_atual, y_atual, fib[i]);
//			//drawArc(x_atual, y_atual, fib[i]);
//            y_atual = y_atual - fib[i+1];  // Update x
//            printf("ENTREI no case 1: %f, y_atual = %f [ %f\n", y_atual, fib[i]);
//            break;
//        case 3:  // Move right
//            glColor3f(0.0, 0.0, 1.0);  // Blue
//            drawSquare(x_atual, y_atual, fib[i]);
//            //drawArc(x_atual, y_atual, fib[i]);
//            x_atual = x_atual + (fib[i]);  // Update y
//
//            printf("ENTREI no case 2: %f, x_atual = %f [ %f\n", x_atual, fib[i]);
//            break;
//        case 0:  // Move up
//            glColor3f(1.0, 0.0, 0.0);  // Red
//            drawSquare(x_atual, y_atual, fib[i]);
//            //drawArc(x_atual, y_atual, fib[i]);
//            y_atual = y_atual + fib[i];  // Update x
//			x_atual = x_atual - fib[i-1];  // Update y
//            printf("ENTREI no case 3: %f, y_atual = %f [ %f\n", y_atual, fib[i + 1]);
//            break;
//        }
//
//        // Debugging output
//        printf("x_atual: %d, y_atual: %d\n", x_atual, y_atual);
//    }
//}
//
//
//void drawMainAxisCenter() {
//	glClearColor(0.0, 0.0, 0.0, 0.5); // Set background color to black
//    //glColor3f(); // Set color to white for the axis
//    glBegin(GL_LINES);
//    glVertex2f(sc_x, sc_y); // Right side of the window
//    glVertex2f(-sc_x, sc_y);  // Left side of the window
//    glVertex2f(sc_x, -sc_y); // Bottom of the window
//    glVertex2f(sc_x, sc_y);  // Top of the window
//    glEnd();
//    glFlush();
//}
//
//// Função de display para o OpenGL
//void display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // Configura as cores
//    glColor3f(1.0, 1.0, 1.0);
//
//    // Desenha a espiral com 10 quadrados
//    //drawGoldenSpiral(20);
//    drawMainAxisCenter();
//	drawFib();
//
//    glFlush();
//}
//
//
//
//// Função para configurar o ambiente OpenGL
//void init() {
//    glClearColor(0.0, 0.0, 0.0, 1.0); // Cor de fundo (preta)
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-sc_x, sc_x, -sc_y, sc_y); // Definindo o sistema de coordenadas
//}
//
//
//
//
//
//// Função principal
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    //glutInitWindowSize(sc_x, sc_y);
//    glutCreateWindow("Espiral de Ouro");
//
//    init();
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}
