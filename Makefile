# export PATH := /usr/local/opt/llvm/bin:$(PATH)
export LDFLAGS := -L/usr/local/opt/llvm/lib -lc++fs
export CPPFLAGS := -I/usr/local/opt/llvm/include
CXX = /usr/local/opt/llvm/bin/clang++

%: %.cpp
	$(CXX) $(CPPFLAGS) -std=c++17 -o $@ $< $(LDFLAGS)
