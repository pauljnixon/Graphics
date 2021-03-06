#include "Cylinder.h"
#include <iostream>
#include <math.h> 
using namespace std;
double Cylinder::Intersect(Point eyeP, Vector rayV, Matrix worldToObj){
    double a, b, c, det, t1, t2, x, y1, y2, z;
    double t = 1000000;
    //Matrix worldToObj = invert(transformMatrix);
    Point p = worldToObj * eyeP;
    Vector d = worldToObj * rayV;
    /*
    if ((p[0] == d[0]) && (p[2] == d[2])){
        if (p[1] * p[1] < 0.25){
            return -1; 
        }
        det = p[0] * p[0] + p[2] * p[2];
        if (det < 0.25) { 
            if (p[1] < 0.0){
                return (p[1] + 0.5) / d[1];
            }
            return (p[1] - 0.5) / d[1];
        }
    }*/
    a = d[0] * d[0] + d[2] * d[2];
    b = 2.0 *p[0] * d[0] + 2.0 * p[2] * d[2];
    c = p[0] * p[0] + p[2] * p[2] - 0.25;
    det = b * b - 4 * a * c;    
//    cout << det << "\n"; 
    /*
    if (det < 0.0) {
        return -1.0;
    } */
    if(det > 0.0){
        t1 = (- b - sqrt(det)) / (2 * a);
        t2 = (- b + sqrt(det)) / (2 * a);
        y1 = p[1] + t1 * d[1];
        y2 = p[1] + t2 * d[1];
        if(t1 > 0.0 && y1 > -0.5 && y1 < 0.5){
            t = t1;
        }
        if(t2 > 0.0 && y2 > -0.5 && y2 < 0.5 && t2 < t1){
            t = t2;
        }
    }
    /*
    if (t1 < 0.0) {
        if (t2 < 0.0) { 
            return -1; 
        }
        return t2;
    }
    if (t2 < 0.0) { 
        return t1; 
    }*/
    //find intersection with caps
    
    t1 = (0.5 - p[1]) / d[1];
    x = p[0] + t1 * d[0];
    z = p[2] + t1 * d[2];
    if(x > -0.5 && x*x + z*z < 0.25 && t1 < t){
        t = t1;
    }

    t1 = (-0.5 - p[1]) / d[1];
    x = p[0] + t1 * d[0];
    z = p[2] + t1 * d[2];
    if(x > -0.5 && x*x + z*z < 0.25 && t1 < t){
        t = t1;
    }

    if(t == 1000000)return -1;
    return t;
}
Vector Cylinder::findIsectNormal(Point eyePoint, Vector ray, double dist){
    Point hit = eyePoint + (ray * dist);
    //caps
    float fudgeFactor = 0.000005;
    if(fabs(hit[1] + 0.5) < fudgeFactor)return Vector(0.0, -1.0, 0.0);
    if(fabs(hit[1] - 0.5) < fudgeFactor)return Vector(0.0, 1.0, 0.0);
    //tube
    Vector ret(hit[0], 0.0, hit[2]);
    ret.normalize();
    return ret; 
}

Point Cylinder::iPointToSquare(Point i, Vector ray, double dist){
    
    Point hit = i + (ray * dist);
    float fudgeFactor = 0.000005;

    if(fabs(hit[1] + 0.5) < fudgeFactor) 
        return Point(hit[0] + 0.5, hit[2] + 0.5, 0.0);
    if(fabs(hit[1] - 0.5) < fudgeFactor)
        return Point(hit[0] + 0.5, hit[2] + 0.5, 0.0);
    
    Point coords;

    coords[0] = -atan2(hit[2], hit[0]) / (2*PI) + 0.5;
    coords[1] = -hit[1] + 0.5;
    coords[2] = 0.0;

    return coords;
}

void Cylinder::drawTriangles(){
    int i,j;
    float x, y;
    x = PI * (2.0f / m_segmentsX);
    y = 1.0f / m_segmentsY;

    for(i=0; i<m_segmentsX; i++){
        //top
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(0.5f*cosf(i*x), 0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), 0.5f, 0.5f*sinf((i+1)*x));
          
        //bottom
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(0.0f, -0.5f, 0.0f);
        glVertex3f(0.5f*cosf(i*x), -0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.5f, 0.5f*sinf((i+1)*x));
          
        for(j=0; j<m_segmentsY; j++){
            //sides
            glNormal3f(cosf((i+0.5f)*x), 0.0f, sinf((i+0.5f)*x));
            glVertex3f(0.5f*cosf(i*x), -0.5f+j*y, 0.5f*sinf(i*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+j*y, 0.5f*sinf((i+1)*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.5f*sinf((i+1)*x));
              
            glVertex3f(0.5f*cosf(i*x), -0.5f+(j+1)*y, 0.5f*sinf(i*x));
            glVertex3f(0.5f*cosf(i*x), -0.5f+j*y, 0.5f*sinf(i*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.5f*sinf((i+1)*x));
        }
    }
};

void Cylinder::drawNormals(){
    int i,j;
    float x,y;
    x =PI * (2.0f / m_segmentsX);
    y = 1.0f / m_segmentsY;

    for(i=0; i<m_segmentsX; i++){
        //top
        glVertex3f(0.0f, 0.5f, 0.0f);
        glVertex3f(0.0f, 0.6f, 0.0f);
        glVertex3f(0.5f*cosf(i*x), 0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf(i*x), 0.6f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), 0.5f, 0.5f*sinf((i+1)*x));
        glVertex3f(0.5f*cosf((i+1)*x), 0.6f, 0.5f*sinf((i+1)*x));
          
        //bottom
        glVertex3f(0.0f, -0.5f, 0.0f);
        glVertex3f(0.0f, -0.6f, 0.0f);
        glVertex3f(0.5f*cosf(i*x), -0.5f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf(i*x), -0.6f, 0.5f*sinf(i*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.5f, 0.5f*sinf((i+1)*x));
        glVertex3f(0.5f*cosf((i+1)*x), -0.6f, 0.5f*sinf((i+1)*x));
          
        for(j=0; j<m_segmentsY; j++){
            //sides
            glVertex3f(0.5f*cosf(i*x), -0.5f+j*y, 0.5f*sinf(i*x));
            glVertex3f(0.6f*cosf(i*x), -0.5f+j*y, 0.6f*sinf(i*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+j*y, 0.5f*sinf((i+1)*x));
            glVertex3f(0.6f*cosf((i+1)*x), -0.5f+j*y, 0.6f*sinf((i+1)*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.5f*sinf((i+1)*x));
            glVertex3f(0.6f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.6f*sinf((i+1)*x));
              
            glVertex3f(0.5f*cosf(i*x), -0.5f+(j+1)*y, 0.5f*sinf(i*x));
            glVertex3f(0.6f*cosf(i*x), -0.5f+(j+1)*y, 0.6f*sinf(i*x));
            glVertex3f(0.5f*cosf(i*x), -0.5f+j*y, 0.5f*sinf(i*x));
            glVertex3f(0.6f*cosf(i*x), -0.5f+j*y, 0.6f*sinf(i*x));
            glVertex3f(0.5f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.5f*sinf((i+1)*x));
            glVertex3f(0.6f*cosf((i+1)*x), -0.5f+(j+1)*y, 0.6f*sinf((i+1)*x));
          }
      }
};
