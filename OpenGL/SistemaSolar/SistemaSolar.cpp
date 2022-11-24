/*
 * Presionar Z para ver los focos de las trayectorias circulares
 * en orden de mas cercano a mas lejano al sol.
 *
 *  Falta extraer funciones y renombrar variables
 */
#include <GL/glut.h>

#include <stdlib.h>
#include <math.h>

int nFoco=0;
const double PI = 3.14159265359;

/* GLUT callback Handlers */

void iniciar(){
    glClearColor(0,0,0,0);
    glOrtho(190,-190,100,-100,100,-100);
}

void ShowFoco(double Foco){
    glColor3d(0,1,0);
    glPushMatrix();
        glTranslated(Foco, 0, 0);
        glBegin(GL_POINTS);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(2*cos(i), 2*sin(i));
            }
        glEnd();
    glPopMatrix();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    glClear(GL_COLOR_BUFFER_BIT);
    double theta;
    int radioFoco = 25;

    //dibujar sol
    double radioSol = 10;
    glColor3d(1,1,0);
    glPushMatrix();
        glBegin(GL_POLYGON);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(radioSol*cos(i), radioSol*sin(i));
            }
        glEnd();
    glPopMatrix();



    //def variables para Mercurio
    double radioMercurio = 1;
    int radioTraslacionMercurio = 15;
    theta = t*1.8;  //Tiempo de traslacion
    double FocoMercurio=radioFoco*0.6*cos(theta);
    double xMercurio=radioTraslacionMercurio*cos(theta)+FocoMercurio;
    double yMercurio=radioTraslacionMercurio*sin(theta);

    //dibujar Mercurio
    glColor3d(0.79,0.79,0.79);
    glPushMatrix();
        glTranslated(xMercurio,yMercurio,0);
        glBegin(GL_POLYGON);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(radioMercurio*cos(i), radioMercurio*sin(i));
            }
        glEnd();
    glPopMatrix();



    //def variables para Venus
    double radioVenus = 4;
    int radioTraslacionVenus = 30;
    theta = t*1.2;  //Tiempo de traslacion
    double FocoVenus=radioFoco*cos(theta);
    double xVenus=radioTraslacionVenus*cos(theta)+FocoVenus;
    double yVenus=radioTraslacionVenus*sin(theta);

    //dibujar Venus
    glColor3d(0.86,0.46,0.2);
    glPushMatrix();
        glTranslated(xVenus,yVenus,0);
        glBegin(GL_POLYGON);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(radioVenus*cos(i), radioVenus*sin(i));
            }
        glEnd();
    glPopMatrix();



    //def variables para Tierra
    int radioTierra = 4;
    int radioTraslacionTierra = 50;
    theta = t;  //Tiempo de traslacion
    double FocoTierra=radioFoco*cos(theta);
    double xTierra=(radioTraslacionTierra*cos(theta) + FocoTierra);
    double yTierra=radioTraslacionTierra*sin(theta);

    //dibujar Tierra
    glColor3d(0,0,1);
    glPushMatrix();
    glTranslated(xTierra, yTierra, 0);
    glBegin(GL_POLYGON);
        for(double i=0 ; i<2*PI ; i+=0.001){
            glVertex2d(radioTierra*cos(i), radioTierra*sin(i));
        }
    glEnd();
    glPopMatrix();


    //def variables para Luna
    double radioLuna = 0.5;
    int radioTraslacionLuna = 7;
    theta = t*4;  //Tiempo de traslacion
    double xLuna=(radioTraslacionLuna*cos(theta) + xTierra) ;
    double yLuna=(radioTraslacionLuna*sin(theta) + yTierra) ;

    //dibujar Luna
    glColor3d(1,1,1);
    glPushMatrix();
        glTranslated(xLuna, yLuna, 0);
        glBegin(GL_POLYGON);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(radioLuna*cos(i), radioLuna*sin(i));
            }
        glEnd();
    glPopMatrix();



    //def variables para Marte
    int radioMarte = 3;
    int radioTraslacionMarte = 80;
    theta = t*0.5;  //Tiempo de traslacion
    double FocoMarte=radioFoco*2*cos(theta);
    double xMarte=radioTraslacionMarte*cos(theta)+FocoMarte;
    double yMarte=radioTraslacionMarte*sin(theta);

    //dibujar Marte
    glColor3d(1,0,0);
    glPushMatrix();
        glTranslated(xMarte,yMarte,0);
        glBegin(GL_POLYGON);
            for(double i=0 ; i<2*PI ; i+=0.001){
                glVertex2d(radioMarte*cos(i), radioMarte*sin(i));
            }
        glEnd();
    glPopMatrix();

    switch(nFoco){
        case 0:
            break;
        case 1:
            ShowFoco(FocoMercurio);
            break;
        case 2:
            ShowFoco(FocoVenus);
            break;
        case 3:
            ShowFoco(FocoTierra);
            break;
        case 4:
            ShowFoco(FocoMarte);
            break;
        case 5:
            nFoco=0;
            break;
    }
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case 'z':
            nFoco++;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1900,1000);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Sistema Solar");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    iniciar();

    glutMainLoop();

    return EXIT_SUCCESS;
}
