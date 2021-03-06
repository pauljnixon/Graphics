#include "Cone.h"

void Cone::drawTriangles(){
    int i,j;
    float x,y;
    x = PI * (2.0f / m_segmentsX);
    y = 0.5f / m_segmentsY;
    for (i = 0; i < m_segmentsX; i++){    
        //bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, -0.5f, 0.0f);
        glVertex3f(0.5f*cosf(i*x), -0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.5f, 0.5f*sinf((i+1)*x));
        for (j = 0; j < m_segmentsY; j++){
            // sides
            glNormal3f(-cosf((i+0.5f)*x), 0.0f, -sinf((i+0.5f)*x));

            glVertex3f((0.5f-(y*j))*cosf(i*x), -0.5f+(y*j*2), (-0.5f+(y*j))*sinf(i*x));
            glVertex3f((0.5f-(y*(j+1)))*cosf(i*x), -0.5f+(y*(j+1)*2), (-0.5f+(y*(j+1)))*sinf(i*x));
            glVertex3f((0.5f-(y*j))*cosf((i+1)*x),-0.5f+(y*j*2), (-0.5f+(y*j))*sinf((i+1)*x));

            glVertex3f((0.5f-(y*(j+1)))*cosf((i+1)*x), -0.5f+(y*(j+1)*2), (-0.5f+(y*(j+1)))*sinf((i+1)*x));
            glVertex3f((0.5f-(y*(j+1)))*cosf(i*x), -0.5f+(y*(j+1)*2), (-0.5f+(y*(j+1)))*sinf(i*x));
            glVertex3f((0.5f-(y*j))*cosf((i+1)*x),-0.5f+(y*j*2), (-0.5f+(y*j))*sinf((i+1)*x));

        }
    }
}

void Cone::drawNormals(){
    int i, j;
    float x, y;    
    x = PI * (2.0f / m_segmentsX);
    y = 0.5f / m_segmentsY;
    //sides
    for (i = 0; i < m_segmentsX; i++){
        //sides
        for (j = 0; j < m_segmentsY; j++){
            glVertex3f((0.5f-(y*(j)))*cosf(i*x), -0.5f+(y*(j)*2), (-0.5f+(y*(j)))*sinf(i*x));
            glVertex3f((0.6f-(y*(j)))*cosf(i*x), (-0.5f+(y*(j)*2))+0.05f, (-0.6f+(y*(j)))*sinf(i*x));
        }
        //bottom
        glVertex3f(0.5f*cosf(i*x), -0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf(i*x), -0.6f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.5f, 0.5f*sinf((i+1)*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.6f, 0.5f*sinf((i+1)*x));
    }
    //top
    glVertex3f(0.0f, 0.5f, 0.0f);
    glVertex3f(0.0f, 0.6f, 0.0f);
    //bottom
    glVertex3f(0.0f, -0.5f, 0.0f);
    glVertex3f(0.0f, -0.6f, 0.0f);
    
}
