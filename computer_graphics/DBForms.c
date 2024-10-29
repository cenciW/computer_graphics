#include "form.h"
#include "DBForms.h"
#include "stdlib.h"

#define N 10

Form* figs;
int n;


void initDBForms(int num) {
    
    int i;
    n = num;
    
    //Allocating memory
    figs = malloc(sizeof(Form) * n);
    
    //Init array of forms
    for (i = 0; i < n; i++) {
        figs[i] = NULL;
    }
}

void printDBForms() {
    //srand(time(NULL));

    for (int i = 0; i < n; i++) {
        if (figs[i] != NULL) {
            printfForm(figs[i]);
        }
    }
}


void populateDBForms(int maxSize) {

    int i;

    for (i = 0; i < N; i++) {
        if (figs[i] != NULL) {
            figs[i] = createRandomForm(maxSize);
        }
    }
}

//insert some form inside database
int insertDBForm(Form f) {
   
    int i = 0;

    for (i = 0; i < n; i++) {
        if (figs[i] == NULL) {
            figs[i] = f;
        }
    }

    return 0;
    //return 1 - tudo ok / 0 - nada ok
}

void deleteRandomDBForm() {
    int i = rand() % n;

    if (figs[i] != NULL) {
        deleteForm(figs[i]);
        figs[i] = NULL;
    }
}

void drawDBForms() {
    for (int i = 0; i < n; i++) {
        if (figs[i] != NULL) {
            drawForm(figs[i]);
        }
    }
}

Form createRandomForm(int maxSize) {
    Form f;

    for (int i = 0; i < N; i++) {
        if (figs[i] != NULL) {
            deleteForm(figs[i]);
            figs[i] = NULL;
        }
    }

    for (int i = 0; i < N; i++) {

        int figureType = (rand() % 6);

        switch (figureType) {
        case 0:
            f = newRectangle(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 1:
            f = newTriangleIso(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 2:
            f = newSquare(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 3:
            //Hexagon
            f = newHexagon(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 4:
            f = newCircle(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        case 5:
            f = newTriangleEq(((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        default:
           f = newRectangle(
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * maxSize - 1,
                ((float)rand() / RAND_MAX) * 50 - 1,
                ((float)rand() / RAND_MAX) * 50 - 1);
            break;
        }
        setBackgroundColor(f, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
        return f;


    }

}