#include <iostream>
#include <vector>
#include <memory>

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
		virtual std::shared_ptr<IProduct> factoryMethod() = 0;
};

class CreatorA : public ICreator {
	public:
                std::shared_ptr<IProduct> factoryMethod() { return std::dynamic_pointer_cast<IProduct>(std::make_shared<ProductA>()); }
};

class CreatorB : public ICreator {
	public:
                std::shared_ptr<IProduct> factoryMethod() { return std::make_shared<ProductB>(); }
};

int main(int argc, char* argv[])
{
	std::vector<std::shared_ptr<ICreator> > factory(2);
	factory[0] = std::make_shared<CreatorA>();
	factory[1] = std::make_shared<CreatorB>();
	
	factory[0]->factoryMethod()->getName();
	factory[1]->factoryMethod()->getName();
	return 0;
}
