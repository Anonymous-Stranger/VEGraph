##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=_VEGraph
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Akash\Documents\Programming\_codelite\c++"
ProjectPath            := "C:\Users\Akash\Documents\Programming\_codelite\c++\_VEGraph"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Akash
Date                   :=29/08/2015
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :="C:/Program Files (x86)/LLVM/bin/clang++.exe"
SharedObjectLinkerName :="C:/Program Files (x86)/LLVM/bin/clang++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="_VEGraph.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++ $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/mingw32 $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include/c++/backward $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include $(IncludeSwitch)c:/MinGW/include $(IncludeSwitch)c:/MinGW/lib/gcc/mingw32/4.8.1/include-fixed $(IncludeSwitch)c:/MinGW/mingw32/include  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files (x86)/LLVM/bin/llvm-ar.exe" rcu
CXX      := "C:/Program Files (x86)/LLVM/bin/clang++.exe"
CC       := "C:/Program Files (x86)/LLVM/bin/clang.exe"
CXXFLAGS := -std=c++11 -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files (x86)/LLVM/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/__main.cpp$(ObjectSuffix) $(IntermediateDirectory)/_test.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug"
	@echo rebuilt > "C:\Users\Akash\Documents\Programming\_codelite\c++/.build-debug/_VEGraph"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/__main.cpp$(ObjectSuffix): __main.cpp $(IntermediateDirectory)/__main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_VEGraph/__main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/__main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/__main.cpp$(DependSuffix): __main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/__main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/__main.cpp$(DependSuffix) -MM "__main.cpp"

$(IntermediateDirectory)/__main.cpp$(PreprocessSuffix): __main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/__main.cpp$(PreprocessSuffix) "__main.cpp"

$(IntermediateDirectory)/_test.cpp$(ObjectSuffix): _test.cpp $(IntermediateDirectory)/_test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Akash/Documents/Programming/_codelite/c++/_VEGraph/_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/_test.cpp$(DependSuffix): _test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/_test.cpp$(DependSuffix) -MM "_test.cpp"

$(IntermediateDirectory)/_test.cpp$(PreprocessSuffix): _test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/_test.cpp$(PreprocessSuffix) "_test.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


