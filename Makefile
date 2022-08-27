CC = gcc
LD = gcc

SOURCE_DIR = src
INCLUDE_DIRS =.venv/include
BUILD_DIR = build

OUT = libsupplier.so

all: $(OUT)

$(OUT): $(BUILD_DIR)/c/supplier.o
	$(LD) -shared $^ -o $@

$(BUILD_DIR)/c/%.o: $(SOURCE_DIR)/c/%.c build
	$(CC) -fPIC -I$(subst $() $(),:,$(INCLUDE_DIRS)) -c $< -o $@


build:
	mkdir -p $(BUILD_DIR)/c $(BUILD_DIR)/lua

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(OUT)
