test:
	cl /c /EHsc BST.cpp
	cl /EHsc BSTtest.cpp BST.obj

replace:
	cl /c /EHsc BST.cpp
	cl /EHsc replace.cpp BST.obj

delete:
	del *.exe
	del *.obj

