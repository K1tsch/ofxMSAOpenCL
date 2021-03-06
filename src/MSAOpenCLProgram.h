#pragma once

#include "ofMain.h"
#ifdef __APPLE__
	#include <OpenCL/Opencl.h>
#else
	#include <CL/opencl.h>
#endif

#include "MSAOpenCLTypes.h"

namespace msa { 

	
	class OpenCLProgram {
	public:
		OpenCLProgram();
		~OpenCLProgram();
		
		void loadFromFile(string filename, bool isBinary = false, string options = "");
		void loadFromSource(string source, string options = "");
		
		OpenCLKernelPtr loadKernel(string kernelName);
		
		void getBinary();
		
		cl_program& getCLProgram();
		
	protected:	
		OpenCL*		pOpenCL;
		cl_program		clProgram;
		
		void			build(string options);
		
	};
	
}