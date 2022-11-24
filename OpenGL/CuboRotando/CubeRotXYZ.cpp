//From Javidx9 3dEngine video (1)  https://www.youtube.com/watch?v=ih20l3pJoeU

#include <GL/glut.h>

#include <stdlib.h>
#include <vector>
#include <math.h>
#include <iostream>

struct vec3d{
	double x, y, z;
};

struct triangulo{
	vec3d p[3];
};

struct mat4x4{
	double m[4][4] = { 0 };
};

struct cubeMesh{
    std::vector<triangulo> tris;
};

void iniciar(){
    glClearColor(0.1,0.1,0.1,0);
    glOrtho(-1,1,-1,1,-1,1);
}

void MultiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m);

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0; //Tiempo transcurrido desde el inicio en milisegundos
    double theta = 0; //Angulo de rotacion
    const double PI = 3.14159;

    double cerca = 0.1 ;
    double lejos = 100 ;
    double fov = 90.0; //field of view; Zoom
    double winHeight = (double)glutGet(GLUT_WINDOW_HEIGHT);
    double winWidth = (double)glutGet(GLUT_WINDOW_WIDTH);
    double aspectRatio = winHeight/winWidth;
    double fovRad = 1.0 / tan(fov * 0.5 / 180.0 * PI );

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,1,0.2);

    cubeMesh mesh;
    mat4x4  matRotZ, matRotX, matProj;
    triangulo triRotZ, triRotZX, triTranslated, triProjected;

    //Para pruebas
    triangulo triRotY, triRotX, triRotZXY;
    mat4x4 matRotY;

    theta += t ;

    //Matriz de rotacion en el eje Z
    //    { cos(theta)      sin(theta)     0     0 }
    //    {-sin(theta)      cos(theta)     0     0 }
    //    { 0               0              1     0 }
    //    { 0               0              0     1 }
    matRotZ.m[0][0]=cos(theta);
    matRotZ.m[1][1]=cos(theta);
    matRotZ.m[2][2]= 1 ;
    matRotZ.m[3][3]= 1 ;
    matRotZ.m[1][0]=-sin(theta);
    matRotZ.m[0][1]=sin(theta);


    //Matriz de rotacion en el eje X
    //    { 1      0            0           0   }
    //    { 0      cos(theta)   sin(theta)  0   }
    //    { 0     -sin(theta)   cos(theta)  0   }
    //    { 0      0            0           1   }
    matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cos(theta);
	matRotX.m[1][2] = sin(theta);
	matRotX.m[2][1] = -sin(theta);
	matRotX.m[2][2] = cos(theta);
	matRotX.m[3][3] = 1;

	//Matriz de rotacion en el eje Y
    //    { cos(theta)    0    -sin(theta)      0   }
    //    { 0             1        0            0   }
    //    { sin(theta)    0     cos(theta)      0   }
    //    { 0             0        0            1   }
    matRotY.m[0][0] = cos(theta);
	matRotY.m[1][1] = 1 ;
	matRotY.m[2][2] = cos(theta);
	matRotY.m[3][3] = 1;
    matRotY.m[2][0] = sin(theta);
    matRotY.m[0][2] = -sin(theta);

	//Matriz de proyeccion
	//    { aspectRatio*fovRad   0               0                  0}
    //    { 0                  fovRad            0                  0}
    //    { 0                    0        lejos/(lejos-cerca)       1}
    //    { 0                    0    (-lejos*cerca)/(lejos-cerca)  0}
	matProj.m[0][0] = aspectRatio * fovRad;
    matProj.m[1][1] = fovRad;
    matProj.m[2][2] = lejos / (lejos - cerca);
    matProj.m[3][2] = (-lejos * cerca) / (lejos - cerca);
    matProj.m[2][3] = 1.0;
    matProj.m[3][3] = 0.0;




    mesh.tris={

    //Adelante
    { 0.0, 0.0, 0.0,    0.0, 1.0, 0.0,    1.0, 1.0, 0.0 },//tri = {vector, vector, vector} = {(x,y,z),(x,y,z),(x,y,z)}
    { 0.0, 0.0, 0.0,    1.0, 1.0, 0.0,    1.0, 0.0, 0.0 },

    //Derecha
    { 1.0, 0.0, 0.0,    1.0, 1.0, 0.0,    1.0, 1.0, 1.0 },
    { 1.0, 0.0, 0.0,    1.0, 1.0, 1.0,    1.0, 0.0, 1.0 },

    //Atras
    { 1.0, 0.0, 1.0,    1.0, 1.0, 1.0,    0.0, 1.0, 1.0 },
    { 1.0, 0.0, 1.0,    0.0, 1.0, 1.0,    0.0, 0.0, 1.0 },

    //Izquierda
    { 0.0, 0.0, 1.0,    0.0, 1.0, 1.0,    0.0, 1.0, 0.0 },
    { 0.0, 0.0, 1.0,    0.0, 1.0, 0.0,    0.0, 0.0, 0.0 },

    //Arriba
    { 0.0, 1.0, 0.0,    0.0, 1.0, 1.0,    1.0, 1.0, 1.0 },
    { 0.0, 1.0, 0.0,    1.0, 1.0, 1.0,    1.0, 1.0, 0.0 },

    //Abajo
    { 1.0, 0.0, 1.0,    0.0, 0.0, 1.0,    0.0, 0.0, 0.0 },
    { 1.0, 0.0, 1.0,    0.0, 0.0, 0.0,    1.0, 0.0, 0.0 },

    };

    glColor3d(0,1,0.2);
    for(auto tri: mesh.tris){

        //Triangulo rotando en el eje z
        MultiplyMatrixVector(tri.p[0],triRotZ.p[0],matRotZ);
        MultiplyMatrixVector(tri.p[1],triRotZ.p[1],matRotZ);
        MultiplyMatrixVector(tri.p[2],triRotZ.p[2],matRotZ);

/*      Solo para pruebas           */
        //Triangulo rotando en el eje x
        MultiplyMatrixVector(tri.p[0],triRotX.p[0],matRotX);
        MultiplyMatrixVector(tri.p[1],triRotX.p[1],matRotX);
        MultiplyMatrixVector(tri.p[2],triRotX.p[2],matRotX);

        //Triangulo rotando en el eje Y
        MultiplyMatrixVector(tri.p[0],triRotY.p[0],matRotY);
        MultiplyMatrixVector(tri.p[1],triRotY.p[1],matRotY);
        MultiplyMatrixVector(tri.p[2],triRotY.p[2],matRotY);


        //Triangulo rotando en el eje Z y en el eje X
        MultiplyMatrixVector(triRotZ.p[0],triRotZX.p[0],matRotX);
        MultiplyMatrixVector(triRotZ.p[1],triRotZX.p[1],matRotX);
        MultiplyMatrixVector(triRotZ.p[2],triRotZX.p[2],matRotX);


/*      Solo para pruebas           */
        //Triangulo rotando en el eje Z, en el eje X y en Y
        MultiplyMatrixVector(triRotZX.p[0],triRotZXY.p[0],matRotY);
        MultiplyMatrixVector(triRotZX.p[1],triRotZXY.p[1],matRotY);
        MultiplyMatrixVector(triRotZX.p[2],triRotZXY.p[2],matRotY);


        triTranslated=triRotZX;
        triTranslated.p[0].z+=3.0;
        triTranslated.p[1].z+=3.0;
        triTranslated.p[2].z+=3.0;

        MultiplyMatrixVector(triTranslated.p[0],triProjected.p[0],matProj);
        MultiplyMatrixVector(triTranslated.p[1],triProjected.p[1],matProj);
        MultiplyMatrixVector(triTranslated.p[2],triProjected.p[2],matProj);

        
        //Dibujar
        glBegin(GL_TRIANGLES);
        glVertex3d(triProjected.p[0].x,triProjected.p[0].y,triProjected.p[0].z);
        glVertex3d(triProjected.p[1].x,triProjected.p[1].y,triProjected.p[1].z);
        glVertex3d(triProjected.p[2].x,triProjected.p[2].y,triProjected.p[2].z);
        glEnd();
    };
    
    glColor3d(1,0,0.2);
    for(auto tri: mesh.tris){

        //Triangulo rotando en el eje z
        MultiplyMatrixVector(tri.p[0],triRotZ.p[0],matRotZ);
        MultiplyMatrixVector(tri.p[1],triRotZ.p[1],matRotZ);
        MultiplyMatrixVector(tri.p[2],triRotZ.p[2],matRotZ);

/*      Solo para pruebas           */
        //Triangulo rotando en el eje x
        MultiplyMatrixVector(tri.p[0],triRotX.p[0],matRotX);
        MultiplyMatrixVector(tri.p[1],triRotX.p[1],matRotX);
        MultiplyMatrixVector(tri.p[2],triRotX.p[2],matRotX);

        //Triangulo rotando en el eje Y
        MultiplyMatrixVector(tri.p[0],triRotY.p[0],matRotY);
        MultiplyMatrixVector(tri.p[1],triRotY.p[1],matRotY);
        MultiplyMatrixVector(tri.p[2],triRotY.p[2],matRotY);


        //Triangulo rotando en el eje Z y en el eje X
        MultiplyMatrixVector(triRotZ.p[0],triRotZX.p[0],matRotX);
        MultiplyMatrixVector(triRotZ.p[1],triRotZX.p[1],matRotX);
        MultiplyMatrixVector(triRotZ.p[2],triRotZX.p[2],matRotX);


/*      Solo para pruebas           */
        //Triangulo rotando en el eje Z, en el eje X y en Y
        MultiplyMatrixVector(triRotZX.p[0],triRotZXY.p[0],matRotY);
        MultiplyMatrixVector(triRotZX.p[1],triRotZXY.p[1],matRotY);
        MultiplyMatrixVector(triRotZX.p[2],triRotZXY.p[2],matRotY);


        triTranslated=triRotZX;
        triTranslated.p[0].z+=3.0;
        triTranslated.p[1].z+=3.0;
        triTranslated.p[2].z+=3.0;

        MultiplyMatrixVector(triTranslated.p[0],triProjected.p[0],matProj);
        MultiplyMatrixVector(triTranslated.p[1],triProjected.p[1],matProj);
        MultiplyMatrixVector(triTranslated.p[2],triProjected.p[2],matProj);

        
        //Dibujar
        glBegin(GL_LINE_LOOP);
        glVertex3d(triProjected.p[0].x,triProjected.p[0].y,triProjected.p[0].z);
        glVertex3d(triProjected.p[1].x,triProjected.p[1].y,triProjected.p[1].z);
        glVertex3d(triProjected.p[2].x,triProjected.p[2].y,triProjected.p[2].z);
        glEnd();

    };


    glutSwapBuffers();
}


static void idle(void)
{
    glutPostRedisplay();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("CuboXZ");

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    iniciar();

    glutMainLoop();

    return EXIT_SUCCESS;
}

void MultiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m){
    //Homogenizaci�n de coordenadas
	//o= vector output; i= vector input
	//Multiplica el vector input por la matriz 4x4 y lo pone en la matriz output
		o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
		o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
		o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
		float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

		if (w != 0.0f)
		{
			o.x /= w; o.y /= w; o.z /= w;
		}
	}
