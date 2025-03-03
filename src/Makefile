# Makefile

bin       := Employee
cpp       != find -name '*.cpp'
cppm      != find -name '*.cppm'
std.o     := std.o
std.pcm   := std.pcm
std.cppm  := /usr/lib/llvm-19/share/libc++/v1/std.cppm

pcm       := $(std.pcm) $(cppm:.cppm=.pcm)
obj       := $(std.o) $(pcm:.pcm=.o) $(cpp:.cpp=.o)

cxx       := clang++-19
std       := -std=c++23
libc++    := -stdlib=libc++ 
warn      := -Wno-reserved-identifier -Wno-reserved-module-identifier

default: $(bin)

$(std.pcm): $(std.cppm)
	$(cxx) $(std) $(libc++) $(warn) --precompile $< -o $@

$(std.o): $(std.pcm)
	$(cxx) $(std) -fprebuilt-module-path=. -c $< -o $@

%.pcm: %.cppm
	$(cxx) $(std) $(warn) --precompile -fprebuilt-module-path=. $< -o $@

%.o: %.pcm
	$(cxx) $(std) -fprebuilt-module-path=. -c $< -o $@

%.o: %.cpp
	$(cxx) $(std) -fprebuilt-module-path=. -c $< -o $@

$(bin): $(obj)
	$(cxx) $(std) $(libc++) $^ -o $@

.PRECIOUS: %.pcm
	
clean:
	rm -rf $(bin) $(obj) $(pcm)

# vim: sw=3:ts=2:noexpandtab
