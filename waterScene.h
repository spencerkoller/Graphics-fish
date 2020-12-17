#ifndef waterScene_h
#define waterScene_h

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#ifdef USEGLEW
#include <GL/glew.h>
#endif
#ifdef __WINDOWS__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define Cos(th) cos(3.1415926/180*(th))
#define Sin(th) sin(3.1415926/180*(th))
extern int texture[5];
extern int fishvalue;
extern double zh;
extern void fishy1(double x,double y,double z,
                      double dx,double dy,double dz,
                      double ux,double uy, double uz,
                      double fl, double fw, double fh,
                      
                      int tex, int face, int f);
extern void Vertex(double th,double ph);
extern void fishVertex(double x, double y, double z, double sscale);
#endif