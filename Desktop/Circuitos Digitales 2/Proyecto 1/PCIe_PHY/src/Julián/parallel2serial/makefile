OBJ = testbench.v
OBJ1 = config_waves.vcd
OBJ2 = synthesizer.ys

CC = iverilog
CC1 = vvp
CC2 = yosys
VISOR = gtkwave
DEBUG = -o

TARGET = test.o
TARGET1 = waves.gtkw

all:   $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(DEBUG) $(TARGET)
	$(CC1) $(TARGET)

synth:
	$(CC2) $(OBJ2)

waves:
	$(VISOR) $(OBJ1)

look:
	$(VISOR) $(TARGET1)

values:
	$(CC1) $(TARGET)

clean:
	rm -f -R *.o *.vcd *.pdf *.dot
	rm p2s_sintetizado.v
