#include "../src/automations_constructor.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>

// Пример использования библиотеки Automations Constructor.
// 
// Входные параметры подаются через командную строку либо через .txt файл (в зависимости от isInputConsole)
// Параметры считываются и на основе их создается последовательность ch::Sequence, 
// с помощью которой строится график через библиотеку SFML.
// 
// Результатом работы программы является окно с построенным графиком автоматизации
// и опциональное сохранение в .png (в зависимости от saveImage)
// 
// Тестовые данные уже введены в файл параметров и изображение для примера сгенерировано

bool isInputConsole = false;
bool saveImage = true;

//Отрисовка последовательности и опциональное сохранение изображения через SFML
void drawAutomationGraph(int windowWidth, int windowHeight, const ch::Sequence<float> sequence, bool saveImage) {

	sf::RenderTexture renderTexture;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Automation Graph");
	window.clear(sf::Color::White);
	if (saveImage)
	{
		renderTexture.create(windowWidth, windowHeight);
		renderTexture.clear(sf::Color::White);
	}
	const float totalDuration = sequence.getDuration();
	const float step = 0.1f;

	sf::View view(sf::FloatRect(0.0f, 0.0f, totalDuration, 1.0f));
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	view.setSize(totalDuration, -1.0f);

	if (saveImage)
		renderTexture.setView(view);
	window.setView(view);

	sf::Vector2f startPoint(0.0f, sequence.getValue(0));

	for (float time = 0.0f; time <= totalDuration; time += step) {

		sf::Vector2f endPoint(time, sequence.getValue(time));
		sf::Vertex line[] = {
			sf::Vertex(startPoint, sf::Color::Black),
			sf::Vertex(endPoint, sf::Color::Black)
		};
		window.draw(line, 2, sf::Lines);
		if(saveImage) renderTexture.draw(line, 2, sf::Lines);

		startPoint = endPoint;
	}
	window.display();
	if(saveImage) renderTexture.display();

	if (saveImage)
	{
		sf::Texture texture = renderTexture.getTexture();
		sf::Image picture = texture.copyToImage();
		picture.saveToFile("../prj.cw/example/automation_graph.png");
		std::cout << "Image saved";
	}
	
	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
}

int main()
{
	au::Automation a; //Создание объекта автоматизации

	int pointsAmount; //Для консольного ввода
	float currentTimeCode;
	std::string currentEaseType;

	std::cout << "Enter type of input you want to use\n 0. Text file\n 1. Console \n";
	std::cin >> isInputConsole;
	std::cout << "\n";
	//Ввод данных
	if (isInputConsole)
	{
		std::cout << "Enter amount of points\n";
		std::cin >> pointsAmount;
		std::cout << "\n";
		std::cout << "Timecode for first point is always 0\n";

		for (int i = 0; i < pointsAmount - 1; i++)
		{
			std::cout << "Enter " << i + 1 << " type of ease\n";
			std::cin >> currentEaseType;
			std::cout << "\n";
			std::cout << "Enter " << i + 2 << " timecode\n";
			std::cin >> currentTimeCode;

			a.setTimecode(currentTimeCode);
			a.setEase(a.inputFormatEase(currentEaseType));
		}
	}
	else
	{
		a.inputFromFile("../prj.cw/example/input.txt");
	}

	std::cout << "\n";

	//Проверка правильности создания автоматизации
	std::cout << "Automation key timecodes are: ";
	for (int i = 0; i < a.getAmountOfPoints(); i++)
	{
		std::cout << a.getTimecode(i) << " ";
	}
	std::cout << "\n\n";

	//Построение последовательности sequence на основе созданной автоматизации au
	choreograph::Sequence<float> sequence = a.makeSequence();

	//Проверка правильности построения последовательности sequence на основе созданной автоматизации au
	std::cout << "Sequence start value = " << sequence.getValue(0) << "\n"; 
	std::cout << "Sequence end value = " << sequence.getValue(sequence.getDuration()) << "\n";
	std::cout << "Sequence duration = " << sequence.getDuration() << "\n";
	
	std::cout << "\n";

	std::cout << "Would you like to save image after drawing?\n 0. Just draw\n 1. Save\n";
	std::cin >> saveImage;
	std::cout << "\n";
	//Визуализация построенной последовательности sequence
	drawAutomationGraph(800, 600, sequence, saveImage);
	
	std::cout << "Thanks for using!";

	return 0;
}