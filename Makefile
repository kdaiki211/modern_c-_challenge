# export PATH := /usr/local/opt/llvm/bin:$(PATH)
export LDFLAGS := -L/usr/local/opt/llvm/lib -lc++fs -lcurl
export CPPFLAGS := -I/usr/local/opt/llvm/include -Iexternal/date/include
CXX = /usr/local/opt/llvm/bin/clang++

%: %.cpp
	$(CXX) $(CPPFLAGS) -std=c++17 -o $@ $< external/date/src/tz.cpp $(LDFLAGS)
