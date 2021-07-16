#include<iostream>
#include<Windows.h>
#include<gl/freeglut.h>
//Radithya Airlangga-672019007
//Asisten Grafika Komputer A
void Inisialisasi(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(4.0f);
	gluOrtho2D(0, 300, 0, 300);
}
void Display(void) {
	float ax1=50, ay1=50, bx1=120, by1=200,
		ax2=50, ay2=160, bx2=200, by2=160,
		ax3=200, ay3=200, bx3=130, by3=50,
		ax4=50, ay4=90, bx4=200, by4=90,
		Mab1,Mab2, Mab3, Mab4, Cab1, Cab2, Cab3,Cab4,
		px, py, pz, pi, pa, pb, pc, pd;
	glClear(GL_COLOR_BUFFER_BIT);
	//Garis Perpotongan
	glBegin(GL_LINES);
	glColor3f(0.35f, 0.0f, 1.0f); //Garis Biru
		glVertex2f(ax1, ay1);
		glVertex2f(bx1, by1);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.1f); //Garis Hijau
		glVertex2f(ax2, ay2);
		glVertex2f(bx2, by2);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.92f, 0.0f); //Garis Kuning
		glVertex2f(ax3, ay3);
		glVertex2f(bx3, by3);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.92f); //Garis Ungu
		glVertex2f(ax4, ay4);
		glVertex2f(bx4, by4);
	glEnd();
	//Rumus Perpotongan
	Mab1 = (by1 - ay1) / (bx1 - ax1);
	Mab2 = (by2 - ay2) / (bx2 - ax2);
	Mab3 = (by3 - ay3) / (bx3 - ax3);
	Mab4 = (by4 - ay4) / (bx4 - ax4);
	Cab1 = ay1 - (ax1 * Mab1);
	Cab2 = ay2 - (ax2 * Mab2);
	Cab3 = ay3 - (ax3 * Mab3);
	Cab4 = ay4 - (ax4 * Mab4);
	//Titik Potong
	px = (Cab2 - Cab1) / (Mab1 - Mab2);
	py = (Mab1 * px) + Cab1;
	pz = (Cab3 - Cab2) / (Mab2 - Mab3);
	pi = (Mab2 * pz) + Cab2;
	pa = (Cab4 - Cab3) / (Mab3 - Mab4);
	pb = (Mab3 * pa) + Cab3;
	pc = (Cab4 - Cab1) / (Mab1 - Mab4);
	pd = (Mab1 * pc) + Cab1;
	//Output
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(px, py);
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(pa, pb);
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(pz, pi);
	glEnd();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(pc, pd);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(50, 200);
	glVertex2i(50, 50);
	glVertex2i(200, 50);
	glVertex2i(200, 200);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080, 720);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("Radithya Airlangga-672019007");
	glutDisplayFunc(Display);
	Inisialisasi();
	glutMainLoop();
}