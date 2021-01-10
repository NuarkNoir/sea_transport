# Information System "Sea transport" 

### IS Entities
	- Vessels 
		– ID
		- harbor
		- cargo
		- capacity
	- Cargo
		- ID
		- volume
		- delivery point
	- Delivery point (Harbor)
		- ID
		- title
		- storages
	- Storage
		- ID
		- capacity

### Operations
	- Vessels listing
	- Cargo movement
	- Cargo listing

### Usergroups
	- Administrator
	- Dispatcher
	- Skipper


# Documentation

Internal documentation generated with Doxygen can be found in [here](./sea_transport/documentation/)


# Code Quality

I am not usig any particular common code conventions, instead I have created my own, based on my specific views and inspirations. Something from Apache's C++ CC, something from Python. In general, I am aimed to write easilly readable? self-documenting code.


# How to build 

## Prequisites:

- QtCreator 4.13+
- QtFramework at least 5.15
- MinGW v81 x64 (I am developed and builded with it, you can use MSVC if it'll compile)

## Step-by step

1. Open project in QtCreator
	1. If needed - reconfigure project to match your setup
2. Set build type to release
3. Click `build` button
4. Locate generated binaries - we will need `{build name}.exe` file
5. Open you shell (I am using OGPowershell, not PSCore)
	1. Locate file `windeployqt.exe` in your Qt installation dir 
	> you can do so by using something like `gci -Path {QtPath} -Recurse -Include windeployqt.exe`
6. Execute command `{path to windeployqt.exe}\windeployqt.exe {path to generated exe}\{build name}.exe`
7. If everything done right - you will get all the static libs to run your build on any computer without Qt installation
