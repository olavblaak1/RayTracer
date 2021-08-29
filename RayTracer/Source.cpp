#include <fstream>
#include <limits>

#define HEIGHT 16
#define WIDTH 16

int main() {
	std::ofstream first_image("image.ppm");
	first_image << "P6\n";
	first_image << HEIGHT << '\n';
	first_image << WIDTH << '\n';
	first_image << UCHAR_MAX;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			first_image << 15 * i << ' ' << 15 * j << ' ' << 0 << ' ';
		}
		first_image << '\n';
	}
}