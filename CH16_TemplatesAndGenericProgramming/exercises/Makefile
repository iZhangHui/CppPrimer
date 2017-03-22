# executable files for this directory
OBJECTS = ex16_02_03.exe ex16_04.exe ex16_05.exe \
          ex16_06.exe ex16_07.exe ex16_11.exe \
          ex16_12_13_main.exe ex16_14_15_main.exe \
          ex16_16_main.exe


include ../../GNU_makefile_template


ex16_12_13.exe: ex16_12_13_main.o ex16_12_13.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex16_12_13_main.o ex16_12_13.o \
			-o ex16_12_13_main.exe

ex16_14_15.exe: ex16_14_15_main.o ex16_14_15.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex16_14_15_main.o ex16_14_15.o \
			-o ex16_14_15_main.exe

ex16_16.exe: ex16_16_main.o ex16_16.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex16_16_main.o ex16_16.o \
			-o ex16_16_main.exe

