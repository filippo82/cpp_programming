// Copy a file
#include <fstream>      // std::ifstream, std::ofstream
#include <iostream>
#include <iomanip>

int main () {
  std::fstream infile;
  infile.open("bar.txt"); //, std::fstream::binary);
  std::cout << infile.is_open() << std:: endl;
  //std::ofstream outfile ("new.txt",std::ofstream::binary);

  // get size of file
  //infile.seekg (0,infile.end);
  //long size = infile.tellg();
  int size {3};

  // allocate memory for file content
  char* buffer = new char[size];

  for (auto i=0; i<100; ++i)
  {
      infile.seekg(6);
      // read content of infile
      infile.read(buffer,size);

      //std::cout << "Ciaone!" << std::endl;
      std::cout << buffer << std::endl;
      infile.seekg(6);
      // write content to infile
      infile << std::setw(3) << i;
  }

  // write to outfile
  //outfile.write (buffer,size);

  // release dynamically-allocated memory
  //delete[] buffer;

  //outfile.close();
  infile.close();
  return 0;
}
