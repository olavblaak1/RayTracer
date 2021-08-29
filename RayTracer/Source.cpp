#include <fstream>
#include <limits>

#define UCHAR_MAX 255
#define HEIGHT 255
#define WIDTH 255

int main() {
	std::ofstream first_image("image.ppm");
	int step_height = UCHAR_MAX / HEIGHT;
	int step_width = UCHAR_MAX / WIDTH;
	first_image << "P3\n";
	first_image << HEIGHT << '\n';
	first_image << WIDTH << '\n';
	first_image << UCHAR_MAX << '\n';
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			first_image << step_height * i << ' ' << step_width * j << ' ' << 0 << ' ';
		}
		first_image << '\n';
	}
}