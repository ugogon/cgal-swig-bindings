#echo No cpp compiled
swig -java -c++ DT3.i && \
g++ -g -fPIC -frounding-math  -c JavaData.cpp EPIC_Kernel.cpp  DT3_wrap.cxx -I${CGAL_DIR}/include -I${CGAL_DIR}/../../../include -I/usr/lib/jvm/java-6-sun-1.6/include && \
#~ g++ -fPIC -frounding-math  -c EPIC_Kernel.cpp  DT3_wrap.cxx -I${CGAL_DIR}/include -I${CGAL_DIR}/../../../include 
g++ -g -shared DT3_wrap.o EPIC_Kernel.o JavaData.o -o libDT3.so -lCGAL -lm -L${CGAL_DIR}/lib && \
/usr/lib/jvm/java-6-sun/bin/javac main.java && \
/usr/lib/jvm/java-6-sun/bin/java main 