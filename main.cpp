#include <GLFW/glfw3.h>
#include<windows.h>
#include <glut.h>
#include <corecrt_math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#defines <GLFW_INCLUDE_GLU>

 int  day = 0;

float theta;
//Game Speed
int FPS = 50;
//Game Track
int start = 0;
int gv = 0;
int level = 0;

//Track Score
int score = 0;

//Form move track
int  DivTopMost = 0;
int  DivTop = 0;
int  DivMdl = 0;
int  DivBtm = 0;

//For Card Left / RIGHT
int lrIndex = 0;

//Meteors Coming
int Meteor1 = 0;
int lrIndex1 = 0;
int Meteor2 = +35;
int lrIndex2 = 0;
int Meteor3 = +70;
int lrIndex3 = 0;

//For Display TEXT
const int font1 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2 = (int)GLUT_BITMAP_HELVETICA_18;
const int font3 = (int)GLUT_BITMAP_8_BY_13;

char s[30];
void renderBitmapString(float x, float y, void* font, const char* string) {
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
void Spaceship() {
     
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.3, 0.5);
    glVertex2f(lrIndex + 27, 6);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 23, 5);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 23, 8);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 28, 10);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.3, 0.5);
    glVertex2f(lrIndex + 28, 10);
    glVertex2f(lrIndex + 33, 8);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 33, 5);
    glColor3f(0.000, 0.545, 0.545);
    glVertex2f(lrIndex + 29, 6);
    glVertex2f(lrIndex + 27, 6);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(lrIndex + 26, 8);
    glVertex2f(lrIndex + 30, 8);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(lrIndex + 26, 8.5);
    glVertex2f(lrIndex + 30, 8.5);
    glEnd();


    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(lrIndex + 27, 5);

    glEnd();


 }

void Meteors(){

    glColor3f(1.0f, 0.0f, 0.0f);  // set the drawing color to red
    glBegin(GL_TRIANGLES);// start drawing in 'line' mode
    glVertex2f(lrIndex1 + 7, Meteor1 + 5 + 100);
    glVertex2f(lrIndex1 + 8, Meteor1 + 10 + 100);
    glVertex2f(lrIndex1 + 9, Meteor1 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex1 + 9, Meteor1 + 6 + 100);
    glVertex2f(lrIndex1 + 10, Meteor1 + 15 + 100);
    glVertex2f(lrIndex1 + 11, Meteor1 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex1 + 11, Meteor1 + 6 + 100);
    glVertex2f(lrIndex1 + 12, Meteor1 + 13 + 100);
    glVertex2f(lrIndex1 + 13, Meteor1 + 5 + 100);

    glEnd();
    glColor3f(1.0f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);// start drawing in 'line' mode
    for (int i = 0; i < 360; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(lrIndex1 + 10 + 3 * cos(theta), Meteor1 + 5 + 3 * sin(theta) + 100);
    }
    glEnd();
    Meteor1--;
    if (Meteor1 < -100) {
        Meteor1 = 0;
        lrIndex1 = lrIndex;
    }
    //KIll check car1
    if ((abs(lrIndex - lrIndex1) < 8) && (Meteor1 + 100 < 10)) {
        start = 0;
        gv = 1;

    }

    glColor3f(1.0f, 0.0f, 0.0f); // set the drawing color to red
    glBegin(GL_TRIANGLES);// start drawing in 'line' mode
    glVertex2f(lrIndex2 + 7, Meteor2 + 5 + 100);
    glVertex2f(lrIndex2 + 8, Meteor2 + 10 + 100);
    glVertex2f(lrIndex2 + 9, Meteor2 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex2 + 9, Meteor2 + 6 + 100);
    glVertex2f(lrIndex2 + 10, Meteor2 + 15 + 100);
    glVertex2f(lrIndex2 + 11, Meteor2 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex2 + 11, Meteor2 + 6 + 100);
    glVertex2f(lrIndex2 + 12, Meteor2 + 13 + 100);
    glVertex2f(lrIndex2 + 13, Meteor2 + 5 + 100);

    glEnd();
    glColor3f(1.0f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);// start drawing in 'line' mode
    for (int i = 0; i < 360; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(lrIndex2 + 10 + 3 * cos(theta), Meteor2 + 5 + 3 * sin(theta) + 100);
    }
    glEnd();
    Meteor2--;
    if (Meteor2 < -100) {
        Meteor2 = 0;
        lrIndex2 = lrIndex;
    }
    //KIll check car2
    if ((abs(lrIndex - lrIndex2) < 8) && (Meteor2 + 100 < 10)) {
        start = 0;
        gv = 1;
    }
     

    glColor3f(1.0f, 0.0f, 0.0f);      // set the drawing color to red
    glBegin(GL_TRIANGLES);// start drawing in 'line' mode
    glVertex2f(lrIndex3 + 7, Meteor3 + 5 + 100);
    glVertex2f(lrIndex3 + 8, Meteor3 + 10 + 100);
    glVertex2f(lrIndex3 + 9, Meteor3 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex3 + 9, Meteor3 + 6 + 100);
    glVertex2f(lrIndex3 + 10, Meteor3 + 15 + 100);
    glVertex2f(lrIndex3 + 11, Meteor3 + 6 + 100);

    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(lrIndex3 + 11, Meteor3 + 6 + 100);
    glVertex2f(lrIndex3 + 12, Meteor3 + 13 + 100);
    glVertex2f(lrIndex3 + 13, Meteor3 + 5 + 100);

    glEnd();
    glColor3f(1.0f, 0.9f, 0.9f);
    glBegin(GL_POLYGON);// start drawing in 'line' mode
    for (int i = 0; i < 360; i++) {
        theta = i * 3.142 / 180;
        glVertex2f(lrIndex3 + 10 + 3 * cos(theta), Meteor3 + 5 + 3 * sin(theta) + 100);
    }
    glEnd();
    Meteor3--;
    if (Meteor3 < -100) {
        Meteor3 = 0;
        lrIndex3 = lrIndex;
    }
    //KIll check car3
    if ((abs(lrIndex - lrIndex3) < 8) && (Meteor3 + 100 < 10)) {
        start = 0;
        gv = 1;

    }
}
void startGame() { 

    //TOP
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, DivTop + 80);
    glVertex2f(48, DivTop + 100);
    glVertex2f(52, DivTop + 100);
    glVertex2f(52, DivTop + 80);
    glEnd();
    DivTop--;
    if (DivTop < -100) {
        DivTop = 20;
        score++;
    }
    //Midle
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, DivMdl + 40);
    glVertex2f(48, DivMdl + 60);
    glVertex2f(52, DivMdl + 60);
    glVertex2f(52, DivMdl + 40);
    glEnd();



    DivMdl--;
    if (DivMdl < -60) {
        DivMdl = 60;
        score++;
    }
    //Bottom
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48, DivBtm + 0);
    glVertex2f(48, DivBtm + 20);
    glVertex2f(52, DivBtm + 20);
    glVertex2f(52, DivBtm + 0);
    glEnd();
    DivBtm--;
    if (DivBtm < -20) {
        DivBtm = 100;
        score++;
    }
    //Score Board
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80, 97);
    glVertex2f(100, 97);
    glVertex2f(100, 98 - 8);
    glVertex2f(80, 98 - 8);
    glEnd();

    //Print Score
    char buffer[50];
    sprintf_s(buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95, (void*)font3, buffer);
   
    char level_buffer[50];
    sprintf_s(level_buffer, "LEVEL: %d", level);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5, 95 - 4, (void*)font3, level_buffer);

    //Spaceship shape
    Spaceship(); 

    //Meteors shape
    Meteors();
 

}

void Sun() {
     
    //light
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1); 

    GLfloat light_ambient[] = { 5.0f, 2.0f,1.0f, 1.0f };
    GLfloat light_diffuse[] = { 2.0f, 0.5f, 0.1f, 0.1f };
    GLfloat light_position[] = { 0.0f, 100.0f,  -100.0f, 0.0f };
    GLfloat material_specular[] = { 0.4f, 0.2f, 0.3f };
    GLfloat material_shininess = 10.0f;
     
    glMaterialfv(GL_FRONT, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
    
    
    //sun 3D 
    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(6, 20, 2); 
    glPopMatrix();

    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(5, 20, 2); 
    glPopMatrix();

    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(4, 20, 2); 
    glPopMatrix();

    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(3, 20, 2); 
    glPopMatrix();

    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(2, 20, 2); 
    glPopMatrix();

    glPushMatrix(); 
    glColor3ub(241, 191, 66);
    glTranslated(15, 60, 0);
    glutSolidSphere(1, 20, 2); 
    glPopMatrix();

        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glFlush();

}
void fristDesign() {
    

    // Stars in The first page
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(0, 100);
    glVertex2f(100, 100);
    glColor3f(0.000, 0.000, 0.000);
    glVertex2f(100, 50 - 50);
    glVertex2f(0, 50 - 50);
    glEnd();

  //sun 3D
    Sun();

    // Stars in The first page
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(10, 10);
    glVertex2f(15, 20);
    glVertex2f(20, 10);
    glVertex2f(10, 15);
    glVertex2f(20, 15);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(10, 80);
    glVertex2f(15, 90);
    glVertex2f(20, 80);
    glVertex2f(10, 85);
    glVertex2f(20, 85);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(40, 30);
    glVertex2f(45, 40);
    glVertex2f(50, 30);
    glVertex2f(40, 35);
    glVertex2f(50, 35);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(80, 90);
    glVertex2f(85, 100);
    glVertex2f(90, 90);
    glVertex2f(80, 95);
    glVertex2f(90, 95);
    glEnd();


    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(70, 20);
    glVertex2f(75, 30);
    glVertex2f(80, 20);
    glVertex2f(70, 25);
    glVertex2f(80, 25);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(15, 40);
    glVertex2f(20, 50);
    glVertex2f(25, 40);
    glVertex2f(15, 45);
    glVertex2f(25, 45);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(75, 70);
    glVertex2f(80, 80);
    glVertex2f(85, 70);
    glVertex2f(75, 75);
    glVertex2f(85, 75);
    glEnd();


    glPointSize(2);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(10, 90);
    glVertex2i(25, 60);
    glVertex2i(15, 30);
    glVertex2i(30, 10);
    glVertex2i(50, 60);
    glVertex2i(60, 90);
    glVertex2i(95, 50);
    glVertex2i(90, 80);
    glVertex2i(60, 15);
    glVertex2i(85, 35);
    glEnd();

  
    //Menu Place Holder
    glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();

    glColor3f(00, 0, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 4 + 10);
    glVertex2f(32 - 4, 50 + 4 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 + 45, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 + 45, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();



    //Text Information in Frist Page
    if (gv == 1) {
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(35, 60 + 10, (void*)font1, "GAME OVER");
        glColor3f(1.000, 0.000, 0.000);
        char buffer2[50];
        sprintf_s(buffer2, "Your Score is : %d", score);
        renderBitmapString(33, 60 - 4 + 10, (void*)font1, buffer2);

    }

    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(30, 80, (void*)font1, "• Falling Meteors     •");

    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(30, 50 + 10, (void*)font2, "Press SPACE to START");
    renderBitmapString(30, 50 - 3 + 10, (void*)font2, "Press ESC to Exit");
    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(30, 50 - 6 + 10, (void*)font3, "Press RIGHT to turn Right");
    renderBitmapString(30, 50 - 8 + 10, (void*)font3, "Press LEFT to turn Left");


    glColor3f(0.000, 1.000, 1.000);
    renderBitmapString(30 - 5, 50 - 40, (void*)font3, "Project By:");
    renderBitmapString(30 - 5, 50 - 43, (void*)font3, "Rina Alfarsi, Rahaf Alshehri, Zihar Abdullah");


}

void stars_background() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POINTS);
    glVertex2i(10, 17);
    glVertex2i(15, 50);
    glVertex2i(35, 80);
    glVertex2i(45, 40);
    glVertex2i(60, 20);
    glVertex2i(65, 50);
    glVertex2i(50, 60);
    glVertex2i(50, 80);
    glVertex2i(60, 90);
    glVertex2i(75, 80);
    glVertex2i(60, 45);
    glVertex2i(80, 45);
    glVertex2i(85, 30);
    glVertex2i(90, 20);
    glVertex2i(90, 100);
    glVertex2i(95, 50);
    glVertex2i(70, 65);
    glVertex2i(77, 70);
    glVertex2i(70, 55);
    glVertex2i(50, 15);
    glVertex2i(50, 5);
    glVertex2i(45, 30);
    glVertex2i(90, 5);
    glVertex2i(70, 5);
    glVertex2i(80, 5);
    glVertex2i(10, 40);
    glVertex2i(10, 75);
    glVertex2i(39, 60);
    glVertex2i(10, 75);
    glVertex2i(5, 10);
    glVertex2i(8, 55);
    glVertex2i(5, 33);
    glVertex2i(5, 12);
    glVertex2i(30, 40);
    glVertex2i(35, 55);
    glVertex2i(27, 60);
    glVertex2i(29, 75);
    glVertex2i(27, 57);
    glVertex2i(28, 11);
    glVertex2i(22, 26);
    glVertex2i(13, 30);
    glVertex2i(15, 95);
    glVertex2i(15, 100);
    glVertex2i(20, 100);
    glVertex2i(35, 75);
    glVertex2i(10, 90);
    glVertex2i(25, 60);
    glVertex2i(48, 40);
    glVertex2i(30, 10);
    glVertex2i(50, 60);
    glVertex2i(60, 90);
    glVertex2i(95, 50);
    glVertex2i(90, 80);
    glVertex2i(60, 15);
    glVertex2i(85, 35);
    glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

    if (start == 1) {
 

        glClearColor(0.000, 0.000, 0.000, 0);
        stars_background(); 
        startGame();
    } 
    else {
        fristDesign(); 
    } 
     
    glFlush();
    glutSwapBuffers();
}

 
void spe_key(int key, int x, int y) {
    switch (key) {
    

    case GLUT_KEY_LEFT:
        if (lrIndex >= 0) {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 0) {
                lrIndex = -1;
            }
        }
        break;


    case GLUT_KEY_RIGHT:
        if (lrIndex <= 44) {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 44) {
                lrIndex = 45;
            }
        }
        break;

    default:
        break;
    }

}

void processKeys(unsigned char key, int x, int y) {

    switch (key)
    {
    case ' ':
        if (start == 0) {
            start = 1;
            gv = 0;
            FPS = 50;
            DivTopMost = 0;
            DivTop = 0;
            DivMdl = 0;
            DivBtm = 0;
            lrIndex = 0;
            Meteor1 = 0;
            lrIndex1 = 0;
            Meteor2 = +35;
            lrIndex2 = 0;
            Meteor3 = +70;
            lrIndex3 = 0;
            score = 0;
            level = 0;
        }
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(1300 / FPS, timer, 0);
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 650);
    glutInitWindowPosition(200, 20);
    glutCreateWindow(" Falling Meteors ");

    glutDisplayFunc(display);
    
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);

    glOrtho(0, 100, 0, 100, -1, 1);
    glClearColor(0.184, 0.310, 0.310, 1);

    glutTimerFunc(1000, timer, 0);
    glutMainLoop();

    return 0;
}