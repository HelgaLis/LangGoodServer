CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		LGC_SmpleClent.o

LIBS =

TARGET =	LGC_SmpleClent

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
