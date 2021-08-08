#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

float current_rotation = 0.0f;
float current_scale = 1.0f;
float current_position_x = 0.0f;
float current_position_y = 0.0f;
float current_position_z = 0.0f;

void frame_updater(int value) {
    glutPostRedisplay();
    glutTimerFunc(10, frame_updater, 0);
}
void reshape_handler(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 1.0, 100.0);
}
void keyboard_handler(unsigned char key, int x, int y) {
    switch (key) {
        case 87:
            current_position_y += 0.01f;
            break;
        case 119:
            current_position_y += 0.01f;
            break;
        case 83:
            current_position_y -= 0.01f;
            break;
        case 115:
            current_position_y -= 0.01f;
            break;
        case 68:
            current_position_x += 0.01f;
            break;
        case 100:
            current_position_x += 0.01f;
            break;
        case 65:
            current_position_x -= 0.01f;
            break;
        case 97:
            current_position_x -= 0.01f;
            break;
        case 81:
            current_rotation -= 1.0f;
            break;
        case 113:
            current_rotation -= 1.0f;
            break;
        case 69:
            current_rotation += 1.0f;
            break;
        case 101:
            current_rotation += 1.0f;
            break;
        case 90:
            current_scale += 0.01f;
            break;
        case 122:
            current_scale += 0.01f;
            break;
        case 88:
            current_scale -= 0.01f;
            break;
        case 120:
            current_scale -= 0.01f;
            break;
    }
}

void setTranslate(float x, float y, float z) {
    glTranslatef(x, y, z);
}

void setScale(float x) {
    glScalef(x, x, x);
}
void setRotate(float x) {
    glRotatef(x, 0.0f, 1.0f, 0.0f);
}

void prepare_render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setRotate(0.0f);
    setTranslate(0.0f, 0.0f, -2.0f);
    setScale(1.0f);
    glPopMatrix();
    glPushMatrix();
    setRotate(current_rotation);
    setTranslate(current_position_x, current_position_y, current_position_z);
    setScale(current_scale);
}

void draw_house() {

    glClear(GL_COLOR_BUFFER_BIT);
    
    // On duvar
    glColor3f(0.917, 0.686, 0.482);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.2, 0.0);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.4, -0.2, 0.0);
    glVertex3f(-0.4, -0.2, 0.0);
    glEnd();

    // Arka duvar
    glColor3f(0.917, 0.686, 0.482);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.2, -0.4);
    glVertex3f(0.4, 0.2, -0.4);
    glVertex3f(0.4, -0.2, -0.4);
    glVertex3f(-0.4, -0.2, -0.4);
    glEnd();

    // Sag duvar
    glColor3f(0.917, 0.686, 0.482);
    glBegin(GL_POLYGON);
    glVertex3f(0.4, 0.2, -0.4);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.4, -0.2, 0.0);
    glVertex3f(0.4, -0.2, -0.4);
    glEnd();

    // Sol duvar
    glColor3f(0.917, 0.686, 0.482);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.2, -0.4);
    glVertex3f(-0.4, 0.2, 0.0);
    glVertex3f(-0.4, -0.2, 0.0);
    glVertex3f(-0.4, -0.2, -0.4);
    glEnd();

    // Zemin
    glColor3f(0.192, 0.741, 0.180);
    glBegin(GL_POLYGON);
    glVertex3f(-0.8, -0.2, 0.4);
    glVertex3f(0.8, -0.2, 0.4);
    glVertex3f(0.8, -0.2, -0.8);
    glVertex3f(-0.8, -0.2, -0.8);
    glEnd();

    // Sol Cati
    glColor3f(0.521, 0.439, 0.239);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.17, 0.1);
    glVertex3f(-0.5, 0.17, -0.5);
    glVertex3f(0.0, 0.35, -0.5);
    glVertex3f(0.0, 0.35, 0.1);
    glEnd();

    // Sag Cati
    glColor3f(0.521, 0.439, 0.239);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.17, 0.1);
    glVertex3f(0.5, 0.17, -0.5);
    glVertex3f(0.0, 0.35, -0.5);
    glVertex3f(0.0, 0.35, 0.1);
    glEnd();

    // On Cati
    glColor3f(0.886, 0.866, 0.811);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.4, 0.2, 0.0);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.0, 0.35, 0.0);
    glEnd();

    // Arka Cati
    glColor3f(0.886, 0.866, 0.811);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.4, 0.2, -0.4);
    glVertex3f(0.4, 0.2, -0.4);
    glVertex3f(0.0, 0.35, -0.4);
    glEnd();

    // kapi
    glColor3f(0.364, 0.309, 0.176);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1, 0.1, 0.01);
    glVertex3f(0.1, 0.1, 0.01);
    glVertex3f(0.1, -0.2, 0.01);
    glVertex3f(-0.1, -0.2, 0.01);
    glEnd();

    // sol pencere
    glColor3f(0.839, 0.980, 0.972);
    glBegin(GL_POLYGON);
    glVertex3f(-0.3, 0.1, 0.01);
    glVertex3f(-0.2, 0.1, 0.01);
    glVertex3f(-0.2, 0.0, 0.01);
    glVertex3f(-0.3, 0.0, 0.01);
    glEnd();

    // sag pencere
    glColor3f(0.839, 0.980, 0.972);
    glBegin(GL_POLYGON);
    glVertex3f(0.3, 0.1, 0.01);
    glVertex3f(0.2, 0.1, 0.01);
    glVertex3f(0.2, 0.0, 0.01);
    glVertex3f(0.3, 0.0, 0.01);
    glEnd();

}

void render() {
    prepare_render();
    draw_house();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("CSE 461 HW1");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard_handler);
    glutReshapeFunc(reshape_handler);
    glutTimerFunc(10, frame_updater, 0);
    glutMainLoop();
    return 0;
}
