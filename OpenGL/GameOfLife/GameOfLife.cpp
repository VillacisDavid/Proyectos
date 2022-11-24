#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

const int width = 1100;  
const int height = 800;
int rows;
int columns;
const int resolution = 5; 
int **grid;
int **newGrid;

void drawRect(int x, int y, int w, int h){
    glBegin(GL_POLYGON);
        glVertex2i(x,y);
        glVertex2i(x+w,y);
        glVertex2i(x+w,y+h);
        glVertex2i(x,y+h);
    glEnd();
}

void drawGrid(int **grid){
    glColor3d(0,0,0);
    for(int i = 0; i< rows; i++){
        for(int j = 0; j<columns; j++){
            if(grid[i][j]==1){
                drawRect(i*resolution,j*resolution,resolution,resolution); 
            }
        }
    }
}

void copiar(int **grid, int **newGrid){
    for(int i = 0; i< rows; i++){
        for(int j = 0; j<columns; j++){
        grid[i][j]=newGrid[i][j];
        }
    }
}

void iniciar(){
    glClearColor(1,1,1,1);
    gluOrtho2D(0,width,height,0);

    srand(time(NULL));
    
    // Largo de columnas y filas
    columns =  height/resolution;
    rows =  width/resolution;

    // Inicializar matrices
    newGrid = new int*[rows];
    grid = new int*[rows];
    for(int c=0; c<rows; c++){
        grid[c] = new int[columns];
        newGrid[c] = new int[columns];
    };

    // Llenar matriz con 0s
    for(int i = 0; i< rows; i++){
        for(int j = 0; j<columns; j++){
            grid[i][j]=0;
            newGrid[i][j]=0;
       }
    }

    // Llenar matriz con 1s o 0s aleatorios
    for(int i = 1; i< rows-1; i++){
        for(int j = 1; j<columns-1; j++){
            if(rand()%100>90){
                grid[i][j]=1;
            }else{
                grid[i][j]=0;
            }
            
       }
    }
    copiar(newGrid,grid);
}

void compute(int **grid, int **newGrid){
    int count=0;
    for(int i = 1; i<rows-1; i++){
        for(int j = 1; j<columns-1; j++){
            count=0;
            count+=grid[i-1][j-1];
            count+=grid[i-1][j];
            count+=grid[i-1][j+1];

            count+=grid[i][j-1];
            count+=grid[i][j+1];

            count+=grid[i+1][j-1];
            count+=grid[i+1][j];
            count+=grid[i+1][j+1];

            // std::cout<<count;
            if(grid[i][j]==1){
                if(count<2||count>3){
                    newGrid[i][j]=0;
                }
            }else{
                if(count==3){
                    newGrid[i][j]=1;
                }
            }
            
        }
    }


}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid(grid);
    glutSwapBuffers();
    
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
            compute(grid,newGrid);
            copiar(grid,newGrid);
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("Game of Life");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);

    iniciar();

    glutMainLoop();

    return EXIT_SUCCESS;
}