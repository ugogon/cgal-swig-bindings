#ifndef SWIG_CGAL_JAVA_EXCEPTION_H
#define SWIG_CGAL_JAVA_EXCEPTION_H

#ifndef SWIG 
#include <SWIG_CGAL/Java/global_functions.h>
#include <iostream>
 
bool throwJavaException(const char* msg)
{
  jclass exception = JNU_GetEnv()->FindClass("java/lang/Exception");
  if(!exception) {
    std::cerr << "Cannot find class \"java.lang.Exception\","
              << " and cannot throw java exception!\n";
  }
  else if(JNU_GetEnv()->ThrowNew(exception, msg) != 0)
  {
    std::cerr << 
      "Call to JNU_GetEnv()->ThrowNew(JNU_GetEnv()->FindClass(\"java.lang.Exception\"), msg)"
      " failed\n";
  }
  else {
    return true;
  }
  std::cerr << "msg is:\n" << msg << "\n";
  return false;
}
#endif


#endif //SWIG_CGAL_JAVA_EXCEPTION_H