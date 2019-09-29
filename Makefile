# export PATH := /usr/local/opt/llvm/bin:$(PATH)
export LDFLAGS := -L/usr/local/opt/llvm/lib -lc++fs -lcurl -lxml2
export CPPFLAGS := -I/usr/local/opt/llvm/include -Iexternal/date/include -I/usr/include/libxml2
CXX = /usr/local/opt/llvm/bin/clang++

%: %.cpp
	$(CXX) $(CPPFLAGS) -std=c++17 -o $@ $< external/date/src/tz.cpp $(LDFLAGS)
