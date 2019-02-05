#include <iostream>
#include <string>
#include <boost/program_options.hpp>

// This example uses the Boost Program Options library to handle program options
// Based on:
// https://www.boost.org/doc/libs/1_69_0/doc/html/program_options/tutorial.html
int main(int argc, char** argv) 
{
  namespace po = boost::program_options;

  std::string algorithm = "";

  po::options_description desc("Allowed options");
  desc.add_options()
    ("help", "produce help message")
    ("compression", po::value<int>(), "set compression level")
    ("algorithm", po::value<std::string>(&algorithm)->default_value("gzip"));

  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);    

  if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
  }

  if (vm.count("compression")) {
    std::cout << "Compression level was set to " 
      << vm["compression"].as<int>() << ".\n";
  } else {
    std::cout << "Compression level was not set.\n";
  }

  std::cout << "Algorithm was set to" << algorithm << ".\n";

  return 0;
}