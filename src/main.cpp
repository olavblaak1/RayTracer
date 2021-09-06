#include "vec3.h"
#include "pixel.h"

#include <iostream>
#include <fstream>
#include <exception>



int main(int argc, char* argv[]) {
	if (argc != 2)
		throw std::invalid_argument("Correct usage: ./a.exe [filename]");


	const char* filename = argv[1];
	try {
		std::ofstream image(filename);
		image.exceptions(std::fstream::failbit | std::fstream::badbit);

		const unsigned char HEIGHT = 255u;
		const unsigned char WIDTH = 255u;
		const unsigned char UNSIGNED_CHAR_MAX = 255u;


		// Write header
		image << "P3\n";
		image << (int)HEIGHT << '\n';
		image << (int)WIDTH << '\n';
		image << (int)UNSIGNED_CHAR_MAX << '\n';

		// Write image
		for (int i = 0; i < HEIGHT; i++) {
			std::cerr << "\rScanlines remaining: " << HEIGHT - i << ' ' << std::flush;
			for (int j = 0; j < WIDTH; j++) {
				Pixel rgb(float(j) / WIDTH, float(i) / HEIGHT, 0.25);
				write_pixel(image, rgb);
			}
			image << '\n';
		}
		std::cout << "Image is ready.";
		image.close();
	}
	catch (std::ios_base::failure e) {
		std::cerr << "Could not open/read/write file, please try again.";
	}
	catch (...) {
		std::cerr << "Something went wrong, please try again.";
	}
}