
class Player{
public:
	struct Bullet{ float x, y; };

	Player(int maxAmmo){
		bullets = new Bullet[maxAmmo];
		ammo = 0;
		health = 0;
		maxHealth = 100;
	}

	~Player(){ delete[] bullets; }
	int health;
	int maxHealth;
	int ammo;
	int maxAmmo;
	Bullet *bullets;
};

