#include <GL/glut.h>

#include "callbacks.h"

GLfloat light_position[] = {1, 1, 1, 1};
GLfloat light_ambient[] = {1.8, 1.8, 1.8, 1.8};
GLfloat light_diffuse[] = {0.3, 0.3, 0.3, 0.9};
GLfloat light_specular[] = {1, 1, 1, 1};

void init() {
    set_callbacks();

    init_camera(&camera);
    init_entities(&world);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHT0);
}
