SHELL = /bin/sh

####### 1) Project names and system

#SYSTEM: linux or QNX
SYSTEM = linux
PROJECT=std_loggen
EXE_NAME1 = srt_copyright_writer
# EXE_NAME2 = srt_sigproc_convert

LIB_NAME =
VER_FILE_NAME = version.h

####### 2) Directories for the installation

# Prefix for each installed program. Only ABSOLUTE PATH
prefix=~/
exec_prefix=$(prefix)/
# The directory to install the binary files in.
bindir=$(prefix)/bin
# The directory to install the include par files in.
pfilesdir=$(prefix)/pfiles



####### 3) Directories for the compiler
BIN_DIR = bin
OBJECTS_DIR = obj
SOURCE_DIR = src
INCLUDE_DIR = include
LIB_DIR = lib
DOC_DIR = doc
UT_DIR = ut
CONF_DIR = conf
DOXY_SOURCE_DIR = code_filtered
EXE_DESTDIR  = $(BIN_DIR)
LIB_DESTDIR = lib
DATA_DIR = data


####### 4) Compiler, tools and options

CC       = gcc
CXX      = g++
#Insert the optional parameter to the compiler. The CFLAGS could be changed externally by the user
CFLAGS   = -Wall

#Set INCPATH to add the inclusion paths
# INCPATH = -I ./include -I$(AGILE_LIBWCS_INCLUDE) -I$(AGILE_LIBPIL_INCLUDE) -I$(AGILE_CFITSIO_INCLUDE)
# LIBPATH = -L$(AGILE_LIBWCS_LIB)  -L$(AGILE_LIBPIL_LIB) -L$(AGILE_CFITSIO_LIB)

INCPATH = -I./include -I$(LIBPIL_INCLUDE)  -I$(CFITSIO_INCLUDE)
LIBPATH =  -L$(LIBPIL_LIB) -L$(CFITSIO_LIB)

#Insert the implicit parameter to the compiler:
ALL_CFLAGS =  $(INCPATH) $(LIBPATH) $(CFLAGS)

ifeq ($(SYSTEM), QNX)
	ALL_CFLAGS += -Vgcc_ntox86_gpp -lang-c++
endif
#Use CPPFLAGS for the preprocessor
CPPFLAGS =
#Set LIBS for addition library
# LIBS =  -lcfitsio  -L. -lm -lnsl -lpil
LIBS =  -lcfitsio  -L. -lm  -lpil 


ifeq ($(SYSTEM), QNX)
	LIBS += -lsocket
endif
LINK     = g++
#for link
LFLAGS = -shared -Wl,-soname,$(TARGET1) -Wl,-rpath,$(DESTDIR)
AR       = ar cqs
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f -r
COPY_FILE= $(COPY) -p
COPY_DIR = $(COPY) -pR
DEL_FILE = rm -f
SYMLINK  = ln -sf
DEL_DIR  = rm -rf
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p


####### 5) VPATH

VPATH=$(SOURCE_DIR):$(INCLUDE_DIR):
vpath %.o $(OBJECTS_DIR)

####### 6) Files of the project

INCLUDE=$(foreach dir,$(INCLUDE_DIR), $(wildcard $(dir)/*.h))
SOURCE=$(foreach dir,$(SOURCE_DIR), $(wildcard $(dir)/*.cpp))
SOURCE+=$(foreach dir,$(SOURCE_DIR), $(wildcard $(dir)/*.c))
#Objects to build
OBJECTS=$(addsuffix .o, $(basename $(notdir $(SOURCE))))
#only for documentation generation
DOC_INCLUDE= $(addprefix $(DOXY_SOURCE_DIR)/, $(notdir $(INCLUDE)))
DOC_SOURCE= $(addprefix $(DOXY_SOURCE_DIR)/, $(notdir $(SOURCE)))

####### 9) Pattern rules

%.o : %.cpp
	$(CXX) -Wno-write-strings $(ALL_CFLAGS) -c $< -o $(OBJECTS_DIR)/$@

#only for documentation generation
$(DOXY_SOURCE_DIR)/%.h : %.h
	doxyfilter < $< > $@

$(DOXY_SOURCE_DIR)/%.cpp : %.cpp
	doxyfilter < $< > $@


all: exe 
	
exe: makeobjdir makebindir $(OBJECTS)	
# 		test -d $(EXE_DESTDIR) || mkdir -p $(EXE_DESTDIR)
		$(CXX)  -Wno-write-strings $(ALL_CFLAGS) -o bin/$(EXE_NAME1) obj/$(EXE_NAME1).o $(LIBS)

makeobjdir:
	test -d $(OBJECTS_DIR) || mkdir -p $(OBJECTS_DIR)	
	
makebindir:
#	test -d $(bindir) || mkdir -p $(bindir)
	test -d $(BIN_DIR) || mkdir -p $(BIN_DIR)

#clean: delete all files from the current directory that are normally created by building the program. 
clean:

	$(DEL_DIR) $(OBJECTS_DIR)
	$(DEL_DIR) $(BIN_DIR)		

#Delete all files from the current directory that are created by configuring or building the program. 
distclean: clean

#install: compile the program and copy the executables, libraries, 
#and so on to the file names where they should reside for actual use. 


#uninstall: delete all the installed files--the copies that the `install' target creates. 
uninstall:

# For exe uninstall
	$(DEL_DIR) $(exec_prefix)
#dist: create a distribution tar file for this program
dist: all


#info: generate any Info files needed.
info:
	test -d $(infodir) || mkdir -p $(infodir)
	$(COPY_DIR) $(DOC_DIR)/*.* $(infodir)


install: all
# For exe installation
	test -d $(bindir) || mkdir -p $(bindir)	
	test -d $(pfilesdir)  || mkdir -p $(pfilesdir)

	$(COPY_FILE) bin/* $(bindir)
	$(COPY_FILE) conf/* $(pfilesdir)
#	$(COPY_FILE) script/* $(bindir)



