#include <vector>
#include <iostream>
#include <memory>


class IObserver : public std::enable_shared_from_this<IObserver> {
	public:
		void virtual update(int value) = 0;
};	

class StockMarket {
	private:
		int _value;
		std::vector<std::shared_ptr<IObserver>> _observers;
		
		void notify() {
			for(int i = 0; i < _observers.size(); i++) {
				_observers[i]->update(_value);
			}
		}
	public:
		void setValue(int i) {
			_value = i;
			notify();
		}

		void pushObserver(std::shared_ptr<IObserver> obs) {
			_observers.push_back(obs);
		}

};

class Investor1 : public IObserver {
	private:
		std::string _name;
	public:
                void invest(StockMarket& s){
			s.pushObserver(shared_from_this());
			_name = "Joe";
		}

		void update(int value) {
			std::cout << _name << " say: ";
			if(value > 30)
				std::cout << "I sell my stocks..." << std::endl; 
			else
				std::cout << "keep observing... " << std::endl; 
		}
};

class Investor2 : public IObserver {
	private:
		std::string _name;
	public:	
		void invest(StockMarket& s) {
			s.pushObserver(shared_from_this());
			_name = "John";
		}

		void update(int value) {
			std::cout << _name << " say: ";
			if(value < 30)
				std::cout << "I buy the stocks..." << std::endl; 
			else
				std::cout << "keep observing... " << std::endl; 
		}
};

int main(int argc, char* argv[]) 
{
	StockMarket s;
        std::shared_ptr<Investor1> i1 = std::make_shared<Investor1>();
        std::shared_ptr<Investor2> i2 = std::make_shared<Investor2>();
        i1->invest(s);
        i2->invest(s);
	
	s.setValue(31);
	s.setValue(30);
	s.setValue(29);

	return 1;
}
