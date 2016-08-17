#pragma once
#include <GL\glew.h>
#include <windows.h>
#include <SDL2\SDL.h>
#include <SDL2\SDL_opengl.h>
#include <glm\common.hpp>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <iostream>

	struct coordinate
	{
		float x, y, z;
		coordinate(float a, float b, float c);
	};
	struct face
	{
		int facenum;    //the number of the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it), it's used for the normal vectors
		bool four;              //if true, than it's a quad else it's a triangle
		int faces[4];   //indexes for every vertex, which makes the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
		int texcoord[4];        //indexes for every texture coorinate that is in the face (it's start from 1 not 0, so if you use it as an index, subtract 1 from it)
		int mat;                                        //the index for the material, which is used by the face
		face(int facen, int f1, int f2, int f3, int t1, int t2, int t3, int m);        //constuctor for triangle
		face(int facen, int f1, int f2, int f3, int f4, int t1, int t2, int t3, int t4, int m);  //-"- for quad
	
	};

	struct material
	{
		std::string name;
		float alpha, ns, ni;
		float dif[3], amb[3], spec[3];
		int illum;
		int texture;
		material(const char* na, float al, float n, float ni2, float* d, float* a, float* s, int i, int t);
	};

	struct texcoord
	{
		float u, v;
		texcoord(float a, float b);

	};
	
	class objloader
	{
	
		
		void clean();
		std::vector<std::string*> coord;        //every line of code from the obj file
		std::vector<coordinate*> vertex;        //all vertexes
		std::vector<face*> faces;                                       //all faces
		std::vector<coordinate*> normals;       //all normal vectors
		std::vector<unsigned int> texture;//the id for all the textures (so we can delete the textures after use it)
		std::vector<unsigned int> lists;        //the id for all lists (so we can delete the lists after use it)
		std::vector<material*> materials;       //all materials
		std::vector<texcoord*> texturecoordinate;
		bool ismaterial, isnormals, istexture;
		unsigned int loadTexture(const char* filename);

	public:
		int loader(const char* filename);
		objloader();
		~objloader();


    };

