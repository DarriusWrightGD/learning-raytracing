#include <iostream>
#include <fstream>


void main() {
	auto rows = 200;
	auto columns = 200;

	std::ofstream outputImageStream;
	outputImageStream.open("image.ppm", std::ofstream::out | std::ofstream::trunc);

	outputImageStream << "P3\n" << rows << " " << columns << "\n255\n";

	for (int  column= columns-1 ;   column >= 0; column--)
	{
		for (int row = 0; row < rows; row++)
		{
			float r = static_cast<float>(row) / static_cast<float>(rows);
			float g = static_cast<float>(column) / static_cast<float>(columns);

			int ir = static_cast<int>(255.99f*r);
			int ig = static_cast<int>(255.99f*g);
			int ib = static_cast<int>(255.99f*0.2f);

			outputImageStream << ir << " " << ig << " " << ib << "\n";
		}
	}

	outputImageStream.close();
}