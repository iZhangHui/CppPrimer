# executable files for this directory
OBJECTS = ex16_02_03.exe ex16_04.exe ex16_05.exe \
          ex16_06.exe ex16_07.exe ex16_11.exe \
          ex16_12_13_main.exe ex16_14_15_main.exe \
          ex16_16_main.exe ex16_18.exe ex16_19_20.exe \
          ex16_22_main.exe ex16_24_main.exe ex16_26.exe \
          ex16_30_31.exe ex16_34.exe ex16_37.exe \
          ex16_39.exe


include ../../GNU_makefile_template

ex16_22_main.exe: ex16_22_main.o TextQuery.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) ex16_22_main.o TextQuery.o -o ex16_22_main.exe

