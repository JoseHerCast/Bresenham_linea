//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//

#include "Main.h"

int window_w = 400;
int window_h = 400;


void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Bresenham(int Xi, int Yi, int Xf, int Yf) {

	//Debido a que se utilizo la función vertex3f, se utilizan variables de tipo GLfloat
	GLfloat x1 = Xi;
	GLfloat y1 = Yi;
	GLfloat x2 = Xf;
	GLfloat y2 = Yf;
	//Calculamos los incrementos en X y Y
	int Dy = Yf - Yi;
	int Dx = Xf - Xi;
	int dy = fabs(Dy);
	int dx = fabs(Dx);
	//Calculamos la pendiente para verificicar que este entre 0-1
	float M = Dy / Dx;
	//Se realiza el algoritmo para el caso estandar (Se omite caso especial)
	if (Xi < Xf) {//Condición 1
		if (M >= 0.0f && M <= 1.0f) {//Condición 2: pendiente entre 0-1
			if (Xi >= 0 && Xf >= 0 && Yi >= 0 && Yf >= 0) {//Condición 3: Solo valores positivos
				//Primer paso se dibuja el primer punto de la línea
				GLfloat Xk = x1;
				GLfloat Yk = y1;
				glPointSize(1);//Tamaño de punto a dibujar
				glBegin(GL_POINTS);
				glColor3f(1.0f,1.0f,1.0f);//Color blanco
				glVertex3f(Xk, Yk, -1.0f);
				glEnd();
				//Calculamos los parametros 2 delta de X y 2 delta de Y
				int D2y = 2 * Dy;
				int D2x = 2 * Dx;
				//Asignamos el valor para el primer condicional
				int Pk = D2y - Dx;
				/*Ciclo que se cumple hasta que cumplimos el número de pasos que es igual en este caso
				al valor del incremento en X*/
				for (int j = 0; j <= Dx; j++) {
					//Si el condicional actual es menor a 0
					if (Pk < 0) {
						//Dibujamos el punto (Xk+1,Y)
						Xk++;
						glBegin(GL_POINTS);
						glColor3f(1.0f, 1.0f, 1.0f);
						glVertex3f(Xk, Yk, -1.0f);
						glEnd();
						//Calculamos condicional correspondiente
						Pk = Pk + D2y;					}
					//Caso contrario
					else {
						//Dibujamos el punto (Xk+1,Yk+1)
						Xk++;
						Yk++;
						glBegin(GL_POINTS);
						glColor3f(1.0f, 1.0f, 1.0f);
						glVertex3f(Xk, Yk, -1.0f);
						glEnd();
						//Calculamos condicional correspondiente
						Pk = Pk + D2y - D2x;
					}
				}
			}
			//Si cualquiera de las condiciones iniciales no se cumple, el programa finaliza.
			else exit(0);
		}
		else 
			//Caso especial cuando la pendiente es negativa
			if (fabs(M) >= 0.0f && fabs(M) <= 1.0f) {
				if (Xi >= 0 && Xf >= 0 && Yi >= 0 && Yf >= 0) {//Condición 3: Solo valores positivos
				//Primer paso se dibuja el primer punto de la línea
					GLfloat Xk = x1;
					GLfloat Yk = y1;
					glPointSize(1);//Tamaño de punto a dibujar
					glBegin(GL_POINTS);
					glColor3f(1.0f, 0.0f, 1.0f);//Color violeta
					glVertex3f(Xk, Yk, -1.0f);
					glEnd();
					//Calculamos los parametros 2 delta de X y 2 delta de Y
					int D2y = 2 * dy;
					int D2x = 2 * dx;
					//Asignamos el valor para el primer condicional
					int Pk = D2y + dx;
					/*Ciclo que se cumple hasta que cumplimos el número de pasos que es igual en este caso
					al valor del incremento en X*/
					for (int j = 0; j <= dx; j++) {
						//Si el condicional actual es menor a 0
						if (Pk < 0) {
							//Dibujamos el punto (Xk+1,Y)
							Xk++;
							glBegin(GL_POINTS);
							glColor3f(1.0f, 0.0f, 1.0f);//Color violeta
							glVertex3f(Xk, Yk, -1.0f);
							glEnd();
							//Calculamos condicional correspondiente (esta vez es una resta)
							Pk = Pk + D2y;
						}
						//Caso contrario
						else {
							//Dibujamos el punto (Xk+1,Yk+1)
							Xk++;
							Yk--;//Esta vez se decrementa
							glBegin(GL_POINTS);
							glColor3f(1.0f, 0.0f, 1.0f);//Color violeta
							glVertex3f(Xk, Yk, -1.0f);
							glEnd();
							//Calculamos condicional correspondiente(Se invierten los simbolos)
							Pk = Pk - D2y + D2x;
						}
					}
				}
				//Si cualquiera de las condiciones iniciales no se cumple, el programa finaliza.
				else exit(0);
			}
			else exit(0);
	}
	else exit(0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Bresenham(5,7,35,14);
	Bresenham(5, 7, 80, 35);
	Bresenham(0, 0, 40, 40);
	Bresenham(0, 0, 75, 50);
	Bresenham(0, 0, 50,0);
	Bresenham(50, 50, 75, 50);
	Bresenham(50, 50, 75, 25);
	Bresenham(50, 50, 75, 75);
	Bresenham(25, 38, 35, 25);
	Bresenham(0, 150, 175, 150);
	Bresenham(25, 250, 100, 150);


    glutSwapBuffers ( );
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glOrtho(0,400,0,400,0.1,20);	
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (window_w, window_h);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  //glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  //glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



