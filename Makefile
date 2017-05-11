# **********************************************************************
# *                                                                    *
# *                           MLM-Network                              *
# *                                                                    *
# **********************************************************************

EXECUTABLE=mlmnet

OUTPUTDIR= ./bin

CC= g++
LDFLAGS= -lrt -pthread -lsqlite3
CFLAGS=
INCPATH= -I. -I/usr/include

ifeq ($(DEBUG),1)
    DEFINES+= -D_DEBUG
    CFLAGS= -c -O0 -g -Wall -Wextra -ansi -fexceptions $(INCPATH) $(DEFINES)
endif

ifeq ($(DEBUG),)
    DEFINES+= -D_RELEASE
    CFLAGS= -c -O2 -Wall -ansi -fexceptions $(INCPATH) $(DEFINES)
endif

OBJECTS= $(SOURCES:.cpp=.o)

SOURCES= ./source/Customer.cpp                                \
         ./source/CustomerReaderDataBase.cpp                  \
         ./source/CustomerWriterDataBase.cpp                  \
         ./source/CustomerWriterJSON.cpp                      \
         ./source/CustomerWriterText.cpp                      \
         ./source/DataBaseColumnSQLite3.cpp                   \
         ./source/DataBaseConnectionSQLite3.cpp               \
         ./source/DataBaseStatement.cpp                       \
         ./source/DataBaseStatementSQLite3.cpp                \
         ./source/DebugLogger.cpp                             \
         ./source/Network.cpp                                 \
         ./source/NetworkCollection.cpp                       \
         ./source/NetworkCollectionReaderDataBase.cpp         \
         ./source/NetworkCollectionWriterText.cpp             \
         ./source/NetworkEventHistory.cpp                     \
         ./source/NetworkEventHistoryReaderDataBase.cpp       \
         ./source/NetworkEventHistoryRecorder.cpp             \
         ./source/NetworkEventHistoryWriterDataBase.cpp       \
         ./source/NetworkEventHistoryWriterJSON.cpp           \
         ./source/NetworkEventHistoryWriterText.cpp           \
         ./source/NetworkEventLogger.cpp                      \
         ./source/NetworkReaderDataBase.cpp                   \
         ./source/NetworkWriterDataBase.cpp                   \
         ./source/NetworkWriterDOT.cpp                        \
         ./source/NetworkWriterJSON.cpp                       \
         ./source/NetworkWriterText.cpp                       \
         ./source/PropagationRule.cpp                         \
         ./source/PropagationRuleReaderDataBase.cpp           \
         ./source/PropagationRuleWriterJSON.cpp               \ 
         ./source/PropagationRuleWriterText.cpp               \
         ./source/PropagationStep.cpp                         \
         ./source/main.cpp

all: $(SOURCES) $(EXECUTABLE) move


move: $(EXECUTABLE)
	@if [ ! -d $(OUTPUTDIR) ]; then mkdir $(OUTPUTDIR) ; fi
	mv -f $(EXECUTABLE) $(OUTPUTDIR)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./source/*.o
	rm -f $(OUTPUTDIR)/$(EXECUTABLE)

# $Id: Makefile 448 2017-05-05 10:58:15Z tiago.ventura $ #
