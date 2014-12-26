# UnitFormationAlgorithm

## About

UnitFormationAlgorithm (UFA) is an educational project to test some algorithms to put RTS-like
units in formations and let them move around.

## Build

Before building UFA make sure you installed the dependecies in the correct way. Then you have
to execute cmake to build the binary.

## Dependencies

* UFA uses *SFML 2.2* for visualization (get it [here](http://www.sfml-dev.org/))
	* SFML is expected to be in ```lib/SFML-2.2```
	* on Linux libjpeg62 has to be installed Ubuntu: ```sudo apt-get install libjpeg62-dev```
	* on Linux GLEW has to be installed Ubuntu: ```sudo apt-get install libglew-dev```
 	* if linker cannot find GLEW create symlink from ```/usr/lib/x86_64-linux-gnu/libGLEW.so``` to ```/usr/lib/libGLEW.so.1.10```
* UFA uses *Catch* for Unit Testing (get it [here](https://github.com/philsquared/Catch))
	* Catch is expected to be in ```lib/Catch```