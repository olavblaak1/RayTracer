#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>
#include <fstream>
#include <exception>

color ray_color(const ray& r);

int main(int argc, char* argv[]) {
	if (argc != 2)
		throw std::invalid_argument("Correct usage: ./a.exe [filename]");


	const char* filename = argv[1];
	try {
		std::ofstream image(filename);
		image.exceptions(std::fstream::failbit | std::fstream::badbit);

		// Define image parameters

		const float aspect_ratio = 16.0f / 9.0f;
		const float height = 1080.0f;
		const float width = 1920.0f;
		const int MAX_COLORS = 255;

		// Define viewport

		const float viewport_height = 2.0f;
		const float viewport_width = viewport_height * aspect_ratio;
		const float focal_length = 1.0f;

		const point3 origin(0,0,0);
		const vec3 horizontal(viewport_width, 0, 0);
		const vec3 vertical(0, viewport_height, 0);
		const vec3 top_left_corner = origin + vertical / 2 - horizontal / 2 - vec3(0, 0, 0-focal_length);

		// Write header
		image << "P3\n";
		image << (int)width << '\n';
		image << (int)height << '\n';
		image << MAX_COLORS << '\n';

		// Write image
		for (int i = 0; i < height; i++) {
			std::cerr << "\rScanlines remaining: " << height - i << ' ' << std::flush;
			for (int j = 0; j < width; j++) {
				float u = i / (height - 1);
				float v = j / (width - 1);
				ray current_ray(origin, top_left_corner + v * horizontal - u * vertical - origin);
				write_pixel(image, ray_color(current_ray));
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


color ray_color(const ray& r) {
	vec3 unit_direction = unit_vector(r.direction());
	auto t = 0.5f * (unit_direction.y() + 1.0f);
	return (1.0f - t) * color(1.0f, 1.0f, 1.0f) + t * color(0.5f, 0.7f, 1.0f);
}