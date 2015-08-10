#include <vector>
#include <iostream>


class IObserver {
	public:
		void virtual update(int value) = 0;
};	

class StockMarket {
	private:
		int _value;
		std::vector<IObserver*> _observers;
		
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

		void pushObserver(IObserver* obs) {
			_observers.push_back(obs);
		}

};

class Investor1 : public IObserver {
	private:
		std::string _name;
	public:
		Investor1(StockMarket& s) {
			s.pushObserver(this);
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
		Investor2(StockMarket& s) {
			s.pushObserver(this);
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
	Investor1* i1 = new Investor1(s);
	Investor2* i2 = new Investor2(s);
	
	s.setValue(31);
	s.setValue(30);
	s.setValue(29);

	return 1;
}
