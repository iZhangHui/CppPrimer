# executable files for this directory
OBJECTS = ex12_02_test.exe ex12_06.exe ex12_07.exe\
		  ex12_10.exe ex12_11.exe ex12_12.exe \
		  ex12_13.exe ex12_14.exe ex12_15.exe \
		  ex12_16.exe ex12_17.exe ex12_23.exe \
		  ex12_24.exe ex12_26.exe ex12_27_30_main.exe \
		  ex12_28.exe ex12_32_main.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../../GNU_makefile_template

LOCFLAGS =

ex12_27_30_main.exe: ex12_27_30_main.o ex12_27_30.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex12_27_30_main.o ex12_27_30.o \
			-o ex12_27_30_main.exe

ex12_32_main.exe: ex12_32_main.o ex12_32.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex12_32_main.o ex12_32.o \
			-o ex12_32_main.exe
