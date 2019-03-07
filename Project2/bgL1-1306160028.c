

#include <windows.h>
#include "GL/glut.h"
#include <stdio.h>
#include <math.h>

void display();
void arkaPlanRenk();
void bezierCurve(float);
//int factorial(int);
//float binomDeger(int, int);


float P[4][2];
float bezierX;
float bezierY;
float sonucX = 0;
float sonucY = 0;


int main(int argc, char** argv) {
	
	P[0][0] = 0;
	P[0][1] = 0;
	P[1][0] = 0.3f;
	P[1][1] = 0.8f;
	P[2][0] = 0.9f;
	P[2][1] = 0.8f;
	P[3][0] = 1;
	//P[3][1] = 1;
	P[3][1] = 0;

	


	bezierCurve(0.25f);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("1306160028");
	glutDisplayFunc(display);
	arkaPlanRenk();
	glutMainLoop();
}

void arkaPlanRenk() {
	glClearColor(0.9, 0.9, 1, 0.0); 

	//glColor3f(0.314, 0.314, 0.000);

	glLoadIdentity();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//X ekseni
	glColor3f(1.0f, 0.0f, 0.0f); // Koordinat çizgilerini kýrmýzý yaptým.
	glBegin(GL_LINES);
	glVertex2f(-4.0f, 0.0f);
	glVertex2f(4.0f, 0.0f);
	glEnd();

	//Y ekseni
	glBegin(GL_LINES);
	glVertex2f(0.0, -4.0f);
	glVertex2f(0.0, 4.0f);
	glEnd();
	glFlush();


	//P noktalarýnýn birleþtirilmesi sonucu çýkan þekil
	glColor3i(100, 100, 200);
	glBegin(GL_LINES);

	for (int i = 0; i <= 2; i++) {
		glVertex2f(P[i][0], P[i][1]);
		glVertex2f(P[i+1][0], P[i+1][1]);
	}
	glEnd();
	glFlush();



	//Bezier Eðrisinin çizimi
	
	//Çizginin daha belirgin olmasý için çizginin kalýnlýðýný yükselttim. Stackoverflow'dan buldum.	varsayýlan deðer 1'di.
	glLineWidth(1.5f);
	glColor3f(0.5f, 0.5f, 1);
	glBegin(GL_LINES);
	
	
	for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
		
		bezierCurve(t);
		glVertex2f(bezierX,bezierY);
		printf("%2.5f\n", bezierX);
	}

	glEnd();
	glFlush();

	
	
}

void bezierCurve(float t) {

	//Bezier Deðeri, 4 Nokta kullanýlacaðý için faktoriyel ve binom deðerlerini kullanmadan aþaðýdaki gibi yazdým.
	
	bezierX = pow(1 - t, 3)*P[0][0] + 3 * pow(1 - t, 2)*t*P[1][0] + 3 * (1 - t)*pow(t, 2)*P[2][0] + pow(t, 3)*P[3][0];
	bezierY = pow(1 - t, 3)*P[0][1] + 3 * pow(1 - t, 2)*t*P[1][1] + 3 * (1 - t)*pow(t, 2)*P[2][1] + pow(t, 3)*P[3][1];
		
}



/*
	int factorial(int n) {
	if (n == 1)
		return (1);

	else if (n > 1)
		n = n * factorial(n - 1);
	else {
		//n'in deðeri asla 0'ýn altýna düþmez. Her ihtimale karþý burayý ekledim.
		system("PAUSE");
	}
		return n;
	}
	float binomDeger(int n, int k) {
	return (factorial(n) / ( factorial(k)*factorial(n - k) ));}
	
	*/
