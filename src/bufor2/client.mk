##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=client
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/p4/.codelite/bufor"
ProjectPath            := "/home/p4/.codelite/bufor2"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=p4
Date                   :=06.06.2015
CodeLitePath           :="/home/p4/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/statement$(ObjectSuffix) $(IntermediateDirectory)/connection$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor2/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/p4/.codelite/bufor2/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/p4/.codelite/bufor2/main.cpp"

$(IntermediateDirectory)/statement$(ObjectSuffix): statement.cpp $(IntermediateDirectory)/statement$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor2/statement.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/statement$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/statement$(DependSuffix): statement.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/statement$(ObjectSuffix) -MF$(IntermediateDirectory)/statement$(DependSuffix) -MM "/home/p4/.codelite/bufor2/statement.cpp"

$(IntermediateDirectory)/statement$(PreprocessSuffix): statement.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/statement$(PreprocessSuffix) "/home/p4/.codelite/bufor2/statement.cpp"

$(IntermediateDirectory)/connection$(ObjectSuffix): connection.cpp $(IntermediateDirectory)/connection$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor2/connection.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/connection$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/connection$(DependSuffix): connection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/connection$(ObjectSuffix) -MF$(IntermediateDirectory)/connection$(DependSuffix) -MM "/home/p4/.codelite/bufor2/connection.cpp"

$(IntermediateDirectory)/connection$(PreprocessSuffix): connection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/connection$(PreprocessSuffix) "/home/p4/.codelite/bufor2/connection.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/statement$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/statement$(DependSuffix)
	$(RM) $(IntermediateDirectory)/statement$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/connection$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/connection$(DependSuffix)
	$(RM) $(IntermediateDirectory)/connection$(PreprocessSuffix)
	$(RM) $(OutputFile)


