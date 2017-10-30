//
// README
//

**** Files (.cpp and .h):
codegen : this file contains all methods used for building llvm assembly
llvmbuild : this file contains methods for converting our parse tree into llvm tree
main : start of the program
node (only .h): contains all classes used to instantiate each node of our llvm tree
semantictree : this file contains all methods to analyze semantically our parse tree
treenode : build the parse tree
Others:
scc.l : flex file which recognize tokens
scc.y : bison file contains grammar rules
makefile
----
reports :
7110309022.pdf and docx

**** Samples
"./samples" folder contains some samples :
- sem[i].c, i between 1 and 8 is a sample file which contains semantic error (please refers to the report for more informations)
--------------------------------------------------- 
Please refers to the first project for above files :
- sample1.c : ok using hexadecimal type
- sample2.c : test 2 dimensional array -> in this case failed, because, the restriction "only one dimensional array list" is not respected
- sample3.c : test only integer type has to be returned by a function -> in this case, not
- sample4.c : failed because main function doesn't exist
- sample5.c : ok
- fibonacci.c : ok fibonacci program
- euclid.c : ok

**** Run
./scc {input} {output}
The file containing errors message from llvm parser is error.txt and it can be modify in the class codegen.cpp (e.g.. global variable ERROR_FILE)
1 : program name
2 : input file - if it doesn't exist, a message error appears
3 : output file - if it doesn't exist, the file will be created
