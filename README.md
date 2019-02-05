# CMake example project
This is a little example of a CMake project that includes a Boost library

## Setup (CentOS 7)
```Bash
sudo yum -y install boost-devel cmake
git clone https://github.com/PascalBoeschoten/s4s-minor-cmake-example.git
cd s4s-minor-cmake-example
mkdir build
cd build
cmake ..
make
./example-executable --help
```