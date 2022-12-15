GCC-PARMS = -static -m32 -s
MINGW32-PARMS = -static
BIN = bin
SOURCES = sources/tool
HEADERS = headers

all: fakesethc windowspasser liveisotool

fakesethc: $(SOURCES)/fakesethc.c $(HEADERS)/fakesethc.h
	i686-w64-mingw32-gcc $(MINGW32-PARMS) $(SOURCES)/fakesethc.c -o $(BIN)/$@.exe

windowspasser: $(SOURCES)/windowspasser.c $(HEADERS)/tool.h fakesethc
	$(shell /usr/bin/xxd -n "FAKESH_BIN" -i $(BIN)/fakesethc.exe > $(BIN)/DATA.h)
	gcc $(GCC-PARMS) $(SOURCES)/windowspasser.c -o $(BIN)/$@

liveisotool: $(SOURCES)/liveisotool.c $(HEADERS)/liveisotool.h
	gcc $(GCC-PARMS) $(SOURCES)/liveisotool.c -o $(BIN)/$@
