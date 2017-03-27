////////////////////////////////////////////////////////////////////////////////
// DESCRIPTION
//       Get SRT Copyright 
//       Contributors: SRT Team
//       Author: Alessio Trois (OA Cagliari)
//		
//
// INPUT
//       srt fits 
//
// OUTPUT
//       output filename
//
//
// FILE HISTORY
//                      Authors:        Alessio Trois (OA Cagliari)
//                             		
// NOTICE
//       Any information contained in this software
//       is property of the SRT TEAM and is strictly
//       private and confidential.
//       All rights reserved.
////////////////////////////////////////////////////////////////////////////////////


#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include "fitsio.h"
#include <unistd.h>
#include <ctype.h>
#include <cstring>
#include <pil.h>
#include <iostream>

#ifdef PI
#undef PI
#endif
#define PI 3.141592653589793238462643
#define TWO_PI 6.283185307179586477
#define DEG2RAD 0.017453292519943295769
#define RAD2DEG 57.295779513082320877
#define EARTH_RADIUS 6378.140
#define MOON_RADIUS 1738.
#define EARTH_E2 .0066934216
#define AU 149597870.
#define EPS 1.e-12
#define MJD_B1950 33281.923
#define MJD_J2000 51544.500
const double tspace = 0.1;

using namespace std;
const char * version = "version 0.0 27/03/2017";

