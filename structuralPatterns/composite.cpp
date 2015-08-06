#include <iostream>
#include <string>
#include <vector>

std::string indent = "    ";

class IFile {
	public:
		virtual void ls() = 0;
};

class Dir : public IFile {
	private:
		std::string _name;
		std::vector<IFile*> files;
	public:
		Dir(std::string name) : _name(name) {};
		void ls() {
			std::cout << _name << ":" << std::endl; 
			for(int i = 0; i < files.size(); i++) {
				std::cout << indent;
				if( dynamic_cast<Dir*>(files[i]) ) {
					indent += "     ";
				}			
				files[i]->ls();
			}	
		}

		void add(IFile* file) {
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
	File* one = new File("one");
	File* two = new File("two");
	File* three = new File("three");

	Dir* dir1 = new Dir("dir1");
	Dir* dir2 = new Dir("dir2");

	dir1->add(one);
	dir1->add(two);
	dir1->add(dir2);
	dir2->add(three);
	
	dir1->ls();
}
