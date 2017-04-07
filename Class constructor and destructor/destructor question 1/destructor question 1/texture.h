#include<string>

class Texture{
public:
	Texture(char *aFilepath, int aWidth, int aHeight, int aBytesPerPixel){
		int pathLen = strlen(aFilepath);
		filepath = new char[pathLen + 1];
		strcpy(filepath, aFilepath);

		width = aWidth;
		height = aHeight;

		pixelData = new char[width * height * aBytesPerPixel];
	}

	~Texture(){
		delete[] filepath;
		delete[] pixelData;
	}

	char *filepath;
	char *pixelData;
	int width;
	int height;
};