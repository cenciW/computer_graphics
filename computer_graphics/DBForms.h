#pragma once
//#ifndef __DBFORM_H__
#include "form.h"


void initDBForms(int num);
void populateDBForms(int maxSize);
void printDBForms();
void drawDBForms();
int insertDBForm(Form f);
void deleteRandomDBForm();


//TODO: Go to forms docs
Form createRandomForm(int maxSize);


