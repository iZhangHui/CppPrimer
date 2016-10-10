DIRS = CH01_GettingStarted \
       CH02_VariablesAndBasicTypes \
       CH03_StringsVectorsAndArrays \
       CH04_Expressions \
       CH05_Statements \
       CH06_Functions \
       CH07_Classes \
       CH08_TheIOLibrary \
       CH09_SequentialContainers \
       CH10_GenericAlgorithms \
       CH11_AssociativeContainers \
       CH12_DynamicMemory \
       CH13_CopyControl \
       CH14_OverloadedOperationsAndConversions \
       CH15_ObjectOrientedProgramming \
       CH16_TemplatesAndGenericProgramming \
       CH17_SpecializedLibraryFacilities \
       CH18_ToolsForLargePrograms \
       CH19_SpecializedToolsAndTechniques

all:
	cd CH01_GettingStarted; make
	cd CH02_VariablesAndBasicTypes; make
	cd CH03_StringsVectorsAndArrays; make
	cd CH04_Expressions; make
	cd CH05_Statements; make
	cd CH06_Functions; make
	cd CH07_Classes; make
	cd CH08_TheIOLibrary; make
	cd CH09_SequentialContainers; make
	cd CH10_GenericAlgorithms; make
	cd CH11_AssociativeContainers; make
	cd CH12_DynamicMemory; make
	cd CH13_CopyControl; make
	cd CH14_OverloadedOperationsAndConversions; make
	cd CH15_ObjectOrientedProgramming; make
	# cd CH16_TemplatesAndGenericProgramming; make
	# cd CH17_SpecializedLibraryFacilities; make
	# cd CH18_ToolsForLargePrograms; make
	# cd CH19_SpecializedToolsAndTechniques; make

clean:
	cd CH01_GettingStarted; make clean
	cd CH02_VariablesAndBasicTypes; make clean
	cd CH03_StringsVectorsAndArrays; make clean
	cd CH04_Expressions; make clean
	cd CH05_Statements; make clean
	cd CH06_Functions; make clean
	cd CH07_Classes; make clean
	cd CH08_TheIOLibrary; make clean
	cd CH09_SequentialContainers; make clean
	cd CH10_GenericAlgorithms; make clean
	cd CH11_AssociativeContainers; make clean
	cd CH12_DynamicMemory; make clean
	cd CH13_CopyControl; make clean
	cd CH14_OverloadedOperationsAndConversions; make clean
	cd CH15_ObjectOrientedProgramming; make clean
	# cd CH16_TemplatesAndGenericProgramming; make clean
	# cd CH17_SpecializedLibraryFacilities; make clean
	# cd CH18_ToolsForLargePrograms; make clean
	# cd CH19_SpecializedToolsAndTechniques; make clean

clobber:
	cd CH01_GettingStarted; make clobber
	cd CH02_VariablesAndBasicTypes; make clobber
	cd CH03_StringsVectorsAndArrays; make clobber
	cd CH04_Expressions; make clobber
	cd CH05_Statements; make clobber
	cd CH06_Functions; make clobber
	cd CH07_Classes; make clobber
	cd CH08_TheIOLibrary; make clobber
	cd CH09_SequentialContainers; make clobber
	cd CH10_GenericAlgorithms; make clobber
	cd CH11_AssociativeContainers; make clobber
	cd CH12_DynamicMemory; make clobber
	cd CH13_CopyControl; make clobber
	cd CH14_OverloadedOperationsAndConversions; make clobber
	cd CH15_ObjectOrientedProgramming; make clobber
	# cd CH16_TemplatesAndGenericProgramming; make clobber
	# cd CH17_SpecializedLibraryFacilities; make clobber
	# cd CH18_ToolsForLargePrograms; make clobber
	# cd CH19_SpecializedToolsAndTechniques; make clobber
