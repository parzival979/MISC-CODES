Command line used to find this crash:

afl-fuzz -x c_asm.dict -m 300 -i afl_input/ -o afl_output/ /root/tcc/bin/tcc -I /root/tcc/include -Wall -Wextra -Wimplicit-function-declaration -Wunsupported -Wwrite-strings -Werror -funsigned-char -fsigned-char -fno-common -fleading-underscore -fms-extensions -fdollars-in-identifiers -fPIC -flto -ffunction-sections -falign-functions=4 -m64 -masm=intel -Wshadow -Wcast-align -Wstrict-prototypes -Wstrict-overflow=5 -DDEBUG -D_GNU_SOURCE -D_POSIX_SOURCE -g -b -bt 10 -shared -o hello @@

If you can't reproduce a bug outside of afl-fuzz, be sure to set the same
memory limit. The limit used for this fuzzing session was 300 MB.

Need a tool to minimize test cases before investigating the crashes or sending
them to a vendor? Check out the afl-tmin that comes with the fuzzer!

Found any cool bugs in open-source tools using afl-fuzz? If yes, please drop
me a mail at <lcamtuf@coredump.cx> once the issues are fixed - I'd love to
add your finds to the gallery at:

  http://lcamtuf.coredump.cx/afl/

Thanks :-)
