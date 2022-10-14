#include"Animal.h"
using namespace std;

int main()
{
	IAnimal* ptr = nullptr;
	// ptr - интерфейсная ссылка
	ptr = new Parrot("Ara", 2, "Africa");	
	ptr->Eat();
	ptr->Move();
	Parrot* p = static_cast<Parrot*>(ptr);
	p->Print();
	delete ptr;

	ptr = new Human();
	ptr->Eat();
	ptr->Move();
	delete ptr;
	IFly* ifly = p;
	ifly->Fly();

}