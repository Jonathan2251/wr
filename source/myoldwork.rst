My old work
===========

.. contents::
   :local:
   :depth: 4

Semi-auto system for gcc compiler optimization system
-----------------------------------------------------

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/auto-build-and-run-benchmark

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/run_released_benchmark


Csim 
----

c++ code generator
~~~~~~~~~~~~~~~~~~

I applied compiler code generation concept to propose this solution and Csim team adopted it.

Document
++++++++

https://github.com/Jonathan2251/ow/blob/master/Marvell/assigned-job/CSim/PermissionCreate/PermissionCreate.pdf

Source
++++++

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/CSim/PermissionCreate

cmake
~~~~~

I completed cmake and adjust python programs to build Csim instead of make.

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/CSim/Csim_PJ4

The following script can be used to "copy all CMakeLists.txt and \*.cmake from 
current folder to dest folder and create the relative path name".

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/CSim/get-cmake-files.sh

Csim Report
~~~~~~~~~~~

Team group agree to adopt add_lib(... OBJECT ...) when sun grid server's cmake version upgrade to 2.8.8 above.

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/CSim/meeting/remove_GetObjects_function/meeting2016.6.2.pdf

Do benchmark and report the performance of cmake ninja versus cmake.

https://github.com/Jonathan2251/ow/tree/master/Marvell/assigned-job/CSim/meeting/ninja_report/ninja_vs_make_from_cmake.pdf


Board Level Test in Set Box Manufacturing factory
-------------------------------------------------

Generate test items
~~~~~~~~~~~~~~~~~~~

The code function is to generate c++ code for Board Level Test in Set Box 
Manufacturing factory of .

https://github.com/Jonathan2251/ow/tree/master/Bltc/Tool/CreateStationSourceCode

This tool run on Windows with cygwin (byacc/flex tools) installed.

The commands of building and running the demo program as follows,

.. code-block:: console

  CreateStationSourceCode$ make
  CreateStationSourceCode$ cd run
  run$ demo.bat

Source code
~~~~~~~~~~~

https://github.com/Jonathan2251/ow/tree/master/Bltc/Bltc

Our Board Level Test Code based on my company (Motorola) and vendor's source 
code which was called TvMon.
Since my U.S branch company released their reference testing code every few weeks,
the porting to the newest base took effort. 
I Implemented the I/O redirection mechanism to make the new version of code 
porting task easier.

TvMonIO
~~~~~~~

The following link is the main code which providing I/O redirection mechanism.

https://github.com/Jonathan2251/ow/blob/master/Bltc/TvMonIO/TvMonIO.c

Bltc porting guide
~~~~~~~~~~~~~~~~~~

The following file is the document about how to porting the Board Level Test 
Code to a new released TvMon.

https://github.com/Jonathan2251/ow/blob/master/Bltc/porting.pdf

Bltc documents
~~~~~~~~~~~~~~

Files QIP_BLTC_HLD.pdf, QIP_BLTC_LLD.pdf and QIP7xxx_bltc.mdl are the documents
I wrote.

https://github.com/Jonathan2251/ow/blob/master/Bltc/doc

Bltc with design pattern
~~~~~~~~~~~~~~~~~~~~~~~~

https://github.com/Jonathan2251/ow/blob/master/Bltc/Bltc/Pattern

Process mechansism
~~~~~~~~~~~~~~~~~~

I implemented killing process mechanism on Mips CPU bare machine (bare metal) (ref. https://en.wikipedia.org/wiki/Bare_machine) to jump out from the test item (by restore the stack and cpu registers status).

https://github.com/Jonathan2251/ow/blob/master/Bltc/Bltc/Items/Process.cpp, https://github.com/Jonathan2251/ow/blob/master/Bltc/Bltc/TiLib/Timer_ISR.cpp and https://github.com/Jonathan2251/ow/blob/master/Bltc/Bltc/TiLib/Timer_ISR_asm.cpp


DBTEL
-----

https://github.com/Jonathan2251/ow/tree/master/dbtel


Work during postgraduate (Master degree)
----------------------------------------

Home work for courses:
~~~~~~~~~~~~~~~~~~~~~~

https://github.com/Jonathan2251/ow/tree/master/master-homework

Theme of master degree:
~~~~~~~~~~~~~~~~~~~~~~~

https://github.com/Jonathan2251/ow/tree/master/sortingnetwork/ThesisMaster


Proposal of PHD study
---------------------

https://github.com/Jonathan2251/ow/tree/master/sortingnetwork/PHD

