#ifndef _TerrainObject
#define _TerrainObject

#include <gl/gl3w.h> //apparently this is needed
//#include <gl\GL.h> 
#include <TextureTGA.h>
#include <GpuVertTypes.h>
#include "DrawObject.h"
#include "CellValues.h"
//#include "GL/gl3w.h"
//#include <d3d11.h>
//#include "DirectXTex.h"

class Model;
class GameObject;
struct ID3D11DeviceContext;
struct ID3D11Device;

struct TriangleByIndex;
struct StandardVertex;

//struct CellValues;

class TerrainObject : public DrawObject
{

private:
	//User inputs
	char* heightmapFile;
	float scale;
	float maxHeight;
	float yTrans;
	char* textureFile;
	int repeatU;
	int repeatV;
	

	//Terrain created values
	int imgWidth, imgHeight, icomp;
	float cellSize;

	Vect GOCellMax;
	Vect GOCellMin;

	Model* tModel;

	GraphicsObject_TextureFlat* pGObj_Terrain = nullptr;
	//GraphicsObject_WireframeConstantColor* pGObj_Terrain = nullptr; //use this for wireframe mode
	static Vect DEFAULT_COLOR;
	
	//World data
	Matrix mTerrainScale;
	Vect vTerrainPos;
	Matrix mTerrainRot;
	Matrix mTerrainRotPos;
	Matrix mWorld;

	CellValues** cellArray = nullptr;

	void BuildTerrain();

public:

	TerrainObject();
	TerrainObject(char* fileName, float s, float maxheight, float baseHeight, char* textureName, int repeatu, int repeatv);
	TerrainObject(const TerrainObject&) = delete;
	TerrainObject& operator=(const TerrainObject&) = delete;
	~TerrainObject();

	void Initialize();
	void Draw();

	void SendPosition(Vect pos, float r);
	void TestIntersection(GameObject& go);
	Vect GetTerrainPosNormal(Vect pos);
	float GetTerrainPosHeight(Vect& pos);
	Vect GetPlanePos(Vect pos);

	

};



#endif _TerrainObject