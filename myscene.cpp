
#include "Angel.h"

GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat blackgray[] = { 0.3, 0.3, 0.3, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat cyan[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat blue[] = { 0.0, 0.4, 0.8, 1.0};
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat whitegray[] = { 0.6, 0.6, 0.6, 1.0 };

GLfloat direction[] = { 1.0, 1.3, 0.0, 0.0 };

void draw_rectangle(float scale_y, int translate_x, int translate_z){
  // draw a rectangle with a fixed square
  // scale_y: scale the height, will push down on y axis accordingly
  // translate_x: the offset to translate on x axis according to the highest one
  // translate_z: the offset to translate on z axis according to the highest one
  glPushMatrix();
  glTranslatef(1.6*translate_x, -0.2*((1.0-scale_y)/0.05), 1.6*translate_z);
  glScalef(0.2, scale_y, 0.2);
  glutSolidCube(8.0);
  glPopMatrix();
}

void draw_crow(){
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, black);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

  // head and mouth
  glPushMatrix();
  glTranslatef(-1.5, 7, 0);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-10, 0.0, 0.0, 1.0);
  glRotatef(-90, 0.0, 1.0, 0.0);
  glutSolidCone(1.0, 2.5, 16, 40);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.5, 7, 0);
  glScalef(0.5, 0.5, 0.5);
  glutSolidSphere(0.95, 16, 40);
  glPopMatrix();

  // body
  glPushMatrix();
  glTranslatef(-1.5, 5, 0);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-90, 1.0, 0.0, 0.0);
  glutSolidCone(1.0, 4.0, 16, 40);
  glPopMatrix();

  // eye
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

  glPushMatrix();
  glTranslatef(-1.5, 7.4, 0.3);
  glScalef(0.5, 0.5, 0.5);
  glutSolidSphere(0.3, 16, 40);
  glPopMatrix();
}

void draw_princess(){
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, white);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);

  // hat
  glPushMatrix();
  glTranslatef(-1.5, 7, 0);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-20, 0.0, 0.0, 1.0);
  glRotatef(-90, 0.0, 1.0, 0.0);
  glutSolidCone(1.0, 2.5, 16, 40);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.5, 7, 0);
  glScalef(0.5, 0.5, 0.5);
  glutSolidSphere(0.95, 16, 40);
  glPopMatrix();

  // body
  glPushMatrix();
  glTranslatef(-1.5, 5, 0);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-95, 1.0, 0.0, 0.0);
  glutSolidCone(1.0, 4.0, 16, 40);
  glPopMatrix();

  // legs
  glPushMatrix();
  glTranslatef(-1.6, 4, 0.0);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-95, 1.0, 0.0, 0.0);
  glutSolidCylinder(0.2, 1.0, 16, 40);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-1.5, 4, -0.3);
  glScalef(0.5, 0.5, 0.5);
  glRotatef(-95, 1.0, 0.0, 0.0);
  glutSolidCylinder(0.2, 1.0, 16, 40);
  glPopMatrix();


}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();

  // Rotate the scene so we can see the penrose stairs
  glScalef(1.2, 1.2, 1.2);
  glTranslatef(1.5, 1.0, -3.0);
  glRotatef(54.0, 1.0, 0.0, 0.0);
  glRotatef(-35.0, 0.0, 1.0, 0.0);
  glRotatef(10.0, 0.0, 0.0, 1.0);

  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, blue);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blackgray);

  // twelve rectangles in total
  draw_rectangle(1.0, 0, 0);

  draw_rectangle(0.95, 1, 0);

  draw_rectangle(0.9, 1, 1);

  draw_rectangle(0.85, 1, 2);

  draw_rectangle(0.8, 0, 2);

  draw_rectangle(0.75, -1, 2);

  draw_rectangle(0.7, -2, 2);

  draw_rectangle(0.65, -3, 2);

  draw_rectangle(0.6, -3, 1);

  draw_rectangle(0.55, -3, 0);

  draw_rectangle(0.5, -3, -1);

  draw_rectangle(0.45, -3, -2);

  // draw the princess
  glPushMatrix();
  glTranslatef(-0.5, 1.5, 0.0);
  glScalef(0.8, 0.8, 0.8);
  draw_princess();
  glPopMatrix();

  // draw the crow
  glPushMatrix();
  glTranslatef(5.2, 1.5, 5.5);
  draw_crow();
  glPopMatrix();

  glPopMatrix();
  glFlush();
}

void reshape(GLint weight, GLint height) {
  glViewport(0, 0, weight, height);
  glMatrixMode(GL_PROJECTION);
  GLfloat aspect = GLfloat(weight) / GLfloat(height);
  glLoadIdentity();
  if (weight <= height) {
    glOrtho(-10.0, 10.0, -10.0/aspect, 10.0/aspect, -10.0, 10.0);
  } else {
    glOrtho(-10.0*aspect, 10.0*aspect, -10.0, 10.0, -10.0, 10.0);
  }
}

void init() {
  glLightfv(GL_LIGHT0, GL_AMBIENT, black);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, whitegray);
  glLightfv(GL_LIGHT0, GL_SPECULAR, whitegray);
  glLightfv(GL_LIGHT0, GL_POSITION, direction);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glClearColor(0.0, 0.8, 0.8, 1.0);
}

void keyboard( unsigned char key, int x, int y ) {
  switch( key ) {
  case 033: // Escape Key
  case 'q':
  case 'Q':
    printf("Quit!\n");
    exit( EXIT_SUCCESS );
	   break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Penrose Stairs!");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
  glutMainLoop();
}
