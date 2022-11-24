// w,a,s,d para trasladar
// las flechas para rotar
// + y - para escalar
// clic izquierdo para mover a la posicion del mouse

#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

const float width = 800;
const float height = 800;
float teapotSize = 50;
float rotSpeed = 15, movSpeed = 15;
float rotx=0,roty=0,rotz=0;

struct vec3d{
    float x=0;
    float y=0;
    float z=0;
}pos, mousePos;


void drawTeapot(vec3d pos, float tsize){
    glColor3f(1,0,0);
    glPushMatrix();
        glTranslatef(pos.x, pos.y, pos.z);
        glRotatef(rotx,1,0,0);
        glRotatef(roty,0,1,0);
        glRotatef(rotz,0,0,1);
        glScalef(teapotSize,teapotSize,teapotSize);
        glutWireTeapot(1);
    glPopMatrix();
}

void iniciar(){
    glClearColor(0,0,0,0);
    glOrtho(0,width,0,height,0,-width);

    pos.x=width/2;
    pos.y=height/2;
    pos.z=width/2;
    
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    
    drawTeapot(pos,teapotSize);

    glutSwapBuffers();
    glutPostRedisplay();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            exit(0);
            break;

        case '+':
            teapotSize++;
            break;

        case '-':
            teapotSize--;
            break;
        case 'w':
            pos.y+=movSpeed;
            break;

        case 's':
            pos.y-=movSpeed;
            break;

        case 'a':
            pos.x-=movSpeed;
            break;

        case 'd':
            pos.x+=movSpeed;
            break;
    }

    glutPostRedisplay();
}

void spec(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            rotx+=rotSpeed;            
            break;
        case GLUT_KEY_DOWN:
            rotx-=rotSpeed;
            break;
        case GLUT_KEY_RIGHT:
            roty+=rotSpeed;
            break;
        case GLUT_KEY_LEFT:
            roty-=rotSpeed;
            break;
        
    }

    glutPostRedisplay();
}

void mouse(int boton, int estado, int mousex, int mousey){
    float posy;
    if(boton==GLUT_LEFT_BUTTON && estado == GLUT_DOWN){
        // mousey da la posicion comenzando de arriba hacia abajo, pero en este caso necesito que comience de abajo
        posy= (1 - (float)mousey/height)*height;  
        mousePos={(float)mousex, posy, 0};
        pos.x=mousePos.x;
        pos.y=mousePos.y; 
    };

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Tetera");
    
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(spec);
    glutMouseFunc(mouse);

    iniciar();

    glutMainLoop();

    return EXIT_SUCCESS;
}