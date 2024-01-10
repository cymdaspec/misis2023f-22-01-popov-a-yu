/// \file Реализация методов, объявленных в .h файле

#include "automations_constructor.h";


namespace vm = vimaker;

ch::Sequence<float> vm::Automation::makeSequence()
{
	ch::Sequence<float> result = ch::Sequence<float>(0);
	for (int i = 1; i < vm::Automation::getAmountOfPoints(); i++)
	{
		result.then<ch::Hold>(0, 0.0f);
		result.then<ch::RampTo>(1, vm::Automation::getTimecode(i) - vm::Automation::getTimecode(i-1), vm::Automation::getEase(i-1));
	}
	return result;
};

int vm::Automation::getAmountOfPoints()
{
	return vm::Automation::timecodes.size();
};

void vm::Automation::setTimecode(float time)
{
	timecodes.push_back(time);
}

void vm::Automation::setEase(std::function<float(float)> func)
{
	eases.push_back(func);
}

float vm::Automation::getTimecode(int i)
{
	return timecodes[i];
}

std::function<float(float)> vm::Automation::getEase(int i)
{
	return eases[i];
}

std::function<float(float)> vm::Automation::inputFormatEase(std::string ease)
{
	std::unordered_map<std::string, std::function<float(float)>> eases_map;

	eases_map["none"] = ch::easeNone;
	eases_map["None"] = ch::easeNone;

	eases_map["EaseInQuad"] = ch::easeInQuad;
	eases_map["EaseOutQuad"] = ch::easeOutQuad;
	eases_map["EaseInOutQuad"] = ch::easeInOutQuad;

	eases_map["EaseInCubic"] = ch::easeInCubic;
	eases_map["EaseOutCubic"] = ch::easeOutCubic;
	eases_map["EaseInOutCubic"] = ch::easeInOutCubic;

	eases_map["EaseInQuart"] = ch::easeInQuart;
	eases_map["EaseOutQuart"] = ch::easeOutQuart;
	eases_map["EaseInOutQuart"] = ch::easeInOutQuart;

	eases_map["EaseInQuint"] = ch::easeInQuint;
	eases_map["EaseOutQuint"] = ch::easeOutQuint;
	eases_map["EaseInOutQuint"] = ch::easeInOutQuint;

	eases_map["EaseInSine"] = ch::easeInSine;
	eases_map["EaseOutSine"] = ch::easeOutSine;
	eases_map["EaseInOutSine"] = ch::easeInOutSine;

	eases_map["EaseInExpo"] = ch::easeInExpo;
	eases_map["EaseOutExpo"] = ch::easeOutExpo;
	eases_map["EaseInOutExpo"] = ch::easeInOutExpo;

	eases_map["EaseInCirc"] = ch::easeInCirc;
	eases_map["EaseOutCirc"] = ch::easeOutCirc;
	eases_map["EaseInOutCirc"] = ch::easeInOutCirc;

	if (eases_map.find(ease) != eases_map.end())
		return eases_map[ease];
	else
		throw std::invalid_argument("Received wrong ease input");
}

void vm::Automation::inputFromFile(std::string filePath)
{
	std::fstream inputFileStream;
	std::string currentWord;

	inputFileStream.open(filePath.c_str());

	while (inputFileStream >> currentWord)
	{
		if (std::isdigit(currentWord[0]))
		{
			vm::Automation::setTimecode(stoi(currentWord));
		}
		else
		{
			vm::Automation::setEase(vm::Automation::inputFormatEase(currentWord));
		}
	}
}