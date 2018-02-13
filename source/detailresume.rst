Resume (Detail)
===============

Chen Chung-Shu 陳鍾樞

.. No.10, Aly. 430, Ziqiang S. Rd., Zhubei City, Hsinchu County 302, Taiwan (R.O.C.).                       		    

.. Phone: 886-3-6681193  Cell phone: 886-970577923 (UTC+8:02)

E-mail: gamma_chen@yahoo.com.tw

Personal website
----------------

  http://jonathan2251.github.com/ws/index.html

..  Objective
    ---------

    LLVM compiler engineer


My publish books, LLVM open source work:
----------------------------------------

.. raw:: html

    <ul>
    <li>
    <a href="http://jonathan2251.github.com/lbd/index.html">
    Tutorial: Creating an LLVM Backend for the Cpu0 Architecture</a>
    </li>
    </ul>

    <ul>
    <li>
    <a href="http://jonathan2251.github.com/lbt/index.html">
    Tutorial: Creating an LLVM toolchain for the Cpu0 Architecture</a>
    </li>
    </ul>


Qualifications
--------------

- Familiar with c++ and programming in embedded Linux platform for 6 years.

  - Embedded linux platform: 3 years of ARM cpu, 3 years of Set Top Box, 1 year of 
    Wireless AP.

- Strong debug ability from linux and bare metal (no os) platform and ELF format 
  understanding which from compiler LLVM backend implementation.
  
- Compiler LLVM backend working experience and front end knowledge. 

  - My work is on http://jonathan2251.github.com/lbd/index.html and accepted 
    by LLVM official web at http://llvm.org/docs/tutorial/#external-tutorials.

- Presented llvm/polly to my company's llvm toolchain for loop optimation.

  - Presented the principle of "polyhedrail mathematical model" which behind 
    polly system to compiler team members with 12 hours in total. 
    http://jonathan2251.github.io/lbt/Principle_Polyhedral.pdf
  
  - Presented polly system to compiler team with 6 hours in total.

  - Discussed the advantage with polly author for applying Polyhedrail 
    mathematical model to pipeline instead of multi-core.

- Implement ARM CPU simulator for correction verification.

- Beside programming languages, knowing tools such as Sphinx/restructuredtext 
  and Rational Rose/UML to write the document. My books and web site are the examples.

- Master degree education, majored in parallel algorithm for different type of 
  processor architecture, like SMP, cube, .... . Compiler design has a lot of 
  algorithm & data structure, especially in vector processor/CPU.

- Applied Yacc/Lex tool in real project design, compiler knowledge study after 
  school.	

- Deep knowledge in CPU architecture and mips cpu, program mips assembly in low 
  level hardware dependent layer. It will be helpful in vector processor 
  compiler program and debug.

- Very familiar with C/C++, OOA/OOP, UML, design pattern. Applied these 
  knowledge in real project as above.

- Real compiler tool chain use experience, like llvm, gcc, Code Warrior, gdb, 
  ldb.

- Equipments using, like digital scope, spectrum, power meter. These equipments 
  can be used in debug or problem identify.

- Nearly 20 years of programming experience in total, which include 15 years 
  of working experience in software design of electronic product.

- Majored in Computer Science with MS. degree in 1999.

Achievement
-----------

Marvell
~~~~~~~

- Introduced polly for Marvell llvm toolchain optimization. Polly is a software 
  for loop optimization.

  - The advantage was that it might be 500% speed up in some numerical 
    application program, such as matrix multiplication, or other kind of matrix 
    operation. Though Marvell's CPUs were not used in numerical applications 
    [#polly-evalution]_.

- I applied compiler code generation concept to propose this solution and Csim 
  team adopted it [#marvell-csim-codegen]_.

- I completed cmake and adjusted python programs to build Csim instead of make 
  [#marvell-csim-cmake]_. 

- Report the better solution for cmake writting and performance compare with ninja 
  [#marvell-csim-report]_.

Motorola
~~~~~~~~

- Designed QIP7kP1 and P2 board level testing code. Over 500 millions units of 
  QIP7k model of Set Top Box was tested with this code on production line, as 
  well as shipping to market. Other major products DCX33, DCX34 and DCX35 (over 
  1000 millions of box) were porting from QIP7kP1 & QIP7kP2.

- Combined mips cpu and software engineer knowledge to create a frame work for 
  board level testing code as manager request. 

  - I used Rational Ross UML tool to design the frame work. 
    In this task. I applied object oriented analysis & program (OOA, OOP, 
    design pattern) knowledge and UML tool skill [#bltc-doc]_. 

- Implemented the I/O redirection mechanism to make the new version of code 
  porting task easier [#bltc-tvmonio]_. One of my colleague adopted this 
  mechanism by his will.

- Implemented Board Level Test with design pattern [#bltc-pattern]_.

Frustrate
---------

- I joined the DCX32xx MTC (Manufacture Testing Code) around half year. Some 
  improvementation did by another man, but still not stable enough. The root 
  cause we thought was that it used the cost down version of CPU, a cheaper 
  but not stable CPU.


Personal data
--------------

- Friendly, and enjoy in programming and handling product problem.

Education
----------

- 1997-1999 Master, June 1999, National Taiwan Normal University, Taipei, Major: 
  Computer Science

- 1991-1994 B.S., June 1994, National Taiwan Technology University of Science 
  and Technology, Taipei, Major: Industry Engineer

Licenses
--------
	
- Computer Engineer license, 1995 高考資訊技師及格

My published paper:
-------------------

-  `行排列法簡化步驟之研究 <http://ir.lib.ntnu.edu.tw/ir/handle/309250000Q/22072?locale=en-US>`_

Thesis of master degree:
------------------------

- https://github.com/Jonathan2251/ow/tree/master/sortingnetwork/ThesisMaster

Proposal of PHD study
---------------------

- https://github.com/Jonathan2251/ow/tree/master/sortingnetwork/PHD

Home work for courses in postgraduate
-------------------------------------

- https://github.com/Jonathan2251/ow/tree/master/master-homework


Experience
-----------

March 2013 - November 2016: Marvell
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Work as an CPU engineer in Marvell SOC company.

  - Implement ARM CPU simulator for correction verification.

    - Main required skills C++, CMake and ARM CPU reference manual knowledge.

- Worked as an llvm engineer in Marvell SOC company.

  - Propose importing polly in loop optimization for Marvell llvm toolchain on 
    ARM SOC CPU.
   
  - Polly author, Tobias, visit Marvell Taiwan Hsinchu branch on 2014/08/26. We
    discuss something about polly, chat and have a picture in link, 
    http://jonathan2251.github.io/wr/llvm.html#polly-author-tobias.

  - Modify clang as OpenCL team request.

- Semi-auto system for gcc compiler optimization system.

  - Implemented bash script and run it to generate Excel's format comparison 
    report automatically when the source code of Marvell's gcc toolchain has 
    updated [#marvell-auto-report]_. 

- Member of Marvell welfare committee.

August 2012 - March 2013: LLVM community
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Writing llvm backend book through studying it.



September 2004 - August 2012: Mortorola
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Set Top Box for Digital TV Software, Motorola, more software experiences 
  as follows,
	
  - Design software and over 500 millions of Set Top Box was produced and 
    shipped to market. Used UML (Rational Rose) to design the C++ software 
    frame work and generate code include reverse engineering; Programed the 
    mips cpu assembly language for software low level handling; Applied 
    Yacc/Lex Tool to design and generate C code for the production line test 
    code; Designed the new menu/dialog of VC/MFC for the testing & report 
    generator software frame work run on windows operating system; Programed 
    VB for product data download system; Linux programming and device driver 
    programming; clear case / git / svn software tools using; Digital Scope, 
    Spectrum, Power meter equipments operating and signal measurement.

June 1999 - September 2004: Proton, Abocom, DBTEL, Symmetry and Spirox
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- DTV(Proton); 802.11b(Abocom); DECT wireless phone (DBTEL); SGSN and GGSN for 
  GPRS&3G(Symmetry) ; CAM(Spirox); more detail experiences as follows,
	
  - 8051 mcu, arm cpu, C++/VB program, TTCN software language which generate 
    C++ code. 802.11b, dect wireless phone. Cvs version control system 
    deployment.

August 1997 - December 1993: Data processing center of Ministry of Finance
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- Programmer, Data processing center of Ministry of Finance, more detail 
  experiences as follows,

  - Cobol language run on large computer (IBM,…).

Professional specialty
-----------------------

Language:
~~~~~~~~~ 

- Chinese and Taiwanese are fluently, English is OK (I talk with English 
  speakers well and write tutoral document for llvm open source code).

Computer language:
~~~~~~~~~~~~~~~~~~

- Familiar with OOA/OOP, UML, Design Pattern, STL, C++, cmake, Linux device 
  driver andLinux programming, Keil C (8051 C compiler). Knowing and has real 
  experience in programming of VC/Window Programming, VB, javascript/html/css.

Software Tools:
~~~~~~~~~~~~~~~~

- Rational Rose (UML tool), Yacc/Lex (Compiler or Language parsing tool), TTCN 
  (protocol verify tool which generate C/C++ code), Install Shield (write 
  windows install software package tool), SQL (data base language), Linux/gcc 
  tool chains, Code Warrior IDE compiler, clear case/git/svn/cvs software 
  version control system tool, Sphinx/restructuredtext.

Equipments:
~~~~~~~~~~~~

- Digital Scope, Spectrum, Power meter equipments operation.

Special skill:
~~~~~~~~~~~~~~~

- Clang/llvm compiler, Linux Driver, USB, FAT files system, DTV, DECT, 802.11b, 
  JPEG coding, Sorting Algorithm, mips arm7 cpu, 8051 mcu.


Compiler or CPU related experience
-----------------------------------


CPU architecture study:
~~~~~~~~~~~~~~~~~~~~~~~~

- Studied book “Computer Architecture – A Quantitative Approach” and Mips CPU 
  user manual. Verilog language/tool study.

- Apply in work: 

  - Find the compiler bug of Code Warrior compiler for Mips cpu. The bug come 
    from #pack(1) statement code generation.

    - I emailed the bug along with example code to Code Warrior and it admited 
      that this was a bug of their compiler for mips backend.

  - Implemented the mini process mechanism with mips assembly language to solve 
    the program hang problem. After this implementation, the code was running 
    more stable and fast. It was a serious problem since when one test item 
    hang on, the other test items scheduled after that wouldn't be run. In 
    this situation, operator had no idea of the test result since test result 
    was displayed after all test items executed. I implemented a mechanism 
    (hundred lines of mips assembly) to jump out from the test item (by restore 
    the stack and cpu registers status) [#bltc-process]_.

  - Applied Verilog and book “Computer Architecture" knowledge to change Cpu0 
    verilog code to fit my llvm backend compiler design.

Compiler study:
~~~~~~~~~~~~~~~

- Studied llvm front & backend design. Study book “Compilers – Principles, 
  Techniques, & tools 2nd Aho,...” and yacc and lex tool.

- Applied in work: 

  - I implemented the Cpu0 llvm compiler backend started from scratch for 
    tutorial purpose, and writing books as in my publish books. A lot of 
    readers have been asking me questions and I answering them out of working 
    time.

  - Applied the compiler syntax parsing tool, yacc & lex, in test station 
    design (specify test items for each station in script language I defined) 
    [#bltc-gen-testitems]_. 

References
----------

- Will be furnished on request.


.. [#polly-evalution] explanation on request.

.. [#marvell-auto-report] explanation on request.

.. [#marvell-csim-codegen] explanation on request.

.. [#marvell-csim-cmake] explanation on request.

.. [#marvell-csim-report] explanation on request.

.. [#bltc-gen-testitems] explanation on request.

.. [#bltc-doc] explanation on request.

.. [#bltc-tvmonio] explanation on request.

.. [#bltc-process] explanation on request.

.. [#bltc-pattern] explanation on request.


.. .. [#polly-evalution] https://github.com/Jonathan2251/lbt/blob/master/note/polly/polly.pdf

.. .. [#marvell-auto-report] http://jonathan2251.github.io/wr/myoldwork.html#semi-auto-system-for-gcc-compiler-optimization-system

.. .. [#marvell-csim-codegen] https://github.com/Jonathan2251/ow/blob/master/Marvell/assigned-job/CSim/PermissionCreate/PermissionCreate.pdf

.. .. [#marvell-csim-cmake] http://jonathan2251.github.io/wr/myoldwork.html#cmake

.. .. [#marvell-csim-report] http://jonathan2251.github.io/wr/myoldwork.html#csim-report

.. .. [#bltc-gen-testitems] http://jonathan2251.github.io/wr/myoldwork.html#generate-test-items

.. .. [#bltc-doc] http://jonathan2251.github.io/wr/myoldwork.html#bltc-documents

.. .. [#bltc-tvmonio] http://jonathan2251.github.io/wr/myoldwork.html#tvmonio

.. .. [#bltc-process] http://jonathan2251.github.io/wr/myoldwork.html#process-mechansism

.. .. [#bltc-pattern] http://jonathan2251.github.io/wr/myoldwork.html#bltc-with-design-pattern

