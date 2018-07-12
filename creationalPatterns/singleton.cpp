#include <cstddef>
#include <iostream>
#include <memory>

class Singleton
{
        private:
		int num;
                Singleton() = default;
                Singleton(const Singleton&) = delete;
                Singleton(const Singleton&&) = delete;
                Singleton& operator=(const Singleton&) = delete;

                static std::unique_ptr<Singleton> object;
        public:

                static Singleton& Instance()
                {
                        if(!object) object.reset(new Singleton); 
                        std::cout << "Getting  Singleton object\n";
                        return *(object.get());
                }
		int getNum() { return object->num; }
		void setNum(int i) { object->num = i; }
};

std::unique_ptr<Singleton> Singleton::object = nullptr;

int main()
{
        Singleton& s1 = Singleton::Instance();
        std::cout << "s1 num: " << s1.getNum() << std::endl;
        s1.setNum(2);
        std::cout << "s1 num: " << s1.getNum() << std::endl;
        Singleton& s2 = Singleton::Instance();
        std::cout << "s2 num: " << s2.getNum() << std::endl;

        return 0;
}
