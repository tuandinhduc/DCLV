#if !defined (_MESH_CLASS)
#define _MESH_CLASS

#include "supportClass.h"



class VertexID
{
public:
	int		vertIndex;
	int		colorIndex;
};

class Face
{
	
public:
	int		nVerts;
	VertexID*	vert;
	Vector3		facenorm;
	Face()
	{
		nVerts	= 0;
		vert	= NULL;
	}
	~Face()
	{
		if(vert !=NULL)
		{
			delete[] vert;
			vert = NULL;
		}
		nVerts = 0;
	}
};

class Mesh
{


public:
	int		numVerts;
	Point3*		pt;
	
	int		numFaces;
	Face*		face;
	float		slideX, slideY, slideZ;
	float		rotateX, rotateY, rotateZ;
	float		scaleX, scaleY, scaleZ;

public:
	Mesh()
	{
		slideX = 0;
		slideY = 0;
		slideZ = 0;
		rotateX = 0;
		rotateY = 0;
		rotateZ = 0;
		scaleX = 1;
		scaleY = 1;
		scaleZ = 1;
		numVerts	= 0;
		pt		= NULL;
		numFaces	= 0;
		face		= NULL;
	}
	~Mesh()
	{
		if (pt != NULL)
		{
			delete[] pt;
		}	
		if(face != NULL)
		{
			delete[] face;
		}
		numVerts = 0;
		numFaces = 0;
	}
	void DrawWireframe();
	void Mesh::Draw();
	void Mesh::DrawColor(int color);
	void Mesh::CalculateFacesNorm()
	{
		for (int f = 0; f< numFaces; f++) {
			for (int v = 0; v < face[f].nVerts; v++)
			{
				face[f].facenorm.x += (pt[face[f].vert[v].vertIndex].y - pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].y)
					* (pt[face[f].vert[v].vertIndex].z + pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].z);

				face[f].facenorm.y += (pt[face[f].vert[v].vertIndex].z - pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].z)
					* (pt[face[f].vert[v].vertIndex].x + pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].x);

				face[f].facenorm.z += (pt[face[f].vert[v].vertIndex].x - pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].x)
					* (pt[face[f].vert[v].vertIndex].y + pt[face[f].vert[(v + 1) % face[f].nVerts].vertIndex].y);

			}
			face[f].facenorm.normalize();
		}
	}
	void Mesh::SetColor(int colorIdx) {
		for (int f = 0; f < numFaces; f++)
		{
			for (int v = 0; v < face[f].nVerts; v++)
			{
				face[f].vert[v].colorIndex = colorIdx;
			}
		}
	}

	void CreateTetrahedron();
	void CreateCube(float fSize);
	void CreateCuboid(float	fSizeX, float fSizeY, float	fSizeZ);
	void CreateCylinder(int nSegment, float fHeight, float fRadius);
	void CreateHollow(int nSegment, float fHeight, float fRadius1, float fRadius2);
	void CreateGrooveBox(float fLong, float fLength1, float fLength2, float fLength3, float fHeight1, float fHeight2);
	void CreateLedgeBox(float fLong, float fLength1, float fLength2, float fLength3, float fHeight1, float fHeight2);
	void CreateCylinderxBox(int nSegment, float fRadius, float fLength, float fHeight);
	void CreateTruckle(int nSegment, float fRadius1, float fRadius2, float fLength, float fHeight);
	void CreateFloor();
};

#endif