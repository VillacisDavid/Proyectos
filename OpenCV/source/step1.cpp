/*
	Parte 1 del examen parcial
	Este programa divide una imagen en 16 bloques (4x4)
	aplica un filtro a cada bloque y luego vuelve a unirlos
	La aplicacion de filtros se hace en paralelo
	Finalmente, calcula el tiempo de ejecucion del filtrado
	y el tiempo de ejecucion total del programa
*/

#include<iostream>
#include<vector>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<omp.h>

// Divide la imagen en COLxROW bloques
std::vector<cv::Mat> dividirImagen(cv::Mat image, int COLS, int ROWS){

	// Obtener el tamaño de la imagen
	int img_height, img_width;
	img_height = image.rows;
	img_width = image.cols;
	std::cout << cv::format("Tamaño de la imagen: %ix%i pixeles",img_height,img_width)<<std::endl;
	
	// Obtener el tamaño de los bloques
	int block_height, block_width;
	block_height = img_height/ROWS;
	block_width = img_width/COLS;

	std::vector<cv::Mat> bloques;

	// Generar bloques y agregarlos al vector 
	for(int y=0;y<ROWS;y++)
	{
		for(int x=0;x<COLS;x++)
		{
			cv::Rect roi( block_width  * x,
                    block_height * y,
                    block_width,
                    block_height);

      		bloques.push_back( image( roi ) );
		}
	}

	return bloques;
}

int main(int argc, char** argv){

	// Inicializacion de variables
	double inicio_ejecucion, tiempo_ejecucion;
	double inicio_filtro, fin_filtro;
	const int COL_BLOQUES = 4;
	const int ROW_BLOQUES = 4; 

	// Inicio del tiempo de ejecucion
	inicio_ejecucion = omp_get_wtime();

	/* Tarea 1:  Cargar la imagen */
	cv::Mat image = cv::imread("./imagenes/test.jpg");

    // Mensaje de error si no se encuentra la imagen
    if (image.empty()) 
    {
        std::cout << "No se encontro la imagen" << std::endl;
    }

	/* Tarea 2: Dividir la imagen */
	std::vector<cv::Mat> bloques = dividirImagen(image, COL_BLOQUES, ROW_BLOQUES);

	for(int i = 0; i<bloques.size();i++)
	{
		cv::imshow(cv::format("./imagenes/%i.jpg",i), bloques[i]);
	}
	cv::waitKey();
	/* Tarea 3: Aplicar filtros en paralelo */
	inicio_filtro = omp_get_wtime();

	// Creando kernels para filtros
	std::vector<cv::Mat>kernels;

	// Kernel "identidad"
	kernels.push_back( (cv::Mat_<double>(3,3)<< 0,0,0,0,1,0,0,0,0) );
	// Kernel Blur
	cv::Mat krn_blur = cv::Mat::ones(5,5, CV_64F);
	krn_blur = krn_blur / 25;
	kernels.push_back( krn_blur );
	// Kernel 
	kernels.push_back( (cv::Mat_<double>(3,3)<< 0,0,0,0,1,0,0,0,0) );
	// Kernel 	
	kernels.push_back( (cv::Mat_<double>(3,3)<< 0,0,0,0,1,0,0,0,0) );
	
	// Apply identity filter using kernel
 
    // Blurred using kernel
    // Initialize matrix with all ones
    cv::Mat kernel2 = cv::Mat::ones(5,5, CV_64F);
    // Normalize the elements
    kernel2 = kernel2 / 25;
    cv::Mat img;
    cv::filter2D(image, img, -1 , kernel2, cv::Point(-1, -1), 0, 4);
    cv::imwrite("./imagenes/blur_kernel.jpg", img);

	/* Tarea 4: Calcular tiempos de ejecucion */

	// Calculo del tiempo de filtro
	fin_filtro = omp_get_wtime() - inicio_filtro;
	std::cout << "Tiempo aplicando filtros: " << fin_filtro << std::endl;

	// Calculo del tiempo total de ejecucion
	tiempo_ejecucion = omp_get_wtime() - inicio_ejecucion;
	std::cout << "Tiempo de ejecucion: " << tiempo_ejecucion << std::endl;
	
}
