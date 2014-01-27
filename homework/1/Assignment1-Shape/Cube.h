#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"

class Cube : public Shape {
public:
	Cube() {};
	~Cube() {};

	void draw() {
      glPushMatrix();
      glBegin(GL_TRIANGLES);
      int i,j,k;
      
      for(i=0; i<m_segmentsX; i++){
          for(j=0; j<m_segmentsY; j++){
              //front face (+z)
              glNormal3f(0.0f, 0.0f, 1.0f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              
              //back face (-z)
              glNormal3f(0.0f, 0.0f, -1.0f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              
              //right (+x) face
              glNormal3f(1.0f, 0.0f, 0.0f);
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //left (-x) face
              glNormal3f(-1.0f, 0.0f, 0.0f);
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //top (+y) face
              glNormal3f(0.0f, 1.0f, 0.0f);
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //bottom (-y) face
              glNormal3f(0.0f, -1.0f, 0.0f);
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
          }
      }
      
      glEnd();
      glPopMatrix();
	};


	void drawNormal() {
      glPushMatrix();
      glBegin(GL_TRIANGLES);
      int i,j,k;
      
      for(i=0; i<m_segmentsX; i++){
          for(j=0; j<m_segmentsY; j++){
              //front face (+z)
              glNormal3f(0.0f, 0.0f, 1.0f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), 0.5f);
              
              //back face (-z)
              glNormal3f(0.0f, 0.0f, -1.0f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              
              glVertex3f(-0.5f+i*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+j*(1.0f/m_segmentsY), -0.5f);
              glVertex3f(-0.5f+(i+1)*(1.0f/m_segmentsX), -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f);
              
              //right (+x) face
              glNormal3f(1.0f, 0.0f, 0.0f);
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //left (-x) face
              glNormal3f(-1.0f, 0.0f, 0.0f);
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f, -0.5f+j*(1.0f/m_segmentsY), -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //top (+y) face
              glNormal3f(0.0f, 1.0f, 0.0f);
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), 0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), 0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              //bottom (-y) face
              glNormal3f(0.0f, -1.0f, 0.0f);
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+(j+1)*(1.0f/m_segmentsY), -0.5f, -0.5f+i*(1.0f/m_segmentsX));
              glVertex3f(-0.5f+j*(1.0f/m_segmentsY), -0.5f, -0.5f+(i+1)*(1.0f/m_segmentsX));
          }
      }
      
      glEnd();
      glPopMatrix();
	};

private:

};

#endif
