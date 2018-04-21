#include <iostream>
#include <string>
#include <vector>
#include <memory>

std::string indent = "    ";

class IFile {
	public:
		virtual void ls() = 0;
};

class Dir : public IFile {
	private:
		std::string _name;
		std::vector<std::shared_ptr<IFile> > files;
	public:
		Dir(std::string name) : _name(name) {};

		void ls() {
			std::cout << _name << ":" << std::endl; 
			for(int i = 0; i < files.size(); i++) {
				std::cout << indent;
				if( std::dynamic_pointer_cast<std::shared_ptr<Dir> >(files[i]) ) {
					indent += "     ";
				}			
				files[i]->ls();
			}	
		}

		void add(std::shared_ptr<IFile> file) {
			files.push_back(file);
		}
};

class File : public IFile {
	private:
		std::string _name;
	public:
		File(std::string name) : _name(name) {};
		
		void ls() { 
			std::cout << _name << std::endl; 
		}
};

int main(int argc, char* argv[])
{
        std::shared_ptr<File> f1 = std::make_shared<File>("f1");
        std::shared_ptr<File> f2 = std::make_shared<File>("f2");
        std::shared_ptr<File> f3 = std::make_shared<File>("f3");

        std::shared_ptr<Dir> dir1 = std::make_shared<Dir>("dir1");
        std::shared_ptr<Dir> dir2 = std::make_shared<Dir>("dir2");

	dir1->add(f1);
	dir1->add(f2);
	dir1->add(dir2);
	dir2->add(f3);
	
	dir1->ls();
}
