//
// Created by juaki on 10/13/17.
//

#include <fstream>
#include "parallelOpenCL.h"



void opencl::runIteration(Matrix *grid) {

    int height = grid->getHeight();
    int width = grid->getWidth();

    // create buffers on the device
    cl::Buffer buffer_A(myContext, CL_MEM_READ_WRITE, sizeof(int)*height*width);
    cl::Buffer buffer_C(myContext, CL_MEM_READ_WRITE, sizeof(int)*height*width);
    cl::Buffer buffer_W(myContext, CL_MEM_READ_WRITE, sizeof(int));
    cl::Buffer buffer_H(myContext, CL_MEM_READ_WRITE, sizeof(int));

    int *A = grid->getMatrix();
    /*for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            std::cout << A[i*height + j] << "";
        }
        std::cout << std::endl;
    }*/


    //create queue to which we will push commands for the device.
    cl::CommandQueue queue(myContext,default_device);

    //std::cout << "Matrix A to device" << std::endl;
    //write matrix to the device
    queue.enqueueWriteBuffer(buffer_A, CL_TRUE, 0, sizeof(int)*height*width, A);


    //std::cout << "Run kernel" << std::endl;
    //run the kernel
    /*cl::KernelFunctor simple_add(cl::Kernel(program,"simple_add"),queue,cl::NullRange,cl::NDRange(10),cl::NullRange);
    simple_add(buffer_A,buffer_B,buffer_C);*/

    //alternative way to run the kernel
    cl::Kernel kernel_add = cl::Kernel(myProgram,"simple_add");
    kernel_add.setArg(0, buffer_A);
    kernel_add.setArg(2, width);
    kernel_add.setArg(3, height);
    kernel_add.setArg(1, buffer_C);
    queue.enqueueNDRangeKernel(kernel_add, cl::NullRange, cl::NDRange((size_t) (width * height)), cl::NullRange);
    queue.finish();

    int C[width*height];
    //read result C from the device to array C
    queue.enqueueReadBuffer(buffer_C,CL_TRUE,0,sizeof(int)*width*height,C);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid->setValue(i,j, C[i*height + j]);
        }
    }

}

opencl::opencl() {

    //get all platforms (drivers)
    std::vector<cl::Platform> all_platforms;
    cl::Platform::get(&all_platforms);

    if(all_platforms.size()==0){
        std::cout<<" No platforms found. Check OpenCL installation!\n";
        exit(1);
    }

    cl::Platform default_platform=all_platforms[all_platforms.size() - 1];

    //std::cout << "Using platform: "<<default_platform.getInfo<CL_PLATFORM_NAME>()<<"\n";

    //get default device of the default platform
    std::vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
    if(all_devices.size()==0){
        std::cout<<" No devices found. Check OpenCL installation!\n";
        exit(1);
    }
    default_device = all_devices[0];

    //std::cout<< "Using device: "<< default_device.getInfo<CL_DEVICE_NAME>() <<"\n";

    cl::Context context(default_device);
    myContext = context;

    cl::Program::Sources sources;

    // kernel calculates for each element C=A+B
    std::string kernel_code;

    // Load the kernel from source code
    std::ifstream kernelFile("Implementations/OpenCL/kernelSinIf.cl");
    std::string myLine;

    if (kernelFile.is_open())
    {
        while ( getline (kernelFile, myLine) )
        {
            kernel_code.append(myLine);
            kernel_code.append("\n");
        }
        kernelFile.close();
    }

    sources.push_back({kernel_code.c_str(),kernel_code.length()});

    cl::Program program(context,sources);
    myProgram = program;

    if(program.build({default_device})!=CL_SUCCESS){
        std::cout<<" Error building: "<<program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(default_device)<<"\n";
        exit(1);
    }


}
