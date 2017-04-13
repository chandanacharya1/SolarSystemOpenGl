#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
static int year=0,day=0;
static int key=-1;
static float r=0.0;
static float s=0.0;
struct Image 
{
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};
GLfloat lp[] = {.0,.0, 3.5, 1.0};
GLfloat lp1[] = {0.0,0.0,2.5,0.0};

//int d=1;
typedef struct Image Image;

GLfloat sun[]={1.0, 0.8, 0.0};
GLfloat mer[]={1.0, 0.6, 0.2};
GLfloat ven[]={1.0, 1.0, 0.6};
GLfloat ear[]={0.0, 0.6, 1.0};
GLfloat mar[]={0.8, 0.2, 0.0};
GLfloat jup[]={0.6, 0.2, 0.2};
GLfloat sat[]={1.0, 1.0, 0.6};
GLfloat ura[]={0.0, 0.8, 1.0};
GLfloat nep[]={0.4, 0.6, 1.0};
GLfloat sat1[]={0.6, 0.5, 0.3};
GLfloat bDiffuseMaterial[]={1.0,1.0,1.0};
char  str[]= {"SUN"};
char  str1[]= {"MERCURY"};
char  str2[]= {"VENUS"};
char  str3[]= {"EARTH"};
char  str4[]= {"MOON"};
char  str5[]= {"MARS"};
char  str6[]= {"JUPITOR"};
char  str7[]= {"SATURN"};
char  str8[]= {"URANUS"};
char  str9[]= {"NEPTUNE"}; 
 char strsun[]={"Diameter(km): 1.4 Million Km"};
char strsun1[]={"Rotation Period(In Earth Days): 25.4"};
char strsun2[]={"Mass: 330,000 x Earth's mass"};
char strsun3[]={"Density: 14 x density of water"};
char strsun4[]={"Average distance from Earth: 147 Million Km"};
char strsun5[]={"Surface temperature: 5500 degree celsius"};
char strsun6[]={"Core temperature: 15 Million degree celsius"};
char strsun7[]={"At the centre of the Solar System is the Sun, a vast globe of glowing gas"}; 
char strsun8[]={"that pours energy into space as light and heat"};
//char strsun8[]={" that pours energy into space as light and heat"};
char strmer[]={"Diameter(km): 4878 Km"};
char strmer1[]={"Mean Distance From Sun(AU): 0.39"};
char strmer2[]={"Rotation Period(In Earth Days): 58.65"};
char strmer3[]={"Orbital Period(In Earth Years): 0.24"};
char strmer4[]={"Mass: 0.06 x Earth's mass"};
char strmer5[]={"Surface gravity: 0.38 x Earth's gravity"};
char strmer6[]={"Surface temperature: 167 degree celcius"};
char strven[]={"Diameter(km): 12104 Km"};
char strven1[]={"Mean Distance From Sun(AU): 0.72"};
char strven2[]={"Rotation Period(In Earth Days): 243"};
char strven3[]={"Orbital Period(In Earth Years): 0.62"};
char strven4[]={"Mass: 0.82 x Earth's mass"};
char strven5[]={"Surface gravity: 0.9 x Earth's gravity"};
char strear[]={"Diameter(km): 12756"};
char strear1[]={"Mean Distance From Sun(AU): 1"};
char strear2[]={"Rotation Period(In Earth Days): 1"};
char strear3[]={"Orbital Period(In Earth Years): 1"};
char strear4[]={"Mass: 6000 x 10^18 tonnes"};
char strear5[]={"Surface temperature:-70 degree to +55 degree celsius"};
char strear6[]={"No. of moons: 1"};
char strmar[]={"Diameter(km): 6794 Km"};
char strmar1[]={"Mean Distance From Sun(AU): 1.52"};
char strmar2[]={"Rotation Period(In Earth Days): 1.03"};
char strmar3[]={"Orbital Period(In Earth Years): 1.88"};
char strmar4[]={"Mass: 0.11 x Earth's mass"};
char strmar5[]={"Surface gravity:0.38 x Earth's gravity"};
char strmar6[]={"Surface temperature: -63 degree celsius"};
char strjup[]={"Diameter(km): 142984 Km"};
char strjup1[]={"Mean Distance From Sun(AU): 5.2"};
char strjup2[]={"Rotation Period(In Earth Days): 0.41"};
char strjup3[]={"Orbital Period(In Earth Years): 11.86"};
char strjup4[]={"Mass: 318 x Earth's mass"};
char strjup5[]={"Surface gravity: 2.36 x Earth's gravity"};
char strjup6[]={"No. of moons: 61"};
char strjup7[]={" Four Prominent-GANYMEDE,CALLISTO,IO,EUROPA"};
char strsat[]={"Diameter(km): 120536 Km"};
char strsat1[]={"Mean Distance From Sun(AU): 9.54"};
char strsat2[]={"Rotation Period(In Earth Days): 0.44"};
char strsat3[]={"Orbital Period(In Earth Years): 29.46"};
char strsat4[]={"Mass: 95 x Earth's mass"};
char strsat5[]={"Surface gravity: 0.92 x Earth's gravity"};
char strsat6[]={"No. of moons: 31; One Prominent- TITAN"};
char strura[]={"Diameter(km): 51118 Km"};
char strura1[]={"Mean Distance From Sun(AU): 19.18"};
char strura2[]={"Rotation Period(In Earth Days): 0.72"};
char strura3[]={"Orbital Period(In Earth Years): 84.01"};
char strura4[]={"Mass: 14.5 x Earth's mass"};
char strura5[]={"Surface gravity: 0.89 x Earth's gravity"};
char strnep[]={"Diameter(km): 49528"};
char strnep1[]={"Mean Distance From Sun(AU): 30.06"};
char strnep2[]={"Rotation Period(In Earth Days): 0.72"};
char strnep3[]={"Orbital Period(In Earth Years): 164.8"};
char strnep4[]={"Mass: 17.2 x Earth's mass"};
char strnep5[]={"Surface gravity: 1.13 x Earth's gravity"};
char strnep6[]={"No. of moons: 11;One Prominent-TRIRON"};
void choose(int i);
void display();
void display1();
void star()					//draw stars
{
	glPushMatrix();	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		
 
	glPushMatrix();						
    	glTranslatef(5,-5,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
              glTranslatef(3,-7,0);	
              glColor3f( 0.2, 0.2, 1.0 );
              glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, bDiffuseMaterial);
              glutSolidSphere( 0.02, 50, 50);
              glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(8,3,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
  
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

        glPushMatrix();						
    	glTranslatef(8,6,0);	
    	glColor3f( 1.0, 1.0, 1.0 );
  
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();	

	glPushMatrix();						
    	glTranslatef(8,-2,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
   
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-8,-1,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-7,2,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
   	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-7,-1,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
   	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-5,-4,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
   	 glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-5,4,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-5,7,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-4,9,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(-4,6,5);	
    	glColor3f( 0.2, 0.2, 1.0 );
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
   	glTranslatef(-3,7,-5);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
   	glTranslatef(-3,2,-1);	
    	glColor3f( 0.2, 0.2, 1.0 );
   	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(3,7,-1);	
    	glColor3f( 0.2, 0.2, 1.0 );
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(4,9,-5);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(3,6,-9);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
   	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(4,7,-9);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(0,5,7);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(1,3,-9);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(5,5,-5);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
   	glTranslatef(3,-4,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
    	glutSolidSphere( 0.02, 50, 50);
    	glPopMatrix();		

	glPushMatrix();						
    	glTranslatef(5,3,0);	
    	glColor3f( 0.2, 0.2, 1.0 );
    	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,bDiffuseMaterial);
  	glutSolidSphere( 0.02, 50, 50);
  	glPopMatrix();
}	
void stringdisplay(float a,float c,char *A) 
{
	int j;
	int len=0;
	glDisable (GL_LIGHTING);
	glColor3f(1,1,1);
	len=strlen(A)-1;
	glRasterPos2f(a,c);
	glColor3f(1,1,1);
	 for(j=0;j<=len;j++)
	{
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)A[j]);
	}
              glEnable (GL_LIGHTING);
              glEnable (GL_LIGHT0);
}
void stringdisplay1(float a,float c,char *A) 
{
	int j;
	int len=0;
	glDisable (GL_LIGHTING);
	glColor3f(1,1,1);
	len=strlen(A)-1;
	glRasterPos2f(a,c);
	glColor3f(1,1,1);
	 for(j=0;j<=len;j++)
	{
        		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,(int)A[j]);
	}
       	glEnable (GL_LIGHTING);
       	glEnable (GL_LIGHT0);
}
void display_screen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef ( 0.5, 0.5, -8.0 );
	glDisable (GL_LIGHTING);
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-4.10,5.4,"J S S ACADEMY OF TECHNICAL EDUCATION");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-9.37,2.17," ");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-7.41,1.67,"PROJECT ON:");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-7.41,0.47," SIMULATION OF SOLAR SYSTEM ");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(1.37,-1.67,"PRESENTED BY:");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(1.37,-2.67,"BHARATH KUMAR G");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(1.37,-3.4,"CHANDAN" );
	
        glColor3f(0.7529,1.0,0.2509);
        stringdisplay1(-10,-1.67,"UNDER THE GUIDANCE:");
         glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-10,-2.67,"PROF.SHARAN GOUDA");
	glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-10,-3.4,"PROF.KV SHANTHALA");
        glColor3f(0.7529,1.0,0.2509);
	stringdisplay1(-2.37,-5.0,"PRESS 'E' TO START");
	star();
	glPopMatrix();
	glutSwapBuffers();


}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glutCreateMenu(choose);
glutAddMenuEntry("Sun",0);
glutAddMenuEntry("Mercury",1);
glutAddMenuEntry("Venus",2);
glutAddMenuEntry("Earth",3);
glutAddMenuEntry("Mars",4);
glutAddMenuEntry("Jupiter",5);
glutAddMenuEntry("Saturn",6);
glutAddMenuEntry("Uranus",7);
glutAddMenuEntry("Neptune",8);
glutAddMenuEntry("Exit",9);
glutAttachMenu(GLUT_RIGHT_BUTTON);
star();
glRotatef(r,1.0,0.0,0.0);
glRotatef(s,0.0,1.0,0.0);
glColor3f(1.0,1.0,1.0);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glLightfv(GL_LIGHT0, GL_POSITION,lp);
glRotatef(year,0.0,1.0,0.0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,sun);
glutSolidSphere(0.99,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);

/****************************************************/
glPushMatrix();
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glTranslatef(1.82,0.0,-1.82);
glColor3f(0.0,1.0,0.5);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mer);
glutSolidSphere(0.21,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glPopMatrix();
/************************************************/
glPushMatrix();
glTranslatef(-2.3,0.0,2.30);
glColor3f(1.0,0.0,0.5);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ven);
glutSolidSphere(0.33,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glPopMatrix();
/*********************************************/
glPushMatrix();
glTranslatef(3.03,0.0,3.03);
glRotatef(360.0*12.0*day/365.0,0.0,1.0,0.0);
glColor3f(0.0,0.0,1.0);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ear);

glutSolidSphere(0.37,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glPushMatrix();
glTranslatef(0.6,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glutSolidSphere(0.1,100,100);
glPopMatrix();
glPopMatrix();
/****************************************************/
glPushMatrix();
glTranslatef(-3.650,0.0,3.650);
glColor3f(0.0,1.0,1.0);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mar);
glutSolidSphere(0.25,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);

glPopMatrix();
/******************************************************/
glPushMatrix();
glTranslatef(5.09,0.0,-5.09);
glRotatef(day*2,0.75,0.0,0.0);
glColor3f(1.0,0.0,0.5);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,jup);
glutSolidSphere(0.52,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);

 glPushMatrix();
 glRotatef(3*day, 0, 0, 1);
  glPushMatrix();
 glTranslatef(0, 1, 0);
 glColor3f(0.6, 0.5, 0.3);
 glutSolidSphere( 0.13, 100, 100);
 glPopMatrix(); 

 glPushMatrix();
 glTranslatef(0, -1, 0);
 glColor3f(0.4, 0.5, 0.8);
 glutSolidSphere( .05, 100, 100);
 glPopMatrix();
 glPopMatrix();

glRotatef(360*day/(365), 0, 1, 0);
  glPushMatrix();
 glTranslatef(0, 0, 1);
 glColor3f(.4, 0.4, 0.4);
 glutSolidSphere( .08, 100, 100);

 glPopMatrix(); 

 glPushMatrix();
 glTranslatef(0, 0, -1);
 glColor3f(1.0, 0.5, 0.3);
 glutSolidSphere( .03, 100, 100);
 glPopMatrix();
 glPopMatrix();

glPopMatrix();
/***********************************************************/
glPushMatrix();
glTranslatef(-5.35,0.0,-5.35);
glColor3f(1.0,0.625,0.5);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,sat);
glutSolidSphere(0.47,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glRotatef(4*day, 0, 1, 0);
glPushMatrix();
glTranslatef(0.6,0.0,1.0);
glColor3f(1.0,0.4,0.0);
glutSolidSphere(0.08,100,100);
glPopMatrix();
int i = 0;
 glBegin(GL_LINE_STRIP);
 //glBegin(GL_QUAD_STRIP);
 for(i=0; i <= 360; i++)
 {glColor3f(1.0,0.625,0.5);
  glVertex3f(sin(i*3.1416/180)*0.5,0, cos(i*3.1416/180)*0.5);
  glVertex3f(sin(i*3.1416/180)*0.7,0, cos(i*3.1416/180)*0.7);
 }
 glEnd();
glPopMatrix();
/***********************************************************/
glPushMatrix();
glTranslatef(5.74,0.0,5.74);
glColor3f(1.0,0.655,0.5);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ura);
glutSolidSphere(0.51,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);
glPopMatrix();
/****************************************************************/
glPushMatrix();
glTranslatef(-6.33,0.0,6.33);
glColor3f(1.0,0.655,0.5);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,nep);
glutSolidSphere(0.41,100,100);
glDisable(GL_LIGHTING);
glDisable(GL_LIGHT0);

glPopMatrix();
/********************************************************************/

glFlush();
glutSwapBuffers();
}

void reshape(int w,int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity();
if(w<=h)
	glOrtho(-7.0,7.0,-7.0*(GLfloat)h/(GLfloat)w,7.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
else
	glOrtho(-7.0*(GLfloat)w/(GLfloat)h,7.0*(GLfloat)w/(GLfloat)h,-7.0,7.0,-10.0,10.0);
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}

void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glShadeModel(GL_FLAT);
}
GLuint texture;


void back(int i)
{
	
	switch(i)
	{
		case 0:key=-10;
			glutDisplayFunc(display);
			break;
		case 1:key=1;
		       glutDisplayFunc(display1);
		       break;
		case 2:key=2;
		       glutDisplayFunc(display1);
		       break;
		case 3:key=3;
		       glutDisplayFunc(display1);
		       break;
		case 4:key=4;
		       glutDisplayFunc(display1);
		       break;
		case 5:key=5;
		       glutDisplayFunc(display1);
		       break;
		case 6:key=6;
		       glutDisplayFunc(display1);
		       break;
		case 7:key=7;
		       glutDisplayFunc(display1);
		       break;
		case 8:key=8;
		       glutDisplayFunc(display1);
		       break;
		case 9:key=9;
		       glutDisplayFunc(display1);
		       break;
               case 10:key=10;
                        glutDisplayFunc(display1);
		       break;
                      
	}
}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glutCreateMenu(back);
	glutAddMenuEntry("Solar System",0);
	glutAddMenuEntry("Sun",1);
	glutAddMenuEntry("Mercury",2);
	glutAddMenuEntry("Venus",3);
	glutAddMenuEntry("Earth",4);
	glutAddMenuEntry("Mars",5);
	glutAddMenuEntry("Jupiter",6);
	glutAddMenuEntry("Saturn",7);
	glutAddMenuEntry("Uranus",8);
	glutAddMenuEntry("Neptune",9);
        glutAddMenuEntry("Exit",10);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	stringdisplay1(-6.0,-4.5,"press 'n' for next planet");
        stringdisplay1(-6.0,-5.5,"press 'p' for previous planet");
  //star();
//creating sun
	if(key==1)
	{	
         glClearColor(0.0,0.0,0.0,0.0);
	glPushMatrix();
	glLoadIdentity();
        glColor3f(1.0,0.0,0.0);
	stringdisplay1(0.0,5.5,str);
	stringdisplay(-1.0,2.5,strsun);
	stringdisplay(-1.0,1.5,strsun1);
        stringdisplay(-1.0,0.5,strsun2);
        stringdisplay(-1.0,-0.5,strsun3);
	stringdisplay(-1.0,-1.5,strsun4);
        stringdisplay(-1.0,-2.5,strsun5);
        stringdisplay(-1.0,-3.5,strsun6);
	stringdisplay(-11.5,4.5,strsun7);
        stringdisplay(-1.5,3.5,strsun8);
       // stringdisplay(-7.5,4.0,strsun8);
	glPopMatrix();
	glPushMatrix();
	glLoadIdentity();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,sun);
	glTranslatef(-8.5,0.0,-5.0);
        glColor3f(1.0,0.0,0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
         	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	
	
	//glRotatef((GLfloat)year,0.0,1.0,0.0);
         glColor3f(1.0,0.0,0.0);
	glutSolidSphere(3.5,100,100);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glPopMatrix();
	}

//creating mercury	
	if(key==2)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str1);
	stringdisplay(-1.0,3.5,strmer);
	stringdisplay(-1.0,2.5,strmer1);
	stringdisplay(-1.0,1.5,strmer2);
	stringdisplay(-1.0,0.5,strmer3);
	stringdisplay(-1.0,-0.5,strmer4);
	stringdisplay(-1.0,-1.5,strmer5);
	stringdisplay(-1.0,-2.5,strmer6);
	glPopMatrix();
    
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mer);
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	glColor3f(1.0,1.,1.0);
	
	glutSolidSphere(2.2,100,100);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	}

//creating venus
	if(key==3)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str2);
	stringdisplay(-1.0,3.5,strven);
	stringdisplay(-1.0,2.5,strven1);
	stringdisplay(-1.0,1.5,strven2);
	stringdisplay(-1.0,0.5,strven3);
	stringdisplay(-1.0,-0.5,strven4);
	stringdisplay(-1.0,-1.5,strven5);
	glPopMatrix();
      
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ven);	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);	
	glColor3f(.0,.0,1.0);
	
	glutSolidSphere(2.5,100,100);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	}
//creating earth
	if(key==4)
	{		
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str3);
	stringdisplay(-1.0,3.5,strear);
	stringdisplay(-1.0,2.5,strear1);
	stringdisplay(-1.0,1.5,strear2);
	stringdisplay(-1.0,0.5,strear3);
	stringdisplay(-1.0,-0.5,strear4);
	stringdisplay(-1.0,-1.5,strear5);
	stringdisplay(-1.0,-2.5,strear6);
	
        glPopMatrix();
      
	glPushMatrix();
	glLoadIdentity();
	
	glTranslatef(-8.5,0.0,-5.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ear);	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);	
	glColor3f(1.0,1.0,1.0);
	glRotatef(360.0*day/365.0,0.0,1.0,0.0);
	
	
	
	glutSolidSphere(2.8,100,100);
	glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glPushMatrix();
	glTranslatef(4,0.0,0.0);
	glColor3f(1.0,1.0,1.0);	
	glutSolidSphere(.4,100,100);
	glPopMatrix();
	
	
	
	glPopMatrix();
	}

//creating mars
	if(key==5)
	{
		
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str5);
	stringdisplay(-1.0,3.5,strmar);
	stringdisplay(-1.0,2.5,strmar1);
	stringdisplay(-1.0,1.5,strmar2);
	stringdisplay(-1.0,0.5,strmar3);
	stringdisplay(-1.0,-0.5,strmar4);
	stringdisplay(-1.0,-1.5,strmar5);
	stringdisplay(-1.0,-2.5,strmar6);
	glPopMatrix();
    
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,mar);	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	glColor3f(1.0,.5,.0);
	
	glutSolidSphere(2.3,100,100);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	}
//creating jupiter
	if(key==6)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str6);
	stringdisplay(-1.0,3.5,strjup);
	stringdisplay(-1.0,2.5,strjup1);
	stringdisplay(-1.0,1.5,strjup2);
	stringdisplay(-1.0,0.5,strjup3);
	stringdisplay(-1.0,-0.5,strjup4);
	stringdisplay(-1.0,-1.5,strjup5);
	stringdisplay(-1.0,-2.5,strjup6);
	stringdisplay(-1.0,-3.5,strjup7);
	glPopMatrix();
      //  LoadGLTextures("jupiter.bmp");
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,jup);
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);	
	glColor3f(1.0,1.0,.0);
	
	glutSolidSphere(3.0,100,100);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	 glPushMatrix();
 glRotatef(3*day, 0, 0, 1);
  glPushMatrix();
 glTranslatef(4.2, 1, 0);
 glColor3f(0.6, 0.5, 0.3);
 glutSolidSphere( .5, 100, 100);
 glPopMatrix(); 

 glPushMatrix();
 glTranslatef(-3.8, -1, 0);
 glColor3f(0.4, 0.5, 0.8);
 glutSolidSphere( .38, 100, 100);
 glPopMatrix();
 glPopMatrix();

glRotatef(360*day/(365), 0, 1, 0);
  glPushMatrix();
 glTranslatef(3.6, 0, 1);
 glColor3f(.4, 0.4, 0.4);
 glutSolidSphere( .25, 100, 100);

 glPopMatrix(); 

 glPushMatrix();
 glTranslatef(-3.5, 0, -1);
 glColor3f(1.0, 0.5, 0.3);
 glutSolidSphere( .15, 100, 100);
 glPopMatrix();
 glPopMatrix();


	glPopMatrix();
	}
//creating of satrun
	if(key==7)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str7);
	stringdisplay(-1.0,3.5,strsat);
	stringdisplay(-1.0,2.5,strsat1);
	stringdisplay(-1.0,1.5,strsat2);
	stringdisplay(-1.0,0.5,strsat3);
	stringdisplay(-1.0,-0.5,strsat4);
	stringdisplay(-1.0,-1.5,strsat5);
	stringdisplay(-1.0,-2.5,strsat6);
	glPopMatrix();
        //LoadGLTextures("saturn.bmp");
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);	
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,sat);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	glColor3f(1.0,0.6,0.8);
       
	glRotatef((GLfloat)day,0.0,1.0,1.0);
	glutSolidSphere(2.8,100,100);
	 //glutSolidTorus(0.50,3.5,16,32);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	
        glPushMatrix();
	glTranslatef(3.8,1.0,0.5);
	glColor3f(0.8,0.4,0.2);	
	glutSolidSphere(.3,100,100);
	glPopMatrix();
	
        int i = 0;
           // glBegin(GL_LINE_STRIP);
	glRotatef((GLfloat)year,0.0,1.0,0.5);

           glBegin(GL_QUAD_STRIP);
            glColor3f(0.7, 0.6, 0.4);  
            for(i=0; i <= 360; i++)
              {
              glVertex3f(sin(i*3.1416/180)*2.9,0.0, cos(i*3.1416/180)*2.9);
              glVertex3f(sin(i*3.1416/180)*3.3,0, cos(i*3.1416/180)*3.3);
	    }

	glColor3f(0.6,0.4,0.2);
            for(i=0; i <= 360; i++)
		 {  glVertex3f(sin(i*3.1416/180)*3.35,0.0, cos(i*3.1416/180)*3.35);
              glVertex3f(sin(i*3.1416/180)*3.7,0, cos(i*3.1416/180)*3.7);
		}
		
glEnd();

	glPopMatrix();
	}
//creating of uranus
	if(key==8)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str8);
	stringdisplay(-1.0,3.5,strura);
	stringdisplay(-1.0,2.5,strura1);
	stringdisplay(-1.0,1.5,strura2);
	stringdisplay(-1.0,0.5,strura3);
	stringdisplay(-1.0,-0.5,strura4);
	stringdisplay(-1.0,-1.5,strura5);
	glPopMatrix();
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
         glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,ura);
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	glColor3f(1.0,1.0,.5);
        glutSolidSphere(2.6,100,100);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	}
//creating of neptune
	if(key==9)
	{
	
	glPushMatrix();
	glLoadIdentity();
	stringdisplay1(0.0,5.5,str9);
	stringdisplay(-1.0,3.5,strnep);
	stringdisplay(-1.0,2.5,strnep1);
	stringdisplay(-1.0,1.5,strnep2);
	stringdisplay(-1.0,0.5,strnep3);
	stringdisplay(-1.0,-0.5,strnep4);
	stringdisplay(-1.0,-1.5,strnep5);
	stringdisplay(-1.0,-2.5,strnep6);
	glPopMatrix();
        glPushMatrix();
	glLoadIdentity();
	glTranslatef(-8.5,0.0,-5.0);	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,nep);
	glLightfv(GL_LIGHT0, GL_POSITION,lp1);
	glColor3f(1.0,.5,.5);
	glutSolidSphere(2.4,100,100);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	}
        if (key==10)
	{
         exit(0);
        }
	
	
	glFlush();
	glutSwapBuffers();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
		key++;
	glutPostRedisplay();
}
void spin1()
{
	year+=1.0;
	if(year>360)
		year=0.0;
	day+=2.0;
	if(day>360)
		day=0.0;
	glutPostRedisplay();
}
void choose(int x)
{
	
	switch(x)
	{
		case 0:key=1;
		break;
		case 1:key=2;
		break;
		case 2:key=3;
		break;
		case 3:key=4;
		break;
		case 4:key=5;
		break;
		case 5:key=6;
		break;
		case 6:key=7;
		break;
		case 7:key=8;
		break;
		case 8:key=9;
		break;	
               case 9:key=10;
		break;
	}

	
glutDisplayFunc(display1);
}

void start()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0,1.0,1.0,0.0);
	glutCreateMenu(choose);
	glutAddMenuEntry("solar system",1);
	glutAddMenuEntry("individual planets",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glFlush();
}
void myKey(unsigned char key1,int x,int y)
{
	if(key1=='w')
		r=r+0.5;
	if(key1=='s')
		r=r-0.5;
	if(key1=='a')
		s=s+0.5;
	if(key1=='d')
		s=s-0.5;
	if(key1=='E' || key1=='e')
		glutDisplayFunc(display);
	if(key1=='n')
	{
		key++;
		if(key==10)
			key=1;
	}
 	if (key1=='q'|| key1=='Q')
            exit(0);
	if(key1=='p')
	{
		key--;
		if(key==0)
			key=9;
	}
	glutPostRedisplay();
		
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(1200,650);
glutInitWindowPosition(0,0);
glutCreateWindow("solar system");
glutDisplayFunc(display_screen);
glutIdleFunc(spin1);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutKeyboardFunc(myKey);
init();
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
