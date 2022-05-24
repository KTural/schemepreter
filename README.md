# schemepreter

## Info
#### Basic Interpreter with small set of functionalities for Scheme programming language


### List of Supported Scheme Expressions
```
keywords : if, define, begin, quote, set!, lambda, print, exit, quit
operations : +, -, *, /, >, <, >=, <=, =, not
```

## Installation

### Prerequisites
```
GNU Compiler : g++ -std=c++17

Boost library for regex : <boost/regex.hpp> 
Entire library : https://www.boost.org/users/download/
Regex specific : https://www.boost.org/doc/libs/1_72_0/libs/regex/doc/html/boost_regex/install.html
Docs : https://www.boost.org/doc/libs/1_79_0/libs/regex/doc/html/index.html

Testing : <gtest/gtest.h>
Setup : https://github.com/google/googletest/blob/main/googletest/README.md
User guide : https://google.github.io/googletest/
```

### Building the project
#### Clone the repository
```
$ git clone https://github.com/KTural/schemepreter.git
$ cd schemepreter
```

#### Run the project
```
./build.sh
```
#### Run the exe file
```
./run.sh 
```
#### 
#### Test the project
```
./run_tests.sh
```

## Sample Usage

### Operations :

```
$ ./run.sh
>>> (+ 2 3)
5
>>> (- 4 (- 3 (* 9 2)))
19
>>> (/ 8 (/ 2 4))
16
>>> (not (= 3 4))
#t
>>> (not #t)
#f
>>> (not #f)
#t
>>>
```

### Functions :
```
>>> (define x 3)
>>> (+ x 4)
7
>>> (* x (/ x 2))
4.5
>>> (define (square x)
    (* x x))

>>> (square 4)
16
>>>
```

### Conditions :

```
>>> (define x 11)
>>> (if (< x 10)
    x
    (if (> x 20)
        x
        (* x 2)
    ))
22
>>>
```

### Literal expressions :
```
>>> (quote (+ 1 2))       
( + 1 2 ) 
```

### Lambda expressions :
```
>>> (define reverse-subtract
    (lambda (x y) (- y x)))
>>> (reverse-subtract 7 10)
3
>>> (define square
    (lambda (x) (* x x)))
>>> (square 3)
9
>>> (define fact (lambda (x) (if (<= x 1) 1 (* x (fact (- x 1))))))
>>> (fact 5)
120
>>>
```

### Assignments :
```
>>> (define x 2)
>>> (+ x 1)                     
3
>>> (set! x 4)                 
>>> (+ x 1)     
5
>>>
```

### Sequencing 

```
>>> (define x 0)

>>> (begin (set! x 5)
       (+ x 1))
6
>>>
```

### Printing to the console
```
>>> (define x 10)
>>> (define y 20)
>>> (if (== x 10)
        (print x)
        (print y)
)
10 
>>> (if (< x 10)
        (print x)
        (print y))
20 
>>> 
```
### Exiting the REPL :

```
>>> (quit) 
```

```
>>> (exit)
```
## Sample Tests

```
$ ./run_tests.sh
rm -rf ./build
rm -rf *.o
rm -rf build/test/test_out
mkdir ./build
mkdir ./build/test
g++ -std=c++17 -Wall -Wextra -c src/o* src/e* src/p* src/u* src/s*
g++ -std=c++17 -Wall -Wextra -c tests/*
g++ -o build/test/test_out ./*.o -lgtest -lgtest_main -lpthread 
./build/test/test_out
Running main() from /build/gtest/src/googletest-release-1.11.0/googletest/src/gtest_main.cc
[==========] Running 66 tests from 15 test suites.
[----------] Global test environment set-up.
[----------] 6 tests from EnvironmentTest
[ RUN      ] EnvironmentTest.CheckGetSpecificElement
[       OK ] EnvironmentTest.CheckGetSpecificElement (0 ms)
...
[       OK ] EnvironmentTest.CheckGetMember (0 ms)
[----------] 6 tests from EnvironmentTest (0 ms total)

[----------] 4 tests from ObjectsTest
[ RUN      ] ObjectsTest.CheckGetExprType
[       OK ] ObjectsTest.CheckGetExprType (0 ms)
[ RUN      ] ObjectsTest.CheckGetExprValue
[       OK ] ObjectsTest.CheckGetExprValue (0 ms)
[ RUN      ] ObjectsTest.CheckGetProc
[       OK ] ObjectsTest.CheckGetProc (0 ms)
[ RUN      ] ObjectsTest.CheckNativeProc
[       OK ] ObjectsTest.CheckNativeProc (0 ms)
[----------] 4 tests from ObjectsTest (0 ms total)

[----------] 5 tests from OperationsTestAddition
...
[       OK ] OperationsTestSubtraction.SubtractionInvalidOperand (0 ms)
[----------] 5 tests from OperationsTestSubtraction (0 ms total)

[----------] 5 tests from OperationsTestDivision
[ RUN      ] OperationsTestDivision.DivisionSimple
[       OK ] OperationsTestDivision.DivisionSimple (0 ms)
...
[       OK ] OperationsTestDivision.DivisionInvalidOperand (0 ms)
[----------] 5 tests from OperationsTestDivision (0 ms total)

[----------] 5 tests from OperationsTestMultiplication
...
[       OK ] OperationsTestLessThanOrEqual.LessThanOrEqualInvalidOperand (0 ms)
[----------] 5 tests from OperationsTestLessThanOrEqual (0 ms total)
...
[       OK ] OperationsTestGreaterThan.GreaterThanInvalidOperand (0 ms)
[----------] 5 tests from OperationsTestGreaterThan (0 ms total)

[----------] 5 tests from OperationsTestGreaterThanOrEqual
[ RUN      ] OperationsTestGreaterThanOrEqual.GreaterThanOrEqualSimple
[       OK ] OperationsTestGreaterThanOrEqual.GreaterThanOrEqualSimple (0 ms)
...
[       OK ] OperationsTestGreaterThanOrEqual.GreaterThanOrEqualInvalidOperand (0 ms)
[----------] 5 tests from OperationsTestGreaterThanOrEqual (0 ms total)

[----------] 2 tests from ProcedureTest
[ RUN      ] ProcedureTest.CheckGetArgList
[       OK ] ProcedureTest.CheckGetArgList (0 ms)
[ RUN      ] ProcedureTest.CheckGetProcBody
[       OK ] ProcedureTest.CheckGetProcBody (0 ms)
[----------] 2 tests from ProcedureTest (0 ms total)

[----------] 2 tests from StructureTest
[ RUN      ] StructureTest.CheckGetStr
[       OK ] StructureTest.CheckGetStr (0 ms)
[ RUN      ] StructureTest.CheckGetProc
[       OK ] StructureTest.CheckGetProc (0 ms)
[----------] 2 tests from StructureTest (0 ms total)

[----------] 2 tests from UtilsTest
[ RUN      ] UtilsTest.CheckNumber
[       OK ] UtilsTest.CheckNumber (0 ms)
[ RUN      ] UtilsTest.ParseInput
[       OK ] UtilsTest.ParseInput (0 ms)
[----------] 2 tests from UtilsTest (0 ms total)

[----------] Global test environment tear-down
[==========] 66 tests from 15 test suites ran. (5 ms total)
[  PASSED  ] 66 tests.

```

## References
https://en.wikipedia.org/wiki/Scheme_(programming_language)

https://www.scheme.com/tspl4/

https://www.cs.cmu.edu/Groups/AI/html/r4rs/r4rs_2.html

https://github.com/google/googletest/tree/main/googletest/samples

https://inst.eecs.berkeley.edu/~cs61a/fa14/assets/interpreter/scheme.html