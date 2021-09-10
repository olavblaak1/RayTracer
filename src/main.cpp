#include "constants_rt.h"
#include "color.h"
#include "hittables.h"
#include "sphere.h"


#include <iostream>
#include <fstream>
#include <exception>




color ray_color(const ray& r, const hittables& world);

/*====================================================================*/
//                EXAMPLE OF RAYTRACE WITH A SPHERE					  //
/*====================================================================*/

/*
	The equation of a sphere in 3D is:						x^2 + y^2 + z^2 = r^2
	or, if the sphere's center is not the origin:			(x-c1)^2 + (y-c2)^2 + (z-c3)^2 = r^2			(1)

	To raytrace this object, we must check for which t our ray P(t) = A + bt satisfies the above equation,
	thus intersecting with the sphere (the ray hits the sphere) and giving that pixel a different color.

	Our x, y and z coordinates will depend on P(t), Take C as the point at the center of the circle, then
	(x-c1)^2 + (y-c2)^2 + (z-c3)^2 = (P(t)-C) � (P(t)-C)

	Equation (1) thus simplifies to:							(P(t)-C) � (P(t)-C) = r^2
	simplifying and substituting P(t) for A + bt this becomes:	(bt)^2 + 2bt � (A-C) + (A-C)^2 - r^2 = 0	(2)
	with a^2 meaning a�a if a is a vector.

	We can easily find for which t (2) is satisfied by calculating the discriminant,
	if discriminant < 0, then the ray did not hit the sphere and we do not have to draw anything
	if discriminant > 0, the ray hit the sphere and we must change that pixels color
*/
int main(int argc, char* argv[]) {
	//if (argc != 2)
	//	throw std::invalid_argument("Correct usage: ./a.exe [filename]");


	const char* filename = "image.ppm";
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
		const vec3 top_left_corner = origin + vertical / 2 - horizontal / 2 - vec3(0, 0, focal_length);

		// Write header

		image << "P3\n";
		image << (int)width << '\n';
		image << (int)height << '\n';
		image << MAX_COLORS << '\n';

		// Add objects to the world (spheres, cubes, ...)

		hittables world;
		world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
		world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

		// Write image
		for (int i = 0; i < height; i++) {
			std::cerr << "\rScanlines remaining: " << height - i << ' ' << std::flush;
			for (int j = 0; j < width; j++) {
				float u = i / (height - 1);
				float v = j / (width - 1);
				ray current_ray(origin, top_left_corner + v * horizontal - u * vertical - origin);
				write_pixel(image, ray_color(current_ray, world));
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


color ray_color(const ray& r, const hittables& world) {
	hit_record rec;
	if(world.hit(r, 0, infinity, rec))
		return 0.5 * (rec.normal + color(1, 1, 1));

	vec3 unit_direction = unit_vector(r.direction());
	const float t = 0.5f * (unit_direction.y() + 1.0f);
	return (1.0f - t) * color(1.0f, 1.0f, 1.0f) + t * color(0.5f, 0.7f, 1.0f);
}