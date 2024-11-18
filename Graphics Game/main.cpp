/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include<GL/glut.h>
#include <cstdlib>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
int phyWidth= 700;
int phyHeight= 700;
int logWidth=100;
int logHeight=100;
int centerX = logWidth/2, centerY = logHeight/2;
int sqWid=20;
bool down=true;
float breakPoint1=100.0;
float breakPoint2=100.0;
float breakPoint3=100.0;
int maxY=22;
int mouseX=centerX, mouseY=centerY;

class Asteroids {
public:
    float x, y, radius; // Position and radius of the asteroid
    float red, green, blue; // Color of the asteroid
public:
    Asteroids(){}
    Asteroids(float x, float y, float radius,int color ) {
        this->x = x;
        this->y = y;
        this->radius = radius;
        this->red = (color == 0) ? 1.0f : 0.0f;
        this->green = (color == 1) ? 1.0f : 0.0f;
        this->blue = (color == 2) ? 1.0f : 0.0f;
        //this->breakPoint = breakPoint;
    }


    void draw() {
        // Draw the asteroid body
        glColor3f(red, green, blue);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159 / 180;
            glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
        }
        glEnd();


    }

};



void Timer(int value) {
if(value==0){
    glutTimerFunc(100, Timer, value);
    glutPostRedisplay();
}
else if(value==1){
     glutTimerFunc(50, Timer, value);
    glutPostRedisplay();
}


}

void drawRandomDots() {
    for(int i=0;i<100;i++){
    int x= rand() % 100;
    int y = rand() % 100;
        glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
        glVertex2f(x, y); // Set the point coordinates
        glEnd(); // End drawing points
}
}



void printSome(char *str,int x,int y) {
glColor3f (0, 1.0, 0.0);
glRasterPos2d(x,y);
for (int i=0;i<strlen(str);i++)

glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str[i]);

glFlush();
}

void passiveMouse (int x,int y){
mouseX = x;
mouseX=0.5+1.0*mouseX*logWidth/phyWidth;
mouseY = phyHeight - y;
mouseY=0.5+1.0*mouseY*logHeight/phyHeight;
   // mouseX = mouseX - centerX;
    //mouseY = mouseY - centerY;

glutPostRedisplay();

}

void drawRocket(int rocketX, int rocketY) {

    // int rocketWidth = 10;
    //int rocketHeight = 20;
    //int rocketCenterX = rocketX;
   // int rocketCenterY = rocketY - rocketHeight / 2;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(rocketX - 5, rocketY + 10);
    glVertex2i(rocketX + 5, rocketY + 10);
    glVertex2i(rocketX + 5, rocketY + 80);
    glVertex2i(rocketX - 5, rocketY + 80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.65, 0.0);
    glVertex2i(rocketX - 5, rocketY - 10);
    glVertex2i(rocketX + 5, rocketY - 10);
    glVertex2i(rocketX + 5, rocketY + 10);
    glVertex2i(rocketX - 5, rocketY + 10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(rocketX - 5, rocketY + 10);
    glVertex2i(rocketX + 5, rocketY + 10);
    glVertex2i(rocketX, rocketY + 15);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(rocketX + 5, rocketY );
    glVertex2i(rocketX + 5, rocketY - 5);
    glVertex2i(rocketX + 10, rocketY - 5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2i(rocketX - 5, rocketY );
    glVertex2i(rocketX - 5, rocketY - 5);
    glVertex2i(rocketX - 10, rocketY - 5);
    glEnd();
}
/*
void drawRocket(int rocketX,int rocketY){
    glBegin(GL_POLYGON);
        glRasterPos2d(rocketX,rocketY);
        glColor3f(0.0,1.0,0.0);
        glVertex2i(50,30);
        glVertex2i(60,30);
        glVertex2i(60,100);
        glVertex2i(50,100);
    glEnd();

    glBegin(GL_POLYGON);
        glRasterPos2d(rocketX,rocketY);
        glColor3f(1.0,0.65,0.0);
        glVertex2i(50,10);
        glVertex2i(60,10);
        glVertex2i(60,30);
        glVertex2i(50,30);
    glEnd();

    glBegin(GL_TRIANGLES);
        glRasterPos2d(rocketX,rocketY);
        glColor3f(1.0,1.0,1.0);
        glVertex2i(50,30);
        glVertex2i(60,30);
        glVertex2i(55,35);
    glEnd();
    glBegin(GL_TRIANGLES);
        glRasterPos2d(rocketX,rocketY);
        glColor3f(1.0,1.0,1.0);
        glVertex2i(60,12);
        glVertex2i(60,20);
        glVertex2i(65,12);
    glEnd();
    glBegin(GL_TRIANGLES);
        glRasterPos2d(rocketX,rocketY);
        glColor3f(1.0,1.0,1.0);
        glVertex2i(50,12);
        glVertex2i(50,20);
        glVertex2i(45,12);
    glEnd();

}*/





void init()
{

glClearColor( 0.0, 0.0, 0.0, 1.0); // COLOR BACKGROUND

glMatrixMode( GL_PROJECTION);
gluOrtho2D( 0.0, logWidth, 0.0, logHeight);

}
int astercolor[3] = {0,1,0};
float xrand[25];
int x1,x2,x3;
int c1,c2,c3;
void myDisplay()
{
    Asteroids asteroid[3];
    glClear( GL_COLOR_BUFFER_BIT);
    drawRocket(mouseX,mouseY);
    drawRandomDots();
   if(breakPoint1==100.0){
        x1=rand()%100;
        c1=rand() % 3;
        c2=rand() % 3;
        c3=rand() % 3;
    }
    if(breakPoint2==100.0){
        x2=rand()%100;
    }
    if(breakPoint3==100.0){
        x3=rand()%100;
    }


        asteroid[0]=Asteroids(x1,breakPoint1,3,c1);
        asteroid[0].draw();
        breakPoint1-=1;

        if(breakPoint1<=30){
        asteroid[1]=Asteroids(x2,breakPoint2,3,c2);
        asteroid[1].draw();
        breakPoint2-=1;
        }
        if(breakPoint2<=30){
        asteroid[2]=Asteroids(x3,breakPoint3,3,c3);
        asteroid[2].draw();
        breakPoint3-=1;
        }





glutSwapBuffers();

}

/* Program entry point */

int main(int argc, char *argv[])
{

    glutInit( &argc, argv);
glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);

glutInitWindowPosition( 100, 100);
glutInitWindowSize( phyWidth, phyHeight);
glutCreateWindow( "Space Rocket");
init();
glutPassiveMotionFunc(passiveMouse);

glutDisplayFunc( myDisplay);
Timer(0);
glutMainLoop();
}
