#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
#include<math.h>

using namespace std;

int X, Y, radius;

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(1.0);
glColor3ub (0, 0, 0);
glBegin(GL_POLYGON);
    int xk,yk,pk,c1,c2;
    int r=100;
    xk=0;
    yk=r;
    pk=(1-r);
    while(xk<yk){
        glVertex2i(xk+200,yk+240);
        glVertex2i(yk+200,xk+240);
        glVertex2i(yk+200,-1*xk+240);
        glVertex2i(xk+200,-1*yk+240);
        glVertex2i(-1*xk+200,-1*yk+240);
        glVertex2i(-1*yk+200,-1*xk+240);
        glVertex2i(-1*yk+200,xk+240);
        glVertex2i(-1*xk+200,yk+240);
        c1=xk;
        c2=yk;
        xk++;
        if(pk>=0)
            {yk--;}
        pk=pk+(2*(c1+1))+((yk*yk)-(c2*c2))+1;
    }

glEnd();
glFlush ();
}

void myInit (void)
{
glClearColor(1,1,1,1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Circle Drawing");

cout<<"Enter the co-ordinates of the center: "<<endl;
cout<<"Enter X co-ordinate= ";
cin>>X;
cout<<"Enter Y co-ordinate= ";
cin>>Y;
cout<<"Enter the radius= ";
cin>>radius;


glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
