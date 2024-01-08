#pragma once

#include "modules/choreograph/Choreograph.h" as ch;
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <iostream>
#include <fstream>

namespace vimaker
{
	class Automation
	{
		private:
				
				//Вектор хранящий таймкоды каждой точки
				//Первый таймкод всегда будет находиться в нуле
				
				std::vector<float> timecodes = { 0 };

				//Вектор хранящий функции сглаживания из библиотеки choreograph

				std::vector<std::function<float(float)>> eases;


		public:

			/// Геттеры и сеттеры для значений векторов и количества функций гладкости
			
			void setTime (float time);

			void setEase(std::function<float(float)> func);

			float getTime(int i);

			std::function<float(float)> getEase(int i);

			int getAmountOfPoints();

			/// Метод для чтения данных из .txt файла
						
			void inputFromFile(std::string filePath);

			/// Построение последовательности

			ch::Sequence<float> makeAutomation();

			/// Преобразование ввода в функции сглаживания из choreograph

			std::function<float(float)> inputFormatEase(std::string ease);
	};
}