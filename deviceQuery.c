#include <stdio.h>
 
#include <OpenCL/opencl.h>
 
int main(int argc, char* const argv[]){
    // Number of Device
    cl_uint num_devices, i;
 
    // getting device ids
    clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, 0, NULL, &num_devices);
 
    cl_device_id* devices = (cl_device_id*)calloc(sizeof(cl_device_id), num_devices);
    clGetDeviceIDs(NULL, CL_DEVICE_TYPE_ALL, num_devices, devices, NULL);
 
    char buf[128];
    for (i = 0; i < num_devices; i++){
        clGetDeviceInfo(devices[i], CL_DEVICE_NAME, 128, buf, NULL);
        fprintf(stdout, "Device %s supports", buf);
 
        clGetDeviceInfo(devices[i], CL_DEVICE_VERSION, 128, buf, NULL);
 
        // Printing device info
        fprintf(stdout, "%s\n", buf);
    }
 
    free(devices);
 
    return 0;
}


// 출처: http://dhhwang89.tistory.com/55 [Martin]