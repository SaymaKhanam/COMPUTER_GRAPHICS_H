#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (0, 0, 255);
glPointSize(5.0);
glBegin(GL_QUADS);
glVertex2i(100,140);
glVertex2i(540,140);
glVertex2i(540,340);
glVertex2i(100,340);
glEnd();

glColor3ub (255, 0, 0);
glPointSize(5.0);
glBegin(GL_QUADS);
glVertex2i(100,170);
glVertex2i(540,170);
glVertex2i(540,310);
glVertex2i(100,310);
glEnd();

glColor3ub (255, 255, 255);
glPointSize(5.0);
glBegin(GL_QUADS);
glVertex2i(100,170);
glVertex2i(540,170);
glVertex2i(540,175);
glVertex2i(100,175);
glEnd();


glColor3ub (255, 255, 255);
glPointSize(5.0);
glBegin(GL_QUADS);
glVertex2i(100,305);
glVertex2i(540,305);
glVertex2i(540,310);
glVertex2i(100,310);
glEnd();

glColor3ub (255, 255, 255);
glBegin(GL_POLYGON);
int xk,yk,pk,c1,c2;
    int r=50;
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

  int x=80;
  int y=100;

  glColor3ub (0, 0, 0);
  glPointSize(5.0);

  glBegin(GL_TRIANGLES);
  glVertex2i(150+x,90+y);
  glVertex2i(270+x,190+y);
  glVertex2i(30+x,190+y);
  glEnd();

  glBegin(GL_QUADS);
  glVertex2i(240+x,30+y);
  glVertex2i(150+x,270+y);
  glVertex2i(60+x,30+y);
  glVertex2i(150+x,90+y);
  glEnd();


glFlush ();
}



void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
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
glutCreateWindow ("Flag");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
