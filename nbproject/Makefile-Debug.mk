#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_TDM_32-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/circle.o \
	${OBJECTDIR}/cross.o \
	${OBJECTDIR}/grid.o \
	${OBJECTDIR}/line.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/player.o \
	${OBJECTDIR}/point.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lbgi -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tic_tac_toe.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tic_tac_toe.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tic_tac_toe ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/circle.o: circle.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/circle.o circle.cpp

${OBJECTDIR}/cross.o: cross.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/cross.o cross.cpp

${OBJECTDIR}/grid.o: grid.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/grid.o grid.cpp

${OBJECTDIR}/line.o: line.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/line.o line.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/player.o: player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/player.o player.cpp

${OBJECTDIR}/point.o: point.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/D/graphics -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/point.o point.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
