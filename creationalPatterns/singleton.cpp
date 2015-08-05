#include <cstddef>
#include <iostream>

class Singleton {
	protected:
		int num;
		Singleton() { num = 0; }
		static Singleton* object;
	public:
		static Singleton* getInstance() {
			if( !object )
				object = new Singleton();

			return object;
		}
		
		int getNum() { return object->num; }
		void setNum(int i) { object->num = i; }
};

Singleton* Singleton::object = NULL;


int main(int argc, char* argv[]) 
{
	std::cout << Singleton::getInstance()->getNum() << std::endl;
	Singleton::getInstance()->setNum(2);
	std::cout << Singleton::getInstance()->getNum() << std::endl;
	return 0;
}
