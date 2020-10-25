#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;
GLfloat r, g, b;
GLint especMaterial;
GLdouble posluz;

float escalaX;
float escalaY;
float escalaW;
float escalaF;
float escalaZ;

// Função responsável pela especificação dos parâmetros de iluminação
void DefineIluminacao (void)
{
        GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
        GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};          // "cor"
        //GLfloat luzEspecular[4]={r, g, b, 1.0};
        GLfloat posicaoLuz[4]={0.0, 50.0, 150.0, 1.0};

        // Capacidade de brilho do material
        GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
        // Define a refletância do material
        //glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
        // Define a concentração do brilho
        //glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

        // Ativa o uso da luz ambiente
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

        // Define os parâmetros da luz de número 0
        glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        //glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}



// Função callback chamada para fazer o desenho
void Desenha(void)
{

	
	// Limpa a janela de visualização com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DefineIluminacao();

    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 125);
    char *string = "Comandos: ";
  
  while(*string){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
  }
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 110);
    char *string2 = "(D) Subir";
  
  while(*string2){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string2++);
  }
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 100);
    char *string3 = "(C) Descer";
  
  while(*string3){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string3++);
  }
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 90);
    char *string4 = "(Z) Pra frente";
  
  while(*string4){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string4++);
  }
  
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 80);
    char *string5 = "(X) Pra traz";
  
  while(*string5){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string5++);
  }  

    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 70);
    char *string6 = "(LEFT_BUTTON) Zoon in";
  
  while(*string6){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string6++);
  }    
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 60);
    char *string7 = "(RIGHT_BUTTON) Zoon out";
  
  while(*string7){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string7++);
  }    
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 50);
    char *string8 = "(F2) Apagar";
  
  while(*string8){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string8++);
  }      
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(-170, 40);
    char *string9 = "(F1) Acender";
  
  while(*string9){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string9++);
  }        
  
    glColor3f (0.0, 0.0, 0.0);
    glRasterPos2f(82, -72);
    char *string10 = "CHEGADA";
  
  while(*string10){
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string10++);
  }        
  
	// Troca cor corrente para azul
	glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha o teapot com a cor corrente (wire-frame)
	glPushMatrix();
	  glColor3f(1.0f, 0.0f, 1.0f);
      glTranslatef ((GLfloat) escalaW, escalaF, 0.0f);
	  glutSolidSphere(9, 250, 250);
	glPopMatrix();
	
	//sol
	glPushMatrix();
	  glColor3f(1.0f, 1.0f, 0.0f);
      glTranslatef (190.0f, 100.0f, 0.0f);
	  glutSolidSphere(20, 50, 50);
	glPopMatrix();

glPushMatrix();

glTranslatef (-130.0f, -150.0f, 0.0f);
  //obstáculos de cima
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(40,70);    glVertex2i(40,290);
  glVertex2i(40,70);    glVertex2i(50,70);
  glVertex2i(50,70);    glVertex2i(50,290);
  glVertex2i(50,290);   glVertex2i(40,290);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(80,100);    glVertex2i(80,290); //+40
  glVertex2i(80,100);    glVertex2i(90,100);
  glVertex2i(90,100);    glVertex2i(90,290);
  glVertex2i(90,290);   glVertex2i(80,290);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(120,50);    glVertex2i(120,290); //+40
  glVertex2i(120,50);    glVertex2i(130,50);
  glVertex2i(130,50);    glVertex2i(130,290);
  glVertex2i(130,290);   glVertex2i(120,290);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(160,190);    glVertex2i(160,290); //+40
  glVertex2i(160,190);    glVertex2i(170,190);
  glVertex2i(170,190);    glVertex2i(170,290);
  glVertex2i(170,290);   glVertex2i(160,290);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(200,90);    glVertex2i(200,290); //+40
  glVertex2i(200,90);    glVertex2i(210,90);
  glVertex2i(210,90);    glVertex2i(210,290);
  glVertex2i(210,290);   glVertex2i(200,290);
  glEnd();
  
  //obstáculos de baixo
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(40,0);    glVertex2i(40,50);
  glVertex2i(40,0);    glVertex2i(50,0);
  glVertex2i(50,0);    glVertex2i(50,50);
  glVertex2i(50,50);   glVertex2i(40,50);
  glEnd();
  
  //obstáculos de baixo
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(80,0);    glVertex2i(80,80);
  glVertex2i(80,0);    glVertex2i(90,0);
  glVertex2i(90,0);    glVertex2i(90,80);
  glVertex2i(90,80);   glVertex2i(80,80);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(120,0);    glVertex2i(120,30);
  glVertex2i(120,0);    glVertex2i(130,0);
  glVertex2i(130,0);    glVertex2i(130,30);
  glVertex2i(130,30);   glVertex2i(120,30);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(160,0);    glVertex2i(160,170);
  glVertex2i(160,0);    glVertex2i(170,0);
  glVertex2i(170,0);    glVertex2i(170,170);
  glVertex2i(170,170);   glVertex2i(160,170);
  glEnd();
  
  glBegin(GL_POLYGON);
  glColor3f (0.0, 1.0, 0.0);
  glVertex2i(200,0);    glVertex2i(160,70);
  glVertex2i(200,0);    glVertex2i(210,0);
  glVertex2i(210,0);    glVertex2i(210,70);
  glVertex2i(210,70);   glVertex2i(200,70);
  glEnd();
  
glPopMatrix();

	//nuvem 1
   glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (-190.0f, 25.0f, 2.0f);
	  glutSolidSphere(9, 250, 250);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (-185.0f, 30.0f, 0.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (-182.0f, 25.0f, 1.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (-170.0f, 30.0f, 0.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
   glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (-169.0f, 24.0f, -2.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();

////// nuvem 1

//nuvem 2

   glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (190.0f, 25.0f, 2.0f);
	  glutSolidSphere(9, 250, 250);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (185.0f, 30.0f, 0.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (182.0f, 25.0f, 1.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
    glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (170.0f, 30.0f, 0.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();
	
   glPushMatrix();
	  glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef (169.0f, 24.0f, -2.0f);
	  glutSolidSphere(9, 250, 245);
	glPopMatrix();


	// Execução dos comandos de desenho
	glutSwapBuffers();
}


// Inicialização
void Inicializa(void)
{
        // Define a cor de fundo da janela de visualização como branca
        glClearColor(0.0, 1.0, 1.0, 0.0);

        // Habilita a definição da cor do material a partir da cor corrente
        glEnable(GL_COLOR_MATERIAL);
        //Habilita o uso de iluminação
        glEnable(GL_LIGHTING);
        // Habilita a luz de número 0
        glEnable(GL_LIGHT0);
        // Habilita o depth-buffering
        glEnable(GL_DEPTH_TEST);

        // Habilita o modelo de colorização de Gouraud
        glShadeModel(GL_FLAT);

        // Inicializa a variável que especifica o ângulo da projeção
        // perspectiva
        angle=40;

        // Inicializa as variáveis usadas para alterar a posição do
        // observador virtual
        rotX = 360;
        rotY = 360;
        obsZ = 360;
        r, g, b = 1.0;
        especMaterial = 90;
}


// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	DefineIluminacao();
	// Especifica posição do observador e do alvo
	glTranslatef(0,0,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}


// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,500);

	PosicionaObservador();
}


// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimensões da viewport
	glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}


// Callback para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:	rotY--;
							break;
		case GLUT_KEY_RIGHT:rotY++;
							break;
		case GLUT_KEY_UP:	rotX++;
							break;
		case GLUT_KEY_DOWN:	rotX--;
							break;
		case GLUT_KEY_HOME:	obsZ++;
							break;
		case GLUT_KEY_END:	obsZ--;
							break;
		case GLUT_KEY_F2: glDisable(GL_LIGHT0);
                            break;     
		case GLUT_KEY_F1: glEnable(GL_LIGHT0);
                            break;                                                				
	}
	PosicionaObservador();
	glutPostRedisplay();
}


void eventoTeclado(unsigned char tecla, int x, int y)
{
          switch(tecla){
                    case  '=': escalaX += 0.1; 
                               escalaY += 0.1; 
                               break;
                    case '-':  escalaX -= 0.1;
                               escalaY -= 0.1; 
                               break;
                    case 27: exit(0);
                              break;
                    case 'z': escalaW += 3.90;
                              break;
                    case 'x': escalaW -= 3.90;
                              break;
                    case 'd': escalaF += 3.90;
                              break;
                    case 'c': escalaF -= 3.90;
                              break;
                    case 'a': escalaZ += 3.90;
                              break;
                    case 's': escalaZ -= 3.90;          
                        
                        }
          glutPostRedisplay();
}

// Programa Principal
int main()
{
    
    escalaX = 0;
    escalaY = 0;
    escalaW = -100;
    escalaF = -90;
    escalaZ = 200;
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posição inicial da janela GLUT
    glutInitWindowPosition(10,10);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize (1290, 680); 

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("labirinto 3d");

	// Registra a funcao callback de redesenho da janela de visualizacao
	glutDisplayFunc(Desenha);
	// Registra a funcao callback para tratamento das teclas especiais
	glutSpecialFunc(TeclasEspeciais);
	// Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
	// Registra a funcao callback para tratamento do mouse
	glutMouseFunc(GerenciaMouse);
	
	glutKeyboardFunc(eventoTeclado);

	Inicializa();
	glutMainLoop();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

