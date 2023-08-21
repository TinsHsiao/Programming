#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main(void)
{
	// Open Image File
	ifstream ifile("a.bmp", ios::binary);
	
	// Read Header
	unsigned char header[54];
	ifile.read((char*)&header, sizeof(header));		
 	int width = header[18] + header[19]*256 + header[20]*256*256 + header[21]*256*256*256;    
 	int height = header[22] | header[23] << 8 | header[24] << 16 | header[25] << 24; 	
	int bits_px = header[28] | header[29] << 8;
	
	cout << "Original Image: " << width << "x" << height << "x" << bits_px << endl;	
	
	// Read RGB Data
	unsigned char rgb[height][width][bits_px/8];
	ifile.read((char*)&rgb, sizeof(rgb));
	ifile.close();
	
	// Image Processing
	unsigned char rgb2[height][width][bits_px/8];
	for(int i=0; i<height; i++)
		for(int j=0; j<width; j++)
			for(int k=0; k<bits_px/8; k++)
				rgb2[i][j][k] = rgb[i][j][k];

 	width = width;
 	header[18] = width % 256;
 	header[19] = width / 256 % 256;
 	header[20] = width / 256 / 256 % 256;
 	header[21] = width / 256 / 256 / 256 % 256;;
    
 	height = height;
 	header[22] = height &0x000000ff;
 	header[23] = (height >> 8) &0x000000ff;
 	header[24] = (height >> 16) &0x000000ff;
 	header[25] = (height >> 24) &0x000000ff;
	 	
	int file_size = width * height * bits_px/8 + 54;
 	header[2] = file_size &0x000000ff;
 	header[3] = (file_size >> 8) & 0x000000ff;
	header[4] = (file_size >> 16) & 0x000000ff;
	header[5] = (file_size >> 24) & 0x000000ff; 
	
	cout << "New Image: " << width << "x" << height << "x" << bits_px << endl;	
	
	// Write New Image
	ofstream of1("b.bmp", ios::binary);	
	of1.write((char*)&header, sizeof(header));
	for(int i=0; i<height; i++)
		for(int j=0; j<width; j++)
			for(int k=0; k<bits_px/8; k++)
				of1.write((char*)&rgb2[i][j][k], sizeof(rgb2[i][j][k]));
	of1.close();
	
	return 0;
}
