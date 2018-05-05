#include <iostream>
#include <vector>
#include <memory> 

class Lunch {
	private:
		void sit() { std::cout << "Got the seat" << std::endl; }
		void eat() { std::cout << "eating...." << std::endl; }
	protected:	
		virtual void order() = 0;
	public:
		void haveLunch() {
			std::cout << std::endl;
			sit();
			std::cout << "Template method :  ";
			order();
			eat();
			std::cout << std::endl;
		}
};

class Noodle : public Lunch {
	protected:
		void order() {
			std::cout << "I will have a ramen" << std::endl;
		}
};

class Drink : public Lunch {
	protected:
		void order() {
			std::cout << "I will have an ice tea" << std::endl;
		}
};

int main(int argc, char* argv[]) 
{
        std::shared_ptr<Lunch> me  = std::make_shared<Noodle>();		
	me->haveLunch();	

	me = std::make_shared<Drink>();
	me->haveLunch();
}
