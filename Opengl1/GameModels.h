#ifndef GAME_MODELS_H_
#define GAME_MODELS_H_


#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"
#include "VertexFormat.h"
#include <vector>
#include <map>
#include <string>

namespace Models
{

	struct Model
	{
		unsigned int vao;
		std::vector<unsigned int> vbos;
		
		Model(){}
	};


	class GameModels
	{

	public:
		GameModels(){}
		~GameModels(){}

		void createTriangleModel(const std::string& gameModelName );
		void deleteModel(const std::string& gameModelName);
		unsigned int getModel(const std::string& gameMdelName);

	private:
		std::map<std::string, Model> gameModelList;
	};


}






#endif