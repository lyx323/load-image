#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<double> vTimestamps;
std::vector<std::string> vstrImageFilenames;

void loadImage(const std::string & config_file)
{
  std::ifstream F;
  F.open(config_file.c_str());
  
  if(!F)    
     cout<<"error"<<config_file<<endl;
	
  std::string s1;
  std::string timestamp;
  std::string imagepath;
  // skip first lines
  std::getline(F,s1);
  if(!F.eof())
  {
    std::string s2;
    std::getline(F,s2);
    if(!s2.empty())
    {
      std::stringstream S;
      S << s2;
      S >> timestamp;
      S >> imagepath;
    }
  }

  std::string strFile = timestamp;
  std::ifstream f;
  f.open(strFile.c_str());

  if(!f)    
     cout<<"error"<<strFile<<endl;
	
  // skip first lines
  std::string s0;
  std::getline(f,s0);
  while(!f.eof())
  {
      std::string s;
      std::getline(f,s);
      if(!s.empty())
      {
	  std::stringstream ss;
	  ss << s;
	  double t;
	  ss >> t;
	  vTimestamps.push_back(t);
	  std::string sRGB;
	  ss >> sRGB;
	  vstrImageFilenames.push_back(sRGB);
      }
  }
}

int main(int argc, char** argv)
{
  if(argc != 2)
  {
      std::cout<<"Error input "<<std::endl;
      return 1;
  }
  loadImage(argv[1]);
  return 0;
}



