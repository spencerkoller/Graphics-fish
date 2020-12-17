#include "waterScene.h"



void fishVertex(double x, double y, double z, double sscale)  
{
    glTexCoord2d(-x*sscale+.4,y*sscale+.5);
    glNormal3d(x,y,z);
    glVertex3d(x,y,z);
}

void fishy1(double x,double y,double z,
                      double dx,double dy,double dz,
                      double ux,double uy, double uz,
                      double fl, double fw, double fh,
                      int tex, int face, int frot)
{
  //  Unit vector in direction of swim
  double D0 = sqrt(dx*dx+dy*dy+dz*dz);
  double X0 = dx/D0;
  double Y0 = dy/D0;
  double Z0 = dz/D0;
  //  Unit vector in "up" direction
  double D1 = sqrt(ux*ux+uy*uy+uz*uz);
  double X1 = ux/D1;
  double Y1 = uy/D1;
  double Z1 = uz/D1;
  //  Cross product gives the third vector
  double X2 = Y0*Z1-Y1*Z0;
  double Y2 = Z0*X1-Z1*X0;
  double Z2 = X0*Y1-X1*Y0;
  //  Rotation matrix
  double mat[16];
  mat[0] = X0;    mat[4] = X1;    mat[ 8] = X2;   mat[12] = 0;
  mat[1] = Y0;    mat[5] = Y1;    mat[ 9] = Y2;   mat[13] = 0;
  mat[2] = Z0;    mat[6] = Z1;    mat[10] = Z2;   mat[14] = 0;
  mat[3] =  0;    mat[7] =  0;    mat[11] =  0;   mat[15] = 1;

  //  Save current transforms
  glPushMatrix();
  glTranslated(x,y,z);
  glMultMatrixd(mat);
  if (fw>fh)
    glRotated(-(zh-30),0,1,0);
  double p = -fl/2;
  double px = fl/30;
  double x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;

  for (double i = 0; i<=27; i++) {
    glBegin(GL_QUADS);
    x1 = p;
    y1 = sin((fl/2-p)*3.14/fl)*fh;
    z1 = 0;
    x2 = p;
    y2 = 0;
    z2 = sin((fl/2-p)*3.14/fl)*fw;
    x3 = p+px;
    y3 = 0;
    z3 = sin((fl/2-(p+px))*3.14/fl)*fw;
    x4 = p+px;
    y4 = sin((fl/2-(p+px))*3.14/fl)*fh;
    z4 = 0;   
    fishVertex(x1, y1, z1, 1.0);
    fishVertex(x2, y2, z2, 1.0);
    fishVertex(x3, y3, z3, 1.0);
    fishVertex(x4, y4, z4, 1.0);
    fishVertex(x2, y2, z2, 1.0);
    fishVertex(x1,-y1, z1, 1.0);
    fishVertex(x4,-y4, z4, 1.0);
    fishVertex(x3, y3, z3, 1.0);
    fishVertex(x1, y1, z1, 1.0);
    fishVertex(x2, y2,-z2, 1.0);
    fishVertex(x3, y3,-z3, 1.0);
    fishVertex(x4, y4, z4, 1.0);
    fishVertex(x2, y2,-z2, 1.0);
    fishVertex(x1,-y1, z1, 1.0);
    fishVertex(x4,-y4, z4, 1.0);
    fishVertex(x3, y3,-z3, 1.0);
    glEnd();
    p += px;
  }


  double ydelta, zdelta;
  glDisable(GL_TEXTURE_2D);
  glBegin(GL_POLYGON);
  if (fw<fh){
    zdelta = Sin(9*zh)*fw;
    ydelta = 0;
  }
  else{
    zdelta = 0;
    ydelta = Sin(9*zh)*fh;
  }
  glNormal3f(0, 0, 1) ;
  glTexCoord2f(0, 0.0);  glVertex3d(-fl/2,  0, .001); 
  glTexCoord2f(.3, .7);  glVertex3d(-fl/2-fl*.3, fh*.7+ydelta, .001+zdelta); 
  glTexCoord2f(.15, .7);  glVertex3d(-fl/2-fl*.15, 0, .001+zdelta/2); 
  glTexCoord2f(.3, .7);  glVertex3d(-fl/2-fl*.3, -fh*.7+ydelta, .001+zdelta); 
  glTexCoord2f(0, 0.0);  glVertex3d(-fl/2,  0, .001); 
  glEnd();
  glBegin(GL_POLYGON);
  glNormal3f(0, 0, -1);
  glTexCoord2f(0,0);      glVertex3d(-fl/2, 0.0, -.001); 
  glTexCoord2f(.3, .7);   glVertex3d(-fl/2-fl*.3, fh*.7+ydelta, -.001+zdelta); 
  glTexCoord2f(.15, .7);  glVertex3d(-fl/2-fl*.15, 0, -.001+zdelta/2); 
  glTexCoord2f(.3, .7);   glVertex3d(-fl/2-fl*.3, -fh*.7+ydelta,-.001+zdelta); 
  glTexCoord2f(0,0);      glVertex3d(-fl/2, 0.0, -.001); 
  glEnd();  
  glBegin(GL_QUADS);
  glNormal3f(0, 0, 1) ;
  glVertex3d(-fl/2+.75*fl, sin(.75*fl*3.14/fl)*fh, .001);
  glVertex3d(-fl/2+.6*fl,  sin(.6*fl*3.14/fl)*fh+(fh*.55), .001);
  glVertex3d(-fl/2+.4*fl,  sin(.4*fl*3.14/fl)*fh+(fh*.30), .001);
  glVertex3d(-fl/2+.25*fl, sin(.25*fl*3.14/fl)*fh, .001);
  glNormal3f(0, 0, -1) ;
  glVertex3d(-fl/2+.75*fl, sin(.75*fl*3.14/fl)*fh, -.001);
  glVertex3d(-fl/2+.6*fl, sin(.6*fl*3.14/fl)*fh+(fh*.55), -.001);
  glVertex3d(-fl/2+.4*fl, sin(.4*fl*3.14/fl)*fh+(fh*.30), -.001);
  glVertex3d(-fl/2+.25*fl, sin(.25*fl*3.14/fl)*fh, -.001);
  glEnd();
  glPopMatrix();
}