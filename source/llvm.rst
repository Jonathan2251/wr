Note about LLVM
===============

.. contents::
   :local:
   :depth: 4

lld
---

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD=Cpu0 -G "Unix Makefiles" ../src
make -j8 -l8

cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_BUILD_TYPE=Debug -DLLVM_TARGETS_TO_BUILD=Cpu0 -DLLVM_ENABLE_PIC=OFF -G "Xcode" ../src

git clone http://llvm.org/git/llvm.git src
cd src/tools

git clone http://llvm.org/git/lld.git lld

Sphinx
------

1. gh-pages:

  One time procedure for gh-pages: // Create gp-pages branch

  git checkout -b gh-pages

  touch .nojekyll

  git add .nojekyll

  git push --set-upstream origin gh-pages

.. code-block:: console

  git clone https://github.com/Jonathan2251/web
  cd web
  git checkout gh-pages	// switch to gh-pages
  touch .nojekyll
  git add .nojekyll
  git commit -m "add .nojekyll"
  git push
  make gh-pages
	
nvbook has .nojekyll as follows,

https://github.com/nikhilm/uvbook/blob/gh-pages/.nojekyll

**Without .nojekyll, the gh-pages displayed differently against built html.**

2. For iMac, set following on .profile if language of computer use English instead of Chinese:

.. code-block:: console

  export LC_ALL=en_US.UTF-8
  export LANG=en_US.UTF-8

iMac
----

1. Operation:

  ** show binary file by hexdump or TextWrangler **

  hexdump ch4_5_1.cpu0.o

  otool

  od

  Open binary file by TextWrangler, and select File - Hex Dump Front Document - Front document's file

  Safari cannot attach file in yahoo e-mail, Firefox can.


  Terminal:

  Ctrl + a and Ctrl + e for beginning and end respectively.

  Print screen:

  shift + command + 4, use mouse to select your window/area to copy to chipboard, and paste it to your document file. 

  Room in/out: control + finger move up/down on mouse (must check System Preferences -- Accessibility -- Room -- Use scroll gesture with modifier keys to zoom: Control)

2. Sync/backup disk:

.. code-block:: console
   
   rsync -azv --delete 備份/* /Volumes/Untitled/備份
   

Build libcxx-arm
-----------------

CC='clang' CXX='clang++' cmake -DCMAKE_CROSSCOMPILING=True -DLLVM_TABLEGEN=/usr/local/llvm/release/cmake_release_build/bin/llvm-tblgen -DCLANG_TABLEGEN=/usr/local/llvm/release/cmake_release_build/bin/clang-tblgen -DLLVM_DEFAULT_TARGET_TRIPLE=arm-linux-gnueabihf -DLLVM_TARGET_ARCH=ARM -DLLVM_TARGETS_TO_BUILD=ARM -DCMAKE_CXX_FLAGS='-target armv7a-linux-gnueabihf -mcpu=cortex-a9 -I/usr/gcc-linaro-arm-linux-gnueabihf-4.8-2013.04-20130417_linux/arm-linux-gnueabihf/include/c++/4.8.1/arm-linux-gnueabihf -I/usr/gcc-linaro-arm-linux-gnueabihf-4.8-2013.04-20130417_linux/include/ -mfloat-abi=hard -ccc-gcc-name arm-linux-gnueabihf-gcc' ../src

native try:
PASS: CC=clang CXX=clang++ cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../src
FAIL: CC=clang CXX=clang++ cmake -G "Unix Makefiles" -DLIBCXX_CXX_ABI=libstdc++ -DLIBCXX_LIBSUPCXX_INCLUDE_PATHS="/usr/include/c++/4.8" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr ../src

libc++
------

1. libc++ can be build and run as follows,

  (1). 
      ~/test/llvm-libc++-3.5/cmake_release_build$ cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../src

  (2). Set LD_LIBRARY_PATH="/home/cschen/test/llvm-libc++-3.5/cmake_release_build/lib" in ~/.bashrc as follows
      export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/home/cschen/test/0819-polly/cloog_install/lib:/home/cschen/test/0819-polly/llvm_build/lib:/home/cschen/test/llvm-libc++-3.5/cmake_release_build/lib"

  (3). 
      ~/test/lbd/docs/BackendTutorial/source_ExampleCode/InputFiles$ /home/cschen/test/llvm-libc++-3.5/cmake_release_build/bin/clang++ -stdlib=libc++ -I/home/cschen/test/llvm-libc++-3.5/src/projects/libcxx/include hello.cpp -nodefaultlibs -lc++ -lc++abi -lm -lc -lgcc_s -lgcc

  (4). 
      ~/test/lbd/docs/BackendTutorial/source_ExampleCode/InputFiles$ ./a.out
      hello world

  (5). If you don't set LD_LIBRARY_PATH as (2), then it fail.


2. Native x86_64 can be built successfully by these commands as follows,

  cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_FLAGS=-std=c++11 -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" ../src

  CC=clang CXX=clang++ cmake -G "Unix Makefiles" -DLIBCXX_CXX_ABI=libstdc++ -DLIBCXX_LIBSUPCXX_INCLUDE_PATHS="/usr/include/c++/4.8/;/usr/include/x86_64-linux-gnu/c++/4.8/" -DCMAKE_BUILD_TYPE=Release ../src


3. Arm cross compiler can be built and run successfully by commands,

	clang++ -target arm-linux-gnueabihf -isystem out-arm/include -isystem out-arm/include/c++/v1 -isystem /usr/arm-linux-gnueabihf/include -Lout-arm/lib -lc++ -lpthread -lc++abi -lm -lc -lgcc_s -lgcc hello-world.cpp -o a.out

	export "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/lib/:/usr/arm-linux-gnueabihf/lib/"

4. google libc++ benchmark:
https://github.com/google/benchmark


Unix/linux command
------------------

- Replace "Mips" with "Cpu0" in currently directory of all files.

.. code-block:: console

  // Linux:
  find . -type f -print0 | xargs -0 sed -i 's/Mips/Cpu0/g'
  find . -type f -print0 | xargs -0 sed -i 's/MIPS/CPU0/g'
  find . -type f -print0 | xargs -0 sed -i 's/mips/cpu0/g'
  
  // iMac:
  find . -type f -print0 | xargs -0 sed -i '' 's/Mips/Cpu0/g'

  /*-print0 (GNU find only) tells find to use the null character (\0) instead of whitespace as the output delimiter between pathnames found. This is a safer option if you files can contain blanks or other special character. It is recommended to use the -print0 argument to find if you use -exec command or xargs (the -0 argument is needed in xargs.).*/

  rename Mips Cpu0 * AsmParser/* Disassembler/* InstPrinter/* MCTargetDesc/* TargetInfo/*

  In Ubuntu:
  rename 's/Mips/Cpu0/g' * AsmParser/* Disassembler/* InstPrinter/* MCTargetDesc/* TargetInfo/*

- Replace \\t

.. code-block:: console

  awk '{gsub("\t","  ",$0); print;}' ch4_1.cpu0.s > 1
  
- grep exclude dir.

  grep -R --exclude-dir=./Target/Mips 'mips' .

git
---

- Web:

  My llvmbook:

	  github:				https://github.com/Jonathan2251/lbd

	  gh-pages:			https://jonathan2251.github.io/lbd/index.html
	
	  git clone https://github.com/Jonathan2251/lbd.git

  Other book:

	  github:				https://github.com/Jonathan2251/lbt

	  github:				https://github.com/Jonathan2251/tra

  Personal web:

	  git clone https://github.com/Jonathan2251/ws.git

  uvbook:

	  git clone https://github.com/nikhilm/uvbook

    http://nikhilm.github.com/uvbook/index.html

  clang git hub
    git clone http://llvm.org/git/clang


2. Sync from llvm mirror:

.. code-block:: console

  Sync my changes of lbd to llvmtrunk:
  Use https: instead of git: in company ubuntu

  $ git remote add llvmtrunk https://github.com/llvm-mirror/llvm.git
  $ git fetch llvmtrunk
  $ git merge llvmtrunk/master

  You should also be able to easily update to the latest LLVM trunk version by adding any LLVM git mirror (such as git://github.com/llvm-mirror/llvm.git) as a remote and directly merging from it:

  $ git remote add llvmtrunk git://github.com/llvm-mirror/llvm.git
  $ git fetch llvmtrunk
  $ git merge llvmtrunk/master

  Compare/switch between lbd and llvmtrunk
  You can also do:

  $ git fetch llvmtrunk
  $ git diff llvmtrunk/master


3. Branch operations:

.. code-block:: console

  // see all remote branch
  git remote show origin

  // checkout release 3.4 branch
  git checkout release_34

  // Create remote branch
  git branch release_33
  git push origin release_33

  // switch to clang release 32
  git checkout --track -b release_32 remotes/origin/release_32

  // list remote branches
  git ls-remote --heads origin

  // remove remote branch
  git branch -dr origin/release_370
  // push remove branch to remote
  git push origin :refs/heads/release_370
  // If you have both tag and branch release_370 then you have to do both 
  // commands as above. If you have branch only, the 2nd command is enough.


4. remove files permanently:

.. code-block:: console

  git filter-branch --tree-filter --ignore-unmatch 'rm -rf lib' HEAD
  git push origin master --force

5. create tag:

.. code-block:: console

  git tag -a release_374 -m "release version 3.7.4"
  git push origin release_374


lbt
---

- translate .dot to .png:

.. code-block:: console

  dot -Tpng /tmp/llvm_OHjeXR/dag.main.dot > 1.png
  eog 1.png


- co-works:
  Wei-Ren github,

  Here it is,
   https://github.com/azru0512/lbd

   You can also see my pull-request here on your github,

   https://github.com/Jonathan2251/lbd/pull/10
	
    git clone https://github.com/azru0512/lbd.git

.. code-block:: console

  clang -target mips-unknown-linux-gnu -c ch4_1.cpp -emit-llvm -o ch4_1.bc
  // Replace \t with "  ", Fold 80 characters
  /Users/Jonathan/llvm/test/cmake_debug_build/bin/Debug/llvm-dis ch4_1.bc -o - |awk '{gsub("\t","  ",$0); print;}'|fold -w 80 > ../../terminal_out/ch4_1.ll
  /Users/Jonathan/llvm/test/cmake_debug_build/bin/Debug/llc -march=cpu0 -relocation-model=pic -filetype=asm ch4_1.bc -o - |awk '{gsub("\t","  ",$0); print;}'|fold -w 80|awk '{gsub("\t","  ",$0); print;}' > ../../terminal_out/ch4_1.pic.cpu0.s


oprofile
--------

.. code-block:: console

  ocount --events=l1d_pend_miss:occurences,l1d_pend_miss:pending,l2_l1d_wb_rqsts:miss,l2_l1d_wb_rqsts:hit_e,l2_l1d_wb_rqsts:hit_m,l2_rqsts:rfo_miss,l2_rqsts:rfo_hit,LLC_MISSES,LLC_REFS  ./matmul

  ocount --events=l1d_pend_miss:pending  ./matmul

gem5
----

Use arm cross compiler toolchain from internet:

1. Download gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux.tar.xz

   https://releases.linaro.org/14.04/components/toolchain/binaries/

2. Run

.. code-block:: console

  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ ~/Downloads/gcc-linaro-arm-linux-gnueabihf-4.8-2014.04_linux/bin/arm-linux-gnueabihf-gcc -static hello.c 
  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ ls -l 
  total 516
  -rwxrwxr-x 1 cschen cschen 505534 Feb  1 17:59 a.out
  -rwxrwxr-x 1 cschen cschen   5476 Nov  5 14:25 ch9_3_vararg
  -rw-rw-r-- 1 cschen cschen    769 Nov  4 10:42 ch9_3_vararg.c
  -rw-rw-r-- 1 cschen cschen    743 Nov  4 10:39 ch9_3_vararg.c~
  -rw-rw-r-- 1 cschen cschen   1677 Nov  3 16:03 hello.c
  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ /usr/bin/qemu-arm a.out
  Hello world!

Use built toolchain from me:

.. code-block:: console

  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ ~/test/polly/cmake_arm_debug_build/bin/clang -static -mcpu=cortex-a9 -mfloat-abi=hard -mfpu=neon hello.c 
  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ ls
  a.out  ch9_3_vararg  ch9_3_vararg.c  ch9_3_vararg.c~  hello.c
  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ /usr/bin/qemu-arm a.out
  Hello world!

  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ ~/test/llvm-arm-toolchain/1/Marvell_toolchain_2013_04_12/arm-marvell-linux-gnueabi-hard_x86_64/bin/arm-marvell-linux-gnueabi-gcc -static hello.c 
  cschen@cschen-01:~/test/1/gem5/tests/test-progs/ch9_3_vararg/src$ /usr/bin/qemu-arm a.out
  Hello world!

polly
-----

Can build with c11 option.

1. Install cloog which depend on GMP as follows,

  http://www.cloog.org/
  https://gmplib.org/

2. Install llvm, clang and polly:

  clang and polly put in llvm/tools/

3. Use polly:

  alias pollycc="~/test/polly/cmake_debug_build/bin/clang -Xclang -load -Xclang ~/test/polly/cmake_debug_build/lib/LLVMPolly.so"
  pollycc -mllvm -polly -O3 ch8_1_3.cpp -o a.polly.out
  or, 
  ~/test/polly/cmake_debug_build/bin/clang -Xclang -load -Xclang ~/test/polly/cmake_debug_build/lib/LLVMPolly.so -mllvm -polly -O3 ch8_1_3.cpp -o a.polly.out

4. Reference:

  http://comments.gmane.org/gmane.comp.compilers.llvm.devel/60547
  Polly-basic:  clang -Xclang -load -Xclang LLVMPolly.so -O3  (! load polly but no use of polly optimization)
  Polly-optimize: clang -Xclang -load -Xclang LLVMPolly.so -mllvm -polly -O3 (use polly optimization)

5. Build by polly_cschen.sh and polly_cschen_arm.sh in directory polybench-c-3.2/.

   Run with command, ./polly_cschen.sh to get llvm/clang/polly source and build it on dir llvm_build.
   Run with command, ./polly_cschen_arm.sh to build it with llvm arm toolchain on dir llvm_arm_build.

6. Run example code for polly and compare the result with non-polly as the following commands

.. code-block:: console

    cd polly_ex && ./runtime.sh  // for PC/X86
    cd polly_ex && ./build-matmul-arm.sh            // build with llvm arm
    time ./matmul                                   // non-polly clang -O3
    // result:
        # time ./matmul
        real	10m 25.97s
        user	10m 25.76s
        sys	0m 0.23s

    time ./matmul.polly                             // polly clang -O3
    // result
        # time ./matmul.polly
        real	2m 59.71s
        user	2m 59.55s
        sys	0m 0.16s

    time ./pmatmul > pmatmul.result
    // result
        # time ./pmatmul > pmatmul.result
        real	22m 38.11s
        user	10m 33.15s
        sys	0m 0.51s

    time ./pmatmul.polly > pmatmul.polly.result
    // result
        real	15m 45.92s
        user	3m 12.79s
        sys	0m 0.50s

    diff pmatmul.result pmatmul.polly.result        // to ensure the outputs is same

7. 2014/03/07 the git llvm/polly can build by the following change of polly.sh,

    from:
        make -j$procs -l$procs
    to:
        make 

8. Document:

   http://polly.llvm.org/publications/grosser-diploma-thesis.pdf

9. Gcc option -floop-strip-mine is for tiling.

   You may run man gcc | grep '\-floop\-strip\-mine' to check if that is a supported option.

10. Copy as follows, then can run polly parallel with omp api.

    ~/test/llvm-arm-toolchain/1$ scp ./Marvell_toolchain_2013_04_12/arm-marvell-linux-gnueabi-hard_x86_64/arm-marvell-linux-gnueabi/libc/lib/libgomp.so.1 root@10.19.132.177:/usr/lib/

11. Change tile size in tools/polly/lib/ScheduleOptimizer.cpp,

    static isl_basic_map *getTileMap(isl_ctx *ctx, int scheduleDimensions, isl_space *SpaceModel, int tileSize = 32/*12*/);

12. For static debug:

  (1). Set ~/.bashrc as follows,

    export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/home/cschen/test/0819-polly/cloog_install/lib"

    because:

    http://stackoverflow.com/questions/695530/why-do-i-have-to-define-ld-library-path-with-an-export-every-time-i-run-my-appli

  (2). cmake change as follows,

    cmake -DCMAKE_PREFIX_PATH=${CLOOG_INSTALL} -D LINK_POLLY_INTO_TOOLS:Bool=ON -DCMAKE_BUILD_TYPE=Debug ${LLVM_SRC}

  (3). gdb -args [clang -v] : 

      [clang -v]= display for 

      ~/test/0819-polly/llvm_build/bin/clang -O3 -mllvm -polly -mllvm -enable-polly-openmp -lgomp -mllvm -polly-ignore-aliasing -I utilities -I datamining/covariance utilities/polybench.c -DPOLYBENCH_TIME -DPOLYBENCH_USE_SCALAR_LB -DSMALL_DATASET datamining/correlation/correlation.c -o polybench/correlation.paralle -v


Gang-Ryung Uh: Associate professor
-------------------------------------

http://cs.boisestate.edu/~uh/

Does VPO generate ARM Assembly code only, or it can generate other micro-processor assembly with little extend?
Regarding the static pipeline architecture you created. Is it possible to extend VPO to support it?

Find applications for static pipeline CPU, like merge into GPGPU architecture.

