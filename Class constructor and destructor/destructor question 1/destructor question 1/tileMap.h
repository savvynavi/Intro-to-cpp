class TileMap{
public:
	struct Tile{ int x, y; int tileValue; };
	TileMap(int aWidth, int aHeight){
		width = aWidth;
		height = aHeight;

		tiles = new Tile*[height];

		for(int rowIndex = 0; rowIndex < height; ++rowIndex){
			tiles[rowIndex] = new Tile[width];
		}
	}

	~TileMap(){
		for(int i = 0; i < height; ++i){
			delete tiles[i];
		}
		delete[] tiles;
	}

	int width;
	int height;
	Tile **tiles;
};