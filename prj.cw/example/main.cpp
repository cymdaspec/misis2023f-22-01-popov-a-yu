#include "../src/automations_constructor.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <iostream>
#include <fstream>

// ������ ������������� ���������� Automations Constructor.
// 
// ������� ��������� �������� ����� ��������� ������ ���� ����� .txt ���� (� ����������� �� isInputConsole)
// ��������� ����������� � �� ������ �� ��������� ������������������ ch::Sequence, 
// � ������� ������� �������� ������ ����� ���������� SFML.
// 
// ����������� ������ ��������� �������� ���� � ����������� �������� �������������
// � ������������ ���������� � .png (� ����������� �� saveImage)
// 
// �������� ������ ��� ������� � ���� ���������� � ����������� ��� ������� �������������

const bool isInputConsole = false;
const bool saveImage = true;

//��������� ������������������ � ������������ ���������� ����������� ����� SFML
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
	vimaker::Automation au; //�������� ������� �������������

	int pointsAmount; //��� ����������� �����
	float timeCode;
	std::string easeType;

	//���� ������
	if (isInputConsole)
	{
		std::cout << "Enter amount of points" << std::endl;
		std::cin >> pointsAmount;
		std::cout << "Timecode for first point is always 0" << std::endl;

		for (int i = 0; i < pointsAmount - 1; i++)
		{
			std::cout << "Enter " << i + 1 << " type of ease" << std::endl;
			std::cin >> easeType;
			std::cout << "Enter " << i + 2 << " timecode" << std::endl;
			std::cin >> timeCode;

			au.setTimecode(timeCode);
			au.setEase(au.inputFormatEase(easeType));
		}
	}
	else
	{
		au.inputFromFile("../prj.cw/example/input.txt");
	}

	//�������� ������������ �������� �������������
	std::cout << "Automation key timecodes are: ";
	for (int i = 0; i < au.getAmountOfPoints(); i++)
	{
		std::cout << au.getTimecode(i) << " ";
	}
	std::cout << "\n\n";

	//���������� ������������������ sequence �� ������ ��������� ������������� au
	choreograph::Sequence<float> sequence = au.makeSequence();

	//�������� ������������ ���������� ������������������ sequence �� ������ ��������� ������������� au
	std::cout << "Sequence start value = " << sequence.getValue(0) << "\n"; 
	std::cout << "Sequence end value = " << sequence.getValue(sequence.getDuration()) << "\n";
	std::cout << "Sequence duration = " << sequence.getDuration() << "\n";

	//������������ ����������� ������������������ sequence
	drawAutomationGraph(800, 600, sequence, saveImage);

	return 0;
}