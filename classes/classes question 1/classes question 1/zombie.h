#ifndef ZOMBIE_H
#define ZOMBIE_H
#include<string>


class Zombie{
public:
	Zombie();
	Zombie(std::string name, std::string job, int hp, int att);
	~Zombie();
	void setName(std::string name);
	std::string getName();
	void setHealth(int hp);
	int getHealth();
	void setAttack(int att);
	int getAttack();
	void setJob(std::string job);
	std::string getJob();
private:
	std::string m_name;
	std::string m_job;
	int m_hp;
	int m_attack;
};
#endif
