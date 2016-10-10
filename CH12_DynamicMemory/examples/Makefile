# executable files for this directory
OBJECTS = allocPtr.exe allocSP.exe \
		  oknew.exe querymain.exe release.exe \
		  unique.exe UP.exe usealloc.exe usealloc2.exe \
		  useBlob.exe weak.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../../GNU_makefile_template

# CH07_Classes has Sales_data files, CH06_Functions has make_plural
LOCFLAGS = -I../../CH07_Classes/examples -I../../CH06_Functions/examples

querymain.exe: querymain.o TextQuery.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) querymain.o TextQuery.o \
			-o querymain.exe

