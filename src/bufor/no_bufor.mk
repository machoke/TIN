##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=no_bufor
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/p4/.codelite/bufor"
ProjectPath            := "/home/p4/.codelite/bufor"
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
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/statement$(ObjectSuffix) $(IntermediateDirectory)/connection$(ObjectSuffix) $(IntermediateDirectory)/connectionSettings$(ObjectSuffix) 

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
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/p4/.codelite/bufor/main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/p4/.codelite/bufor/main.cpp"

$(IntermediateDirectory)/statement$(ObjectSuffix): statement.cpp $(IntermediateDirectory)/statement$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor/statement.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/statement$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/statement$(DependSuffix): statement.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/statement$(ObjectSuffix) -MF$(IntermediateDirectory)/statement$(DependSuffix) -MM "/home/p4/.codelite/bufor/statement.cpp"

$(IntermediateDirectory)/statement$(PreprocessSuffix): statement.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/statement$(PreprocessSuffix) "/home/p4/.codelite/bufor/statement.cpp"

$(IntermediateDirectory)/connection$(ObjectSuffix): connection.cpp $(IntermediateDirectory)/connection$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor/connection.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/connection$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/connection$(DependSuffix): connection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/connection$(ObjectSuffix) -MF$(IntermediateDirectory)/connection$(DependSuffix) -MM "/home/p4/.codelite/bufor/connection.cpp"

$(IntermediateDirectory)/connection$(PreprocessSuffix): connection.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/connection$(PreprocessSuffix) "/home/p4/.codelite/bufor/connection.cpp"

$(IntermediateDirectory)/connectionSettings$(ObjectSuffix): connectionSettings.cpp $(IntermediateDirectory)/connectionSettings$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/p4/.codelite/bufor/connectionSettings.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/connectionSettings$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/connectionSettings$(DependSuffix): connectionSettings.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/connectionSettings$(ObjectSuffix) -MF$(IntermediateDirectory)/connectionSettings$(DependSuffix) -MM "/home/p4/.codelite/bufor/connectionSettings.cpp"

$(IntermediateDirectory)/connectionSettings$(PreprocessSuffix): connectionSettings.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/connectionSettings$(PreprocessSuffix) "/home/p4/.codelite/bufor/connectionSettings.cpp"


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
	$(RM) $(IntermediateDirectory)/connectionSettings$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/connectionSettings$(DependSuffix)
	$(RM) $(IntermediateDirectory)/connectionSettings$(PreprocessSuffix)
	$(RM) $(OutputFile)


