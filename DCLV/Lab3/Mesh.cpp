#include "stdafx.h"
#include "Mesh.h"
#include <math.h>

#define PI			3.1415926
#define	COLORNUM		20


float	ColorArr[COLORNUM][3] = { {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, { 0.0,  0.0, 1.0},
								{1.0, 1.0,  0.0}, { 1.0, 0.0, 1.0},{ 0.0, 1.0, 1.0},
								 {0.3, 0.3, 0.3}, {0.5, 0.5, 0.5}, { 0.9,  0.9, 0.9},
								{1.0, 0.5,  0.5}, { 0.5, 1.0, 0.5},{ 0.5, 0.5, 1.0},
									{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {0.72, 0.11, 0.11}, {0.815, 0.6, 0.11} };





void Mesh::CreateCube(float	fSize)
{
	int i;

	numVerts=8;
	pt = new Point3[numVerts];
	pt[0].set(-fSize, fSize, fSize);
	pt[1].set( fSize, fSize, fSize);
	pt[2].set( fSize, fSize, -fSize);
	pt[3].set(-fSize, fSize, -fSize);
	pt[4].set(-fSize, -fSize, fSize);
	pt[5].set( fSize, -fSize, fSize);
	pt[6].set( fSize, -fSize, -fSize);
	pt[7].set(-fSize, -fSize, -fSize);


	numFaces= 6;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	
	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for(i = 0; i<face[4].nVerts ; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for(i = 0; i<face[5].nVerts ; i++)
		face[5].vert[i].colorIndex = 5;
	CalculateFacesNorm();
}



void Mesh::CreateTetrahedron()
{
	int i;
	numVerts=4;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(1, 0, 0);
	pt[2].set(0, 1, 0);
	pt[3].set(0, 0, 1);

	numFaces= 4;
	face = new Face[numFaces];

	face[0].nVerts = 3;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 2;
	face[0].vert[2].vertIndex = 3;
	for(i = 0; i<face[0].nVerts ; i++)
		face[0].vert[i].colorIndex = 0;
	

	face[1].nVerts = 3;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;	
	face[1].vert[1].vertIndex = 2;
	face[1].vert[2].vertIndex = 1;
	for(i = 0; i<face[1].nVerts ; i++)
		face[1].vert[i].colorIndex = 1;

	
	face[2].nVerts = 3;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 3;
	face[2].vert[2].vertIndex = 2;
	for(i = 0; i<face[2].nVerts ; i++)
		face[2].vert[i].colorIndex = 2;


	face[3].nVerts = 3;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 1;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 0;
	for(i = 0; i<face[3].nVerts ; i++)
		face[3].vert[i].colorIndex = 3;
	CalculateFacesNorm();
}


void Mesh::DrawWireframe()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;

			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
	
}

void Mesh::DrawColor(int color)
{
	
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	for (int f = 0; f < numFaces; f++)
	{
		glBegin(GL_POLYGON);
		for (int v = 0; v < face[f].nVerts; v++)
		{
			int		iv = face[f].vert[v].vertIndex;
			int		ic = color;
			
//			ic = f % COLORNUM;

			glColor3f(ColorArr[ic][0], ColorArr[ic][1], ColorArr[ic][2]); 
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
	
}

void Mesh::Draw() {
	for (int f = 0; f < numFaces; f++) {
		glBegin(GL_POLYGON);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		for (int v = 0; v < face[f].nVerts; v++) {
			int		iv = face[f].vert[v].vertIndex;
			glNormal3f(face[f].facenorm.x, face[f].facenorm.y, face[f].facenorm.z);
			glVertex3f(pt[iv].x, pt[iv].y, pt[iv].z);
		}
		glEnd();
	}
	
}

void Mesh::CreateCuboid(float	fSizeX, float fSizeY, float	fSizeZ) {
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(-fSizeX, fSizeY, fSizeZ);
	pt[1].set(fSizeX, fSizeY, fSizeZ);
	pt[2].set(fSizeX, fSizeY, -fSizeZ);
	pt[3].set(-fSizeX, fSizeY, -fSizeZ);
	pt[4].set(-fSizeX, -fSizeY, fSizeZ);
	pt[5].set(fSizeX, -fSizeY, fSizeZ);
	pt[6].set(fSizeX, -fSizeY, -fSizeZ);
	pt[7].set(-fSizeX, -fSizeY, -fSizeZ);


	numFaces = 6;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 1;
	face[0].vert[1].vertIndex = 5;
	face[0].vert[2].vertIndex = 6;
	face[0].vert[3].vertIndex = 2;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	//Right face
	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 0;
	face[1].vert[1].vertIndex = 3;
	face[1].vert[2].vertIndex = 7;
	face[1].vert[3].vertIndex = 4;
	for (i = 0; i<face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	//top face
	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 2;
	face[2].vert[3].vertIndex = 3;
	for (i = 0; i<face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	//bottom face
	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 7;
	face[3].vert[1].vertIndex = 6;
	face[3].vert[2].vertIndex = 5;
	face[3].vert[3].vertIndex = 4;
	for (i = 0; i<face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	//near face
	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 4;
	face[4].vert[1].vertIndex = 5;
	face[4].vert[2].vertIndex = 1;
	face[4].vert[3].vertIndex = 0;
	for (i = 0; i<face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	//Far face
	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 3;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 6;
	face[5].vert[3].vertIndex = 7;
	for (i = 0; i<face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;
	CalculateFacesNorm();
}


void Mesh::CreateCylinder(int nSegment, float fHeight, float fRadius) {
	numVerts = nSegment * 2 + 2;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = 2 * PI / nSegment;
	float	x, y, z;

	pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i<nSegment; i++) {
		x = fRadius* cos(fAngle*i);
		z = fRadius* sin(fAngle*i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);
	}
	pt[numVerts - 1].set(0, -fHeight / 2, 0);

	numFaces = nSegment * 3;
	face = new Face[numFaces];

	idx = 0;
	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = 0;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = i + 1;
		idx++;
	}

	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1;
		if (i <nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}

	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = numVerts - 1;
		if (i < nSegment - 1)
			face[idx].vert[2].vertIndex = i + 2 + nSegment;
		else
			face[idx].vert[2].vertIndex = 1 + nSegment;
		face[idx].vert[1].vertIndex = i + 1 + nSegment;
		idx++;
	}
	CalculateFacesNorm();
}
 

void Mesh::CreateHollow(int nSegment, float fHeight, float fRadius1, float fRadius2)
{
	numVerts = nSegment * 4;
	pt = new Point3[numVerts];
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i == 2)
			fHeight *= -1;
		float r = (i == 0 || i == 3) ? fRadius1 : fRadius2;
		for (int j = 0; j < nSegment; j++)
		{
			float x = r * cos(2 * PI*j / nSegment);
			float z = r * sin(2 * PI*j / nSegment);
			pt[count].set(x, fHeight, z);
			count++;
		}
	}
	// ve face
	numFaces = nSegment * 4;
	face = new Face[numFaces];
	count = 0;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < nSegment; j++)
		{
			face[count].nVerts = 4;
			face[count].vert = new VertexID[face[count].nVerts];
			face[count].vert[0].vertIndex = nSegment * (i % 4) + j;
			face[count].vert[1].vertIndex = nSegment * (i % 4) + ((j + 1) % nSegment);
			face[count].vert[2].vertIndex = nSegment * (i - 1) + ((j + 1) % nSegment);
			face[count].vert[3].vertIndex = nSegment * (i - 1) + j;
			count++;
		}
	}
	CalculateFacesNorm();
}

void Mesh::CreateGrooveBox(float fLong, float fLength1, float fLength2, float fLength3, float fHeight1, float fHeight2) {
	int i;

	numVerts = 20;
	pt = new Point3[numVerts];
	pt[0].set(fLong / 2, -fHeight1, fLength1 / 2);
	pt[1].set(fLong / 2, 0, fLength1 / 2);
	pt[2].set(fLong / 2, 0, fLength2 / 2);
	pt[3].set(fLong / 2, fHeight2, fLength1 / 2);
	pt[4].set(fLong / 2, fHeight2, fLength3 / 2);
	pt[5].set(fLong / 2, -fHeight1, -fLength1 / 2);
	pt[6].set(fLong / 2, 0, -fLength1 / 2);
	pt[7].set(fLong / 2, 0, -fLength2 / 2);
	pt[8].set(fLong / 2, fHeight2, -fLength1 / 2);
	pt[9].set(fLong / 2, fHeight2, -fLength3 / 2);
	pt[10].set(-fLong / 2, -fHeight1, fLength1 / 2);
	pt[11].set(-fLong / 2, 0, fLength1 / 2);
	pt[12].set(-fLong / 2, 0, fLength2 / 2);
	pt[13].set(-fLong / 2, fHeight2, fLength1 / 2);
	pt[14].set(-fLong / 2, fHeight2, fLength3 / 2);
	pt[15].set(-fLong / 2, -fHeight1, -fLength1 / 2);
	pt[16].set(-fLong / 2, 0, -fLength1 / 2);
	pt[17].set(-fLong / 2, 0, -fLength2 / 2);
	pt[18].set(-fLong / 2, fHeight2, -fLength1 / 2);
	pt[19].set(-fLong / 2, fHeight2, -fLength3 / 2);
	numFaces = 20;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 2;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 3;
	face[0].vert[3].vertIndex = 4;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 7;
	face[1].vert[1].vertIndex = 6;
	face[1].vert[2].vertIndex = 8;
	face[1].vert[3].vertIndex = 9;
	for (i = 0; i<face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 6;
	face[2].vert[3].vertIndex = 5;
	for (i = 0; i<face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 0;
	face[3].vert[1].vertIndex = 3;
	face[3].vert[2].vertIndex = 13;
	face[3].vert[3].vertIndex = 10;
	for (i = 0; i<face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 3;
	face[4].vert[1].vertIndex = 4;
	face[4].vert[2].vertIndex = 14;
	face[4].vert[3].vertIndex = 13;
	for (i = 0; i<face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 11;
	face[5].vert[1].vertIndex = 12;
	face[5].vert[2].vertIndex = 14;
	face[5].vert[3].vertIndex = 13;
	for (i = 0; i<face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;

	face[6].nVerts = 4;
	face[6].vert = new VertexID[face[6].nVerts];
	face[6].vert[0].vertIndex = 2;
	face[6].vert[1].vertIndex = 4;
	face[6].vert[2].vertIndex = 14;
	face[6].vert[3].vertIndex = 12;
	for (i = 0; i<face[6].nVerts; i++)
		face[6].vert[i].colorIndex = 6;

	face[7].nVerts = 4;
	face[7].vert = new VertexID[face[7].nVerts];
	face[7].vert[0].vertIndex = 10;
	face[7].vert[1].vertIndex = 11;
	face[7].vert[2].vertIndex = 16;
	face[7].vert[3].vertIndex = 15;
	for (i = 0; i<face[7].nVerts; i++)
		face[7].vert[i].colorIndex = 7;

	face[8].nVerts = 4;
	face[8].vert = new VertexID[face[8].nVerts];
	face[8].vert[0].vertIndex = 2;
	face[8].vert[1].vertIndex = 7;
	face[8].vert[2].vertIndex = 17;
	face[8].vert[3].vertIndex = 12;
	for (i = 0; i<face[8].nVerts; i++)
		face[8].vert[i].colorIndex = 8;

	face[9].nVerts = 4;
	face[9].vert = new VertexID[face[9].nVerts];
	face[9].vert[0].vertIndex = 17;
	face[9].vert[1].vertIndex = 16;
	face[9].vert[2].vertIndex = 18;
	face[9].vert[3].vertIndex = 19;
	for (i = 0; i<face[9].nVerts; i++)
		face[9].vert[i].colorIndex = 9;

	face[10].nVerts = 4;
	face[10].vert = new VertexID[face[10].nVerts];
	face[10].vert[0].vertIndex = 7;
	face[10].vert[1].vertIndex = 9;
	face[10].vert[2].vertIndex = 19;
	face[10].vert[3].vertIndex = 17;
	for (i = 0; i<face[10].nVerts; i++)
		face[10].vert[i].colorIndex = 10;

	face[11].nVerts = 4;
	face[11].vert = new VertexID[face[11].nVerts];
	face[11].vert[0].vertIndex = 9;
	face[11].vert[1].vertIndex = 8;
	face[11].vert[2].vertIndex = 18;
	face[11].vert[3].vertIndex = 19;
	for (i = 0; i<face[11].nVerts; i++)
		face[11].vert[i].colorIndex = 11;

	face[12].nVerts = 4;
	face[12].vert = new VertexID[face[12].nVerts];
	face[12].vert[0].vertIndex = 5;
	face[12].vert[1].vertIndex = 8;
	face[12].vert[2].vertIndex = 18;
	face[12].vert[3].vertIndex = 15;
	for (i = 0; i<face[12].nVerts; i++)
		face[12].vert[i].colorIndex = 12;

	face[13].nVerts = 4;
	face[13].vert = new VertexID[face[13].nVerts];
	face[13].vert[0].vertIndex = 0;
	face[13].vert[1].vertIndex = 5;
	face[13].vert[2].vertIndex = 15;
	face[13].vert[3].vertIndex = 10;
	for (i = 0; i<face[13].nVerts; i++)
		face[13].vert[i].colorIndex = 13;
	CalculateFacesNorm();
}

void Mesh::CreateLedgeBox(float fLong, float fLength1, float fLength2, float fLength3, float fHeight1, float fHeight2) {
	int i;

	numVerts = 20;
	pt = new Point3[numVerts];
	pt[0].set(fLong / 2, fHeight1, fLength1 / 2);
	pt[1].set(fLong / 2, 0, fLength1 / 2);
	pt[2].set(fLong / 2, 0, fLength2 / 2);

	pt[3].set(fLong / 2, -fHeight2, fLength3 / 2);
	pt[4].set(fLong / 2, fHeight1, -fLength1 / 2);
	pt[5].set(fLong / 2, 0, -fLength1 / 2);
	pt[6].set(fLong / 2, 0, -fLength2 / 2);

	pt[7].set(fLong / 2, -fHeight2, -fLength3 / 2);
	pt[8].set(-fLong / 2, fHeight1, fLength1 / 2);
	pt[9].set(-fLong / 2, 0, fLength1 / 2);
	pt[10].set(-fLong / 2, 0, fLength2 / 2);

	pt[11].set(-fLong / 2, -fHeight2, fLength3 / 2);
	pt[12].set(-fLong / 2, fHeight1, -fLength1 / 2);
	pt[13].set(-fLong / 2, 0, -fLength1 / 2);
	pt[14].set(-fLong / 2, 0, -fLength2 / 2);
	pt[15].set(-fLong / 2, -fHeight2, -fLength3 / 2);


	numFaces = 20;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 5;
	face[0].vert[3].vertIndex = 4;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	face[1].nVerts = 4;
	face[1].vert = new VertexID[face[1].nVerts];
	face[1].vert[0].vertIndex = 4;
	face[1].vert[1].vertIndex = 5;
	face[1].vert[2].vertIndex = 13;
	face[1].vert[3].vertIndex = 12;
	for (i = 0; i<face[1].nVerts; i++)
		face[1].vert[i].colorIndex = 1;

	face[2].nVerts = 4;
	face[2].vert = new VertexID[face[2].nVerts];
	face[2].vert[0].vertIndex = 0;
	face[2].vert[1].vertIndex = 1;
	face[2].vert[2].vertIndex = 9;
	face[2].vert[3].vertIndex = 8;
	for (i = 0; i<face[2].nVerts; i++)
		face[2].vert[i].colorIndex = 2;

	face[3].nVerts = 4;
	face[3].vert = new VertexID[face[3].nVerts];
	face[3].vert[0].vertIndex = 8;
	face[3].vert[1].vertIndex = 9;
	face[3].vert[2].vertIndex = 13;
	face[3].vert[3].vertIndex = 12;
	for (i = 0; i<face[3].nVerts; i++)
		face[3].vert[i].colorIndex = 3;

	face[4].nVerts = 4;
	face[4].vert = new VertexID[face[4].nVerts];
	face[4].vert[0].vertIndex = 0;
	face[4].vert[1].vertIndex = 4;
	face[4].vert[2].vertIndex = 12;
	face[4].vert[3].vertIndex = 8;
	for (i = 0; i<face[4].nVerts; i++)
		face[4].vert[i].colorIndex = 4;

	face[5].nVerts = 4;
	face[5].vert = new VertexID[face[5].nVerts];
	face[5].vert[0].vertIndex = 1;
	face[5].vert[1].vertIndex = 2;
	face[5].vert[2].vertIndex = 10;
	face[5].vert[3].vertIndex = 9;
	for (i = 0; i<face[5].nVerts; i++)
		face[5].vert[i].colorIndex = 5;

	face[6].nVerts = 4;
	face[6].vert = new VertexID[face[6].nVerts];
	face[6].vert[0].vertIndex = 6;
	face[6].vert[1].vertIndex = 5;
	face[6].vert[2].vertIndex = 13;
	face[6].vert[3].vertIndex = 14;
	for (i = 0; i<face[6].nVerts; i++)
		face[6].vert[i].colorIndex = 6;

	face[7].nVerts = 4;
	face[7].vert = new VertexID[face[7].nVerts];
	face[7].vert[0].vertIndex = 3;
	face[7].vert[1].vertIndex = 2;
	face[7].vert[2].vertIndex = 10;
	face[7].vert[3].vertIndex = 11;
	for (i = 0; i<face[7].nVerts; i++)
		face[7].vert[i].colorIndex = 7;

	face[8].nVerts = 4;
	face[8].vert = new VertexID[face[8].nVerts];
	face[8].vert[0].vertIndex = 6;
	face[8].vert[1].vertIndex = 7;
	face[8].vert[2].vertIndex = 15;
	face[8].vert[3].vertIndex = 14;
	for (i = 0; i<face[8].nVerts; i++)
		face[8].vert[i].colorIndex = 8;

	face[9].nVerts = 4;
	face[9].vert = new VertexID[face[9].nVerts];
	face[9].vert[0].vertIndex = 3;
	face[9].vert[1].vertIndex = 7;
	face[9].vert[2].vertIndex = 15;
	face[9].vert[3].vertIndex = 11;
	for (i = 0; i<face[9].nVerts; i++)
		face[9].vert[i].colorIndex = 9;

	face[10].nVerts = 4;
	face[10].vert = new VertexID[face[10].nVerts];
	face[10].vert[0].vertIndex = 2;
	face[10].vert[1].vertIndex = 6;
	face[10].vert[2].vertIndex = 7;
	face[10].vert[3].vertIndex = 3;
	for (i = 0; i<face[10].nVerts; i++)
		face[10].vert[i].colorIndex = 10;

	face[11].nVerts = 4;
	face[11].vert = new VertexID[face[11].nVerts];
	face[11].vert[0].vertIndex = 10;
	face[11].vert[1].vertIndex = 14;
	face[11].vert[2].vertIndex = 15;
	face[11].vert[3].vertIndex = 11;
	for (i = 0; i<face[11].nVerts; i++)
		face[11].vert[i].colorIndex = 11;

	CalculateFacesNorm();
}

void Mesh::CreateCylinderxBox(int nSegment, float fRadius, float fLength, float fHeight) {	
	numVerts = nSegment * 4 + 4;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = (2 * PI / nSegment)/4;
	float	x, y, z;

	pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i<nSegment; i++) {
		x = fRadius* cos(0.75*PI + fAngle*i) + fRadius+fLength/2;
		z = fRadius* sin(0.75*PI+fAngle*i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);
	}
	
	for (i = 0; i<nSegment; i++) {
		x = fRadius* cos(-0.25*PI+fAngle*i)-fRadius-fLength/2;
		z = fRadius* sin(-0.25*PI+fAngle*i);
		y = fHeight / 2;
		pt[i + 1 + 2*nSegment].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + 3*nSegment].set(x, y, z);
	}

	numFaces = 100;
	face = new Face[numFaces];

	idx = 0;
	

	for (int j = 0; j < 19; j++) {
		face[j].nVerts = 4;
		face[j].vert = new VertexID[face[j].nVerts];
		face[j].vert[0].vertIndex = j + 1;
		face[j].vert[1].vertIndex = j + 2;
		face[j].vert[2].vertIndex = j + 22;
		face[j].vert[3].vertIndex = j + 21;
		for (i = 0; i < face[0].nVerts; i++)
			face[j].vert[i].colorIndex = j;
	}
	

	for (int j = 40; j < 59; j++) {
		face[j].nVerts = 4;
		face[j].vert = new VertexID[face[j].nVerts];
		face[j].vert[0].vertIndex = j + 1;
		face[j].vert[1].vertIndex = j + 2;
		face[j].vert[2].vertIndex = j + 22;
		face[j].vert[3].vertIndex = j + 21;
		for (i = 0; i < face[0].nVerts; i++)
			face[j].vert[i].colorIndex = j;
	}

	
		
	for (int j = 0; j < 19; j++) {
		face[j+20].nVerts = 4;
		face[j+20].vert = new VertexID[face[j+20].nVerts];
		face[j+20].vert[0].vertIndex = j + 1;
		face[j+20].vert[1].vertIndex = j + 2;
		face[j+20].vert[2].vertIndex = 59 - j;
		face[j+20].vert[3].vertIndex = 60 - j;
		for (i = 0; i < face[0].nVerts; i++)
			face[j+20].vert[i].colorIndex = j+20;
	}

	for (int j = 20; j < 39; j++) {
		face[j+40].nVerts = 4;
		face[j+40].vert = new VertexID[face[j+40].nVerts];
		face[j+40].vert[0].vertIndex = j + 1;
		face[j+40].vert[1].vertIndex = j + 2;
		face[j+40].vert[2].vertIndex = 99-j;
		face[j+40].vert[3].vertIndex = 100-j;
		for (i = 0; i < face[0].nVerts; i++)
			face[j+40].vert[i].colorIndex = j+40;
	}
	
	face[79].nVerts = 4;
	face[79].vert = new VertexID[face[79].nVerts];
	face[79].vert[0].vertIndex = 20;
	face[79].vert[1].vertIndex = 40;
	face[79].vert[2].vertIndex = 61;
	face[79].vert[3].vertIndex = 41;
	for (i = 0; i<face[0].nVerts; i++)
		face[79].vert[i].colorIndex = 79;

	face[80].nVerts = 4;
	face[80].vert = new VertexID[face[80].nVerts];
	face[80].vert[0].vertIndex = 1;
	face[80].vert[1].vertIndex = 21;
	face[80].vert[2].vertIndex = 80;
	face[80].vert[3].vertIndex = 60;
	for (i = 0; i<face[0].nVerts; i++)
		face[80].vert[i].colorIndex = 80;

	CalculateFacesNorm();
}


void Mesh::CreateTruckle(int nSegment, float fRadius1, float fRadius2, float fLength, float fHeight) {
	numVerts = nSegment * 2 + 2;
	pt = new Point3[numVerts];

	int		i;
	int		idx;
	float	fAngle = 2 * PI / nSegment;
	float	x, y, z;

	pt[0].set(0, fHeight / 2, 0);
	for (i = 0; i<nSegment; i++) {
		x = fRadius1* cos(fAngle*i);
		z = fRadius1* sin(fAngle*i);
		y = fHeight / 2;
		pt[i + 1].set(x, y, z);

		y = -fHeight / 2;
		pt[i + 1 + nSegment].set(x, y, z);
	}
	

	numFaces = nSegment * 3;
	face = new Face[numFaces];

	idx = 0;
	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = 0;
		if (i < nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = i + 1;
		idx++;
	}

	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 4;
		face[idx].vert = new VertexID[face[idx].nVerts];

		face[idx].vert[0].vertIndex = i + 1;
		if (i <nSegment - 1)
			face[idx].vert[1].vertIndex = i + 2;
		else
			face[idx].vert[1].vertIndex = 1;
		face[idx].vert[2].vertIndex = face[idx].vert[1].vertIndex + nSegment;
		face[idx].vert[3].vertIndex = face[idx].vert[0].vertIndex + nSegment;

		idx++;
	}

	for (i = 0; i<nSegment; i++) {
		face[idx].nVerts = 3;
		face[idx].vert = new VertexID[face[idx].nVerts];
		face[idx].vert[0].vertIndex = numVerts - 1;
		if (i < nSegment - 1)
			face[idx].vert[2].vertIndex = i + 2 + nSegment;
		else
			face[idx].vert[2].vertIndex = 1 + nSegment;
		face[idx].vert[1].vertIndex = i + 1 + nSegment;
		idx++;
	}
	CalculateFacesNorm();
}


void Mesh::CreateFloor()
{
	int i;

	numVerts = 8;
	pt = new Point3[numVerts];
	pt[0].set(0, 0, 0);
	pt[1].set(0.5, 0, sqrt(3)/2+0.1);
	pt[2].set(1, 0, 0);
	pt[3].set(0.5, 0, -0.5*sqrt(3)-0.1);
	pt[4].set(-0.5, 0, -0.5*sqrt(3));
	pt[5].set(-1, 0, 0);
	pt[6].set(-0.5, 0, 0.5*sqrt(3));



	numFaces = 3;
	face = new Face[numFaces];

	//Left face
	face[0].nVerts = 4;
	face[0].vert = new VertexID[face[0].nVerts];
	face[0].vert[0].vertIndex = 0;
	face[0].vert[1].vertIndex = 1;
	face[0].vert[2].vertIndex = 2;
	face[0].vert[3].vertIndex = 3;
	for (i = 0; i<face[0].nVerts; i++)
		face[0].vert[i].colorIndex = 0;

	

}