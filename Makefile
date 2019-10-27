# export PATH := /usr/local/opt/llvm/bin:$(PATH)
XCODE_SDK_PATH := $(xcrun --show-sdk-path)
export LDFLAGS := -L/usr/local/opt/llvm/lib -lc++fs -lcurl -lxml2
export CPPFLAGS := -I/usr/local/opt/llvm/include -Iexternal/date/include -I$(XCODE_SDK_PATH)/usr/include/libxml2 --sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk
CXX = /usr/local/opt/llvm/bin/clang++

%: %.cpp
	$(CXX) $(CPPFLAGS) -std=c++17 -o $@ $< external/date/src/tz.cpp $(LDFLAGS)
