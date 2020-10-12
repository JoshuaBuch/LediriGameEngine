#include "TerrainObject.h"
#include "Model.h"

#include "../Lediri Engine/GameObjectDependencies.h"

Vect TerrainObject::DEFAULT_COLOR = Color::Red;

TerrainObject::TerrainObject()
{
	//****** This constructor is only for testing!!!! Ignore how ugly it is!*****
	//LPCWSTR heightmapFile, float scale, float maxheight, float ytrans, int RepeatU, int RepeatV
//L"../Assets/Textures/heightmap.tga", 2, 100, -20, 10, 10
	repeatU = 1;
	repeatV = 1;
	scale = 20.0f;
	maxHeight = 20.0f;
	yTrans = 0;

	heightmapFile = "Textures/h4x4.tga";
	//int imgWidth = 2, imgHeight = 2, icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(heightmapFile, &imgWidth, &imgHeight, &icomp, &dtype);
	assert(imgWidth == imgHeight && imgWidth != 0);

	int side = imgHeight;

	float uvMap = 1.0f / (side - 1);
	float textureU = uvMap * repeatU;
	float textureV = uvMap * repeatV;
	textureU;
	textureV;

	float halfTerrain = 0.5f * (side * scale);
	cellSize = (side * scale) / (side - 1);
	halfTerrain;

	float pixelHeight = 0;

	float hVal_neCol = 0;
	float hVal_prCol = 0;
	float hVal_neInx = 0;
	float hVal_prInx = 0;

	float normZ = 0.0f;
	float normX = 0.0f;

	// Figure out numVers and numTries
	int ntri = ((side - 1) * (side - 1)) * 2;
	int nverts = ntri * 3;

	VertexStride_VUN* pVerts;
	TriangleIndex* pTriList;
	// Instanciate arrays
	pVerts = new VertexStride_VUN[(size_t)nverts];
	pTriList = new TriangleIndex[(size_t)ntri];

	// Generate array data

	float x = 0.0f;
	float z = 0.0f;

	Vect normal = Vect(0, 1, 0);
	int itter = 0;
	for (int row = 0; row < side; row++)
	{
		//DebugMsg::out("\n");
		z = -(halfTerrain - row * cellSize);


		for (int col = 0; col < side; col++)
		{
			//pixelHeight = ((hgtmap->pixels[TexelIndex(side, row, col)] * maxHeight) / 255);
			pixelHeight = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
			pixelHeight = ((float)pixelHeight / 255) * maxHeight;

			x = halfTerrain - col * cellSize;
			x = x;
			//x -= (side) / (side - 1);

			//DebugMsg::out("%f, index:%d\t", pixelHeight, ((row * side) + col) * 3);
			//pVerts[itter].set(
			//	x,
			//	//(float)row * scale,			// x 
			//	pixelHeight + ytrans,		// y
			//	z,
			//	//(float)col * scale,			// z
			//	//(float)col / (float)imgHeight,
			//	//(float)row / (float)imgWidth,
			//	(float)col * textureU,				// u
			//	(float)row * textureV,				// v
			//	0,
			//	0,
			//	0
			//);				// color

											// Top Edge
			if (pVerts[itter].y == 0)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row + 1)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[(((row + 1) * side) + col) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = pixelHeight - hVal_neCol;
			}
			// Edges
			else if (pVerts[itter].y == side - 1)
			{
				//hVal_prCol = ((hgtmap->pixels[TexelIndex(side, col, row - 1)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[(((row - 1) * side) + col) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = hVal_prCol - pixelHeight;
			}
			// Middle
			else
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				//hVal_prCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = ((pixelHeight - hVal_neCol) + (hVal_prCol - pixelHeight)) * 0.5f;
			}

			if (pVerts[itter].x == 0)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col + 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col + 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normX = pixelHeight - hVal_neInx;
			}
			else if (pVerts[itter].x == side - 1)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col - 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col - 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normX = hVal_prInx - pixelHeight;
			}
			else
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col + 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col + 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				//hVal_prCol = ((float)(hgtmap->pixels[TexelIndex(side, col - 1, row)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[((row * side) + (col - 1)) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = ((pixelHeight - hVal_neInx) + (hVal_prCol - pixelHeight)) * 0.5f;

			}



			normal.set(normX, 1.0f, normZ);

			pVerts[itter].set(
				x,
				//(float)row * scale,			// x 
				pixelHeight + yTrans,		// y
				z,
				//(float)col * scale,			// z
				(float)col * textureU,				// u
				(float)row * textureV,				// v
				normal.X(),
				normal.Y(),
				normal.Z()
			);				// color

			//pVerts[itter].x = x;
			//pVerts[itter].y = pixelHeight + ytrans;
			//pVerts[itter].z = z;
			//pVerts[itter].u = (float)col * textureU;
			//pVerts[itter].v = (float)row * textureV;

			//pVerts[itter++].normal = normal.getNorm(); ignore norms for now
			pVerts[itter + 1].ny = normal.Y();
			pVerts[itter + 1].nx = normal.X();
			pVerts[itter + 1].nz = normal.Z();
			itter++;
		}

		//z += (side) / (side - 1);
		//x = side * .5f;
	}

	//for (int i = 0; i < nverts; i++)
	//{
	//	DebugMsg::out("\n%f, index:%d\t");
	//	float m = pVerts[i].x;
	//	m;

	//}
	//int cellAmount = ntri / 2;
	//cellArray = new CellValues [cellAmount];

	cellArray = new CellValues * [imgWidth - 1];
	for (int i = 0; i < imgWidth - 1; i++)
	{
		cellArray[i] = new CellValues[imgWidth - 1];
	}
	int t = 0;
	for (int i = 0; i < imgWidth - 1; i++)		// row
	{
		for (int j = 0; j < imgWidth - 1; j++)	// col
		{
			cellArray[i][j].max.Y() = pVerts[(i + 1) * imgWidth + j].y;
			//cellArray[i][j].min.Y() = pVerts[(i + 1) * imgWidth + j].y;
			cellArray[i][j].min.Y() = pVerts[(i * imgWidth) + j + 1].y;
			//row*dim+col		//row*dim+col+1		//(row+1)*dim+col

			pTriList[t++].set(i * imgWidth + j, i * imgWidth + j + 1, (i + 1) * imgWidth + j);

			//check for max Y values in vertices
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v0].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v0].y;
			}
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v1].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v1].y;
			}
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v0].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v0].y;
			}
			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v1].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v1].y;
			}
			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			//cellArray[i][j].max.Y() = cellArray[i][j].max.Y();
			//cellArray[i][j].min.Y() = cellArray[i][j].min.Y();

			cellArray[i][j].max.X() = pVerts[pTriList[t - 1].v2].x;
			cellArray[i][j].max.Z() = pVerts[pTriList[t - 1].v2].z;

			cellArray[i][j].min.X() = pVerts[pTriList[t - 1].v1].x;
			cellArray[i][j].min.Z() = pVerts[pTriList[t - 1].v1].z;
			//grab the Cell's x max and z min
			/*
			vertex 1 (bottom right of cell should be max X and max Z since we're in right handed space)
			vertex 2 (top left of cell should be min X and min Z)
			*/
			//DebugMsg::out("\nVertex %i Pos: x=%f, y=%f, z=%f", i* imgWidth + j, pVerts[0].x, pVerts[0].y, pVerts[0].z);
			//DebugMsg::out("\nVertex %i Pos: x=%f, y=%f, z=%f", (i + 1)* imgWidth + j, pVerts[2].x, pVerts[2].y, pVerts[2].z);

			//DebugMsg::out("\nTriVerts: %d, %d, %d", i* imgWidth + j, i* imgWidth + j + 1, (i + 1)* imgWidth + j);
			//pVerts[0].y = -2.0f;

			//pVerts[2].y = 1.0f;
			//pVerts[3].y = 2.0f;


			//(row+1)*dim+col		//row*dim+col+1		//(row+1)*dim+col+1
			pTriList[t++].set((i + 1) * imgWidth + j, i * imgWidth + j + 1, (i + 1) * imgWidth + j + 1);

			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			//cellArray[i][j].max.Y() = cellArray[i][j].max.Y();
			//cellArray[i][j].min.Y() = cellArray[i][j].min.Y();

			//DebugMsg::out("\nTriVerts: %d, %d, %d", (i + 1)* imgWidth + j, i* imgWidth + j + 1, (i + 1)* imgWidth + j + 1);
			//this creates one cell so create the AABB variables here.

			//************************IMPORTANT
			//for getting the correct indices for a cell
			//return Cell(int(-1 * (maxZ - v.Z()) / cellHeight), int((maxX - v.X()) / cellWidth));
			//for loop for finding every Cell
			//[i, j] = [2, 0];
			//for(int x = j of max; j < i + 1; j++)

			//return Cell(int(-1 * (maxZ - v.Z()) / cellHeight), int((maxX - v.X()) / cellWidth));

			//cellArray[i][j].yMax = pVerts[i * imgWidth + j + 1].y;
			//cellArray[i][j].yMin = pVerts[(i + 1) * imgWidth + j].y;

			//DebugMsg::out("\nCell[%d][%d] max = %f, %f, %f", i, j, cellArray[i][j].max.X(), cellArray[i][j].max.Y(), cellArray[i][j].max.Z());
			//DebugMsg::out("\nCell[%d][%d] min = %f, %f, %f", i, j, cellArray[i][j].min.X(), cellArray[i][j].min.Y(), cellArray[i][j].min.Z());

		}
	}


	// Create new terrain instance
	//pModTerrain = new Model(dev, pVerts, (int)nverts, pTriList, (int)ntri);


	tModel = new Model(pVerts, nverts, pTriList, ntri);

	delete[] pVerts;
	delete[] pTriList;

	//pGObj_Terrain = new GraphicsObject_WireframeConstantColor(tModel, ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);

	pGObj_Terrain = new GraphicsObject_TextureFlat(tModel, ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("GrassTex"));

	mTerrainScale.set(SCALE, 1.0f, 1.0f, 1.0f);

	mTerrainRot.set(IDENTITY);
	//mTerrainRot *= Matrix(ROT_Y, 3.14159f);

	vTerrainPos.set(0, 0, 0);
	mWorld = mTerrainScale * mTerrainRot * Matrix(TRANS, vTerrainPos);
	pGObj_Terrain->SetWorld(mWorld);

	SubmitDrawRegistration();
}

TerrainObject::TerrainObject(char* fileName, float s, float maxheight, float baseHeight, char* textureName, int repeatu, int repeatv)
{
	//Assign user inputs
	heightmapFile = fileName;
	scale = s;
	maxHeight = maxheight;
	yTrans = baseHeight;
	textureFile = textureName;
	repeatU = repeatu;
	repeatV = repeatv;
}

void TerrainObject::Initialize()
{
	this->BuildTerrain();
}

void TerrainObject::BuildTerrain()
{
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(heightmapFile, &imgWidth, &imgHeight, &icomp, &dtype);
	assert(imgWidth == imgHeight && imgWidth != 0);

	int side = imgHeight;

	float uvMap = 1.0f / (side - 1);
	float textureU = uvMap * repeatU;
	float textureV = uvMap * repeatV;
	textureU;
	textureV;

	float halfTerrain = 0.5f * (side * scale);
	cellSize = (side * scale) / (side - 1);
	halfTerrain;

	float pixelHeight = 0;

	float hVal_neCol = 0;
	float hVal_prCol = 0;
	float hVal_neInx = 0;
	float hVal_prInx = 0;

	float normZ = 0.0f;
	float normX = 0.0f;

	// Figure out numVers and numTries
	int ntri = ((side - 1) * (side - 1)) * 2;
	int nverts = ntri * 3;

	VertexStride_VUN* pVerts;
	TriangleIndex* pTriList;
	// Instanciate arrays
	pVerts = new VertexStride_VUN[(size_t)nverts];
	pTriList = new TriangleIndex[(size_t)ntri];

	// Generate array data

	float x = 0.0f;
	float z = 0.0f;

	Vect normal = Vect(0, 1, 0);
	int itter = 0;
	for (int row = 0; row < side; row++)
	{
		//DebugMsg::out("\n");
		z = -(halfTerrain - row * cellSize);


		for (int col = 0; col < side; col++)
		{
			//pixelHeight = ((hgtmap->pixels[TexelIndex(side, row, col)] * maxHeight) / 255);
			pixelHeight = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
			pixelHeight = ((float)pixelHeight / 255) * maxHeight;

			x = halfTerrain - col * cellSize;
			x = x;
			//x -= (side) / (side - 1);

			//DebugMsg::out("%f, index:%d\t", pixelHeight, ((row * side) + col) * 3);
			//pVerts[itter].set(
			//	x,
			//	//(float)row * scale,			// x 
			//	pixelHeight + ytrans,		// y
			//	z,
			//	//(float)col * scale,			// z
			//	//(float)col / (float)imgHeight,
			//	//(float)row / (float)imgWidth,
			//	(float)col * textureU,				// u
			//	(float)row * textureV,				// v
			//	0,
			//	0,
			//	0
			//);				// color

											// Top Edge
			if (pVerts[itter].y == 0)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row + 1)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[(((row + 1) * side) + col) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = pixelHeight - hVal_neCol;
			}
			// Edges
			else if (pVerts[itter].y == side - 1)
			{
				//hVal_prCol = ((hgtmap->pixels[TexelIndex(side, col, row - 1)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[(((row - 1) * side) + col) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = hVal_prCol - pixelHeight;
			}
			// Middle
			else
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				//hVal_prCol = ((float)(hgtmap->pixels[TexelIndex(side, col, row)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[((row * side) + col) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = ((pixelHeight - hVal_neCol) + (hVal_prCol - pixelHeight)) * 0.5f;
			}

			if (pVerts[itter].x == 0)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col + 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col + 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normX = pixelHeight - hVal_neInx;
			}
			else if (pVerts[itter].x == side - 1)
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col - 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col - 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				normX = hVal_prInx - pixelHeight;
			}
			else
			{
				//hVal_neCol = ((float)(hgtmap->pixels[TexelIndex(side, col + 1, row)] / 255) * maxHeight);

				hVal_neCol = static_cast<unsigned char>(imgData[((row * side) + (col + 1)) * 3]);
				hVal_neCol = ((float)pixelHeight / 255) * maxHeight;

				//hVal_prCol = ((float)(hgtmap->pixels[TexelIndex(side, col - 1, row)] / 255) * maxHeight);

				hVal_prCol = static_cast<unsigned char>(imgData[((row * side) + (col - 1)) * 3]);
				hVal_prCol = ((float)pixelHeight / 255) * maxHeight;

				normZ = ((pixelHeight - hVal_neInx) + (hVal_prCol - pixelHeight)) * 0.5f;

			}



			normal.set(normX, 1.0f, normZ);

			pVerts[itter].set(
				x,
				//(float)row * scale,			// x 
				pixelHeight + yTrans,		// y
				z,
				//(float)col * scale,			// z
				(float)col * textureU,				// u
				(float)row * textureV,				// v
				normal.X(),
				normal.Y(),
				normal.Z()
			);				// color

			//pVerts[itter].x = x;
			//pVerts[itter].y = pixelHeight + ytrans;
			//pVerts[itter].z = z;
			//pVerts[itter].u = (float)col * textureU;
			//pVerts[itter].v = (float)row * textureV;

			//pVerts[itter++].normal = normal.getNorm(); ignore norms for now
			pVerts[itter + 1].ny = normal.Y();
			pVerts[itter + 1].nx = normal.X();
			pVerts[itter + 1].nz = normal.Z();
			itter++;
		}

		//z += (side) / (side - 1);
		//x = side * .5f;
	}

	//for (int i = 0; i < nverts; i++)
	//{
	//	DebugMsg::out("\n%f, index:%d\t");
	//	float m = pVerts[i].x;
	//	m;

	//}
	//int cellAmount = ntri / 2;
	//cellArray = new CellValues [cellAmount];

	cellArray = new CellValues * [imgWidth - 1];
	for (int i = 0; i < imgWidth - 1; i++)
	{
		cellArray[i] = new CellValues[imgWidth - 1];
	}
	int t = 0;
	for (int i = 0; i < imgWidth - 1; i++)		// row
	{
		for (int j = 0; j < imgWidth - 1; j++)	// col
		{
			cellArray[i][j].max.Y() = pVerts[(i + 1) * imgWidth + j].y;
			//cellArray[i][j].min.Y() = pVerts[(i + 1) * imgWidth + j].y;
			cellArray[i][j].min.Y() = pVerts[(i * imgWidth) + j + 1].y;
			//row*dim+col		//row*dim+col+1		//(row+1)*dim+col

			pTriList[t++].set(i * imgWidth + j, i * imgWidth + j + 1, (i + 1) * imgWidth + j);

			//check for max Y values in vertices
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v0].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v0].y;
			}
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v1].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v1].y;
			}
			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v0].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v0].y;
			}
			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v1].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v1].y;
			}
			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			//cellArray[i][j].max.Y() = cellArray[i][j].max.Y();
			//cellArray[i][j].min.Y() = cellArray[i][j].min.Y();

			cellArray[i][j].max.X() = pVerts[pTriList[t - 1].v2].x;
			cellArray[i][j].max.Z() = pVerts[pTriList[t - 1].v2].z;

			cellArray[i][j].min.X() = pVerts[pTriList[t - 1].v1].x;
			cellArray[i][j].min.Z() = pVerts[pTriList[t - 1].v1].z;
			//grab the Cell's x max and z min
			/*
			vertex 1 (bottom right of cell should be max X and max Z since we're in right handed space)
			vertex 2 (top left of cell should be min X and min Z)
			*/
			//DebugMsg::out("\nVertex %i Pos: x=%f, y=%f, z=%f", i* imgWidth + j, pVerts[0].x, pVerts[0].y, pVerts[0].z);
			//DebugMsg::out("\nVertex %i Pos: x=%f, y=%f, z=%f", (i + 1)* imgWidth + j, pVerts[2].x, pVerts[2].y, pVerts[2].z);

			//DebugMsg::out("\nTriVerts: %d, %d, %d", i* imgWidth + j, i* imgWidth + j + 1, (i + 1)* imgWidth + j);
			//pVerts[0].y = -2.0f;

			//pVerts[2].y = 1.0f;
			//pVerts[3].y = 2.0f;


			//(row+1)*dim+col		//row*dim+col+1		//(row+1)*dim+col+1
			pTriList[t++].set((i + 1) * imgWidth + j, i * imgWidth + j + 1, (i + 1) * imgWidth + j + 1);

			if (cellArray[i][j].max.Y() < pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].max.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			if (cellArray[i][j].min.Y() > pVerts[pTriList[t - 1].v2].y)
			{
				cellArray[i][j].min.Y() = pVerts[pTriList[t - 1].v2].y;
			}

			//cellArray[i][j].max.Y() = cellArray[i][j].max.Y();
			//cellArray[i][j].min.Y() = cellArray[i][j].min.Y();

			//DebugMsg::out("\nTriVerts: %d, %d, %d", (i + 1)* imgWidth + j, i* imgWidth + j + 1, (i + 1)* imgWidth + j + 1);
			//this creates one cell so create the AABB variables here.

			//************************IMPORTANT
			//for getting the correct indices for a cell
			//return Cell(int(-1 * (maxZ - v.Z()) / cellHeight), int((maxX - v.X()) / cellWidth));
			//for loop for finding every Cell
			//[i, j] = [2, 0];
			//for(int x = j of max; j < i + 1; j++)

			//return Cell(int(-1 * (maxZ - v.Z()) / cellHeight), int((maxX - v.X()) / cellWidth));

			//cellArray[i][j].yMax = pVerts[i * imgWidth + j + 1].y;
			//cellArray[i][j].yMin = pVerts[(i + 1) * imgWidth + j].y;

			//DebugMsg::out("\nCell[%d][%d] max = %f, %f, %f", i, j, cellArray[i][j].max.X(), cellArray[i][j].max.Y(), cellArray[i][j].max.Z());
			//DebugMsg::out("\nCell[%d][%d] min = %f, %f, %f", i, j, cellArray[i][j].min.X(), cellArray[i][j].min.Y(), cellArray[i][j].min.Z());

		}
	}


	// Create new terrain instance
	//pModTerrain = new Model(dev, pVerts, (int)nverts, pTriList, (int)ntri);


	tModel = new Model(pVerts, nverts, pTriList, ntri);

	delete[] pVerts;
	delete[] pTriList;

	//pGObj_Terrain = new GraphicsObject_WireframeConstantColor(tModel, ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);

	pGObj_Terrain = new GraphicsObject_TextureFlat(tModel, ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture(textureFile));

	mTerrainScale.set(SCALE, 1.0f, 1.0f, 1.0f);

	mTerrainRot.set(IDENTITY);
	//mTerrainRot *= Matrix(ROT_Y, 3.14159f);

	vTerrainPos.set(0, 0, 0);
	mWorld = mTerrainScale * mTerrainRot * Matrix(TRANS, vTerrainPos);
	pGObj_Terrain->SetWorld(mWorld);

	SubmitDrawRegistration();
}


void TerrainObject::Draw()
{
	//Visualizer::ShowCollisionVolume(*it1, Color::Red);
	//iterate through every cell and show it's AABB
	for (int i = 0; i < imgWidth - 1; i++)
	{
		for (int j = 0; j < imgHeight - 1; j++)
		{
			Visualizer::ShowAABB(cellArray[i][j].min, cellArray[i][j].max, Color::Green);
		}
	}

	//Visualizer::DrawLine(cellArray[0][0].min, cellArray[imgWidth - 2][imgHeight - 2].max, Color::White);
	//tPos.set(6.5f, 0.0f, -5.0f);
	

	//Test to check all corresponding cells from min and max cells
	//for (int i = (int)GOCellMin.X(); i < GOCellMax.X() + 1; i++)
	//{
	//	for (int j = (int)GOCellMax.Z(); j < GOCellMin.Z() + 1; j++)
	//	{
	//		Visualizer::ShowAABB(cellArray[i][j].min, cellArray[i][j].max, Color::Green);
	//	}
	//}

	
	//Visualizer::ShowAABB(cellArray[(int)GOCell.X()][(int)GOCell.Z()].min, cellArray[(int)GOCell.X()][(int)GOCell.Z()].max, Color::Green);
	//Visualizer::ShowAABB(cellArray[(int)GOCell2.X()][(int)GOCell2.Z()].min, cellArray[(int)GOCell2.X()][(int)GOCell2.Z()].max, Color::Green);
	pGObj_Terrain->Render(SceneManager::getCurScene()->GetCurCam());
}

void TerrainObject::SendPosition(Vect pos, float r)
{
	Vect vMax;
	vMax.set(pos.X() + r, pos.Y() + r, pos.Z() + r);
	Vect vMin;
	vMin.set(pos.X() - r, pos.Y() - r, pos.Z() - r);

	float maxZ = imgWidth * scale / 2.0f;
	float maxX = imgWidth * scale / 2.0f;

	//check for max boundaries
	if (vMax.X() >= maxX)
	{
		vMax.X() = maxX - .1f;
	}
	else if (vMax.X() <= -maxX)
	{
		vMax.X() = -maxX + .1f;
	}
	if (vMax.Z() >= maxZ)
	{
		vMax.Z() = maxZ - .1f;
	}
	else if (vMax.Z() <= -maxZ)
	{
		vMax.Z() = -maxZ + .1f;
	}

	//check for min boundaries
	if (vMin.X() >= maxX)
	{
		vMin.X() = maxX - .1f;
	}
	else if (vMin.X() <= -maxX)
	{
		vMin.X() = -maxX + .1f;
	}
	if (vMin.Z() >= maxZ)
	{
		vMin.Z() = maxZ - .1f;
	}
	else if (vMin.Z() <= -maxZ)
	{
		vMin.Z() = -maxZ + .1f;
	}

	float cellSideLen = imgWidth * scale / (imgWidth - 1);
	int row, col;
	row = int(1 * (maxZ + vMax.Z()) / cellSideLen); //row position which is along the Z-axis
	//j = int(-1 * (maxZ - pos.Z()) / cellSideLen); 
	col = int((maxX - vMax.X()) / cellSideLen); //col position which is along the X-axis

	//assert(row > maxZ);

	GOCellMax.set((float)row, 0.0f, (float)col); //Vect.X = i(row) and Vect.Z = j(column)the array of cells goes by row then column so [row][col] x is row, z is col.
	//DebugMsg::out("\n\nMax Pos: %f, %f, %f = Cell: (%f, %f)", vMax.X(), vMax.Y(), vMax.Z(), GOCellMax.X(), GOCellMax.Z());
	//(int(-1 * (maxZ - pos.Z()) / cellHeight), int((maxX - pos.X()) / cellWidth))

	row = int(1 * (maxZ + vMin.Z()) / cellSideLen);
	//j = int(-1 * (maxZ - pos.Z()) / cellSideLen);
	col = int((maxX - vMin.X()) / cellSideLen);

	//assert(row > maxZ);

	GOCellMin.set((float)row, 0.0f, (float)col); //the array of cells goes by row then column so [row][col] or [
	//DebugMsg::out("\nMin Pos: %f, %f, %f = Cell: (%f, %f)", vMin.X(), vMin.Y(), vMin.Z(), GOCellMin.X(), GOCellMin.Z());


}

Vect TerrainObject::GetTerrainPosNormal(Vect pos)
{
	float maxZ = imgWidth * scale / 2.0f;
	float maxX = imgWidth * scale / 2.0f;

	if (pos.X() >= maxX)
	{
		pos.X() = maxX - .1f;
	}
	else if (pos.X() <= -maxX)
	{
		pos.X() = -maxX + .1f;
	}
	if (pos.Z() >= maxZ)
	{
		pos.Z() = maxZ - .1f;
	}
	else if (pos.Z() <= -maxZ)
	{
		pos.Z() = -maxZ + .1f;
	}

	float cellSideLen = imgWidth * scale / (imgWidth - 1);
	int row, col;
	row = int(1 * (maxZ + pos.Z()) / cellSideLen);
	//j = int(-1 * (maxZ - pos.Z()) / cellSideLen);
	col = int((maxX - pos.X()) / cellSideLen);

	//assert(row > maxZ);
	//DebugMsg::out("\nPos: %f, %f, %f = Cell: (%d, %d)", pos.X(), pos.Y(), pos.Z(), row, col);

	Vect v1, v2, v3;
	Vect* vList = tModel->getVectList();
	int offsetRow = 1;
	int offsetCol = 1;
	if (row > imgWidth - 1 || row < 0)
	{
		offsetRow = 0;
	}
	if (col > (imgWidth - 1) || col < 0)
	{
		offsetCol = 0;
	}
	
	v1.set(vList[(row * imgWidth) + col]); //bottom left vertex
	v2.set(vList[(row * imgWidth) + col + offsetCol]); //bottom right vertex
	v3.set(vList[((row + offsetRow) * imgWidth) + col + offsetCol]); //top right vertex
	v1.W() = 0;
	v2.W() = 0;
	v3.W() = 0;
	Vect a = v2 - v1;
	Vect b = v3 - v1;
	Vect cross = a.cross(b);
	cross = cross.norm();

	return cross;

}

float TerrainObject::GetTerrainPosHeight(Vect& pos)
{


	float maxZ = imgWidth * scale / 2.0f;
	float maxX = imgWidth * scale / 2.0f;

	if (pos.X() >= maxX)
	{
		pos.X() = maxX - .1f;
	}
	else if (pos.X() <= -maxX)
	{
		pos.X() = -maxX + .1f;
	}
	if (pos.Z() >= maxZ)
	{
		pos.Z() = maxZ - .1f;
	}
	else if (pos.Z() <= -maxZ)
	{
		pos.Z() = -maxZ + .1f;
	}

	float cellSideLen = imgWidth * scale / (imgWidth - 1);
	int row, col;
	row = int(1 * (maxZ + pos.Z()) / cellSideLen);
	//j = int(-1 * (maxZ - pos.Z()) / cellSideLen);
	col = int((maxX - pos.X()) / cellSideLen);


	////assert(row > maxZ);
	////DebugMsg::out("\nPos: %f, %f, %f = Cell: (%d, %d)", pos.X(), pos.Y(), pos.Z(), row, col);

	Vect v1, v2, v3, v4;
	Vect* vList = tModel->getVectList();
	int offsetRow = 1;
	int offsetCol = 1;
	if (row > imgWidth - 1 || row < 0)
	{
		offsetRow = 0;
	}
	if (col > (imgWidth - 1) || col < 0)
	{
		offsetCol = 0;
	}

	

	v1.set(vList[(row * imgWidth) + col]); //bottom left vertex
	v2.set(vList[(row * imgWidth) + col + offsetCol]); //bottom right vertex
	v3.set(vList[((row + offsetRow) * imgWidth) + col]); //top left vertex
	v4.set(vList[((row + offsetRow) * imgWidth) + col + offsetCol]); //top right vertex
	
	//pos.set(v4);

	const Vect dir = pos - v1;
	Vect A, B, C;
	A = v1;
	if ((-1 * dir.X()) < dir.Z())
	{
		B = v4;
		C = v3;
	}
	else
	{
		B = v2;
		C = v4;
	}

	Vect d0 = B - A;
	Vect d1 = C - B;
	Vect d2 = pos - A;

	float a = d0.dot(d0);
	float b = d1.dot(d0);
	float c = d1.dot(d1);
	float d = d2.dot(d0);
	float e = d2.dot(d1);

	float beta = (d * c - b * e) / (a * c - b * b);
	float gamma = (a * e - d * b) / (a * c - b * b);

	float Q = A.Y() + beta * (B.Y() - A.Y()) + gamma * (C.Y() - B.Y());

	return Q;
}



void TerrainObject::TestIntersection(GameObject& go)
{
	//bool b = LediriMathTools::Intersect(go.GetCollisionSphere(), GOCellMin, GOCellMax);
	//DebugMsg::out("\ntest = %d", b);

	for (int i = (int)GOCellMin.X(); i < GOCellMax.X() + 1; i++)
	{
		for (int j = (int)GOCellMax.Z(); j < GOCellMin.Z() + 1; j++)
		{
			bool b = LediriMathTools::Intersect(go.GetCollisionSphere(), cellArray[i][j].min, cellArray[i][j].max);
			if (b)
			{
				//yellow = intersecting with BSphere
				//Visualizer::ShowAABB(cellArray[i][j].min, cellArray[i][j].max, Color::Yellow);
				b = LediriMathTools::Intersect(&go, cellArray[i][j].min, cellArray[i][j].max);
				if (b)
				{
					//red = intersecting with GO CollisionVolume
					//Visualizer::ShowAABB(cellArray[i][j].min, cellArray[i][j].max, Color::Red);
				}
			}
			else
			{
				//blue is any cell within the GO's initial range but not intersecting with the BSphere
				//Visualizer::ShowAABB(cellArray[i][j].min, cellArray[i][j].max, Color::Blue);
			}
		}
	}
}

Vect TerrainObject::GetPlanePos(Vect pos)
{
	float maxZ = imgWidth * scale / 2.0f;
	float maxX = imgWidth * scale / 2.0f;

	if (pos.X() >= maxX)
	{
		pos.X() = maxX - .1f;
	}
	else if (pos.X() <= -maxX)
	{
		pos.X() = -maxX + .1f;
	}
	if (pos.Z() >= maxZ)
	{
		pos.Z() = maxZ - .1f;
	}
	else if (pos.Z() <= -maxZ)
	{
		pos.Z() = -maxZ + .1f;
	}

	float cellSideLen = imgWidth * scale / (imgWidth - 1);
	int row, col;
	row = int(1 * (maxZ + pos.Z()) / cellSideLen);
	//j = int(-1 * (maxZ - pos.Z()) / cellSideLen);
	col = int((maxX - pos.X()) / cellSideLen);

	//assert(row > maxZ);
	//DebugMsg::out("\nPos: %f, %f, %f = Cell: (%d, %d)", pos.X(), pos.Y(), pos.Z(), row, col);

	Vect v1, v2, v3;
	Vect* vList = tModel->getVectList();
	int offsetRow = 1;
	int offsetCol = 1;
	if (row > imgWidth - 1 || row < 0)
	{
		offsetRow = 0;
	}
	if (col > (imgWidth - 1) || col < 0)
	{
		offsetCol = 0;
	}

	v1.set(vList[(row * imgWidth) + col]); //bottom left vertex
	v2.set(vList[(row * imgWidth) + col + offsetCol]); //bottom right vertex
	v3.set(vList[((row + offsetRow) * imgWidth) + col + offsetCol]); //top right vertex
	v1.W() = 0;
	v2.W() = 0;
	v3.W() = 0;
	DebugMsg::out("\n\nv1: %f, %f, %f", v1.X(), v1.Y(), v1.Z());
	DebugMsg::out("\nv2: %f, %f, %f", v2.X(), v2.Y(), v2.Z());
	DebugMsg::out("\nv3: %f, %f, %f", v3.X(), v3.Y(), v3.Z());
	Vect a = v2 - v1;
	Vect b = v3 - v1;
	Vect cross = a.cross(b);
	cross = cross.norm();

	//L(t') = s + tv = ((p_0 - s) dot n) / v dot n) * v
	//n = cross
	Vect s = pos;
	s.Y() = maxHeight;
	Vect p_0 = (v3 - v1) * 0.5f;
	//DebugMsg::out("\nP_0: %f, %f, %f", p_0.X(), p_0.Y(), p_0.Z());
	Vect dir = Vect(0, -1.0f, 0);
	//dir = (p_0 - s).norm();
	Vect intersect = s + (((p_0 - s).dot(cross) / dir.dot(cross)) * dir);
	return p_0;
}

TerrainObject::~TerrainObject()
{
	if (cellArray != nullptr)
	{
		for (int i = 0; i < imgWidth - 1; i++)
		{
			delete[] cellArray[i];
		}
		delete[] cellArray;
		delete pGObj_Terrain;
		delete tModel;
	}


}


