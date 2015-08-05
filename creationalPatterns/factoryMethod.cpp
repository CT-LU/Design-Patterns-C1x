#include <iostream>
#include <vector>

class IProduct {
	public:
		virtual void getName() = 0;
};

class ProductA : public IProduct {
	public:
		void getName() { std::cout << "Poduct A created..." << std::endl; }

};

class ProductB : public IProduct {
	public:
		void getName() { std::cout << "Poduct B created..." << std::endl; }
};

class ICreator {
	public:
		virtual IProduct* factoryMethod() = 0;
};

class CreatorA : public ICreator {
	public:
		IProduct* factoryMethod() { return new ProductA(); }
};

class CreatorB : public ICreator {
	public:
		IProduct* factoryMethod() { return new ProductB(); }
};

int main(int argc, char* argv[])
{
	std::vector<ICreator*> factory(2);
	factory[0] = new CreatorA();
	factory[1] = new CreatorB();
	
	factory[0]->factoryMethod()->getName();
	factory[1]->factoryMethod()->getName();
	return 0;
}
