##############################
INSTALLATION:
##############################

========================================================================
    STATIC LIBRARY :
========================================================================

1. 	Copy the Include and LIB folders to a folder within the project that will
	utilise the library.
	
2.	Open the project settings within Visual Studio and navigate to the
	VC++ Directories.
	
3.	For the option labelled 'Include Directories', click in the field
	and under the drop-down menu select edit. Now click the 'add new'
	button and type in the Solution-relative directory to the Include
	folder.
	
4.	For the option labelled 'Library Directories', click in the field
	and under the drop-down menu select edit. Now click the 'add new'
	button and type in the Solution-relative directory to the LIB folder.
	
5.	Under the 'Linker' drop down on the left hand side, select the 'Input'
	option. Click the 'Additional Dependencies' field and select edit from
	the drop-down menu. Add a new line and type in 'library.lib'

	
========================================================================
    DYNAMIC LINKED LIBRARY :
========================================================================

1. 	Copy the Include and DLL folders to a folder within the project that will
	utilise the library.
	
2.	Open the project settings within Visual Studio and navigate to the VC++
	Directories.
	
3.	For the option labelled 'Include Directories', click in the field
	and under the drop-down menu select edit. Now click the 'add new'
	button and type in the Solution-relative directory to the Include
	folder.

4.	For the option labelled 'Library Directories', click in the field
	and under the drop-down menu select edit. Now click the 'add new'
	button and type in the Solution-relative directory to the DLL folder.
	
5.	Depending on the project setup, you may also have to navigate to the Debug
	option and set the 'Working Directory' to the path of the DLL folder.
	

##############################
ABOUT:
##############################

All classes contained within the Math library are templated and will require
instantiation using the template parameter list.

For example:
Vector2<float> v2;

will call the default constructor for the Vector2 class using floats for all of
the instance's member variables and functions.